#include "OperacjeMacierzowe.c"
#include <stdio.h>

#define N 2

int zapiszMacierz(char *const path, char *const nazwa, int n1, int n2, double *M)
{
	FILE *wp;
	if ((wp = fopen(path, "w")) == NULL) return 1;
	if (piszMacierz(wp, nazwa, n1, n2, M)) return 0;
	return 1;
}



int main()
{
	double V[N] = {0, 1};
	
	
	zapiszMacierz("V.txt", "V", 1, 2, &V[0]);
	
	
	return 0;
}
