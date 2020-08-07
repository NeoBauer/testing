#include <iostream>
#include <sstream>

#include "../DirectoryContent.hpp"
#include "../FlagTests.hpp"
#include "../ScoreBoard.hpp"
#include "catch.hpp"
namespace fs = std::filesystem;

SCENARIO("SearchingFilesAndFileContentInDirectory") {
    GIVEN("Created directoryContent object and fake vector just for comparison") {
        char dir[] = "../scores";
        DirectoryContent scores(dir);
        std::vector<fs::path> expectedDirectoryContent;
        fs::path dir1("../scores/lane1");
        fs::path dir2("../scores/lane2");
        fs::path dir3("../scores/lane3");
        expectedDirectoryContent.emplace_back(dir1);
        expectedDirectoryContent.emplace_back(dir2);
        expectedDirectoryContent.emplace_back(dir3);
        std::map<std::string, std::vector<std::string>> const expectedMap{
            {"lane1", {"Name1:X|4-|3", "Name2:34|X|0-", ":X|22|33"}},
            {"lane2", {}},
            {"lane3",
             {"Michael:X|7/|9-|X|-8|8/|-6|X|X|X||81",
              "Radek:9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||"}}};
        WHEN("Iterate through directory") {
            THEN("Check if function found all files") {
                REQUIRE_THAT(expectedDirectoryContent,
                             Catch::Matchers::Equals(scores.getFilesInDirectory()));
            }
        }
        WHEN("ReadFiles") {
            THEN("MapWithFileNameAndFileContentFilled") {
                REQUIRE(expectedMap == scores.getFileNameAndContentMap());
            }
        }
    }
}

SCENARIO("CheckingActionsDependsOnFlag") {
    GIVEN("OutputBufferObjectToWriteIn") {
        std::stringstream OutputBufferObject;
        printOutHelp(OutputBufferObject);
        THEN("CheckIfPrintWhatItShould") {
            REQUIRE(OutputBufferObject.str() == "HelpMeIamLost");
        }
    }
}

SCENARIO("ParsingFileContentAndCountingPoints") {
    GIVEN("Map of fake files content and expected scores") {
        ScoreBoard board;

        std::map<std::string, std::vector<std::string>> const fileContent{
            {"lane1", {"Name1:X|4-|3", "Name2:34|X|0-", ":X|22|33"}},
            {"lane2", {}},
            {"lane3",
             {"Michael:X|7/|9-|X|-8|8/|-6|X|X|X||81",
              "Radek:9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||"}}};

        std::map<std::string, std::vector<std::pair<std::string, size_t>>> const expectedScores{
            {"lane1", {{{"Name1"}, {30}}, {{"Name2"}, {44}}, {{""}, {34}}}},
            {"lane2", {}},
            {"lane3", {{{"Michal"}, {167}}, {{"Radek"}, {90}}}}};

        auto returnedScores = board.calculateScores(fileContent);
        WHEN("Parse files contents and return scores") {
            THEN("ScoreMapsShouldMatch") {
                REQUIRE(returnedScores == expectedScores);
            }
        }
    }
}