#! /bin/bash


function clean() {
    exe_file="terminal_colors.cgi"
    if [ -f $exe_file ] 
    then
        rm ./terminal_colors.cgi;
        echo "Cleaned"
    else
        echo "Clean"
    fi
}

function make() {
    echo "Starting compilation.."
    g++ terminal_colors.cpp -o terminal_colors.cgi;
    echo "Compilation complete!"
}

function run() {
    echo "Running compiled code.."
    chmod +x terminal_colors.cgi;
    ./terminal_colors.cgi;

}


function setUp() {
    clean 
    make
    run

}

setUp