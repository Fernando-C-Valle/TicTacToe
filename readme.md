# Introduction
## Tic Tac Toe game

Tic Tac Toe console application using C++.

# How does it work?
The working is pretty simple. Once the game is running, each player can get a nickname, and when playing,
they can type a valid position, chosing from one through nine each time. The game will automatically switch turns.

#Execution
This game was developed in a Linux OS, for those who would like to give it a try in the same system, the compilation 
process can be done by following the next steps.

### Install build essential
sudo apt-get install build-essential -y

This will install the required packages for the program to work, like the compilers g++ and gcc.

###Compile the code
g++ -Wall -o executableName ticTacToe.cpp

In order to compile the code, type this command. I used the g++ compiler, the -Wall warning options, -o to create 
the executable file and give it a name, and finally the cpp source code file.

### Run
./executableName
Now you can execute the program and give it a try.

