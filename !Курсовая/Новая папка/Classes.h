#include <iostream>
#include <fstream>
using namespace std;
///////////////////////////////////////////
class Money {

	//static int count;//-------------------------------------------------������� ���������� ��������

public:
	string Currency;
	long Sum;
	Money();
	Money(string Currency, long Sum);
	string GetCurrency();
	long GetSum();
};
//______________________________________________________________________����������� �����
class AccPrototype {
public:
		virtual void AddMoney(long Sum) = 0;
		virtual long SubMoney(long Sum) = 0;
};
//______________________________________________________________________��������� ������������
class Account: public AccPrototype {

	//static int count;//-------------------------------------------------������� ���������� ��������

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
	void operator!();//-------------------------------------------------���������� ! (������ �������) ��� Account
	friend ostream & operator<<(ostream &, Account &);//----------------���������� ��� �������
};
//______________________________________________________________________����������� �����
class PremParametr {
public:
	virtual bool GetParam() = 0;
	virtual void ChangeParam() = 0;
};
//______________________________________________________________________������������� ������������
class PremAccount:public Account,public PremParametr {
public:
	//static int count;//-------------------------------------------------������� ���������� ��������
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
	void operator!();//-------------------------------------------------���������� ! (������ �������) ��� PremAccount
	PremAccount(string FIO, long ident, Money m,bool param) {
		this->param = param;
		this->FIO = FIO;
		this->ident = ident;
		this->m = m;
		cout << "������ PremAccount ������" << endl;
		//this->count++;//-------------------------------------------------������� ���������� ��������
	}
	bool GetParam() {
		return this->param;
	}
	void ChangeParam() {
		if (this->param == true)
			this->param = false;
		else this->param = true;
	}
	friend ostream & operator<<(ostream &, PremAccount &);//-------------���������� ��� �������
};