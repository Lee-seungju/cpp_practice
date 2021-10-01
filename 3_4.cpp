#include <iostream>

using namespace std;

class CoffeeMachine {
	private:	// 커피머신의 세 인자 커피, 물, 설탕 선언
		int coffee;
		int water;
		int sugar;
	public:	// main에 맞게 각각 생성자와 메서드 생성
		CoffeeMachine(int cof, int wa, int su);
		void	show();
		void	drinkEspresso();
		void	drinkAmericano();
		void	drinkSugarCoffee();
		void	fill();
};

CoffeeMachine::CoffeeMachine(int cof, int wa, int su) {
	this->coffee = cof;
	this->water = wa;
	this->sugar = su;
}

void	CoffeeMachine::show() { // 출력 부분 완성
	cout << "커피 머신 상태, 커피:" << this->coffee << " 물:" << this->water << " 설탕:" << this->sugar << endl;
}

// main문에 맞춰서 각각 소비를 시킨다.
void	CoffeeMachine::drinkEspresso() {
	this->coffee -= 1;
	this->water -= 1;
}

void	CoffeeMachine::drinkAmericano() {
	this->coffee -= 1;
	this->water -= 2;
}

void	CoffeeMachine::drinkSugarCoffee() {
	this->coffee -= 1;
	this->water -= 2;
	this->sugar -= 1;
}

//while문을 이용해 10이 될때까지 채운다.
void	CoffeeMachine::fill() {
	while (this->coffee != 10)
		this->coffee++;
	while (this->water != 10)
		this->water++;
	while (this->sugar != 10)
		this->sugar++;
}

int main() {
    CoffeeMachine java(5, 10, 3); // 커피량:5, 물량:10, 설탕:6 으로 초기화
    java.drinkEspresso(); // 커피 1, 물 1 소비
    java.show(); // 현재 커피 머신의 상태 출력
    java.drinkAmericano(); // 커피 1, 물 2 소비
    java.show(); // 현재 커피 머신의 상태 출력
    java.drinkSugarCoffee(); // 커피 1, 물 2, 설탕 1 소비
    java.show(); // 현재 커피 머신의 상태 출력
    java.fill(); // 커피 10, 물 10, 설탕 10 으로 채우기
    java.show(); // 현재 커피 머신의 상태 출력
}