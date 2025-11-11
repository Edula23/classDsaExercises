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
        p->next = p;  
        p->previous = p;  
        cout << "Node inserted at the beginning";
        total += 1;
    }
    else
    {
        student *last = (*start)->previous;  
        
        p->next = *start;
        p->previous = last;
        
        (*start)->previous = p;
        last->next = p;
        
        *start = p;  
        cout << "Node inserted at the beginning";
        total += 1;
    }
}

void insertEnd(int &total, student *p, student **start)
{
    if (*start == NULL)
    {
        *start = p;
        p->next = p;  
        p->previous = p;  
        cout << "Node inserted at the end";
        total += 1;
    }
    else
    {
        student *last = (*start)->previous;  
        
        p->next = *start;
        p->previous = last;
        
        last->next = p;
        (*start)->previous = p;
        
        cout << "\nNode inserted successfully at the end\n";
        total += 1;
    }
}

void insertMid(int &total, int pos, student *p, student **start)
{
    if (pos > total + 1 || pos < 1){
        cout << "Invalid position";
        return;
    }
    
    if (pos == 1)
    {
        insertBeg(total, p, start);
        return;
    }
    
    if (pos == total + 1)
    {
        insertEnd(total, p, start);
        return;
    }
    
    student *temp = *start;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    
    p->next = temp->next;
    p->previous = temp;
    temp->next->previous = p;
    temp->next = p;
    
    cout << "Inserted at position " << pos << endl;
    total += 1;
}

void deleteFir(int &total, student **start)
{
    if(total < 1) {
        cout << "List is empty";
        return;
    }
    
    if (total == 1)
    {
        delete *start;
        *start = NULL;
        total -= 1;
        return;
    }
    
    student *temp = *start;
    student *last = (*start)->previous;
    
    *start = temp->next;
    (*start)->previous = last;
    last->next = *start;
    
    delete temp;
    total -= 1;
    cout << "First node deleted successfully";
}

void deleteLas(int &total, student **start)
{
    if(total == 0){
        cout << "List is empty";
        return;
    }
    
    if (total == 1)
    {
        delete *start;
        *start = NULL;
        total -= 1;
        return;
    }
    
    student *last = (*start)->previous;
    student *secondLast = last->previous;
    
    secondLast->next = *start;
    (*start)->previous = secondLast;
    
    delete last;
    total -= 1;
    cout << "Last node deleted successfully";
}

void deleteMid(int &total, int pos, student **start)
{
    if(pos > total || pos < 1){
        cout << "Invalid position";
        return;
    }
    
    if (pos == 1)
    {
        deleteFir(total, start);
        return;
    }
    
    if (pos == total)
    {
        deleteLas(total, start);
        return;
    }
    
    student *temp = *start;
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    
    temp->previous->next = temp->next;
    temp->next->previous = temp->previous;
    
    delete temp;
    total -= 1;
    cout << "Node at position " << pos << " deleted successfully";
}

void displayFor(student **start)
{
    if (*start == NULL)
    {
        cout << "List is empty";
        return;
    }
    
    struct student *temp = *start;
    cout << "Forward traversal: ";
    do
    {
        cout << temp->name << " ";
        temp = temp->next;
    } while (temp != *start);
    cout << endl;
}

void displayBac(student **start)
{
    if (*start == NULL)
    {
        cout << "List is empty";
        return;
    }
    
    student *last = (*start)->previous;
    student *temp = last;
    cout << "Backward traversal: ";
    do
    {
        cout << temp->name << " ";
        temp = temp->previous;
    } while (temp != last);
    cout << endl;
}

void search(int &total, student *q, student **start)
{
    if(total <= 0 ){
        cout << "List is empty";
        return;
    }
    
    int i = 1;
    struct student *temp = *start;
    do
    {
        if (q->name == temp->name)
        {
            cout << "Node is found at position " << i;
            return;
        }
        temp = temp->next;
        i += 1;
    } while (temp != *start);
    
    cout << "Node not found";
}

int main()
{
    student *start = NULL;
    int total = 0;
    int choice;
    
    while (true)
    {
        cout << "\n\nChoose:";
        cout << "\n1. Insert at beginning";
        cout << "\n2. Insert at the end"; 
        cout << "\n3. Insert at the middle";
        cout << "\n4. Delete first";
        cout << "\n5. Delete last";
        cout << "\n6. Delete middle";
        cout << "\n7. Display forward";
        cout << "\n8. Display backward";
        cout << "\n9. Search";
        cout << "\n10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice)
        {
        case 1:
        {
            student *a = new student;
            a->next = NULL;
            a->previous = NULL;
            cout << "Enter name: ";
            cin >> a->name;
            cout << "Enter age: ";
            cin >> a->age;
            insertBeg(total, a, &start);
            break;
        }
        case 2:
        {
            student *b = new student;
            b->next = NULL;
            b->previous = NULL;
            cout << "Enter name: ";
            cin >> b->name;
            cout << "Enter age: ";
            cin >> b->age;
            insertEnd(total, b, &start);
            break;
        }
        case 3:
        {
            student *c = new student;
            c->next = NULL;
            c->previous = NULL;
            int pos;
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter name: ";
            cin >> c->name;
            cout << "Enter age: ";
            cin >> c->age;
            insertMid(total, pos, c, &start);
            break;
        }
        case 4:
            deleteFir(total, &start);
            break;
        case 5:
            deleteLas(total, &start);
            break;
        case 6:
        {
            int pos;
            cout << "Enter position: ";
            cin >> pos;
            deleteMid(total, pos, &start);
            break;
        }
        case 7:
            displayFor(&start);
            break;
        case 8:
            displayBac(&start);
            break;
        case 9:
        {
            student *d = new student;
            d->next = NULL;
            d->previous = NULL;
            cout << "Enter name to search for: ";
            cin >> d->name;
            search(total, d, &start);
            delete d;  
            break;
        }
        case 10:
            exit(0);
        default:
            cout << "Invalid choice!";
            break;
        }
    }
    
    return 0; }