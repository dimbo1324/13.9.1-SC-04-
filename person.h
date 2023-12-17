#pragma once

#include <string>

/**
 * @brief ����� ����������� ��������, ��� ���������� � ���� ���������� ������. 
 * 
 */
class Person
{
public:
	/// ����������� ����������� id ��� �������� ������ ����������.
	Person(std::string aName) : name(aName)
	{
		id = currentId++;
	}
	bool operator==(const Person& anotherPerson) const;
	bool operator<(const Person& anotherPerson) const;
	std::string getName() const;
	int getId() const;
	
private:
	std::string name;
	static int currentId;
	int id;
};



