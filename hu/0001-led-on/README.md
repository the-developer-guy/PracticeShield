# 1. Lecke: Villantsunk egy LED-et! 💡

Üdv a beágyazott rendszerek és a hardverközeliség világában! Ma megírod az első olyan programodat, ami nemcsak a monitoron csinál valamit, hanem valódi, kézzelfogható hardvert vezérel. Készen állsz, hogy életet leheljünk a panelba?

## 🎯 A küldetésed
Állítsd be a `4`-es digitális lábat kimenetként, és kapcsold be a rá kötött LED-et!

---

## 🧠 Hogyan működik? (A motorháztető alatt)

### Mi az a GPIO láb?
A mikrokontroller szélén sorakozó kis fém lábakat **GPIO**-nak hívjuk – ez az angol *General Purpose Input/Output* (általános célú bemenet/kimenet) rövidítése. Gondolj rájuk úgy, mint a mikrovezérlő kezeire és érzékszerveire:
* **Bemenetként (`INPUT`)** figyel a külvilágra (például megérzi, ha átbillentesz egy kapcsolót vagy megnyomsz egy gombot).
* **Kimenetként (`OUTPUT`)** jeleket küld ki, hogy vezéreljen valamit (például felkapcsoljon egy LED-et vagy megpörgessen egy motort).

Alapértelmezésben minden láb bemenetként indul, hogy bekapcsoláskor ne küldjenek ki véletlenül feszültséget oda, ahova nem kéne. Ahhoz, hogy világítson a LED, szólnunk kell a vezérlőnek: *"Figyelj, a 4-es láb mostantól kimenet lesz!"*

### 1. lépés: A láb beállítása (`pinMode`)
Nézd meg közelebbről a panelt! A **LED1** mellett a **D4** (*Digital Pin 4*) feliratot látod. A kódban egyszerűen csak a számával hivatkozunk rá: `4`.

A beállításhoz a `pinMode()` függvényt használjuk a `setup()` blokkon belül (ez a kapcsos zárójelek `{}` közötti rész, ami csak egyszer fut le, amikor áramot kap a panel vagy megnyomod a Resetet):

```cpp
void setup() {
  pinMode(4, OUTPUT);
}
```

> **Fejlesztői tipp:** Látod, hogy az `OUTPUT` csupa NAGYBETŰVEL van írva? Azért, mert ez egy előre definiált kulcsszó, úgynevezett **makró** (később sajátokat is fogunk írni!). A C++ fordító nem viccel: ha kisbetűvel írod, hogy `output`, azonnal hibát dob. Maradjunk a nagybetűknél!

### 2. lépés: Adjunk rá feszültséget! (`digitalWrite`)
Most, hogy a 4-es láb készen áll a jelküldésre, engedjük rá az áramot! A `digitalWrite()` függvénnyel két állapotot tudunk beállítani: `HIGH` (magas szint / BE) vagy `LOW` (alacsony szint / KI):
* **`HIGH`**: Rákapcsolja a lábat a panel tápfeszültségére (ez egy klasszikus Arduino Uno esetén **5V**, egy ESP32-nél pedig általában **3,3V**). Az áram megindul a LED-en keresztül, és az szépen felvillan!
* **`LOW`**: Ráköti a lábat a földre (**GND / 0V**), így elalszik a LED.

Rakjuk össze az egészet a `setup()`-ban:

```cpp
void setup() {
  pinMode(4, OUTPUT);    // A 4-es láb legyen kimenet
  digitalWrite(4, HIGH); // Kapcsoljuk fel a LED-et!
}

void loop() {
  // Ide most még nem kell semmi – a LED így is égve marad!
}
```

Töltsd fel a kódot a panelra! Ha a **LED1** világít, pacsi – megírtad az első hardveres programodat! 🎉

---

## 🛠️ Hardveres és forrasztási ellenőrzés (Házi feladat / Tanári konzultáció)
* **Forrasztási szemle:** Ha a kód hibátlan, mégsem világít a LED, ne ess pánikba – elő a nagyítóval! Nézd meg a **LED1** és a mellette lévő ellenállás forrasztási pontjait. Fényesek, simák és kis vulkánra hasonlítanak? Egy hidegforrasztás vagy apró zárlat simán megakaszthatja az áramkört.
* **Gondolkodtató kérdés (Ha elakadsz, kérdezz rá a tanárodnál!):** A LED-ek polaritásérzékenyek, vagyis az áram csak egy irányba tud átfolyni rajtuk (a hosszabb lábtól, az *anódtól* a rövidebb láb, a *katód* felé). Nézd meg a panelt: miért van minden egyes LED mellett egy apró ellenállás is beforrasztva? Mi történne a LED-del, ha direktben rákötnénk az 5V-ra?
