//Элементы целочисленного массива А(N), значения которых
 //оказались простыми числами, расположить в порядке возрастания, не нарушая порядка следования других элементов.
#include <iostream>
using namespace std;
void initArray(int *A, const int N) {
	for (int *p = A; p < A + N; p++) {
		*p = rand() % 49;
	}
}
void printArray(int *A, const int N) {
	cout << "Array elements: ";
	for (int *p = A; p < A + N; p++) {
		cout << *p << "  ";
	}
	cout << endl;
}

int *give_m(int N) {
	int *A;
	try {
		A = new int[N];
	}
	catch (...) {
		cout << "EROR! Can't creat this array.";
		return 0;
	}
	return A;
}

int delete_m(int *A, int N) {
	delete[N] A;
	return 0;
}

bool IsSimple(unsigned n) {
	if (n == 1 || n == 0) return false;
	for (int k = 2; k*k <= n; k++) {
		if ((n) % k == 0) return false;
	}
	return true;
}

void sortA(int *A, int N) {
	for (int *p = A; p < N+A; p++) {
		if (IsSimple(*p)) {
			for (int *q = p;q < N+A ; q++) {
				if (IsSimple(*(q+1))) {
					if (*p >*(q+1))
						swap(*p, *(q+1));
				}
			}
		}
	}
}


int main() {
	setlocale(LC_ALL, "ru");
	int N = 0;
	cin >> N;
	int *A;
	A = give_m(N);
	initArray(A, N);
	printArray(A, N);
	sortA(A, N);
	printArray(A, N);
	system("pause");
	return 0;
}