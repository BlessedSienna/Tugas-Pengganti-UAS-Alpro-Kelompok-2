# Smart Parking Management System 🚗

Program manajemen parkir kampus berbasis terminal (CLI) yang dibangun murni menggunakan **C++ Native**. Proyek ini mengimplementasikan berbagai struktur data dan algoritma dari awal (*from scratch*) tanpa menggunakan Standard Template Library (STL) bawaan seperti `<queue>`, `<stack>`, atau `<algorithm>`. 

Proyek ini dikembangkan menggunakan prinsip *Modular Programming* di mana setiap fitur utama diisolasi ke dalam _file header_ terpisah.

## 👥 Tim Pengembang (Kelompok 23)
1. **Satria Ramadhan Aulia Rivanka** - [21120124130080]
2. **Fajar Herdiansyah** - [21120123140142]
3. **Hafiyyan Dimas Walana** - [21120124140130]

## 🛠️ Fitur & Implementasi Algoritma
Sistem ini menyediakan 6 menu utama yang masing-masing mendemonstrasikan konsep struktur data dan algoritma yang berbeda:

1. **Kendaraan Masuk (`Queue`)**
   - Menggunakan *Circular Array* murni untuk mengelola antrean.
   - Kompleksitas Waktu: **O(1)**
2. **Kendaraan Keluar (`Stack`)**
   - Menggunakan LIFO (*Last In First Out*) Array murni untuk menyimpan riwayat kendaraan yang paling terakhir keluar.
   - Kompleksitas Waktu: **O(1)**
3. **Pencarian Plat Nomor (`Divide & Conquer`)**
   - Menyalin data dari antrean, mengurutkannya dengan **Merge Sort**, lalu mencari data menggunakan **Binary Search**.
   - Kompleksitas Waktu: **O(n log n)** untuk *sorting*, **O(log n)** untuk *searching*.
4. **Rekap Area Parkir (`Paralel`)**
   - Menghitung jumlah kendaraan pada dua area berbeda secara bersamaan menggunakan *Multi-threading* bawaan C++ (`std::thread`).
   - Kompleksitas Waktu: Mendekati **O(n/p)** di mana *p* adalah jumlah thread.
5. **Histori Kendaraan Keluar**
   - Menampilkan isi stack.
6. **Tampilkan Semua Kendaraan**
   - Menampilkan seluruh kendaraan yang saat ini sedang berada di dalam antrean *queue* parkiran.


## 🚀 Cara Menjalankan program
Pastikan komputer Anda sudah terinstal *compiler* **MinGW-w64 (MSYS2)** atau GCC yang mendukung standar C++11 ke atas (untuk dukungan library `<thread>`).

1. *Clone repository* ini ke komputer lokal:
   ```bash
   git clone https://github.com/FarrellFausto/smart-parking-system.git
   ```
2. Masuk ke direktori proyek:
   ```bash
   cd smart-parking-system
   ```
3. Lakukan kompilasi melalui terminal menggunakan perintah `g++`:
   ```bash
   g++ main.cpp -o SmartParking
   ```
4. Jalankan aplikasi yang sudah dikompilasi:
   ```bash
   .\SmartParking
   ```
