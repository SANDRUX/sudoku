all:
	g++ -o sudoku sudoku.cpp generate_map.cpp fill_with_zeros.cpp scenes/menu_scene.cpp scenes/game_scene.cpp scenes/game_over_scene.cpp scenes/win_game_scene.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

run: all
	./sudoku

mac-all:
	g++ -o sudoku sudoku.cpp generate_map.cpp fill_with_zeros.cpp scenes/game_scene.cpp scenes/menu_scene.cpp scenes/game_scene.cpp scenes/game_over_scene.cpp scenes/win_game_scene.cpp -framework IOKit -framework Cocoa -framework OpenGL `pkg-config --libs --cflags raylib` -lpthread -lm -ldl -std=c++11