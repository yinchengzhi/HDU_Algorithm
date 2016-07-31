#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

char Number[10][6] = { "zero","one","two","three","four","five","six","seven","eight","nine" };

int search(char *str) {
	int i;
	for (i = 0; i < 10; i++) {
		if (strcmp(Number[i], str) == 0) {
			break;
		}
	}
	return i;
}


void main() {
	char count[10];
	int a, b;
	while (1) {
		a = 0;
		while (scanf("%s", count) && strcmp(count, "+") != 0) {
			a = a * 10 + search(count);
		}
		b = 0;
		while (scanf("%s", count) && strcmp(count, "=") != 0) {
			b = b * 10 + search(count);
		}
		if (a == 0 && b == 0) {
			break;
		}
		else {
			printf("%d\n", a + b);
		}
	}
}