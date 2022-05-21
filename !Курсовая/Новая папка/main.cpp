#include "stdafx.h"
#include "Classes.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <ctype.h>
#include <locale.h>
#define SIZE 256
using namespace std;
bool ru = true;//язык
string p;
int i = 0;//переменная для навигации в файлах
void changei() {
	if (ru)
		i = 0;
	else
		i = 1;
}
string Text(const string& filename, int Num)
{
	ifstream file;
	string p;
	file.open(filename);
	if (file.is_open() == 0)
	{
		changei();
		p = Text(Text("config.txt", 2), (i + 23));//Ошибка: файл
		return string(p);
	}
	string line;
	bool notreached = true;
	while (getline(file, line) && (notreached = (Num-- > 0)));
	if (!notreached)
	{
		file.close();
		return line;
	}
	else
	{
		file.close();
		changei();
		p = Text(Text("config.txt", 2), (i + 25));//Ошибка: строка
		return string(p);
	}
}
template <typename T>
class CList//_________________________________________________________________Класс контейнер
{
private:
	struct list
	{
		T data;
		list *next;
		list *prev;
	};
	list *head, *tale;
public:
	int countofel;
	CList() : head(nullptr), tale(nullptr) {};
	~CList()
	{
		DeleteList();
	}
	void save(string s) {
		ofstream fout;
		fout.open(s);
		if (!fout.is_open()) {
			changei();
			p = Text(Text("config.txt", 2), (i + 23));//Ошибка: файл
			cout << p << endl;
		}
		fout << countofel<<endl;
		fout.close();
		for (list* p = head; p!= NULL; p = p->next) {
			p->data.savea(s);
		}

		
	}
	void DeleteList()
	{
		list* p = head;
		while (p)
		{
			head = head->next;
			delete p;
			p = head;
		}
		countofel = 0;
	}
	void load(string s) {
		DeleteList();
		ifstream fin;
		fin.open(s);
		if (!fin.is_open()) {
			changei();
			p = Text(Text("config.txt", 2), (i + 23));//Ошибка: файл
			cout << p << endl;
		}
		else {
			changei();
			p = Text(Text("config.txt", 2), (i + 31));//Файл открыт
			cout << p << endl;
			T dat;
			int i = 0,o;
			fin >> o;
			for (int i = 0; i < o; i++){
				dat.fread(s,i);
				this->AddItem(dat);
			}
			fin.close();
		};
	}
	void AddItem(T value)
	{
		this->countofel++;//Подсчет объектов
		if (head)
		{
			tale->next = new list;
			tale->next->prev = tale;
			tale = tale->next;
		}
		else
		{
			head = tale = new list;
			tale->prev = nullptr;
		}
		tale->next = nullptr;
		tale->data = value;
	}
	void DisplayList()
	{
		if (head)
		{
			for (list *p = head; p != nullptr; p = p->next)
			{
				cout << p->data << "-->";
			}
			changei();
			p = Text(Text("config.txt", 2), (i + 33));//конец списка
			cout << p << endl;
		}
		else
		{
			changei();
			p = Text(Text("config.txt", 2), (i + 35));//список пуст
			cout << p << endl;
		}
	}
	void DisplayElement(long id) {
		if (head)
		{
			int k=0;
			for (list *q = head; q != nullptr; q = q->next)
			{
				if (q->data.GetIdent() == id) {
					cout << q->data << endl;
					k++;
				}//if
				else {
					if (q->next == NULL && k==0){
						changei();
						p = Text(Text("config.txt", 2), (i + 37));//Элемент с номером
						cout << p;
						cout << id;
						changei();
						p = Text(Text("config.txt", 2), (i + 39));//не найден
						cout << p << endl;
						
					}//if
				}//else
			}//for
		}//if(head)
		else
		{
			changei();
			p = Text(Text("config.txt", 2), (i + 35));//список пуст
			cout << p << endl;
		}//else
	}
	T* ReturnElement(long id) {
		if (head)
		{
			int k = 0;
			for (list *p = head; p != nullptr; p = p->next)
			{
				if (p->data.GetIdent() == id) {
					return &p->data;
					k++;
				}//if
			}//for
			changei();
			p = Text(Text("config.txt", 2), (i + 37));
			cout << p << endl;
			cout << p << id;
			changei();
			p = Text(Text("config.txt", 2), (i + 39));
			cout << p << endl;
			
		return NULL;
		}//if(head)
		else
		{
			changei();
			p = Text(Text("config.txt", 2), (i + 35));
			cout << p << endl;
		}//else
		return NULL;
	}

};




