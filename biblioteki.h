#include <stdio.h>
#include <stdlib.h>
//#include <ncurses/ncurses.h>
//#include <ncurses/panel.h>
#include <ncurses.h>
#include <panel.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include "struktury.h"
#include "initFstruct.h"
#include "delay.h" // opoznienie
#include "X.h" // wyswietla X w danym miejscu
#include "resources.h"
#include "animacjahangaru.h"
//#include "znak.h" // -||- wyœwietla znak z okreœlonymi atrybutami
// na górze nie ruszaæ
#include "build.h"
#include "loadgame.h"
#include "armageddon.h"
#include "explosion.h"
#include "rocket.h"
#include "abs.h"
#include "missile.h"
#include "enemys.h"
#include "enemysmove.h"
#include "enemysshoot.h"
#include "wypiszmape.h"
#include "outlines.h"
#include "inlines.h"
#include "menu.h"
#include "czysciana.h"
#include "Pojemnosc.h"
#include "zmien_nazwe_mapy.h"
#include "komputer.h"
#include "shoot.h"
#include "help.h"
#include "wypelnijTablice.h"
#include "warn.h" // wyœwietla okienko ostrzegawcze i zwraca 0 dla OK i 1 dla Anuluj
#include "info.h" // -||- okienko informacyjne
#include "K.h" // skraca wyswietlanie duzych liczb np 12000 na 1,2K,
#include "gameinfo.h"
#include "factory.h" 
#include "generator.h" // obsluguje animacje generatora i przyrost energii
#include "repair.h" // -||- naprawy i przyrost hp
#include "zapiszmape.h" // zapisuje tabele z zawartoscia planszy do pliku
#include "wczytajmape.h" // -||- wczytuje
#include "huta.h" // obsluguje hute (odzysk stali ze zlomu)
#include "magazyn.h" // obsluguje magazyn (przeniesienie durowcow z robota do hangaru)
#include "modd.h" // funkcja zwracaj¹ca czêœæ ca³kowit¹ z dzielenia a/b
#include "drzwi.h"
//#include "podmenu.h"

