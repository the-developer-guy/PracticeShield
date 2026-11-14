# 3. Lecke: Felváltva villogó LED-ek és az első változóid 🚦

Egy LED-et vezérelni menő, de az igazi projektekben egyszerre több dolgot irányítunk! Gondolj csak a vasúti átjárók villogójára vagy a rendőrautók fényhídjára: amikor az egyik felvillan, a másik kialszik. Ma pontosan ezt rakjuk össze, közben pedig megismerkedsz a programozók egyik legfontosabb eszközével: a **változókkal**.

## 🎯 A küldetésed
Állítsd be a bal oldali (`4`-es) és a jobb oldali (`8`-as) LED-et kimenetként, és villogtasd őket felváltva! Úgy írd meg a kódot, hogy a villogás sebességét **egyetlen szám átírásával** tudd módosítani!

[📺 Nézd meg a bemutató videót!](https://youtube.com/shorts/P8eT7SSupE8)

---

## 🧠 Hogyan működik?

### 1. lépés: Két LED villogtatása
Pontosan úgy, ahogy az előző leckében a `4`-es lábat beállítottad, a `setup()`-ban most a `8`-ast is beállítod kimenetnek. A `loop()`-ban pedig felváltva kapcsolgatod őket:
1. A `4`-es láb legyen **BE** (`HIGH`), a `8`-as **KI** (`LOW`).
2. Várj `500` ezredmásodpercet.
3. A `4`-es láb legyen **KI** (`LOW`), a `8`-as **BE** (`HIGH`).
4. Várj `500` ezredmásodpercet.

```cpp
void setup() {
  pinMode(4, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  digitalWrite(4, HIGH);
  digitalWrite(8, LOW);
  delay(500);

  digitalWrite(4, LOW);
  digitalWrite(8, HIGH);
  delay(500);
}
```

### Utolsó lépés: Jöjjenek a változók!
Tegyük fel, hogy szeretnéd megduplázni a villogás sebességét, és átírod az `500`-at `250`-re. Jelenleg ezt **két helyen** kell megtenned. Mi van, ha az egyiket átírod `250`-re, a másikat meg véletlenül `500`-on felejted? Máris sántítani fog a villogód! És képzeld el, mi lenne egy több száz soros kódban, ahol 50 helyen szerepel a késleltetés – kész rémálom lenne egyesével vadászni őket.

Itt lépnek képbe a **változók**! Képzelj el egy felcímkézett dobozt a mikrovezérlő memóriájában, amibe beteszel egy értéket, és később bárhol előveheted a neve alapján.

Egy változó létrehozásához két dolgot kell megadnod:
1. **Az adattípust:** Most az `int` típust használjuk (az angol *integer*, azaz egész szám rövidítése – ez tárolja a kerek számokat, például `500`, `250` vagy `-10`).
2. **Egy beszédes nevet:** Mindig adj értelmes nevet a változóidnak, mint például `delayTime`, ahelyett, hogy titokzatos `x` vagy `a` betűket használnál – két hét múlva a saját kódodat sem fogod érteni, ha spórolsz a betűkkel!

```cpp
int delayTime = 500; // Létrehozunk egy delayTime nevű változót, és beletesszük az 500-at
```

Ezt a sort írd **legfelülre, még a `void setup()` elé**! Ha minden függvényen kívül hozod létre, akkor **globális változó** lesz, vagyis a programod minden egyes része látja és használhatja.

Most cseréld le mindkét `500`-ast a `delayTime` nevére:

```cpp
int delayTime = 500;

void setup() {
  pinMode(4, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  digitalWrite(4, HIGH);
  digitalWrite(8, LOW);
  delay(delayTime);

  digitalWrite(4, LOW);
  digitalWrite(8, HIGH);
  delay(delayTime);
}
```

Töltsd fel – pont ugyanúgy villog, mint eddig! Most írd át legfelül az `int delayTime = 500;` sort `int delayTime = 250;`-re, és töltsd fel újra. Bumm – egyszerre frissült mindkét időzítés, és kétszer olyan gyorsan villognak a LED-ek!

---

## 🛠️ Hardveres ellenőrzés és Házi feladat
* **Forrasztási tipp:** Ha a `4`-es LED szépen villog, de a `8`-as meg sem nyikkan, ellenőrizd a **D8**-as LED lábainak forrasztását a panelon!
* **Kihívás (Kérj tippet a tanárodtól, ha elakadsz!):** Figyelted, hogy a `delayTime` kisbetűvel kezdődik, a második szó pedig nagybetűvel? Ezt **camelCase** (tevepúp) írásmódnak hívják a programozók! Tudnál bevenni a játékba egy **harmadik** LED-et is (mondjuk a `6`-os lábon), hogy hárman fussanak körbe a `delayTime` változóddal?
