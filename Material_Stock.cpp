/*a) Подобрать покупателю ближайший склад с наличием нужного ему
количества товара. Если на одном складе нет нужного количества
товара, то забрать максимально возможное количество с
ближайшего склада, а остальное – предложить со следующего по
расстоянию.

b) Выполнить сортировку массива объектов в порядке возрастания
номера склада материала, по выбранному пользователем товару.

c) Получить сводку о наличии каждого из материалов на каждом
складе и на всех складах, а также их общую стоимость по складам.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <fstream>
int Max = 255;
const int M = 15;
using namespace std;
char *delim = "----------------------------------------------------------------";
char s[] = "D:\\bar.b";

class Build {
private:
	char *name;
	unsigned int stock;
	unsigned int distance;
	unsigned int amount;
	double price;

public:
	Build() : name(nullptr), stock(0), distance(0), amount(0), price(0) {/* cout << "Работает конструктор по умалчанию" << endl; */ };

	Build(char *nam, int s = 0, int d = 0, int a = 0, double p = 0) : name(nullptr), stock(s), distance(d), amount(a), price(p) {
		try {
			name = new char[strlen(nam) + 1];
			strcpy(name, nam);
		}
		catch (...) {
			cout << "Error!";
			exit(0);
		}
	}
	~Build() {
		delete[] name;
	};

	Build(Build &other) : name(nullptr), stock(other.stock), distance(other.distance), amount(other.amount), price(other.price) {
		try {
			name = new char[strlen(other.name) + 1];
			strcpy(name, other.name);
		}
		catch (...) {
			cout << "Error!";
			exit(0);
		}
	};

	void operator=(const Build &other) {
		if (this != &other) {   //сравнивается 2 адреса
			Build tmp;
			tmp.setName(other.name);
			tmp.setStock(other.stock);
			tmp.setDistance(other.distance);
			tmp.setAmount(other.amount);
			tmp.setPrice(other.price);
			swap(*this, tmp);
		}
		else {
			cout << "Вы хотите приравнять один и тот же материал" << endl;
		}
	}
	char *getName() {
		return name;
	}
	double getPrice() {
		return price;
	}
	int getDistance() {
		return distance;
	}
	int getAmount() {
		return amount;
	}
	int getStock() {
		return stock;
	}

	void setName(char *str) {
		try {
			delete[]name;
			name = new char[strlen(str) + 1];
			strcpy(name, str);
		}
		catch (...) {
			cout << "не получилось выделить место";
		}
	}

	void setPrice(double pri) {
		(*this).price = pri;
	}
	void setAmount(int amo) {
		(*this).amount = amo;
	}
	void setStock(int sto) {
		(*this).stock = sto;
	}
	void setDistance(int dis) {
		(*this).distance = dis;
	}

	friend ostream& operator<<(ostream &output, Build &tmp) {
		cout << "Material name: " << tmp.name << endl << "Number of stock: " << tmp.stock << endl << "Distance from stock :" << tmp.distance << " m " << endl;
		cout << "Amount of material: " << tmp.amount << endl << "Price fo one elements: " << tmp.price << " BLR" << endl;
		return output;
	}
	friend istream& operator>> (istream &input, Build &tmp) {
		cout << "Введите название материала: " << endl;
		try {
			tmp.name = new char[Max];
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.getline(tmp.name, Max);
		}
		catch (...) {
			cout << "не получилось выделить место";
		}
		cout << "Введите номер склада: \n";
		cin >> tmp.stock;
		cout << "Введите расстояние до склада: \n";
		cin >> tmp.distance;
		cout << "Введите количество материала: \n";
		cin >> tmp.amount;
		cout << "Введите цену материала: \n";
		cin >> tmp.price;
		return input;
	}

};
void init(Build *A, int N) {
	char *C[] = { "Conon","Poas","Poan","Loanep","Sonic" };
	double price[] = { 15.99,20.86,31.22,60.25,90,98.27 };
	int B[] = { 101,102,103,104 };
	int dist[] = { 1000,5000,2500,100,3000,7000,8000,10,160 };
	for (int i = 0; i < N; i++) {
		A[i].setName(C[rand() % 4]);
		A[i].setStock(B[rand() % 4]);
		A[i].setDistance(dist[rand() % 8]);
		A[i].setPrice(price[rand() % 5]);
		A[i].setAmount(dist[rand() % 8]);

	}
}
char* input(char* &s, int n = 15) {
	s = new char[n];

	cout << "Enter name of element (no more then " << n << "symbols)\n";
	while (1) {
		fflush(stdin);
		cin.getline(s, n);
		if (strlen(s)) break;
	}
	return 0;
}			// Количество символов равно 15 потому что у нас на складне нет материала с название больше чем 15

