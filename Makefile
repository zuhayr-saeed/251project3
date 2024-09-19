CXXFLAGS = -O2 -Wall -I. -g -std=c++2a

tests: canvaslist.cpp shape.cpp canvaslist_tests.cpp
	g++ $(CXXFLAGS) canvaslist.cpp shape.cpp canvaslist_tests.cpp -lgtest -lgtest_main -lpthread -o canvaslist_tests
solution_tests: canvaslist_solution.o shape_solution.o canvaslist_tests.cpp
	g++ $(CXXFLAGS) canvaslist_solution.o shape_solution.o canvaslist_tests.cpp -lgtest -lgtest_main -lpthread -o solution_tests
canvaslist_main: canvaslist.cpp shape.cpp main.cpp
	g++ $(CXXFLAGS) canvaslist.cpp shape.cpp canvaslist_main.cpp -o canvaslist_main

run: canvaslist_main
	valgrind ./canvaslist_main

run_tests: tests
	valgrind ./canvaslist_tests --gtest_color=yes

run_solution_tests: solution_tests
	valgrind ./solution_tests --gtest_color=yes
