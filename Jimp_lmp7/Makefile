a.out: main.o wektor.o biblioteka.o skorowidz.o
	$(CC) $^

main.o: biblioteka.h skorowidz.h
skorowidz.o: wektor.h biblioteka.h skorowidz.h
biblioteka.o: biblioteka.h
wektor.o: wektor.h
