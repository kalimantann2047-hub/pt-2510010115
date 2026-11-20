// SiNilai v0.7: SiNilai v0.6 yang dipisah menjadi sembilan fungsi, masing-masing satu tugas.
// Prinsip: hasil tunggal lewat return, hasil banyak lewat referensi, dan tanpa variabel global.
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Konstanta (bukan variabel) boleh dibaca semua fungsi karena nilainya tetap.
const double BOBOT_HADIR = 0.10;
const double BOBOT_TUGAS = 0.45;
const double BOBOT_TENGAH = 0.25;
const double BOBOT_AKHIR = 0.20;

int bacaJumlah();
string bacaNama();
double bacaKomponen(string label);
void bacaData(string& nama, string& npm, double& kehadiran, double& mingguan, double& uts, double& uas);
double hitungNilaiAkhir(double kehadiran, double mingguan, double uts, double uas);
string hurufMutu(double nilai_akhir);
void cetakBaris(string nama, double nilai_akhir, string huruf, bool lulus);
void perbaruiPenghitung(char awal, int& a, int& b, int& c, int& d, int& e);
void cetakSebaran(int a, int b, int c, int d, int e);

int main() {
    cout << "=== SiNilai " << "v0.7 ===\n";
    const int populasi = bacaJumlah();
    cout << fixed << setprecision(2);

    // Penghitung disimpan di main; fungsi lain hanya menerimanya lewat parameter.
    double jumlah_skor = 0;
    int belum_lulus = 0;
    int cnt_a = 0, cnt_b = 0, cnt_c = 0, cnt_d = 0, cnt_e = 0;
    double skor_teratas = -1;
    string nama_teratas;

    for (int ke = 1; ke <= populasi; ++ke) {
        string nama, npm;
        double hadir = 0, tugas = 0, tengah = 0, akhir = 0;

        cout << "\n--- Mahasiswa ke-" << ke << " dari " << populasi << " ---\n";
        bacaData(nama, npm, hadir, tugas, tengah, akhir);

        const double skor = hitungNilaiAkhir(hadir, tugas, tengah, akhir);
        const string mutu = hurufMutu(skor);
        const bool lulus = skor >= 60;
        cetakBaris(nama, skor, mutu, lulus);

        jumlah_skor += skor;
        if (!lulus) {
            ++belum_lulus;
        }
        perbaruiPenghitung(mutu[0], cnt_a, cnt_b, cnt_c, cnt_d, cnt_e);
        if (skor > skor_teratas) {
            skor_teratas = skor;
            nama_teratas = nama;
        }
    }

    const int lulus_total = populasi - belum_lulus;
    cout << "\n=== Laporan Kelas ===\n";
    cout << "Jumlah mahasiswa : " << populasi << "\n";
    cout << "Lulus            : " << lulus_total << "\n";
    cout << "Belum lulus      : " << belum_lulus << "\n";
    cout << "Rata-rata kelas  : " << jumlah_skor / populasi << "\n";
    cout << "Tertinggi        : " << nama_teratas << " (" << skor_teratas << ")\n";
    cetakSebaran(cnt_a, cnt_b, cnt_c, cnt_d, cnt_e);
    return 0;
}

// Jumlah mahasiswa: bilangan bulat >= 1, diulang sampai sah.
int bacaJumlah() {
    int n = 0;
    cout << "Jumlah mahasiswa (paling sedikit 1): ";
    cin >> n;
    while (cin.fail() || n <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Harus bilangan bulat paling sedikit 1. Coba lagi: ";
        cin >> n;
    }
    cin.ignore(1000, '\n');
    return n;
}

