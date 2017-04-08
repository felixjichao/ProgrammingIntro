// Table.cpp  Table class implementation

#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>



// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************

// create an empty table, i.e., one where numEntries() is 0
// (Underlying hash table is HASH_SIZE.)
Table::Table() {
    hashSize = HASH_SIZE;

    // create an array of HASH_SIZE pointers to ListType
    // make all the pointers point to NULL
    data = new ListType[HASH_SIZE];
    for (unsigned int i = 0; i < HASH_SIZE; i++) {
        data[i] = NULL;
    }

    // create an array of HASH_SIZE integers for chain length
    // make all initial values zero
    chainLength = new int[HASH_SIZE];
    for (unsigned int i = 0; i < HASH_SIZE; i++) {
        chainLength[i] = 0;
    }

    entryNum = 0;
    nonEmptyBucketNum = 0;
}

// create an empty table, i.e., one where numEntries() is 0
// such that the underlying hash table is hSize
Table::Table(unsigned int hSize) {
    hashSize = hSize;

    // create an array of hSize pointers to ListType
    // make all the pointers point to NULL
    data = new ListType[hSize];
    for (unsigned int i = 0; i < hSize; i++) {
        data[i] = NULL;
    }

    // create an array of hSize integers for chain length
    // make all initial values zero
    chainLength = new int[hSize];
    for (unsigned int i = 0; i < hSize; i++) {
        chainLength[i] = 0;
    }

    entryNum = 0;
    nonEmptyBucketNum = 0;
}

// insert a new pair into the table
// return false iff this key was already present
//         (and no change made to table)
bool Table::insert(const string &key, int value) {
    // the No. of bucket that the key belongs to according to hash code
    unsigned int bucketNo = hashCode(key);
    if (lookup(key) == NULL) { // the key is not in the table
        listInsert(data[bucketNo], key, value); // insert the key to the table

        // update corresponding statistics
        entryNum++;
        chainLength[bucketNo]++;
        // the element is inserted into an empty bucket
        if (chainLength[bucketNo] == 1) {
            nonEmptyBucketNum++;
        }
        return true;
    }
    return false;
}

// returns the address of the value or NULL if key is not present
int * Table::lookup(const string &key) {
    unsigned int bucketNo = hashCode(key);
    if (listLookup(data[bucketNo], key) != NULL) { // find the key
        return listLookup(data[bucketNo], key); // return the address of the value
    }
    return NULL;
}

// remove an element
// false iff element wasn't present
bool Table::remove(const string &key) {
    unsigned int bucketNo = hashCode(key);

    // the key to be removed is in the table, and remove it
    if (lookup(key) != NULL && listRemove(data[bucketNo], key)) {
        // update corresponding statistics
        entryNum--;
        chainLength[bucketNo]--;
        // the removed element is the only one in the bucket,
        // and this bucket gets empty
        if (data[bucketNo] == NULL) {
            nonEmptyBucketNum--;
        }
        return true;
    }
    return false;
}

// print out all the entries in the table, one per line.
// Sample output:
//   joe 32
//   sam 273
//   bob 84
void Table::printAll() const {
    for (unsigned int i = 0; i < hashSize; i++) {
        if (data[i] != NULL) {
            listPrint(data[i]);
        }
    }
}

// return number of entries in the table
int Table::numEntries() const {
    return entryNum;
}

// hashStats: for diagnostic purposes only
// prints out info to let us know if we're getting a good distribution
// of values in the hash table.
// Sample output from this function
//   number of buckets: 997
//   number of entries: 10
//   number of non-empty buckets: 9
//   longest chain: 2
void Table::hashStats(ostream &out) const {
    out << "number of buckets: " << hashSize << endl;
    out << "number of entries: " << entryNum << endl;
    out << "number of non-empty buckets: " << nonEmptyBucketNum << endl;
    out << "longest chain: " << longestChain(chainLength) << endl;
}

// add definitions for your private methods here

// calculate and return the length of the longest chain in the table
int Table::longestChain(int* target) const {
    int maxLength = target[0];

    for (unsigned int i = 0; i < hashSize; i++) {
        if (target[i] > maxLength) {
            maxLength = target[i];
        }
    }
    return maxLength;
}
