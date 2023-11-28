#ifndef WEKTOR_H_
#define WEKTOR_H_

typedef struct wektor_t {
        int *tablica;
        int rozmiar;
}wektor_t;

wektor_t dodaj_element (wektor_t w, char c);

void wypisz_wektor(FILE *out,wektor_t w);

#endif
