CC=g++
CFLAGS= -std=c++17 -Wall -w -g
USERLIBS= 
OFLAGS= -g -c
OBJS=main.o cardGameWar.o player.o cards.o
EXE=output


$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE) $(USERLIBS) -lm


main.o: main.cc
	$(CC) $(OFLAGS) main.cc

cardGameWar.o: cardGameWar.cc
	$(CC) $(OFLAGS) cardGameWar.cc

player.o: player.cc
	$(CC) $(OFLAGS) player.cc

cards.o: cards.cc
	$(CC) $(OFLAGS) cards.cc

clean:
	rm *.o output

cleanEmacs:
	rm *~
run: $(EXE)
	./output

redo: 
	make clean
	make run
