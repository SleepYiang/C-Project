#include <iostream>
#include <stdexcept>

class DynamicArray {
public:
    DynamicArray()
        : capacity(2), size(0), data((int*)malloc(capacity * sizeof(int))) {
        if (data == nullptr) {
            throw std::bad_alloc();
        }
    }
    ~DynamicArray() {
        free(data);
    }
    void add(int value) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        data[size++] = value;
    }
    int get(size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    size_t getSize() const { return size; }
private:
    void resize(size_t new_capacity) {
        int* temp = (int*)realloc(data, new_capacity * sizeof(int));
        if (temp == nullptr) {
            throw std::bad_alloc();
        }
        data = temp;
        capacity = new_capacity;
    }
    size_t capacity;
    size_t size;
    int* data;
};
int main() {
    try {
        DynamicArray arr;
        arr.add(10);
        arr.add(20);
        arr.add(30); // 触发扩展

        std::cout << "Dynamic Array Contents:" << std::endl;
        for (size_t i = 0; i < arr.getSize(); ++i) {
            std::cout << arr.get(i) << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation error: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Array access error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}