#ifndef _BASIC_H__
#define _BASIC_H__

#include<iostream>
#include<string>

using namespace std;

class pos{

private:

	string productName;
	int price;

public:

	virtual void setProduct();
	virtual int getProduct();

};

class Table{

private:
	
	int tableNum;
	const int MAX_TABLE=15;
	
public:
	
	int getTableNumber();


};



#endif