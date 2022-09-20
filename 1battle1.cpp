#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printbattle(int b1, int b2, int b3, int b4) {
	printf("================COMPUTER==================\n\n\t");
	if (b1)
		printf("%d", b1);
	printf("\t\t\t");
	if (b2)
		printf("%d", b2);
	printf("\t\n\n==========================================\n\n\t");
	if (b3)
		printf("%d", b3);
	printf("\t\t\t");
	if (b4)
		printf("%d", b4);
	printf("\t\n\n==================YOU=====================\n");
}
void printmenu(int b1, int b2, int b3, int b4) {
	if (b1 && b3)
		printf("1 : your %d add computer's %d.\n", b3, b1);
	if (b2 && b3)
		printf("2 : your %d add computer's %d.\n", b3, b2);
	if (b1 && b4)
		printf("3 : your %d add computer's %d.\n", b4, b1);
	if (b2 && b4)
		printf("4 : your %d add computer's %d.\n", b4, b2);
}
void printstep(int b1, int b2, int b3, int b4, int c) {
	if (c == 1)
		printf("computer's %d add your %d.\n", b3, b1);
	if (c == 2)
		printf("computer's %d add your %d.\n", b3, b2);
	if (c == 3)
		printf("computer's %d add your %d.\n", b4, b1);
	if (c == 4)
		printf("computer's %d add your %d.\n", b4, b2);
}
void add(int* b1, int* b2, int* b3, int* b4, int c) {
	if (c == 1)
		*b3 = (*b3 + *b1) % 10;
	else if (c == 2)
		*b3 = (*b3 + *b2) % 10;
	else if (c == 3)
		*b4 = (*b4 + *b1) % 10;
	else if (c == 4)
		*b4 = (*b4 + *b2) % 10;
	return;
}
int ifComputerZero(int* b1, int* b2, int* b3, int* b4) {
	int c[4] = {}, r, t=0;
	if (*b3 + *b1 == 10 && *b1 % 10 && *b3 % 10)
		c[t++] = 1;
	if (*b4 + *b1 == 10 && *b1 % 10 && *b4 % 10)
		c[t++] = 2;
	if (*b3 + *b2 == 10 && *b2 % 10 && *b3 % 10)
		c[t++] = 3;
	if (*b4 + *b2 == 10 && *b2 % 10 && *b4 % 10)
		c[t++] = 4;
	if (!(c[0] || c[1] || c[2] || c[3]))
		return 0;
	srand((int)time(NULL));
	r = rand() % t;
	return c[r];
}
int ifYouZero(int* b1, int* b2, int* b3, int* b4) {
	int c[4] = {}, m, r, t = 0;
	m = *b1 + *b3;
	if ((m + *b3) % 10 && (m + *b4) % 10 && *b1 % 10 && *b3 % 10)
		c[t++] = 1;
	m = *b1 + *b4;
	if ((m + *b3) % 10 && (m + *b4) % 10 && *b1 % 10 && *b4 % 10)
		c[t++] = 2;
	m = *b2 + *b3;
	if ((m + *b3) % 10 && (m + *b4) % 10 && *b2 % 10 && *b3 % 10)
		c[t++] = 3;
	m = *b2 + *b4;
	if ((m + *b3) % 10 && (m + *b4) % 10 && *b2 % 10 && *b4 % 10)
		c[t++] = 4;
	srand((int)time(NULL));
	if (!(c[0] || c[1] || c[2] || c[3])) {
		if (*b1 % 10 && *b2 % 10) {
			r = rand() % 4;
			return r + 1;
		}
		else if (*b1 % 10 && *b2 % 10 == 0) {
			r = rand() % 2;
			return r + 1;
		}
		else {
			r = rand() % 2;
			return r + 3;
		}
	}
	r = rand() % t;
	return c[r];
}
void computer(int* b1, int* b2, int* b3, int* b4) {
	int r;
	r = ifComputerZero(b1, b2, b3, b4);
	if (r) {
		printstep(*b3, *b4, *b1, *b2, r);
		add(b3, b4, b1, b2, r);
		return;
	}
	r = ifYouZero(b1, b2, b3, b4);
	printstep(*b3, *b4, *b1, *b2, r);
	add(b3, b4, b1, b2, r);
	return;
}
void main() {
	int b1 = 1, b2 = 1, b3 = 1, b4 = 1, c;
	while ((b1 % 10 || b2 % 10) && (b3 % 10 || b4 % 10)) {
		printbattle(b1, b2, b3, b4);
		printmenu(b1, b2, b3, b4);
		scanf_s("%d", &c);
		add(&b1, &b2, &b3, &b4, c);
		if (!(b1 % 10 || b2 % 10) && (b3 % 10 || b4 % 10))
			break;
		computer(&b1, &b2, &b3, &b4);
	}
	if (b1 % 10 == 0 && b2 % 10 == 0)
		printf("You lose!");
	else
		printf("You win!");
}