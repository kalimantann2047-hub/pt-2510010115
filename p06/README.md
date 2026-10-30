# P06 Perulangan Lanjutan: Bersarang, break, continue, Debugger, iomanip

Folder kode Pertemuan 6 Pemrograman Terstruktur. Setiap program berpasangan dengan flowchart di modul;
pada perulangan bersarang ada dua panah yang kembali, dan pada break/continue ada panah yang
"memotong jalan".

## Isi

| Berkas | Kegunaan |
|---|---|
| `bersarang_tabel.cpp` | for di dalam for: tabel perkalian dengan kolom lurus (setw) |
| `break_tebak.cpp` | break: berhenti lebih awal begitu tebakan benar, paling banyak 5 kesempatan |
| `continue_remediasi.cpp` | continue: lewati mahasiswa yang nilainya cukup, daftar hanya yang perlu remediasi |
| `rapi_iomanip.cpp` | fixed, setprecision, setw, left, right: keluaran berkolom rapi |
| `debug_rerata.cpp` | Program dengan kesalahan logika yang sengaja ditanam; dicari dengan debugger, bukan dibaca |
| `masukan_debug.txt` | Masukan untuk `debug_rerata`: 3 nilai (80, 70, 90), rata-rata yang benar 80 |
| `sinilai_v05_awal.cpp` | Starter SiNilai v0.5: v0.4 lengkap, lengkapi iomanip, penghitung huruf, tertinggi, sebaran batang |
| `contoh_masukan.txt` | Enam mahasiswa untuk menguji v0.5 |
| `.vscode/launch.json` | Konfigurasi debugger VS Code (gdb MSYS2); tekan F5 pada berkas .cpp yang terbuka |
| `.vscode/settings.json`, `tasks.json`, `.gitignore` | Sama dengan pertemuan sebelumnya |

## Kasus uji SiNilai v0.5 (`./sinilai_v05 < contoh_masukan.txt`)

| Mahasiswa | Komponen | Nilai akhir (2 desimal) | Huruf | Status |
|---|---|---|---|---|
| Siti Aminah | 100, 85.5, 78, 80 | 83.97 | A | Lulus |
| Budi Santoso | 80, 70, 65, 60 | 67.75 | C+ | Lulus |
| Rina Wati | 60, 50, 40, 55 | 49.50 | D | Belum lulus |
| Dewi Lestari | 90, 90, 90, 90 | 90.00 | A | Lulus |
| Eko Prasetyo | 75, 72, 70, 68 | 71.00 | B | Lulus |
| Fajar Nugroho | 30, 20, 35, 25 | 25.75 | E | Belum lulus |

Laporan kelas: 6 mahasiswa, 4 lulus, 2 belum lulus, rata-rata 64.66, tertinggi Dewi Lestari (90.00).
Sebaran huruf: A 2, B 1, C 1, D 1, E 1 (B+ dihitung sebagai B, C+ sebagai C).

Catatan: 83.975 tampil sebagai 83.97, bukan 83.98, karena di dalam komputer 83.975 tersimpan
sebagai 83.97499...; pembulatan mengikuti angka yang tersimpan.

## Debugger

`launch.json` memakai `C:/msys64/ucrt64/bin/gdb.exe` dan program `<nama>.exe` hasil tasks.json.
Di Linux hapus akhiran `.exe` dan ganti `miDebuggerPath` menjadi `/usr/bin/gdb`; di macOS ganti
`MIMode` menjadi `lldb` dan hapus `miDebuggerPath`. Panduan lengkap: `03_Modul/Panduan_Debugger_VS_Code.docx`.

## Yang dikumpulkan mahasiswa

Folder `p06` di repository `pt-NPM` berisi `sinilai_v05.cpp`. Lihat Modul Pertemuan 6 bagian E.

## Deklarasi AI

**Label AI 1**

