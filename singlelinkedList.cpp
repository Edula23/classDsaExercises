#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct student
{
    int id;
    string name;
    student *next;
};
void insertBeg(student *q, student **start){
        struct student *temp = *start;
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
void insertEnd(student *q, student **start){
    struct student *temp = *start;
    if(*start==NULL){
        *start = q;
        cout <<"Node is at the beginning and at the end.";
    }
    else{
        while (temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = q;
        
    }
}
void insertMid(int c, student *q, student **start ){
    if(*start==NULL){
        *start = q;
        cout <<"Node is at the beginning and at the end.";
    }
    else{
        struct student *temp = *start;
        for(int i=1; i<c-1; i++){
            temp = temp->next;
        }
        q->next = temp->next;
        temp->next = q;
    }
}
void deleteFirst(student **start){
    struct student *temp = *start;
    *start = temp->next;
}
void deleteLast(student **start){
    struct student *temp = *start;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    
}
void deleteMid(int c, student **start){
    struct student *temp = *start;
    struct student *temp2 = temp->next;
    for(int i=1; i<c-1; i++){
        temp = temp->next;
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    delete temp2;
}
void displayFor(student **start){
    struct student *temp = *start;
    while (temp=NULL)
    {
       cout<<temp->name;
       temp = temp ->next;
    }
    
}
void displayBackward(student **start) {
    if (start == NULL) {
        return;
    }    
    student *end = NULL;
    while (end != *start) {
        student *temp = *start;
        while (temp->next != end)
            temp = temp->next;
            if (temp == *start){
                break;
            }
        cout << temp->name << " ";
        end = temp; 
        
    }
}
void search(student *q, student **start){
    int i= 1;
    struct student *temp = *start;
    while (temp!=NULL)
    {
        if(q->name == temp->name){
            cout<<"Node is found at position "<<i;
            break;
        }
        temp = temp->next;
        i+=1;
    }
    
}
int main(){
    struct student *k;
    k = new student;
    k->name = "hello ";
    k->next = NULL;
    student *m = new student;
    m->name = " Abebe ";
    k->next = m;
    m->next = NULL;    
    student *n = new student;
    n->name = " Kebede ";
    m->next = n; 
    n->next = NULL;   
    struct student *start = NULL;
    start = k;
    int choice;
    do
    {
    cout<<"Choose \n1.Insert at beginning \n2.Insert at the end \n3.Insert at the middle \n4.Delete first \n5.Delete last \n6.Delete middle \n7.Display forward \n8.Display backward \n9.Search \n10.Exit"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"Enter new name ";        
        struct student *a;
        a = new student;
        cin>>a->name;
        insertBeg(a, &start);
        break;
    case 2:
        struct student *b;
        b = new student;
        cout<<"Enter name: ";
        cin>>b->name;
        insertEnd(b, &start);
        break;
    case 3:
        struct student *c;
        c = new student;
        int pos;
        cout<<"Insert position ";
        cin>>pos;
        cout<<"Enter name ";
        cin>>c->name;
        insertMid(pos, c, &start);
        break;
    case 4:
        deleteFirst(&start);
        break;
    case 5:
        deleteLast(&start);
        break;
    case 6:
        cout<<"Insert position ";
        cin>>pos;
        deleteMid(pos, &start);
        break;
    case 7:
        displayFor(&start);
        break;
    case 8:
        displayBackward(&start);
        break;
    case 9:
        cout<<"Enter name to search for";        
        student *d;
        cin>>d->name;
        search(d, &start);
        break;
    case 10:
        exit;      
    
    default:
        break;
    }
struct student *temp = start;
    while (temp!=NULL)
    {
        cout<<temp->name;
        temp = temp->next;
    } 
    } while (choice != 10);    
    
    return 0;
    
}