# 6. Lecke: Irányváltós pörgettyű és a Makrók 🔄

Ideje összerakni mindent, amit eddig tanultál! Ma egy olyan interaktív LED-pörgettyűt építünk, ami a kapcsoló átbillentésének *pillanatában* irányt vált – ráadásul megtanulod, hogyan tüntetik el a profik a „mágikus számokat” **makrók** segítségével.

## 🎯 A küldetésed
Olvasd az `A3` lábon lévő kapcsolót! Az egyik állásban az óramutató járásával megegyezően, a másikban ellentétesen fusson körbe a fény (`4`–`11`), és azonnal váltson irányt, amint átkattintod a kapcsolót!

---

## 🧠 Hogyan működik?

### 1. lépés: Miért nem elég két `for` ciklus?
Elsőre adná magát az ötlet: *"Simán berakok egy előre számoló `for` ciklust az `if`-be, egy visszafelé számolót pedig az `else`-be!"*

```cpp
// Óramutató járásával ellentétesen (4-től 11-ig)
for (int i = 4; i <= 11; i++) { ... }

// Óramutató járásával megegyezően (11-től 4-ig)
for (int i = 11; i >= 4; i--) { ... }
```

Ez működik is, **egyetlen szépséghibával**: ha a program belép egy `for` ciklusba, addig ki sem jön belőle, amíg mind a 8 LED végig nem pörög! Ha a kör felénél átbillented a kapcsolót, a panel tudomást sem vesz rólad, amíg be nem fejezi a megkezdett kört.

Ahhoz, hogy **abban a szent pillanatban** irányt váltson, amikor hozzáérsz a kapcsolóhoz, el kell engednünk a külső `for` ciklust, és hagynunk kell, hogy maga az Arduino `loop()` léptesse a fényt egyesével!

### 2. lépés: Pozíció követése globális változóval
Ha nincs `for` ciklus, ami számol helyettünk, honnan fogja tudni a program, melyik LED világít éppen? Onnan, hogy eltároljuk egy **globális változóban** a kód tetején!

Hozzunk létre egy `int nextLed = 4;` változót a `setup()` felett. Minden egyes alkalommal, amikor lefut a `loop()`, csak **egyetlen lépéssel** mozdítjuk el a `nextLed` értékét:
1. Megnézzük a kapcsolót (`A3`).
2. Ha a kapcsoló `HIGH` (Jobbra áll), hozzáadunk `1`-et a `nextLed`-hez (`nextLed++`). Ha túlmegy `11`-en, visszaugrasztjuk `4`-re!
3. Ha a kapcsoló `LOW` (Balra áll), levonunk `1`-et a `nextLed`-ből (`nextLed--`). Ha `4` alá esik, átugrik `11`-re!
4. Lekapcsoljuk az összes LED-et, felkapcsoljuk a `nextLed`-et, és várunk `delayTime` ideig.

Mivel a `loop()` *minden egyes lépés előtt* ránéz a kapcsolóra, az irányváltás teljesen azonnali lesz!

### Utolsó lépés: Száműzzük a „mágikus számokat” makrókkal (`#define`)!
Nézd meg a kódban szétszórt `4`-es és `11`-es számokat. Ha valaki úgy olvassa a kódodat, hogy nincs a kezében a panel, csak pislog: *"Mi az a 4? Miért pont 11?"* A programozók az ilyen magyarázat nélküli számokat **mágikus számoknak (magic numbers)** hívják – és igyekeznek kerülni őket!

A **`#define`** utasítással beszédes nevet adhatunk ezeknek az értékeknek. Ezt hívjuk **makrónak**:

```cpp
#define MIN_LED 4
#define MAX_LED 11
```

#### Miben más egy Makró, mint egy Változó?
* Egy **változó** (`int delayTime = 150;`) helyet foglal a mikrovezérlő RAM-jában, és futás közben módosítható.
* Egy **makró** (`#define MAX_LED 11`) **nulla bájt RAM-ot** használ! Mielőtt a kód feltöltődik a chipre, a fordító egyszerűen lefuttat egy keresés-cserét, és minden `MAX_LED` feliratot kicserél `11`-re. Mivel ez nem változó, futás közben nem is tudsz neki új értéket adni (a `MAX_LED = 8;` fordítási hibát okozna).
* Íratlan szabály, hogy a makrókat mindig **`CSUPA_NAGYBETŰVEL_ÉS_ALÁHÚZÁSSAL`** írjuk. Ha bárhol olyan szót látsz, hogy `HIGH`, `LOW`, `INPUT`, `OUTPUT` vagy `MAX_LED`, azonnal tudni fogod, hogy egy makróval van dolgod!

### A teljes, kész kód

```cpp
#define MIN_LED 4
#define MAX_LED 11
#define SWITCH_PIN A3

int delayTime = 150;
int nextLed = MIN_LED;

void setup() {
  pinMode(SWITCH_PIN, INPUT);
  for (int pin = MIN_LED; pin <= MAX_LED; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  // 1. Kapcsoló olvasása és a nextLed léptetése 1-gyel
  if (digitalRead(SWITCH_PIN) == HIGH) {
    nextLed++;
    if (nextLed > MAX_LED) {
      nextLed = MIN_LED; // Átfordulás 11-ről 4-re
    }
  }
  else {
    nextLed--;
    if (nextLed < MIN_LED) {
      nextLed = MAX_LED; // Átfordulás 4-ről 11-re
    }
  }

  // 2. Minden LED lekapcsolása
  for (int pin = MIN_LED; pin <= MAX_LED; pin++) {
    digitalWrite(pin, LOW);
  }

  // 3. Az új LED felkapcsolása és várakozás
  digitalWrite(nextLed, HIGH);
  delay(delayTime);
}
```

Nézd meg, milyen könnyű így karbantartani a kódot: ha holnap úgy döntesz, hogy csak félkörben pattanjon a fény, elég a kód tetején átírnod a `#define MAX_LED 11` sort `#define MAX_LED 8`-ra – **egyetlen helyen**!

---

## 🎉 Tananyag-ellenőrző és Házi feladat
* **Próbáld ki:** Írd át a `MIN_LED` és `MAX_LED` értékeit, és nézd meg, hogyan mozog a fény egy kisebb íven!
* **Záró kihívás (Mutasd meg a tanárodnak!):** Tudnál beleépíteni egy **„szünet” funkciót** vagy turbó fokozatot? Gondold végig, hogyan használhatnál egy újabb `if` feltételt – vagy kérdezd meg a tanárodat, hogyan köthetsz be egy nyomógombot, ami lenyomva tartva felpörgeti a fényjátékot!
