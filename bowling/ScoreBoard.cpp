#include "ScoreBoard.hpp"

using mapOfScoresWithNames = std::map<std::string, std::vector<std::pair<std::string, size_t>>>;

mapOfScoresWithNames ScoreBoard::calculateScores(std::map<std::string, std::vector<std::string>> fileContent) {
    mapOfScoresWithNames returnMap{};
    std::string nameDelimeter = ":";
    std::string scoreDelimeter = "|";

    for (auto& element : fileContent) {
        std::pair<std::string, std::vector<std::pair<std::string, size_t>>> para;
        para.first = element.first;
        for (auto& vectorEl : element.second) {
            std::pair<std::string, size_t> scoreToInsert{};
            scoreToInsert.first = vectorEl.substr(0, vectorEl.find(nameDelimeter));
        }

        returnMap.insert(para);
    }
}