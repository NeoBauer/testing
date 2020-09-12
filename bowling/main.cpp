#include <filesystem>
#include <iostream>

#include "ArgsParser.hpp"
#include "DirectoryContent.hpp"

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    char dir[] = "../scores";
    DirectoryContent ScoresFolder(dir);
    ArgsParser Parser_;

    Parser_.CheckArguments(argc, argv);

    return 0;
}
