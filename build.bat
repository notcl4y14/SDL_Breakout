@echo off
g++ -I src/include -L src/lib -o SDL_Breakout.exe main.cpp src/*.cpp src/util/*.cpp -fpermissive -mwindows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf