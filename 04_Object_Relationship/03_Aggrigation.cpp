#include "03_lecture.h"

int main()
{
	using namespace std;
	
	Teacher t("Teacher");
	Student s1("Student1");
	Student s2("Student2");
	Student s3("Student3");

	cout << "t : " << &t << endl;
	cout << "s1 : " << &s1 << endl;
	cout << "s2 : " << &s2 << endl;
	cout << "s3 : " << &s3 << endl;
	cout << endl;

	{
		// ������ �Ѵ�. �׷��� lec ��ü�� �������� t, s1, s2, s3�� �����ȴ�.
		Lecture lec("C++_Language");
		lec.AssignmentTeacher(&t);
		lec.AssignmentStudent(&s1);
		lec.AssignmentStudent(&s2);
		lec.AssignmentStudent(&s3);
		lec.Print();
	}

	cout << "t : " << &t << endl;
	cout << "s1 : " << &s1 << endl;
	cout << "s2 : " << &s2 << endl;
	cout << "s3 : " << &s3 << endl;
	cout << endl;

	return 0;
}