# Starter Makefile
# add .cpp and .h files as specified in each task.
OBJECTS=main.o reservoir.o reverseorder.o

main: main.o reservoir.o reverseorder.o
	g++ -o main $(OBJECTS)

main.o: main.cpp reservoir.h reverseorder.h
	g++ -c main.cpp

reservoir.o: reservoir.cpp reservoir.h reverseorder.h
	g++ -c reservoir.cpp

reverseorder.o: reverseorder.cpp reverseorder.h reservoir.h

clean:
	rm -f $(OBJECTS)
