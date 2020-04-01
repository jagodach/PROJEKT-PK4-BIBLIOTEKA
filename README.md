# PROJEKT-PK4-BIBLIOTEKA
Temat projektu: Biblioteka

Program jest systemem zarządzania/obsługi biblioteki. Dane przechowywane są w plikach csv. Pliki te zachowują się podobnie do plików txt. Format danych jest ważny tylko dla zapisywania  i pobierania danych. Różne typy obiektów są przechowywane  w innych wektorach. Wektory posiadają wskaźniki do obiektów. Obiekty posiadają referencje do siebie nawzajem. Przechowują tylko id w plikach z danymi. Używają ID żeby znaleźć obiekt  i związać go z innymi kolekcjami. Po zalogowaniu się jako user czyli zwykły użytkownik możemy tylko zobaczyć aktualne wypożyczenia danego użytkownika na którego jesteśmy zalogowani, zobaczyć historyczne wypożyczenia danego użytkownika, wypożyczyć przedmioty (książki papierowe, ebooki), zwrócić przedmioty(książki papierowe, ebooki). Po zalogowaniu się jako admin jest dostępnych dużo więcej funkcji. Użytkownik musi zapłacić za wypożyczenie (cena wypożyczenia + 10% za każdy tydzień opóźnienia). Użytkownik ma możliwość wyszukania książki po różnych kryteriach np: id, tytuł, autor. Użytkownik ma także oczywiście możliwość opuszczenia programu bibliotecznego. Admin może zobaczyć aktualne wypożyczenia wszystkich użytkowników biblioteki, zobaczyć historyczne wypożyczenia wszystkich użytkowników biblioteki, może wypożyczyć książkę dla wybranego przez siebie użytkownika, zwrócić książkę dla wybranego przez siebie użytkownika, dodawać autorów, usuwać autorów, dodawać przedmioty (książki papierowe, ebooki), usuwać przedmioty (książki papierowe, ebooki) oraz dodawać dane o nich np rok powstania, rok wydania, format ebooka itp. oraz ma możliwość wyjścia z programu. Każdy przedmiot może być wypożyczony raz (czyli jeśli chcemy mieć w bibliotece trzy te same książki to muszą  zostać one dodane trzy razy).


Opis ważnych klas:
LibraryManager: klasa, która przechowuje całe dane i jest połączona z GUI. Cała „logika” aplikacji się tutaj znajduje.

Helpers: klasa za statycznymi metodami, które wykonują podstawowe rzeczy takie jak: odczytywanie/zapisywanie plików, rozdzielanie stringów.

FileRecord: abstrakcyjna klasa, która zachowuje się jak interfejs umożliwiający odczytywanie i zapisywanie danych.
LibraryItem, Book, Ebook: przedmioty w bibliotece. LibraryItem jest podstawowym przedmiotem, reszta pokazuje dziedziczenie po nim
Book, EBook: mają tylko małe różnice między sobą. Mogłoby zostać stworzone więcej przedmiotów, ale to jest jeszcze do przemyślenia bo wszystkie byłyby takie same i nie wiem czy ma to jakiś głębszy cel.
LendRecord: reprezentuje wypożyczenia. Łączy użytkownika  z przedmiotami i ustawia datę i cenę za wypożyczenie.
HelpersforGUI: klasa umożliwiająca wymiane danych między interfejsem, a logiką aplikacji
Poza tym w pliku LibrarySystem.cpp znajduje się main() i cała obsługa aplikacji. A Structs zawiera podstawowe typy używane w aplikacji (SimpleData i PersonData). SimpleData jest prostym "wrapperem"( funkcje lub klasy, których zadaniem jest jedynie wywołanie innych funkcji lub metod obiektów) ponieważ używanie funkcji związanych z datą i czasem jest bardzo skomplikowane. PersonData umożliwia nie dołączać wszędzie name, surname, birthday.

Techniki obiektowe, które zostaną użyte w projekcie (4 z 8):
W projekcie zostaną użyte szablonu, kontenery stl(wektory jako pojemniki na dane), algorytmy stl, RTTI oraz wyrażenia regularne (regex) do wyszukiwania książek.
Aplikacja jest stworzona na podstawie wektorów (kontenery stl).
Lista dwukierunkowa do przemieszczania się po książkach.

Opis funkcji dostepnych dla użytkownika:
Po zalogowaniu się jako user czyli zwykły użytkownik możemy tylko zobaczyć aktualne wypożyczenia danego użytkownika na którego jesteśmy zalogowani, zobaczyć historyczne wypożyczenia danego użytkownika, wypożyczyć przedmioty (książki papierowe, ebooki), zwrócić przedmioty(książki papierowe, ebooki). Po zalogowaniu się jako admin jest dostępnych dużo więcej funkcji. Użytkownik musi zapłacić za wypożyczenie (cena wypożyczenia + 10% za każdy tydzień opóźnienia). Użytkownik ma możliwość wyszukania książki po różnych kryteriach np: id, tytuł, autor. Użytkownik ma także oczywiście możliwość opuszczenia programu bibliotecznego. Admin może zobaczyć aktualne wypożyczenia wszystkich użytkowników biblioteki, zobaczyć historyczne wypożyczenia wszystkich użytkowników biblioteki, może wypożyczyć książkę dla wybranego przez siebie użytkownika, zwrócić książkę dla wybranego przez siebie użytkownika, dodawać autorów, usuwać autorów, dodawać przedmioty (książki papierowe, ebooki), usuwać przedmioty (książki papierowe, ebooki) oraz dodawać dane o nich np rok powstania, rok wydania, format ebooka itp. oraz ma możliwość wyjścia z programu.


Schemat działania programu:
-Ładowanie danych: Aplikacja ładuje dane z plików wprowadzonych na stałe (hardcoded) w rozwiązaniu. Różne typy obiektów są przechowywane w innych wektorach. Wektory posiadają tylko wskaźniki do obiektów
-Wiązanie danych: Obiekty posiadają referencje do siebie nawzajem. Przechowują tylko id w plikach z danymi. Używają ID żeby znaleźć obiekt i związać go z innymi kolekcjami.
-Login:
-GUI: Użytkownik może wybrać różne opcje. Różni użytkownicy posiadają różne menu i funkcje w nich zawarte. Użytkownik może tylko zobaczyć dane i wypożyczyć przedmioty(np. książki).
Admin może robić wszystko: Autorzy: dodawanie, oglądanie, usuwanie Użytkownicy: dodawanie, oglądanie, usuwanie Przedmioty: dodawanie, oglądanie, usuwanie
Wypożyczenia:
-mogą być oglądane(użytkownik może zobaczyć tylko własne wypożyczenia, admin widzi wszystkie)
-mogą być zwracane. Po zwróceniu przedmiotu pojawia się on w historii wypożyczeń. Użytkownik musi zapłacić za wypożyczenie(cena wypożyczenia + 10% za każdy tydzień opóźnienia)

-każdy przedmiot może być wypożyczony raz(Jeśli chcemy mieć w bibliotece trzy te same książki to muszą zostać one dodane trzy razy)

-zakończenie programu
