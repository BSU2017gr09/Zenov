/*Структура содержит информацию о регистрации автомашин: марка
автомобиля, год выпуска, цвет, стоимость.
a) Получить список автомашин старше заданного года выпуска;
) Определения машины с максимальной стоимостью;
) Получить список автомашин заданной марки, упорядочив его по году
выпуска.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;
char *delim = "----------------------------------------------------------------";

class Auto {
private:
	char *name;
	char *color;
	unsigned int price;
	unsigned int year;


public:
	//Конструктор,который срабатывает по умолчанию
	Auto() :year(0), price(0), name(nullptr), color(nullptr) { cout << "Работает конструктор по умалчанию" << endl; };


	//Конструктор для название машины
	Auto(char *nam, char* col, int p = 0, int s = 0, int d = 0) : name(nullptr), price(s), year(d), color(nullptr) {
		cout << "Работает конструктор для " << nam << endl;
		try {
			name = new char[strlen(nam) + 1];
			color = new char[strlen(col) + 1];
		}
		catch (...) {
			cout << "Ошибка при выделении памяти!\n";
		}
		strcpy(name, nam);
		strcpy(color, col);
	}

	~Auto() {
		cout << "Работает деструктор" << endl;
		delete[] name;
		delete[] color;
	};

	Auto(Auto &other) : name(nullptr), color(nullptr), year(other.year), price(other.price) {
		cout << "Работает конструктор копирования" << endl;
		try {
			name = new char[strlen(other.name) + 1];
			color = new char[strlen(other.color) + 1];
		}
		catch (...) {
			cout << "Ошибка при выделении памяти!\n";
		}
		strcpy(name, other.name);
		strcpy(color, other.color);
	};

	Auto& operator =(const Auto &other) {
		cout << "Работает оператор Равно" << endl;
		if (this == &other) {
			return *this;

		}
		else {
			delete[] name;
			delete[] color;
			try {
				name = new char[strlen(other.name) + 1];
				color = new char[strlen(other.color) + 1];
			}
			catch (...) {
				cout << "Ошибка при выделении памяти!\n";
			}
			strcpy(name, other.name);
			strcpy(color, other.color);
			year = other.year;
			price = other.price;
		}
	};

	char *getName() {
		return name;
	}

	char *getColor() {
		return color;
	}

	int getPrice() {
		return price;
	}

	int getYear() {
		return year;
	}

	void setName(char *str) {
		//(*this).name = str;
		try {
			this->name = new char[strlen(str) + 1];
		}
		catch (...) {
			cout << "Error!\n";
			exit(1);
		}
		strcpy(name, str);
	}

	void setColor(char *str) {
		//(*this).color = str;
		try {
			this->color = new char[strlen(str) + 1];
		}
		catch (...) {
			cout << "Error!\n";
			exit(1);
		}
		strcpy(color, str);
	}

	void setPrice(int pri) {
		(*this).price = pri;
	}
	void setYear(int yea) {
		(*this).year = yea;
	}

	friend ostream& operator<<(ostream &output, Auto &tmp) {
		cout << "Car name: " << tmp.name << endl << "Color of car: " << tmp.color << endl << "Price :" << tmp.price << " $ " << endl;
		cout << "Year : " << tmp.year << endl;
		return output;
	}



};

typedef Auto* menu(Auto*, int);
typedef menu* ptrMenu;

void forEach(Auto A[], int n, ptrMenu operation) {
	operation(A, n);
}

Auto* exit(Auto A[], int n) {
	exit(0);
}

Auto* help(Auto A[], int n) {
	cout << "Cтруктура содержит информацию о регистрации автомашин: марка автомобиля, год выпуска, цвет, стоимость." << endl << "a) Получить список автомашин старше заданного года выпуска" << endl << "b)Определения машины с максимальной стоимостью;" << endl;
	cout << "c) Получить список автомашин заданной марки, упорядочив его по году выпуска." << endl;
	return &Auto();

}

Auto *moreyear(Auto A[], int N) {
	int y = 0, k = 0;
	cout << "Введите год старше которого хотите увидеть машины: ";
	cin >> y;
	cout << "/n Машины старше " << y << " года выпуска" << endl;
	for (int i = 0; i < N; i++) {
		if (A[i].getYear()> y) {
			cout << delim << endl << A[i] << endl;
			k++;
		}
	}
	if (!k) { cout << "Машин старше " << y << " года выпуска нет"; }
	return &Auto();
}

Auto *Maxprice(Auto A[], int N) {
	Auto tmp;
	tmp.setPrice(0);
	for (int i = 0; i < N; i++) {
		if (A[i].getPrice() > tmp.getPrice()) {
			tmp = A[i];
		}
	}
	cout << "Машина с максимальной ценой: " << endl << tmp;
	return &Auto();
}

char* input(char* &s, int n = 15) {//Машины больше чем 15 символов в автосалоне нет
	s = new char[n];

	cout << "Enter name of element (no more then " << n << " symbols)\n";
	while (1) {
		fflush(stdin);
		cin.getline(s, n);
		if (strlen(s)) break;
	}
	return 0;
}


void info(char *s, Auto A[], int N) {

	int k = 0;
	for (int i = 0; i < N; i++) {

		if (!strcmp(A[i].getName(), s)) {
			k++;
			cout << A[i] << delim << endl;

		}
	}
	if (!k) { cout << "No such elemets"; }

}




void init(Auto *A, int N) {
	char *C[] = { "Audi","Mercedes","Lamba","BMW","Skoda" };
	char *B[] = { "Black","Red","White","Blue","Yellow" };
	int price[] = { 1599,2000,70005,100000,600000,35900 };//Инициализация рандомными значениямм
	int year[] = { 2009,2010,2011,2012,2013,2018,2017,2016,2015 };
	for (int i = 0; i < N; i++) {
		A[i].setName(C[rand() % 4]);
		A[i].setColor(B[rand() % 4]);
		A[i].setPrice(price[rand() % 5]);
		A[i].setYear(year[rand() % 8]);

	}
}//Псевдоинитиализация для удобства пользования


Auto *printAll(Auto A[], int N) {
	for (int i = 0; i < N; i++) {
		cout << endl;
		cout << A[i] << delim << endl;
	}
	return &Auto();
}

void Sort(Auto *A, int N) {
	Auto T;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (A[i].getYear() > A[j].getYear()) {
				T = A[i];
				A[i] = A[j];
				A[j] = T;
			}
		}
	}
}



Auto* search(Auto A[], int N) {
	char *mark;
	input(mark);
	Sort(A, N);
	info(mark, A, N);
	return &Auto();
}



int main() {
	ptrMenu function[6] = { exit, help, moreyear, Maxprice, search,printAll };
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	const int N = 10;
	Auto A[N];
	init(A, N);
	int op;
	while (1) {
		cout << "Выберите номер операции" << endl;
		cout << "0 - Выход" << endl;
		cout << "1 - Условие задачи" << endl;
		cout << "2 - Выдать список машин старше заданного года выпуска" << endl;
		cout << "3 - Машина с максимальной ценой" << endl;
		cout << "4 - Получить список автомашин заданной марки, упорядочив его по году выпуска" << endl;
		cout << "5 - Посмотреть все машины в автосалоне" << endl;

		cin >> op;

		if (op > 5 || op < 0) {
			cout << "Неверный номер операции\n";
			continue;
		}

		forEach(A, N, function[op]);
	}

	system("pause");
	return 0;
}