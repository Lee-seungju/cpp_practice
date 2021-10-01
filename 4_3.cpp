#include <iostream>
#include <string>
using namespace std;

int	main() {
	string str;
	int	i = 0;
	int count = 0;
	int len;
	
	cout << "문자열 입력>>";
	getline(cin, str);
	len = str.length();
	while (i < len) {
		if (str[i] == 'a')
			count++;
		i++;
	}
	cout << "문자 a는 " << count << "개 있습니다." << endl;
}