#include <iostream>

using namespace std;
 
class Circle{
    int radius;
public:
    Circle(int radius=0) { this->radius = radius; }
    int getRadius() { return radius; }
    void setRadius(int radius) { this->radius = radius; }
    double getArea() { return 3.14*radius*radius; }
};
 
// NameCircle 클래스 - Circle을 상속받는다.
class NameCircle : public Circle { // public으로 상속받았기 때문에 private -> pravite, public -> public으로 가져옴
    string name;
public:
    void	setRN(int R, string N);
    string 	getName();
};

string	NameCircle::getName(){
    return name;
}

void	NameCircle::setRN(int R, string N){
	setRadius(R);
	this->name = N;
}

int main() {
    string name;
    int radius,biggest;
    double size[5];
    NameCircle pizza[5];

    cout << "5 개의 정수 반지름과 원의 이름을 입력하세요" << endl;

    for(int i=0; i<5; i++){
        cout << i+1 << ">> ";
        cin >> radius >> name;
        pizza[i].setRN(radius,name);
        size[i] = pizza[i].getArea();
    }
    biggest = 0;
    for(int i=0; i<4; i++){
        if(size[i] < size[i+1])
            biggest = i+1; 
    }
    cout << "가장 면적이 큰 피자는 " << pizza[biggest].getName() << "입니다" << endl;
}
