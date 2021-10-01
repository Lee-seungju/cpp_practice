#include <iostream>

using namespace std;

class Person{
    string name;
    string tel;
public:
    Person();
    string getName() { return name; }
    string getTel() { return tel; }
    void set(string name, string tel);
};

void Person::set(string name, string tel) {
	this->name = name;
	this->tel = tel;
}

Person::Person() {
	name = "";
	tel = "";
}

int main()
{
	cout << "이름과 전화 번호를 입력해 주세요" << endl;

	Person p[3];	// 배열의 크기가 3인 Persion클래스 생성
	for(int i=0; i<3; i++) {	// 질문과 함께 이름과 전화번호 각 클래스의 set에 저장
		cout << "사람 " << i+1 << ">> ";	// i = 0; -> 처음이 사람 1이 되기 위해 i에 1을 더해줌
		string n;
		string t;

		cin >> n >> t;
		p[i].set(n, t);
	}
	// 모든사람의 이름 출력
	cout << "모든 사람의 이름은 " << p[0].getName() << " " \
		<< p[1].getName() << " " << p[2].getName() << endl;
	cout << "전화번호 검색합니다. 이름을 입력하세요>>";
	
	string search_n;
	string search_tel;

	cin >> search_n;
	// 입력받은 이름이 있는지 찾은후 없으면 없다고 출력
	if (search_n == p[0].getName()) {
		search_tel = p[0].getTel();
	} else if (search_n == p[1].getName()) {
		search_tel = p[1].getTel();
	} else if (search_n == p[2].getName()) {
		search_tel = p[2].getTel();
	} else {
		cout << "해당 이름이 존재하지 않습니다." << endl;
		return (0);	// 밑의 문장까지 나오지 않게 종료.
	}

	// 찾으면 찾은 번호 출력.
	cout << "전화 번호는 " << search_tel << endl;
}
