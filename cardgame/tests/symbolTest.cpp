/* https://stackoverflow.com/questions/16944750/c-unicode-characters-printing */
#include <clocale>
#include <iostream>
#include <ctime>
#include<stdlib.h>
#include "../include/TColor.h"

int main()
{
    setlocale(LC_ALL, "");
    std::wcout << std::endl << L"\u2665" << std::endl;
    std::wcout << std::endl << L"\u2666" << std::endl;
    std::wcout << std::endl << L"\u2663" << std::endl;
    std::wcout << std::endl << L"\u2660" << std::endl;

    print("\u2665", color_red, color_white);
    print("\u2666", color_red, color_white);
    print("\u2663", color_black, color_white);
    print("\u2660", color_black, color_white);
    return 0;
}