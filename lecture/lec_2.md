# Terminfo 2. eloadas - 2020.09.15

## Rendszerrel kapcsolatos terminologiak

Rendszer tervezesekor elso sorban a celt kell kituzni. 
Egyutt a rendszer elemei igy tobbet tudnak nyulytani, mint egyenkent.
Objektum - altalanositott fogalom (fizikai, gondolati is)
Rendszerek kozotti kapcsolat - informacio.

- Rendszerelmelet (Systems theory)
    - Absztrakt fogalmak es torvenyek egyuttese.
- Rendszertechnika (Systems Engineering)
    - Rendszer tervezesere szolgalo modszerek osszessege.
- Rendszerszemlelet (Systems approach)
    - Angol: fokozatos megkozelites.
    - Magyar: Kotott szempont.
    - A rendszerek tudomanyos vizsgalataban alkalmazott elmeleti megkozelites modszereinek osszefoglalo neve.

### Alapgondolat:

Rendszer tervezes eseten meghatarozott modszerkkel meghatarozott tevekenysegeket meghatarozott eszkozokkel.
Mindig a celt kell kituzni!

### Uj rendszer kialakitasanak lepesei

1. Cel definialasa
1. Funkcio
    - Kepessegek osszessegek, melyeket a rendszernek meg kell valositani.
1. Struktura
    - Rendszert alkoto elemek es kozottuk levo kolcsonhatasok osszessege.
1. Belso mukodes
    - Konkretan meg kell tervezni, hogy milyen adatforrasbol, hogyan erem el az adatokat.
    - Dontesi logika.
    - Utemterv birtokaban: ertekeles.
1. Kornyezettel valo kapcsolat
    - Valamilyen interfesz (pl. file, DB, GUI, terminal, stb.)

Rendszer elemzese eseten ezeket a lepeseket forditva vegezzuk el, tehat a Kornyezeti kapcsolatok elemzesevel kezdunk.

### Rendszerek kombinalasaval letrehozott uj rendszer

Rendszer komplexitasa: Valahogy mernunk kell a rendszerek bonyolultsagat.
Mennyi fele allapotot tud felvenni a rendszer?
Ez az allapotvalasztek.

Egyesiteskor az elrendszerek komplexitasat ossze kell szorozni!
Az allapotvalasztekot minel inkabb le kell csokkenteni.

### Rendszer iranyitasa

Minden rendszernek szuksege van egy iranyito rendszerre.

- $V_0$ az eredmenyek v celok valaszteka.
- $V$ az iranyado rendszer allapotvalaszteka
- $V_c$ az iranyito rendszer allapotvalaszteka

\[ V_0 = \frac{V}{V_c} \]

A rendszert nem szabad magara hagyni. Vissza kell terelni az eredeti menetrend fele.
Hiszen ha magara hagyjuk, akkor mindig elter a normalis mukodestol.

Az iranyito rendszernek legalabb olyan komplexitasunak kell lennie, mint az iranyitottnak, hiszen csak akkor tudjuk az osszes allapotat lekepezni.
A rendszerbe torteno folyamatok iranyitasara is iranyito rendszerre van szukseg.

### Funkcio

- Adott tulajdonságok összessége, amely képessé teszi a rendszert, hogy megfelelően működjék

### Integracio

- Bizonyos rendszerelemeket koherensen, kompatibilisen es konzisztensen kapcsoljuk ossze, hogy uj rendszert hozzunk letre.
    - Koherens - egymassal egyuttmukodo.
    - Kompatibilis - Kepes egymassal egyutt mukodni.

### Algoritmus

- Valamely kituzott feladat megoldasara szolgalo olyan eljaras, amely jol definialt elemi lepesek sorozatabol all.
- Algoritmizalas: a feladat megoldasanal lepesekre torteno lebontasa.

### Optimalizalas

- Egy rendszerben olyan intezkedesek, amelyekkel maximalis hatast erunk el.
- Statikus, dinamikus
    - Statikus: a dontesi valtozo az erteke az idotol fuggetlen.
    - Dinamikus: A mukodes az idotol fugg.
- Determinisztikus, sztochaikus
- Dontesi valtozok, korlatozasok, celfuggvenyek
    - Korlaton beluli ertekeket vesszuk csak figyelembe. Majd ezeket a celfuggvenybe helyettesitessel vizsgaljuk.
    - Egyetlen hierarchiai szinten nem tudjuk kezelni. Tul sok a korlatfeltetel.
        - Ilyenkor Hierarchikus optimalizalas.
- Hierarchikus optimalizalas
    - A valosagot lekepezem egy optimalizalasi modellre.
    - Ezt mas hierarchiai szintem az elozo optimalizalas hatasat vizsgalom (levetitem).
    - Amikor nincs metszet, akkor nem valosithato meg az optimalizalas. Igy pl a kijelolt idokeretben nem gyarthatom le az adott termeket.
        - Ilyenkor: A folottes szinten jelezzuk a problemat. Azon egy masik pontot jelolunk ki, hogy az alsobb hierarchiai szintan is benne legyunk a keretben.

Csak akkor, ha a legjobb megoldast talaljuk meg, nem akkor, ha csak egy korabbinal jobbat talaltunk.

Tartozik hozza valami korlatozas/feltetel rendszer.
Meres, szamitas kell, amivel minosithetjuk a jelolteket.
Ez a celfuggveny <- az eljarasokat formalizalja.

Optimalis mar magaban lehet legjobb, nincs legoptimalis!

ZH-ban szokott lenni (Optimalizalas, Hierarchikus optimalizalas tul.)

### A Problema megoldasa

- Matematikai modszerek alkalmazasanak feltetelei:
    - A problema numerikus formaban is leirhato.
    - A cel celfuggvenykent felirhato.
    - All randelkezesre egy algoritmus, ami elfogadhato idon belul elvezet a problema megoldasahoz. (Gyakorlati igenyhez kotott)