void swap(Build &A, Build &B) {
	Build C;
	C.setName(A.getName());
	C.setStock(A.getStock());
	C.setDistance(A.getDistance());
	C.setAmount(A.getAmount());
	C.setPrice(A.getPrice());


	A.setName(B.getName());
	A.setStock(B.getStock());
	A.setDistance(B.getDistance());
	A.setAmount(B.getAmount());
	A.setPrice(B.getPrice());


	B.setName(C.getName());
	B.setStock(C.getStock());
	B.setDistance(C.getDistance());
	B.setAmount(C.getAmount());
	B.setPrice(C.getPrice());

}
void sort(Build  *A, int N) {
	Build T;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (A[i].getStock() > A[j].getStock()) {
				swap(A[i], A[j]);
			}
		}
	}
}
void sortAmount(Build A[], int N) {
	Build T;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (A[i].getAmount() > A[j].getAmount()) {
				swap(A[i], A[j]);
			}
		}
	}
}

typedef void menu(Build*, int);
typedef menu* ptrMenu;

void forEach(Build A[], int n, ptrMenu operation) {
	operation(A, n);
}
void inf(char* nam, Build A[], int N) {


	int k = 0;
	float  sum = 0;
	for (int i = 0; i < N; i++) {

		if (!strcmp(A[i].getName(), nam)) {//strcspn возвращает 0 если строки равны 
			k++;
			cout << A[i] << delim << endl;
			sum = A[i].getPrice() + sum;

		}

	}
	if (!k) { cout << "No such elemets"; }
	cout << "Общая стоимость: " << sum;

}



void stocksort(Build A[], int N) {//Пользователь выбирает вводит нужный товар и производится сортировка относительно цены на этот товар
	char *nam;
	input(nam);
	sort(A, N);
	inf(nam, A, N);
}

void info(Build A[], int N) {
	char* nam;
	input(nam);
	int k = 0;
	float  sum = 0;
	for (int i = 0; i < N; i++) {

		if (!strcmp(A[i].getName(), nam)) {//strcspn возвращает 0 если строки равны 
			k++;
			cout << A[i] << delim << endl;
			sum = A[i].getPrice() + sum;

		}

	}
	if (!k) { cout << "No such elemets"; }
	cout << "Общая стоимость: " << sum;

}

void outfile(Build *A, const int N) {//запись данных из файла в массив
	char titl[255];
	int tmp = 0;
	char q;
	ifstream fin(s, ios::in | ios::binary);
	for (int i = 0; i < N; i++) {
		fin.getline(titl, Max, '*');
		A[i].setName(titl);

		fin.read((char *)&tmp, sizeof(tmp));
		A[i].setStock(tmp);
		fin.read((char *)&tmp, sizeof(tmp));
		A[i].setDistance(tmp);
		fin.read((char *)&tmp, sizeof(tmp));
		A[i].setAmount(tmp);
		fin.read((char *)&tmp, sizeof(tmp));
		A[i].setPrice(tmp);
		fin.read((char *)&tmp, sizeof(tmp));
	}
	fin.close();
}

void printAll(Build *A, int N) {
	for (int i = 0; i < N; i++) {
		cout << endl;
		cout << A[i] << delim << endl;

	}

}

void exit(Build A[], int n) {
	exit(0);
}

void help(Build A[], int n) {
	cout << "Объект содержит информацию о наличиистроительных материалов на складах : шифр материала, номер склада,расстояние до него, количество материала, стоимость единицы." << endl << "a) Подобрать покупателю ближайший склад с наличием нужного ему	количества" << endl;
	cout << "товара.Если на одном складе нет нужного количеств товара, то забрать максимально возможное количество с ближайшего склада, а остальное – предложить со следующего по расстоянию." << endl;
	cout << "b)Выполнить сортировку массива объектов в порядке возрастания номера склада материала, по выбранному пользователем товару. " << endl;
	cout << "c) Получить сводку о наличии каждого из материалов на каждом складе и на всех складах, а также их общую стоимость по складам." << endl;

}

