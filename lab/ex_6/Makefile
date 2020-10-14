CC = g++
FLAGS = -std=gnu++17 -pthread -Wall -fsanitize=leak -fsanitize=address -o
FILES = main.cpp models/Task.cpp models/Job.cpp
PROG = example6

all: compile run
compile:
	${CC} ${FILES} ${FLAGS} ${PROG}
run:
	./${PROG}
clean:
	rm ${PROG}
