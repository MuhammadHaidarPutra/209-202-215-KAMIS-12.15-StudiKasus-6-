#include <iostream>
using namespace std;

class Mahasiswa {
private:
    string nama;
    int nim;
    float alpro, matdis, pweb, aljabar;
    float nilaiAkhir;

    float inputNilaiMataKuliah(const char* matkul) {
        float nilai;
        do {
            cout << "|Input Nilai " << matkul << nama <<" : ";
            cin >> nilai;
            if (nilai > 100 || nilai < 0) {
                cout << "|Nilai harus antara 0 - 100. Ulangi input!\n";
            }
        } while (nilai > 100 || nilai < 0);
        return nilai;
    }

public:
    void inputData(int index) {
        if (index == 1) {
            cout << "+=======================================+\n";
            cout << "|         INPUT NILAI MAHASISWA         |\n";
            cout << "+=======================================+\n";
        } else {
            cout << "+=======================================+\n";
        }
        cin.ignore();
        cout << "|Masukkan Nama Mahasiswa ke-" << index << " : ";
        getline(cin, nama);
        cout << "|Masukkan NIM " << nama << " : ";
        cin >> nim;
        cout << "|\n";

        alpro   = inputNilaiMataKuliah("Alpro ");
        matdis  = inputNilaiMataKuliah("Matdis ");
        pweb    = inputNilaiMataKuliah("Pweb ");
        aljabar = inputNilaiMataKuliah("Aljabar ");

        nilaiAkhir = (alpro + matdis + pweb + aljabar) / 4.0;
    }

    void tampilkanData(bool tampilHeader = false) {
        char huruf;
        const char* kelulusan;

        if (nilaiAkhir >= 85) {
            huruf = 'A';
            kelulusan = "LULUS";
        } else if (nilaiAkhir >= 75) {
            huruf = 'B';
            kelulusan = "LULUS";
        } else if (nilaiAkhir >= 60) {
            huruf = 'C';
            kelulusan = "TIDAK LULUS";
        } else {
            huruf = 'D';
            kelulusan = "TIDAK LULUS";
        }

        if (tampilHeader) {
            cout << "+==========================================+\n";
            cout << "|          DATA NILAI MAHASISWA            |\n";
            cout << "+==========================================+\n";
        }

        cout << "| Nama                  : " << nama << endl;
        cout << "| NIM                   : " << nim << endl;
        cout << "| Nilai Akhir Mahasiswa : " << nilaiAkhir << endl;
        cout << "| Huruf                 : " << huruf << endl;
        cout << "| Kelulusan             : " << kelulusan << endl;
        cout << "+==========================================+\n";
    }

    float getNilaiAkhir() {
        return nilaiAkhir;
    }
};

int main() {
    int jumlah;
    do {
        cout << "Masukan Jumlah mahasiswa: ";
        cin >> jumlah;
        if (jumlah <= 0 || jumlah > 100) {
            cout << "Jumlah harus antara 1 - 100. Ulangi!\n";
        }
    } while (jumlah <= 0 || jumlah > 100);

    Mahasiswa mhs[100];
    int pilihan;
    bool sudahInput = false;

    do {
        cout << "\n+===========================+\n";
        cout << "|           MENU            |\n";
        cout << "+===========================+\n";
        cout << "| 1. Input Nilai            |\n";
        cout << "| 2. Tampilkan Data Nilai   |\n";
        cout << "| 3. Keluar                 |\n";
        cout << "+===========================+\n";
        cout << "|Masukkan Pilihan : "; cin >> pilihan;
        cout << "+===========================+\n\n";

        if (pilihan == 1) {
            for (int i = 0; i < jumlah; i++) {
                mhs[i].inputData(i + 1);
            }
            cout << "+=======================================+\n";
            cout << "|     NILAI MAHASISWA BERHASIL DIINPUT  |\n";
            cout << "+=======================================+\n";
            sudahInput = true;

        } else if (pilihan == 2) {
            if (!sudahInput) {
                cout << "\nSilakan input data terlebih dahulu!\n";
            } else {
                float totalNilai = 0;
                for (int i = 0; i < jumlah; i++) {
                    mhs[i].tampilkanData(i == 0); 
                    totalNilai += mhs[i].getNilaiAkhir();
                }
                float rataRata = totalNilai / jumlah;

                cout << "| Jumlah Mahasiswa         : " << jumlah << endl;
                cout << "| Total Nilai Mahasiswa    : " << totalNilai << endl;
                cout << "| Rata-rata nilai Mahasiswa: " << rataRata << endl;
                cout << "+=======================================+\n";
            }

        } else if (pilihan == 3) {
            cout << "\nTerima Kasih.\n";

        } else {
            cout << "\nPilihan tidak valid, silakan ulangi.\n";
        }

    } while (pilihan != 3);

    return 0;
}
