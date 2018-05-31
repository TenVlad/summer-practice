#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <Windows.h>
using namespace std;

struct data {
	int dayg;
	int monthg;
	int yearg;
	int dayr;
	int monthr;
	int yearr;
};
struct List {
	char author[20]; 
	char title[20]; 
	char publish[20];
	int year; 
	char id[9]; 
	data date; 
	int	quantity; 
	char category[20]; 
};
struct Node {
	List key;
	Node* next;
};
struct Node* init() {
	struct Node *lst; 
	lst = new(Node);
	cout << "Ввведите информацию о книге:" << endl;
	getchar();
	cout << "Автор: "; cin.getline(lst->key.author, 20);
	cout << "Название книги: "; cin.getline(lst->key.title, 20);
	cout << "Название издательства: "; cin.getline(lst->key.publish, 20);
	cout << "Год издания: "; cin >> lst->key.year;
	cout << "ID читателя: "; cin >> lst->key.id;
	cout << "Дата выдачи, дата возврата" << endl << "  Дата выдачи:" << endl
		<< "    День: "; cin >> lst->key.date.dayg; cout << "    Месяц: "; cin >> lst->key.date.monthg;
	cout << "    Год: "; cin >> lst->key.date.yearg;
	cout << "  Дата возврата:" << endl
		<< "    День: "; cin >> lst->key.date.dayr; cout << "    Месяц: "; cin >> lst->key.date.monthr;
	cout << "    Год: "; cin >> lst->key.date.yearr;
	cout << "Количество оставшихся экземпляров: "; cin >> lst->key.quantity;
	getchar();
	cout << "Категория: "; cin.getline(lst->key.category, 20);
	lst->next = NULL;  
	return(lst);
}
void add_elem(Node* head) {
	struct Node *temp, *p;
	p = head;
	while (p->next != NULL) p = p->next;
	temp = init();
	temp->next = NULL;
	p->next = temp;
}
void print_list(Node* head, int number) {
	if (head != NULL) {
		cout << setw(3) << left << number << "|" << setw(20) << left << head->key.author
			<< "|" << setw(20) << left << head->key.title << "|" << setw(20) << left << head->key.publish
			<< "|" << setw(11) << left << head->key.year << "|" << setw(11) << left << head->key.id << "|";
		if (head->key.date.dayg < 10) { cout << "0"; } cout << head->key.date.dayg << ".";
		if (head->key.date.monthg < 10) { cout << "0"; } cout << head->key.date.monthg << ".";
		if (head->key.date.yearg < 10) { cout << "0"; } cout << head->key.date.yearg << "/";
		if (head->key.date.dayr < 10) { cout << "0"; } cout << head->key.date.dayr << ".";
		if (head->key.date.monthr<10) { cout << "0"; } cout << head->key.date.monthr << ".";
		if (head->key.date.yearr<10) { cout << "0"; } cout << head->key.date.yearr;
		cout << "|" << setw(7) << left << head->key.quantity << "|" << setw(20) << left << head->key.category << endl;
		number++;
		print_list(head->next, number);
	}
	else cout << endl;
}
void print_elem(Node* curr, int num) {
	cout << setw(3) << num << "|" << setw(20) << left << curr->key.author
		<< "|" << setw(20) << left << curr->key.title << "|" << setw(20) << left << curr->key.publish
		<< "|" << setw(11) << left << curr->key.year << "|" << setw(11) << left << curr->key.id << "|";
	if (curr->key.date.dayg < 10) { cout << "0"; } cout << curr->key.date.dayg << ".";
	if (curr->key.date.monthg < 10) { cout << "0"; } cout << curr->key.date.monthg << ".";
	if (curr->key.date.yearg < 10) { cout << "0"; } cout << curr->key.date.yearg << "/";
	if (curr->key.date.dayr < 10) { cout << "0"; } cout << curr->key.date.dayr << ".";
	if (curr->key.date.monthr<10) { cout << "0"; } cout << curr->key.date.monthr << ".";
	if (curr->key.date.yearr<10) { cout << "0"; } cout << curr->key.date.yearr;
	cout << "|" << setw(7) << left << curr->key.quantity << "|" << setw(20) << left << curr->key.category << endl;
}
void edit_elem(Node* head) {
	Node* p = head;
	int n, num = 1;
	while (p->next != NULL) {
		p = p->next;
		num++;
	}
	p = head;
	cout << "Введите номер редактируемого элемента списка: "; cin >> n; cout << endl;
	if (n > num) {
		cout << "Элемента с таким номером не существует." << endl;
	}
	else {
		num = 1;
		while (num != n) {
			p = p->next;
			num++;
		}
		cout << "Введите номер редактируемого поля: "; cin >> n; cout << endl;
		switch (n)
		{
		case 1:
			getchar();
			cout << "Введите новое имя автора: "; cin.getline(p->key.author, 20); cout << endl;
			break;
		case 2:
			getchar();
			cout << "Введите новое название книги: "; cin.getline(p->key.title, 20); cout << endl;
			break;
		case 3:
			getchar();
			cout << "Введите новое название издательства: "; cin.getline(p->key.publish, 20); cout << endl;
			break;
		case 4:
			cout << "Введите новый год издания: "; cin >> p->key.year; cout << endl;
			break;
		case 5:
			cout << "Введите новый ID читателя: "; cin >> p->key.id; cout << endl;
			break;
		case 6:
			cout << "Введите новые дату выдачи, дату возврата" << endl << "  Дата выдачи:" << endl
				<< "    День: "; cin >> p->key.date.dayg;  cout << "    Месяц: "; cin >> p->key.date.monthg;
			cout << "    Год: "; cin >> p->key.date.yearg;
			cout << "  Дата возврата:" << endl
				<< "    День: "; cin >> p->key.date.dayr; cout << "    Месяц: "; cin >> p->key.date.monthr;
			cout << "    Год: "; cin >> p->key.date.yearr;
			break;
		case 7:
			cout << "Введите новое количество оставшихся экземпляров: "; cin >> p->key.quantity; cout << endl;
			break;
		case 8:
			getchar();
			cout << "Введите новую категорию: "; cin.getline(p->key.category, 20); cout << endl;
			break;
		default: cout << "Поля с таким номером не существует.";
		}
	}
}
struct Node* del_elem_numb(Node* head, int numb) {
	Node* current = head;
	Node* temp = current;
	int CurrNum = 1;
	if (numb == 1) {
		temp = head->next;
		delete(head); 
		head = temp;
	}
	else {
		while (current->next != NULL) {
			temp = temp->next;
			CurrNum++;
			if (CurrNum == numb) {
				current->next = temp->next;
				delete(temp);
				break;
			}
			else current = temp;
			if ((temp->next == NULL) && numb > CurrNum) cout << "Элемент не существует";
		}
	}
	return(head);
}
void search_list(Node* head) {
	Node* temp;
	int n, num, i = 0;
	num = 1;
	temp = head;
	cout << "Введите год издания: "; cin >> n; cout << endl;
	while (temp != NULL) {
		if (temp->key.year == n) {
			print_elem(temp, num);
			i = 1;
			num++;
		}
		temp = temp->next;
	}
	if (i == 0) { cout << "Совпадений не найдено" << endl; }
}
struct Node* sort_list_title(Node* head) {
	Node* curr = head;
	Node* k = head;
	Node* min = head;
	Node* q = head;
	Node* temp = head;
	Node* p = head->next; 
	while (p != NULL) {
		if (strcmp(min->key.title, p->key.title) > 0) {
			temp = q;
			min = p;
		}
		q = q->next;
		p = q->next;
	}
	if (curr != min) {
		temp->next = min->next;
		min->next = curr;			
		head = min;
	}
	k = min;
	temp = min;
	min = curr;
	q = min;
	p = q->next;

