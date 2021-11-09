#include <iostream>

using namespace std;

class Book{
    string title;
    int price, pages;
public:
    Book(string title="", int price=0, int pages=0){
        this->title = title; this->price = price; this->pages = pages;
    }
    void show() {
        cout << title << " " << price << "원 " << pages << " 페이지" << endl;
    }
    string getTitle() {
        return title;
    }

	bool operator==(int p);
	bool operator==(string t);
	bool operator==(Book& b);
};

bool Book::operator==(int p) {
	if (this->price == p)
		return true;
	return false;
}

bool Book::operator==(string t) {
	if (this->title == t)
		return true;
	return false;
}

bool Book::operator==(Book& b) {
	if (this->price == b.price && this->title == b.title)
		return true;
	return false;
}

int main()
{
	Book a("명품 C++" , 30000, 500), b("고품 C++", 30000, 500);
	if(a == 30000) cout << "정가 30000원" << endl; // price 비교 
	if(a == "명품 C++") cout << "명품 C++ 입니다." << endl; // 책 title 비교 
	if(a == b) cout << "두 책이 같은 책입니다." << endl;  // title, price, pages 모두 비교 
}