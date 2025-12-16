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

## Strategijos
- `Strategija 1` – Paprastas skirstymas į kategorijas naudojant iteracinį erase metodą:
  - Kiekvienas studentas tikrinamas ir perkeltas į atitinkamą vektorių arba sąrašą. 
  - Trūkumas: daug erase operacijų → gali būti O(n²) blogiausiu atveju.
- `Strategija 2` – Optimizuotas skirstymas naudojant std::partition:
  - Vienu perėjimu padalina duomenis į dvi grupes.
  - Naudojamas move ir vienkartinis erase → O(n) laikas.
- `Strategija 3` – Optimaliausias algoritmas (naudojant std::partition_copy arba copy_if):
  - Sukuria dvi atskiras kolekcijas vienu arba dviem perėjimais.
  - Mažiausiai realokacijų, geras našumas dideliems duomenų kiekiams.

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

## Paleidimo instrukcija (su g++)

### Kaip kompiliuoti
- Terminale:
  ```bash
  g++ -std=c++17 main.cpp v.pradine.cpp vector.cpp -o programa.exe
  ```

### Kaip paleisti
- Terminale:
  ```bash
  ./programa.exe
  ```
## idiegimo instrukcija

### Variantas A: Make (Unix/Linux/macOS)
- Įdiek g++ (pvz., `sudo apt install build-essential` arba `xcode-select --install` macOS).
- Terminale:
   ```bash
   make        # sukompiliuoja 'programa'
   make run    # paleidžia ./programa
   make clean  # išvalo build artefaktus
   ```

### Variantas B: CMake (Windows/Linux/macOS)
- Įdiek CMake (https://cmake.org) ir C++ kompiliatorių (MSVC arba MinGW Windows, gcc/clang Linux/macOS).
- Terminale:
  ```bash
  mkdir -p build && cd build
  cmake -DCMAKE_BUILD_TYPE=Release ..
  cmake --build . --config Release
  ```

### Programos paleidimas
- Terminale:
  ```bash
  ./programa                 # Linux/macOS
  .\Release\programa.exe     # Windows (MSVC)
  .\programa.exe             # Windows (MinGW)
  ```

## Spartos analizės rezultatai

### LIST - 1 strategija

| Failas | Nuskaitymas (s) | Rūšiavimas (s) | Įrašymas (s) | Bendras (s) |
|--------|-----------------|---------------|-------------|------------|
| studentai10.txt | 0.0004683 | 0.000004 | 0.002750 | 0.005685 |
| studentai100.txt | 0.001077 | 0.000033 | 0.003208 | 0.006923 |
| studentai1000.txt | 0.008084 | 0.000271 | 0.025702 | 0.038109 |
| studentai10000.txt | 0.079605 | 0.002673 | 0.159430 | 0.250481 |
| studentai100000.txt | 0.980284 | 0.025490 | 1.685742 | 2.701157 |

### Vector - 1 strategija

| Failas | Nuskaitymas (s) | Rūšiavimas (s) | Įrašymas (s) | Bendras (s) |
|--------|-----------------|---------------|-------------|------------|
| studentai10.txt | 0.000277 | 0.000006 | 0.002759 | 0.005732 |
| studentai100.txt | 0.000875 | 0.000021 | 0.003380 | 0.007000 |
| studentai1000.txt | 0.005006 | 0.000096 | 0.011492 | 0.020073 |
| studentai10000.txt | 0.043560 | 0.001785 | 0.104525 | 0.156593 |
| studentai100000.txt | 0.589808 | 0.008538 | 1.041460 | 1.647818 |

### LIST - 2 strategija

| Failas | Nuskaitymas (s) | Rūšiavimas (s) | Įrašymas (s) | Bendras (s) |
|--------|-----------------|---------------|-------------|------------|
| studentai10.txt | 0.000308 | 0.000001 | 0.002355 | 0.007255 |
| studentai100.txt | 0.000942 | 0.000006 | 0.002077 | 0.006302 |
| studentai1000.txt | 0.012570 | 0.000076 | 0.018926 | 0.038212 |
| studentai10000.txt | 0.111792 | 0.000611 | 0.122498 | 0.238394 |
| studentai100000.txt | 1.043421 | 0.011668 | 1.365263 | 2.428025 |

### VECTOR - 2 strategija

| Failas | Nuskaitymas (s) | Rūšiavimas (s) | Įrašymas (s) | Bendras (s) |
|--------|-----------------|---------------|-------------|------------|
| studentai10.txt | 0.000285 | 0.000015 | 0.002364 | 0.006179 |
| studentai100.txt | 0.000696 | 0.000034 | 0.002038 | 0.006295 |
| studentai1000.txt | 0.006659 | 0.000215 | 0.014942 | 0.027365 |
| studentai10000.txt | 0.052394 | 0.001360 | 0.110564 | 0.169590 |
| studentai100000.txt | 0.437229 | 0.011256 | 1.008927 | 1.448204 |

### LIST - 3 strategija

| Failas | Nuskaitymas (s) | Rūšiavimas (s) | Įrašymas (s) | Bendras (s) |
|--------|-----------------|---------------|-------------|------------|
| studentai10.txt | 0.000303 | 0.000014 | 0.003095 | 0.009514 |
| studentai100.txt | 0.001567 | 0.000034 | 0.004046 | 0.011619 |
| studentai1000.txt | 0.008382 | 0.000176 | 0.017993 | 0.030193 |
| studentai10000.txt | 0.074557 | 0.001841 | 0.129775 | 0.209747 |
| studentai100000.txt | 0.612980 | 0.008422 | 1.176789 | 1.805983 |

### Vector - 3 strategija

| Failas | Nuskaitymas (s) | Rūšiavimas (s) | Įrašymas (s) | Bendras (s) |
|--------|-----------------|---------------|-------------|------------|
| studentai10.txt | 0.000246 | 0.000008 | 0.002980 | 0.006848 |
| studentai100.txt | 0.002074 | 0.000061 | 0.012370 | 0.072213 |
| studentai1000.txt | 0.012862 | 0.000391 | 0.018819 | 0.037375 |
| studentai10000.txt | 0.082182 | 0.002688 | 0.179310 | 0.268398 |
| studentai100000.txt | 1.443004 | 0.036372 | 1.581471 | 3.066483 |

## Pastabos
- Laikas didėja linijiškai su duomenų kiekiu – algoritmai O(n).
- Didžiausią laiko dalį sudaro failų rašymas (I/O), ne algoritmas.
- Vector greitesnis už List dėl nuoseklios atminties ir mažesnių realokacijų.
- 3 strategija yra greičiausia ir efektyviausia su LIST.
- 2 strategija yra greičiausia ir efektyviausia su Vector.
- Nedideli svyravimai tarp paleidimų yra normalūs dėl OS, cache, I/O.

## Testavimo sistemos parametrai
| Parametras | Reikšmė |
|------------|---------|
| CPU | 11th Gen Intel(R) Core(TM) i5-1145G7 @ 2.60GHz |
| RAM | 16 GB DDR4 |
| HDD / SSD | NVMe SSD |
| OS | Windows 11 Enterprise x64 |
