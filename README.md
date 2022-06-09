# ObjProg

## Programos aprasymas

Programa sugeneruoja studentu namu darbus ir egzamino pazymius, juos nuskaito ir isveda galutinius pazymius. Taip pat galima naudoti jau sugeneruota faila.

Studentus padalija i dvi grupes: islaikiusius ir neislaikiusius. Rezultatai isvedami i faila. Programa raso kiek laiko uzeme skaitymas is failo ir studentu skirstymas i grupes.

## Programos spartumo analize

| Nuskaitymas | 1000        | 10000       | 100000      | 1000000     | 10000000    |
| ----------- | ----------- |------------ | ----------- | ----------- | ----------- |
| Deque       |  0.0096s    | 0.04023s    | 0.19s       | 1.6984s     | 19.2925s    |
| List        |  0.0096s    | 0.03601s    | 0.2928s     | 2.9071s     | 24.1068s    |
| Vector      |  0.0092s    | 0.0308s     | 0.2221s     | 1.8795s     | 18.3123s    |

| Dalijimas   | 1000        | 10000       | 100000      | 1000000     | 10000000    |
| ----------- | ----------- |------------ | ----------- | ----------- | ----------- |
| Deque       |  0.0013s    | 0.0159 s    | 0.2032s     | 2.8   s     | 32.9s       |
| List        |  0.0003s    | 0.0048 s    | 0.0515s     | 0.6135s     | 7.1953s     |
| Vector      |  0.0011s    | 0.0136s     | 0.2116s     | 2.7025s     | 26.9287s    |

## Sistemos parametrai

CPU: Intel(R) Core(TM) i5-8300H CPU @ 2.30GHz   2.30 GHz
RAM: 16GB DDR4
HDD: 256GB M.2 2280 NVMe SSD (WDC PC SN720 SDAPNTW-256G)

## Paleidimas

Aplankale vector, list arba deque komandinej eilutej parasyti:

1. "g++ -c mainvector.cpp"
2. "g++ -c studentasvector.cpp"
3. "g++ -c funkcijos.cpp"
4. "g++ -o ObjProgLab_V0.5.exe mainvector.o studentasvector.o funkcijos.o"
5. Paleisti ObjProg_Lab_V0.5.exe faila
