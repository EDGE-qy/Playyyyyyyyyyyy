#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef _2048_H_
#define _2048_H_
void printline(int* line) {
	printf("==================================\n||");
	if (line[0])
		printf("%d", line[0]);
	printf("\t||");
	if (line[1])
		printf("%d", line[1]);
	printf("\t||");
	if (line[2])
		printf("%d", line[2]);
	printf("\t||");
	if (line[3])
		printf("%d", line[3]);
	printf("\t||\n");
}
void printmap(int(*map)[4], int* score) {
	printf("2048GAME\t\tscore:\t%d\n\n", *score);
	printline(map[0]);
	printline(map[1]);
	printline(map[2]);
	printline(map[3]);
	printf("==================================\n");
}
void uppush(int(*map)[4], int* score) {
	int i = 0;
	for (i = 0; i < 4; i++) {
		if (!map[2][i]) {
			map[2][i] = map[3][i];
			map[3][i] = 0;
		}
		if (!map[1][i]) {
			map[1][i] = map[2][i];
			map[2][i] = map[3][i];
			map[3][i] = 0;
		}
		if (!map[0][i]) {
			map[0][i] = map[1][i];
			map[1][i] = map[2][i];
			map[2][i] = map[3][i];
			map[3][i] = 0;
		}
		if (map[0][i] && map[0][i] == map[1][i]) {
			map[0][i] *= 2;
			*score += map[0][i];
			map[1][i] = map[2][i];
			map[2][i] = map[3][i];
			map[3][i] = 0;
		}
		if (map[1][i] && map[1][i] == map[2][i]) {
			map[1][i] *= 2;
			*score += map[1][i];
			map[2][i] = map[3][i];
			map[3][i] = 0;
		}
		if (map[2][i] && map[2][i] == map[3][i]) {
			map[2][i] *= 2;
			*score += map[2][i];
			map[3][i] = 0;
		}
	}
}
void downpush(int(*map)[4], int* score) {
	int i;
	for (i = 0; i < 4; i++) {
		if (!map[1][i]) {
			map[1][i] = map[0][i];
			map[0][i] = 0;
		}
		if (!map[2][i]) {
			map[2][i] = map[1][i];
			map[1][i] = map[0][i];
			map[0][i] = 0;
		}

		if (!map[3][i]) {
			map[3][i] = map[2][i];
			map[2][i] = map[1][i];
			map[1][i] = map[0][i];
			map[0][i] = 0;
		}
		if (map[3][i] && map[3][i] == map[2][i]) {
			map[3][i] *= 2;
			*score += map[3][i];
			map[2][i] = map[1][i];
			map[1][i] = map[0][i];
			map[0][i] = 0;
		}
		if (map[2][i] && map[2][i] == map[1][i]) {
			map[2][i] *= 2;
			*score += map[2][i];
			map[1][i] = map[0][i];
			map[0][i] = 0;
		}
		if (map[1][i] && map[1][i] == map[0][i]) {
			map[1][i] *= 2;
			*score += map[1][i];
			map[0][i] = 0;
		}
	}
}
void leftpush(int(*map)[4], int* score) {
	int i;
	for (i = 0; i < 4; i++) {
		if (!map[i][2]) {
			map[i][2] = map[i][3];
			map[i][3] = 0;
		}
		if (!map[i][1]) {
			map[i][1] = map[i][2];
			map[i][2] = map[i][3];
			map[i][3] = 0;
		}
		if (!map[i][0]) {
			map[i][0] = map[i][1];
			map[i][1] = map[i][2];
			map[i][2] = map[i][3];
			map[i][3] = 0;
		}
		if (map[i][0] && map[i][0] == map[i][1]) {
			map[i][0] *= 2;
			*score += map[i][0];
			map[i][1] = map[i][2];
			map[i][2] = map[i][3];
			map[i][3] = 0;
		}
		if (map[i][1] && map[i][1] == map[i][2]) {
			map[i][1] *= 2;
			*score += map[i][1];
			map[i][2] = map[i][3];
			map[i][3] = 0;
		}
		if (map[i][2] && map[i][2] == map[i][3]) {
			map[i][2] *= 2;
			*score += map[i][2];
			map[i][3] = 0;
		}
	}
}
void rightpush(int(*map)[4], int* score) {
	int i;
	for (i = 0; i < 4; i++) {
		if (!map[i][1]) {
			map[i][1] = map[i][0];
			map[i][0] = 0;
		}
		if (!map[i][2]) {
			map[i][2] = map[i][1];
			map[i][1] = map[i][0];
			map[i][0] = 0;
		}
		if (!map[i][3]) {
			map[i][3] = map[i][2];
			map[i][2] = map[i][1];
			map[i][1] = map[i][0];
			map[i][0] = 0;
		}
		if (map[i][3] && map[i][3] == map[i][2]) {
			map[i][3] *= 2;
			*score += map[i][3];
			map[i][2] = map[i][1];
			map[i][1] = map[i][0];
			map[i][0] = 0;
		}
		if (map[i][2] && map[i][2] == map[i][1]) {
			map[i][2] *= 2;
			*score += map[i][2];
			map[i][1] = map[i][0];
			map[i][0] = 0;
		}
		if (map[i][1] && map[i][1] == map[i][0]) {
			map[i][1] *= 2;
			*score += map[i][1];
			map[i][0] = 0;
		}
	}
}
void randomadd(int(*map)[4]) {
	int num, place = 16, i, j[16] = {};
	srand((int)time(NULL));
	num = 2 + 2 * (rand() % 2);
	for (i = 0; i < 16; i++) {
		if (map[i / 4][i % 4]) {
			j[i] = 1;
			place--;
		}
	}
	srand((int)time(NULL));
	place = rand() % place;
	i = -1;
	do {
		i++;
		while (j[i])
			i++;
		place--;
	} while (place >= 0);
	map[i / 4][i % 4] = num;
}
bool isFull(int(*map)[4]) {
	int i;
	for (i = 0; i < 16; i++)
		if (!map[i / 4][i % 4])
			return false;
	return true;
}
#endif
