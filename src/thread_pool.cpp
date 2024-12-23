#include "thread_pool.h"
using namespace std;

void ThreadPool::initialize(size_t numThreads) {
    for (size_t i = 0; i < numThreads; ++i) {
        workers.emplace_back(&ThreadPool::workerThread, this);
    }
}

void ThreadPool::enqueueTask(function<void()> task) {
    {
        lock_guard<mutex> lock(queueMutex);
        taskQueue.push(task);
    }
    condition.notify_one();
}

void ThreadPool::workerThread() {
    while (true) {
        function<void()> task;
        {
            unique_lock<mutex> lock(queueMutex);
            condition.wait(lock, [this] { return !taskQueue.empty() || stop; });
            if (stop && taskQueue.empty()) return;
            task = move(taskQueue.front());
            taskQueue.pop();
        }
        task();
    }
}

void ThreadPool::shutdown() {
    {
        lock_guard<mutex> lock(queueMutex);
        stop = true;
    }
    condition.notify_all();
    for (thread& worker : workers) {
        if (worker.joinable()) {
            worker.join();
        }
    }
}

ThreadPool::~ThreadPool() {
    if (!stop) shutdown();
}

