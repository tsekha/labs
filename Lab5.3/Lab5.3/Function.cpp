#include <iomanip>
#include <iostream>
#include <ctime>
#include "Function.h"

using namespace std;

void vvod_mass(int** a, int n, int m) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[j][i] = rand() % 100;
		}
	}
}

void vivod_mass(int** a, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(4) << a[j][i] << " ";
		}
		cout << '\n';
	}
}

void sort(int** a, int n, int m) {
	int min1 = 100000, min2 = 100000;

	for (int j = 0; j < m; j++) {

		int min_idx = j;

		int min1 = a[j][0];
		for (int i = 0; i < n; i++) {
			if (a[j][i] < min1) {
				min1 = a[j][i];
			}
		}

		int min_val = min1;

		for (int j2 = j+1; j2 < m; j2++) {
			
			int min2 = a[j2][0];
			for (int i = 1; i < n; i++) {
				if (a[j2][i] < min2) {
					min2 = a[j2][i];
				}
			}

			if (min2 > min_val) {
				min_val = min2;
				min_idx = j2;
			}
		}

		swap(a[j], a[min_idx]);
	}
}