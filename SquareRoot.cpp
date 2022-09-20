#include<stdio.h>
#include<math.h>
int main() {
	double a=0.0, x1=0.0, x2=0.0;
	printf("Input a positive real number.\n");
	scanf("%lf", &a);
	x2 = a;
	do {
		x1 = x2;
		x2 = (x1 + a / x1)/2;
	} while (fabs(x1 - x2) >= 1e-5);
	printf("Its square root is %lf.\n", x2);
	return 0;
}