#! /bin/bash
RED="31m"
GREEN="32m"
LIGHTCYAN="96m"
LIGHTGRAY="37m"
GRAY="90m"

BOLD="\e[1;"
ITALIC="\e[3;"

STARTCOLOR="\e["
ENDCOLOR="\e[0m"

function clean() {
    exe_file="symbolTest.exe"
    compiled_file="symbolTest"
    if [ -f $exe_file ]
    then
        rm ./symbolTest.exe;
        echo -e "${ITALIC}${GREEN}Cleaned ✓${ENDCOLOR}"
    elif [ -f $compiled_file ] 
    then
        rm ./symbolTest;
        echo -e "${ITALIC}${GREEN}Cleaned ✓${ENDCOLOR}"
    else
        echo -e "${ITALIC}${LIGHTCYAN}Clean ✓${ENDCOLOR}"
    fi
}

function make() {
    echo -e "${ITALIC}${GRAY}Starting compilation...${ENDCOLOR}"
    g++ -o symbolTest ./symbolTest.cpp;
    echo -e "${ITALIC}${GREEN}Compilation complete! ✓${ENDCOLOR}"
}

function run() {
    echo -e "${ITALIC}${GRAY}Running compiled tests..${ENDCOLOR}"
    echo ""
    ./symbolTest;

}


function setUp() {
    clean 
    make
    run
}

setUp