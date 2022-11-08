#! /bin/bash


function compileCardGame52() {
    exe_file="Source.exe"
    if [ -f $exe_file ] 
    then
        rm ./Source.exe;
        echo "Removed (old) Source.exe"
    else
        echo "Cleaned"
    fi
    echo "Starting compilation.."
    g++ -o Source ./Card.cpp ./Source.cpp ./Deck.cpp;
    echo "Compilation complete!"
    echo "Running compiled code.."
    ./Source;

}

compileCardGame52