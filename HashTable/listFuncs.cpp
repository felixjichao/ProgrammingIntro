#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
    key = theKey;
    value = theValue;
    next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
    key = theKey;
    value = theValue;
    next = n;
}




//*************************************************************************
// put the function definitions for your list functions below

// returns the address of the value or NULL if key is not present
int * listLookup(ListType &list, string target) {
    ListType p = list;
    while (p != NULL) { // iterate the list
        if (p->key == target) { // find the key
            return &(p->value); // return the address
        }
        p = p->next;
    }
    return NULL; // key is not present
}

// remove an element
// false iff this element wasn't present
bool listRemove(ListType &list, string target){
    // empty list
    if (list == NULL) { return false; }

    // there is only one element in the list
    if (list->next == NULL) {
        if (list->key == target) {
            delete list;
            list = NULL;
            return true;
        }
        else { return false; }
    }

    // there are two or more elements in the list
    ListType p = list;

    // check the first element in the list
    if (p->key == target) {
        list = p->next;
        delete p;
        return true;
    }

    // check the rest elements in the list
    while (p->next != NULL) { // iterate the remaining list
        if (p->next->key == target) { // find the element
            ListType deleteGuy = p->next;
            p->next = p->next->next; // relink the list skipping removed one
            delete deleteGuy;
            return true;
        }
        p = p->next;
    }

    return false;
}

// insert a new pair of key and value into the list
void listInsert(ListType &list, string target, int targetValue) {
    ListType p = list;

    // empty list; create a new Node and add it to the list
    if (p == NULL) {
        list = new Node(target, targetValue);
        return;
    }

    // create a new Node and add it to the last of the list
    while (p->next != NULL) { // iterate to find the last one
        p = p->next;
    }
    p->next = new Node(target, targetValue);
}

// change the value of an element in the list
// false iff this element wasn't present
bool listChange(ListType &list, string target, int targetValue) {
    ListType p = list;
    while (p != NULL) { // iterate the list
        if (p->key == target) { // find the key
            p->value = targetValue; // change the value
            return true;
        }
        p = p->next;
    }
    return false;
}

// delete all the elements in the list
void listClear(ListType &list) {
    ListType rest = list;
    while (list != NULL) { // iterate the list
        rest = list->next;
        delete list;
        list = rest;
    }
}

// print out all the elements in the list, one per line.
// Sample output:
//   joe 32
//   sam 273
//   bob 84
void listPrint(ListType list) {
    ListType p = list;
    while (p != NULL) { // iterate the list
        cout << p->key << " " << p->value << endl;
        p = p->next;
    }
}
