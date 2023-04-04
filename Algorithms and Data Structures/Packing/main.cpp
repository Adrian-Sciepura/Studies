#include <iostream>

using std::cout;
using std::cin;

struct Item
{
    int price;
    int weight;
    float profitability;

    Item(int price, int weight) :
        price{price}, weight{weight}, profitability{static_cast<float>(price) / weight}
    {

    }

    bool operator < (const Item& item)
    {
        if (this->profitability < item.profitability)
            return true;
        
        return false;
    }
};

int main()
{
    int numberOfItems = 0;
    int temp;
    cin >> numberOfItems;

    int* itemPrices = new int[numberOfItems];
    Item** items = new Item * [numberOfItems]; 

    for (int i = 0; i < numberOfItems; i++)
    {
        cin >> itemPrices[i];
    }
    for (int i = 0; i < numberOfItems; i++)
    {
        cin >> temp;
        items[i] = new Item(itemPrices[i], temp);
        
    }

    for(int i = 0; i < numberOfItems - 1; i++)
    {
        for (int j = 0; j < numberOfItems - i - 1; j++)
        {
            if (*items[j] < *items[j + 1])
            {
                Item* temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }


    int carCapacity = 0;
    int profit = 0;
    int currentWeight = 0;
    cin >> carCapacity;


    for (int i = 0; i < numberOfItems; i++)
    {
        if (currentWeight + items[i]->weight <= carCapacity)
        {
            currentWeight += items[i]->weight;
            profit += items[i]->price;
        }
    }

    cout << profit;

    delete[] itemPrices;
    for (int i = 0; i < numberOfItems; i++)
        delete items[i];

    return 0;
}