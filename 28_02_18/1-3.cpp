/*Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования. Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.*/
#include <iostream>
using namespace std;
void initArray(int *A, const int N) {
	for (int *p = A; p < A + N; p++) {
		*p = rand() % 50-25;
	}
}

void printArray(int *A, const int N) {
	cout << "Elements of Array: ";
	for (int *p = A; p < A + N; p++) {
		cout << *p << "  ";
	}
	cout << endl;
}

int * give_m(int N) {
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

void sortArray(int *A, const int N) {
	for (int *p = (A + N - 1); p >= A; p--) {
		for (int *k = p; k >= A; k--) {
			if (*p <0) {
				swap(*p, *k);
			}
		}
	}
	for (int *p = A; p < A + N, *p<0; p++) {
		for (int *k = p; k < A + N; k++) {
			if (*p > *k) {
				swap(*k, *p);
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	int N;
	int *A;
	cout << "Enter size of Array: ";
	cin >> N;
	A = give_m(N);
	initArray(A, N);
	printArray(A, N);
	sortArray(A, N);
	cout << "Sorted Array" << endl;
	printArray(A, N);
	system("pause");
	delete_m(A, N);
	return 0;
}