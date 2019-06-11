#include <iostream>

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
	
	system("pause");
	return 0;
}