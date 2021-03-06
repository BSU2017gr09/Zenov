/*В массиве размера N, заполненного случ.числами от 0 до 10, подсчитать количество элементов, встречающихся более одного раза.*/
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
int CountRepeat(int *A, const int N) {
	int repeat = 0;
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (*(A + i) == *(A + j)) count++;//Если элементы совпадают,включается счетчик
		}
		if (count >= 1)repeat++;//Если встречаем повторяющийся элемент конечный ответ увеличивается
		if (count >= 2)repeat--;//Если счетчик больше 2,значит уменьшаем наш конечный ответ,т.к. повторяющееся число еще раз встретится в массиве(к примеру 1 3 1 5 1)
		count = 0;
	}
	return repeat;
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
	cout << endl;
	cout<<CountRepeat(A, N);
	delete[]A;
	system("pause");
	return 0;

}