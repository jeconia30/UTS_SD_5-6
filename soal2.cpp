#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;   
    Node* next;    
};

Node* head = NULL; 
Node* tail = NULL;

// tambah pasien normal
void TambahPasienNormal(string nama) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->next = NULL;

    // Jika antrian kosong
    if (head == NULL) {
        head = tail = baru;
    } 
    else {
        tail->next = baru;
        tail = baru;
    }
}

// tambah pasien darurat(masuk ke depan antrian)
void TambahPasienDarurat(string nama) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->next = head;   
    head = baru;

    if (tail == NULL) {
        tail = baru;
    }
}

// LAYANI 
void LayaniPasien() {
    if (head != NULL) {
        cout << head->nama << endl;   

        Node* hapus = head;
        head = head->next;
        delete hapus;

        if (head == NULL) {
            tail = NULL;
        }
    }
}

int main() {
    int N;
    cin >> N;   

    for (int i = 0; i < N; i++) {
        string perintah, nama;
        cin >> perintah;

        if (perintah == "DATANG") {
            cin >> nama;
            TambahPasienNormal(nama);
        }
        else if (perintah == "DARURAT") {
            cin >> nama;
            TambahPasienDarurat(nama);
        }
        else if (perintah == "LAYANI") {
            LayaniPasien();
        }
    }

    return 0;
}

/*
Penjelasan algoritma/logika penyelesaian soal no 2.
Program ini mensimulasikan antrian pasien di rumah sakit dengan dua jenis yaitu Pasien normal dan Pasien darurat.

Program menggunakan linked list untuk membuat antrian pasien.
1. Pasien NORMAL → ditambahkan di belakang antrian (setelah tail).
2. Pasien DARURAT → ditambahkan di depan antrian (sebelum head).
3. Saat "LAYANI", pasien pada posisi head dilayani dan dihapus dari antrian.

Jika setelah penghapusan antrian kosong, head dan tail diset menjadi NULL.
Logika: pasien darurat selalu didahulukan karena langsung berada di depan antrian.
*/
