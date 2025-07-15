//伪代码
#include<iostream>
int a[10];
void QuuickSort(int left,int right)
{
    if (left>right) return;
    int i = left, j = right;
    int mid=(left+right)/2;
    int p=a[mid];
    while (i<=j)
    {
        while (a[i]<p) i++;
        while (a[j]>0) j--;
        if (i<=j)
        {
            std::swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if (left<j) QuuickSort(left,j);
    if (right>i) QuuickSort(i,right);
}
int main()
{
    return 0;
}