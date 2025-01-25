#Makefile for Homework2
CXX = g++
OBJECTS = event.o main.o eventFactory.o searchingStrategy.o searchingContext.o
FLAGS = -std=c++20
SOURCE = $(wildcard *.cpp)

main: $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o main

# $< refers to the first prequisite
# $@ refers to the target
%.o: %.cpp %.h
	$(CXX) -c $< -o $@

run: main
	./main

echo:
	echo $(SOURCE)

clean: 
	rm -f *.o main