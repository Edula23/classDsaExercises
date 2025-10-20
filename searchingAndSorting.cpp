#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertionSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int j = i - 1;
        while (j >= 0 && arr[j] > arr[i])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = arr[i];
    }
    cout << "Array sorted using insertion sort.\n";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}

void linearSearch(const vector<int> &arr, int target)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            cout << "Element found at index " << i << "\n";
            return;
        }
    }
    cout << "Element not found\n";
}
void binarySearch(vector<int> &arr, int target)
{
    insertionSort(arr);
    int found = 0, index = 0;
    int top = arr.size() - 1, bottom = 0, middle;
    do
    {
        middle = (top + bottom) / 2;
        if (target == arr[middle])
            found = 1;
        else
        {
            if (target < arr[middle])
                top = middle - 1;
            else
                bottom = middle + 1;
        }
    } while (found == 0 && top >= bottom);
    if (found == 0)
        cout << "Element not found\n";
    else if(found == 1)
        index = middle;
    cout << "Element found at index " << index << "\n";
}
void simpleSort(vector<int> &arr)
{
    for (int i = 0; i <= arr.size() - 2; i++)
        for (int j = i + 1; j <= arr.size() - 1; j++)
            if (arr[i] > arr[j])
            {
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
    cout << "Array sorted using simple sort.\n";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}
void bubbleSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
        for (int j = 0; j < arr.size() - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    cout << "Array sorted using bubble sort.\n";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}

void selectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
    cout << "Array sorted using selection sort.\n";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}

int menu(){
    cout << "Menu:\n";
    cout << "1. Search for an element\n";
    cout << "2. Sort the array\n";
    cout << "3. Exit\n";
    int choice;
    cin >> choice;
    return choice;    
}
void sortElement()
{
    cout << "Enter numbers ";
    vector<int> numArray;
    int num;
    while (cin >> num)
    {
        numArray.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    cout << "Which sorting method would you like to use?\n 1. Simple Sort\n 2. Bubble Sort\n 3. Selection Sort\n 4. Insertion Sort\n 5. Back\n";
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        simpleSort(numArray);
    }
    else if (choice == 2)
    {
        bubbleSort(numArray);
    }
    else if (choice == 3)
    {
        selectionSort(numArray);
    }
    else if (choice == 4)
    {
        insertionSort(numArray);
    }
    else if (choice == 5)
    {
        menu();
    }
}
void searchElement()
{
    cout << "Enter numbers ";
    vector<int> numArray;
    int num;
    while (cin >> num)
    {
        numArray.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    cout << "Enter number to search: ";
    int target;
    cin >> target;
    cout << "Which searching method would you like to use?\n 1. Linear Search\n 2. Binary Search\n 3.Back\n";
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        linearSearch(numArray, target);
    }
    else if (choice == 2)
    {
        binarySearch(numArray, target);
    }
    else if (choice == 3){
        menu();
    }
}

int main()
{
    int choice = menu();
    switch (choice)
    {
    case 1:
    {
        searchElement();
        break;
    }
    case 2:
    {
        sortElement();
        break;
    }
    case 3:
        cout << "Exiting...\n";
        return 0;
    default:
        cout << "Invalid choice. Please try again.\n";
    }    
    return 0;
}