# Terminfo 4. eloadas - 2020.09.29

## A termeles fofolyamatanak egyszerusitett modellje

Bonyolult, osszetett objektum, melynek kulonbozo reszei vannak (diszkret eseten).

### ***Abra*** (BOM): 

1. Fa struktura
   - vegen a vegtermek
   - Milyen alrendszerekbol epul ossze.
   - Legalso szinten: Monolit vagy kvazi monolit komponensek epulnek be (Monolit: nem bonthato (pl. Csavar), kvazi monlit: funkcio szerint egyseg (pl. csapagy)).
   - Minden szukseges komponensnek rendelkezesre kell allnia.
   - **File rendszer analogia**
2. Iranyitott graf
   - Elek: beepules
   - Alkatreszgraf
   - P - Szerelveny
   - p - monolit, kvazi monolit komponensek
   - Szamszeruseg: elek szama
   - Egyenerteku a fa strukturaval
3. Incidenciamatrix
   - Lenyege:
     - oszlopok: darabok
     - sorok: komponensek
     - cella: beepulesi mennyiseg
   - Osszesito vektor
     - A teljes rendszert figyelembe veve, a kulonbozo komponensekbol hany darab talalhato.

### Technologiai folyamatterv (BOP)

Milyen muvelettel es milyen eroforrassal illesztjuk ossze az adott komponenseket.

Aljatol felfele: a beepulo komponensek (megvasarolhato), ezekbol transzformaciot hajtunk vegre (Elogyartas).
Pl.: rud anyag megvasarlasa, majd feldarabolasa

Alkatresz keszremunkalasa: Keszre gyartas. Ez is az alkatresz gyartas resze. Pl.: feldarabolt rudbol tengely.

Alkatreszek osszeszerelese:
Tengelyek, fogaskerekek, stb. osszeszerelese.
Magasabb hierarchia szint.
Un. szerelveny.
Lehetseges, hogy a szerelvenyek koreben kissebb csoportokat keszitunk, melyeket ismet osszeszerelunk.
Ilyenkor: Eloszereles -> vegszereles.

Barmely hierarchiai szintem megjelenhetnek olyan komponensek, melyeket nem mi allitottunk elo, hanem veteleztunk.
Pl.: Autogyartoknal pl.: fek rendszer megvete, beszerelese.

Szukseg van az elemi muveletek megtervezesere, ez a Gyartastervezes.
Szerszamok, utasitasok, szukseges programok elozetes megtervezese.
Process Plan (PP): Folyamatterv.

## Termeles tervezes

Nem egy, hanem sok termekre vontakozik.
Ami osszetartja oket az az, hogy az elerheto eroforrasokat egyutt hasznaljak fel.

### A termeles fofolyamatanak egyszerusitett elvi modellje

1. Ismernunk kell, hogy milyen rendelesek vannak
   - Vevoi rendeles (kulso, vallalaton kivuli piaci szereplotol)
   - Belso rendeles (Vallalaton beluli igeny)
2. Ezeket felhasznalva elozetes tervezesi terv keszitese
    - Prognozisokbol, kalkulaciokbol
3. Terv valtozatokbol egyet fogadunk el
    - MPS vagy MPP (Master Production Plan/Schedule)
    - Mely tipusbol a kovetkezo idoszakban hany db-ot celszeru legyartani.

|     | 1.honap     | 2.honap | ... |
| --- | ----------- | ------- | --- |
| p1  | x1; x2; ... | ...     | ... |
| p2  | ...         |         |     |
| ... | ...         | ...     | ... |

4. Szukseglet szamitas (anyagszukseglet)
    - Elozetes tervezesi feazis eredmenye (vezerterv) alapjan
    - Ha ismerjuk a BOM-ot, akkor ebbol le tudjuk generalni, hogy a komponensek szintjen mennyi az igeny.
    - Termek tipusok kozti atfedes.
    - Brutto anyagszukseglet
      - Altalaban vannak eppen vegrehalytas alatt levo folyamatok.
      - A raktarkeszlet sem 0.
      - Dinamikusan keletkeznek olyan termekek, melyek elerhetove valnak.
5. Nettositas
    - Jelenleg a felhasznalhato komponensek milyen mennyisegben allnak rendelkezesre.
    - A Bruttobol ezeket leveszem.
    - pl.: rendelnek 100db-ot, de nekem mar raktaron van 50, akkor a brutto anyagszukseglet: 100, a netto pedig 50.
    - Gyartando = brutto - netto
6. Rendelesi mennyisegek elemzese
    - BOP
    - Eszkozok figyelembe vetele.
    - Hogyan hasznalom fel az eroforrasaimat
      - Belso rendelesek halmaza is megjelenik.
        - Vasarlas
        - Helyben gyartas

{R^b_i}; belso rendelesek halmaza

R^b_i -> d_i; Ez a durva tervezes vegeredmenye

7. Vegrehalytas megszervezese
   1. Kifele iranyulo
   2. Befele iranyulo

### Tervezes

