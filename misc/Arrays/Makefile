PROJECT = arrays
CC = gcc
OBJ = arrays.o main.o

all: $(PROJECT)

.c.o:
	$(CC) -g -c -std=c99 $<

$(PROJECT): $(OBJ)
	$(CC) $(OBJ) -o $(PROJECT)

clean:
	rm -f $(PROJECT) $(OBJ)
