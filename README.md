# ObjProg

## Programos aprasymas

Programa sugeneruoja studentu namu darbus ir egzamino pazymius, juos nuskaito ir isveda galutinius pazymius. Taip pat galima naudoti jau sugeneruota faila.

Studentus padalija i dvi grupes: islaikiusius ir neislaikiusius. Rezultatai isvedami i faila. Programa raso kiek laiko uzeme skaitymas is failo ir studentu skirstymas i grupes.

Skirstymas realizuotas trijais budais su std::list, std::vector ir std::deque :

1. Bendro studentai konteinerio skaidymas i du naujus to paties tipo konteinerius
2. Bendro studentu konteinerio skaidymas panaudojant tik viena konteineri
3. Isrikiuojant studentu konteineri ir perkeliant neislaikiusius i kita konteineri, istrinant is studentu konteinerio (Mano sugalvotas budas is pradziu, surikiavus konteineri reikia pareiti tik apie puse studentu, tada prasideda islaikiusieji ir skaidyma galima stabdyti (Leciau veikia negu kiti, bet pazymiai buna isrikiuoti))

## Programos spartumo analize

| List        | 100000      | 1000000     | 10000000    |
| ----------- | ----------- | ----------- | ----------- |
| 1 budas     | 0.0355s       | 0.3584s     | 3.4389s    |
| 2 budas     | 0.0407s     | 0.4237s    | 4.0646s          |
| 3 budas     | 0.0518s     | 0.6475s    | 6.8626           |

| Deque       | 100000      | 1000000     | 10000000    |
| ----------- | ----------- | ----------- | ----------- |
| 1 budas     | 0.0238s      | 0.2088s     | 3.6714s    |
| 2 budas     | 0.0392s     | 0.3663s    |   5.1635s     |
| 3 budas     | 0.19s     | 2.8627s    |     32.0869        |

| Vector      | 100000      | 1000000     | 10000000    |
| ----------- | ----------- | ----------- | ----------- |
| 1 budas     | 0.0272s       | 0.3401s     | 2.7002s    |
| 2 budas     | 0.0237s    | 0.2690s   |    2.6788s         |
| 3 budas     | 0.22s     | 2.5484    |    26.5656s         |

## Sistemos parametrai

CPU: Intel(R) Core(TM) i5-8300H CPU @ 2.30GHz   2.30 GHz  

RAM: 16GB DDR4  

HDD: 256GB M.2 2280 NVMe SSD (WDC PC SN720 SDAPNTW-256G)  


## Paleidimas

Aplankale vector, list arba deque komandinej eilutej parasyti:

1. "cmake ."
2. "cmake build"
5. Paleisti Pazymiai.exe faila
