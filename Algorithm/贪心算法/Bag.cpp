#include<iostream>
#include<algorithm>
#include<vector>
struct Item
{
    int weight;
    int value;
    double unitValue;
};

bool compareItem(const Item&a,const Item&b)
{
    return a.unitValue > b.unitValue;
}

double fractionalKnapsack(int W,std::vector<Item>&items)
{
    for (auto&item:items)
    {
        item.unitValue =static_cast<double>(item.weight)/items.size();
    }
    sort(items.begin(),items.end(),compareItem);
    double totalValue = 0.0;
    for (auto&item:items)
    {
        if (W>=item.weight)
        {
            totalValue += item.value;
            W -= item.weight;
        }
        else
        {
            totalValue +=W* item.unitValue;
            break;
        }
    }
    return totalValue;
}
int main()
{
    int n=3;
    int W=50;
    std::vector<Item> items={
        {10,60,0.0},
        {20,100,0.0},
        {30,120,0.0}
    };
    double maxValue=fractionalKnapsack(W,items);
    std::cout<<maxValue<<std::endl;
    return 0;
}