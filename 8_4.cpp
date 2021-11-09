#include <iostream>

using namespace std;

class Point {
    int x,y;
	public:
		Point(int x, int y) { this->x = x; this->y = y; }
		int getX(){ return x; }
		int getY(){ return y; }
	protected:
		void move(int x, int y) { this->x = x; this->y = y; }
};

class ColorPoint : public Point {
	private:
		string color;
	public:
		// 일반 생성자가 두 argument를 받는 생성자를 생성해준다.
		ColorPoint();
		ColorPoint(int x, int y);
		// 위치와 색깔을 설정할 수 있는 메서드를 만든다.
		void setPoint(int x, int y);
		void setColor(string color);
		void show();
};

// 최기화 리스트를 통해 간단하게 정의해준다.
ColorPoint::ColorPoint(): Point(0, 0), color("BLACK") {
}

ColorPoint::ColorPoint(int x, int y): Point(x, y), color("BLACK"){
}

void	ColorPoint::setPoint(int x, int y){
	//move는 protected므로 다른 클래스에서 사용가능하다.
	Point::move(x, y);
}

void	ColorPoint::setColor(string color){
	this->color = color;
}

void	ColorPoint::show(){
	cout << this->color << "색으로 (" << Point::getX() << "," << Point::getY() << ")에 위치한 점입니다.\n"; 
}

int main() {
    ColorPoint zeroPoint; // BLACK 색에 (0, 0) 위치의 점
    zeroPoint.show(); // zeroPoint를 출력한다.
    
    ColorPoint cp(5, 5);
    cp.setPoint(10, 20);
    cp.setColor("BLUE");
    cp.show(); // cp를 출력한다.
}
