#include <iostream>

using namespace std;

class StuNode  {
    public:
    string name;
    int id;
    StuNode * next;
    StuNode (string s, int d, StuNode * n = 0)  {
        name = s;
        id = d;
        next = n;
    }
};

class StuList   {
private:
    StuNode * head = NULL;
    StuNode * tail = NULL;
public:
    StuList ();		// constructor that makes the list empty
    bool isEmpty ();		// checks whether the list is empty
    void addtoHead (string, int);	// adds a student to the beginning of the list
    void addtoTail (string, int);	// adds a student to the end of the list
    StuNode *deleteFromHead ();	// deletes a student from the beginning of the list
    StuNode *deleteFromTail ();	// deletes a student from the end of the list
    void deleteNode (int);	// deletes a student given the id   
    bool search (int);		// searches for a student given the id
    void printList ();		// prints all the information of students in the list
    int ListLength ();		// returns number of students in the list
    string getHeadName();        //print name of the student in the beginning of the list
    int getHeadId();          //print id of the student in the beginning of the list
};

