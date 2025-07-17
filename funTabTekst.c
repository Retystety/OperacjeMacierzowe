#include <stdio.h>
#include <stdbool.h>

unsigned wczytajTekst(char gdzie[], const unsigned max)
{
	unsigned i = 0;
	for (; i < (max - 1); i++)
	{
		char znak = getchar();
		if (znak == 0 || znak == EOF)
		{
			gdzie[i] = 0;
			return (i + 1);
		}
		gdzie[i] = znak;
	}
	gdzie[i] = 0;
	return max;
}

int wypiszTekst(FILE *plik, const char tekst[])
{
	return fprintf(plik, "%s", tekst);
}

int czytajTekst(FILE *plik, char tekst[], const unsigned max)
{
	unsigned i = 0;
	for (; i < (max - 1); i++)
	{
		if ((tekst[i] = fgetc(plik)) == EOF) break;
	}
	tekst[i] = 0;
	return i;
}

int kopiujTekst(const char skad[], char dokad[], const unsigned max)
{
	unsigned i = 0;
	for (; i < max; i++)
	{
		if ((dokad[i] = skad[i]) == 0) return (i + 1);
	}
	return max;
}

bool cyfra(const char znak)
{
	if (znak >= '0' && znak <= '9') return true;
	return false;
}

bool czyBialy(const char znak)
{
	if (znak == ' ' || znak == '\n' || znak == '\t' || znak == '\0' || znak == EOF) return true;
	return false;
}

int wszystkieZnaki(const char tekst[])
{
	unsigned i = 0;
	while (tekst[i])
	{
		i++;
	}
	return (i + 1);
}

int czarneZnaki(const char tekst[])
{
	unsigned i = 0;
	int cz = 0;
	do
	{
		if (!czyBialy(tekst[i])) cz++;
		i++;
	} while (tekst[i]);
	return cz++;
}

int linie(const char tekst[])
{
	unsigned i = 0;
	unsigned l = 1;
	while (tekst[i])
	{
		if (tekst[i] == '\n') l++;
		i++;
	}
	return l;
}

int slowa(const char tekst[])
{
	unsigned i = 0;
	int slowa = 0;
	bool ostatniKolor = true;
	do
	{
		bool kolor = czyBialy(tekst[i]);
		if (!kolor && ostatniKolor) slowa++;
		ostatniKolor = kolor;

		i++;
	} while (tekst[i]);
	return slowa;
}
