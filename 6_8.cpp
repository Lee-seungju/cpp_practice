#include <iostream>

using namespace std;

class Trace {
	public:
		static string method[100];
		static string str[100];
		static int	count;
		static void put(string _method, string _str);
		static void print(string _method = "all");
};

int	Trace::count = 0;
string Trace::str[100];
string Trace::method[100];

void Trace::put(string _method, string _str) {
	method[count] = _method;
	str[count] = _str;
	count++;
}

void Trace::print(string _method) {
	if (_method == "all") {
		cout << "----- 모든 Trace 정보를 출력합니다. -----" << endl;
		for (int i=0; i<count; i++) {
			cout << method[i] << ":" << str[i] << endl;
		}
	}
	else {
		cout << "----- " << _method << "태그의 Trace 정보를 출력합니다. -----" << endl;
		for (int i=0; i<count; i++) {
			if (_method == method[i])
				cout << method[i] << ":" << str[i] << endl;
		}
	}
}

void f() {
    int a, b, c;
    cout << "두 개의 정수를 입력하세요>>";
    cin >> a >> b;
    Trace::put("f()", "정수를 입력 받았음"); // 디버깅 정보 저장
    c = a + b; 
    Trace::put("f()", "합 계산"); // 디버깅 정보 저장
    cout << "합은 " << c << endl; 
}
 
int main() {
    Trace::put("main()", "프로그램을 시작합니다"); // 디버깅 정보 저장
    f();
    Trace::put("main()", "종료");    // put()의 첫 번째 매개 변수는 태그이고 
                                     // 두 번째 매개 변수는 디버깅 정보이다. 
    Trace::print("f()"); // "f()" 태그를 가진 디버깅 정보를 모두 출력한다.
    Trace::print(); // 모든 디버깅 정보를 출력한다.
}
