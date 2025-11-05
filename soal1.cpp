#include <iostream>   
#include <vector>     
using namespace std; 

// Fungsi untuk melakukan rotasi kiri pada array
vector<int> rotasiKiri(int d, vector<int> arr) {
    int n = arr.size();   
    d = d % n;            // Jika jumlah rotasi lebih besar dari panjang array, disesuaikan
    vector<int> hasil;    

    // Salin elemen mulai dari indeks ke-d hingga akhir array
    for (int i = d; i < n; i++) {
        hasil.push_back(arr[i]);
    }

    // Tambahkan elemen dari awal sampai sebelum indeks ke-d
    for (int i = 0; i < d; i++) {
        hasil.push_back(arr[i]);
    }

    return hasil;  // Kembalikan hasil rotasi ke fungsi pemanggil
}

int main() {
    system("cls");  

    int n, d;  
    cout << "Masukkan n dan banyak rotasi: ";
    cin >> n >> d;  

    vector<int> arr(n);  

    cout << "Masukkan elemen array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  
    }

    // Panggil fungsi rotasiKiri dengan parameter d dan arr
    vector<int> hasil = rotasiKiri(d, arr);

    
    cout << "Hasil rotasi kiri: ";
    for (int i = 0; i < hasil.size(); i++) {
        cout << hasil[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Program ini melakukan rotasi kiri pada sebuah array sebanyak d kali.
Rotasi kiri berarti elemen paling depan akan berpindah ke belakang secara berurutan.

- Langkah 1–5: Input jumlah elemen (n), jumlah rotasi (d), dan isi array.
- Fungsi rotasiKiri memindahkan elemen dari indeks ke-d hingga akhir ke bagian depan.
- Kemudian, elemen dari awal sampai sebelum indeks ke-d ditaruh di bagian belakang.
- Hasil akhirnya adalah array yang sudah dirotasi ke kiri sebanyak d kali.
*/
