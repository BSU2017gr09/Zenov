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

bool IsSimple(unsigned x) {
	if (x == 1 || x == 0) return false;
	for (int k = 2; k<= sqrt(n); k++) {
		if ((x) % k == 0) return false;
	}
	return true;
}

void sortA(int *A, int N) {
	for (int *p = A; p < N+A; p++) {
		if (IsSimple(*p)) {
			for (int *q = p;q < N+A-1 ; q++) {
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
	cout << "Enter size of Array:";
	cin >> N;
	int *A;
	A = give_m(N);
	initArray(A, N);
	printArray(A, N);
	sortA(A, N);
	printArray(A, N);
	delete_m(A, N);
	system("pause");
	return 0;
}