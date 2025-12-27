#include "pegawai.h"

/*INISIALISASI HEAD LIST*/
Pegawai* headPegawai = NULL;
Shift* headShift = NULL;

/*FUNGSI TAMBAH DATA*/

/* Menambahkan pegawai ke linked list */
void tambahPegawai(string nama) {
    Pegawai* p = new Pegawai;
    p->nama = nama;
    p->relasi = NULL;
    p->next = headPegawai;
    headPegawai = p;
}

/* Menambahkan shift ke linked list */
void tambahShift(string nama) {
    Shift* s = new Shift;
    s->nama = nama;
    s->relasi = NULL;
    s->next = headShift;
    headShift = s;
}

/*FUNGSI PENCARIAN*/

/* Cari pegawai berdasarkan nama */
Pegawai* cariPegawai(string nama) {
    Pegawai* p = headPegawai;
    while (p != NULL) {
        if (p->nama == nama)
            return p;
        p = p->next;
    }
    return NULL;
}

/* Cari shift berdasarkan nama */
Shift* cariShift(string nama) {
    Shift* s = headShift;
    while (s != NULL) {
        if (s->nama == nama)
            return s;
        s = s->next;
    }
    return NULL;
}

/*FUNGSI TAMBAH RELASI*/

/* Menghubungkan pegawai dengan shift (many-to-many) */
void tambahRelasi(string namaPegawai, string namaShift) {
    Pegawai* p = cariPegawai(namaPegawai);
    Shift* s = cariShift(namaShift);

    if (p == NULL || s == NULL) {
        cout << "Pegawai atau shift tidak ditemukan!\n";
        return;
    }

    Relasi* r = new Relasi;
    r->pegawai = p;
    r->shift = s;

    /* Hubungkan ke pegawai */
    r->nextPegawai = p->relasi;
    p->relasi = r;

    /* Hubungkan ke shift */
    r->nextShift = s->relasi;
    s->relasi = r;
}

/*FUNGSI HAPUS DATA*/

/* Menghapus pegawai beserta relasinya */
void hapusPegawai(string namaPegawai) {
    Pegawai *p = headPegawai, *prev = NULL;

    while (p != NULL && p->nama != namaPegawai) {
        prev = p;
        p = p->next;
    }

    if (p == NULL) {
        cout << "Pegawai tidak ditemukan!\n";
        return;
    }

    /* Hapus semua relasi */
    Relasi* r = p->relasi;
    while (r != NULL) {
        Relasi* temp = r;
        r = r->nextPegawai;
        delete temp;
    }

    /* Hapus dari list */
    if (prev == NULL)
        headPegawai = p->next;
    else
        prev->next = p->next;

    delete p;
}

/* Menghapus shift beserta relasinya */
void hapusShift(string namaShift) {
    Shift *s = headShift, *prev = NULL;

    while (s != NULL && s->nama != namaShift) {
        prev = s;
        s = s->next;
    }

    if (s == NULL) {
        cout << "Shift tidak ditemukan!\n";
        return;
    }

    /* Hapus semua relasi */
    Relasi* r = s->relasi;
    while (r != NULL) {
        Relasi* temp = r;
        r = r->nextShift;
        delete temp;
    }

    /* Hapus dari list */
    if (prev == NULL)
        headShift = s->next;
    else
        prev->next = s->next;

    delete s;
}

/*FUNGSI TAMPIL DATA*/

/* Menampilkan seluruh pegawai dan shift-nya */
void tampilSemua() {
    Pegawai* p = headPegawai;
    while (p != NULL) {
        cout << "Pegawai : " << p->nama << " | Shift : ";
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

/* Menampilkan pegawai berdasarkan shift */
void tampilPegawaiPerShift(string namaShift) {
    Shift* s = cariShift(namaShift);
    if (s == NULL) return;

    cout << "Shift " << namaShift << " diisi oleh : ";
    Relasi* r = s->relasi;

    if (r == NULL) cout << "-";
    while (r != NULL) {
        cout << r->pegawai->nama << " ";
        r = r->nextShift;
    }
    cout << endl;
}

/* Menampilkan shift berdasarkan pegawai */
void tampilShiftPerPegawai(string namaPegawai) {
    Pegawai* p = cariPegawai(namaPegawai);
    if (p == NULL) return;

    cout << "Pegawai " << namaPegawai << " bekerja pada shift : ";
    Relasi* r = p->relasi;

    if (r == NULL) cout << "-";
    while (r != NULL) {
        cout << r->shift->nama << " ";
        r = r->nextPegawai;
    }
    cout << endl;
}

/* Menentukan pegawai dengan shift terbanyak dan tersedikit */
void pegawaiTerbanyakTersedikit() {
    Pegawai *p = headPegawai, *maxP = NULL, *minP = NULL;
    int max = -1, min = 999;

    while (p != NULL) {
        int jumlah = 0;
        Relasi* r = p->relasi;
        while (r != NULL) {
            jumlah++;
            r = r->nextPegawai;
        }

        if (jumlah > max) { max = jumlah; maxP = p; }
        if (jumlah < min) { min = jumlah; minP = p; }

        p = p->next;
    }

    if (maxP && minP) {
        cout << "Pegawai shift terbanyak  : " << maxP->nama << endl;
        cout << "Pegawai shift tersedikit : " << minP->nama << endl;
    }
}
