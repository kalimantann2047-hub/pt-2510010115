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
| `sinilai_v03.cpp` | Program SiNilai v0.3 yang menghitung huruf mutu, keterangan, dan status |
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

Tuliskan AI yang digunakan, prompt, dan umpan balik AI

## Deklarasi Penggunaan AI

- saya menggunakan chat gpt dengan promt:
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    const double BOBOT_KEHADIRAN = 0.10;
    const double BOBOT_MINGGUAN = 0.45;
    const double BOBOT_UTS = 0.25;
    const double BOBOT_UAS = 0.20;

    int jumlah_mahasiswa;

    cout << "=== SiNilai v0.4 ===\n";

    do {
        cout << "Masukkan jumlah mahasiswa: ";
        cin >> jumlah_mahasiswa;

        if (jumlah_mahasiswa < 1) {
            cout << "Jumlah mahasiswa minimal 1!\n";
        }
    } while (jumlah_mahasiswa < 1);

    double total_nilai = 0;
    int jumlah_lulus = 0;

    for (int i = 1; i <= jumlah_mahasiswa; i++) {
        string nama, npm;
        double kehadiran, mingguan, uts, uas;

        cout << "\nMahasiswa ke-" << i << "\n";

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

        double nilai_akhir =
            kehadiran * BOBOT_KEHADIRAN +
            mingguan * BOBOT_MINGGUAN +
            uts * BOBOT_UTS +
            uas * BOBOT_UAS;

        string huruf_mutu;

        if (nilai_akhir >= 80)
            huruf_mutu = "A";
        else if (nilai_akhir >= 75)
            huruf_mutu = "B+";
        else if (nilai_akhir >= 70)
            huruf_mutu = "B";
        else if (nilai_akhir >= 65)
            huruf_mutu = "C+";
        else if (nilai_akhir >= 60)
            huruf_mutu = "C";
        else if (nilai_akhir >= 40)
            huruf_mutu = "D";
        else
            huruf_mutu = "E";

        bool lulus = nilai_akhir >= 60;
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
        }

        cout << fixed << setprecision(2);
        cout << "\n=== Kartu Nilai ===\n";
        cout << "Nama        : " << nama << "\n";
        cout << "NPM         : " << npm << "\n";
        cout << "Nilai akhir : " << nilai_akhir << "\n";
        cout << "Huruf mutu  : " << huruf_mutu << "\n";
        cout << "Keterangan  : " << keterangan << "\n";

        if (lulus) {
            cout << "Status      : Lulus\n";
            jumlah_lulus++;
        } else {
            cout << "Status      : Belum lulus\n";
        }

        total_nilai += nilai_akhir;
    }

    double rata_rata = total_nilai / jumlah_mahasiswa;

    cout << "\n=== Rekap Kelas ===\n";
    cout << "Jumlah mahasiswa : " << jumlah_mahasiswa << "\n";
    cout << "Lulus            : " << jumlah_lulus << "\n";
    cout << "Belum lulus      : "
         << jumlah_mahasiswa - jumlah_lulus << "\n";
    cout << "Rata-rata kelas  : " << rata_rata << "\n";

    return 0;
}
apakan codingan ini sesuai dengan TODO

respons chat gpt :
Ya, codingan kamu sudah sesuai dengan TODO 1 sampai TODO 5 pada kode SiNilai v0.4. Ada sedikit perbedaan tampilan, tetapi inti programnya tetap sama.

Berikut pemeriksaannya:

| TODO   | Keterangan                                                                          | Status   |
| ------ | ----------------------------------------------------------------------------------- | -------- |
| TODO 1 | Menggunakan `do-while` untuk memastikan jumlah mahasiswa minimal 1                  | ✅ Sesuai |
| TODO 2 | Membuat `total_nilai` dan `jumlah_lulus` sebelum perulangan                         | ✅ Sesuai |
| TODO 3 | Menggunakan `for` dari mahasiswa ke-1 sampai jumlah mahasiswa                       | ✅ Sesuai |
| TODO 4 | Menambahkan nilai akhir ke `total_nilai` dan menghitung jumlah mahasiswa yang lulus | ✅ Sesuai |
| TODO 5 | Menampilkan rekap kelas dan rata-rata nilai                                         | ✅ Sesuai |

### Catatan kecil

1. TODO 1: Kode kamu sudah menggunakan `do-while`. Namun, jika pengguna memasukkan huruf, program belum menangani kesalahan input tersebut. Untuk tugas dasar ini, biasanya tidak masalah jika input yang dimasukkan berupa angka.
2. TODO 4: Baris `jumlah_lulus++;` sudah berada di dalam kondisi `if (lulus)`, sedangkan `total_nilai += nilai_akhir;` berada setelah pemeriksaan kelulusan. Jadi, keduanya tidak dihitung secara ganda.
3. TODO 5: Penggunaan `setprecision(2)` membuat nilai ditampilkan dengan dua angka desimal. Ini merupakan tambahan tampilan dan tidak mengubah rumus nilai.

Kesimpulan: Kode kamu sudah memenuhi kelima TODO dan bisa digunakan untuk tugas SiNilai v0.4. Tidak perlu mengubah inti programnya lagi.