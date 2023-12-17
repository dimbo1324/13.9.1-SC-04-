#include <iostream>
#include <map>
#include <limits>

#include "Graph.h"

using namespace std;

#define VERYBIGINT std::numeric_limits<int>::max() // очень большое число

PersonGraph::PersonGraph() 
{
    for (int i = 0; i < SIZE; i++)  
        for (int j = 0; j < SIZE; j++) 
            friendshipMatrix[i][j] = 0;
    vertexCount = 0;
}

/// Метод добавления человека в граф социальных отношений.  
void PersonGraph::addPerson(Person& newPerson)
{
    vertexes.push_back(newPerson);
    vertexCount++;
}

/// Метод добавления отношения "дружба" между людьми.
void PersonGraph::addFriendship(Person& person1, Person& person2)
{
    friendshipMatrix[person1.getId()][person2.getId()] = true;
    friendshipMatrix[person2.getId()][person1.getId()] = true;
}

/// Метод проверки существования отношения "дружба".
bool PersonGraph::friendshipExists(Person& person1, Person& person2)
{
    return friendshipMatrix[person1.getId()][person2.getId()];
}

/// Метод проверки существования человека в графе социальных отношений.
bool PersonGraph::personExists(Person& person)
{
    for (int i = 0; i < vertexCount; i++)
        if (vertexes[i] == person)
            return true;
    return false;
}

/// Метод отобажающий все социальные связи через personQuantity, для каждого человека добавленного в граф.
void PersonGraph::findAllHandshakes(unsigned int personQuantity)
{
    for (int i = 0; i < vertexCount; i++)
    {
        std::cout << "All friends through three handshakes of user " << vertexes[i].getName() << ":" << std::endl;
        findHandshakes(vertexes[i], personQuantity);
    }
}

/// Метод отобажающий все социальные связи через personQuantity, для конкретного человека добавленного в граф.
void PersonGraph::findHandshakes(Person& fromPerson, unsigned int personQuantity)
{
    map<Person, int> distances;
    for (int i = 0; i < vertexCount; ++i) // инициализация меток
    {
        distances[vertexes[i]] = VERYBIGINT;
    }
    distances[fromPerson] = 0;
    
    bool* passed = new bool[vertexCount]; 
    for (int i = 0; i < vertexCount; ++i) 
    {
        passed[i] = false; // все неокрашены изначально
    }
    // принимаем стартовую вершину за текущую
    int currentVertexNum = fromPerson.getId();
    int min_dist = 0;
    while (min_dist != VERYBIGINT)
    {
        passed[currentVertexNum] = true; // окрашиваем текущую
        for (int i = 0; i < vertexCount; ++i)
        {
            if (friendshipExists(vertexes[currentVertexNum], vertexes[i])
                && distances[vertexes[currentVertexNum]] + friendshipMatrix[currentVertexNum][i] < distances[vertexes[i]])
            {
                distances[vertexes[i]] = distances[vertexes[currentVertexNum]] + friendshipMatrix[currentVertexNum][i];
            }
        }
    
        min_dist = VERYBIGINT;
        for (int i = 0; i < vertexCount; ++i)
        {
            // выбираем новую текущую вершину
            if (personExists(vertexes[i]) && !passed[i] && distances[vertexes[i]] < min_dist) // выбор новой вершины
            {
                min_dist = distances[vertexes[i]];
                currentVertexNum = i;
            }
        }
    }

    for (int i = 0; i < vertexCount; ++i) // вывод результата
    {
        if (distances[vertexes[i]] > 0 && distances[vertexes[i]] <= personQuantity)
        {
            std::cout << vertexes[i].getName() << " - " << distances[vertexes[i]] << std::endl;
        }
    }

    delete[] passed;
}