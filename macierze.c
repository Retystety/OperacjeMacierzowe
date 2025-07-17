#include <stdio.h>

#include "OperacjeMacierzowe.h"
#include "stdlib.h"
#include <assert.h>

#define N 2

#define MAX 10000


int main()
{
	/*
	double T[N][N] = {1.0 , 2.0, 3.0, 4.0};
	wypiszMacierz(stdout, "T", N, T);
	*/
	
	double W[N];
	char linia[MAX] = "1.0;2.0;";
	assert(czytajWiersz(linia, N, W)); 
	assert(wypiszWektor(stdout, "W", N, W));
	
	double A[N][N];
	char nazwa_A[MAX];
	FILE *A_WP = fopen("A.txt", "r");
	assert(czytajMacierz(A_WP, nazwa_A, N, A));
	assert(wypiszMacierz(stdout, nazwa_A, N, A));
	
	double B[N][N];
	char nazwa_B[MAX];
	FILE *B_WP = fopen("B.txt", "r");
	assert(czytajMacierz(B_WP, nazwa_B, N, B));
	assert(wypiszMacierz(stdout, nazwa_B, N, B));
	
	double V[N];
	char nazwa_V[MAX];
	FILE *V_WP = fopen("V.txt", "r");
	assert(czytajWektor(V_WP, nazwa_V, N, V));
	assert(wypiszWektor(stdout, nazwa_V, N, V));
	
	double c;
	char nazwa_c[MAX];
	FILE *c_WP = fopen("c.txt", "r");
	assert(czytajLiczbe(c_WP, nazwa_c, &c));
	assert(wypiszLiczbe(stdout, nazwa_c, c));
	
	
	transponojMacierz(N, A, A);
	assert(wypiszMacierz(stdout, nazwa_A, N, A));
	
	mnozLiczbaMacierz(N, c, A, A);
	assert(wypiszMacierz(stdout, nazwa_A, N, A));
	
	dodajMacierze(N, A, B, A);
	odejmijMacierze(N, A, B, A);
	assert(wypiszMacierz(stdout, nazwa_A, N, A));
	
	mnozMacierzWektor(N, A, V, V);
	assert(wypiszWektor(stdout, nazwa_V, N, V));
	
	mnozMacierze(N, A, B, A);
	assert(wypiszMacierz(stdout, nazwa_A, N, A));
	
	
}

