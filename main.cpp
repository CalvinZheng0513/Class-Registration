//Oluwadamilare Jobi 23520934
//Calvin Zheng 24186866

#include <iostream>
#include "Student.h"

using namespace std;

int main(){
    
    int choice;
    StuList enroll[5];
    StuList wait[5];
    string name;
    int id;
    int sect;

    cout<<"Hello Professor. Welcome to our Section Enrollment Program";

    while(1){
 
        cout<<"\n\n";
 
        cout<<"press 1 to enroll a student in a section."<<endl;
 
        cout<<"press 2 to withdraw a student from a section."<<endl;
 
        cout<<"press 3 to print the list of enrolled students and the waiting list of a section."<<endl;
 
        cout<<"press 4 to search for a student in a section."<<endl;
 
        cout<<"press 5 to exit the program."<<endl << endl;
 
        cin>>choice;
 
        switch(choice){
 
            case 1:// Add a student
                
                cout<<"please enter the desired section number(1-5), student's name, and student's id : ";
                cin >> sect;
                cin >> name;
                cin >> id;
                
                if(enroll[sect-1].ListLength()==10 && wait[sect-1].ListLength()==5){
                    cout<<"Both the enrollment and waiting listing for this section is full." << endl;
                    cout <<"Please try another section." << endl;
                }else{
                    if(enroll[sect-1].ListLength()==0){//add the first student to the enroll list
                        enroll[sect-1].addtoHead(name,id);
                    }else if(enroll[sect-1].ListLength()<10){//add the next student inorder
                        enroll[sect-1].addtoTail(name,id);  
                    }else if(enroll[sect-1].ListLength()==10 && wait[sect-1].ListLength()==0){//add the first student to the wait list
                        wait[sect-1].addtoHead(name,id);
                    }else if(wait[sect-1].ListLength()<5){//add the next student inorder
                        wait[sect-1].addtoTail(name,id);  
                    }
                }
                
    
                cout <<"Total Student enrolled in Section "<<sect<<": "<< enroll[sect-1].ListLength() << endl;
                cout <<"Total Student waiting for Section "<<sect<<": "<< wait[sect-1].ListLength() << endl;
                break;
 
            case 2:// Withdraw a student
                cout<<"please enter the desired section number(1-5) and student's id : ";
                cin >> sect;
                cin >> id;
                if(enroll[sect-1].search(id)==true){// check enroll list
                    enroll[sect-1].deleteNode(id);
                    cout << "The student's id "<< id <<" is removed from the enrollment list." << endl;
                }else if(wait[sect-1].search(id)==true){// check wait list
                    wait[sect-1].deleteNode(id);
                    cout << "The student's id "<< id <<" is removed from the waiting list." << endl;
                }else{//if both are false
                    cout << "The student is neither in the enrollment list nor waiting list." << endl;
                }
                
                
                if(enroll[sect-1].ListLength()<10 && wait[sect-1].ListLength()>0){
                    enroll[sect-1].addtoTail(wait[sect-1].getHeadName(),wait[sect-1].getHeadId());
                    wait[sect-1].deleteFromHead();
                }
 
                cout <<"Total Student enrolled in Section "<<sect<<": "<< enroll[sect-1].ListLength() << endl;
                cout <<"Total Student waiting for Section "<<sect<<": "<< wait[sect-1].ListLength() << endl;
                break;
 
            case 3://print the student in enrollment and waiting list in a section
 
                cout<<"please enter the desired section number(1-5)" << endl;
                cin >> sect;
                cout << "People enrolled in Section " << sect << ": " << endl;
                enroll[sect-1].printList();
                cout << "People waiting for Section " << sect << ": " << endl;
                wait[sect-1].printList();
                break;
 
            case 4://Search for the student by id
            
                cout<<"enter the section where you think the student is" << endl;
                cin >> sect;
                cout<<"enter the id of the student" << endl;
                cin >> id;
            
                if(enroll[sect-1].search(id)==true){// check enroll list
                    cout << "The student is in the enrollment list." << endl;
                }else if(wait[sect-1].search(id)==true){// check wait list
                    cout << "The student is in the waiting list." << endl;
                }else{//if both are false
                    cout << "The student is neither in the enrollment list nor waiting list." << endl;
                }
 
                break;

            case 5:// Exit the program
                
                cout << "Goodbye"<< endl;
 
                return 0;
 
                break;
 
                default:
 
            cout<<"this is wrong answer , try again! "<<endl;
}
        
    }

    return 0;
}
