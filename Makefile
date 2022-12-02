all: main

main: main.cpp
	$(CXX) -o main main.cpp

clean:
	$(RM) main
