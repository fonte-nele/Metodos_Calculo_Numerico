#include <bits/stdc++.h>
#include "raizes.h"
using namespace std;

void GaussPivoteamentoParcial(float **a, int n, float *b)
{
	int i, j, k, r;
	float w, m, aux;

	for (k = 0; k < n; k++)
	{
		w = fabs(a[k][k]);
		r = k;
		for (i=k; i<n; i++)
		{
			if (fabs(a[i][k]) > w)
			{
				w = fabs(a[i][k]);
				r = i;
			}
		}
		for (j=k; j<n; j++)
		{
			aux = a[k][j];
			a[k][j] = a[r][j];
			a[r][j] = aux;
		}
		aux = b[k];
		b[k] = b[r];
		b[r] = aux;
		for (i = k+1; i < n; i++)
		{
			m = -a[i][k] / a[k][k];
			for (j=k+1; j<n; j++)
			{
				a[i][j] = a[i][j] + m * a[k][j];    
			}
			b[i] = b[i] + m * b[k];    
		}    
	}    
}

float Substituicao_Retroativa(float** coef, int n, float* termosInd, float* x)
{
	double soma;
	x[n-1] = termosInd[n-1]/coef[n-1][n-1];
	for(int i=n-2; i>=0; i--)
	{
		soma = 0;
		for(int j=i+1; j<n; j++)
		{
			soma = soma + coef[i][j]*x[j];
		}
		x[i] = 	(termosInd[i] - soma)/coef[i][i];
	}
	return* x;
}

void imprimeSolucao(float *x, int n)
{
	cout<<"\n==== SOLUCAO ===="<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<" x"<<i+1<<" = "<<x[i]<<endl;
	}
	cout<<"================="<<endl;
}