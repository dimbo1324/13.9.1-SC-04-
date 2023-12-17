#include "person.h"

/// ����� ��������� �����.
std::string Person::getName() const
{
	return name;
}

/// ����� ��������� id.
int Person::getId() const
{
	return id;
}

bool Person::operator== (const Person& anotherPerson) const
{
	return id == anotherPerson.getId() && name == anotherPerson.getName();
}

bool Person::operator<(const Person& anotherPerson) const
{
	return id < anotherPerson.getId();
}

int Person::currentId = 0;