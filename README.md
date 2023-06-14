Procesor CSS

Prosty silnik przetwarzający CSS. Program wczytuje ze standardowego wejścia sekcje CSS przeplatane sekcjami komend. Sekcje CSS są parsowane i umieszane w odpowiednich strukturach, sekcje komend są parsowane i wykonywane wypisując na standardowe wyjście.

CSS

    Przetwarzanie rozpoczyna się wczytania deklaracji CSS. CSS jest syntaktycznie poprawny i składa się bloku atrybutów ew. poprzedzonych selektorami. Brak selektorów jest legalny (oznaczałby atrybuty aplikowane do wszystkiego).
    Selektory (selectors) są separowane przecinkami. Dopuszczalne są selektory legalne dla CSS, ale można założyć, że nie zawierają znaków przecinka ani nawiasów klamrowych.
    Blok atrybutów ujęty jest w nawiasy klamrowe.
    Atrybuty są oddzielone średnikami i składają się z nazwy (property) i wartości (value) oddzielonych dwukropkiem. Po ostatnim atrybucie w bloku może, ale nie musi nastąpić średnik.
    Jako wartości atrybutów mogą występować legalne dla CSS konstrukcje, jednak dla uproszczenia można bezpiecznie założyć, że ew. napisy nie są złośliwe tj. nie zawierają escapowanych znaków cudzysłowu, nawiasów klamrowych lub średników.
    Jeśli konkretny atrybut (nazwa) w bloku występuje więcej niż raz należy potraktować to jako jedno wystąpienie, przy czym znacząca jest ostatnia wartość).
    Zarówno selektory, nazwy atrybutów jak i wartości atrybutów nie wymagają interpretacji semantycznej tj. traktujemy je (po odrzuceniu skrajnych białych znaków, jako wartość. Tj. np.: 'margin-left : 8px', 'margin: 4px 7px 4px 7px' traktujemy jako oddzielne, niezwiązane atrybuty o nazwach odpowiednio 'margin-left' i 'margin' i wartościach '8px' oraz '4px 7px 4px 7px' Podobnie, selektory są traktowane jako wartość i nie wymagają interpretacji tj. np.: 'h1' i 'h1.theme' traktujemy jako oddzielne, niepowiązane selektory.
    Uproszczenie: CSS nie zawiera komentarzy, ani selektorów typu @, bloki nie mogą się zagnieżdżać.
    Dla potrzeb testów można założyć, że żaden selektor ani atrybut nie jest podzielony na kilka linii (ciągle w jednej linii może być kilka separatorów/ i lub atrybutów).

Komendy
W poniższych komendach i oraz j to dodatnie liczby całkowite (mieszczą się w int), natomiast n to legalna nazwa atrybutu. ???? – początek sekcji komend;

    **** - wznów czytanie CSS;
    ? – wypisz liczbę bloków CSS;
    i,S,? – wypisz liczbę selektorów dla bloku nr i (numery zaczynają się od 1), jeśli nie ma takiego bloku pomiń;
    i,A,? - wypisz liczbę atrybutów dla bloku nr i, jeśli nie ma takiego bloku lub bloku pomiń;
    i,S,j – wypisz j-ty selector dla i-tego bloku (numery bloków oraz atrybutów zaczynają się od 1) jeśli nie ma bloku lub selektora pomiń;
    i,A,n – wypisz dla i-tego bloku wartość atrybutu o nazwie n, jeśli nie ma takiego pomiń;
    n,A,? – wypisz łączną (dla wszystkich bloków) liczbę wystąpień atrybutu nazwie n. (W ramach pojedynczego bloku duplikaty powinny zostać usunięte na etapie wczytywania). Możliwe jest 0;
    z,S,? – wypisz łączną (dla wszystkich bloków) liczbę wystąpień selektora z. Możliwe jest 0;
    z,E,n – wypisz wartość atrybutu o nazwie n dla selektora z, w przypadku wielu wystąpień selektora z bierzemy ostatnie. W przypadku braku pomiń;
    i,D,* - usuń cały blok nr i (tj. separatory+atrybuty), po poprawnym wykonaniu wypisz deleted;
    i,D,n – usuń z i-tego bloku atrybut o nazwie n, jeśli w wyniku operacji pozostaje pusty blok powinien zostać również usunięty (wraz z ew. selektorami), po poprawnym wykonaniu wypisz deleted.