2 nagy fazis:

1. Elozetes tervezes (Elo ideju)
2. Iranyitas (Valos idejo)

Ahol a belso rendeles megjelenik, az valasztja el a termeles tervezest es a gyartasiranyitast.

1. Termelesi foterv elkeszitese
    - Konkret megrendelesek
    - varhato ertekesitesek prognozis-adatai alapjan **Teteles vegtermek-kiszallitasi terv**
    - vegtermekre,
    - tartalek szerelvenyekre, szerviz alkatreszekre, amely
      - "hozza" a tervezett vallalti nyereseget
      - eroforrasok (szemelyek + eszkozok) oldalarol realis fedezettel rendelkezik
      - tukrozi a vallalat hosszu tavu muszaki fejlesztesi elkepzeleseit
2. Szuksegletszamitas
    - Anyagszukseglet tervezese
      - Termelesi foterv brutto anyagszukseglete
      - Raktarkeszlet + inditott rendelesek eredmenyekent kepzodo keszlet
    - Anyagszukseglet- terv
      - beszerzesi tetelekre
      - belso gyartaso (szerelesu) tetelekre.
    - Kapacitasszukseglet tervezese
      - eroforras adatok
      - muveleti idoadatok
    - Durva-program
      - belso gyartaso tetelekre
3. Termelesprogramozas
    - durva program alapjan rovid idoszakra elore megadja az elvegezendo feladatok reszletes listajat homogen munkahely vagy egyedi gep bontasban
    - es alapjan elkeszithatok a reszletes gyartasi dokumentaciok

### Diszkret folyamatok iranyitasa

- Kozeptau termelesi tervek rovidtavu bontasa, a feladatok utemezese, finomprogramozasa;
- A feladatok vegrehajtasahoz szukseges anyagi, szmelyi es informacios feltetelek biztositasa;
- a feladatok kiosztasa es elinditasa;
- a folyamatok valos ideju felugyelete es iranyitasa;
- a vegrehajtas minosegenek biztositasa;
- teljesitmenymutatok szamitasa es az eredmenyek ertekelese;
- a bizonytalansagok es a varatlan esemenyek kezelese.
  - Egyik eszkoze az ujrautemezes vagy atutemezes
    - Az utemtervet atirjuk, hogy a menetkozben fellepo esemenyek karos hataset minimalizaljuk.

### MES

***Abra - FONTOS!***

- Felso szint: Tervezesi fazis
- Elso bemenet: Milyen operaciokat kell vegrehajtani.
- Elso szoftver szolgaltatas
  - Finom programozas, reszletes utemezes (Detailed scheduling)
    - Melyik eroforras, milyen muveletet es mikor hajtson vegre
- Dispatching
  - Utemezes szetbontasa
  - Monitorozas, szukseg eseten atutemezes, korrigalas
- Execution management, Process control and execution
  - A folyamatok tenyleges vegrehajtasa.

### Az MRP II paradigma

- MRP (Manufacturing Resource Planning) II
  - "Nyomo"-elvre alapozott hierarchikus iranyitas
  - szuksegletszamitasok es -tervezesek
  - prediktiv utemezesi es ujrautemezesi modellek
    - Elore tervezett
  - **csuszo (gordulo)** tervezesi modszer

Alapja, hogy elore elkeszitem a tervet (elorol hatrafele haladva tervezek, ellenorzok).
Akkor hasznaljuk, ha jol modellezheto a rendszer, a muveleti idok jol tervezhetoek, jol definialtak a munkahelyek.

### A JIT (Just In Time) paradigma

- "huzo"-elvre alapozott decentralizalt iranyitas
- "termeld meg a szukseges mennyiseget a megfelelo idopontra"
- ki kell kuszobolni mindenfele veszteseget, el kell hatirani az ezeket kivalto okokat
- tervezett minimalis keszletek fenntartasaval megbizhato gyartast kell megvalositani
- rovid furasi idok (gyors reagalas)
- szigoru szallitasi fegyelem

Alapja, hogy a munkahelyek kozott tarolok vannak.
A tervezes a folyamat vegerol indul.
Van egy R^k_i kulso rendeles.
Ha van a raktarban, akkor ki is szallitom. 
Ha nincs, akkor megnezem, hogy egy lepessel visszabb van-e termekem (pl. csomagolas elott).
Ha van, akkor ezt a folyamatot vegzem el.
Ha nincs, ismet visszalepek egy folyamattal.

A folyamatot a vegerol "huzzuk" vegig.

Akkor hasznalhato, ha megfeleloen meretezheto a keszletszint. 
Nem az a cel, hogy 0 legyen a keszletszint, hanem, hogy minel alacsonyabb legyen.
Ha jol van meghatarozva a keszlet szintem, akkor megakadalyozzuk azt, hogy a teljes folyamatot vegig huzzuk egy megrendeles beerkezesekor, a legkisebb ilyen keszlet a minimalis keszlet.

Nagyon pontos vegrehajtasra van szukseg.
