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
using namespace std;
char *delim = "----------------------------------------------------------------";



class Build {
private:
	char *name;
	unsigned int stock;
	unsigned int distance;
	unsigned int amount;
	double price;

public:
	//Конструктор,который срабатывает по умолчанию
	Build() :stock(0), distance(0), name(nullptr), amount(0),price(0) {/* cout << "Работает конструктор по умалчанию" << endl; */};


	//Конструктор для название машины
	Build(char *nam, double p = 0, int s = 0, int d=0, int a=0) : name(nullptr), stock(s), price(p),distance(d),amount(a) {
		cout << "Работает конструктор для " << nam << endl;
		name = new char[strlen(nam) + 1];
		strcpy(name, nam);
	}
	~Build() {
		/*cout << "Работает деструктор" << endl;*/
		delete[] name;
	};

	Build(Build &other) : name(nullptr), stock(other.stock), price(other.price),distance(other.distance),amount(other.amount) {
		cout << "Работает конструктор копирования" << endl;
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
	};

	Build& operator =(const Build &other) {
		/*cout << "Работает оператор Равно" << endl;*/
		if (this == &other) {
			return *this;

		}
		else {
			delete[] name;
			name = new char[strlen(other.name) + 1];
			strcpy(name, other.name);
			amount = other.amount;
			price = other.price;
			stock = other.stock;
			distance = other.distance;
		}
	};
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
	
	friend ostream& operator<<(ostream &output,Build &tmp) {
		cout << "Material name: " << tmp.name << endl << "Number of stock: " << tmp.stock << endl << "Distance from stock :"<< tmp.distance << " m " << endl;
		cout << "Amount of material: "  << tmp.amount << endl << "Price fo one elements: " << tmp.price << " BLR" << endl;
		return output;
	}

	
};
void init(Build *A, int N) {
	char *C[] = { "Conon","Poas","Poan","Loanep","Sonic" };
	double price[] = { 15.99,20.86,31.22,60.25,90,98.27 };//Инициализация рандомными значениямм
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
char* input(char* &s, int n=15) {
	s = new char[n];

	cout << "Enter name of element (no more then " << n << "symbols)\n";
	while (1) {
		fflush(stdin);
		cin.getline(s, n);
		if (strlen(s)) break;
	}
	return 0;
}			// Количество символов равно 15 потому что у нас на складне нет материала с название больше чем 15

void sort(Build  *A, int N) {
	Build T;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (A[i].getStock() > A[j].getStock()) {
				T = A[i];
				A[i] = A[j];
				A[j] = T;
			}
		}
	}
}
void sortAmount(Build A[], int N) {
	Build T;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (A[i].getAmount() > A[j].getAmount()) {
				T = A[i];
				A[i] = A[j];
				A[j] = T;
			}
		}
	}
}
	
	typedef Build* menu(Build*, int);
	typedef menu* ptrMenu;

	void forEach(Build A[], int n, ptrMenu operation) {
		operation(A, n);
	}
	void inf(char* nam,Build A[], int N) {
		
	
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


	Build* stocksort(Build A[], int N) {//Пользователь выбирает вводит нужный товар и производится сортировка относительно цены на этот товар
		char *nam;
		input(nam);
		sort(A, N);
		inf(nam, A, N);
		return &Build();
	}
	Build *info( Build A[], int N) {
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
		return &Build();
	}
	Build *printAll(Build *A, int N) {
		for (int i = 0; i < N; i++) {
			cout << endl;
			cout << A[i] << delim << endl;

		}
		return &Build();
	}
	Build* exit(Build A[], int n) {
		exit(0);
	}
	Build* help(Build A[], int n) {
		cout << "Объект содержит информацию о наличиистроительных материалов на складах : шифр материала, номер склада,расстояние до него, количество материала, стоимость единицы." << endl << "a) Подобрать покупателю ближайший склад с наличием нужного ему	количества" << endl;
		cout << "товара.Если на одном складе нет нужного количеств товара, то забрать максимально возможное количество с ближайшего склада, а остальное – предложить со следующего по расстоянию." << endl;
		cout<< "b)Выполнить сортировку массива объектов в порядке возрастания номера склада материала, по выбранному пользователем товару. " << endl;
		cout << "c) Получить сводку о наличии каждого из материалов на каждом складе и на всех складах, а также их общую стоимость по складам." << endl;
		return &Build();

	}
	Build *selection(Build A[],int N) {
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
			if (am - val- A[counter].getAmount() > 0) {
				val = tmp[i].getAmount() + val;
				cout << "Нужное количество товара можно найти здесь " <<delim<< endl << tmp[i]<<delim<<endl;
			}
			
			else{break;}
		}
		
		return 0;
	}

int main() {
	ptrMenu function[6] = { exit, help, info, printAll,stocksort,selection };
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	
	const int N = 10;
	Build A[N];
	init(A, N);
	int op;
	while (1) {
		cout << "Выберите номер операции" << endl;
		cout << "0 - Выход" << endl;
		cout << "1 - Условие задачи" << endl;
		cout << "2 - Вывести информацию про определенный товар" << endl;
		cout << "3 - Показать все материалы" << endl;
		cout << "4 - Показать товар сортированный относительно номера склада" << endl;
		cout << "5 - Подобрать ближайший по расстоянию,нужный вам  товар" << endl;

		cin >> op;

		if (op > 5 || op < 0) {
			cout << "Неверный номер операции\n";
			continue;
		}

		forEach(A, N, function[op]);
	}
	printAll(A, N);
	selection(A, N);

	system("pause");
	return 0;
}
