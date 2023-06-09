#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "03_Student.h"
#include "03_Teacher.h"

class Lecture
{
public:
	Lecture(const std::string& name)
		: name(name)
	{}

	void AssignmentTeacher(Teacher* teacher)
	{
		this->teacher = teacher;
	}

	void AssignmentStudent(Student* student)
	{
		students.push_back(student);
	}

	void Print()
	{
		std::cout << "teacher : " << teacher << std::endl;

		for (const auto& student : students)
			std::cout << "student : " << student << std::endl;

		std::cout << std::endl;
	}

private:
	std::string name;
	Teacher* teacher;
	std::vector<Student*> students;
};