void FirstScreen(bool rus) {//Первый кадр
	string p;
	char h;
	switch (rus) {
	case true:
		for (int i = 0; i < 9; i++)
		{
			p = Text(Text("config.txt", 0), i);
			cout << p << endl;
		}
		h=_getch();
		if (h == '1') {
			ru = !ru;
			FirstScreen(ru);
		}
		break;
	case false:
		for (int i = 0; i < 9; i++)
		{
			p = Text(Text("config.txt", 1), i);
			cout << p << endl;
		}
		h = _getch();
		if (h == '1') {
			ru = !ru;
			FirstScreen(ru);
			break;
		}
	}
}
void MainMenu(bool ru) {//Главное меню
	string p;
	system("cls");
	switch (ru) {
	case true:
		for (int i = 9; i < 15; i++)
		{
			p = Text(Text("config.txt", 0), i);
			cout << p << endl;
		}
		break;
	case false:
		for (int i = 9; i < 15; i++)
		{
			p = Text(Text("config.txt", 1), i);
			cout << p << endl;
		}

	}
};
void DemonstrationMenu1(bool ru) {
	string p;
	system("cls");
	switch (ru) {
	case true:
		for (int i = 15; i < 20; i++)
		{
			p = Text(Text("config.txt", 0), i);
			cout << p << endl;
		}

		break;
	case false:
		for (int i = 15; i < 20; i++)
		{
			p = Text(Text("config.txt", 1), i);
			cout << p << endl;
		}

	}

}
void DemonstrationMenu2(bool ru) {
	string p;
	system("cls");
	switch (ru) {
	case true:
		for (int i = 20; i < 27; i++)
		{
			p = Text(Text("config.txt", 0), i);
			cout << p << endl;
		}
		break;
	case false:
		for (int i = 20; i < 27; i++)
		{
			p = Text(Text("config.txt", 1), i);
			cout << p << endl;
		}
	}
}
void corrInput(int *x)
{
	while (!(cin >> *x)||*x<0)
	{
		string p;
		changei();
		p = Text(Text("config.txt", 2), (i + 21));
		cout << p << endl;
		cin.clear();
		while (cin.get() != '\n');
	}
}
void Descriptionmenu(bool ru) {
	string p;
	system("cls");
	switch (ru) {
	case true:
		for (int i = 27; i < 34; i++)
		{
			p = Text(Text("config.txt", 0), i);
			cout << p << endl;
		}
		break;
	case false:
		for (int i = 27; i < 34; i++)
		{
			p = Text(Text("config.txt", 1), i);
			cout << p << endl;
		}
	}
}



