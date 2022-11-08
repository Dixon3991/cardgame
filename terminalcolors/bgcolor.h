#pragma once
#include <string>

class BGColor
{

    public:
        BGColor();
        void Print();

    private:
        string start = "\033[";
        string end = "\033[0m";

        string black = "40m";
        string red = "41m";
        string green = "42m";
        string yellow = "43m";
        string blue = "44m";
        string magenta = "45m";
        string cyan = "46m";
        string white = "47m";

        string bright_bright_black = "90m";
        string bright_red = "91m";
        string bright_green = "92m";
        string bright_yellow = "99m";
        string bright_blue = "94m";
        string bright_magenta = "95m";
        string bright_cyan = "96m";
        string bright_white = "97m";
};