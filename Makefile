all:
	g++ sudoku.cpp scenes/menu_scene.cpp scenes/game_scene.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

run: all
	./a.out

mac-all:
	g++ scenes/game_scene.cpp scenes/menu_scene.cpp sudoku.cpp -framework IOKit -framework Cocoa -framework OpenGL `pkg-config --libs --cflags raylib` -lpthread -lm -ldl -std=c++11 -o sudoku.app

mac-run: mac-all
	./sudoku.app