Saya menggunakan claude Ai
Dengan promt
```cpp
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    const double BOBOT_KEHADIRAN = 0.10;
    const double BOBOT_MINGGUAN = 0.45;
    const double BOBOT_UTS = 0.25;
    const double BOBOT_UAS = 0.20;

    int jumlah_mahasiswa = 0;
    cout << "=== SiNilai v0.5 ===\n";
    do {
        cout << "Jumlah mahasiswa (paling sedikit 1): ";
        cin >> jumlah_mahasiswa;
    } while (jumlah_mahasiswa < 1);

    cout << fixed << setprecision(2);

    double total_nilai = 0;
    int jumlah_lulus = 0;
    int jumlah_a = 0;
    int jumlah_b = 0;
    int jumlah_c = 0;
    int jumlah_d = 0;
    int jumlah_e = 0;
    double nilai_tertinggi = -1;
    string nama_tertinggi;

    for (int i = 1; i <= jumlah_mahasiswa; i++) {
        string nama;
        string npm;
        double kehadiran = 0;
        double mingguan = 0;
        double uts = 0;
        double uas = 0;

        cout << "\n--- Mahasiswa ke-" << i << " dari " << jumlah_mahasiswa << " ---\n";
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

        double nilai_akhir = kehadiran * BOBOT_KEHADIRAN + mingguan * BOBOT_MINGGUAN
                           + uts * BOBOT_UTS + uas * BOBOT_UAS;

        string huruf_mutu;
        if (nilai_akhir >= 80) {
            huruf_mutu = "A";
        } else if (nilai_akhir >= 75) {
            huruf_mutu = "B+";
        } else if (nilai_akhir >= 70) {
            huruf_mutu = "B";
        } else if (nilai_akhir >= 65) {
            huruf_mutu = "C+";
        } else if (nilai_akhir >= 60) {
            huruf_mutu = "C";
        } else if (nilai_akhir >= 40) {
            huruf_mutu = "D";
        } else {
            huruf_mutu = "E";
        }

        bool lulus = nilai_akhir >= 60;

        cout << "  " << left << setw(20) << nama << right << setw(7) << nilai_akhir
             << "  " << left << setw(3) << huruf_mutu << (lulus ? "Lulus" : "Belum lulus") << "\n";

        total_nilai += nilai_akhir;
        if (lulus) {
            jumlah_lulus++;
        }

        // B+ dan B sama-sama masuk hitungan B; C+ dan C masuk hitungan C.
        switch (huruf_mutu[0]) {
            case 'A':
                jumlah_a++;
                break;
            case 'B':
                jumlah_b++;
                break;
            case 'C':
                jumlah_c++;
                break;
            case 'D':
                jumlah_d++;
                break;
            default:
                jumlah_e++;
        }

        if (nilai_akhir > nilai_tertinggi) {
            nilai_tertinggi = nilai_akhir;
            nama_tertinggi = nama;
        }
    }

    cout << "\n=== Laporan Kelas ===\n";
    cout << "Jumlah mahasiswa : " << jumlah_mahasiswa << "\n";
    cout << "Lulus            : " << jumlah_lulus << "\n";
    cout << "Belum lulus      : " << jumlah_mahasiswa - jumlah_lulus << "\n";
    cout << "Rata-rata kelas  : " << total_nilai / jumlah_mahasiswa << "\n";
    cout << "Tertinggi        : " << nama_tertinggi << " (" << nilai_tertinggi << ")\n";

    cout << "\nSebaran huruf mutu:\n";
    for (char huruf = 'A'; huruf <= 'E'; huruf++) {
        int banyak = 0;
        if (huruf == 'A') {
            banyak = jumlah_a;
        } else if (huruf == 'B') {
            banyak = jumlah_b;
        } else if (huruf == 'C') {
            banyak = jumlah_c;
        } else if (huruf == 'D') {
            banyak = jumlah_d;
        } else {
            banyak = jumlah_e;
        }

        cout << huruf << " | ";
        for (int k = 0; k < banyak; k++) {
            cout << '#';
        }
        cout << " " << banyak << "\n";
    }
    return 0;
}

```
apakah code ini sdh sesuai TODO

dan respons:
Ya, kode itu sudah sesuai semua TODO, dan sama persis dengan `sinilai_v05.cpp` yang saya buat. Saya sudah mengompilasi dan menjalankannya, hasilnya cocok dengan tabel di README.

| TODO | Syarat | Di kodemu |
|---|---|---|
| 1 | Dua angka di belakang koma | `cout << fixed << setprecision(2);` |
| 2 | Lima penghitung `int` mulai 0 | `jumlah_a` sampai `jumlah_e` |
| 3 | `nilai_tertinggi = -1` dan `nama_tertinggi` | Ada, dideklarasikan sebelum perulangan |
| 4 | Satu baris berkolom | Dua spasi, nama `left` `setw(20)`, nilai `right` `setw(7)`, dua spasi, huruf `left` `setw(3)`, lalu Lulus atau Belum lulus |
| 5 | `switch` pada `huruf_mutu[0]` | Ada. B+ dan B masuk hitungan B, C+ dan C masuk hitungan C, `default` ke E |
| 6 | Perbarui mahasiswa tertinggi | `if (nilai_akhir > nilai_tertinggi)` |
| 7 | Cetak `Tertinggi : nama (nilai)` | Ada, format sesuai |
| 8 | if-else bertingkat pada `huruf` | Ada |
| 9 | Perulangan dalam untuk `#` | `for (int k = 0; k < banyak; k++)` |

Perulangan bersarang ada di bagian sebaran: `for huruf` di luar dan `for k` di dalam.

Dosenmu mungkin memeriksa dua hal, jadi pastikan kamu bisa menjelaskannya:
- **`switch` dan `break`:** `default` tidak memakai `break` karena sudah berada di akhir.
- **83.97, bukan 83.98:** ini sudah dijelaskan di catatan README.

