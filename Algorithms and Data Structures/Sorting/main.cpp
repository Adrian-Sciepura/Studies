#include <iostream>
#include <string>

using std::cout, std::cin, std::string;

bool compare(const string& first, const string& second)
{
    if(first.length() > second.length())
    {
        return true;
    }
    else if(first.length() == second.length())
    {
        for(int i = 0; i < first.length(); i++)
        {
            if(first[i] > second[i])
            {
                return true;
            }
            else if(first[i] < second[i])
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

void merge(string*& left, int leftSize, string*& right, int rightSize)
{
    string* temp = new string[leftSize + rightSize];
    int tempCounter = 0;
    int leftCounter = 0;
    int rightCounter = 0;

    while(leftCounter < leftSize && rightCounter < rightSize)
    {
        if(compare(left[leftCounter], right[rightCounter]))
        {
            temp[tempCounter] = right[rightCounter];
            rightCounter++;
        }
        else
        {
            temp[tempCounter] = left[leftCounter];
            leftCounter++;
        }
        tempCounter++;
    }
    

    while(leftCounter < leftSize)
    {
        temp[tempCounter] = left[leftCounter];
        leftCounter++;
        tempCounter++;
    }


    while(rightCounter < rightSize)
    {
        temp[tempCounter] = right[rightCounter];
        rightCounter++;
        tempCounter++;
    }


    for(int i = 0; i < (leftSize + rightSize); i++)
        left[i] = temp[i];


    delete[] temp;
}

void mergeSort(string*& array, int size)
{
    if(size <= 1)
        return;

    int middle = size / 2;
    string* left = &array[0];
    string* right = &array[middle];
    int leftSize = middle;
    int rightSize = size - leftSize;

    mergeSort(left, leftSize);
    mergeSort(right, rightSize);
    merge(left, leftSize, right, rightSize);
}

int main()
{
    int quantity = 0;
    cin >> quantity;
    
    string* numbers = new string[quantity];

    for(int i = 0; i < quantity; i++)
        cin >> numbers[i];

    cout << '\n';
    mergeSort(numbers, quantity);

    for(int i = 0; i < quantity; i++)
        cout << numbers[i] << '\n';

    return 0;
}