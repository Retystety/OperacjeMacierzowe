#include "funTabTekst.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 9999

unsigned _D = 1;

void DEBUG()
{
	printf("OK %i\n", _D++);
}


unsigned czytajLinie(char *const skad, char *linia) 
{
	unsigned i = 0;
	while (linia[i] = skad[i])
	{
		if (linia[i] == '\n') 
		{
			linia[i] = 0;
			i++;
			return i;
		}
		i++;
	}
	return i;
}

bool nastLiczba(char *const linia, char *liczba, unsigned *i_ptr)
{
	unsigned i = *i_ptr;
	unsigned j = 0;
	while (linia[i])
	{
		//printf("%i\n", j);
		if (linia[i] == ';')
		{
			liczba[j] = '\0';
			i++;
			*i_ptr = i; 
			return true;
		}
		
		liczba[j] = linia[i];
		i++;
		j++;
	}
	return false;
}

bool czytajWiersz(char *linia, int n, double *W)
{
	unsigned i = 0;
	unsigned x = 0;
	char liczba[MAX];
	double wartosc;
	while (nastLiczba(linia, liczba, &i))
	{	
		//printf("%i\n", i);
		wartosc = atof(liczba);
		W[x] = wartosc;
		
		x++;
		if(x == n) return true;
	}
	return false;
}

bool wczytajMacierz(FILE *wp, char *nazwa, int n1, int n2, double *M)
{
	char tekst[MAX];
	
	if (czytajTekst(wp, tekst, MAX) < 2) return false;
	
	/*
	unsigned iter = 0;
	while(tekst[iter])
	{
		
		printf("%i: %c\n", iter, tekst[iter]);
		iter ++;
	}
	*/
	
	unsigned nast = czytajLinie(tekst, nazwa);
	
	unsigned i = 0;
	while (i < n1)
	{
		if (nast >= MAX) return false;
		
		char linia[MAX];
		unsigned len = czytajLinie(&tekst[nast], linia);

		if (len == 0) return false;
		nast += len;
		
		if (!czytajWiersz(linia, n2, &M[i * n2])) return false;
		
		i++;
	}
	
	return true;	
}

int czytajMacierz(FILE *wp, char *nazwa, int n, double M[n][n])
{
	return wczytajMacierz(wp, nazwa, n, n, &M[0][0]);
}

int czytajWektor(FILE *wp, char *nazwa, int n, double V[n])
{
	return wczytajMacierz(wp, nazwa, 1, n, &(V[0]));
}

bool piszZnak(char *gdzie, char znak, unsigned n)
{
	if (n < MAX)
	{
		gdzie[n] = znak;
		return true;
	}
	return false;
}

double get(double *const tab, unsigned x, unsigned y, unsigned n)
{
	return *(tab + x*n + y);
}

bool piszMacierz(FILE *wp, char *nazwa, int n1, int n2, double *M)//double M[n1][n2])
{
	char macierz[MAX] = {0};	
	//for (unsigned i; i < (MAX - 1); i++) macierz[i] = 1;
	
	unsigned nast = 0;
	
	
	unsigned ile = snprintf(&macierz[nast], MAX - nast, "%s", nazwa);
	if (ile < 0) return false;
	nast += ile;
	
	if (!piszZnak(macierz, '\n', nast++)) return false; 
	
	for (unsigned i = 0; i < n1; i++)
	{
		for (unsigned j = 0; j < n2; j++)
		{
			ile = snprintf(&macierz[nast], MAX - nast, "%f", get(M, i, j, n1)); //nast = sprintf(macierz[nast], "%f", M[i][j]);
			if (ile < 0) return false;
			nast += ile;
			
			if (!piszZnak(macierz, ';', nast++)) return false;
		}
		if (!piszZnak(macierz, '\n', nast++)) return false;
	}
	
	//if ((wp = fopen(nazwa, "w")) == NULL) return false;
	if (fprintf(wp, "%s", &macierz[0]) < 0) return false;
	return true; 	
}

int wypiszMacierz(FILE *wp, char *nazwa, int n, double M[n][n])
{
	if (piszMacierz(wp, nazwa, n, n, &M[0][0])) return 1;
	return 0;
}

int wypiszWektor(FILE *wp, char *nazwa, int n, double V[n])
{ 
	if (piszMacierz(wp, nazwa, 1, n, &V[0])) return 1;
	return 0;
}

void transponojMacierz(int n, double M[n][n], double MT[n][n])
{
	for (unsigned i = 0; i < n; i++)
	{
		for (unsigned j = 0; j < n; j++)
		{
			MT[j][i] = M[i][j];
		}
	}
}
 
void dodajMacierze(int n, double A[n][n], double B[n][n], double C[n][n])
{
	for (unsigned i = 0; i < n; i++)
	{
		for (unsigned j = 0; j < n; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}	
}

void odejmijMacierze(int n, double A[n][n], double B[n][n], double C[n][n])
{
	for (unsigned i = 0; i < n; i++)
	{
		for (unsigned j = 0; j < n; j++)
		{
			C[i][j] = A[i][j] - B[i][j];
		}
	}	
}

void mnozLiczbaMacierz(int n, double c, double A[n][n],double B[n][n])
{
	for (unsigned i = 0; i < n; i++)
	{
		for (unsigned j = 0; j < n; j++)
		{
			B[i][j] = A[i][j] * c;
		}
	}	
}

double skalarny(int n, double *A, double *B)
{
	double e = 0;
	
	for (unsigned i = 0; i < n; i++)
	{
		e += *(A + i) * *(B + i);
	}
	
	return e;
}

void mnozMacierzWektor(int n, double A[n][n], double V[n], double W[n])
{
	for (unsigned i = 0; i < n; i++)
	{
		W[i] = skalarny(n, &A[i][0], &W[0]);
	}
}

void mnozMacierze(int n, double A[n][n], double B[n][n], double C[n][n])
{
	for (unsigned i = 0; i < n; i++)
	{
		for (unsigned j = 0; j < n; j++)
		{	
			double e = 0; 
			
			for (unsigned k = 0; k < n; k++)
			{
				e += A[i][k] * B[k][j];
			}
			
			C[i][j] = e; 
		}
	}
}

int czytajLiczbe(FILE *wp, char *nazwa, double *c)
{
	if(wczytajMacierz(wp, nazwa, 1, 1, c)) return 1;
	return 0;
}

int wypiszLiczbe(FILE *wp, char *nazwa, double c)
{
	if(piszMacierz(wp, nazwa, 1, 1, &c)) return 1;
	return 0;
}

