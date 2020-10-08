#include <map>
#include <string>
#include <vector>

using mapOfScoresWithNames = std::map<std::string, std::vector<std::pair<std::string, size_t>>>;
using pairOfScoreSymbolsForPlayer = std::pair<std::string, std::vector<std::string>>;

class ScoreBoard {
private:
    std::map<std::string, std::vector<pairOfScoreSymbolsForPlayer>> pairPlayersWithLanes(std::map<std::string, std::vector<std::string>>& fileContent);
    pairOfScoreSymbolsForPlayer extractScoresForPlayer(std::string& playerScores);
public:
    mapOfScoresWithNames calculateScores(std::map<std::string, std::vector<pairOfScoreSymbolsForPlayer>>& playersWithLanes);
};
