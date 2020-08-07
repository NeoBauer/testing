#include <map>
#include <string>
#include <vector>

class ScoreBoard {
public:
    std::map<std::string, std::vector<std::pair<std::string, size_t>>> calculateScores(std::map<std::string, std::vector<std::string>> fileContent);
};