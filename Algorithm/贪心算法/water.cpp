#include <algorithm>
#include<iostream>
int main()
{
    int amount[510]={0};
    int n,r,s=0;
    std::cout<<"输入人数: "<<std::endl;
    std::cin>>n;
    std::cout<<"水龙头数"<<std::endl;
    std::cin>>r;
    std::cout<<"每个人的打水时间: "<<std::endl;
    for(int i=1;i<=n;i++)
    {
        std::cin>>amount[i];
    }
    std::sort(amount+1,amount+n+1);
    for(int i=1;i<=n;i++)
    {
        if (i>=r+1)
        {
            amount[i]=amount[i]+amount[i-r];
        }
        s=s+amount[i];
    }
    std::cout<<s<<std::endl;
    return 0;
}