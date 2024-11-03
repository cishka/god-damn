#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>


void Bubble(int mas[], int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size-i; ++j) {
			if (mas[j + 1] < mas[j]) {
				int tmp = mas[j + 1];
				mas[j + 1] = mas[j];
				mas[j] = tmp;
			}
		}
	}
}

void SearcSort(int mas[], int size) {
	for (int i = 0; i < size; ++i) {
		int k = i;
		for (int j = i + 1; j < size; ++j) {
			if (mas[j] < mas[k]) {
				k = j;
			}
		}
		int tmp = mas[k];
		mas[k] = mas[i];
		mas[i] = tmp;
	}
}

void Insertion(int mas[], int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = i - 1; j >= 0; --j){
			if (mas[j] > mas[j + 1]) {
				int tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
		}
	}
}


int main() {
	int size;
	printf("Vvedite dliny mass\n");
	scanf_s("%d", &size);
	int* (mas) = (int*)malloc(size);
	srand(time(NULL));


	for (int i = 0; i < size; ++i) {
		mas[i] = rand() % 10;
	}
	for (int i = 0; i < size; ++i) {
		printf("%d", mas[i]);
	}

	int a;
	printf("vvedite reshim sorta\n");
	printf("1)sort bubbl\n");
	printf("2)sort search\n");
	printf("3)sort insertion\n");
	scanf_s("%d", &a);
	if (a == 1) {
		time_t t0 = time(0);
		Bubble(mas,size);
		time_t t1 = time(0);
		double time_in_sec = difftime(t1, t0);
		printf("%d", time_in_sec);
	}
	if (a == 2) {
		SearcSort(mas, size);
	}
	if (a == 3) {
		Insertion(mas, size);
	}
	for (int i = 0; i < size; ++i) {
		printf("%d", mas[i]);
	}
}