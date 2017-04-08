/* 
 *  See ecListFuncs.h for specification of each function.
 */

#include <iostream>

#include <cassert>


#include "ecListFuncs.h"

using namespace std;
//*************************************************************************
bool allUnique(ListType list) {
    if (list == NULL || list->next == NULL) {
        return true;
    }
    ListType p1 = list;
    ListType p2 = list->next;
    while (p1->next != NULL) {
        while (p2 != NULL) {
            if (p1->data == p2->data) {
                return false;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
        p2 = p1->next;
    }
    return true;
}

void splice(ListType &list, int value, ListType subList) {
    if (list == NULL) {
        list = subList;
        return;
    }
    if (subList == NULL) {
        return;
    }
    ListType pl = list;
    ListType ps = subList;
    for (int i = value; i > 1; i--) {
        pl = pl->next;
    }
    while (ps->next != NULL) {
        ps = ps->next;
    }
    if (value == 0) {
        ps->next = list;
        list = subList;
        return;
    }
    ps->next = pl->next;
    pl->next = subList;

}

ListType fibSeq(int n) {
    ListType result = new Node(1);
    if (n == 1) {
        return result;
    }
    result->next = new Node(1);
    ListType first = result;
    ListType second = result->next;
    for (int i = n; i > 2; i--) {
        int newValue = first->data + second->data;
        second->next = new Node(newValue);
        first = first->next;
        second = second->next;
    }
    return result;
}

void removeEveryOther(ListType &list) {
    if (list == NULL || list->next == NULL) {
        list == NULL;
    }
    ListType rest = list->next;
    delete list;
    list = rest;
    ListType p = list;
    while (p != NULL && p->next != NULL) {
            ListType deadGuy = p->next;
            p->next = p->next->next;
            delete deadGuy;
            p = p->next;
    }
}

void remove7s(ListType &list) {
    while (list != NULL && list->data == 7) {
        ListType rest = list->next;
        delete list;
        list = rest;
    }
    ListType p = list;
    while (p != NULL && p->next != NULL) {
        if (p->next->data == 7) {
            ListType deadGuy = p->next;
            p->next = p->next->next;
            delete deadGuy;
        }
        else {
            p = p->next;
        }
    }
}

void removeKAtLoc(ListType list, int loc, int k) {
    int length = 0;
    ListType p = list;
    while (p != NULL) {
        length++;
        p = p->next;
    }
    if (loc >= length) {
        return;
    }

    ListType firstTail = list;
    for (int i = loc - 1; i > 0; i--) {
        firstTail = firstTail->next;
    }
    if (k + loc >= length) {
        firstTail->next = NULL;
        return;
    }

    ListType secondHead = firstTail->next;
    for (int i = k; i > 0; i--) {
        ListType deadGuy = secondHead;
        secondHead = secondHead->next;
        delete deadGuy;
    }
    firstTail->next = secondHead;

}

ListType interList(ListType list1, ListType list2) {
    ListType p1 = list1;
    ListType p2 = list2;
    ListType intersection = NULL;
    ListType pi = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->data == p2->data) {
            if (intersection == NULL) {
                intersection = new Node(p1->data);
                pi = intersection;
            }
            else {
                pi->next = new Node(p1->data);
                pi = pi->next;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->data < p2->data) {
            p1 = p1->next;
        }
        else {
            p2 = p2->next;
        }
    }
    return intersection;
}

bool contained(ListType list1, ListType list2) {
    if (list1 == NULL && list2 == NULL) {
        return true;
    }
    ListType p1 = list1;
    ListType p2 = list2;
    while (p1 != NULL && p2 != NULL) {
        if (p1->data != p2->data) {
            p1 = p1->next;
        }
        else {
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    if (p2 == NULL) { return true; }
    return false;
}

ListType mergeList2(ListType &list1, ListType &list2) {
    if (list1 == NULL) { return list2; }
    if (list2 == NULL) { return list1; }

    if (list1->data < list2->data) {
        list1->next = mergeList2(list1->next, list2);
        return list1;
    }
    else {
        list2->next = mergeList2(list1, list2->next);
        return list2;
    }
}

ListType mergeList(ListType &list1, ListType &list2) {
    ListType mergeOne = NULL;
    if (list1->data < list2->data) {
        mergeOne = list1;
        list1 = list1->next;
        mergeOne->next = NULL;
    }
    else {
        mergeOne = list2;
        list2 = list2->next;
        mergeOne->next = NULL;
    }
    ListType p = mergeOne;
    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            p->next = list1;
            list1 = list1->next;
        }
        else {
            p->next = list2;

            list2 = list2->next;

        }
        p = p->next;
        p->next = NULL;
    }
    if (list1 != NULL){
        p->next = list1;
        list1 = NULL;
    }
    else {
        p->next = list2;
        list2 = NULL;
    }
    return mergeOne;
}

ListType copyEveryOther(ListType list) {
    if (list == NULL) {
        return NULL;
    }

    if (list->next == NULL || list->next->next == NULL) {
        return new Node(list->data);
    }
    ListType copyOne = NULL;
    copyOne = new Node(list->data);
    ListType cp = copyOne;
    ListType p = list->next->next;
    while (p != NULL && p->next != NULL) {
        cp->next = new Node(p->data);
        cp = cp->next;
        p = p->next->next;
    }
    if (p != NULL && p->next == NULL) {
        cp->next = new Node(p->data);
    }
    return copyOne;
}

ListType copyList(ListType list) {
    ListType copy = new Node(list->data);
    ListType cp = copy;
    ListType p = list->next;
    while (p != NULL) {
        cp->next = new Node(p->data);
        cp = cp->next;
        p = p->next;
    }
    return copy;
}

void buildList(ListType &list) {
    int value = 0;
    while (cin >> value) {
        list = new Node(value, list);
    }
}

void rotateRightOne(ListType &list) {
    ListType p = list;
    while (p->next->next != NULL) {
        p = p->next;
    }
    p->next->next = list;
    list = p->next;
    p->next = NULL;
}

void rotateLeftOne(ListType &list) {
    ListType first = list;

    list = list->next;
    ListType p = list;
    while(p->next != NULL) {
        p = p->next;
    }
    p->next = first;
    first->next = NULL;
}

void dupList2(ListType &list) {
    ListType p = list;
    while (p != NULL) {
        ListType dup = new Node(p->data, p->next);
        p->next = dup;
        p = p->next->next;
    }
}

ListType dupList(ListType list) {
    ListType newList = new Node(list->data);
    newList->next = new Node(list->data);
    ListType np = newList->next;
    ListType p = list->next;
    while (p != NULL) {
        //int current = p->data;
        np->next = new Node(p->data);
        np = np->next;
        np->next = new Node(p->data);
        np = np->next;
        p = p->next;
    }
    return newList;
}

void reverseList2(ListType &list) {
    ListType before = NULL;
    ListType after = NULL;
    ListType current = list;
    while (current != NULL) {
        after = current->next;
        current->next = before;
        before = current;
        current = after;
    }
    list = before;
}

ListType reverseList(ListType list) {
    ListType revList = NULL;
    ListType p = list;
    while (p != NULL) {
        revList = new Node(p->data, revList);
        p = p->next;
    }
    return revList;
}

void removeOfValue(ListType &list, int value) {
    while (list != NULL && list->data < value) {
        ListType rest = list->next;
        delete list;
        list = rest;
    }
    ListType p = list;
    while (p != NULL && p->next != NULL) {
        if (p->next->data < value) {
            ListType deadGuy = p->next;
            p->next = p->next->next;
            delete deadGuy;
        }
        p = p->next;
    }

}

ListType newListOfValue(ListType list, int value) {
    ListType newList = NULL;
    ListType p = list;
    while (p != NULL) {
        if (p->data > value) {
            newList = new Node(p->data, newList);
        }
        p = p->next;
    }
    return newList;
}

int numOfValue(ListType list, int value) {
    ListType p = list;
    int num = 0;
    while(p != NULL) {
        if (p->data == value) {
            num++;
        }
        p = p->next;
    }
    return num;
}

void insertMid(ListType &list, int value) {
    ListType p1 = list;
    ListType p2 = list;
    p2 = p2->next->next;
    while (p2 != NULL && p2->next != NULL) {
        p2 = p2->next->next;
        p1 = p1->next;
    }
    p1->next = new Node(value, p1->next);
}

void removeMid(ListType &list) {
    ListType p1 = list;
    ListType p2 = list;
    p2 = p2->next->next;
    while (p2 != NULL && p2->next != NULL) {
        p2 = p2->next->next;
        p1 = p1->next;
    }
    ListType deadGuy = p1->next;
    p1->next = p1->next->next;
    delete deadGuy;
}

int middleValue(ListType list) {
    ListType p1 = list;
    ListType p2 = list;

    while (p2 != NULL && p2->next != NULL) {
        p2 = p2->next->next;
        p1 = p1->next;

    }
    return p1->data;

    /*ListType p = list;
    int elemNum = 0;
    while (p != NULL) {
        elemNum++;
        p = p->next;
    }
    int middle = 0;
    if (elemNum % 2 == 0) {
        middle = elemNum / 2;
    }
    else {
        middle = elemNum / 2 + 1;
    }
    p = list;
    for (int i = 1; i < middle; i++) {
        p = p->next;
    }
    return p->data;*/
}


//*************************************************************************
void insertFront(ListType &list, int val) {
  list = new Node(val, list);
}


void printList(ListType list) {

  if (list == NULL) {
    cout << "<empty>";
  }

  Node *p = list;
  while (p != NULL) {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}


void clearList(ListType &list) {

  Node *rest = list;

  while (list != NULL) {
    rest = list->next;  // rest is all but the first element
    delete list;  // reclaims one node only
    list = rest;
  }

}

Node::Node(int item) {
  data = item;
  next = NULL;
}

Node::Node(int item, Node *n) {
  data = item;
  next = n;
}
// returns true iff the elements in the list are in increasing order
// (duplicate elements allowed)
bool isInOrder(ListType list) {
    // list is empty, or there is one element
    if (list == NULL || list->next == NULL) {
        return true;
    }

    // list contains more than one element
    ListType p = list;
    while (p->next != NULL) {
        // find an element that is not in increasing order
        if (p->data > p->next->data) {
            return false;
        }
        p = p->next;
    }
    return true;
}

// inserts the new node into the ordered list.
void insertInOrder(ListType & list, Node *itemP) {
    assert(isInOrder(list));     // checks the preconditions
    assert(itemP->next == NULL);
    // add the rest of the code after this line
    // for an empty list, just insert itemP into list
    if (list == NULL) {
        list = itemP;
        return;
    }

    // list is not empty
    ListType p = list;
    while (p != NULL) {
        // data in itemP is smaller than the first element in list
        if (list->data >= itemP->data) {
            itemP->next = list;
            list = itemP;
            return;
        }

        // data in itemP is larger than the last element in list
        if (p->next == NULL && p->data <= itemP->data) {
            p->next = itemP;
            return;
        }

        // data in itemP is somewhere in the middle of list
        if (p->data <= itemP->data && p->next->data >= itemP->data) {
            itemP->next = p->next;
            p->next = itemP;
            return;
        }
        p = p->next;
    }
}

// sorts the list in increasing order using the insertion sort algorithm
void insertionSort(ListType &list) {
    // list is empty, or there is one element
    if (list == NULL || list->next == NULL) {
        return;
    }

    // list contains more than one element
    ListType p = list; // pointer to the last element of sorted part
    ListType temp = p->next; // pointer to the element to be selected
    while (p->next != NULL) { // iterate the whole list
        // find an element that is not in increasing order
        if (p->data > temp->data) {
            p->next = temp->next; // remove the element to be sorted

            // insert the selected element into the sorted part
            ListType sortPart = list;
            bool sortDone = false;
            while (!sortDone) {
                // the selected element is smaller than the first one
                // in the sorted part
                if (temp->data <= sortPart->data) {
                    temp->next = sortPart;
                    list = temp;
                    sortDone = true;
                }

                // the selected element is somewhere between the first
                // and the one that p points to
                if (temp->data > sortPart->data &&
                    temp->data <= sortPart->next->data) {
                        temp->next = sortPart->next;
                        sortPart->next = temp;
                        sortDone = true;
                    }
                sortPart = sortPart->next;
            }
            temp = p->next; // update the selected element
        }
        else { // current element is in increasing order
            p = p->next;
            temp = p->next;
        }
    }
}

// splits list into two sub-lists. "a" will contain the first, third,
// fifth, etc.  element from list.  And "b" will contain the second,
// fourth, sixth, etc. element from list.
void splitEvenOdd(ListType &list, ListType &a, ListType &b){
    // list is empty
    if (list == NULL) {
        return;
    }

    // list contains at least one element
    // insert the first element in a
    a = list;
    list = list->next;
    a->next = NULL;

    // insert the first element in b if existing
    if (list != NULL) {
        b = list;
        list = list->next;
        b->next = NULL;
    }

    ListType pa = a; // pointer to iterate list a
    ListType pb = b; // pointer to iterate list b
    // insert the first element in the remaining list into list a and b alternatively
    while (list != NULL) {
        // insert the element into the end of list a
        while (pa->next != NULL) {
            pa = pa->next;
        }
        pa->next = list;
        list = list->next;
        pa->next->next = NULL;

        // insert the element into the end of list b if existing
        if (list != NULL) {
            while (pb->next != NULL) {
                pb = pb->next;
            }
            pb->next = list;
            list = list->next;
            pb->next->next = NULL;
        }
    }

}
