#ifndef STACKPARKIR_H
#define STACKPARKIR_H

#include <iostream>
#include "Kendaraan.h"

// Modul Stack menggunakan Array LIFO Native untuk histori kendaraan keluar
class StackParkir {
private:
    int top;
    int capacity;
    Kendaraan* data;

public:
    StackParkir(int size) {
        capacity = size;
        data = new Kendaraan[capacity];
        top = -1;
    }
    
    ~StackParkir() { 
        delete[] data; 
    }

    void push(Kendaraan k) {
        if (top < capacity - 1) {
            data[++top] = k;
        }
    }

    void pop() {
        if (top >= 0) {
            std::cout << "Kendaraan " << data[top].plat << " dihapus dari histori.\n";
            top--;
        }
    }

    void displayStack() {
        if (top == -1) {
            std::cout << "Belum ada kendaraan yang keluar.\n";
            return;
        }
        std::cout << "\n--- Histori Kendaraan Keluar Terakhir (Stack) ---\n";
        for (int i = top; i >= 0; i--) {
            std::cout << "- Plat: " << data[i].plat << " (Area " << data[i].area << ")\n";
        }
    }
};

#endif
