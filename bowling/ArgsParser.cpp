#include "ArgsParser.hpp"

#include <string.h>

#include <filesystem>
#include <iostream>

ArgsParser::ArgsParser() {
}

ArgsParser::ArgsParser(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "";
    }
}

CommandArguments ArgsParser::CheckArguments(int ArgsNum, char* ArgsTab[]) {
    if (ArgsNum <= 1)
        return CommandArguments::ERR_PROGRAM_NAME_ONLY;

    if (strcmp(ArgsTab[1], "-h") == 0)
        return CommandArguments::SHOW_HELP;

    if (!CheckIfDirectoryExists(ArgsTab[1]))
        return CommandArguments::ERR_WRONG_DIR_NAME;

    if (ArgsNum == 2) {
        return CommandArguments::SOURCE_DIRECTORY_NAME;
    }
    if (ArgsNum == 3) {
        return CommandArguments::SOURCE_DIRECTORY_AND_OUTPUT_FILE;
    }
}

bool ArgsParser::CheckIfDirectoryExists(char name[]) {
    return std::filesystem::exists(name);
}