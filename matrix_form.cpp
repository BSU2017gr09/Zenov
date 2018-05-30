﻿//Симметричную матрицу А(N, N), заданную нижним треугольником в виде одномерного массива 
//относительно побочной диагонали, умножить на вектор В(N).В памяти матрицу не получать.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<iomanip>
using namespace std;
typedef int fff(int **, int *, int);
typedef fff *pfff;
void giveMemory(int **&A, const int N) {
	try { A = new int*[N]; }
	catch (...) {
		cout << "Ошибка: невозможно создать массив для строк.";
		exit(0);
	}

	for (int i = 0; i<N; i++) {
		try { A[i] = new int[N]; }
		catch (...) {
			cout << "Ошибка: невозможно создать очередную строку.";
			exit(0);
		}
	}

}
void giveMemory1(int *&B, const int N) {
	try { B = new int[N]; }
	catch (...) {
		cout << "Ошибка: невозможно создать массив для строк.";
		exit(0);
	}
}
void initArray(int* *A, int N) { //Заполнение симметричной матрицы А(N, N), заданной верхним треугольником относительно побочной диагонали
	for (int i = 0; i<N; i++) {
		for (int j = 0; j < N; j++) {
			if (j && (j - i)>=1) { A[i][j] = 0; }
			else {
				if (N % 2 && j&&i > N / 2 && (N - j - i <= 0)) {      
					A[i][j] = A[N - j - 1][N - i - 1]; continue;
				}
				if (!(N % 2) && j&&i >= N / 2 && (N - j - i <= 0)) {    
					A[i][j] = A[N - j - 1][N - i - 1]; continue;
				}
				cin >> A[i][j];
			}
		}
	}
}




void initArrayB(int *B, int N) {
	for (int i = 0; i<N; i++) {
		cin >> B[i];
	}
}
void printArray(int **A, int N) {
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			cout << setw(3) << A[i][j];
		}
		cout << endl;
	}
}
void printArrayB(int *B, int N) {
	for (int i = 0; i<N; i++) {
		cout << B[i];
		cout << endl;
	}
}
void freeMemory(int **A, const int N) {
	for (int i = 0; i<N; i++) {
		delete[]A[i];
	}
}
int help(int **A, int *B, int N) {
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

int exit(int **A, int *B, int N) {
	exit(0);
}
int input(int **A, int *B, int N) {
	cout << "Введите элементы верхнетреугольной матрицы: " << "\n";
	initArray(A, N);
	cout << "Введите координаты вектра, на который будет умножаться матрица" << "\n";
	initArrayB(B, N);
	cout << "Матрица:" << endl;
	printArray(A, N);
	cout << "Вектор" << endl;
	printArrayB(B, N);
	return 0;
}
int output(int **A, int *B, int N) {
	int rez = 0;
	cout << "Результат произведения: " << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0, k = 0; j < N; j++, k++) {
			rez += B[k] * A[i][j];
		}
		cout << rez << "\n";
		rez = 0;
	}
	return 0;
}
void forEach(int **A, int* B, const int N, pfff pf) {
	pf(A, B, N);
}
int main() {
	setlocale(LC_ALL, "ru");
	int N, n;
	int* *A = nullptr;
	int *B = nullptr;
	cout << "Введите количество строк и столбцов в cимметричной матрице А(N, N): " <<endl;
	cin >> N;
	giveMemory(A, N);
	giveMemory1(B, N);
	

	fff * Fmenu[4] = { exit, help, input, output };
	
	while (1) {
		cout << "Введите номер операции:" << "\n" << "0-Выход" << "\n" << "1-Условие задачи" <<endl << "2-Ввести параметры" << endl << "3-Вывести результат" << endl;
		cin >> n;
		forEach(A, B, N, Fmenu[n]);
	}
	printArray(A, N);
	freeMemory(A, N);
	system("pause");
	return 0;
}
