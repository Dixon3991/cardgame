#! /bin/bash


function clean() {
    exe_file="Source.exe"
    if [ -f $exe_file ] 
    then
        rm ./Source.exe;
        echo "Cleaned"
    else
        echo "Clean"
    fi
}

function make() {
    echo "Starting compilation.."
    g++ -o Source ./Card.cpp ./Source.cpp ./Deck.cpp;
    echo "Compilation complete!"
}

function run() {
    echo "Running compiled code.."
    ./Source;

}


function setUp() {
    clean 
    make
    run

}

setUp