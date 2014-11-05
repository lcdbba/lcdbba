#ifndef __PERSON_H__
#define __PERSON_H__

#include<iostream>
#include<string>
using namespace std;


class person{

private:
	int age;
	string name;
public:
	person() :age(0), name(""){};
	person(int age, string name) :age(age), name(name){};

	void setInfo(int age, string name);
	int getAge();
	string getName();

};

#endif