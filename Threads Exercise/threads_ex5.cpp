#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable> // will learn about it later

std::mutex mutex_fileF;
std::mutex mutex_fileG;

std::mutex mutex_print;

#define THREAD_F 1
#define THREAD_G 2
#define SPACE "     "



bool firstFinish = false;
std::mutex mutex_sync;
std::condition_variable condition_variable;

/**
 * The first thread that enter this function is wait,
 * and the second thread that enters this function is
 * wakes the first one. In other words this function forces
 * two thread to wait for each other.
 */
void wait_for_the_other_thread() {
    std::unique_lock<std::mutex> lock(mutex_sync);
    if (firstFinish) {
        firstFinish = false;
        condition_variable.notify_all();
    } else {
        firstFinish = true;
        condition_variable.wait(lock);
    }
}



void print(int threadId, std::string str) {
    mutex_print.lock();

    if (threadId == THREAD_F) {
        std::cout << " | " << SPACE << " | "<< std::endl;
        std::cout << str   << SPACE << " | "<< std::endl;
    } else {
        std::cout << " | " << SPACE << " | "<< std::endl;
        std::cout << " | " << SPACE << str  << std::endl;
    }

    mutex_print.unlock();

    // make sure that the other thread can print to...
    std::this_thread::sleep_for(std::chrono::microseconds (1));
}

void F(std::fstream *fileF, std::fstream *fileG) {
    bool isLocked;

    do {
        mutex_fileF.lock(); // lock the resource: fileF, because need to read from it
        print(THREAD_F, "[F]");

        // make sure that the threads check the lock together
        wait_for_the_other_thread();

        // try to lock the mutex, but he is not waiting!
        isLocked = mutex_fileG.try_lock();

        // and make sure that one thread is not faster than the other
        wait_for_the_other_thread();

        // try to be smart and open the mutex for the other thread
        if (!isLocked) {
            mutex_fileF.unlock();
            print(THREAD_F, "_F_");
        }

    } while (!isLocked);

    print(THREAD_F, "[G]");

    // doSomething();

    mutex_fileG.unlock();
    print(THREAD_F, "_G_");

    mutex_fileF.unlock();
    print(THREAD_F, "_F_");
}

void G(std::fstream *fileF, std::fstream *fileG) {
    bool isLocked;

    do {
        mutex_fileG.lock(); // lock the resource: fileG, because need to read from it
        print(THREAD_G, "[G]");

        // make sure that the threads check the lock together
        wait_for_the_other_thread();

        // try to lock the mutex, but he is not waiting!
        isLocked = mutex_fileF.try_lock();

        // and make sure that one thread is not faster than the other
        wait_for_the_other_thread();

        // try to be smart and open the mutex for the other thread
        if (!isLocked) {
            mutex_fileG.unlock();
            print(THREAD_G, "_G_");
        }

    } while (!isLocked);

    print(THREAD_G, "[F]");

    // doSomething();

    mutex_fileF.unlock();
    print(THREAD_G, "_F_");

    mutex_fileG.unlock();
    print(THREAD_G, "_G_");
}

int main() {
    std::fstream *f; // shared resource
    std::fstream *g; // shared redsource

    std::thread t1(F, f, g);
    std::thread t2(G, f, g);

    t1.join();
    t2.join();
}