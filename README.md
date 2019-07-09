# BVCC – Die Bitvektor-Coding-Challenge

Bearbeiten Sie bis zur Seminarphase mindestens die Aufgaben 1 und 2. Wer auch die optionale Aufgabe 3 noch erfolgreich bearbeitet, braucht sich für die Projektgruppe keine Sorgen mehr zu machen.

Beachten Sie folgende allgemeine Hinweise:
* Alle Implementierungen sollen in C++17 erfolgen! Es sollen keine externen Bibliotheken verwendet werden.
* Nutzen Sie den gegebenen Code-Rahmen. Die in den Aufgaben genannten Schnittstellen müssen erhalten bleiben, ansonsten dürfen Sie Ihrer Kreativität freien Lauf lassen!
* Die vorgefertigten Implementierungen im Code-Rahmen sind funktionsfähig, aber sehr naiv und nicht platzeffizient. Sie dienen als Überblick und Einstiegspunkt.
* Die Lösungsvorschläge sind Vorschläge - probieren Sie gern eigene Ideen aus!
* Es gibt einen Preis für die beste Implementierung (beste Laufzeit und kleinster Speicherplatzverbrauch in gleicher Testumgebung)!

## Aufgabe 1

Implementieren Sie eine Klasse `bit_vector`, die Bitvektoren repräsentiert. Verwenden Sie _word packing_ (z.B. mit `uint64_t`, um jeweils 64 Bits in einem Wort speichern zu können).

Der Bitvektor soll über den Konstruktor seine Länge `n` erhalten und für diese `n` Bits Speicher allokieren. Initial sollen alle Bits auf 0 stehen. Über die Operationen `bitset` und `bitread` sollen Bits für eine Position `i < n` geschrieben bzw. gelesen werden können. Um dies zu realisieren, müssen Sie sich mit bitweisen Operationen in C bzw. C++ vertraut machen.

Hinweise:
* Für gewöhnlich ist `std::vector<bool>` in der Standardbibliothek als Bitvektor implementiert und kann in der Praxis verwendet werden, wie es im Code-Rahmen der Fall ist. Das Ziel dieser Aufgabe ist es jedoch, sich selbst mit den Basics auseinanderzusetzen.

#### Beispiel-Anwendung
```cpp
bit_vector B(4); // Konstruktion mit Länge 4
B.bitset(0, 1); // setze erstes Bit auf 1
B.bitset(1, 0); // setze zweites Bit auf 0
B.bitset(2, 0); // ...
B.bitset(3, 1); // ...
```
Eine Überprüfung, dass `i < n` gilt, wird nicht gefordert.

#### Aufgabe 1b *

Überladen Sie den Index-Access-Operator `[]`, so dass z.B. `B[0] = 1` geschrieben werden kann, um das erste Bit zu setzen und `b = B[0]`, um es zu lesen.

## Aufgabe 2

Implementieren Sie die Klasse `bit_vector_rank`, die im Konstruktor einen `bit_vector B` erhält und eine statische platzeffiziente Datenstruktur konstruiert, die _rank_-Anfragen auf `B` für eine Position `i < n` in konstanter Zeit beantworten kann. Die Anfrage `rank1(i)` gibt die Anzahl der 1-Bits zurück, die von Anfang bis (einschließlich) Position `i` in `B` stehen. Implementieren Sie auch `rank0` für 0-Bits.

Die Datenstruktur ist statisch, das heißt, sie wird nur einmal für den gegebenen Bitvektor konstruiert und wird nicht aktualisiert, sollte sich der Bitvektor ändern.

Hinweise:
* Verwenden Sie z.B. die Strategie, wie sie im ersten Treffen der PG grob besprochen wurde [1]. Machen Sie sich Gedanken, wie Sie diese möglichst speichereffizient halten. Hierzu kann es sinnvoll sein, sich nicht auf 8-Bit-alignierte Datentypen (`uint8_t`, `uint16_t`, ...) zu beschränken und Arrays für Zahlen von beliebiger Bitbreite zu implementieren.
* Nutzen Sie die popcount-Instruktion (`__builtin_popcount`) für das Zählen von 1-bits in Wörtern.

#### Beispiel-Anwendung
```cpp
bit_vector_rank Br(B);
std::cout << Br.rank1(3) << std::endl; // sollte 2 ausgeben, da es bis einschl. Position 3 zwei 1-Bits gibt
std::cout << Br.rank1(0) << std::endl; // sollte 1 ausgeben, da es bis einschl. Position 0 ein 1-Bit gibt
std::cout << Br.rank0(3) << std::endl; // sollte 2 ausgeben
std::cout << Br.rank0(0) << std::endl; // sollte 0 ausgeben
```

## Aufgabe 3*

Implementieren Sie die Klasse `bit_vector_select`, die im Konstruktor einen `bit_vector B` erhält und eine statische Datenstruktur konstruiert, die _select_-Anfragen auf `B` für eine Zahl `k > 0` in konstanter Zeit beantworten kann. Die Anfrage `select1(k)` gibt die Position des `k`-ten 1-Bits in `B` zurück. Falls `k` größer ist als die Anzahl der Vorkommen des jeweiligen Bits, wird `n` (die Länge des Bitvektors) ausgegeben. Implementieren Sie auch `select0` für 0-Bits.

Hinweise:
* Machen Sie sich z.B. mit der im Buch [1] genannten Strategie vertraut und setzen Sie diese platzeffizient um.

#### Beispiel-Anwendung
```cpp
bit_vector_select Bs(B);
std::cout << Bs.select1(1) << std::endl; // sollte 0 ausgeben, da das erste 1-Bit an Position 0 steht
std::cout << Bs.select1(2) << std::endl; // sollte 3 ausgeben, da das zweite 1-Bit an Position 3 steht
std::cout << Bs.select1(3) << std::endl; // sollte 4 ausgeben, da es kein drittes 1-Bit gibt
std::cout << Bs.select0(1) << std::endl; // sollte 1 ausgeben
std::cout << Bs.select0(2) << std::endl; // sollte 2 ausgeben
std::cout << Bs.select0(3) << std::endl; // sollte 4 ausgeben
```

## Testen

Im Code-Rahmen sind einfache Testprogramme enthalten, mit der Sie Ihre Implementierung auf Korrektheit testen können. Um diese zu kompilieren, ist der GCC und CMake erforderlich. Benutzen Sie am besten ein Linux-System!

Zum Kompilieren wechseln Sie in das `bvcc`-Verzeichnis und führen folgende Befehle aus:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

Führen Sie im Unterverzeichnis `test` die Programme `test-bv`, `test-rank`, `test-select` und `test-integration` aus, um Ihre Implementierungen von Bitvektoren Korrektheit zu überprüfen.

#### Benchmark
Der Benchmark zur Ermittlung der Sieger wird unter fairen Bedingungen durchgeführt. Sieger sind die Implementierungen, die auf der Pareto-Front bezüglich Laufzeit und Speicherplatzverbrauch für den Benchmark liegen.

Machen Sie sich Gedanken, wie Sie Ihre Implementierung auf Laufzeit und Speicherplatzverbrauch hin testen und entwerfen Sie ggf. eigene Benchmarks!

## Literatur

[1] Navarro: Compact Data Structures (Kapitel 4.2 und 4.3)
