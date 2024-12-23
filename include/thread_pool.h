#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <functional>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <atomic>
using namespace std;

class ThreadPool {
public:
    void initialize(size_t numThreads);
    void enqueueTask(function<void()> task);
    void shutdown();
    ~ThreadPool();

private:
    vector<thread> workers;
    queue<function<void()>> taskQueue;
    mutex queueMutex;
    condition_variable condition;
    atomic<bool> stop{false};

    void workerThread();
};

#endif

