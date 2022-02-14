# Starter Makefile
# add .cpp and .h files as specified in each task.
OBJECTS=main.o reservoir.o

main: main.o reservoir.o
	g++ -o main $(OBJECTS)

main.o: main.cpp reservoir.h
	g++ -c main.cpp

reservoir.o: reservoir.cpp reservoir.h
	g++ -c reservoir.cpp
clean:
	rm -f $(OBJECTS)
