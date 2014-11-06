#include"person.h"

void person::setInfo(int age, string name){

	this->age = age;
	this->name = name;

}
int person::getAge(){
	
	return this->age;
}

string person::getName(){

	return this->name;

}


int main(){

	person p1(26,"jackson");

	cout<<p1.getName();
	

	return 0;

}