#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"lib.h"

int main(){
	//x and y coordinate values
	int m=3, n=8;
	
	//Defining the matrices or linkedlist
    	Node *a = NULL;
	Node *b = NULL;
	Node *c = NULL;
	Node *d = NULL;
	Node *e1 = NULL;
	Node *x = NULL;
	Node *y = NULL;

	// load the values of D and e1 from .dat files
	d = loadtxt("d.dat");
	e1 = loadtxt("e1.dat");
	x = loadtxt("3.dat");
	y = loadtxt("8.dat");
	
	//Performing required operations for A and saving in a.dat file
	a = linalg_add_x(d,3);
	save(a, "a.dat");
	
	//Performing required operations for B and saving in b.dat file
	b = linalg_add_y(a,8);
	save(b,"b.dat");
    	
    	//Performing required operations for C and saving in c.dat file
	c = linalg_add_x(b,3);
	save(c,"c.dat");
}	
