#include "pegawai.h"

int main() {
    int pilih;
    string namaP, namaS;

    do {
        cout << "\nMENU\n";
        cout << "1 Tambah Pegawai\n";
        cout << "2 Tambah Shift\n";
        cout << "3 Tambah Relasi\n";
        cout << "4 Tampil Semua\n";
        cout << "5 Pegawai per Shift\n";
        cout << "6 Shift per Pegawai\n";
        cout << "7 Terbanyak & Tersedikit\n";
        cout << "0 Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            cin >> namaP;
            tambahPegawai(namaP);
        }
        else if (pilih == 2) {
            cin >> namaS;
            tambahShift(namaS);
        }
        else if (pilih == 3) {
            cin >> namaP >> namaS;
            tambahRelasi(namaP, namaS);
        }
        else if (pilih == 4) {
            tampilSemua();
        }
        else if (pilih == 5) {
            cin >> namaS;
            tampilPegawaiPerShift(namaS);
        }
        else if (pilih == 6) {
            cin >> namaP;
            tampilShiftPerPegawai(namaP);
        }
        else if (pilih == 7) {
            pegawaiTerbanyakTersedikit();
        }
    } while (pilih != 0);

    return 0;
}
