#include <iostream>
using namespace std;

class Circle {
    int radius; // 원의 반지름 값 
public:
    void setRadius(int radius); // 반지름을 설정한다. 
    double getArea(); // 면적을 리턴한다. 
};

void Circle::setRadius(int radius) {
	this->radius = radius;
}

double Circle::getArea() {
	return 3.14 * this->radius * this->radius;
}

int	main()
{
	Circle a[3];	// 3개의 배열 클래스 생성
	int	r;
	int count = 0;

	cout << "원 1의 반지름>>";
	cin >> r;
	a[0].setRadius(r);	// 포인트가 아니기 때문에 .으로 접근
	cout << "원 2의 반지름>>";
	cin >> r;
	a[1].setRadius(r);
	cout << "원 3의 반지름>>";
	cin >> r;
	a[2].setRadius(r);
	for(int i=0; i<3; i++) {	// 3개의 원의 면적중에 100보다 큰거 찾기
		if (a[i].getArea() > 100)
			count++;
	}
	cout << "면적이 100보다 큰 원은 " << count << "개 입니다." << endl;
}