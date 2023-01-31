# Build
clang++ -std=c++17 -o output/derafsh src/main.cpp -lSDL2 -lSDL2_image -lSDL2_ttf

clang -o output/derafsh src/main.c src/lib/*.c -lGL -lglfw -lGLEW -lGL -lX11 -lGLU -lm
