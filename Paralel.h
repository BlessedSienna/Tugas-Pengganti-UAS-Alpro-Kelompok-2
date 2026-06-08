#ifndef PARALEL_H
#define PARALEL_H

#include <string>
#include "Kendaraan.h"

// Parameter areaTarget diubah menjadi std::string
inline void hitungAreaThread(Kendaraan* arr, int start, int end, std::string areaTarget, int& hasil) {
    int count = 0;
    for (int i = start; i < end; i++) {
        if (arr[i].area == areaTarget) count++;
    }
    hasil = count;
}

#endif