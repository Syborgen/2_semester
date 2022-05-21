#include <iostream>
#include <fstream>
using namespace std;
///////////////////////////////////////////
class Money {

	//static int count;//-------------------------------------------------подсчет количества объектов

public:
	string Currency;
	long Sum;
	Money();
	Money(string Currency, long Sum);
	string GetCurrency();
	long GetSum();
};
//______________________________________________________________________Виртуальный класс
class AccPrototype {
public:
		virtual void AddMoney(long Sum) = 0;
		virtual long SubMoney(long Sum) = 0;
};
//______________________________________________________________________Одиночное наследование
class Account: public AccPrototype {

	//static int count;//-------------------------------------------------подсчет количества объектов

protected:
	string FIO;
	long ident;
	Money m;
public:
	Account();
	Account(string FIO, long ident, Money m);
	void AddMoney(long Sum);
	long SubMoney(long Sum);
	void fread(string, int);
	long GetIdent() {
	return this->ident;
	};
	virtual void savea(string);
	void operator!();//-------------------------------------------------перегрузка ! (внутри функции) для Account
	friend ostream & operator<<(ostream &, Account &);//----------------перегрузка вне функции
};
//______________________________________________________________________Виртуальный класс
class PremParametr {
public:
	virtual bool GetParam() = 0;
	virtual void ChangeParam() = 0;
};
//______________________________________________________________________Множественное наследование
class PremAccount:public Account,public PremParametr {
public:
	//static int count;//-------------------------------------------------подсчет количества объектов
	bool param;
	PremAccount() {
		this->param = false;
		Money m;
		this->FIO = "";
		this->ident = 0;
		this->m = m;
		
	}
	void fread(string, int);
	void savea(string);
	void operator!();//-------------------------------------------------перегрузка ! (внутри функции) для PremAccount
	PremAccount(string FIO, long ident, Money m,bool param) {
		this->param = param;
		this->FIO = FIO;
		this->ident = ident;
		this->m = m;
		cout << "Объект PremAccount создан" << endl;
		//this->count++;//-------------------------------------------------подсчет количества объектов
	}
	bool GetParam() {
		return this->param;
	}
	void ChangeParam() {
		if (this->param == true)
			this->param = false;
		else this->param = true;
	}
	friend ostream & operator<<(ostream &, PremAccount &);//-------------перегрузка вне функции
};