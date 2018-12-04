#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;
ofstream g("date.out");
#define pi 3.14159265
#define POP_SIZE 100
#define RAND_NUMBER (rand() / ((double)RAND_MAX + 1))
int prec, nr_zec, p;
class chromo
{
	public:
	vector<bool>    bits;
	float     fitness;
	chromo() :fitness (0.0f) {}
	chromo(vector<bool> bts, float ftns) : bits(bts), fitness(ftns) {}

};
int precizie(double dmin, double dmax, int n)
{
	return (int)ceil(log((dmax - dmin) * pow(10, n)));
}
vector<bool> generate(int n)
{
	int i;
	vector<bool> x;
	for (i = 0; i < prec*n; i++)
	{
		x.push_back(rand() % 2);
	}
	return x;
}
double converttoint(vector<bool> x, int k, int l)
{
	double nr = 0;
	for (int i = k; i < l; i++)
		nr += x[i] * pow(2, l - i - 1);
	return nr;

}
vector<bool> vecin(int i, vector<bool> x)
{
	vector<bool> rez;
	rez = x;
	if (x[i] == 0) rez[i] = 1;
	else rez[i] = 0;
	return rez;
}
double decode(vector<bool> x, double dmin, double dmax, int k, int l)
{
	double var = converttoint(x, k, l);
	var = var / pow(2, prec);
	var = var * (dmax - dmin);
	var = var + dmin;
	return var;

}
double dejongsfunction(vector<bool> x, int n)
{
	double dmin, dmax, var;
	dmin = -5.12;
	dmax = 5.12;
	int i;
	double rezultat = 0;
	for (i = 0; i < n; i++)
	{
		var = decode(x, dmin, dmax, i * prec, (i + 1) * prec);
		rezultat = rezultat + pow(var, 2);

	}

	return rezultat;
}
double schwefelsfunction(vector<bool> x, int n)
{
	double dmin = -500;
	double dmax = 500;
	int i; double rezultat = 0, var, exp;
	for (i = 0; i < n; i++)
	{
		var = decode(x, dmin, dmax, i*prec, (i + 1)* prec);
		exp = -sin(sqrt(abs(var))) * var;
		rezultat += exp;
	}
	return rezultat;
}
double six_hump(vector<bool> x, int n)
{
	double var1, var2, rezultat;
	var1 = decode(x, -3, 3, 0, prec);
	var2 = decode(x, -2, 2, prec, 2 * prec);
	rezultat = (4 - 2.1*var1*var1 + pow(var1, 4) / 3)*var1*var1 + var1 * var2 + (-4 + 4 * pow(var2, 2))*pow(var2, 2);
	return rezultat;
}
double rastriginsfunction(vector<bool> x, int n)
{
	double dmin = -5.12;
	double dmax = 5.12;
	int i;
	double rezultat = 10 * n, var, exp;

	for (i = 0; i < n; i++)
	{
		var = decode(x, dmin, dmax, i*prec, (i + 1)*prec);
		var = var * 2 * pi;
		exp = pow(var, 2) - 10 * cos(var);
		rezultat += exp;
	}
	return rezultat;
}
vector<bool> GetRandomBits(int nr)
{
	vector<bool> rez;
	for (int i = 0; i < nr; i++)
		rez.push_back(rand() % 2);
	return rez;
}
void InitPop(chromo vector[POP_SIZE],int n, int k)
{
	for (int i = 0; i<POP_SIZE; i++)
	{
		vector[i].bits = GetRandomBits(n*k);
		vector[i].fitness = 0.0f;
	}
}
float AssignFitness(vector<bool> x, int function)
{
	for (int i = 0; i < x.size(); i++)
	{

	}
}
int main()
{
	int n,k,prec;
	srand((int)time(NULL));
	chromo Population[POP_SIZE];
	cout << "1: dejongfunction" << '\n';
	cout << "2: schwefelsfunctionn" << '\n';
	cout << "3: rastriginsfunction" << '\n';
	cout << "4: six hum function" << '\n' << '\n';
	cin >> f;
	cout << "Dati dimensiunea" << '\n';
	cin >> n;
	switch (f)
	{
	case 1:
	{
		prec = precizie(-5.12, 5.12, n);
		cout << prec << "nr biti ";
		break;
	}
	case 2:
	{
		prec = precizie(-500, 500, n);
		break;

	}
	case 3:
	{
		prec = precizie(-5.12, 5.12, n);
		break;
	}
	case 4:
	{
		prec = precizie(-3, 3, n);
		break;
	}
	default:
		break;
	}
	InitPop(Population, n, prec);
	for (int i = 0; i<POP_SIZE; i++)
	{
		Population[i].fitness = AssignFitness(Population[i].bits, f);

		TotalFitness += Population[i].fitness;
	}
}
