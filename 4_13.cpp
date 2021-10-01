#include <iostream>
#include <string>
using namespace std;

class Histogram {
	private:
		int count[25];
		string str;
	public:
		Histogram();
		Histogram(string str);
		void put(string str);
		void putc(char c);
		void print();
};

Histogram::Histogram() {
	for(int i=0; i<26; i++) {
		this->count[i] = 0;
	}
}

Histogram::Histogram(string str) {
	this->str = str + '\n';
	for(int i=0; i<26; i++) {
		this->count[i] = 0;
	}
}

void Histogram::put(string str) {
	this->str += str;
}

void Histogram::putc(char c) {
	this->str += c;
}

void Histogram::print() {
	int sum = 0;
	string sub = this->str;
	int len = this->str.length();
	int i = 0;

	cout << this->str << "\n" << endl;
	
	while (i < len) {
		if (sub[i] >= 'A' && sub[i] <= 'Z') {
			sub[i] += 32;	// 아스키값으로 보면 [대문자 알파벳] + 32 = [소문자 알파벳]이다.
		}
		// 위 과정에서 대문자 알파벳은 소문자로 바뀌었으니 알파벳과 알파벳이 아닌 기호같은 것들이 남았다.
		// 알파벳이 아닌 경우가 들어오면 아스키값으로 코드가 꼬일수 있으므로
		// 알파벳이 아닌 경우에는 다음 인덱스로 넘기고 continue로 다시 위로 올려줍니다.
		if (sub[i] < 'a' || sub[i] > 'z') {
			i++;
			continue ;
		}
		// a의 아스키값은 97이다. 그러므로 97을 빼면 0이 된다. 즉 count[0] = a로 두고 개수를 세기 위함이다.
		// count[0] -> a의 개수
		// count[1] -> b의 개수
		this->count[sub[i] - 97]++;
		i++;
	}
	for (int j=0; j<26; j++) {	// 합계 정산중.
		sum += this->count[j];
	}
	cout << "총 알파벳 수 " << sum << "\n" << endl;

	for (int k=0; k<26; k++) {
		// (char)로 알바벳을 출력해주고 그뒤에 몇개가 있는지 보여준 다음.
		// *을 for문을 통해 찍어준다.
		cout << (char)(k + 97) << " (" << this->count[k] << ")   : ";
		for (int q=0; q<this->count[k]; q++) {
			cout << "*";
		}
		cout << endl;
	}
}

int	main()
{
	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();
}