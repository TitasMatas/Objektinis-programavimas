# Studentų pažymių valdymo sistema ir spartos analizė

## Aprašymas
Programa skirta:
- Įvesti studentų duomenis (rankiniu būdu, atsitiktinai arba iš failo)
- Apskaičiuoti galutinį pažymį pagal vidurkį ir medianą
- Suskirstyti studentus į dvi kategorijas:
  - **Protingi** (galutinis vidurkis ≥ 5.0)
  - **Ne tokie protingi** (galutinis vidurkis < 5.0)
- Išvesti rezultatus į failus
- Atlikti **spartos analizę** su skirtingais duomenų kiekiais

## Projekto struktūra
- `main.cpp` – pagrindinė programos logika
- `functions.cpp` – funkcijų realizacija
- `functions.h` – funkcijų deklaracijos
- `student.h` – struktūra `Student`
- Testiniai failai:
  - `studentai10.txt`
  - `studentai100.txt`
  - `studentai1000.txt`
  - `studentai10000.txt`
  - `studentai100000.txt`

## Kaip kompiliuoti
```bash
g++ main.cpp functions.cpp -o programa.exe
```

## Kaip paleisti
```bash
./programa.exe
```

Programa automatiškai testuoja visus 5 failus ir išveda laikus kiekvienam žingsniui.

---

## Spartos analizės rezultatai

| Failas              | Nuskaitymas (s) | Rūšiavimas (s) | Įrašymas (s) | Bendras laikas (s) |
|----------------------|-----------------|-----------------|--------------|----------------------|
| studentai10.txt      | 0.000387       | 0.0000041       | 0.0032546    | 0.0062417           |
| studentai100.txt     | 0.0006264      | 0.0000286       | 0.0036587    | 0.0066728           |
| studentai1000.txt    | 0.0047477      | 0.0002817       | 0.0215964    | 0.0291042           |
| studentai10000.txt   | 0.0471313      | 0.0031111       | 0.194292     | 0.249615            |
| studentai100000.txt  | 0.539877       | 0.0297988       | 1.53576      | 2.11343             |

## Pastabos
- Naudojama `setlocale(LC_ALL, "")` dėl lietuviškų simbolių.
