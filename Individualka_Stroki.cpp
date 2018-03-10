
/* Назовём два слова, стоящие рядом, особой парой, если заданная буква
встречается в них одинаковое число раз, и номера позиций, в которых она
располагается и в том и в другом слове, одинаковы.Вывести на экран все
особые пары и заменить их на *. */
#include <iostream> 
#include <string> 
#include <clocale> 

// exit, input, condition, output 

typedef char* menu(char*&, int);
typedef menu* ptrMenu;

using namespace std;

void forEach(char* &s, int n, ptrMenu operation);
char* exit(char* &s, int n);
char* help(char* &s, int n);
char* input(char* &s, int n);
char* transform(char* &s, int n);
char* output(char* &s, int n);

bool checkWords(char* s1, int len1, char* s2, int len2, char symb);
void replace(char* &s, int len, char symb, char rSymb = '*');


int main() {
	setlocale(LC_ALL, "Rus");

	ptrMenu function[5] = { exit, help, input, transform, output };
	char* s = nullptr;
	const int n = 255;
	int op;
	while (1) {
		cout << "Выберите номер операции\n";
		cout << "0 - Выход\n";
		cout << "1 - Условие задачи\n";
		cout << "2 - Ввести строку\n";
		cout << "3 - Преобразовать строку по условию\n";
		cout << "4 - Вывести результат\n";

		cin >> op;

		if (op > 4 || op < 0) {
			cout << "Неверный номер операции\n";
			continue;
		}

		forEach(s, n, function[op]);
	}
}

void forEach(char* &s, int n, ptrMenu operation) {
	operation(s, n);
}

char* exit(char* &s, int n) {
	exit(0);
}

char* help(char* &s, int n) {
	cout << "Назовём два слова, стоящие рядом, особой парой, если заданная буква\nвстречается в них одинаковое число раз, и номера позиций, в которых она\nрасполагается и в том и в другом слове, одинаковы.Вывести на экран все\nособые пары и заменить их на *.\n\n";
	return 0;
}

char* input(char* &s, int n) {
	s = new char[n];
	cout << "Введите строку (не более " << n << " символов)\n";
	while (1) {
		fflush(stdin);
		cin.getline(s, n);
		if (strlen(s)) break;
	}
	return 0;
}

char* transform(char* &s, int n) {
	char delim[] = " ?:-,.!;()";
	char *p = s;
	cout << "Введите букву, необходимую по условию задачи\n";
	char c;
	cin >> c;
	char* tmp = s;
	char* word2 = tmp + strspn(tmp, delim);
	int len2 = strcspn(word2, delim);
	tmp = word2 + len2;
	char* word1;
	int len1;
	while (1) {
		word1 = word2;
		len1 = len2;
		word2 = tmp + strspn(tmp, delim);
		len2 = strcspn(word2, delim);
		tmp = word2 + len2;

		if (checkWords(word1, len1, word2, len2, c)) {
			replace(word1, len1, c);
			replace(word2, len2, c);
		}
		if (!strlen(tmp)) break;
	}


	return 0;
}
char* output(char* &s, int n) {
	cout << s << '\n';
	return 0;
}

bool checkWords(char* s1, int len1, char* s2, int len2, char symb) {
	int pos1 = strchr(s1, symb) - s1;
	int pos2 = strchr(s2, symb) - s2;
	int lenNow1 = len1;
	int lenNow2 = len2;

	while (pos1 == pos2) {
		if (pos1 == -1 && pos2 == -1) return true;
		s1 += pos1 + 1;
		s2 += pos2 + 1;
		lenNow1 -= (pos1 + 1);
		lenNow2 -= (pos2 + 1);

		if (lenNow1 || lenNow2) {
			if (strchr(s1, symb) == NULL) pos1 = -1;
			else pos1 = strchr(s1, symb) - s1;
			if (strchr(s2, symb) == NULL) pos2 = -1;
			else pos2 = strchr(s2, symb) - s2;
			if (pos1 > lenNow1) pos1 = -1;
			if (pos2 > lenNow2) pos2 = -1;
			continue;
		}
		return true;
	}
	return false;
}

void replace(char* &s, int len, char symb, char rSymb) {
	char* p = s;
	p = strchr(p, symb);
	while (p != NULL) {
		*p = rSymb;
		p = strchr(p, symb);
		if (p > s + len) break;
	}
}