#include <iostream>
using namespace std;

class Container {               // 통 하나를 나타내는 클래스 
    int size;                   // 현재 저장 량, 최대 저장량은 10 
public:
    Container() {size = 10;}
    void fill();                // 최대량(10)으로 채우기 
    void consume();             // 1 만큼 소모하기 
    int getSize();              // 현재 크기 리턴 
};

void Container::fill() {	// 통이 10이 될때까지 채운다.
	while (this->size != 10)
		this->size++;
}

void Container::consume() {
	this->size--;
}

int Container::getSize() {
	return this->size;
}

class CoffeeVendingMachine {    // 커피자판기를 표현하는 클래스 
    Container tong[3];          // tong[0]는 커피, tong[1]은 물, tong[2]는 설탕통을 나타냄
    void fill();                // 3개의 통을 모두 10으로 채움 
    void selectEspresso();      // 에스프레소를 선택한 경우, 커피 1, 물 1 소모 
    void selectAmericano();     // 아메리카노를 선택한 경우, 커피 1, 물 2 소모 
    void selectSugarCoffee();   // 설탕커피를 선택한 경우, 커피 1, 물 2, 설탕 1 소모
    void show();               // 현재 커피, 물, 설탕의 잔량 출력 
public:
    void run();  // 커피 자판기 작동 
};

void CoffeeVendingMachine::run() {
	

	cout << "***** 커피 자판기를 작동합니다. *****" << endl;
	while (true) {
		cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기)>> ";
		int n;

		cin >> n;
		if (n == 1) {
			selectEspresso();
		} else if (n == 2) {
			selectAmericano();
		} else if (n == 3) {
			selectSugarCoffee();
		} else if (n == 4) {
			show();
		} else if (n == 5) {
			fill();
		}
	}
}
void CoffeeVendingMachine::fill() {
	tong[0].fill();
	tong[1].fill();
	tong[2].fill();
	show();	// 전부 다 채우고 잔량을 보여준다.
}

void CoffeeVendingMachine::selectEspresso() {
	if (!(tong[0].getSize()) || !(tong[1].getSize())) {	// 커피가 0이거나 물이 0이면 원료부족
		cout << "원료가 부족합니다." << endl;
		return ;
	}
	tong[0].consume();
	tong[1].consume();
	cout << "에스프레소 드세요" << endl;
}

void CoffeeVendingMachine::selectAmericano() {
	if (!(tong[0].getSize()) || tong[1].getSize() < 2) {	// 커피가 0이거나 물이 2보다 작으면 부족
		cout << "원료가 부족합니다." << endl;
		return ;
	}
	tong[0].consume();
	tong[1].consume();
	tong[1].consume();
	cout << "아메리카노 드세요" << endl;
}

void CoffeeVendingMachine::selectSugarCoffee() {
	if (!(tong[0].getSize()) || tong[1].getSize() < 2 || !(tong[2].getSize())) {
		cout << "원료가 부족합니다." << endl;	// 커피가 0이거나 물이 2보다 작거나 설탕이 0이면 부족
		return ;
	}
	tong[0].consume();
	tong[1].consume();
	tong[1].consume();
	tong[2].consume();
	cout << "설탕커피 드세요" << endl;
}

void CoffeeVendingMachine::show() {	// 잔량표시
	cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize() << endl;
}

int	main()
{
	CoffeeVendingMachine	machine;
	machine.run();
}