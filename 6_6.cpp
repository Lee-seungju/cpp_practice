#include <iostream>

using namespace std;

class ArrayUtiliry2 {
	
	public:
		// s1과 s2를 연결한 새로운 배열을 동적 생성하고 포인터 리턴 
		static int* concat(int s1[], int s2[], int size);

		// s1에서 s2에 있는 숫자를 모두 삭제한 새로운 배열을 동적 생성하여 리턴 
		// 리턴하는 배열의 크기는 retSize에 전달. retSize가 0인 경우 NULL 리턴 
		static int* remove(int s1[], int s2[], int size, int& retSize);
};

int*	ArrayUtiliry2::concat(int s1[], int s2[], int size) {
	int*	n_s = new int[size];
	for(int i=0; i<size/2; i++) {
		n_s[i] = s1[i];
	}

	int		helf = size/2;
	for(int i=0; i<size/2; i++) {
		n_s[helf + i] = s2[i];
	}

	return n_s;
}

int*	ArrayUtiliry2::remove(int s1[], int s2[], int size, int& retSize) {
	// 처음에 중복된 수들의 개수를 모르기 때문에
	// 일단 int 크기를 크게 잡고 시작한다.
	int*	n_s = new int[size];
	int		count = 0;
	for(int i=0; i<size/2; i++) {
		// 중복된 수가 있으면 signal이 증가하게 된다.
		int	signal = 0;
		for(int j=0; j<size/2; j++) {
			if (s1[i] == s2[j])
				signal++;
		}
		// 중복된 값이 없으면 n_s에 값을 넣는다.
		if (signal == 0) {
			n_s[count] = s1[i];
			count++;
			retSize++;
		}
	}
	
	// count는 n_s 배열에 넣은 수의 개수가 된다.
	// 배열 크기를 맞추기 위해 다시 새 int를 만들고 값을 넣는다.
	int*	nn_s = new int[count];
	for(int i=0; i<count; i++) {
		nn_s[i] = n_s[i];
	}

	if (retSize == 0)
		return NULL;
	return nn_s;
}

int main()
{
	int	x[5], y[5];
	int size, retSize = 0;
	ArrayUtiliry2 c;
	cout << "정수 5 개 입력하라. 배열 x에 삽입한다>>";
    for(int i=0; i<5; i++){ 
         cin >> x[i];
    }
	cout << "정수 5 개 입력하라. 배열 y에 삽입한다>>";
    for(int i=0; i<5; i++){ 
         cin >> y[i];
    }
	size = (sizeof(x) + sizeof(y)) / sizeof(int);
	cout << "합친 정수 배열을 출력한다" << endl;
	int* s = c.concat(x, y, size);
	for (int i=0; i<size; i++) {
		cout << s[i] << " ";
	}
	cout << endl;

	cout << "배열 x[]에서 y[]를 뺀 결과를 출력한다. 개수는 ";
	s = c.remove(x, y, size, retSize);
	cout << retSize << endl;
	for (int i=0; i<retSize; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}