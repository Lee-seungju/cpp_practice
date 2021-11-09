#include <iostream>

using namespace std;

class Statistics {
	private:
		int *a;
		int size;
	public:
		Statistics();
		bool operator! ();
		Statistics& operator<< (int num);
		void operator~ ();
		void operator>> (int& avg);
		~Statistics();
};

Statistics::Statistics(): a(new int[8]), size(0) {
}

Statistics::~Statistics() {
	delete[] this->a;
}

bool Statistics::operator! (){
        if( this->a && this->size==0) return true;
        return false;
}

Statistics& Statistics::operator<< (int num){
        this->a[this->size] = num;
        this->size++;
        return *this;
}

void Statistics::operator~ (){
        for(int i=0; i<this->size; i++) 
            cout << this->a[i] << ' ';
        cout << endl;
}

void Statistics::operator>> (int& avg){
        avg = 0;
        for(int i=0; i<this->size; i++)
            avg += this->a[i];
         avg /= this->size; 
}

int main() {
    Statistics stat;
    if(!stat) cout << "현재 통계 데이타가 없습니다." << endl;
    
    int x[5];
    cout << "5 개의 정수를 입력하라>>";
    for(int i=0; i<5; i++) cin >> x[i]; // x[i]에 정수 입력 
    
    for(int i=0; i<5; i++) stat << x[i]; // x[i] 값을 통계 객체에 삽입한다. 
    stat << 100 << 200; // 100, 200을 통계 객체에 삽입한다. 
    ~stat; // 통계 데이터를 모두 출력한다. 
    
    int avg;
    stat >> avg; // 통계 객체로부터 평균을 받는다. 
    cout << "avg=" << avg << endl;  // 평균을 출력한다. 
}
