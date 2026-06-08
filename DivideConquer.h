#ifndef DIVIDECONQUER_H
#define DIVIDECONQUER_H

#include <string>
#include "Kendaraan.h"

// Modul Divide & Conquer: Merge Sort & Binary Search
inline void merge(Kendaraan arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    Kendaraan* L = new Kendaraan[n1];
    Kendaraan* R = new Kendaraan[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].plat <= R[j].plat) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
    
    delete[] L;
    delete[] R;
}

inline void mergeSort(Kendaraan arr[], int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

inline int binarySearch(Kendaraan arr[], int l, int r, std::string targetPlat) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m].plat == targetPlat) return m;
        if (arr[m].plat < targetPlat) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

#endif
