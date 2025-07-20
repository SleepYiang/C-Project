#include<iostream>
class DynamicArray
{
public:
    DynamicArray(size_t initial_size=1):size(initial_size)
    ,data((int*)malloc(size*sizeof(int)))
    {
        if(data==nullptr)
        {
            throw std::bad_alloc();
        }
    }
    ~DynamicArray()
    {
        free(data);
    }
    void resize(size_t new_size)
    {
        int* temp=(int*)realloc(data,new_size*sizeof(int));
        if(temp==nullptr)
        {
            throw std::bad_alloc();
        }
        data=temp;
        size=new_size;
    }

    int& operator[](size_t index) {
        return data[index];
    }
    size_t getSize() const { return size; }

private:
    size_t size;
    int* data;
};
int main()
{
    //初始分配三个整数
    int * arr=(int*)malloc(3*sizeof(int));
    if (arr==nullptr)
    {
        std::cerr<<"Error in memory allocation"<<std::endl;
        return -1;
    }
    //初始化数组
    for (int i=0;i<3;i++)
    {
        arr[i]=i+1;
    }
    std::cout<<"Initial array: ";
    for (int i=0;i<3;i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
    //重新分配5个整数
    int* temp=(int*)realloc(arr,5*sizeof(int));
    if (temp==nullptr)
    {
        std::cerr<<"Error in memory allocation"<<std::endl;
        free(arr);//释放内存
        return 1;
    }
    arr=temp;
    //初始化新元素
    for (int i=3;i<5;i++)
    {
        arr[i]=i*10;
    }
    std::cout<<"Final array: ";
    for (int i=0;i<5;i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
    free(arr);
    std::cout<<"******************************************"<<std::endl;
    try {
        DynamicArray arr(3);
        // 初始化
        for (size_t i = 0; i < arr.getSize(); ++i) {
            arr[i] = i + 1;
        }

        std::cout << "Initial array: ";
        for (size_t i = 0; i < arr.getSize(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        // 调整大小
        arr.resize(5);
        arr[3] = 40;
        arr[4] = 50;

        std::cout << "Resized array: ";
        for (size_t i = 0; i < arr.getSize(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
///sgnsdg
