#include <iostream>
#include <string>
#include <thread>
#include <cstdlib>
#include "Kendaraan.h"
#include "QueueParkir.h"
#include "StackParkir.h"
#include "DivideConquer.h"
#include "Paralel.h"

using namespace std;

void tampilkanMenu() {
    cout << "=========================================\n";
    cout << "   SMART PARKING SYSTEM - Kel 2\n";
    cout << "   Satria Ramadhan Aulia Rivanka (21120124130080)\n";
    cout << "   Fajar Herdiansyah (21120123140142)\n";
    cout << "   Hafiyyan Dimas Walana (21120124140130)\n";
    cout << "=========================================\n";
    cout << "1. Kendaraan Masuk\n";
    cout << "2. Kendaraan Keluar\n";
    cout << "3. Cari Kendaraan\n";
    cout << "4. Rekap Area Parkir\n";
    cout << "5. Histori Kendaraan Keluar\n";
    cout << "6. Tampilkan Semua Kendaraan\n";
    cout << "0. Keluar\n";
    cout << "Pilih menu: ";
}

int main() {
    QueueParkir antrean(100);
    StackParkir historiKeluar(100);
    int pilihan;

    do {
        system("cls"); 
        tampilkanMenu();
        
        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(10000, '\n');
            pilihan = -1; 
        }

        if (pilihan == 1) {
            string plat;
            string area;
            
            cout << "\nMasukkan Plat Nomor: ";
            cin.ignore(10000, '\n'); 
            getline(cin, plat);

            cout << "Masukkan Area (Contoh: VIP, A1, B): ";
            getline(cin, area); 

            antrean.enqueue(plat, area);

        } else if (pilihan == 2) {
            cout << "\n";
            Kendaraan k = antrean.dequeue();
            if (k.area != "") { 
                historiKeluar.push(k);
            }

        } else if (pilihan == 3) {
            cout << "\n";
            Kendaraan dataKendaraan[100];
            int n;
            antrean.getAll(dataKendaraan, n);

            if (n == 0) {
                cout << "Parkiran masih kosong!\n";
            } else {
                string cariPlat;
                cout << "Masukkan plat yang dicari: ";
                cin.ignore(10000, '\n'); 
                getline(cin, cariPlat); 

                mergeSort(dataKendaraan, 0, n - 1);
                int indeks = binarySearch(dataKendaraan, 0, n - 1, cariPlat);

                if (indeks != -1) {
                    cout << "\n>>> KETEMU! Kendaraan " << cariPlat << " berada di Area " << dataKendaraan[indeks].area << ".\n";
                } else {
                    cout << "\n>>> TIDAK DITEMUKAN! Kendaraan tidak ada di parkiran.\n";
                }
            }

        } else if (pilihan == 4) {
            Kendaraan dataKendaraan[100];
            int n;
            antrean.getAll(dataKendaraan, n);

            string target1, target2;
            cout << "\nMasukkan nama Area ke-1 yang ingin direkap: ";
            cin >> target1;
            cout << "Masukkan nama Area ke-2 yang ingin direkap: ";
            cin >> target2;

            int totalArea1 = 0, totalArea2 = 0;
            
            thread t1(hitungAreaThread, dataKendaraan, 0, n, target1, ref(totalArea1));
            thread t2(hitungAreaThread, dataKendaraan, 0, n, target2, ref(totalArea2));

            t1.join();
            t2.join();

            cout << "\n--- Rekap Paralel ---\n";
            cout << "Kendaraan di Area " << target1 << ": " << totalArea1 << "\n";
            cout << "Kendaraan di Area " << target2 << ": " << totalArea2 << "\n";

        } else if (pilihan == 5) {
            historiKeluar.displayStack();

        } else if (pilihan == 6) { // <-- Logika Tambahan untuk Menu 6
            cout << "\n--- Daftar Kendaraan di Parkiran ---\n";
            Kendaraan dataKendaraan[100];
            int n;
            
            // Ambil semua data dari antrean (queue)
            antrean.getAll(dataKendaraan, n);

            if (n == 0) {
                cout << "Parkiran saat ini kosong!\n";
            } else {
                for (int i = 0; i < n; i++) {
                    cout << i + 1 << ". Plat: " << dataKendaraan[i].plat 
                         << " | Area: " << dataKendaraan[i].area << "\n";
                }
                cout << "\nTotal kendaraan di dalam parkiran: " << n << " kendaraan\n";
            }
        }

        if (pilihan != 0) {
            cout << "\n";
            system("pause"); 
        }

    } while (pilihan != 0);

    cout << "\nProgram selesai. Terima kasih!\n";
    return 0;
}