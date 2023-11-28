#ifndef SKOROWIDZ_H_
#define SKOROWIDZ_H_

#include "wektor.h"

typedef struct skorowidz_t {
        int ile_slow;
        char **slowa;
        wektor_t *linie;
}skorowidz_t;

skorowidz_t zainicjuj_skorowidz( int argc, char **argv );

void filtruj_bufor(char *buf);

void wczytaj_skorowidz (skorowidz_t * skorowidz, FILE *in);

void wypisz_skorowidz( skorowidz_t skorowidz, FILE *out );

#endif
