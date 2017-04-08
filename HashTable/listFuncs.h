//*************************************************************************
// Node class definition
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// used by the Table class; not by any Table client code.


#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

using namespace std;

struct Node {
    string key;
    int value;

    Node *next;

    Node(const string &theKey, int theValue);

    Node(const string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.


// returns the address of the value or NULL if key is not present
int * listLookup(ListType &list, string target);

// remove an element
// false iff this element wasn't present
bool listRemove(ListType &list, string target);

// insert a new pair of key and value into the list
void listInsert(ListType &list, string target, int targetValue);

// change the value of an element in the list
// false iff this element wasn't present
bool listChange(ListType &list, string target, int targetValue);

// delete all the elements in the list
void listClear(ListType &list);

// print out all the elements in the list, one per line.
// Sample output:
//   joe 32
//   sam 273
//   bob 84
void listPrint(ListType list);

// keep the following line at the end of the file
#endif
