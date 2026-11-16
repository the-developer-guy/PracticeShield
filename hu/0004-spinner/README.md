# 4. Lecke: LED-pörgettyű és a `for` ciklus 🎡

A panelodon egy egész környi LED sorakozik a `4`-es lábtól egészen a `11`-esig! Nyolcszor egymás után leírni a `pinMode()`-ot és a `digitalWrite()`-ot eléggé favágó munka lenne. A jó fejlesztő viszont kreatívan lusta: ha valami szabályos minta szerint ismétlődik, azt rábízza a gépre egy ciklussal!

## 🎯 A küldetésed
Futtasd körbe a fényt az óramutató járásával ellentétes irányban a LED-körön (`4`-től `11`-ig) egy `for` ciklus segítségével, és szabályozd a forgás sebességét egy változóval!

---

## 🧠 Hogyan működik?

### 1. lépés: Mi történik lépésről lépésre?
Mielőtt ciklust írunk, nézzük meg, mit is akarunk csinálni:
1. Beállítjuk a `4`–`11` digitális lábakat kimenetnek.
2. Felkapcsoljuk a `4`-es LED-et, és várunk `delayTime` ezredmásodpercet.
3. Lekapcsoljuk a `4`-est, felkapcsoljuk az `5`-öst, és várunk.
4. Ezt folytatjuk körbe egészen a `11`-es LED-ig!

### 2. lépés: Ismerkedj meg a `for` ciklussal!
Azt már tudjuk, hogy a `loop()` a végtelenségig fut, de mi van akkor, ha egy olyan ciklust szeretnénk, ami elszámol `4`-től `11`-ig, aztán megáll? Erre találták ki a **`for` ciklust**!

Így néz ki a felépítése:

```cpp
for (int pin = 4; pin <= 11; pin++) {
  // Az itt lévő kód minden lábra lefut 4-től 11-ig!
}
```

Szedjük szét a zárójelben lévő három utasítást:
1. **`int pin = 4;`**  -  *Kezdőérték:* Létrehozunk egy ideiglenes számláló változót `pin` néven, és `4`-ről indítjuk.
2. **`pin <= 11;`**  -  *Feltétel:* Addig ismételjük a ciklust, amíg a `pin` értéke kisebb vagy egyenlő `11`-gyel.
3. **`pin++`**  -  *Léptetés:* Minden kör végén hozzáadunk `1`-et a `pin` értékéhez (a `pin++` a `pin = pin + 1` rövidítése).

Ezzel a trükkel már a `setup()`-ban is megspórolunk egy csomó gépelést – 8 sor helyett 3 sorból megvan az összes láb beállítása:

```cpp
int delayTime = 250;

void setup() {
  for (int pin = 4; pin <= 11; pin++) {
    pinMode(pin, OUTPUT);
  }
}
```

### Utolsó lépés: Legyen atombiztos a kódunk!
Van egy tipikus kezdő hiba: ha a ciklus csak felkapcsolja az aktuális LED-et, majd amikor `11`-ről visszaugrik `4`-re, a `11`-es LED égve maradhat! Vagy ha valamiért két LED egyszerre kap jelet, összekuszálódik a fényjáték.

Tegyük **100%-ig golyóállóvá** a programot egy tiszta, kiszámítható szabállyal minden egyes lépésnél:
1. **Kapcsold KI az ÖSSZES LED-et** (egy gyors belső `for` ciklussal!).
2. **Kapcsold BE csak az aktuális LED-et** (`pin`).
3. **Várj** (`delay(delayTime)`).

Nézd, milyen letisztult és megbízható a teljes kód:

```cpp
int delayTime = 250;

void setup() {
  for (int pin = 4; pin <= 11; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  for (int pin = 4; pin <= 11; pin++) {
    // 1. Először minden LED-et lekapcsolunk
    for (int offPin = 4; offPin <= 11; offPin++) {
      digitalWrite(offPin, LOW);
    }

    // 2. Felkapcsoljuk az éppen soron következő LED-et
    digitalWrite(pin, HIGH);

    // 3. Várunk a következő lépés előtt
    delay(delayTime);
  }
}
```

Így bármi történik, **mindig pontosan egyetlen LED** fog világítani!

---

## 🚀 Házi feladat és Tanári konzultáció
* **Kísérlet:** Állítsd a `delayTime` értékét `50`-re – máris úgy pörög, mint egy rulettkerék!
* **Kihívás (Ha elakadsz, kérdezd meg a tanárodat!):** Jelenleg a fény `4`-től `11`-ig halad. Hogyan módosítanád a `loop()`-on belüli `for` ciklust úgy, hogy **visszafelé** forogjon (`11`-től lefelé `4`-ig)? *(Tipp: A `pin++` párja C++-ban a `pin--`, ami 1-et von le!)*
