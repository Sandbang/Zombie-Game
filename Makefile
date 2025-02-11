
output:
	gcc main.c -o game.exe -O1 -Wall -std=c99 -Wno-missing-braces -Include/ -L lib/ -lfile_read -lraylib -lopengl32 -lgdi32 -lwinmm