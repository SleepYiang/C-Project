#include<iostream>
#include<vector>
void bubbleSortWithFlag(std::vector<int> &nums) {
    // 外循环：未排序区间为 [0, i]
    for (int i = nums.size() - 1; i > 0; i--) {
        bool flag = false; // 初始化标志位
        // 内循环：将未排序区间 [0, i] 中的最大元素交换至该区间的最右端
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[j + 1]) {
                // 交换 nums[j] 与 nums[j + 1]
                // 这里使用了 std::swap() 函数
                std::swap(nums[j], nums[j + 1]);
                flag = true; // 记录交换元素
            }
        }
        if (!flag)
            break; // 此轮“冒泡”未交换任何元素，直接跳出
    }
}
int main()
{
    std::vector<int> nums={100,2,3,4,56,6,7,34,56,67,};
    bubbleSortWithFlag(nums);
    for(int i=0;i<nums.size();i++)
    {
        std::cout<<nums[i]<<" ";
    }
    return 0;
}