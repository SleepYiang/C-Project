//Actor
//用于异步通信，将消息发送到一个消息队列之中，进程主要通过访问队列完成进程的操作
//发送方知道接收方的信息，接收方知道发送方的相关信息

//CSP
//两个进程的通信依赖管道，接收方和发送方并不关心对的信息

//基于C++实现的CSP
#include<iostream>
#include<queue>
#include<mutex>
#include<condition_variable>
template <typename T>
class Channel
{
private:
    std::mutex mtx_;
    std::condition_variable cv_producer_;
    std::condition_variable cv_consumer_;
    std::queue<T> queue_;
    size_t capacity_;
    bool closed_=false;
public:
    //有参构造
    Channel(size_t capacity=0):capacity_(capacity){}

    //发送
    bool send(T value)
    {
        std::unique_lock<std::mutex> lock(mtx_);
        cv_producer_.wait(lock,[this]()
        {
            // 对于无缓冲的channel，我们应该等待直到有消费者准备好
            return (capacity_==0&&queue_.empty())||queue_.size()<capacity_||closed_;
        });
        if (closed_) return false;
        queue_.push(value);
        cv_consumer_.notify_one();
        return true;
    }
    bool receive(T& value)
    {
        std::unique_lock<std::mutex>lock(mtx_);
        cv_consumer_.wait(lock,[this]()
        {
            return !queue_.empty()||closed_;
        });
        if (closed_&&queue_.empty()) return false;
        value = queue_.front();
        queue_.pop();
        cv_producer_.notify_one();
        return true;
    }
    void close()
    {
        std::unique_lock<std::mutex> lock(mtx_);
        closed_=true;
        cv_producer_.notify_all();
        cv_consumer_.notify_all();
    }
};
int main()
{
    Channel<int> ch(10);
    std::thread producer([&]()
    {
        for(int i=0;i<5;i++)
        {
            ch.send(i);
            std::cout<<"Send"<<i<<std::endl;
        }
        ch.close();
    });
    std::thread consumer([&]()
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        int val;
        while (ch.receive(val))
        {
            std::cout<<"Receive: "<<val<<std::endl;
        }
    });
    producer.join();
    consumer.join();
    return 0;
}