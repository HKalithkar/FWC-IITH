#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"lib.h"

int main(){
	//Initializing the variables as matrices
	double **a, **b, **c, **d, **e1, **x, **y;
	double m=2, n=1;

	// loading the point D and e1 from text files
	d = loadtxt("d.dat", m, n);
	e1 = loadtxt("e1.dat", m, n);
	x = loadtxt("3.dat", m, n);
	y = loadtxt("8.dat", m, n);

	//Finding the points A, B and C by using point D as reference
	a = linalg_add(x,d,m,n);
	b = linalg_add(x,y,m,n);
	c = linalg_add((matmult(2,x,m,n)),y,m,n);

	// Saving the points A, B and C to .dat files
	save_a(a,m,n);
	save_b(b,m,n);
	save_c(c,m,n);
}	
