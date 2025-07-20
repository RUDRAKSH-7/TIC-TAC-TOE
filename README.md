# TIC-TAC-TOE
Tic tac toe made in C++

## DOWNLOAD THE EXE FILE FOR PLAYING DIRECTLY

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
   > g++ game.cpp -Iinclude -Llib -lraylib -lopengl32 -lgdi32 -lwinmm -o game.exe -static -static-libgcc -static-libstdc++ -Wl,--subsystem,windows

THIS COMMAND STATICALLY LINKS ALL RAYLIB HEADER FILES AND LIBRAYLIB.a FILES to create a single exe that doesn't open up the console.

## RUN THE ABOVE COMMAND ONLY IN COMMAND PROMPT

## YOU CAN ALSO USE THE GO.BAT FILE INCLUDED WITH THE SOURCE.zip TO COMPILE WITH JUST A CLICK !

# DEPENDENCY\
1. winlibs g++ for x64 systems
2. raylib, its optional cz I already included the required header files with the source code
3. OPENGL SUPPORT IS NECESSARY  !!!
