#include <iostream>

#include "Graph.h"
#include "person.h"

int main()
{
    Person p1("Slava");
    Person p2("Petr");
    Person p3("Alex");
    Person p4("Nastya");
    Person p5("Egor");
    Person p6("Sveta");
    Person p7("Kiril");
    Person p8("Vlad");
    Person p9("Kostya");

    PersonGraph g;

    g.addPerson(p1);
    g.addPerson(p2);
    g.addPerson(p3);
    g.addPerson(p4);
    g.addPerson(p5);
    g.addPerson(p6);
    g.addPerson(p7);
    g.addPerson(p8);
    g.addPerson(p9);

    g.addFriendship(p1, p2);
    g.addFriendship(p2, p3);
    g.addFriendship(p3, p4);
    g.addFriendship(p4, p5);
    g.addFriendship(p5, p6);
    g.addFriendship(p5, p7);
    g.addFriendship(p6, p8);
    g.addFriendship(p8, p9);
    g.addFriendship(p9, p1);

    g.findAllHandshakes(3);
    return 0;
}
