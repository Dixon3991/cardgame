#! /bin/bash


function clean() {
    exe_file="tcolor.cgi"
    if [ -f $exe_file ] 
    then
        rm ./tcolor.cgi;
        echo "Cleaned"
    else
        echo "Clean"
    fi
}

function make() {
    echo "Starting compilation.."
    g++ tcolor.cpp -o tcolor.cgi;
    echo "Compilation complete!"
}

function run() {
    echo "Running compiled code.."
    chmod +x tcolor.cgi;
    ./tcolor.cgi;

}


function setUp() {
    clean 
    make
    run

}

setUp