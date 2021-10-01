#include <iostream>
#include <string>

using namespace std;
 
 class Date {
	private :	// 클래스 안의 멤버들은 private을 이용해서 외부에서 접근하지 못하도록 합니다.
		int year;
		int month;
		int day;
	public :	// 외부에서 사용할 함수들과 생성자는 public으로 설정합니다.
		Date(string all);
		Date(int year, int month, int day);
		void show();
		int getYear() { return this->year; }	// 원래 string으로 했다가 프린트가 이상하게 되서 int로 변환시켰습니다.
		int getMonth() { return this->month; }
		int getDay() { return this->day; }
};

Date::Date(int year, int month, int day) {
	this->year = year;	// 클래스 안의 year을 매개변수 year로 값을 넣어줍니다. 밑에도 마찬가지로 해줍니다.
	this->month = month;
	this->day = day;
}

Date::Date(string all) {
	int first = all.find('/');	// 처음 '/'를 찾는 과정입니다. 
	int second = all.find('/', first + 1);
	// 두번째 '/'를 찾는 과정입니다. 1994/01/05, 1994/1/5 처럼 두번째 인자와 세번재 인자가 1글자 또는 2글자이기 때문에 정확한 위치를 찾아주었습니다.

	this->year = stoi(all.substr(0, first));
	this->month = stoi(all.substr(first + 1, second - (first + 1)));
	this->day = stoi(all.substr(second + 1, all.length()));
	// substr로 첫번째 인덱스와 마지막 인덱스를 기준으로 string을 뽑은 다음 stoi를 이용해 int형으로 반환시켜주었습니다.
	// length()는 문자열 전체 길이를 반환시켜줍니다. 마지막 글자까지 출력하기 위해 사용했습니다.
}

void Date::show() {
	cout << this->year << "년" << this->month << "월" << this->day << "일" << endl;
}

int main() {
    Date birth(2014, 3, 20);
    Date independenceDay("1945/8/15");
    independenceDay.show();
    cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
}
