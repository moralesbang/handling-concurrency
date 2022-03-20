#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

using namespace std;

class Semaphore {

public:
    Semaphore (int count_ = 0)
    : count(count_) 
    {
    }
    
    inline void notify( int tid ) {
        std::unique_lock<std::mutex> lock(mtx);
        count++;
        cout << "thread " << tid <<  " notify" << endl;
        cv.notify_one();
    }
    inline void wait( int tid ) {
        std::unique_lock<std::mutex> lock(mtx);
        while(count == 0) {
            cout << "thread " << tid << " wait" << endl;
            cv.wait(lock);
            cout << "thread " << tid << " run" << endl;
        }
        count--;
    }
private:
    std::mutex mtx;
    std::condition_variable cv;
    int count;
};

int buffer[1];
Semaphore sem(1);
std::mutex mtx2;

void producer() {
 
  sem.wait( 1 );
  int i;
  for (i = 0; i < 10000; i++)
  {
      buffer[0]=buffer[0]+i;
  }
  
  sem.notify( 1 ); 
}

void consumer() {

  sem.wait( 2 );
  int i;
  for (i = 0; i < 10000; i++)
  {
      buffer[0]=buffer[0]-i;
  }
  sem.notify( 2 );
}

int main()
{
    
   thread t1(producer);
   thread t2(consumer);
    
    t1.join();
    t2.join();

    }