### Heurisztikus modszer

- Matematikai modszerek alkalmazasanak feltetelei nem teljesulnek.
- Az adott problema megoldasat egy terv konstrualasa utjan probalja megkeresni. Ez a konstrualasi folyamat lepesrol-lepesre dont a kovetkezo tervezesi elemrol.
- Tartalmaz szubjektiv tenyezot, ezert az eljeres josagat kizarolag gyakorlati alkalmazhatosagan lehet merni.

## Informacio

Az informatika lapfogalma. Valamifele hir, hirkozles, ami valamifele bizonytalansagot szuntet meg.

### Adat - informacio

- Adat: nincs jelentese
- Informacio: Az erteket valamilyen intelligens szemely vagy eszkoz fel tudja dolgozni.

### Kommunikacio

Ket vagy tobb termeszetes szemely vagy eszkoz kozt.

5 szintet kulonboztetunk meg:

1. Statisztika
    - Jel.
    - Jelek tulajdonsagaival, hibak keletkezesevel, kezelesevel foglalkozunk.
1. Szintaktika
    - Forma.
    - Formai kovetelmeny.
1. Szemantika
    - Jelentes.
    - Leirt/kozolt jelsorozat tartalmi feldolgozasa.
1. Pragmatika
    - Cselekves.
    - Cselekves kivaltasa. Az elvart cselekvesnek es a kivaltott cselekves meg kell, hogy egyezzen.
1. Apobetika
    - Celok.
    - Az egesz kommunikacionak valojaban megvalosult-e a celja, vagy sem.

## Informatika

- Az informacio
    - megszerzesevel
    - tovabbitasaval
    - terolasaval
    - feldolgozasaval
    - megertesevel
    - felhasznalasaval

foglalkozik.

## Az informatika hatasa

- Az informacio, mint alapmennyiseg.
    - Ezzel is ugyanugy kell gazdalkodni.
    - Eroforras.
    - Megszerzese, feldolgozasa, megertese egyre fontosabb.

- Az informaciofeldolgozasi technologia es a kommunikacio integracioja: ICT.
    - Internet
    - Kommunikacios savszelesseg novekedese.
    - ICT vilagmeretu konvergenciaja

- A hozzaferes minosegileg megvaltozik.
- Az informacio alapveto ertek.
- Az uzleti es igazgatasi dontesi feladatok felgyorsulasa
- Tavoli egyuttmukodes lehetseges.
- A hagyomanyos belso strukturak mellet kulso, egyuttmukodo strukturak.

## Termeles (ZH-ba 100)

- Hasznalati javak tervszeru es sokszorozott eloallitasa a tudomany, technika es a technologia mindenkori szintjen
- Kornyezeti feltetelek:
    - tudomany
    - technika es technologia
    - tarsadalom, gazdasag es politika
- Magaban foglalja:
    - A fizikai termek eloallitasa
    - Szolgaltatasok
    - A teljes muszaki elokeszites
    - Minosegbiztositas

## Gyartas (ZH-ba 100)

- Halmazelmeleti megkozelitesben a gyartas a termeles valodi reszhalaza.
- A gyartas egy allapot-transzformacio, amely a munkadarabokat a legdurvabb nyersallapotbol a legfinomabb kesz allapotba viszi at.
- A gyartas magaban foglalja a kapcsolodo tervezest es kivitelezest is.

### Ket kategoria:

1. Diszkret gyartas
    - Diszkret elemekbol tevodik ossze.
    - A fazisok idoben es terben jol megkulonboztethetok, elvalaszthatok
1. Folytonos (pl.: vegyipar)
    - Anyagok osszekeveresevel valtoztatjuk meg a tulajdonsagokat.
    - Idoben nem szeparalhato el.

### Folyamatok rendszerezese:

- Termeles eseteben:
    - Fo folyamat
        - A munkadarab mindig folyamatosan jelen van es valamilyen tulajdonsagat tudatosan, celzottan valtoztatjuk meg.
    - Mellek folyamatok
        - A munkadarab szinten folyamatosan jelen van, de tudatosan nincs jellemzo tulajdonsag valtoztatas (pl.: szallitas, raktarozas, rakodas).
        - Altalaban a logisztikahoz tartoznak.
    - Seged folyamatok
        - Mar a munkadarab nem feltetlenul van jelen, de az allapot valtozasanak elokeszitese tortenik (pl.: szerszam ellatas).
    - Kornyezeti folyamatok
        - Pl.: Huto, keno anyagok tarolasa...
    - Karbantarto folyamatok (TMK - Tervszeru Megelozo Karbantartas)
        - Az eszkozok allapotat fenn kell tartani.
        - A rendszer tervezo altal eloirt allapotat tartja fenn tudatosan.

## Termeles informatika

- Termelesen belul alkalmazott informatika.
    - Informatika -> Alkalmazott informatika -> Termeles informatika

- Termelesi rendszerek
    - Modellezese
    - tervezese
    - iranyitasaval foglalkozik.

- Alkalmazasi szintjei
    - Muszaki tervezes tamogatasa
    - Termelesi rendszerek iranyitasa, felugyelete
    - Berendezesek, munkahelyek, folyamatok iranyitasa, ellenorzese
    - A termelezinformatika interdiszciplinaris erintkezesi feluletei:
        - Automatizalas
        - Informaciofeldolgozasi technologiak
        - Uzleti folyamatok informatikaja
        - Vallalatiranyitas, menedzsment funkciok.

- Virtualis vallalat
    - Laza koalicio, amelyben tobb fuggetlen szereplo van egyutt.
    - Rovid idon keresztul mukodik.