int main(){
	setlocale(0, "RUS");
	ifstream fin;
	string p;
	char q;
	
	string path = "config.txt";
	fin.open(path);//----------------------------------------------------------------------открытие файла конфига
	if (!fin.is_open()) {
		changei();
		cout << "File error/ошибка файла" << endl;
		_getch();
		exit(-1);
	}
	else {
		cout << "Выберите язык/choose language:" << endl << "1. Русский язык" << endl << "2. English language" << endl;
		do {
			if ((q = _getch()) < '1' || q > '2') {
				p = Text(Text("config.txt", 2), i);
				cout << p << endl;
			}
			else {
				if (q == '2') {
					ru = false;
					i++;
				}
			}
		} while (q<'1'||q>'2');
		fin.close();


		
		CList<PremAccount> ListOfPAcc;
		CList<Account> ListOfAcc;
		char ExitParam = ' ', BackParam = ' ', SelectParam1 = ' ', SelectParam2 = ' ',DParam=' ';
		
		FirstScreen(ru);
		changei();
		do {

			MainMenu(ru);
			if ((ExitParam = _getch()) < '0' || ExitParam > '4') {
				changei();
				p = Text(Text("config.txt", 2), (i+1));
				cout << p << endl;
			}
			else {
				cout << ExitParam << endl;
				switch (ExitParam) {
				case '1': {//Демонстрация
					do {
						DemonstrationMenu1(ru);
						if ((BackParam = _getch()) < '0' || BackParam > '3') {
							changei();
							p = Text(Text("config.txt", 2), (i + 3));
							cout << p << endl;
						}
						else {
							cout << BackParam << endl;
							switch (BackParam) {
							case '1': {//базовый класс
								do {
									DemonstrationMenu2(ru);
									if ((SelectParam1 = _getch()) < '0' || SelectParam1 > '5') {
										changei();
										p = Text(Text("config.txt", 2), (i + 5));
										cout << p << endl;
									}
									else {
										switch (SelectParam1) {
										case '1': {//------------------------------------------------------------------Добавление элемента
											char fio[SIZE], currency[SIZE];
											int id, sum = 0, a = 0, l, kil = 0;
											changei();
											p = Text(Text("config.txt", 2), (i + 7));
											cout << p;
											do {
												cin >> fio;
												kil=l = 0;
												do {
													if (!isalpha(fio[l++])) { kil = 1; cout << "строка содержит цифру или другой неподходящий символ\n"; break; }
												} while (fio[l] != '\0');
											} while (kil == 1);
											p = Text(Text("config.txt", 2), (i + 9));
											cout << p;
											corrInput(&id);
											p = Text(Text("config.txt", 2), (i + 11));
											cout << p;
											do {
												cin >> currency;
												kil=l = 0;
												do {
													if (!isalpha(currency[l++])) { kil = 1; cout << "строка содержит цифру или другой неподходящий символ\n"; break; }
												} while (currency[l] != '\0');
											} while (kil == 1);
											p = Text(Text("config.txt", 2), (i + 27));
											cout << p;
											corrInput(&sum);
											Money m(currency, sum);
											Account acco(fio, id, m);
											ListOfAcc.AddItem(acco);
											break;
										}//case 1
										case '2': {//---------------------------------------------------------------------------Вывод списка объектов
											ListOfAcc.DisplayList();
											break;
										}//case 2
										case '3': {//----------------------------------------------------------------------------Вывод отдельного объекта
											int cid;
											changei();
											p = Text(Text("config.txt", 2), (i + 13));
											cout << p << endl;
											corrInput(&cid);
											ListOfAcc.DisplayElement(cid);
											break;
										}//case 3
										case '4': {//--------------------------------------------------------------------------Обнуление счета аккауна
											int cid;
											Account *a = NULL;
											changei();
											p = Text(Text("config.txt", 2), (i + 15));
											cout << p << endl;
											corrInput(&cid);
											a = (ListOfAcc.ReturnElement(cid));
											if (a)
												a->operator!();
											break;
										}//case 4
										case '5': {
											ru = !ru;
											break;
										}//case 5
										case '0': {
											break;
										}//case 0
										}//switch SelectParam1

									}//else
									changei();
									p = Text(Text("config.txt", 2), (i + 29));//Нажмите любую кнопку...
									cout << p << endl;
									_getch();//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
								} while (SelectParam1 != '0');
								ListOfAcc.save("ListOfAcc.txt");

								
								break;
							}//case 1
							case '2': {//производный класс
								do {
									DemonstrationMenu2(ru);
									if ((SelectParam2 = _getch()) < '0' || SelectParam2 > '5') {
										changei();
										p = Text(Text("config.txt", 2), (i + 5));
										cout << p << endl;
									}
									else {
										switch (SelectParam2) {
										case '1': {//------------------------------------------------------------------Добавление элемента
											char fio[SIZE], currency[SIZE];
											int id, sum = 0, a = 0, o;
											bool premparam=false;
											changei();
											p = Text(Text("config.txt", 2), (i + 7));
											cout << p;
											do {
												cin >> fio;
												kil=l = 0;
												do {
													if (!isalpha(fio[l++])) { kil = 1; cout << "строка содержит цифру или другой неподходящий символ\n"; break; }
												} while (fio[l] != '\0');
											} while (kil == 1);
											p = Text(Text("config.txt", 2), (i + 9));
											cout << p;
											corrInput(&id);
											p = Text(Text("config.txt", 2), (i + 11));
											cout << p;
											do {
												cin >> currency;
												kil=l = 0;
												do {
													if (!isalpha(currency[l++])) { kil = 1; cout << "строка содержит цифру или другой неподходящий символ\n"; break; }
												} while (currency[l] != '\0');
											} while (kil == 1);
											p = Text(Text("config.txt", 2), (i + 27));//Введите количество денег на счету
											cout << p;
											corrInput(&sum);
											p = Text(Text("config.txt", 2), (i + 17));
											cout << p << endl;
											do{
											if ((o = _getch()) < 49 || o > 50) {
												changei();
												p = Text(Text("config.txt", 2), (i + 19));
												cout << p << endl;
											}//if
											} while (o < 49 || o>50);
											
												if (o == 49) {
													cout << "1" << endl;
													premparam = true;
												}//if
												else {
													cout << "2" << endl;
													premparam = false;
												//else
											}//else
											Money m(currency, sum);
											PremAccount pacco(fio, id, m, premparam);
											ListOfPAcc.AddItem(pacco);
											break;
										}//case 1
										case '2': {//---------------------------------------------------------------------------Вывод списка объектов
											ListOfPAcc.DisplayList();
											break;
										}//case 2
										case '3': {//----------------------------------------------------------------------------Вывод отдельного объекта
											int cid;
											changei();
											p = Text(Text("config.txt", 2), (i + 13));
											cout << p << endl;
											corrInput(&cid);
											ListOfPAcc.DisplayElement(cid);
											break;
										}//case 3
										case '4': {//--------------------------------------------------------------------------Обнуление счета аккауна
											int cid;
											Account *a = NULL;
											changei();
											p = Text(Text("config.txt", 2), (i + 15));
											cout << p << endl;
											corrInput(&cid);
											a = (ListOfAcc.ReturnElement(cid));
											if (a)
												a->operator!();
											break;
										}//case 4
										case '5': {
											ru = !ru;
											break;
										}//case 5
										case '0': {
											break;
										}//case 0

										}//switch SelectParam2
									}//else
									changei();
									p = Text(Text("config.txt", 2), (i + 29));//нажмите любую кнопку
									cout << p << endl;
									_getch();//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
								} while (SelectParam2 != '0');
								ListOfPAcc.save("ListOfPAcc.txt");
								break;
							}//case 2
							case '3': {
								ru = !ru;
								break;
							}
							case '0': {
								break;
							}//case 0
							}//switch BackParam

						}//else


					} while (BackParam != '0');





					break;
				};//case 1

				case '2': {//ПрО
					do {
						Descriptionmenu(ru);
						if ((DParam = _getch()) < '0' || DParam > '5') {
							changei();
							p = Text(Text("config.txt", 2), (i + 5));
							cout << p << endl;
						}//if
						else {
							switch (DParam) {
							case '1': {//ПрО
								for (int j = 0; j < 7; j++) {
									switch (ru) {
									case true:
										p = Text(Text("config.txt", 3), j);
										cout << p << endl;
										break;
									case false:
										p = Text(Text("config.txt", 4), j);
										cout << p << endl;
										break;
									}
								}

								break;
							}//case 1
							case '2': {//Об авторе
								for (int j = 0; j < 2; j++) {
									switch (ru) {
									case true:
										p = Text(Text("config.txt", 5), j);
										cout << p << endl;
										break;
									case false:
										p = Text(Text("config.txt", 6), j);
										cout << p << endl;
										break;
									}
								}
								break;
							}//case 2
							case '3': {//Опрограмме
								for (int j = 0; j < 13; j++) {
									switch (ru) {
									case true:
										p = Text(Text("config.txt", 7), j);
										cout << p << endl;
										break;
									case false:
										p = Text(Text("config.txt", 8), j);
										cout << p << endl;
										break;
									}
								}
								break;
							}//case 3
							case '4': {//Руководство
								for (int j = 0; j < 8; j++) {
									switch (ru) {
									case true:
										p = Text(Text("config.txt", 9), j);
										cout << p << endl;
										break;
									case false:
										p = Text(Text("config.txt", 10), j);
										cout << p << endl;
										break;
									}
								}
								break;
							}//case 4
							case '5': {//смена языка
								ru = !ru;
								break;
							}//case 5
							case '0': {//back
								break;
							}//case 0



							}//switch DParam



						}//else
						changei();
						p = Text(Text("config.txt", 2), (i + 29));
						cout << p << endl;
						_getch();//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
					} while (DParam != '0');
					break;
				};//case 2

				case '3': {//смена языка
					ru = !ru;
					break;
				};//case 3

				case '4': {//помощ


					/*	if (this->head) {
								this->DeleteList();
							}*/

					ListOfAcc.load(Text("config.txt", 11));
					ListOfPAcc.load(Text("config.txt", 12));




						/*switch (ru) {
						case true:
							p = Text(Text("config.txt", 13), 0);
							cout << p << endl;
							break;
						case false:
							p = Text(Text("config.txt", 14), 0);
							cout << p << endl;
							break;
						}*/
				
					break;
				}//case 4

				case '0': {//выход
					break;
				};//case 0



				}//switch ExitParam



			}//else













	
		} while (ExitParam != '0');//do
	}//else
}
