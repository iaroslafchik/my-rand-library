#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdint.h>

unsigned long int next = 1;

void srand(int seed) {
	next = seed;
}

int rand(int min, int max) {
	next = next * 48271 + 0;
	return (unsigned int)(next/65536) % (max - min + 1) + min;
}

double drand(void) {
	return rand(0, 65535)/65536.0;
}

int main() {
	int a[16384];

	for (int i = 0; i < 16384; i++) {
		a[i] = 0;
	}

	for (int i = 0; i < 1000000; i++) {
		a[rand(-128, 128) + 8192]++;
	}

	for (int i = -8192; i < 8192; i++) {
		if (a[i + 8192] != 0) printf("\na[%d] = %d", i, a[i + 8192]);
	}

	for (int i = 0; i < 100; i++) {
		printf("\n%.15lf", drand());
	}
}