#include <iostream>

using namespace std;

class Person {
    int id;
    double weight;
    string name;
public:
    void show() { cout << id << ' ' << weight << ' ' << name << endl; }
	// 생성자 생성
	Person();
	Person(int _id, string _name);
	Person(int _id, string _name, double _weight);
};

// 생성자 오버라이딩, 초기화 리스트를 이용해 예제의 결과를 참고해 설정한다.
Person::Person(): id(1), weight(20.5), name("Grace") {
}

Person::Person(int _id, string _name): id(_id), name(_name), weight(20.5) {
}

Person::Person(int _id, string _name, double _weight): id(_id), name(_name), weight(_weight) {
}

int main() {
    Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
    grace.show();
    ashley.show();
    helen.show();
}