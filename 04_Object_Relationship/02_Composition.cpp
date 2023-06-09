#include <iostream>

using namespace std;

// part-of

class Point2D
{
public:
	int x;
	int y;
};

class Monster
{
public:
	Monster(int x, int y)
	{
		position.x = x;
		position.y = y;
	}

private:
	string name;
	Point2D position;
};

int main()
{
	{
		Monster mon1(10, 20);
	}

	return 0;
}