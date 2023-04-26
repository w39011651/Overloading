#include<iostream>

using namespace std;
class Fraction {
public:
	Fraction()
		:num(0), den(1)
	{
	}
	Fraction(int num, int den) {
		this->num = num;
		this->den = den;
	}
	int getnum() {
		return num;
	}
	int getden() {
		return den;
	}
	void setnum(int num) {
		this->num = num;
	}
	void setden(int den) {
		if(den!=0)
			this->den = den;
	}
	Fraction& operator-() {
		num = -num;
		return *this;
	}
	Fraction& operator+(const Fraction& op2) {
		int Newden = 1, Newnum = 0;
		if (den == op2.den) {
			Newden = den;
			Newnum = num + op2.num;
		}
		else {
			Newden = den * op2.den;
			Newnum = num * op2.den + op2.num * den;
		}
		Fraction temp(Newnum, Newden);
		return temp;
	}
	Fraction& operator-(const Fraction& op2) {
		int Newden = 1, Newnum = 0;
		if (den == op2.den) {
			Newden = den;
			Newnum = num - op2.num;
		}
		else {
			Newden = den * op2.den;
			Newnum = - num * op2.den + op2.num * den;
		}
		Fraction temp(Newnum, Newden);
		return temp;
	}
	Fraction& operator*(const Fraction& op2) {
		int Newden = den * op2.den, Newnum = num * op2.num;
		Fraction temp(Newnum, Newden);
		return temp;
	}
	Fraction& operator/(const Fraction& op2) {
		int Newden = den * op2.num, Newnum = num * op2.den;
		Fraction temp(Newnum, Newden);
		return temp;
	}
	
	bool operator>(const Fraction& op2) {
		int left = op2.den * num, right = den * op2.num;
		bool returner;
		(left > right) ? returner = true : returner = false;
		return returner;
	}
	bool operator<(const Fraction& op2) {
		int left = op2.den * num, right = den * op2.num;
		bool returner;
		(left < right) ? returner = true : returner = false;
		return returner;
	}
	bool operator==(const Fraction& op2) {
		int left = op2.den * num, right = den * op2.num;
		bool returner;
		(left == right) ? returner = true : returner = false;
		return returner;
	}
	bool operator!=(const Fraction& op2) {
		return !(*this == op2);
	}
	bool operator>=(const Fraction& op2) {
		return (*this == op2 || *this > op2);
	}
	bool operator<=(const Fraction& op2) {
		return (*this == op2 || *this < op2);
	}

	friend ostream& operator<<(ostream& os, const Fraction& f) {
		if (f.num != f.den)os << f.num << "/" << f.den;
		else os << "1";
		return os;
	}
	friend istream& operator>>(istream& is, Fraction& f) {
		is >> f.num >> f.den;
		return is;
	}

	Fraction& operator++() {
		num += den;
		return *this;
	}
	Fraction& operator--() {
		num -= den;
		return *this;
	}

	Fraction operator=(const Fraction& op2) {
		den = op2.den;
		num = op2.num;
		return *this;
	}

	Fraction& simplify() {
		int greater, less, factor=1;
		if (num >= den) {
			greater = num;
			less = den;
		}
		else {
			greater = den;
			less = num;
		}
		while (greater>0&&less>0) {
			if (greater >= less) {
				greater -= less;
			}
			else {
				less -= greater;
			}
		}
		if (greater == 0)factor = less;
		else if (less == 0)factor = greater;

		den /= factor;
		num /= factor;
		return *this;
	}
private:
	int num = 0;//¤À¤l
	int den = 1;//¤À¥À
};
int main() {
	//CONSTRUCTOR
	Fraction f1(3, 5), f2(4, 6);
	cout << f1 << " " << f2 << endl;
	//OPERATOR+-*/
	Fraction f3 = f1 + f2, f4 = f1 - f2, f5 = f1 * f2, f6 = f1 / f2;
	cout << f3 << " " << f4 << " " << f5 << " " << f6 << endl;
	//OPERATOR-
	Fraction f7(16, 7);
	cout << -f7 << endl;
	//OPERATOR COMPARE
	Fraction f8(3, 5), f9(4,7);
	cout << (f1 > f9) << " " << (f1 < f9) << " " << (f1 >= f9) << " " << (f1 < f9) << " "
		<< (f1 != f9) << " " << (f1 == f9) << " "<<(f1 == f8) << endl;
	//INCREMENT AND DECREMENT
	Fraction f10(3, 5), f11(3,5);
	--f10;
	++f11;
	cout << f10 << " " << f11<<endl;
	//OPERATOR ASSIGNMENT
	Fraction f12;
	f12 = f10;
	cout << f12 << endl;
	//SIMPLIFY
	Fraction f13(13, 91);
	cout << f13 << endl;
	cout << f13.simplify() << endl;
}