#ifndef _SORT_ALGO_COMPARATOR_H_
#define _SORT_ALGO_COMPARATOR_H_

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
// #include <pthread.h>
// #include <windows.h>
// #include <time.h>

#include <chrono>
#include <thread>

typedef struct argument_t {
    int *data;
    int n;
} argument_t;

template <typename T>
class SortAlgoComparator {
    private:
    T *data;
    size_t size;

    public:
    SortAlgoComparator();
    ~SortAlgoComparator();
    read_data(const std::string filename);
    void sort(T *(*sort)(T *data, int n), const std::string algo_name, int timeout = 15);
};

template <typename T>
SortAlgoComparator<T>::SortAlgoComparator() {
    data = NULL;
    size = 0;
}

template <typename T>
SortAlgoComparator<T>::~SortAlgoComparator() {
    if (data) {
        delete[] data;
    }
}

template <typename T>
int SortAlgoComparator<T>::read_data(const std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return 0;
    }

    int count = 0;
    T elem;
    while (file >> elem) {
        count++;
    }

    data = new T[count];
    if (!data) {
        file.close();
        return 0;
    }
    size = count;

    file.clear();
    file.seekg(0, std::ios::beg);

    count = 0;
    while (file >> elem) {
        data[count++] = elem;
    }

    file.close();
    return count;
}

template <typename T>
void SortAlgoComparator<T>::sort(T *(*sort)(T *data, int n), const std::string algo_name, int timeout) {
    // make a copy of data
    T *data = new T[size];
    memcpy(data, this->data, size * sizeof(T));

    std::cout << algo_name << " started..." << std::endl;
    auto start = std::chrono::system_clock::now();
    std::thread t(sort, data, size);

    if (t.joinable() && t.get_id() != std::thread::id()) {
        t.join();
        auto end = std::chrono::system_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        if (elapsed.count() > timeout * 1000) {
            std::cout << algo_name << " timed out :" << timeout << std::endl;
        } else {
            std::cout << algo_name << ": " << std::fixed << std::setprecision(3) << (double)elapsed.count() / 1000 << " seconds" << std::endl;
        }
    }
}

#endif