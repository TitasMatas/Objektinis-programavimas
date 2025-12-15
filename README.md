# Studentų pažymių valdymo sistema ir spartos analizė

## Aprašymas
Programa skirta:
- Įvesti studentų duomenis (rankiniu būdu, atsitiktinai arba iš failo)
- Apskaičiuoti galutinį pažymį pagal vidurkį ir medianą
- Suskirstyti studentus į dvi kategorijas:
  - **Protingi** (galutinis vidurkis ≥ 5.0)
  - **Ne tokie protingi** (galutinis vidurkis < 5.0)
- Išvesti rezultatus į failus
- Atlikti spartos analizę su skirtingais duomenų kiekiais (List ir Vector strategijos)

## Releases
- **v0.1** – Bazinė versija: rankinis įvedimas, atsitiktiniai pažymiai, lentelės spausdinimas
- **v0.2** – Pridėtas failų nuskaitymas, kategorijų skirstymas, spartos analizė (List)
- **v0.3** – Optimizacijos, Vector strategija, algoritmų palyginimas (partition, erase)

## Projekto struktūra
- `main.cpp` – pagrindinė programos logika
- `functions.cpp` – funkcijų realizacija
- `vector.cpp` – funkcijų realizacija naudojant std::vector.
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

## Spartos analizės rezultatai

### LIST - 1 strategija

| Failas | Nuskaitymas (s) | Rūšiavimas (s) | Įrašymas (s) | Bendras (s) |
|--------|-----------------|---------------|-------------|------------|
| studentai10.txt | 0.0040244 | 0.0187402 | 0.0034467 | 0.0300635 |
| studentai100.txt | 0.0019569 | 9.97e-05 | 0.0105004 | 0.0170775 |
| studentai1000.txt | 0.0105721 | 0.0003927 | 0.029581 | 0.0435474 |
| studentai10000.txt | 0.111251 | 0.0027431 | 0.198954 | 0.315839 |
| studentai100000.txt | 1.22648 | 0.0417616 | 2.07247 | 3.3437 |

### Vector - 1 strategija

| Failas | Nuskaitymas (s) | Rūšiavimas (s) | Įrašymas (s) | Bendras (s) |
|--------|-----------------|---------------|-------------|------------|
| studentai10.txt | 0.0004625 | 0.0036824 | 0.0044514 | 0.0145581 |
| studentai100.txt | 0.0009774 | 8.1e-06 | 0.0036543 | 0.0080524 |
| studentai1000.txt | 0.0045498 | 0.0001253 | 0.0127471 | 0.0203829 |
| studentai10000.txt | 0.0450281 | 0.0006673 | 0.111536 | 0.163732 |
| studentai100000.txt | 0.686533 | 0.0177833 | 1.32892 | 2.03908 |

### LIST - 2 strategija

| Failas | Nuskaitymas (s) | Rūšiavimas (s) | Įrašymas (s) | Bendras (s) |
|--------|-----------------|---------------|-------------|------------|
| studentai10.txt | 0.0002597 | 1.1e-06 | 0.0023858 | 0.0063553 |
| studentai100.txt | 0.0009697 | 6.5e-06 | 0.0020115 | 0.0065847 |
| studentai1000.txt | 0.0081081 | 6.15e-05 | 0.0125882 | 0.0239601 |
| studentai10000.txt | 0.0761137 | 0.0004438 | 0.105113 | 0.188598 |
| studentai100000.txt | 0.888503 | 0.0038834 | 0.946277 | 1.84691 |

### VECTOR - 2 strategija

| Failas | Nuskaitymas (s) | Rūšiavimas (s) | Įrašymas (s) | Bendras (s) |
|--------|-----------------|---------------|-------------|------------|
| studentai10.txt | 0.0003272 | skaidymo laikas: 4.5e-06 | 0.0023801 | 0.0067653 |
| studentai100.txt | 0.0007489 | skaidymo laikas: 1.76e-05 | 0.0018791 | 0.0062425 |
| studentai1000.txt | 0.0069607 | skaidymo laikas: 0.0001581 | 0.0119115 | 0.0231657 |
| studentai10000.txt | 0.0415528 | skaidymo laikas: 0.0019942 | 0.099897 | 0.151998 |
| studentai100000.txt | 0.514775 | skaidymo laikas: 0.011704 | 0.941129 | 1.47655 |

## Pastabos
- Laikas didėja linijiškai su duomenų kiekiu – algoritmai O(n).
- Didžiausią laiko dalį sudaro failų rašymas (I/O), ne algoritmas.
- Vector greitesnis už List dėl nuoseklios atminties ir mažesnių realokacijų.
- 2 strategija (partition) efektyvesnė už 1 strategiją (erase ciklas).
- Nedideli svyravimai tarp paleidimų yra normalūs dėl OS, cache, I/O.

## Testavimo sistemos parametrai
| Parametras | Reikšmė |
|------------|---------|
| CPU | 11th Gen Intel(R) Core(TM) i5-1145G7 @ 2.60GHz |
| RAM | 16 GB DDR4 |
| HDD / SSD | NVMe SSD |
| OS | Windows 11 Enterprise x64 |
