#include <array>
#include <thread>

class Tasks
{
  private:
    std::array<std::thread, 10> threads;       // array of threads for up to 10 tasks
    int                         numThreads{0}; // current number of threads/tasks
  public:
    Tasks() = default;

    // pass a new thread:
    template <typename T>
    void
    start(T op)
    {
        threads[numThreads] = std::thread{std::move(op)};
        ++numThreads;
    }
    //...

    // OOPS: enable default move semantics:
    Tasks(Tasks &&)            = default;
    Tasks &operator=(Tasks &&) = default;

    // at the end wait for all started threads:
    ~Tasks()
    {
        for (int i = 0; i < numThreads; ++i)
        {
            threads[i].join();
        }
    }
};
