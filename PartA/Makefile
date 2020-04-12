CC = gcc
FLAGS = -Wall -g

# $@ - the file on the left side of the :
# $< - the first name in the dependencies list
# $^ - the right side of :

all: hello_Ariel1 hello_Ariel2 hello_Ariel3

hello_Ariel1: main1_1.o hello_Ariel.o
	$(CC) $(FLAGS) -o $@ $^

hello_Ariel2: main1_2.o libhello.so
	gcc -Wall -g -o $@ $< ./libhello.so

hello_Ariel3: main1_3.o libhello.so
	gcc -Wall -g -o $@ $< -ldl

libhello.so: hello_Ariel.o
	gcc -shared -o $@ -fPIC $^	

hello_Ariel.o: hello_Ariel.c hello_Ariel.h
	$(CC) $(FLAGS) -c -fPIC $<

main1_3.o: main1_3.c hello_Ariel.h
	$(CC) $(FLAGS) -c $<	

main1_2.o: main1_2.c hello_Ariel.h
	$(CC) $(FLAGS) -c $<	

main1_1.o: main1_1.c hello_Ariel.h
	$(CC) $(FLAGS) -c $<

.PHONY: clean all

clean:
	rm -f *.o *.so hello_Ariel1 hello_Ariel2 hello_Ariel3
