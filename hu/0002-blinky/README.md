# 2. Lecke: Blinky – A hardveres „Hello, World!” 🚨

Szoftverfejlesztésnél az első lépés mindig az, hogy kiíratjuk a képernyőre: *"Hello, World!"*. Beágyazott rendszereknél ugyanez a belépő a **LED-villogtatás**! Azt már tudod, hogyan kell felkapcsolni – most tanítsuk meg lekapcsolni is, és adjunk neki egy stabil szívverést!

## 🎯 A küldetésed
Állítsd be a `4`-es digitális lábat kimenetként, és villogtasd a LED-et másodpercenként egyszer (1 Hz-es frekvenciával)!

[📺 Nézd meg a bemutató videót!](https://youtube.com/shorts/rRoTMfvWe2Y?feature=share)

---

## 🧠 Hogyan működik?

### `setup()` kontra `loop()`
Minden Arduino/C++ programnak két alapvető építőköve van:
1. **`setup()`**: **Csak egyszer** fut le bekapcsoláskor vagy Reset után. Ide kerül az előkészítés, például a `pinMode()`.
2. **`loop()`**: Végtelen ciklusban fut **újra és újra**, amíg csak áram alatt van a panel. Amit ide írsz, az megállás nélkül ismétlődik!

És ha a `digitalWrite(4, HIGH);` felkapcsolja a LED-et, mi kapcsolja le? Bizony, a `digitalWrite(4, LOW);`!

### 1. lépés: Próba a `setup()`-ban (Túl gyors!)
Mi történik, ha mindkét parancsot beírjuk a `setup()`-ba?

```cpp
void setup() {
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH); // Bekapcsolás
  digitalWrite(4, LOW);  // Azonnali kikapcsolás
}

void loop() {
}
```
Ha ezt lefuttatod, látszólag... semmi nem történik. Miért? Mert a mikrovezérlő a másodperc törtrésze alatt hajtja végre az utasításokat. Olyan brutális sebességgel kapcsolta fel, majd le a LED-et, hogy az emberi szem esélytelen észrevenni!

### 2. lépés: Átrakjuk a `loop()`-ba (Még mindig túl gyors!)
Oké, tegyük át a kapcsolgatást a `loop()`-ba, hogy ismétlődjön:

```cpp
void setup() {
  pinMode(4, OUTPUT);
}

void loop() {
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
}
```
Most úgy tűnik, mintha a LED folyamatosan világítana – legfeljebb egy picit halványabban! Ez azért van, mert **másodpercenként több ezerszer** villan fel és alszik ki. A szemünk összemossa a gyors villanásokat egy folyamatos fénnyé (pont ugyanezt a trükköt használja a monitorod és a mozivetítő is).

### Utolsó lépés: Tartsunk szünetet a `delay()` segítségével!
Ahhoz, hogy lássuk is a villogást, várakoztatnunk kell a vezérlőt az állapotváltások között. Erre való a `delay()` függvény, ami **ezredmásodpercben (milliszekundumban)** méri az időt (`1000 ms = 1 másodperc`).

Az **1 Hz-es** villogáshoz (másodpercenként egy teljes be-ki ciklushoz):
1. Kapcsold **BE** a LED-et (`HIGH`)
2. Várj **500 ms**-ot (fél másodpercet)
3. Kapcsold **KI** a LED-et (`LOW`)
4. Várj **500 ms**-ot (fél másodpercet)

```cpp
void setup() {
  pinMode(4, OUTPUT);
}

void loop() {
  digitalWrite(4, HIGH); // LED be
  delay(500);            // Várunk 0,5 másodpercet
  digitalWrite(4, LOW);  // LED ki
  delay(500);            // Várunk 0,5 másodpercet
}
```
*(Megjegyzés: Tanuláshoz szuper a `delay()`, de jó, ha tudod: ilyenkor a mikrovezérlő konkrétan malmozik, és semmi mást nem tud csinálni, amíg le nem telik az idő. Később majd megnézzük, hogyan lehet úgy időzíteni, hogy közben ne blokkoljuk a procit!)*

---

## 🚀 Kísérletezés és Házi feladat
* **Játssz az időzítéssel:** Írd át az `500`-at `100`-ra egy pörgős stroboszkóphoz, vagy `2000`-re egy lassú, álmos pulzáláshoz! Mi történik, ha a bekapcsolt idő `50 ms`, a kikapcsolt pedig `950 ms`?
* **Gondolkodj el rajta (Kérdezd meg a tanárodat, ha bizonytalan vagy!):** Miért van szükség *két* `delay(500);` sorra? Mi történne, ha kitörölnéd a második `delay(500);`-at a `digitalWrite(4, LOW);` alól? Próbáld ki élőben!