void selection(Build A[], int N) {
	int dist = 0;
	int am = 0;
	char *nam;
	int counter = 0;
	int min = 10000;
	int k = 0;
	cout << "Введите нужный вам товар " << endl;
	input(nam);
	cout << "Введите сколько материала вам потребуется ";
	cin >> am;
	cout << "Введите на каком метре вы находитесь ";
	cin >> dist;
	Build *tmp = new Build[N];

	for (int i = 0; i < N; i++) {
		if (!strcmp(A[i].getName(), nam)) {
			if (abs(A[i].getDistance() - dist) < min) {

				min = abs(A[i].getDistance() - dist);
				counter = i;
				tmp[k] = A[i];
				k++;
			}
		}
	}

	sortAmount(tmp, k);
	cout << "Нужный вам товар вы можете найти  " << delim << endl << A[counter] << delim << endl;
	for (int i = 0; i < k; i++) {
		int val = 0;
		if (am - val - A[counter].getAmount() > 0) {
			val = tmp[i].getAmount() + val;
			cout << "Нужное количество товара можно найти здесь " << delim << endl << tmp[i] << delim << endl;
		}

		else { break; }
	}


}

void entry(Build A[], int N) { //Запись все в файле 
	ofstream fout(s, ios::out | ios::binary);
	int tmp = 0;
	double d = 0;
	if (!fout) {
		cout << "Невозможно найти такой файл!";
		exit(1);
	}
	else {
		for (int i = 0; i < N; i++) {

			fout.write((char*)A[i].getName(), strlen(A[i].getName()));
			fout.write((char*)"*", 1);

			tmp = A[i].getStock();
			fout.write((char*)&tmp, sizeof(tmp));

			tmp = A[i].getDistance();
			fout.write((char*)&tmp, sizeof(tmp));

			tmp = A[i].getAmount();
			fout.write((char*)&tmp, sizeof(tmp));

			d = A[i].getPrice();
			fout.write((char*)&d, sizeof(d));
			fout.write((char*)"*", 1);
		}
		fout.close();

	}

}

void derivation(Build A[], int N) {//Выводит отдельный товар
	int n = 0;
	int tmp = 0, y = 0;
	int count = 0;
	char q;
	double d = 0;
	cout << "Введите номер товара\n";
	cin >> n;
	if (n<1 || n>N) {
		cout << "Такого товара нет" << endl;
		exit(1);
	}
	ifstream fin(s, ios::in);
	while (1) {
		if (n == 1) {
			break;
		}
		fin.read((char*)&q, 1);
		if (q == '*') {
			count++;
		}
		if (count == (n - 1) * 2) {
			break;
		}
	}
	char lokki[255];
	Build t;
	fin.getline(lokki, Max, '*');
	t.setName(lokki);
	fin.read((char*)&tmp, sizeof(tmp));
	t.setStock(tmp);
	fin.read((char*)&tmp, sizeof(tmp));
	t.setDistance(tmp);
	fin.read((char*)&tmp, sizeof(tmp));
	t.setAmount(tmp);
	fin.read((char*)&d, sizeof(d));
	t.setPrice(d);
	cout << t;
	fin.close();

}

void editMaterial(Build *A, const int N) {
	cout << "Введите номер редактируемоего материала(до " << M << ")";
	Build tmp;
	int n;
	while (1) {
		cin >> n;
		if (n < 1 || n>M) {
			cout << "Материала под таким номером нет!";
		}
		else break;
	}
	cin >> tmp;
	swap(A[n - 1], tmp);
}

void fileditMaterial(Build *A, const int N) {
	outfile(A, N);
	editMaterial(A, N);
	entry(A, N);
}

int main() {
	ptrMenu function[10] = { exit, help,
		info, printAll,
		stocksort,selection,
		entry,derivation,
		editMaterial,fileditMaterial };
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");

	Build A[M];
	init(A, M);
	int op;
	while (1) {
		cout << "Выберите номер операции" << endl;
		cout << "0 - Выход" << endl;
		cout << "1 - Условие задачи" << endl;
		cout << "2 - Вывести информацию про определенный товар" << endl;
		cout << "3 - Показать все материалы" << endl;
		cout << "4 - Показать товар сортированный относительно номера склада" << endl;
		cout << "5 - Подобрать ближайший по расстоянию,нужный вам  товар" << endl;
		cout << "6 - Запись в файл всей информации" << endl;
		cout << "7 - Вывести информацию по конкретному товару" << endl;
		cout << "8 - Редактировать материал" << endl;
		cout << "9 - Редактировать материал в файле" << endl;

		cin >> op;

		if (op > 10 || op < 0) {
			cout << "Неверный номер операции\n";
			continue;
		}

		forEach(A, M, function[op]);
	}
	printAll(A, M);
	selection(A, M);

	system("pause");
	return 0;
}
