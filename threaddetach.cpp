#include <thread>
#include <iostream>

void workFunc(int* ptr, size_t times) {
    while (times--) { 
        *ptr += 1;
    }
}

int main(int argc, const char* argv[]) {
    int *numbers = new int[3];

    std::thread t1(workFunc, numbers, 50000);
    std::thread t2(workFunc, numbers + 1, 60000);
    std::thread t3(workFunc, numbers + 2, 70000);

    t1.detach();
    t2.detach();
    t3.detach();

    delete[] numbers;
    
    return 0;
}