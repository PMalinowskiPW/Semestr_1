#include <stdlib.h>
#include <stdio.h>

typedef struct wektor_t {
        int *tablica;
        int rozmiar;
}wektor_t;

wektor_t dodaj_element (wektor_t w, int i) {
	int pocz = 5;
        if (w.rozmiar == 0){
                w.tablica = malloc(pocz*sizeof(int));
		}
	if (w.rozmiar < pocz){
	        w.tablica[w.rozmiar] = i;
        	w.rozmiar += 1;
		}
        else{
                w.tablica = realloc(w.tablica, (w.rozmiar +1) * sizeof(int));

        w.tablica[w.rozmiar] = i;
        w.rozmiar += 1;
	}
return w;
}


void wypisz_wektor(FILE *out,wektor_t w ) {

        fprintf(out, "[ ");
        for (int i = 0; i < w.rozmiar; i++)
                fprintf(out, "%i ", w.tablica[i]);

        fprintf(out, "]\n");
}
