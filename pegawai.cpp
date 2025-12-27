#include "pegawai.h"

/* ===== HEAD LIST ===== */
// Pointer awal untuk linked list pegawai
Pegawai* headPegawai = NULL;

// Pointer awal untuk linked list shift
Shift* headShift = NULL;


/* ====== TAMBAH DATA ====== */
// Menambahkan satu data pegawai ke dalam list pegawai
void tambahPegawai(string nama) {
    if (cariPegawai(nama) != NULL) {
        cout << "[GAGAL] Pegawai \"" << nama << "\" sudah terdaftar.\n";
        return;
    }

    Pegawai* p = new Pegawai;
    p->nama = nama;
    p->relasi = NULL;
    p->next = headPegawai;
    headPegawai = p;

    cout << "[BERHASIL] Pegawai \"" << nama << "\" berhasil ditambahkan.\n";
}

// Menambahkan satu data shift ke dalam list shift
void tambahShift(string nama) {
    Shift* s = new Shift;
    s->nama = nama;
    s->relasi = NULL;
    s->next = headShift;
    headShift = s;
}


/* PENCARIAN DATA  */
// Mencari pegawai berdasarkan nama
Pegawai* cariPegawai(string nama) {
    Pegawai* p = headPegawai;
    while (p != NULL) {
        if (p->nama == nama)
            return p;
        p = p->next;
    }
    return NULL;
}

// Mencari shift berdasarkan nama
Shift* cariShift(string nama) {
    Shift* s = headShift;
    while (s != NULL) {
        if (s->nama == nama)
            return s;
        s = s->next;
    }
    return NULL;
}


/* ====== TAMBAH RELASI ====== */
// Menghubungkan pegawai dengan shift (many to many)
void tambahRelasi(string namaPegawai, string namaShift) {
    Pegawai* p = cariPegawai(namaPegawai);
    Shift* s = cariShift(namaShift);

    // Jika salah satu tidak ditemukan
    if (p == NULL || s == NULL) {
        cout << "Data tidak ditemukan\n";
        return;
    }

    // Membuat node relasi baru
    Relasi* r = new Relasi;
    r->pegawai = p;
    r->shift = s;

    // Relasi ke pegawai
    r->nextPegawai = p->relasi;
    p->relasi = r;

    // Relasi ke shift
    r->nextShift = s->relasi;
    s->relasi = r;
}


/* ====== TAMPILKAN SEMUA DATA ====== */
// Menampilkan seluruh pegawai beserta shift yang dimiliki
void tampilSemua() {
    Pegawai* p = headPegawai;
    while (p != NULL) {
        cout << "Pegawai: " << p->nama << " | Shift: ";
        Relasi* r = p->relasi;

        if (r == NULL) cout << "-";
        while (r != NULL) {
            cout << r->shift->nama << " ";
            r = r->nextPegawai;
        }
        cout << endl;
        p = p->next;
    }
}


/* ====== PEGAWAI PER SHIFT ====== */
// Menampilkan pegawai yang bekerja pada shift tertentu
void tampilPegawaiPerShift(string namaShift) {
    Shift* s = cariShift(namaShift);
    if (s == NULL) return;

    cout << "Shift " << namaShift << ": ";
    Relasi* r = s->relasi;

    if (r == NULL) cout << "-";
    while (r != NULL) {
        cout << r->pegawai->nama << " ";
        r = r->nextShift;
    }
    cout << endl;
}


/* ====== SHIFT PER PEGAWAI ====== */
// Menampilkan shift yang dimiliki oleh pegawai tertentu
void tampilShiftPerPegawai(string namaPegawai) {
    Pegawai* p = cariPegawai(namaPegawai);
    if (p == NULL) return;

    cout << "Pegawai " << namaPegawai << ": ";
    Relasi* r = p->relasi;

    if (r == NULL) cout << "-";
    while (r != NULL) {
        cout << r->shift->nama << " ";
        r = r->nextPegawai;
    }
    cout << endl;
}


/* ====== TERBANYAK & TERSEDIKIT ====== */
// Menentukan pegawai dengan jumlah shift terbanyak dan tersedikit
void pegawaiTerbanyakTersedikit() {
    Pegawai* p = headPegawai;
    Pegawai* maxP = NULL;
    Pegawai* minP = NULL;

    int max = -1;
    int min = 999;

    while (p != NULL) {
        int jumlah = 0;
        Relasi* r = p->relasi;
        while (r != NULL) {
            jumlah++;
            r = r->nextPegawai;
        }

        if (jumlah > max) {
            max = jumlah;
            maxP = p;
        }
        if (jumlah < min) {
            min = jumlah;
            minP = p;
        }

        p = p->next;
    }

    if (maxP && minP) {
        cout << "Shift terbanyak  : " << maxP->nama << endl;
        cout << "Shift tersedikit : " << minP->nama << endl;
    }
}
