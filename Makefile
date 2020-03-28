CC = gcc
FLAGS = -Wall -g

all: hello_Ariel

hello_Ariel: main1_1.o hello_Ariel.o
	$(CC) $(FLAGS) -o $@ $^

hello_Ariel.o: hello_Ariel.c hello_Ariel.h
	$(CC) $(FLAGS) -c $<

main1_1.o: main1_1.c hello_Ariel.h
	$(CC) $(FLAGS) -c $<

.PHONY: clean all

clean:
	rm -f *.o hello_Ariel
