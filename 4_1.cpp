#include<iostream>
using namespace std;
 
class Color {
    int red, green, blue;
public:
    Color() {red = green = blue = 0;}
    Color(int r, int g, int b) {red = r; green = g; blue = b;}
    void setColor(int r, int g, int b) {red = r; green = g; blue = b;}
    void show() {cout << red << ' ' << green << ' ' << blue << endl;}
};
 
int main() {
    Color screenColor(255,0,0);
    Color *p;
	// p는 screenColor의 주소값을 갖게됨. screenColor 접근가능
    p = &screenColor;
    // 포인트 배열은 ->로 연결
	p->show();
	Color colors[3];
    p = colors;	// color 배열과 연결됨
    
    p[0].setColor(255, 0, 0);
	p[1].setColor(0, 255, 0);
	p[2].setColor(0, 0, 255);
    
    for(int i=0; i<3; i++) {
		p[i].show();
	}
}