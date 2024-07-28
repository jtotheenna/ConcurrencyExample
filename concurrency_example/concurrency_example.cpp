#include <iostream>
#include <thread>
#include <mutex>
#include <stdexcept>

std::mutex mtx;

void countUp() {
    try {
        for (int i = 0; i <= 20; ++i) {
            std::lock_guard<std::mutex> lock(mtx);
            std::cout << "Count Up: " << i << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception in countUp: " << e.what() << std::endl;
    }
}

void countDown() {
    try {
        for (int i = 20; i >= 0; --i) {
            std::lock_guard<std::mutex> lock(mtx);
            std::cout << "Count Down: " << i << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception in countDown: " << e.what() << std::endl;
    }
}

int main() {
    try {
        std::thread t1(countUp);
        t1.join(); // Wait for the first thread to finish

        std::thread t2(countDown);
        t2.join(); // Wait for the second thread to finish

        std::cout << "Counting completed successfully." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception in main: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
