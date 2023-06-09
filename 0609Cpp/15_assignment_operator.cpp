#include <iostream>
#include <cassert>

using namespace std;

// Special Member Function
// 기본 생성자
// 소멸자
// 복사 생성자
// 복사 대입 연산자
// 이동 생성자
// 이동 대입 연산자

/*
	Deep copy vs Shallow copy
	깊은 복사의 경우 직접 만들어야함
*/

// homework 6개 직접 구현 (+깊은복사로 구현)

class MyString
{
public:
	char* data = nullptr;
	int length = 0;

public:
	MyString() = default;

	MyString(const char* const src = "")
	{
		assert(src);

		length = strlen(src) + 1;
		data = new char[length];

		for (int i = 0; i < length; i++)
			data[i] = src[i];

		data[length - 1] = '\0';
	}

	MyString(const MyString& other)
	{
		cout << "copy constructor" << endl;

		this->length = other.length;

		if (other.data != nullptr)
		{
			this->data = new char[length];
			for (int i = 0; i < this->length; i++)
			{
				this->data[i] = other.data[i];
			}
		}
		else
			data = nullptr;
	}

	~MyString()
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}

	MyString& operator = (const MyString& other)
	{
		if (this == &other) // prevent self-assignment
			return *this;

		if (this->data != nullptr)
		{
			delete[] this->data;
			this->data = nullptr;
		}

		cout << "copy assignment operator" << endl;

		this->length = other.length;

		if (other.data != nullptr)
		{
			this->data = new char[length];
			for (int i = 0; i < this->length; i++)
			{
				this->data[i] = other.data[i];
			}
		}
		else
			data = nullptr;

		return *this;
	}

	MyString(MyString&& other)
	{
		cout << "move constructor" << endl;

		this->data = std::move(other.data);
		this->length = std::move(other.length);

		other.data = nullptr;
	}

	MyString& operator = (MyString&& other)
	{
		cout << "move assignment operator" << endl;

		if (this == &other)
			return*this;

		if (this->data != nullptr)
		{
			if (other.data != nullptr && this->data != other.data)
			{
				delete[] this->data;
				this->data = nullptr;

				this->data = std::move(other.data);
			}
		}
		else
		{
			this->data = std::move(other.data);
		}

		this->length = std::move(other.length);

		other.data = nullptr;

		return *this;
	}
};


int main()
{
	cout << "*******1********" << endl;
	MyString str("Hello");
	cout << (int*)str.data << endl;
	cout << str.data << endl << endl;

	//copy
	cout << "*******2********" << endl;
	{
		MyString copy(str); // copy constructor
		copy = str; // copy assignment constructor
		cout << (int*)copy.data << endl;
		cout << copy.data << endl << endl;
	}

	cout << "*******3********" << endl;
	if (str.data != nullptr)
	{
		cout << (int*)str.data << endl;
		cout << str.data << endl << endl;
	}
	else
	{
		cout << (int*)str.data << endl << endl;
	}

	cout << "*******4********" << endl;
	{
		MyString copy(std::move(str));
		copy = std::move(str);

		cout << (int*)copy.data << endl;
		cout << copy.data << endl << endl;
	}

	cout << "*******5********" << endl;
	if (str.data != nullptr)
	{
		cout << (int*)str.data << endl;
		cout << str.data << endl << endl;
	}
	else
	{
		cout << (int*)str.data << endl << endl;
	}

	// 알수 있는것 : 복사는 원본유지시키고 새로 공간을 만든다
	// 이동은 원본 그 자체를 이동시킨다.

	return 0;
}