#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "2048.h"

void step(int(*map)[4],int *score) {
	randomadd(map);
	printmap(map, score);
	char key;
	key = getchar();
	getchar();
	if (key == 'w' || key == 'W')
		uppush(map, score);
	else if (key == 's' || key == 'S')
		downpush(map, score);
	else if (key == 'a' || key == 'A')
		leftpush(map, score);
	else if (key == 'd' || key == 'D')
		rightpush(map, score);
}
int main() {
	int MAP[4][4] = {}, (*map)[4], * score = (int*)malloc(sizeof(int));
	*score = 0;
	map = MAP;
	while (!isFull(map))
		step(map,score);
	printf("\nGAMEOVER\t\tscore:\t%d\n",*score);
	return 0;
}