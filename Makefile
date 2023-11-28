a.out: main.o wektor.o skorowidz.o
	$(CC) $^

main.o: wektor.h skorowidz.h
skorowidz.o: wektor.h skorowidz.h
list.o: wektor.h
