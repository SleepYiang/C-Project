#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int>& vec, int left, int right)
{
    // 递归结束的条件
    if (left >= right)
    {
        return;
    }

    //设置基值
    int pivot = vec[(left + right) / 2];
    int begin = left - 1, end = right + 1;
    while (begin < end)
    {
        // 先移动再判断
        do
        {
            begin++;
        } while (vec[begin] < pivot);
        do
        {
            end--;
        } while (vec[end] > pivot);
        if (begin < end)
        {
            swap(vec[begin], vec[end]);
        }
    }
    quickSort(vec, left, end);
    quickSort(vec, end + 1, right);
}

int main()
{
    srand(time(nullptr));
    vector<int> data;
    cout << "排序前的原始数据: ";
    for (int i = 0; i < 10; ++i)
    {
        data.push_back(rand() % 100);
        cout << data.back() << " ";
    }
    cout << endl;
    quickSort(data, 0, data.size() - 1);
    cout << "排序之后的数据: ";
    for (const auto& item : data)
    {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}
