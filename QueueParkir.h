#ifndef QUEUEPARKIR_H
#define QUEUEPARKIR_H

#include <iostream>
#include <string>
#include "Kendaraan.h"

class QueueParkir {
private:
    int front, rear, count, capacity;
    Kendaraan* data;

public:
    QueueParkir(int size) {
        capacity = size;
        data = new Kendaraan[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }
    ~QueueParkir() { delete[] data; }

    void enqueue(std::string plat, std::string area) { // Wajib std::string area
        if (count < capacity) {
            rear = (rear + 1) % capacity;
            data[rear].plat = plat;
            data[rear].area = area;
            count++;
            std::cout << "Kendaraan " << plat << " masuk ke Area " << area << ".\n";
        } else {
            std::cout << "Parkir Penuh!\n";
        }
    }

    Kendaraan dequeue() {
        Kendaraan k = {"", ""}; // Defaultnya harus string kosong ("")
        if (count > 0) {
            k = data[front];
            front = (front + 1) % capacity;
            count--;
            std::cout << "Kendaraan " << k.plat << " keluar dari parkiran.\n";
        } else {
            std::cout << "Parkiran Kosong!\n";
        }
        return k;
    }

    void getAll(Kendaraan* arr, int& n) {
        n = count;
        for (int i = 0; i < count; i++) {
            arr[i] = data[(front + i) % capacity];
        }
    }
};

#endif