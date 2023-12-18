a.out: main_test.o mat_io.o gauss.o backsubst.o
	$(CC) $^

main_test.o: mat_io.h gauss.h
gauss.o: mat_io.h gauss.h
mat_io.o: mat_io.h
backsubst.o: mat_io.h backsubst.h