// Nama tidak boleh kosong atau mengandung angka; hasil dirapikan per kata.
string bacaNama() {
    // Lambda lokal (bukan fungsi baru): memeriksa apakah ada karakter yang memenuhi syarat.
    auto ada = [](const string& s, bool (*uji)(char)) {
        for (char ch : s) {
            if (uji(ch)) {
                return true;
            }
        }
        return false;
    };
    auto bukan_spasi = [](char ch) { return ch != ' '; };
    auto angka = [](char ch) { return isdigit(ch) != 0; };

    string teks;
    bool lanjut = true;
    while (lanjut) {
        cout << "Nama      : ";
        getline(cin, teks);
        if (!ada(teks, bukan_spasi)) {
            cout << "Nama tidak boleh kosong.\n";
        } else if (ada(teks, angka)) {
            cout << "Nama tidak boleh mengandung angka.\n";
        } else {
            lanjut = false;
        }
    }

    char sebelumnya = ' ';
    for (char& ch : teks) {
        const char asli = ch;
        if (asli != ' ') {
            ch = (sebelumnya == ' ') ? toupper(asli) : tolower(asli);
        }
        sebelumnya = asli;
    }
    return teks;
}

// Satu pembaca untuk semua komponen; label menentukan teks yang tampil.
double bacaKomponen(string label) {
    auto di_luar_rentang = [](double x) { return x < 0 || x > 100; };

    double nilai = 0;
    cout << label << " : ";
    cin >> nilai;
    while (cin.fail() || di_luar_rentang(nilai)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Harus angka 0 sampai 100. " << label << " : ";
        cin >> nilai;
    }
    return nilai;
}

// Referensi: enam variabel milik main diisi dari sini, jadi tidak perlu return.
void bacaData(string& nama, string& npm, double& kehadiran, double& mingguan, double& uts, double& uas) {
    nama = bacaNama();
    cout << "NPM       : ";
    getline(cin, npm);
    kehadiran = bacaKomponen("Kehadiran ");
    mingguan = bacaKomponen("Mingguan  ");
    uts = bacaKomponen("UTS       ");
    uas = bacaKomponen("UAS       ");
    cin.ignore(1000, '\n');
}

double hitungNilaiAkhir(double kehadiran, double mingguan, double uts, double uas) {
    double jumlah = kehadiran * BOBOT_HADIR;
    jumlah = jumlah + mingguan * BOBOT_TUGAS;
    jumlah = jumlah + uts * BOBOT_TENGAH;
    jumlah = jumlah + uas * BOBOT_AKHIR;
    return jumlah;
}

// Nilai lulus (>= 60) diperiksa dengan if bertingkat; di bawah 60 dengan ekspresi kondisi.
string hurufMutu(double nilai_akhir) {
    if (nilai_akhir >= 60) {
        if (nilai_akhir >= 85) {
            return "A";
        } else if (nilai_akhir >= 80) {
            return "B+";
        } else if (nilai_akhir >= 75) {
            return "B";
        } else if (nilai_akhir >= 70) {
            return "C+";
        }
        return "C";
    }
    return (nilai_akhir >= 50) ? "D" : "E";
}

void cetakBaris(string nama, double nilai_akhir, string huruf, bool lulus) {
    cout << "  " << left << setw(20) << nama;
    cout << right << setw(7) << nilai_akhir;
    cout << "  " << left << setw(3) << huruf;
    cout << (lulus ? "Lulus\n" : "Belum lulus\n");
}

// Pilih penghitung dari urutan A..D lewat indeks; selain itu (E) masuk ke e.
void perbaruiPenghitung(char awal, int& a, int& b, int& c, int& d, int& e) {
    int* const kotak[4] = {&a, &b, &c, &d};
    int indeks = awal - 'A';
    if (indeks >= 0 && indeks < 4) {
        *kotak[indeks] += 1;
    } else {
        e += 1;
    }
}

// Semua parameter pass by value: fungsi ini hanya mencetak.
void cetakSebaran(int a, int b, int c, int d, int e) {
    auto batang = [](int n) { return string(n, '#'); };

    cout << "Sebaran huruf mutu:\n";
    cout << "  A : " << batang(a) << " (" << a << ")\n";
    cout << "  B : " << batang(b) << " (" << b << ")\n";
    cout << "  C : " << batang(c) << " (" << c << ")\n";
    cout << "  D : " << batang(d) << " (" << d << ")\n";
    cout << "  E : " << batang(e) << " (" << e << ")\n";
}
