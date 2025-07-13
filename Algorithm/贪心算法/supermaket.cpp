//硬币找零问题
#include<iostream>
#include<vector>
int coinChange(int amount)
{
    //定义硬币面额
    std::vector<int> coins={100,50,20,10,5,1};
    int coinCount=0;
    std::vector<int>used;
    for (int coin:coins)
    {
        int numCoins=amount/coin;
        for (int i=0;i<numCoins;i++)
        {
            used.push_back(coin);
        }
         amount%=coin;
         coinCount+=numCoins;
    }
    std::cout<<"找零的数量"<<coinCount<<std::endl;
    std::cout<<"找零的金额";
    for (int coin:used)
    {
        std::cout<<coin<<"元";
    }
    std::cout<<std::endl;
    return coinCount;
}
int main()
{
    int amount=63;
    coinChange(amount);
    return 0;
}