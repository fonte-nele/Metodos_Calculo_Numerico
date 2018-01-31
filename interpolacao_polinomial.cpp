#include "interpolacao_polinomial.h"
#include <bits/stdc++.h>
using namespace std;

double metodoLagrange(double *x,double *y, double valor, int tam)
{
	double result = 0, L[tam];

	for(int i = 0; i < tam; i++)
	{
		L[i] = 1;
		for(int j = 0; j < tam; j++)
		{
			if(j != i)
				L[i] = L[i] * ((valor - x[j])/(x[i]-x[j]));	// Funcao de Lagrange!
		}
		result += L[i] * y[i];	// Valor do polinomio!
	}

	return result;
}