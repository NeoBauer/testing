#include "ScoreBoard.hpp"
#include <algorithm>

using mapOfScoresWithNames = std::map<std::string, std::vector<std::pair<std::string, size_t>>>;  //std::map<laneName, std::vector<std::pair<playerName, theirScore>>>
using pairOfScoreSymbolsForPlayer = std::pair<std::string, std::vector<std::string>>;             // std::pair<playerName, theirStrikeSybols>

pairOfScoreSymbolsForPlayer ScoreBoard::extractScoresForPlayer(std::string& fileContent) {
    pairOfScoreSymbolsForPlayer playerScores{};
    std::string scoresString{};
    int delimeterCount{};

    std::string nameDelimeter{":"};
    char scoreDelimeter = '|';

    playerScores.first = fileContent.substr(0, fileContent.find(nameDelimeter));
    scoresString = fileContent.substr(fileContent.find(nameDelimeter) + 1, fileContent.length());

    delimeterCount = std::count_if(scoresString.begin(), scoresString.end(), [&scoreDelimeter](auto& el) { return el == scoreDelimeter; });  // if needed for points count, can be removed
    scoresString.erase(std::remove(scoresString.begin(), scoresString.end(), scoreDelimeter), scoresString.end());

    std::for_each(scoresString.begin(), scoresString.end(), [&playerScores](auto el) { playerScores.second.push_back(std::string(1, el)); });

    return playerScores;
}

std::map<std::string, std::vector<pairOfScoreSymbolsForPlayer>> ScoreBoard::pairPlayersWithLanes(std::map<std::string, std::vector<std::string>>& fileContent) {
    std::map<std::string, std::vector<pairOfScoreSymbolsForPlayer>> lanesMap;  //std::map<laneName, std::vector<std::pair<playerName, theirStrikeSybols>>>

    for (auto& fileElement : fileContent) {
        std::vector<pairOfScoreSymbolsForPlayer> players{};
        for (auto& vectorElement : fileElement.second) {
            players.push_back(extractScoresForPlayer(vectorElement));
        }
        lanesMap[fileElement.first] = players;
    }

    return lanesMap;
}

mapOfScoresWithNames ScoreBoard::calculateScores(std::map<std::string, std::vector<pairOfScoreSymbolsForPlayer>>& lanes) {
}