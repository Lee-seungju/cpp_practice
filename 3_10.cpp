#include <iostream>
#include <string>
using namespace std;

class Add {
	private:
		int a;
		int b;
	public:
		void setValue(int x, int y) {
			a = x;
			b = y;
		}
		int	calculate() { return a+b; }
};

class Sub {
	private:
		int a;
		int b;
	public:
		void setValue(int x, int y) {
			a = x;
			b = y;
		}
		int	calculate() { return a-b; }
};

class Mul {
	private:
		int a;
		int b;
	public:
		void setValue(int x, int y) {
			a = x;
			b = y;
		}
		int	calculate() { return a*b; }
};

class Div {
	private:
		int a;
		int b;
	public:
		void setValue(int x, int y) {
			a = x;
			b = y;
		}
		int	calculate() { return a/b; }
};

int	main()
{
	Add a;
	Sub s;
	Mul m;
	Div d;
	while(true) {
		int x;
		int y;
		char k;
		cout << "두 정수와 연산자를 입력하세요>>";
		// 세 값을 각각 변수에 넣는다.
		cin >> x >> y >> k;
		// k값에 따라 다르게 넣어준다.
		if (k == '+') {
			a.setValue(x, y);
			cout << a.calculate() << endl;
		} else if (k == '-') {
			s.setValue(x, y);
			cout << s.calculate() << endl;
		} else if (k == '*') {
			m.setValue(x, y);
			cout << m.calculate() << endl;
		} else if (k == '/') {
			d.setValue(x, y);
			cout << d.calculate() << endl;
		} else {
			cout << "잘못 입력하셨습니다." << endl;
		}
	}
}