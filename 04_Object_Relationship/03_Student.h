#pragma once

#include <string>

class Student
{
public:
	Student() = default;

	Student(const std::string& name, int count = 0)
		:name(name), count(count)
	{}

	auto GetName() const { return name; }
	void SetName(const std::string& name) { this->name = name; }

	auto GetCount() const { return count; }
	void SetCount(const int& count) { this->count = count; }

private:
	std::string name;
	int count;
};