#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class AList
{
private:
    int maxSize;    // Maximum size of list
    int listSize;   // Actual elem count
    int curr;       // Position of curr
    int *listArray; // Array holding list
public:
    AList(int size = 20)
    { // Constructor
        maxSize = size;
        listSize = curr = 0;
        listArray = new int[maxSize];
    }
    void clear()
    { // Reinitialize the list
        delete[] listArray;
        listSize = curr = 0;
        listArray = new int[maxSize];
    }
    void setStart() { curr = 0; }
    void setEnd() { curr = listSize; }
    void prev()
    {
        if (curr != 0)
            curr--;
    }
    void next()
    {
        if (curr <= listSize)
            curr++;
    }
    int length() { 
        return listSize; }
    bool setPos(int pos)
    {
        if ((pos >= 0) && (pos <= listSize))
            curr = pos;
        return (pos >= 0) && (pos <= listSize);
    }
    bool getValue()
    {
        int it;
        if (listSize == 0)
            return false;
        else
        {
            it = listArray[curr];
            return true;
        }
    }
    bool insert(int item)
    {
        if (listSize == maxSize)
            return false;
        for (int i = listSize; i > curr; i--)
            // Shift Elems up to make room
            listArray[i] = listArray[i - 1];
        listArray[curr] = item;
        listSize++; // Increment list size
        return true;
    }
    bool append(int item)
    {
        if (listSize == maxSize)
            return false;
        listArray[listSize++] = item;
        return true;
    }
    bool remove()
    {
        int it;
        if (length() == 0)
            return false;
        it = listArray[curr]; // Copy element
        for (int i = curr; i < listSize - 1; i++)
            // Shift them down
            listArray[i] = listArray[i + 1];
        listSize--; // Decrement size
        return true;
    }
};
int main()
{
    // Create an AList with default size (20). To specify size use AList myList(50);
    AList myList;

    // Use public methods to interact with the object
    myList.append(10);
    myList.append(20);
    cout << "List length: " << myList.length() << '\n';

    return 0;
}
