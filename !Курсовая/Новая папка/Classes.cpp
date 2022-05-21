#include "Classes.h"
#include <string>
#include <string.h>
// в этом файле содержиться реализация методов класса Money, Account, перегрузка операторов ! и << для классов Account, PremAccount


Money::Money(string Currency, long Sum) {
	this->Currency = Currency;
	this->Sum = Sum;
	cout << "Объект Money создан" << endl;
	//this->count++;//------------------------------------------подсчет количества объектов
}

string Money::GetCurrency() {
	return this->Currency;
}

long Money::GetSum() {
	return this->Sum;
}

Money::Money() {
	this->Currency = "";
	this->Sum = 0;
}

Account::Account(string FIO, long ident, Money m) {
	this->FIO = FIO;
	this->ident = ident;
	this->m = m;
	cout << "Объект Account создан" << endl;
	//this->count++;//------------------------------------------подсчет количества объектов
}

Account::Account() {
	Money m;
	this->FIO = "0";
	this->ident = 0;
	this->m = m;
}
void Account::fread(string s, int i) {
	fstream fin;
	fin.open(s);
	string t, k;
	getline(fin, t);
	for (int j = 0; j < i * 4; j++)
		getline(fin, t);
	getline(fin, FIO);
	fin >> ident;
	fin >> m.Currency;
	fin >> m.Sum;
	fin.close();
}
void PremAccount::fread(string s, int i) {
	fstream fin;
	fin.open(s);
	string t, k;
	getline(fin, t);
	for (int j = 1; j < i * 5; j++)
		getline(fin, t);
	getline(fin, FIO);
	fin >> ident;
	getline(fin, m.Currency);
	fin >> m.Sum;
	fin >> param;
	fin.close();
}
void Account::savea(string s) {
	ofstream fout;
	fout.open(s, ofstream::app);
	if (!fout.is_open()) {
		cout << "Error:file" << endl;
	}
	else {
		fout << FIO << endl;
		fout << ident << endl;
		fout << m.GetCurrency() << endl;
		fout << m.GetSum() << endl;
	}
	fout.close();
}

void PremAccount::savea(string s) {
	ofstream fout;
	fout.open(s, ofstream::app);
	if (!fout.is_open()) {
		cout << "Error:file" << endl;
	}
	else {
		fout << FIO << endl;
		fout << ident << endl;
		fout << m.GetCurrency() << endl;
		fout << m.GetSum() << endl;
		fout << param << endl;
	}
	fout.close();
}

void Account::AddMoney(long Sum) {
	this->m.Sum += Sum;
}

long Account::SubMoney(long Sum) {
	if ((this->m.Sum - Sum) < 0)
		return -1;
	else
		this->m.Sum -= Sum;
	return this->m.Sum;
}

void Account::operator!() {
	this->m.Sum = 0;
	cout << "Счет обнулен для аккаунта с идентификационным номером " << this->ident << endl;
}
void PremAccount::operator!() {
	this->m.Sum = 0;
}

ostream& operator<<(ostream & os, Account & Acc) {//------------------------------------------перегрузка вывода для Account
	if (Acc.FIO == "") cout << "ФИО аккаунта: NULL" << endl;
	else cout << "ФИО аккаунта: " << Acc.FIO << endl;
	cout << "Идентификационный номер аккаунта: " << Acc.ident << endl;
	if (Acc.m.GetCurrency() == "") cout << "Валюта аккаунта: NULL" << endl;
	else cout << "Валюта аккаунта: " << Acc.m.GetCurrency() << endl;
	cout << "Количество денег в данной валюте: " << Acc.m.Sum << endl;
	return os;
}

ostream & operator<<(ostream & os, PremAccount & PAcc) {//-------------------------------------перегрузка вывода для PremAccount
	if (PAcc.FIO == "") cout << "ФИО аккаунта: NULL" << endl;
	else cout << "ФИО аккаунта: " << PAcc.FIO << endl;
	cout << "Идентификационный номер аккаунта: " << PAcc.ident << endl;
	if (PAcc.m.GetCurrency() == "") cout << "Валюта аккаунта: NULL" << endl;
	else cout << "Валюта аккаунта: " << PAcc.m.GetCurrency() << endl;
	cout << "Количество денег в данной валюте: " << PAcc.m.Sum << endl;
	if (PAcc.param) cout << "Параметр премиума: истина" << endl;
	else cout << "Параметр премиума: ложь" << endl;
	return os;
};
