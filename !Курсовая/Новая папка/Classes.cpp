#include "Classes.h"
#include <string>
#include <string.h>
// � ���� ����� ����������� ���������� ������� ������ Money, Account, ���������� ���������� ! � << ��� ������� Account, PremAccount


Money::Money(string Currency, long Sum) {
	this->Currency = Currency;
	this->Sum = Sum;
	cout << "������ Money ������" << endl;
	//this->count++;//------------------------------------------������� ���������� ��������
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
	cout << "������ Account ������" << endl;
	//this->count++;//------------------------------------------������� ���������� ��������
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
	cout << "���� ������� ��� �������� � ����������������� ������� " << this->ident << endl;
}
void PremAccount::operator!() {
	this->m.Sum = 0;
}

ostream& operator<<(ostream & os, Account & Acc) {//------------------------------------------���������� ������ ��� Account
	if (Acc.FIO == "") cout << "��� ��������: NULL" << endl;
	else cout << "��� ��������: " << Acc.FIO << endl;
	cout << "����������������� ����� ��������: " << Acc.ident << endl;
	if (Acc.m.GetCurrency() == "") cout << "������ ��������: NULL" << endl;
	else cout << "������ ��������: " << Acc.m.GetCurrency() << endl;
	cout << "���������� ����� � ������ ������: " << Acc.m.Sum << endl;
	return os;
}

ostream & operator<<(ostream & os, PremAccount & PAcc) {//-------------------------------------���������� ������ ��� PremAccount
	if (PAcc.FIO == "") cout << "��� ��������: NULL" << endl;
	else cout << "��� ��������: " << PAcc.FIO << endl;
	cout << "����������������� ����� ��������: " << PAcc.ident << endl;
	if (PAcc.m.GetCurrency() == "") cout << "������ ��������: NULL" << endl;
	else cout << "������ ��������: " << PAcc.m.GetCurrency() << endl;
	cout << "���������� ����� � ������ ������: " << PAcc.m.Sum << endl;
	if (PAcc.param) cout << "�������� ��������: ������" << endl;
	else cout << "�������� ��������: ����" << endl;
	return os;
};
