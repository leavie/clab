#include <stdio.h>
#include <math.h>
#define dx 0.0001	//the symbol dx was taken to represent an infinitesimally "small piece" of the independent variable x 

//a = lower limit,b = upper limit
double integrate(double (*f)(double), double a, double b) {
	double x, area = 0.0;
	for (x=a; x<b; x+=dx) {
		area = area + f(x)*dx;
	}
	return area;
}

double square(double x) {
	return x*x;
}

double cube(double x) {
	return x*x*x;
}

double other(double x) {
	return 2*x + x*x;
}

int main() {
	printf("The integral value with x^2 on the interval [0, 1] is %.3f\n", integrate(square,0,1));
	printf("The integral value with x^3 on the interval [0, 1] is %.3f\n", integrate(cube,0,1));
	printf("The integral value with 2x + x^2 on the interval [0, 1] is %.3f\n", integrate(other,0,1));
	printf("The integral value with sin(x) on the interval [0, £k] is %.f\n", integrate(sin,0,3.14159));
}
