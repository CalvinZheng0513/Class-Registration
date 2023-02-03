#include "Student.h"

StuList::StuList() {
    head = NULL;
    tail = NULL;
  }
  
bool StuList::isEmpty() {
  if (head == NULL) {
    return true;
  } else {
    return false;
  }
}
void StuList::addtoHead(string name, int id) {
    StuNode *student = new StuNode(name, id);
    student -> next = head;
    head = student;
}
void StuList::addtoTail(string name, int id) {
    StuNode * student = new StuNode(name, id);
    StuNode * curr = head;
    while (curr -> next != NULL)    {
        curr = curr -> next;
    }
    curr -> next = student;
    student -> next = NULL;
    tail = student;
 }
StuNode *StuList::deleteFromHead() {
  StuNode * curr = head;
  if (head == NULL) {
    return NULL;
  } else {
    head = curr -> next;
    return curr;
  }
}
StuNode *StuList::deleteFromTail() {
    StuNode * curr = head;
    StuNode * deleted = curr;
    if (head == NULL) {
        return NULL;
    }
    else {
        while (curr -> next != NULL) {
        deleted = curr;
        curr = curr -> next;
    }
    deleted -> next = NULL;
    return curr;
    }
}
void StuList::deleteNode(int num) {
  StuNode * curr = head;
  if (head == NULL) {
    return;
  } else if (head -> id == num) {
    head = curr -> next;
    delete curr;
  } else {
    while (curr -> next != NULL) {
      if (curr -> next -> id != num) {
        curr = curr -> next;
      } else {
        StuNode * deleted = curr -> next;
        curr -> next = curr -> next -> next;
        delete deleted;
      }
    }
  }
}
bool StuList::search(int num) {
  StuNode * curr = head;
  if (head == NULL) {
    return false;
  } else if (head -> id == num) {
    return true;
  } else {
    while (curr -> next != NULL) {
      curr = curr -> next;
      if (curr -> id == num) {
        return true;
      }
    }
  }
  return false;
}
void StuList::printList() {
  StuNode * curr = head;
  if (head != NULL) {
      cout << curr -> name << ", " << curr -> id << endl;
      while (curr -> next != NULL) {
          curr = curr -> next;
          cout << curr -> name << ", " << curr -> id << endl;
        }
  } else {
    cout << "No students are in list." << endl;
  }
}
int StuList::ListLength() {
  StuNode * curr = head;
  int numStudent = 0;
  if (head != NULL) {
    while (curr -> next != NULL) {
      curr = curr -> next;
      numStudent++;
    }
    numStudent++;
  }
  return numStudent;
}
string StuList::getHeadName(){
    StuNode* curr = head;
    return curr->name;
}

int StuList::getHeadId()
{
    StuNode* curr = head;
    return curr->id;
}
