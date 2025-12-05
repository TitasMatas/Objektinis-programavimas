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

## Spartos analizės rezultatai (list konteineris)

| Failas              | Nuskaitymas (s) | Rūšiavimas (s) | Įrašymas (s) | Bendras laikas (s) |
| ------------------- | --------------- | -------------- | ------------ | ------------------ |
| studentai10.txt     | 0.000421        | 0.015190       | 0.003641     | 0.023598           |
| studentai100.txt    | 0.001104        | 0.000088       | 0.005448     | 0.009962           |
| studentai1000.txt   | 0.007286        | 0.000833       | 0.026106     | 0.039963           |
| studentai10000.txt  | 0.129223        | 0.003643       | 0.232335     | 0.368637           |
| studentai100000.txt | 1.212290        | 0.052461       | 2.137380     | 3.407940           |

## Pastabos
- Naudojama `setlocale(LC_ALL, "")` dėl lietuviškų simbolių.


---

## Testavimo sistemos parametrai

| Parametras        | Reikšmė |
|------------------|----------|
| CPU               | 11th Gen Intel(R) Core(TM) i5-1145G7 @ 2.60GHz |
| RAM               | 16 GB DDR4 |
| HDD / SSD         | NVMe SSD (model not specified) |
| OS                | Windows 11 Enterprise x64 (Build 22631.6199) |
