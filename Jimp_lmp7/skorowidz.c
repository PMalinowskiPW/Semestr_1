#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "biblioteka.h"
#include "wektor.h"

#define BUFSIZE 8192

 typedef struct skorowidz_t {
        int ile_slow;
        char **slowa;
        wektor_t *linie;
} skorowidz_t;


skorowidz_t zainicjuj_skorowidz( int argc, char **argv ) {
        skorowidz_t skorowidz;

        skorowidz.ile_slow = argc-3;
        skorowidz.slowa = malloc( skorowidz.ile_slow * sizeof(char*));
        skorowidz.linie = malloc( skorowidz.ile_slow * sizeof(wektor_t));
        for(int i = 0; i < (argc-3); i++ ) {
                skorowidz.slowa[i] = argv[i+3];
                skorowidz.linie[i].rozmiar = 0;
        }

return skorowidz;
}

void wczytaj_skorowidz (skorowidz_t * skorowidz, FILE *in) {
        char buf[BUFSIZE];
        int nr_linii= 0;
        char * tmp_ptr;

        while( fgets( buf, BUFSIZE, in ) != NULL ) {
                 filtruj_bufor( buf );
		 printf("po %s\n",buf);

                for( int i= 0; i < skorowidz->ile_slow; i++ ) {
                        tmp_ptr = buf;
                	
			while ((tmp_ptr = strstr(tmp_ptr, skorowidz->slowa[i])) != NULL) {
                                        skorowidz->linie[i] = dodaj_element(skorowidz->linie[i], nr_linii);

					while (tmp_ptr && *tmp_ptr != ' ')
						tmp_ptr++;                         
                         }
                }
                nr_linii++;
        }
}

void wypisz_skorowidz(skorowidz_t skorowidz, FILE *out ) {
        int i,j;

        for( i = 0; i < skorowidz.ile_slow; i++ ) {
                if( skorowidz.linie[i].rozmiar > 0 ) {
                       
                        printf( "słowo \"%s\" wystąpiło %i razy w liniach: ", skorowidz.slowa[i], skorowidz.linie[i].rozmiar);
                        wypisz_wektor(stdout, skorowidz.linie[i]);

                        if (out != stdout) {
                                fprintf(out, "\"%s\" %i ",  skorowidz.slowa[i], skorowidz.linie[i].rozmiar);
                                wypisz_wektor(out, skorowidz.linie[i]);
                        }
               } else
                        printf( "nie napotkano słowa \"%s\"\n", skorowidz.slowa[i] );
  }
}
