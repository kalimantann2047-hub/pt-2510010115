# P01 Program Pertama: Dari Python ke C++

Folder kode Pertemuan 1 Pemrograman Terstruktur. Buka folder ini di Visual Studio Code
(File, Open Folder) supaya pengaturan di `.vscode` ikut terpakai.

## Isi

| Berkas | Kegunaan |
|---|---|
| `hello.cpp` | Program pertama, sama dengan yang dibangun saat persiapan. Mencetak `Halo dari C++` |
| `versi.cpp` | Membuktikan compiler memakai C++20: mencetak `202002` |
| `rerata.py` | Versi Python program rata-rata tiga nilai, dijalankan dulu untuk tahu hasil yang benar |
| `rerata_awal.cpp` | Lab porting: lengkapi tiga TODO sampai keluarannya sama dengan versi Python |
| `kesalahan/k1_sintaks.cpp` | Contoh kesalahan sintaks: titik koma hilang, gagal compile |
| `kesalahan/k2_nama.cpp` | Contoh kesalahan compile: nama variabel salah ketik dan belum dideklarasikan |
| `kesalahan/k3_runtime.cpp` | Contoh kesalahan runtime: lolos compile, berhenti mendadak saat dibagi nol |
| `kesalahan/k4_logika.cpp` | Contoh kesalahan logika: berjalan mulus, hasilnya salah (pembagian bilangan bulat) |
| `.vscode/settings.json` | Terminal bawaan Git Bash dan tombol Code Runner dengan baseline kelas |
| `.vscode/tasks.json` | Tombol build Ctrl+Shift+B dengan baseline kelas untuk berkas yang sedang dibuka |
| `.gitignore` | Contoh: hasil build (`.exe`, `.o`) tidak ikut disimpan ke Git |
| `_kunci/` | Kunci lab porting, hanya untuk dosen. Tidak dibagikan ke mahasiswa |

## Membangun

Semua program dibangun dengan baseline kelas dari Git Bash, bukan PowerShell:

```
g++ -std=c++20 -Wall -Wextra -Wpedantic -g hello.cpp -o hello
./hello
```

Atau buka berkasnya di VS Code lalu tekan Ctrl+Shift+B (build saja) atau tombol Run Code
dari Code Runner (build lalu jalankan).

## Yang dikumpulkan mahasiswa

Folder `p01` di repository `pt-NPM` berisi `hello.cpp`, `rerata.cpp` hasil porting, dan
`catatan_kesalahan.md` (empat jenis kesalahan beserta pesan yang muncul). Lihat Modul Pertemuan 1
bagian E.
