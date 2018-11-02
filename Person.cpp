#include "Person.h"

Person::Person(int newPosition)
{
	this->position = newPosition;
}

Person::~Person()
{};

void Person::print()
{
	cout << this->position << endl;
}

int Person::getpostion() const
{
	return this->position;
}
