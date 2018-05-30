//Симметричную матрицу А(N, N), заданную нижним треугольником в виде одномерного массива 
//относительно побочной диагонали, умножить на вектор В(N).В памяти матрицу не получать.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<iomanip>
using namespace std;
typedef int fff(int *, int *, int);
typedef fff *pfff;
void giveMemory(int *&A, const int N) {
	try { A = new int[N*(N+1)/2]; }
	catch (...) {
		cout << "Ошибка: невозможно создать массив для строк.";
		exit(0);
	}
}
void giveMemory1(int *&B, const int N) {
	try { B = new int[N]; }
	catch (...) {
		cout << "Ошибка: невозможно создать массив для строк.";
		exit(0);
	}
}



void initArrayA(int *B, int N) {
	for (int i = 0; i<N*(N+1)/2; i++) {
		cin >> B[i];
	}
}



void initArrayB(int *B, int N) {
	for (int i = 0; i<N; i++) {
		cin >> B[i];
	}
}

void printArrayB(int *B, int N) {
	for (int i = 0; i<N; i++) {
		cout << B[i];
		cout << endl;
	}
}
void freeMemory(int *A, const int N) {

		delete[N]A;
	
}
int help(int *A, int *B, int N) {
	cout << "Симметричную матрицу А(N,N), заданную нижним треугольником в виде одномерного массива относительно побочной диагонали, умножить на вектор В(N). В памяти матрицу не получать." << endl;
	cout << "Пользователь вводит x:" << endl;
	cout << "Программа симметрично относительно побочной оси отображает элементы y" << endl;
	cout << "x 0 0 0 0 0" << endl;
	cout << "x x 0 0 0 0" << endl;
	cout << "x x x 0 0 0" << endl;
	cout << "x x y y y 0" << endl;
	cout << "x y y y y y" << endl;



	
	return 0;
}

int exit(int *A, int *B, int N) {
	exit(0);
}



int input(int *A, int *B, int N) {

	cout << "Введите координаты матрицы, на который будет умножаться матрица" << "\n";
	initArrayA(A, N);
	cout << "Вектор" << endl;
	initArrayB(B, N);

	return 0;
}
int output(int *A, int *B, int N) {
	int rez = 0;
	int digit = 0;
	int k = N - 1;
	for (int i = 0; i < N*(N+1)/2;) {
		for (int j = 0; j <N-k; j++,i++) {
			digit = A[i] * B[j];
			rez = rez + digit;
			
		}
		cout << "Результат произведения:" << rez << endl;
		k--;
		rez = 0;
	}
	return 0;
}
void forEach(int *A, int* B, const int N, pfff pf) {
	pf(A, B, N);
}
int main() {
	setlocale(LC_ALL, "ru");
	int N, n;
	cout << "Введите N";
	cin >> N;
	int *A=nullptr;
	int *B=nullptr;
	cout << "Введите количество строк и столбцов в cимметричной матрице А(N, N): " <<endl;
	giveMemory(A, N);
	giveMemory1(B, N);
	

	fff * Fmenu[4] = { exit, help, input, output };
	
	while (1) {
		cout << "Введите номер операции:" << "\n" << "0-Выход" << "\n" << "1-Условие задачи" <<endl << "2-Ввести параметры" << endl << "3-Вывести результат" << endl;
		cin >> n;
		forEach(A, B, N, Fmenu[n]);
	}
	freeMemory(A, N);
	
	system("pause");
	return 0;
}
