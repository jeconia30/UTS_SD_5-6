#include <iostream>
#include <vector>
using namespace std;

vector<int> rotasiKiri(int d, vector<int> arr) {
    int n = arr.size();
    d = d % n; // jika jumlah rotasi melebihi panjang array
    vector<int> hasil;

    // menyalin elemen mulai dari indeks d hingga akhir
    for (int i = d; i < n; i++) {
        hasil.push_back(arr[i]);
    }

    // lanjutkan dengan elemen dari awal hingga sebelum indeks d
    for (int i = 0; i < d; i++) {
        hasil.push_back(arr[i]);
    }

    return hasil;
}

int main() {
    system("cls");
    int n, d;
    cout << "Masukkan n dan banyak rotasi: ";
    cin >> n >> d;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> hasil = rotasiKiri(d, arr);

    for (int i = 0; i < hasil.size(); i++) {
        cout << hasil[i] << " ";
    }
    cout << endl;

    return 0;
}
