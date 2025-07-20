# TIC-TAC-TOE
Tic tac toe made in C++


# DESCRIPTION :
Its a Tic tac toe game made purely in raylib library for c++.
Doesn't use any assets for textures.

# PROJECT SPECIFICATIONS:
Not an object oriented project. Made entirely for learning purposes as its my first project in c++ (and raylib also).
May not be the best with memory handling but doesn't take up more than 30 mb of RAM. 
Purely procedural code with lots of comment for understanding of what has been done.

# COMPILE THE CODE FROM SCRATCH

To compile the code from scratch :
1. Keep the include and Lib folder and its file in the same folder as the source code.
2. Enter the following command :
   > g++ game.cpp -Iinclude -Llib -lraylib -lopengl32 -lgdi32 -lwinmm -o game.exe -static -static-libgcc -static-libstdc++ -Wl,--subsystem,windows <
