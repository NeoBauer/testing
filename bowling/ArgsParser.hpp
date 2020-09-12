#pragma once

enum class CommandArguments {
    ERR_PROGRAM_NAME_ONLY = -2,
    ERR_WRONG_DIR_NAME,
    SOURCE_DIRECTORY_NAME,
    SOURCE_DIRECTORY_AND_OUTPUT_FILE,
    SHOW_HELP
};

class ArgsParser {
public:
    ArgsParser();
    ArgsParser(int argc, char* argv[]);
    CommandArguments CheckArguments(int ArgsNum, char* ArgsTab[]);

private:
    bool CheckIfDirectoryExists(char name[]);
};