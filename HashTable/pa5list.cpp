// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile (and lab 13 Makefile) includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"


void testInsert(ListType &list) {
    cout << "Test Insert:" << endl;
    listInsert(list, "Anna", 90);
    listInsert(list, "Bob", 92);
    listInsert(list, "Carol", 94);
    listPrint(list);
    cout << "[Expected:](key, value): (Anna, 90)(Bob, 92)(Carol, 94)" << endl;
    cout << endl;
}

void testLookup(ListType &list) {
    cout << "Test Lookup:" << endl;

    cout << "lookup Anna: ";
    if (listLookup(list, "Anna")) { cout << "true" << endl; }
    else { cout << "false" << endl; }
    cout << "[Expected:]true" << endl;

    cout << "lookup Carol: ";
    if (listLookup(list, "Carol")) { cout << "true" << endl; }
    else { cout << "false" << endl; }
    cout << "[Expected:]true" << endl;

    cout << "lookup An: ";
    if (listLookup(list, "An")) { cout << "true" << endl; }
    else { cout << "false" << endl; }
    cout << "[Expected:]false" << endl;

    cout << endl;
}

void testRemove(ListType &list) {
    cout << "Test Remove:" << endl;

    listRemove(list, "Anna");
    listPrint(list);
    cout << "[Expected:](key, value): (Bob, 92)(Carol, 94)" << endl;

    listRemove(list, "An");
    listPrint(list);
    cout << "[Expected:](key, value): (Bob, 92)(Carol, 94)" << endl;

    cout << endl;
}

void testChange(ListType &list) {
    cout << "Test Change:" << endl;

    cout << "Change Bob'value to 96:" << endl;
    listChange(list, "Bob", 96);
    listPrint(list);
    cout << "[Expected:](key, value): (Bob, 96)(Carol, 94)" << endl;

    cout << "Change Bo'value to 96:" << endl;
    listChange(list, "Bo", 96);
    listPrint(list);
    cout << "[Expected:](key, value): (Bob, 96)(Carol, 94)" << endl;

    cout << endl;
}

void testClear(ListType &list) {
    cout << "Test Clear:" << endl;

    listClear(list);
    listPrint(list);
    cout << "[Expected:](key, value): " << endl;

    cout << endl;
}

int main() {
    ListType test = NULL;

    testInsert(test);

    testLookup(test);

    testRemove(test);

    testChange(test);

    testClear(test);

    return 0;
}
