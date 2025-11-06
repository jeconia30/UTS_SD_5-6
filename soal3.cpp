#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int V, E;
    cout << "Masukkan jumlah orang (V) dan hubungan (E): ";
    cin >> V >> E;

    vector<vector<int>> graph(V); // graf sebagai daftar teman tiap orang
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int S, K;
    cout << "Masukkan orang pertama terinfeksi dan hari ke-K: ";
    cin >> S >> K;

    vector<int> hari(V, -1); // -1 artinya belum terinfeksi
    queue<int> q;
    hari[S] = 0; // orang pertama terinfeksi di hari ke-0
    q.push(S);

    while (!q.empty()) {
        int orang = q.front(); q.pop();
        for (int teman : graph[orang]) {
            if (hari[teman] == -1) { // belum terinfeksi
                hari[teman] = hari[orang] + 1; // terinfeksi hari berikutnya
                q.push(teman);
            }
        }
    }

    vector<int> hasil;
    for (int i = 0; i < V; i++)
        if (hari[i] == K) hasil.push_back(i);

    if (hasil.empty()) cout << "(TIDAK ADA)\n";
    else {
        sort(hasil.begin(), hasil.end());
        cout << "Orang yang terinfeksi pada hari ke-" << K << ": ";
        for (int x : hasil) cout << x << ' ';
        cout << '\n';
    }
}

/*
Penjelasan singkat:
- Gunakan BFS untuk simulasi penyebaran virus per hari.
- hari[i] menyimpan hari kapan orang ke-i terinfeksi.
- Hasil: orang yang hari infeksinya = K.
*/
