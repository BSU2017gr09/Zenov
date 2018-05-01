//Массив чисел размера N проинициализировать случайными числами из промежутка от -N до N
//Написать функцию циклического сдвига элементов массива вправо на k элементов.
#include <iostream>
using namespace std;

void initArray(int *A, const int N) {
	for (int *p = A; p < A + N; p++) {
		*p = rand() %(2*N)+(-N);
	}
}

void printArray(int *A, const int N) {
	cout << "Элементы массива: ";
	for (int *p = A; p < A + N; p++) {
		cout << *p << " ";
	}
}

void my_Shift(int *A, const int N, int k) {

	for (int *p = A, size = 0, *q = (A + N - 1); size < N / 2; p++, q--) {//Цикл,переварачивающий весь массив
		swap(*q, *p);
		size++;
	}
	for (int *p = A, size = 0, *q = (A + k - 1); size<k / 2; p++, q--) {//Цикл,переварачивающий первый блок(от 0 элемента до k-1). 
									    //p-начальный,q-указатель на последний элемент первого блока
		swap(*q, *p);
		size++;
	}
	for (int *p = A + k, size = 0, *q = (A + N - 1); size<(N - k) / 2; p++, q--) {//Цикл,переварачивающмй второй блок(от k элемента 
										     //до последнего)
		swap(*q, *p);
		size++;
	}

}
int main() {
	setlocale(LC_ALL, "Rus");
	int N = 0;
	int *A;
	int k = 0;
	cout << "Введите кол-во элементов массива:" << endl;
	cin >> N;

	try {
		A = new int[N];
	}
	catch (...) {
		cout << "Нехватает памяти!" << endl;
		return 1;
	}
	cout << "Введите на сколько элементов идет сдвиг:" << endl;
	cin >> k;
	initArray(A, N);
	printArray(A, N);
	my_Shift(A, N, k);
	printArray(A, N);
	delete[] A;
	//Освободил :)
// почему память не освобождаем????
	system("pause");
	return 0;
}
