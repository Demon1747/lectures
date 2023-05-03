#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

std::atomic_int acnt;
int cnt;

void f()
{
    for (int n = 0; n < 10000; ++n)
    {
        ++acnt; // acnt.fetch_add(1, std::memory_order_relaxed);
        ++cnt;
    }
}

int main()
{
    
    std::vector<std::thread> pool;
    for (int n = 0; n < 10; ++n)
        pool.emplace_back(f);
    
    for (auto& i : pool) {
        i.join();
    }
 
    std::cout << "The atomic counter is " << acnt << '\n'
              << "The non-atomic counter is " << cnt << '\n';
}
