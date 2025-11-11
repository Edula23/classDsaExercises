#include <iostream>
#include <string>
using namespace std;
struct student
{
    string name;
    int age;
    student *next;
    student *previous;
};
void insertBeg(int &total, student *p, student **start)
{
    if (*start == NULL)
    {
        *start = p;
        cout << "Node inserted at the beginning";
        total += 1;
    }
    else
    {
        student *temp = *start;
        *start = p;
        temp->previous = p;
        p->next = temp;
        cout << "Node inserted at the beginning";
        total += 1;
    }
}
void insertEnd(int &total, student *p, student **start)
{
    if (*start == NULL)
    {
        *start = p;
        cout << "Node inserted at the end";
        total += 1;
    }
    else
    {
        student *temp = *start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
        p->previous = temp;
        cout << "\n Node inserted successfully at the end\n";
        total += 1;
    }
}
void insertMid(int &total, int pos, student *p, student **start)
{
    if (pos > total || pos < 0){
        cout << "Out of reach node";
        return;
    }
    student *temp = *start;

    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    p->next = temp->next;
    temp->next->previous = p;
    temp->next = p;
    p->previous = temp;
    cout << "Inserted"<<endl;
    total += 1;
}
void deleteFir(int &total , student **start)
{
    if(total < 1) {
        cout << "Out of reach";
        return;
    }
    student *temp = *start;
    *start = temp->next;
    temp = temp->next;
    temp->previous = NULL; 
    total -= 1;
}
void deleteLas(int &total , student **start)
{
    if(total==0){
        cout<<"Out of reach";
        return;
    }
    struct student *temp = *start;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
void deleteMid(int &total, int pos, student **start)
{
    if(pos > total || total < 0){
        cout<<"Out of reach";
        return;
    }
    student *temp = *start;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    student *temp2 = temp->next;
    temp->next = temp2->next;
    temp2->next->previous = temp;
    delete temp;
    cout << "Deleted Successfully";
}
void displayFor(student **start)
{
    struct student *temp = *start;
    while (temp != NULL)
    {
        cout << temp->name;
        temp = temp->next;
    }
}
void displayBac(student **start)
{
    student *temp = *start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp->previous != NULL)
    {
        cout << temp->name;
        temp = temp->previous;
    }
}
void search(int &total , student *q, student **start)
{
    if(total <=0 ){
        cout<<"Out of reach";
        return;
    }
    int i = 1;
    struct student *temp = *start;
    while (temp != NULL)
    {
        if (q->name == temp->name)
        {
            cout << "Node is found at position " << i;
            break;
        }
        temp = temp->next;
        i += 1;
    }
}
int main()
{
    student *start = NULL;
    int total =0;
    int choice;
    while (true)
    {
        cout << "Choose \n1.Insert at beginning \n2.Insert at the end \n3.Insert at the middle \n4.Delete first \n5.Delete last \n6.Delete middle \n7.Display forward \n8.Display backward \n9.Search \n10.Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter new name ";
            struct student *a;
            a = new student;
            a->next = NULL;
            a->previous = NULL;
            cin >> a->name;
            insertBeg(total, a, &start);
            break;
        case 2:
            struct student *b;
            b = new student;
            cout << "Enter name: ";
            cin >> b->name;
            b->next = NULL;
            b->previous = NULL;
            insertEnd(total, b, &start);
            break;
        case 3:
            struct student *c;
            c = new student;
            int pos;
            cout << "Insert position ";
            cin >> pos;
            cout << "Enter name ";
            cin >> c->name;
            c->next = NULL;
            c->previous = NULL;
            insertMid(total, pos, c, &start);
            break;
        case 4:
            deleteFir(total, &start);
            break;
        case 5:
            deleteLas(total, &start);
            break;
        case 6:
            cout << "Insert position ";
            cin >> pos;
            deleteMid(total, pos, &start);
            break;
        case 7:
            displayFor(&start);
            break;
        case 8:
            displayBac(&start);
            break;
        case 9:
            cout << "Enter name to search for";
            struct student *d;
            d = new student;
            cin >> d->name;
            d->next = NULL;
            d->previous = NULL;
            search(total, d, &start);
            break;
        case 10:
            exit(0);

        default:
            break;
        }
        struct student *temp = start;
        while (temp != NULL)
        {
            cout << temp->name  << endl;
            temp = temp->next;
        }
    }

    return 0;
}
