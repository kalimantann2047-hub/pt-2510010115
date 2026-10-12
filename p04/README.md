# P04 Percabangan: if, if-else, switch, dan Operator Logika

Folder kode Pertemuan 4 Pemrograman Terstruktur. Setiap program di sini punya flowchart pasangannya
di modul (Gambar 2 sampai 7); baca gambarnya dulu, baru kodenya.

## Isi

| Berkas | Kegunaan |
|---|---|
| `if_dasar.cpp` | if satu cabang: peringatan bila nilai di bawah 60 |
| `if_else.cpp` | if-else: lulus atau belum lulus |
| `bertingkat.cpp` | if-else bertingkat tiga syarat; coba tukar urutannya |
| `logika.cpp` | `&&`, `||`, `!` dengan bool bernama; syarat ikut UAS |
| `switch_menu.cpp` | switch dengan break dan default; coba hapus break-nya |
| `sinilai_v03_awal.cpp` | Starter SiNilai v0.3: bagian v0.2 sudah jadi, lengkapi huruf mutu, status, keterangan |
| `contoh_masukan.txt` | Masukan uji yang sama dengan pertemuan sebelumnya |
| `.vscode/`, `.gitignore` | Sama dengan pertemuan sebelumnya |

## Kasus uji SiNilai v0.3

| Empat komponen | Nilai akhir | Huruf | Keterangan | Status |
|---|---|---|---|---|
| contoh_masukan.txt | 83.975 | A | Sangat baik | Lulus |
| 80 x4 | 80 | A | Sangat baik | Lulus |
| 79.9 x4 | 79.9 | B+ | Baik | Lulus |
| 60 x4 | 60 | C | Cukup | Lulus |
| 59.9 x4 | 59.9 | D | Kurang | Belum lulus |
| 30 x4 | 30 | E | Sangat kurang | Belum lulus |

## Yang dikumpulkan mahasiswa

Folder `p04` di repository `pt-NPM` berisi `sinilai_v03.cpp` dan  `README.md`. Lihat Modul Pertemuan 4 bagian E.

## Deklarasi AI

**Deklarasi Penggunaan AI**
saya menggunakan chat gpt

promt=
// SiNilai v0.3: nilai akhir diubah menjadi huruf mutu dan keterangan kelulusan.
// Dibangun di atas v0.2. Tabel konversi mengikuti peraturan akademik (lihat kontrak kuliah):
//   80-100 A | 75-79,9 B+ | 70-74,9 B | 65-69,9 C+ | 60-64,9 C | 40-59,9 D | 0-39,9 E
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    const double BOBOT_KEHADIRAN = 0.10;
    const double BOBOT_MINGGUAN = 0.45;
    const double BOBOT_UTS = 0.25;
    const double BOBOT_UAS = 0.20;

    string nama, npm;
    double kehadiran = 0.0, mingguan = 0.0;
    double uts = 0.0, uas = 0.0;
    string huruf_mutu;
    bool lulus = false;
    string keterangan;

    cout << "=== SiNilai v0.3 ===\n";
    cout << "Nama      : ";
    getline(cin, nama);

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

    double nilai_akhir = (kehadiran * BOBOT_KEHADIRAN)
                       + (mingguan * BOBOT_MINGGUAN)
                       + (uts * BOBOT_UTS)
                       + (uas * BOBOT_UAS);

    // TODO 1: deklarasikan string huruf_mutu, lalu isi dengan if-else bertingkat sesuai tabel di atas.
    //         Mulai dari batas tertinggi (80) turun ke bawah. Pikirkan kasus batas: 79.9, 80, 59.9, 60.
    if (nilai_akhir < 40)
        huruf_mutu = "E";
    else if (nilai_akhir < 60)
        huruf_mutu = "D";
    else if (nilai_akhir < 65)
        huruf_mutu = "C";
    else if (nilai_akhir < 70)
        huruf_mutu = "C+";
    else if (nilai_akhir < 75)
        huruf_mutu = "B";
    else if (nilai_akhir < 80)
        huruf_mutu = "B+";
    else
        huruf_mutu = "A";

    // TODO 2: deklarasikan bool lulus. Aturan SiNilai: lulus bila huruf mutu minimal C
    //         (dengan kata lain, nilai_akhir >= 60).
    lulus = (nilai_akhir >= 60);

    // TODO 3: deklarasikan string keterangan. Isi dengan switch pada huruf pertama huruf_mutu
    //         (huruf_mutu[0] bertipe char): 'A' Sangat baik, 'B' Baik, 'C' Cukup,
    //         'D' Kurang, 'E' Sangat kurang. Ingat break.
    switch (huruf_mutu.at(0))
    {
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
        case 'E':
            keterangan = "Sangat kurang";
            break;
        default:
            keterangan = "Tidak diketahui";
            break;
    }

    cout << "\n--- Kartu Nilai Mahasiswa ---\n";
    cout << "Nama        : " << nama << '\n';
    cout << "NPM         : " << npm << '\n';
    cout << fixed << setprecision(2);
    cout << "Nilai akhir : " << nilai_akhir << '\n';

    // TODO 4: tampilkan Huruf mutu, Keterangan, dan Status (Lulus / Belum lulus) sejajar.
    cout << left;
    cout << setw(14) << "Huruf mutu"
         << setw(20) << "Keterangan"
         << "Status\n";

    cout << setw(14) << huruf_mutu
         << setw(20) << keterangan
         << (lulus ? "Lulus" : "Belum lulus") << '\n';

    return 0;
}
apakah codingan saya sudah sesuai dengan to do


repons=
Ya, codingan kamu sudah sesuai dengan keempat TODO. Logika percabangan, kelulusan, dan keterangan sudah benar.

Berikut pemeriksaannya:

| TODO   | Status   | Penjelasan                                                                    |
| ------ | -------- | ----------------------------------------------------------------------------- |
| TODO 1 | ✅ Sesuai | `if-else` mengonversi nilai akhir menjadi huruf mutu sesuai tabel.            |
| TODO 2 | ✅ Sesuai | `lulus = (nilai_akhir >= 60);` berarti nilai minimal 60 dinyatakan lulus.     |
| TODO 3 | ✅ Sesuai | `switch` membaca huruf pertama `huruf_mutu` dan menentukan keterangan.        |
| TODO 4 | ✅ Sesuai | `setw()` dan `left` membuat kolom huruf mutu, keterangan, dan status sejajar. |

### Catatan penting

1. Konversi nilai sudah benar. Contohnya, nilai 59,9 mendapat D dan nilai 60 mendapat C.
2. Penggunaan `switch` sudah tepat. Huruf `B` mencakup B dan B+, sedangkan huruf `C` mencakup C dan C+.
3. Deklarasi variabel tidak perlu ditambahkan lagi. `huruf_mutu`, `lulus`, dan `keterangan` sudah dideklarasikan di bagian atas program.

### Kesimpulan

Codingan kamu sudah memenuhi TODO 1–4 dan tidak perlu diperbaiki lagi dari sisi logika. Kamu tinggal menjalankan program dan menguji beberapa nilai batas, seperti 39,9; 40; 59,9; 60; 79,9; dan 80 untuk memastikan hasilnya sesuai.