/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 *
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

static const int INSERT = 1;
static const int CHANGE = 2;
static const int LOOKUP = 3;
static const int REMOVE = 4;
static const int PRINT = 5;
static const int SIZE = 6;
static const int STATS = 7;
static const int HELP = 8;
static const int QUIT = 9;


// handle the commands from the user;
// return an array of string for user commands.
string* reanCMD() {
    cout << "cmd>";
    string* cmd = new string[3];
    string command;
    getline(cin, command); // read in the whole line of user input
    for (int i = 0; i < 3; i++) {
        // find the first argument in the string, store it into an array,
        // and erase this argument from the string
        size_t startLoc = command.find_first_not_of(" ");
        size_t endLoc = command.find_first_of(" ");
        if (startLoc != endLoc) {
            cmd[i] = command.substr(startLoc, endLoc - startLoc);
            command.erase(startLoc, endLoc - startLoc);

            // find and erase the white space between two arguments
            startLoc = command.find_first_of(" ");
            endLoc = command.find_first_not_of(" ");
            if (startLoc != endLoc) {
                command.erase(startLoc, endLoc - startLoc);
            }
        }
    }
    return cmd;
}

// return corresponding integer representing the program working mode
// according to the first argument.
int progranmMode(string cmd) {
    if (cmd == "insert") { return INSERT; }
    else if(cmd == "change") { return CHANGE; }
    else if(cmd == "lookup") { return LOOKUP; }
    else if(cmd == "remove") { return REMOVE; }
    else if(cmd == "print") { return PRINT; }
    else if(cmd == "size") { return SIZE; }
    else if(cmd == "stats") { return STATS; }
    else if(cmd == "help") { return HELP; }
    else if(cmd == "quit") { return QUIT; }
    return 0;
}

// Insert this name and score in the grade table. If this name was already
// present, print a message to that effect, and don't do the insert.
void insertGrades(Table * grades, string name, int score) {
    if (!grades->insert(name, score)) {
        cout << name << " is already in the grade table." << endl;
    }
}

// Change the score for name.
// Print an appropriate message if this name isn't present.
void changeGrades(Table * grades, string name, int score) {
    if (grades->lookup(name) != NULL) {
        *grades->lookup(name) = score;
    }
    else {
        cout << name << " is not in the table." << endl;
    }
}

// Lookup the name, and print out his or her score.
// Print an appropriate message if this student is not in the table.
void lookupGrades(Table * grades, string name) {
    if (grades->lookup(name) != NULL) {
        cout << name << " " << *grades->lookup(name) << endl;
    }
    else {
        cout << name << " is not in the table." << endl;
    }
}

// Remove this student.
// If this student wasn't in the grade table, print a message to that effect.
void removeGrades(Table * grades, string name) {
    if (!grades->remove(name)) {
        cout << name << " is not in the table." << endl;
    }
}

// Prints out a brief command summary.
void cmdSummary() {
    cout << "command usage [command function]:" << endl;
    cout << "insert name score [insert this name and score in the grade table]" << endl;
    cout << "change name newscore [change the score for name]" << endl;
    cout << "lookup name [lookup the name]" << endl;
    cout << "remove name [remove this student]" << endl;
    cout << "print [prints out all names and scores in the table]" << endl;
    cout << "size [prints out the number of entries in the table]" << endl;
    cout << "stats [prints out statistics about the hash table]" << endl;
    cout << "help [prints out a brief command summary]" << endl;
    cout << "quit [exits the program]" << endl;
}

int main(int argc, char * argv[]) {

    // gets the hash table size from the command line

    int hashSize = Table::HASH_SIZE;

    Table * grades;  // Table is dynamically allocated below, so we can call
                   // different constructors depending on input from the user.

    if (argc > 1) {
        hashSize = atoi(argv[1]);  // atoi converts c-string to int

        if (hashSize < 1) {
        cout << "Command line argument (hashSize) must be a positive number"
        << endl;
        return 1;
    }

        grades = new Table(hashSize);

    }
    else {   // no command line args given -- use default table size
        grades = new Table();
    }


    grades->hashStats(cout);

    // add more code here
    // Reminder: use -> when calling Table methods, since grades is type Table*

    // repeatedly reads and executes commands from the user
    // until the user enters the quit command.
    bool done = false;
    while (!done) {
        // handle the user command
        string* p = reanCMD();
        string cmd[3];
        for (int i = 0; i < 3; i++) {
            cmd[i] = *p;
            p++;
        }

        // program works in corresponding mode according to user command
        switch (progranmMode(cmd[0])) {
            case INSERT:
                insertGrades(grades, cmd[1], atoi(cmd[2].c_str()));
                break;
            case CHANGE:
                changeGrades(grades, cmd[1], atoi(cmd[2].c_str()));
                break;
            case LOOKUP:
                lookupGrades(grades, cmd[1]);
                break;
            case REMOVE:
                removeGrades(grades, cmd[1]);
                break;
            case PRINT:
                grades->printAll();
                break;
            case SIZE:
                cout << grades->numEntries() << endl;
                break;
            case STATS:
                grades->hashStats(cout);
                break;
            case HELP:
                cmdSummary();
                break;
            case QUIT:
                done = true;
                break;
            default:
                cout << "ERROR:invalid command" << endl;
                cmdSummary();
        }
    }

    return 0;
}
