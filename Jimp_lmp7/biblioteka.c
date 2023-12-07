#include <stdio.h>
#include <string.h>

#include "biblioteka.h"
//usuwany z bufora znaki interpunkcyjne
void filtruj_bufor(char buf[]) {
        int i = 0;

        while (buf[i]) {
                if (buf[i] < 'A'&& buf[i]> 0)
                        buf[i] = ' ';
                i++;
        }
}


//sprawdzamy, czy argumenty są prawidłowo wprowadzone 
int pomoc (int argc, char **argv) {
	char *nazwa_pliku = argc > 2 ? argv[2] : NULL;// potrzebjemy przynajmniej 2 argumentów, plik wejscia, wyjścia

	if (argc < 2) 
		return 1;

	if (nazwa_pliku != NULL) {// sprawdzamy, czy plik out jest odpowiednio nazwany
		 char txt[] = ".txt";
		
		 if (strstr(nazwa_pliku, txt) == NULL) 
			return 2;
	}
	return 0; 
}
