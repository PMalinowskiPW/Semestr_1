#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "biblioteka.h"
#include "skorowidz.h"

int main( int argc, char **argv ) {
// obsługa błędów wywołania. Obsługiwana przez funkcję pomoc
  if (pomoc(argc, argv) == 1) {
	 fprintf (stderr, "Wywołanie: ./a.out nazwa_pliku_z_danymi.txt nazwa_pliku_wyjścia.txt słowa_do_wyszukania\n");
 	 return EXIT_FAILURE;
  }
  if (pomoc(argc, argv) == 2) {
	 fprintf (stderr, "Wywołanie: ./a.out nazwa_pliku_z_danymi.txt nazwa_pliku_wyjścia.txt słowa_do_wyszukania\n");
         fprintf (stderr, "Plik wyjściowy musi mieć rozszerzenie .txt\n");		
	return EXIT_FAILURE;		
  }

  FILE *in = argc > 1 ? fopen( argv[1], "r") : stdin;
  FILE *out = argc > 2 ? fopen(argv[2], "w") : stdout;

  skorowidz_t skorowidz = zainicjuj_skorowidz( argc, argv);

  if( skorowidz.ile_slow == 0 ) {
    fprintf( stderr, "%s: błąd: proszę podać słowa do wyszukiwania\n", argv[0] );
    return EXIT_FAILURE;
  }
  if( in == NULL ) {
    fprintf( stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[1] );
    return EXIT_FAILURE;
  }
  if( out == NULL ) {
    fprintf( stderr, "%s: błąd: nie mogę pisać do pliku %s\n", argv[0], argv[2] );
    return EXIT_FAILURE;
  }

  wczytaj_skorowidz( &skorowidz, in );
  wypisz_skorowidz( skorowidz, out );

  return EXIT_SUCCESS;
}
