#include<iostream>
#include<string>
#define MAX_PRODUCT 5 
using namespace std;

struct Product{ //��ǰ�Է� ����ü
	string bacode;
	string productName;
	int price;
};

void addProduct(Product &p, string bacode, string productName, int price); //��ǰ �߰� �Լ�
void printProduct(Product *p, int count); //��ϵ� ��ǰ ��� �Լ�
void printMenu(); // �޴� ��� �Լ�
bool isStored(Product *p, string bacode, int count); //����� ��ǰ���� ���ϴ� �Լ�
bool isMax(int count); //������ �� �ִ��� Ȯ�� �Լ�

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

				cout << "��ǰ ��� �޴� �Դϴ�.\n";
				cout << "---------------------\n";
				cout << "���ڵ� : ";

				cin >> bacode;

				if (!isStored(p, bacode, count)){
					cout << "�̹� �����ϴ� ���ڵ��Դϴ�.\n";
					continue;
				}

				cout << "��ǰ�� : ";
				cin.ignore();
				getline(cin, productName);

				cout << "���� : ";
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
				cout << "����뷮t �ʰ��߽��ϴ�..\n";
			}

		}
		else if (input == "q" || input == "Q"){
			return 0;
		}
		else{
			cout << "�߸��� ����Դϴ�.\n";
		}

	}



	return 0;
}

void printMenu(){

	cout << "----------------\n";
	cout << "1. ��� ��ǰ ��ȸ\n";
	cout << "2. ��ǰ ���\n";
	cout << "Q. ����\n";
	cout << "----------------\n";
	cout << "������ �Ͻðڽ��ϱ�?";

}


void printProduct(Product *p, int count){

	if (count == 0){
		cout << "��ϵ� ��ǰ�� �����ϴ�.\n";
		return;
	}
	for (int i = 0; i<count; i++){
		cout << "---------------------\n";
		cout << "���ڵ� : ";
		cout << p[i].bacode << endl;
		cout << "��ǰ�� : ";
		cout << p[i].productName << endl;
		cout << "���� : ";
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