	while (curr->next != NULL) {
		while (p != NULL) {
			if (strcmp(min->key.title, p->key.title) > 0) {
				temp = q;
				min = p;
			}
			q = q->next;
			p = q->next;
		}
		if (curr == min) {
			k = curr;
			temp = curr;
			curr = curr->next;
		}
		else {
			temp->next = min->next;
			min->next = curr;
			k->next = min;
			temp = min;
			k = min;
		}
		min = curr;
		q = min;
		p = q->next;
	}
	return(head);
}
struct Node* sort_list_year(Node* head) {
	Node* curr = head;
	Node* k = head;
	Node* min = head;
	Node* q = head;
	Node* temp = head;
	Node* p = head->next; 
	while (p != NULL) {
		if (min->key.year > p->key.year) {
			temp = q;
			min = p;
		}
		q = q->next;
		p = q->next;
	}
	if (curr != min) {
		temp->next = min->next;
		min->next = curr;			
		head = min;
	}
	k = min;
	temp = min;
	min = curr;
	q = min;
	p = q->next;

	while (curr->next != NULL) {
		while (p != NULL) {
			if (min->key.year > p->key.year) {
				temp = q;
				min = p;
			}
			q = q->next;
			p = q->next;
		}
		if (curr == min) {
			k = curr;
			temp = curr;
			curr = curr->next;
		}
		else {
			temp->next = min->next;
			min->next = curr;
			k->next = min;
			temp = min;
			k = min;
		}
		min = curr;
		q = min;
		p = q->next;
	}
	return(head);
}
void schet(Node* head) {
	Node *curr, *temp;
	int arr[20];
	int i, j, k;
	temp = head;
	i = 0;
	while (temp != NULL) {
		arr[i] = temp->key.date.dayr - temp->key.date.dayg + 30 * (temp->key.date.monthr - temp->key.date.monthg) +
			365 * (temp->key.date.yearr - temp->key.date.yearg);
		temp = temp->next;
		i++;
	}
	curr = head;
	temp = head;
	i = 0;
	while (curr != NULL) {
		j = 0;
		k = 1;
		while (temp != NULL) {
			if (strcmp(curr->key.category, temp->key.category) == 0 && i > j) {
				k = 0;
				break;
			}
			if (strcmp(curr->key.category, temp->key.category) == 0 && i < j) {
				arr[i] += arr[j];
				k++;
			}
			j++;
			temp = temp->next;
		}
		if (k != 0) {
			cout << curr->key.category << ":" << arr[i] / k << endl;
		}
		i++;
		curr = curr->next;
		temp = head;
	}
}
void hat() {
	cout << "№  |" << setw(20) << left << "Автор"
		<< setw(21) << left << "|Название книги" << setw(21) << left << "|Издательство"
		<< setw(12) << left << "|Год издания" << setw(12) << left << "|id читателя"
		<< setw(22) << left << "|Дата выдачи/возврата "
		<< setw(7) << left << "|Кол-во " << setw(21) << left << "|Категория" << endl;
}
void menu1() {
	cout << "Меню" << endl << "1.Создать библиотеку" << endl << "2.Открыть библиотеку" << endl;
}
void menu2() {
	cout << "Меню" << endl << "1.Создать новую библиотеку" << endl << "2.Открыть другую библиотеку" << endl
		<< "3.Ввод данных" << endl << "4.Вывод данных на экран" << endl
		<< "5.Редактирование записей" << endl << "6.Удаление записи" << endl << "7.Поиск" << endl
		<< "8.Сортировка" << endl << "9.Среднее количество дней на которое берется каждая категория" << endl
		<< "0.Выход" << endl << endl;
}



