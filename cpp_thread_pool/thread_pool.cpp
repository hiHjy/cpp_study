#include <iostream>
#include <thread>
#include <string>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <vector>
class ThreadPool {
public:
    //锁
    std::mutex mux;

    //条件变量对象
    std::condition_variable con;    
   
    //线程数组
    std::vector<std::thread> threads; 

    //任务队列,队列中每一个元素都可以调用都是可以调用的
    std::queue<std::function<void()>> tasks;

    bool running;  
    ThreadPool() = delete;
    ~ThreadPool() {
        {
            std::unique_lock lock(mux);
            running = false;
        }
        con.notify_all();
        for (auto &t : threads) {
            //线程池要停止工作，等待线程池中的正在执行的任务 
            t.join(); 
        }
    }
    
    template <class F, class... Args>
    void enqueue(F&& f, Args&& ... args) {
        aoto task = bind(std::forward<F> (f), std::forward<Args> (args)...);
        {
            std::unique_lock<std::mutex> lock(mux);
            //添加任务
            tasks.emplace(move(task));
        }

        con.notify_one();
    }

     //构造线程池
     ThreadPool(int threadNum): running(true) {
        for (int i = 0; i < threadNum; i++) {
            //提前构造threadNum个线程
           
            threads.emplace_back([this]() {
                //用lanmbda表达式传线程回调函数
                while (true) {
                    //使用条件变量前先上锁
                    std::unique_lock<std::mutex> lock(mux);
                    
                    //先自动解锁判断!tasks.empty() || running 的值 ，当任务队列中有任务或者线程池停止工作时唤醒(谓词？)
                    con.wait(lock, [this]() {return !tasks.empty() || !running;});

                    //看一下被唤醒的原因是线程池停止工作了还是来活了
                    if (!running) {
                        //如果被线程池设置为停止工作，那么应该退出该线程
                        std::cout << "线程池停止工作" << std::endl;
                        return;
                    }
                    //唤醒之后去取任务
                        //任务是一个可以调用的用function<返回值(参数列表)>, 用移动构造提高效率
                    std::function<void()> task = move(tasks.front());
                    tasks.pop();  

                    //取出任务立马释放锁
                    lock.unlock();
                   
                    
                    //执行任务
                    task();
                    

                    
                }//while  //创建了threadNum个工作线程

            });//threads.emplace_back()
           
     
            
        }
     }
};


int main() {


    return 0;
}