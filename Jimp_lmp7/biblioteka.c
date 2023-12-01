#include <stdio.h>
#include <string.h>

#include "biblioteka.h"

void filtruj_bufor(char buf[]) {
        int i = 0;

        while (buf[i]) {
                if (buf[i] < 'A'&& buf[i]> 0)
                        buf[i] = ' ';
                i++;
        }
}

int pomoc (int argc, char **argv) {
	char *nazwa_pliku = argc > 2 ? argv[2] : NULL;

	if (argc < 2) 
		return 1;

	if (nazwa_pliku != NULL) {
		 char txt[] = ".txt";
		
		 if (strstr(nazwa_pliku, txt) == NULL) 
			return 2;
	}
	return 0; 
}
