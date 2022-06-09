# ObjProg

## Programos aprasymas

Programa sugeneruoja studentu namu darbus ir egzamino pazymius, juos nuskaito ir isveda galutinius pazymius. Taip pat galima naudoti jau sugeneruota faila.

Studentus padalija i dvi grupes: islaikiusius ir neislaikiusius. Rezultatai isvedami i faila. Programa raso kiek laiko uzeme skaitymas is failo ir studentu skirstymas i grupes.

## Programos spartumo analize

Panaudota V1.0 versijos vector programa su 3 rusiavimo budu (Aprasa galima rasti V1.0 branch'e)  

|             | 1000000     | 10000000    |
| ----------- | ----------- | ----------- |
| V1.0 vector | 0.22s       | 2.5484s     |
| Class       | 0.4436s     | 5.1748s     |
| -O1 class   | 0.4059s     | 4.344s      |
| -O2 class   | 0.3722s     | 4.3409      |
| -O3 class   | 0.3498s     | 4.4041      |


## Sistemos parametrai

CPU: Intel(R) Core(TM) i5-8300H CPU @ 2.30GHz   2.30 GHz  

RAM: 16GB DDR4  

HDD: 256GB M.2 2280 NVMe SSD (WDC PC SN720 SDAPNTW-256G)  


## Paleidimas

Komandineje eiluteje parasyti:

1. "cmake ."
2. "cmake build"
5. Paleisti Pazymiai.exe faila
