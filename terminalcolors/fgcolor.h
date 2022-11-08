#pragma once
#include <string>

class FGColor
{

    public:
        FGColor();
        void Print();

    private:
        string start = "\x1B[";
        string end = "\033[0m";

        string reset = "0m";

        string black = "30m";
        string red = "31m";
        string green = "32m";
        string yellow = "33m";
        string blue = "34m";
        string magenta = "35m";
        string cyan = "36m";
        string white = "37m";

        string bright_bright_black = "90m";
        string bright_red = "91m";
        string bright_green = "92m";
        string bright_yellow = "93m";
        string bright_blue = "94m";
        string bright_magenta = "95m";
        string bright_cyan = "96m";
        string bright_white = "97m";
};