#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNING

#include "stdio.h"
#include <stdlib.h>
#include "conio.h"
#include "malloc.h"
#include <locale>
#include <queue>
using namespace std;







void bfsd(int v, int** arr, int* dist, int m) {


	queue <int> q;
	q.push(v);
	dist[v] = 0;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		printf("%d, ", v);


		for (int j = 0; j < m; j++) {
			if ((arr[v][j] != 0) && (dist[j] == -1)) {
				q.push(j);
				dist[j] = dist[v] + arr[v][j];
			}

		}
	}


}



void main() {

	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	int n;

	printf("¬ведите размер массива: ");
	scanf("%d", &n);

	int** arr1 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		arr1[i] = (int*)malloc(n * sizeof(int));
	}

	int* dista = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			arr1[i][j] = rand() % 2;
			if (arr1[i][j] == 1) {
			 arr1[i][j] = rand() % 5; 
			}


		}
	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			arr1[j][i] = arr1[i][j];
			if (i == j) { arr1[i][j] = 0; }
			printf("%d  ", (arr1[i][j]));

		}
		printf("\n");
	}



	printf("\n\n\n");


	for (int i = 1; i < n; i++) {

		dista[i] = -1;

	}


	bfsd(0, arr1, dista, n);



	printf("\n\n\n");

	for (int i = 0; i < n; i++) {

		printf("%d  ", dista[i]);



	}

}
