CC = gcc
FLAGS = -Wall -g

# $@ - the file on the left side of the :
# $< - the first name in the dependencies list
# $^ - the right side of :

all: app1 app2 app3 app4

app1: app1.o
	$(CC) $(FLAGS) -o $@ $^

app2: app2.o
	$(CC) $(FLAGS) -o $@ $^

app3: app3.o
	$(CC) $(FLAGS) -o $@ $^

app4: app4.o app1 app2 app3
	$(CC) $(FLAGS) -o $@ $<

app4.o: app4.c app1.o app2.o app3.o
	$(CC) $(FLAGS) -c $<	

app3.o: app3.c
	$(CC) $(FLAGS) -c $<	

app2.o: app2.c
	$(CC) $(FLAGS) -c $<	

app1.o: app1.c 
	$(CC) $(FLAGS) -c $<

.PHONY: clean all

clean:
	rm -f *.o app1 app2 app3 app4
