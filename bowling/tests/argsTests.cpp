#include "../ArgsParser.hpp"
#include "catch.hpp"

SCENARIO("CheckingNumberOfArgumentsAndProgramBehaviour") {
    ArgsParser parser;
    char name[] = "./bowling";

    GIVEN("CheckProgramArguments") {
        WHEN("ProgramWithoutAnyArgs") {
            int argsNum = 1;
            char* tab[1] = {name};
            THEN("ReturnNoArgs") {
                REQUIRE(parser.CheckArguments(argsNum, tab) == CommandArguments::ERR_PROGRAM_NAME_ONLY);
            }
        }
        WHEN("DirectoryDoesntExists") {
            int argsNum = 2;
            char dirname[] = "./Very/Wrong/Name";
            char* tab[2] = {name, dirname};
            THEN("ReturnInfoWrongName") {
                REQUIRE(parser.CheckArguments(argsNum, tab) == CommandArguments::ERR_WRONG_DIR_NAME);
            }
        }
        WHEN("DirectoryExists") {
            int argsNum = 2;
            char dirname[] = "/usr";
            char* tab[2] = {name, dirname};
            THEN("ReturnInfoForDirectoryOnly") {
                REQUIRE(parser.CheckArguments(argsNum, tab) == CommandArguments::SOURCE_DIRECTORY_NAME);
            }
        }
        WHEN("DirectoryExistsAndOutputFileIsGiven") {
            int argsNum = 3;
            char dirname[] = "/usr";
            char outFileName[] = "results.txt";
            char* tab[3] = {name, dirname, outFileName};
            THEN("ReturnInfoDirectoryAndFilename") {
                REQUIRE(parser.CheckArguments(argsNum, tab) == CommandArguments::SOURCE_DIRECTORY_AND_OUTPUT_FILE);
            }
        }
        WHEN("DirectoryExistsAndOutputFileIsGiven-WrongOrder!") {
            int argsNum = 3;
            char dirname[] = "/usr";
            char outFileName[] = "results.txt";
            char* tab[3] = {name, outFileName, dirname};
            THEN("ReturnInfoDirectoryAndFilename") {
                REQUIRE(parser.CheckArguments(argsNum, tab) == CommandArguments::ERR_WRONG_DIR_NAME);
            }
        }
        WHEN("ShowMeHelp!") {
            int argsNum = 2;
            char helpCall[] = "-h";
            char* tab[2] = {name, helpCall};
            THEN("ReturnInfoAboutHelp") {
                REQUIRE(parser.CheckArguments(argsNum, tab) == CommandArguments::SHOW_HELP);
            }
        }
    }
}