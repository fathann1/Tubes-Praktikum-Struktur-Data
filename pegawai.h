#ifndef PEGAWAI_H
#define PEGAWAI_H

#include <iostream>
using namespace std;

/*STRUCT DATA*/

/* Forward declaration */
struct Relasi;

/* Struct Pegawai (node pegawai) */
struct Pegawai {
    string nama;          // Nama pegawai
    Pegawai* next;        // Pointer ke pegawai berikutnya
    Relasi* relasi;       // Pointer ke relasi shift
};

/* Struct Shift (node shift kerja) */
struct Shift {
    string nama;          // Nama shift
    Shift* next;          // Pointer ke shift berikutnya
    Relasi* relasi;       // Pointer ke relasi pegawai
};

/* Struct Relasi (many to many) */
struct Relasi {
    Pegawai* pegawai;     // Pegawai terkait
    Shift* shift;         // Shift terkait
    Relasi* nextPegawai;  // Relasi berikutnya di pegawai
    Relasi* nextShift;    // Relasi berikutnya di shift
};

/*HEAD POINTER*/
extern Pegawai* headPegawai;
extern Shift* headShift;

/*PROTOTYPE FUNGSI*/

/* Penambahan data */
void tambahPegawai(string nama);
void tambahShift(string nama);
void tambahRelasi(string namaPegawai, string namaShift);

/* Penghapusan data */
void hapusPegawai(string namaPegawai);
void hapusShift(string namaShift);

/* Penampilan data */
void tampilSemua();
void tampilPegawaiPerShift(string namaShift);
void tampilShiftPerPegawai(string namaPegawai);
void pegawaiTerbanyakTersedikit();

#endif
