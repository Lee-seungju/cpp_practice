#include <iostream>
#include <string>
using namespace std;

// Ram.h
class Ram {
    char mem[100 * 1024]; // 100KB 메모리. 한 번지는 한 바이트이므로 char 타입 사용 
    int size;
public:
    Ram(); // mem 배열을 0으로 초기화하고 size를 100*1024로 초기화 
    ~Ram(); // "메모리 제거됨" 문자열 출력 
    char read(int address);    // address 주소의 메모리 바이트 리턴 
    void write(int address, char value); // address 주소에 한 바이트로 value 저장 
};

// Ram.cpp
Ram::Ram() {	// 생성자. 문제의 조건대로 초기화
	this->size = 100*1024;
	for(int i=0; i<this->size; i++) {
		this->mem[i] = 0;
	}
}

Ram::~Ram() {	// 소멸자. 힙이 아닌 스택에 넣었으니 프로그램이 종료될때 소멸자 실행됨
	cout << "메모리 제거됨" << endl;
}

char	Ram::read(int address) {
	return (this->mem[address]);	// address가 인덱스인 mem값 출력
}

void	Ram::write(int address, char value) {
	this->mem[address] = value;	// address가 인덱스인  mem에 value 저장
}

// main.cpp
int main() {
    Ram ram;
    ram.write(100, 20); // 100 번지에 20 저장 
    ram.write(101, 30); // 101 번지에 30 저장 
    char res = ram.read(100) + ram.read(101); // 20 + 30 = 50
    ram.write(102, res); // 102 번지에 50 저장 
    cout << "102 번지의 값 = " << (int)ram.read(102) << endl; // 102 번지 값 출력 
}
