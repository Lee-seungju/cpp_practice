#include <iostream>

using namespace std;

class Matrix {
	private:
		int n[4];
	public:
		Matrix();
		Matrix(int _n1, int _n2, int _n3, int _n4);
		void show();

		Matrix operator+ (Matrix b);
    	Matrix operator+= (Matrix &b);
    	bool operator== (Matrix b);
};

Matrix	Matrix::operator+ (Matrix b) {
	Matrix	a;
	for(int i=0; i< 4; i++) {
		a.n[i] = this->n[i] + b.n[i];
	}
	return a;
}

Matrix	Matrix::operator+= (Matrix &b) {
	for(int i=0; i<4; i++) {
		this->n[i] += b.n[i];
	}
	return *this;
}

bool	Matrix::operator== (Matrix b) {
	for(int i=0; i<4; i++) {
		if (this->n[i] != b.n[i])
			return false;
	}
	return true;
}

Matrix::Matrix() {
	for (int i=0; i<4; i++) {
		n[i] = 0;
	}
}

Matrix::Matrix(int _n1, int _n2, int _n3, int _n4) {
	n[0] = _n1;
	n[1] = _n2;
	n[2] = _n3;
	n[3] = _n4;
}

void Matrix::show() {
	cout << "Matrix = { ";
	for (int i=0; i<4; i++) {
		cout << n[i] << " ";
	}
	cout << "}" << endl;
}

int main()
{
	Matrix a(1,2,3,4), b(2,3,4,5), c;
    c = a + b;
    a += b;
    a.show(); b.show(); c.show();
    if(a==c)
        cout << "a and c are the same" << endl;
}