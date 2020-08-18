#include <map>
#include <string>
#include <vector>

using mapOfScoresWithNames = std::map<std::string, std::vector<std::pair<std::string, size_t>>>;

class ScoreBoard {
public:
    mapOfScoresWithNames calculateScores(std::map<std::string, std::vector<std::string>> fileContent);
};
