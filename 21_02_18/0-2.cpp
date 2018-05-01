/*В массиве размера N, заполненного случ.числами от 0 до 10, определить максимальную длину последовательности равных элементов.*/
#include <iostream>
using namespace std;

void initArray(int *A, const int N) {
	for (int *p = A; p < A + N; p++) {
		*p = rand() % 11;
	}
}

void printArray(int *A, const int N) {
	cout << "Элементы массива: ";
	for (int *p = A; p < A + N; p++) {
		cout << *p << " ";
	}
}

int MaxLength(int *A, const int N) {
	int maxlength = 1;
	int length = 1;
	for (int *p = A; p <A + N; p++) {
		if (*p == *(p + 1)) length++;
		else {
			if (length > maxlength)maxlength = length;
			length = 1;
		}
	}
	return maxlength;
}

int main() {
	setlocale(LC_ALL, "Rus");
	int N = 0;
	int *A;
	cout << "Введите кол-во элементов массива:" << endl;
	cin >> N;

	try {
		A = new int[N];
	}
	catch (...) {
		cout << "Нехватает памяти!" << endl;
		return 1;
	}
	initArray(A, N);
	printArray(A, N);
	cout<<MaxLength(A, N);
	delete[] A;
	//Освободил :)
// почему память не освобождаем????
	system("pause");
	return 0;
}
