#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    string nama;
    int N;
    cin >> N; 
    queue<string> normal;
    queue<string> darurat;

    for (int i = 0; i < N; i++) {
        string perintah;
        cin >> perintah;
        
//tambah pasien normal
        if (perintah == "DATANG") {
            cin >> nama;
            normal.push(nama); 
        }

// tambah pasien darurat(masuk ke depan antrian)
        else if (perintah == "DARURAT") {
            cin >> nama;
            darurat.push(nama); 
        }

//LAYANI
        else if (perintah == "LAYANI") {
            if (!darurat.empty()) {
                cout << darurat.front() << endl;
                darurat.pop();
            } 
            else if (!normal.empty()) {
                cout << normal.front() << endl;
                normal.pop();
            }
        }
    }
    return 0;
}

/*
Penjelasan algoritma/logika penyelesaian soal no 2.
Program ini mensimulasikan antrian pasien di rumah sakit dengan dua jenis yaitu Pasien normal dan Pasien darurat.

Program ini menggunakan dua buah queue yaitu queue normal dan queue darurat.
- Jika perintah "DATANG", nama pasien dimasukkan ke queue normal.
- Jika perintah "DARURAT", nama pasien dimasukkan ke queue darurat.
- Jika perintah "LAYANI":
    • Jika ada pasien darurat, yang dilayani adalah yang paling depan (front) di queue darurat.
    • Jika tidak ada pasien darurat, melayani pasien paling depan dari queue normal.

Queue bekerja dengan prinsip FIFO (First In First Out):
- Elemen paling awal masuk akan dilayani lebih dulu.
- Untuk pasien darurat, antriannya dipisah sehingga mereka selalu diprioritaskan.
*/
