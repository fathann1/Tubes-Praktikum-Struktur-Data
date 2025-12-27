#ifndef PEGAWAI_H
#define PEGAWAI_H

#include <iostream>
using namespace std;

/* ===== STRUCT ===== */
struct Relasi;

struct Pegawai {
    string nama;
    Pegawai* next;
    Relasi* relasi;
};

struct Shift {
    string nama;
    Shift* next;
    Relasi* relasi;
};

struct Relasi {
    Pegawai* pegawai;
    Shift* shift;
    Relasi* nextPegawai;
    Relasi* nextShift;
};

/* ===== HEAD ===== */
extern Pegawai* headPegawai;
extern Shift* headShift;

/* ===== FUNGSI ===== */
void tambahPegawai(string nama);
void tambahShift(string nama);
void tambahRelasi(string namaPegawai, string namaShift);

void tampilSemua();
void tampilPegawaiPerShift(string namaShift);
void tampilShiftPerPegawai(string namaPegawai);
void pegawaiTerbanyakTersedikit();

#endif
