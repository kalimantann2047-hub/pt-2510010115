# P05 Perulangan: for, while, do-while

Folder kode Pertemuan 5 Pemrograman Terstruktur. Setiap program punya flowchart pasangannya
di modul (Gambar 1 sampai 5); perhatikan panah yang kembali ke atas, itulah perulangan.

## Isi

| Berkas | Kegunaan |
|---|---|
| `for_hitung.cpp` | for dengan jumlah putaran yang diketahui; coba ubah `<=` menjadi `<` |
| `for_jumlah.cpp` | Pola akumulator: total dan rata-rata dari n nilai; coba masukkan 0 |
| `while_sentinel.cpp` | while dengan angka negatif sebagai tanda berhenti; jumlah putaran tidak diketahui |
| `do_while_menu.cpp` | do-while untuk menu yang diulang sampai pengguna memilih keluar; switch dari Pertemuan 4 |
| `sinilai_v04_awal.cpp` | Starter SiNilai v0.4: badan v0.3 sudah ada, lengkapi do-while, for, akumulator, dan rekap |
| `contoh_masukan.txt` | Tiga mahasiswa untuk menguji v0.4 |
| `.vscode/`, `.gitignore` | Sama dengan pertemuan sebelumnya |

## Kasus uji SiNilai v0.4 (`./sinilai_v04 < contoh_masukan.txt`)

| Mahasiswa | Komponen | Nilai akhir | Huruf | Status |
|---|---|---|---|---|
| Siti Aminah | 100, 85.5, 78, 80 | 83.975 | A | Lulus |
| Budi Santoso | 80, 70, 65, 60 | 67.75 | C+ | Lulus |
| Rina Wati | 60, 50, 40, 55 | 49.5 | D | Belum lulus |

Rekap kelas: 3 mahasiswa, 2 lulus, 1 belum lulus, rata-rata kelas 67.075.
Jumlah mahasiswa 0 atau negatif harus ditanya ulang (do-while).

## Kalau program berputar tanpa henti

Tekan `Ctrl+C` di terminal. Penyebab yang paling sering: lupa langkah (`i++`), syarat yang tidak
pernah salah, atau mengetik huruf saat program meminta angka (`cin` gagal dan nilai variabelnya
menjadi 0; obatnya dibahas di Pertemuan 7).

## Yang dikumpulkan mahasiswa

Folder `p05` di repository `pt-NPM` berisi `sinilai_v04.cpp`. Lihat Modul Pertemuan 5 bagian E.

## Deklarasi AI

saya menggunakan chhatgpt

