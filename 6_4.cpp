#include <iostream>

using namespace std;

class MyVector{
    int *mem;
    int size;
public:
    MyVector();
    MyVector(int n, int val);
    ~MyVector() { delete [] mem; }
	// 테스트를 위한 메서드를 하나 만들어 준다.
	void show();
};
 
MyVector::MyVector() {
    mem = new int [100];
    size = 100;
    for(int i=0; i<size; i++) mem[i] = 0;
}
 
MyVector::MyVector(int n, int val) {
    mem = new int [n];
    size = n;
    for(int i=0; i<size; i++) mem[i] = val;
}

// size 크기를 반환하고 mem에 들어있는 내용을 size만큼 출력해준다.
void	MyVector::show() {
	cout << "size = " << this->size << endl;
	for(int i=0; i<size; i++) {
		cout << this->mem[i] << " ";
	}
	cout << endl;
	cout << endl;
}

int main()
{
	MyVector a;
	MyVector b(10, 50);

	cout << "testing...\n" << endl;
	a.show();
	b.show();
}