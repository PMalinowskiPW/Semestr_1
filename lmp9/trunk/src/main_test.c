#include "gauss.h"
#include "mat_io.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {

        Matrix * A = readFromFile(argv[1]);
        Matrix * b = readFromFile(argv[2]);

        if (A == NULL) return -1;
        if (b == NULL) return -2;
//        printToScreen(A);
//      printToScreen(b);

       	if (eliminate(A,b)== 1)
		printf("dzielenie przez 0");

//        printToScreen(A);
//        printToScreen(b);

        freeMatrix(A);
        freeMatrix(b);

        return 0;
}
