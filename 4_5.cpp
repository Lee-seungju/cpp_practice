#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int	main()
{
	srand((unsigned)time(0));
	int n = rand();
	char change[53] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int ch_rand = rand() % 52;

	while (true) {
		string str;
		cout << "아래 한 줄을 입력하세요.(exit를 입력하면 종료합니다.)" << endl;
		cout << ">>";
		getline(cin, str);
		if (str == "exit")
			return (0);
		n = n % str.length();
		str[n] = change[ch_rand];
		cout << str << endl;
	}
}