#include<iostream>
#include<string>
using namespace std;
 
class Integer {
	private:
		int num;	
	public:
		Integer(int n);
		Integer(string n);
		int get();
		int isEven();
		void set(int s);
};

Integer::Integer(int n) {
	this->num = n;
}

Integer::Integer(string n) {
	this->num = stoi(n);
}

int Integer::get() {
	return this->num;
}

int Integer::isEven() {
	return true;
}

void Integer::set(int s) {
	this->num = s;
}


int main() {
    Integer n(30);
    cout << n.get() << ' '; // 30 출력 
    n.set(50);
    cout << n.get() << ' '; // 50 출력 
    
    Integer m("300");
    cout << m.get() << ' '; // 300 출력 
    cout << m.isEven(); // true(정수로 1) 출력 
}
