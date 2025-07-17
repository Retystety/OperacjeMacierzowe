#include <stdio.h>

unsigned wczytajTekst(char gdzie[], const unsigned max); //wczytuje znaki z stdin do gdzie, nie wiecej niz max
int wypiszTekst(FILE *pilk, const char tekst[]); //wypisuje tekst do stdout
int czytajTekst(FILE *plik, char tekst[], const unsigned max); //wczytuje tekst z pliku do tekst, nie wiecej niz max

int kopiujTekst(const char skad[], char dokad[], const unsigned max); //kopiuje znaki z skad do gdzie, nie wiecej niz max

int wszystkieZnaki(const char tekst[]); //liczba wszystkich znakow
int czarneZnaki(const char tekst[]); //liczba czarnych znakow
int linie(const char tekst[]); //liczba znakow \n
int slowa(const char tekst[]); //liczba slow

