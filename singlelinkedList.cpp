#include <iostream>
#include <iomanip>
using namespace std;
struct student
{
    int id;
    string name;
    student *next;
};
void insertBeg(student *q, student **start){
        student *temp;
        if(*start==NULL){
            *start = q;
            cout <<"Node is the beginning";
        }
        else{
            temp = *start;
            *start = q;
            q->next = temp;
        }
    }
int main(){
    struct student *start = NULL;
    struct student *p;
    p = new student;
    cout<<"Enter the name";
    cin>>p->name;
    start = p;
    struct student *k ;
    k = new student;
    k->name = "helu";
    insertBeg(k, &start);
    struct student *temp = start;
    while(temp->next!=NULL){
        cout<<temp->name;
        temp = temp->next;
    }
    
}