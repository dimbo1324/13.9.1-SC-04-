#ifndef __GRAPH__
#define __GRAPH__

#include <vector>

#include "person.h"

#define SIZE 10 

/**
 * @brief ����� ����������� ���� ���������� ������.
 * 
 */
class PersonGraph 
{
public:
    PersonGraph();
    void addPerson(Person& newPerson);
    void addFriendship(Person& person1, Person& person2);
    bool friendshipExists(Person& person1, Person& person2);
    bool personExists(Person& person);
    void findAllHandshakes(unsigned int personQuantity);
    void findHandshakes(Person& fromPerson, unsigned int personQuantity);
    
private:
    bool friendshipMatrix[SIZE][SIZE]; // ������� ��������� 
    std::vector<Person> vertexes; // ��������� ������
    int vertexCount; // ���������� ����������� ������
};

#endif