int _tmain(int argc, _TCHAR* argv[])
{
	//system("color F0");
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	int qt, k, i, n, numb, number = 1;
	fstream f, lib;
	Node *lst, *temp, *p;
	char name[10], buf[50];
	menu1();
	do {
		cout << "Выберите пункт меню: "; cin >> n;
		if (n == 1) {
			lib.open("library.txt", ios::in | ios::out);
			do {
				cout << "Введите название файла: "; cin >> name;
				i = 1;
				while (!lib.eof()) {
					lib.getline(buf, 20, '\n');
					if (strcmp(buf, name) == 0){
						cout << "Файл с таким название уже существует." << endl;
						i = 0;
					}
				}
				lib.clear();
				lib.seekg(0);
			} while (i == 0);
			lib.clear();
			lib.seekg(0, ios::end);
			lib << name << endl;
			lib.close();
			lst = init();
			cout << "Добавить данные?" << endl << "  1.Да" << endl << "  2.Нет" << endl;
			cin >> i;
			while (i == 1) {
				add_elem(lst);
				cout << "Добавить данные?" << endl << "  1.Да" << endl << "  2.Нет" << endl;
				cin >> i;
			}
		}
		else if (n == 2) {
			qt = 1;
			lib.open("library.txt", ios::in);
			while (!lib.eof()) {
				lib.getline(buf, 20, '\n');
				if (strcmp(buf, "") == 0){ break; }
				cout << qt << " | " << buf << endl;
				qt++;
			}
			lib.clear();
			lib.seekg(0);
			do {
				cout << "Выберите библиотеку: ";
				cin >> k;
				if (k < qt) {
					for (int i = 0; i < k; i++) {
						lib.getline(name, 20, '\n');
					}
				}
				else cout << "Библиотеки с таким номером не существует." << endl;
			} while (k > qt);
			lib.close();
			f.open(name, ios::in);
			lst = new(Node);
			f.getline(lst->key.author, 20, '\n');
			f.getline(lst->key.title, 20, '\n');
			f.getline(lst->key.publish, 20, '\n');
			f.getline(buf, 20);
			lst->key.year = atoi(buf);
			f.getline(lst->key.id, 20);
			f.getline(buf, 20);
			lst->key.date.dayg = atoi(buf);
			f.getline(buf, 20);
			lst->key.date.monthg = atoi(buf);
			f.getline(buf, 20);
			lst->key.date.yearg = atoi(buf);
			f.getline(buf, 20);
			lst->key.date.dayr = atoi(buf);
			f.getline(buf, 20);
			lst->key.date.monthr = atoi(buf);
			f.getline(buf, 20);
			lst->key.date.yearr = atoi(buf);
			f.getline(buf, 20);
			lst->key.quantity = atoi(buf);
			f.getline(lst->key.category, 20);
			lst->next = NULL;
			p = lst;
			while (!f.eof()) {
				temp = new(Node);
				f.getline(temp->key.author, 20, '\n');
				f.getline(temp->key.title, 20, '\n');
				f.getline(temp->key.publish, 20, '\n');
				f.getline(buf, 20);
				temp->key.year = atoi(buf);
				f.getline(temp->key.id, 20);
				f.getline(buf, 20);
				temp->key.date.dayg = atoi(buf);
				f.getline(buf, 20);
				temp->key.date.monthg = atoi(buf);
				f.getline(buf, 20);
				temp->key.date.yearg = atoi(buf);
				f.getline(buf, 20);
				temp->key.date.dayr = atoi(buf);
				f.getline(buf, 20);
				temp->key.date.monthr = atoi(buf);
				f.getline(buf, 20);
				temp->key.date.yearr = atoi(buf);
				f.getline(buf, 20);
				temp->key.quantity = atoi(buf);
				f.getline(temp->key.category, 20);
				temp->next = NULL;
				p->next = temp;
				p = temp;
			}
			f.close();
		}
		else cout << "Пункта с таким номером не существует." << endl << endl;
	} while (n > 2);

	do {
		menu2();
		cout << "Выберите пункт меню: "; cin >> n;
		switch (n)
		{
		case 1:
			temp = lst;
			f.open(name, ios::out | ios::trunc);
			while (temp != NULL) {
				f << temp->key.author << endl << temp->key.title << endl << temp->key.publish << endl
					<< temp->key.year << endl << temp->key.id << endl << temp->key.date.dayg << endl
					<< temp->key.date.monthg << endl << temp->key.date.yearg << endl
					<< temp->key.date.dayr << endl << temp->key.date.monthr << endl << temp->key.date.yearr << endl
					<< temp->key.quantity << endl;
				if (temp->next != NULL) { f << temp->key.category << endl; }
				else f << temp->key.category;
				temp = temp->next;
			}
			f.close();
			lib.open("library.txt", ios::in | ios::out);
			do {
				cout << "Введите название файла: "; cin >> name;
				i = 1;
				while (!lib.eof()) {
					lib.getline(buf, 20, '\n');
					if (strcmp(buf, name) == 0){
						cout << "Файл с таким название уже существует." << endl;
						i = 0;
					}
				}
				lib.clear();
				lib.seekg(0);
			} while (i == 0);
			lib.clear();
			lib.seekg(0, ios::end);
			lib << name << endl;
			lib.close();
			lst = init();
			cout << "Добавить данные?" << endl << "  1.Да" << endl << "  2.Нет" << endl;
			cin >> i;
			while (i == 1) {
				add_elem(lst);
				cout << "Добавить данные?" << endl << "  1.Да" << endl << "  2.Нет" << endl;
				cin >> i;
			}
			break;
		case 2:
			temp = lst;
			f.open(name, ios::out | ios::trunc);
			while (temp != NULL) {
				f << temp->key.author << endl << temp->key.title << endl << temp->key.publish << endl
					<< temp->key.year << endl << temp->key.id << endl << temp->key.date.dayg << endl
					<< temp->key.date.monthg << endl << temp->key.date.yearg << endl
					<< temp->key.date.dayr << endl << temp->key.date.monthr << endl << temp->key.date.yearr << endl
					<< temp->key.quantity << endl;
				if (temp->next != NULL) { f << temp->key.category << endl; }
				else f << temp->key.category;
				temp = temp->next;
			}
			f.close();
			qt = 1;
			lib.open("library.txt", ios::in);
			while (!lib.eof()) {
				lib.getline(buf, 20, '\n');
				if (strcmp(buf, "") == 0){ break; }
				cout << qt << " | " << buf << endl;
				qt++;
			}
			lib.clear();
			lib.seekg(0);

			do {
				cout << "Выберите библиотеку: ";
				cin >> k;
				if (k < qt) {
					for (int i = 0; i < k; i++) {
						lib.getline(name, 20, '\n');
					}
				}
				else cout << "Библиотеки с таким номером не существует." << endl;
			} while (k > qt);
			lib.close();
			f.open(name, ios::in);
			lst = new(Node);
			f.getline(lst->key.author, 20, '\n');
			f.getline(lst->key.title, 20, '\n');
			f.getline(lst->key.publish, 20, '\n');
			f.getline(buf, 20);
			lst->key.year = atoi(buf);
			f.getline(lst->key.id, 20);
			f.getline(buf, 20);
			lst->key.date.dayg = atoi(buf);
			f.getline(buf, 20);
			lst->key.date.monthg = atoi(buf);
			f.getline(buf, 20);
			lst->key.date.yearg = atoi(buf);
			f.getline(buf, 20);
			lst->key.date.dayr = atoi(buf);
			f.getline(buf, 20);
			lst->key.date.monthr = atoi(buf);
			f.getline(buf, 20);
			lst->key.date.yearr = atoi(buf);
			f.getline(buf, 20);
			lst->key.quantity = atoi(buf);
			f.getline(lst->key.category, 20);
			lst->next = NULL;
			p = lst;
			while (!f.eof()) {
				temp = new(Node);
				f.getline(temp->key.author, 20, '\n');
				f.getline(temp->key.title, 20, '\n');
				f.getline(temp->key.publish, 20, '\n');
				f.getline(buf, 20);
				temp->key.year = atoi(buf);
				f.getline(temp->key.id, 20);
				f.getline(buf, 20);
				temp->key.date.dayg = atoi(buf);
				f.getline(buf, 20);
				temp->key.date.monthg = atoi(buf);
				f.getline(buf, 20);
				temp->key.date.yearg = atoi(buf);
				f.getline(buf, 20);
				temp->key.date.dayr = atoi(buf);
				f.getline(buf, 20);
				temp->key.date.monthr = atoi(buf);
				f.getline(buf, 20);
				temp->key.date.yearr = atoi(buf);
				f.getline(buf, 20);
				temp->key.quantity = atoi(buf);
				f.getline(temp->key.category, 20);
				temp->next = NULL;
				p->next = temp;
				p = temp;
			}
			f.close();
			break;
		case 3:
			add_elem(lst);
			cout << "Добавить данные?" << endl << "  1.Да" << endl << "  2.Нет" << endl;
			cin >> i;
			while (i == 1) {
				add_elem(lst);
				cout << "Добавить данные?" << endl << "  1.Да" << endl << "  2.Нет" << endl;
				cin >> i;
			}
			break;
		case 4:
			hat();
			print_list(lst, 1);
			break;
		case 5:
			edit_elem(lst);
			hat();
			print_list(lst, 1);
			break;
		case 6:
			cout << "Введите номер удаляемого элемента: ";
			cin >> numb; cout << endl;
			lst = del_elem_numb(lst, numb);
			hat();
			print_list(lst, 1);
			break;
		case 7:
			search_list(lst);
			break;
		case 8:
			cout << "1.Сортировка по названию книг" << endl << "2.Сортировка по году изданию" << endl
				<< "Выберите пункт меню: ";
			cin >> i;
			switch (i)
			{
			case 1:
				lst = sort_list_title(lst);
				break;
			case 2:
				lst = sort_list_year(lst);
				break;
			default: cout << "Пункта с таким номером не существует." << endl;
			}
			hat();
			print_list(lst, 1);
			break;
		case 9:
			schet(lst);
			break;
		case 0:
			temp = lst;
			f.open(name, ios::out | ios::trunc);
			while (temp != NULL) {
				f << temp->key.author << endl << temp->key.title << endl << temp->key.publish << endl
					<< temp->key.year << endl << temp->key.id << endl << temp->key.date.dayg << endl
					<< temp->key.date.monthg << endl << temp->key.date.yearg << endl
					<< temp->key.date.dayr << endl << temp->key.date.monthr << endl << temp->key.date.yearr << endl
					<< temp->key.quantity << endl;
				if (temp->next != NULL) { f << temp->key.category << endl; }
				else f << temp->key.category;
				temp = temp->next;
			}
			f.close();
			break;
		default: cout << "Пункта с таким номером не существует." << endl;
		}
		if (n != 0) system("pause");
	} while (n != 0);
	return 0;
}
