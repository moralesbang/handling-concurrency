#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int current_count = 0;
mutex critical_section;

void increment(int n) {
    critical_section.lock();
    for (int i = 0; i < n; ++i) {
        ++current_count;
    }
    critical_section.unlock();
}

int main() {

    thread t1(increment, 100000000);
    thread t2(increment, 100000000);

    t1.join();
    t2.join();
    
    cout << "Current count: " << current_count << endl;
    
    return 0;
}