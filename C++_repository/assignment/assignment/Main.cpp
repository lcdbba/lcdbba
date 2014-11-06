#include<iostream>
#include<string>
#define MAX_PRODUCT 5 
using namespace std;

struct Product{ //상품입력 구조체
	string bacode;
	string productName;
	int price;
};

void addProduct(Product &p, string bacode, string productName, int price); //상품 추가 함수
void printProduct(Product *p, int count); //등록된 상품 출력 함수
void printMenu(); // 메뉴 출력 함수
bool isStored(Product *p, string bacode, int count); //저장된 상품인지 비교하는 함수
bool isMax(int count); //저장할 수 있는지 확인 함수

int main(){

	int count = 0;
	Product p[MAX_PRODUCT];

	while (true){

		string bacode;
		string productName;
		int price;
		string input;

		printMenu();
		cin >> input;

		if (input == "1"){

			printProduct(p, count);

		}
		else if (input == "2"){

			if (isMax(count) == false){

				cout << "상품 등록 메뉴 입니다.\n";
				cout << "---------------------\n";
				cout << "바코드 : ";

				cin >> bacode;

				if (!isStored(p, bacode, count)){
					cout << "이미 존재하는 바코드입니다.\n";
					continue;
				}

				cout << "상품명 : ";
				cin.ignore();
				getline(cin, productName);

				cout << "가격 : ";
				cin >> price;
				if (cin.fail() == 1){
					cout << "";
					cin.clear();
					cin.ignore();
					continue;
				}

				addProduct(p[count], bacode, productName, price);

				count++;

			}
			else{
				cout << "저장용량t 초과했습니다..\n";
			}

		}
		else if (input == "q" || input == "Q"){
			return 0;
		}
		else{
			cout << "잘못된 등록입니다.\n";
		}

	}



	return 0;
}

void printMenu(){

	cout << "----------------\n";
	cout << "1. 등록 상품 조회\n";
	cout << "2. 상품 등록\n";
	cout << "Q. 종료\n";
	cout << "----------------\n";
	cout << "무엇을 하시겠습니까?";

}


void printProduct(Product *p, int count){

	if (count == 0){
		cout << "등록된 상품이 없습니다.\n";
		return;
	}
	for (int i = 0; i<count; i++){
		cout << "---------------------\n";
		cout << "바코드 : ";
		cout << p[i].bacode << endl;
		cout << "상품명 : ";
		cout << p[i].productName << endl;
		cout << "가격 : ";
		cout << p[i].price << endl;
		cout << "---------------------\n";

	}
}

bool isStored(Product *p, string bacode, int count){

	for (int i = 0; i<count + 1; i++){

		if (p[i].bacode == bacode)
			return false;

	}

	return true;

}

bool isMax(int count){

	if (MAX_PRODUCT == count)
		return true;
	else
		return false;

}


void addProduct(Product &p, string bacode, string productName, int price){



	p.bacode = bacode;
	p.productName = productName;
	p.price = price;

}


