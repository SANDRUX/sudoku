all:
	g++ sudoku.cpp scenes/menu_scene.cpp scenes/game_scene.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

run: all
	./a.out