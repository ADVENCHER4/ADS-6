// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
template<typename T, int size>
class TPQueue {
 private:
    T* arr;
    uint64_t first, last, count;

 public:
    TPQueue(): first(0), last(0), count(0) {
        arr = new T[size];
    }
    bool isEmpty() const {
        return count == 0;
    }
    bool isFull() const {
        return count == size;
    }
    void push(const T& val) {
        if (isFull()) {
            throw std::string("Full");
        } else {
            count++;
            int ind = last;
            for (int i = first; i < last; i++) {
                if (arr[i].prior < val.prior) {
                    ind = i;
                    break;
                }
            }
            for (int i = last; i > ind; i--) {
                arr[i % size] = arr[(i - 1) % size];
            }
            arr[ind % size] = val;
            last++;
        }
    }
    T& pop() {
        if (isEmpty()) {
            throw std::string("Empty");
        } else {
            count--;
            return arr[first++ % size];
        }
    }
    ~TPQueue() {
        delete[] arr;
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