promt:
// SiNilai v0.4: memproses banyak mahasiswa sekaligus dan mencetak rekap kelas.
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    const double BOBOT_KEHADIRAN = 0.10;
    const double BOBOT_MINGGUAN = 0.45;
    const double BOBOT_UTS = 0.25;
    const double BOBOT_UAS = 0.20;

    int jumlah_mahasiswa = 0;
    cout << "=== SiNilai v0.4 ===\n";

    do {
        cout << "Jumlah mahasiswa (paling sedikit 1): ";
        if (!(cin >> jumlah_mahasiswa)) {
            cerr << "Input jumlah mahasiswa harus berupa angka.\n";
            return 1;
        }
        if (jumlah_mahasiswa < 1) {
            cout << "Jumlah mahasiswa harus paling sedikit 1.\n";
        }
    } while (jumlah_mahasiswa < 1);

    // Dua akumulator untuk rekap kelas.
    double total_nilai = 0.0;
    int jumlah_lulus = 0;

    for (int i = 1; i <= jumlah_mahasiswa; i++) {
        string nama;
        string npm;
        double kehadiran = 0.0;
        double mingguan = 0.0;
        double uts = 0.0;
        double uas = 0.0;

        cout << "\n--- Mahasiswa ke-" << i << " dari "
             << jumlah_mahasiswa << " ---\n";
        cout << "Nama      : ";
        getline(cin >> ws, nama);
        cout << "NPM       : ";
        cin >> npm;
        cout << "Kehadiran : ";
        cin >> kehadiran;
        cout << "Mingguan  : ";
        cin >> mingguan;
        cout << "UTS       : ";
        cin >> uts;
        cout << "UAS       : ";
        cin >> uas;

        const double nilai_akhir =
            kehadiran * BOBOT_KEHADIRAN +
            mingguan * BOBOT_MINGGUAN +
            uts * BOBOT_UTS +
            uas * BOBOT_UAS;

        string huruf_mutu;
        if (nilai_akhir >= 80.0) {
            huruf_mutu = "A";
        } else if (nilai_akhir >= 75.0) {
            huruf_mutu = "B+";
        } else if (nilai_akhir >= 70.0) {
            huruf_mutu = "B";
        } else if (nilai_akhir >= 65.0) {
            huruf_mutu = "C+";
        } else if (nilai_akhir >= 60.0) {
            huruf_mutu = "C";
        } else if (nilai_akhir >= 40.0) {
            huruf_mutu = "D";
        } else {
            huruf_mutu = "E";
        }

        const bool lulus = nilai_akhir >= 60.0;

        string keterangan;
        switch (huruf_mutu[0]) {
            case 'A':
                keterangan = "Sangat baik";
                break;
            case 'B':
                keterangan = "Baik";
                break;
            case 'C':
                keterangan = "Cukup";
                break;
            case 'D':
                keterangan = "Kurang";
                break;
            default:
                keterangan = "Sangat kurang";
                break;
        }

        cout << fixed << setprecision(3);
        cout << "\n--- Kartu Nilai Mahasiswa ---\n";
        cout << "Nama        : " << nama << "\n";
        cout << "NPM         : " << npm << "\n";
        cout << "Nilai akhir : " << nilai_akhir << "\n";
        cout << "Huruf mutu  : " << huruf_mutu << "\n";
        cout << "Keterangan  : " << keterangan << "\n";
        cout << "Status      : " << (lulus ? "Lulus" : "Belum lulus") << "\n";

        // Akumulator untuk menghitung rata-rata dan jumlah mahasiswa lulus.
        total_nilai += nilai_akhir;
        if (lulus) {
            jumlah_lulus++;
        }
    }

    cout << "\n=== Rekap Kelas ===\n";
    cout << "Jumlah mahasiswa : " << jumlah_mahasiswa << "\n";
    cout << "Lulus            : " << jumlah_lulus << "\n";
    cout << "Belum lulus      : " << jumlah_mahasiswa - jumlah_lulus << "\n";
    cout << fixed << setprecision(3);
    cout << "Rata-rata kelas  : "
         << total_nilai / jumlah_mahasiswa << "\n";

    return 0;
}
apakah kode tersebut sudah sesuai TODO

respons:
Ya, kode yang kamu kirim sudah sesuai dengan 5 TODO pada tugas Pertemuan 5. Saya juga mengujinya menggunakan contoh_masukan.txt dari ZIP tugas, dan hasil rekapnya sesuai dengan README.
Pemeriksaan setiap TODO
TODO	Status	Penjelasan
1. do-while	Sesuai	Mengulang input jika jumlah mahasiswa kurang dari 1.
2. Dua akumulator	Sesuai	total_nilai dan jumlah_lulus sudah dideklarasikan sebelum for.
3. Perulangan for	Sesuai	Memproses mahasiswa dari urutan 1 sampai jumlah mahasiswa.
4. Akumulasi nilai	Sesuai	Menambahkan nilai akhir dan menghitung jumlah mahasiswa lulus.
5. Rekap kelas	Sesuai	Menampilkan jumlah mahasiswa, jumlah lulus, belum lulus, dan rata-rata.
Hasil pengujian
Program berhasil dikompilasi


Jumlah mahasiswa3

Lulus2

Belum lulus1

Rata-rata kelas67.075


Saran kecil
Ada dua hal yang perlu diperhatikan:
1. Validasi input: jika pengguna memasukkan huruf saat diminta jumlah mahasiswa, program berhenti. Ini tidak melanggar TODO, karena instruksi hanya mewajibkan pengulangan untuk jumlah nol atau negatif.
2. Deklarasi AI: README tugas meminta kamu mencantumkan alat AI yang digunakan, prompt, dan umpan balik AI. Jangan lupa melengkapi bagian tersebut sesuai proses pengerjaanmu.
Kesimpulan: kode kamu sudah memenuhi TODO 1–5 dan hasil pengujian sesuai. Kamu bisa menggunakan kode tersebut sebagai sinilai_v04.cpp untuk tugas ini.