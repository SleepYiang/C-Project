#ifndef MEMORYPOOL_1_0_H
#define MEMORYPOOL_1_0_H
namespace memoryPool
{
#define  MEMORY_POOL_NUM 64
#define SLOT_BASE_SIZE 8
#define MAX_SLOT_SIZE 512

struct Slot
{
    Slot*next;
};
class MemoryPool
{
public:
    MemoryPool(size_t BlockSize=4096);
    ~MemoryPool();

    void init(size_t);

    void* allocate();
    void deallocate(void*);
private:
    void allocateNewBlock();
    size_t padPointer(char*,size_t align);
};
}



#endif //MEMORYPOOL_1_0_H
