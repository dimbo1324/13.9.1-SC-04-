#pragma once

#include <string>

/**
 * @brief Класс описывающий человека, для добавления в граф социальных связей. 
 * 
 */
class Person
{
public:
	/// Конструктор увеличивает id при создании нового экземпляра.
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



