#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;



class My_string
{
public:
	My_string();
	My_string(const char *str);
	~My_string();
	void print();

	My_string& operator =(const My_string &other) {

		if (this->str != nullptr) {
			delete[] str;
		}
			str_lenght = strlen(other.str);
			this->str = new char[str_lenght + 1];

			for (int i = 0; i < str_lenght; i++) {
				this->str[i] = other.str[i];
			}

			this->str[str_lenght] = '\0';
			return *this;
	}

	My_string operator +(const My_string &other) {
		
		My_string temp_str;
		temp_str.str = new char[strlen(this->str) + strlen(other.str) + 1];
		temp_str.str_lenght = strlen(this->str) + strlen(other.str) + 1;
		int i = 0;
		for (; i < strlen(this->str); i++)
		{
			temp_str.str[i] = this->str[i];
		}
		for (int j = 0; j < strlen(other.str); j++, i++) {
			temp_str.str[i] = other.str[j];
		}
		temp_str.str[strlen(this->str) + strlen(other.str)] = '\0';

		return temp_str;
	}

	My_string(const My_string &other) {

		str_lenght = strlen(other.str);
		this->str = new char[str_lenght + 1];

		for (int i = 0; i < str_lenght; i++) {
			this->str[i] = other.str[i];
		}

		this->str[str_lenght] = '\0';
	}
	 bool operator ==(const My_string &other) {
		if (this->str_lenght != other.str_lenght) {
			return false;
		}
		for (int i = 0; i < this->str_lenght; i++)
		{
			if (this->str[i] != other.str[i]) {
				return false;
			}
		}
		return true;
	}
	 bool operator !=(const My_string &other) {
		 if (this->str_lenght != other.str_lenght) {
			 return true;
		 }
		 for (int i = 0; i < this->str_lenght; i++)
		 {
			 if (this->str[i] != other.str[i]) {
				 return true;
			 }
		 }
		 return false;
	}

	friend ostream& operator <<(ostream &out, const My_string &other) {
		if (other.str == nullptr) {
			return out;
		}
		out << other.str;
		return out;
	}

	int length() {
		return str_lenght;
	}
	/*
	friend istream& operator >>(istream &in, My_string &other) {
		char ch = 0;
		int counter = 0;
		while (counter<10) {
			cin >> ch;
			counter++;
		}
		other.str_lenght = counter;
		other.str=new char[other.str_lenght+1]

		return in;
	}
	*/
private:
	char *str;
	int str_lenght = 0;
};
My_string::My_string() {
	this->str = nullptr;
	str_lenght = 0;
}

My_string::My_string(const char *str)
{
	str_lenght = strlen(str);
	this->str = new char[str_lenght + 1];

	for (int i = 0; i < str_lenght; i++) {
		this->str[i] = str[i];
	}

	this->str[str_lenght] = '\0';
}

My_string::~My_string()
{
	delete[] this->str;
}

void My_string::print() {
	for (int i = 0; i < str_lenght; i++) {
		cout << this->str[i];
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
<<<<<<< HEAD
<<<<<<< HEAD
	My_string str1 = "Str2";
	My_string str2 = "Str2";
	cout << str1 + str2 << endl;
	if (str1 != str2) {
		cout << "strings not same" << endl;
	}
	if (str1 == str2) {
		cout << "strings are same" << endl;
	}

	cout << str1.length()+str2.length() << endl;
=======
=======
>>>>>>> bdedd4eed2f2d0787c7748fd631b348d1ab7583c
	char ch,name[20];
	int counter = 0;
	while (counter<20) {
		cin >> ch;
		if (_getch() == '\n') break;
		name[20] = ch;
		counter++;
	}
	name[20] = '\0';
	for (int i = 0; i < counter; i++) {
		cout << name[i];
	}
<<<<<<< HEAD
>>>>>>> bdedd4eed2f2d0787c7748fd631b348d1ab7583c
=======
>>>>>>> bdedd4eed2f2d0787c7748fd631b348d1ab7583c

	system("pause");
	return 0;
}