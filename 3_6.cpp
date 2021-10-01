#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class EvenRandom {
	private:
		int n;
	public:
		EvenRandom();
		int Range(int first, int last);
		int Default();
};

EvenRandom::EvenRandom() {
	this->n = rand();
}

int EvenRandom::Range(int first, int last) {
	// 밑의 while문의 조건에 만약 last와 first 차이가 1일 경우에는
	// 무한루프를 돌기 때문에 예외처리를 해줍니다.
	// 예를 들어 2, 3 이라면 while문 안의 this->n = this->n % last + first에서 3 나누면 0 더하면 2가 무한으로 반복합니다.
	if (last - first == 1) {
		if (first % 2 == 0)
			return first;
		else
			return last;
	}

	// first와 last 범위안에 없는동안 while문을 실행합니다.
	while (this->n < first || this->n > last) {
		// last로 나눈 나머지 값이 first보다 작을 수도 있으므로 first를 더해줍니다. 하지만 더한값이 last보다 클수도 있는데 이때는 while을 다시 돕니다.
		this->n = this->n % last + first;
		if (this->n % 2 == 1)	// 홀수면 짝수로 만들어줍니다.
			this->n++;
	}
	// first < n < last 면 while문이 종료되고 값 반환을 합니다.
	return this->n;
}

int EvenRandom::Default() {	// 일반 기본랜덤값을 지정해주었습니다.
	this->n = this->n % 32767;
	if (this->n % 2 == 1)
		this->n++;
	return (this->n);
}

int main() {
	srand((unsigned)time(0));	// srand로 시드를 바꾸고 시드값을 time으로 계속 바꿔준다.
	
	cout << "-- 0에서 32767까지의 랜덤 정수 10 개--" << endl;
	for(int i=0; i<10; i++) {
		EvenRandom r;
		cout << r.Default() << " ";
	}
	cout << endl;
	cout << endl;
	cout << "-- 2에서 10 까지의 랜덤 정수 10개 --" << endl;
	for(int i=0; i<10; i++) {
		EvenRandom r;
		cout << r.Range(2, 10) << " ";
	}
	cout << endl;
	cout << endl;
}