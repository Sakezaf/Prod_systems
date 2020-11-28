CC = g++
FLAGS = -std=gnu++17 -pthread -Wall -fsanitize=leak -fsanitize=address -Wextra -Wpedantic -Wno-unused-parameter -O3 -o
FILES = main.cpp models/Resource.cpp models/Job.cpp
PROG = example7

all: compile run
compile:
	${CC} ${FILES} ${FLAGS} ${PROG}
run:
	./${PROG}
clean:
	rm ${PROG}
