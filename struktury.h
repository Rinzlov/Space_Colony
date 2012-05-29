struct MIS{
	int nr;
	int aa;
	int bb;
	int dir;
	int type;
	};
struct MIS missile[2000];

struct ILE{
	int count;
	int numbers[2000];
	int liczbaprzeciwnikow;
	};
struct ILE missileQ;

struct robot{
	int klasa;
	float hp;
	float energia;
	int PB;
	int PB2;
	int PB3;
	float pojemnosc;
	int zelazonamapie;
	int krzemnamapie;
	int technetnamapie;
	int aa; // aktualne polozenie y w tablicy mapy
	int bb; // -||- x
	int aaa; // poprzednie polozenie y
	int bbb; // -||- x
	int map_y;
	int map_x;
	int map_y2;
	int map_x2;
	};
struct robot rob={1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 35, 20, 35};

struct hangar{
	float odzysk;
	float energia;
	int sumKrysz;
	int sumZel;
	int sumTech;
	};
struct hangar hang={0.9, 10000, 0, 0, 0};

struct surowce{
	float zlom;
	float stal;
	float krzem;
	float helium;
	float technet;
	};
struct surowce surR={0,0, 0, 0, 0};
struct surowce surH={0,200, 0, 100, 0};

// FABRYKA

struct ladownia{
       float nr;
       float pojemnosc;
       float waga;
	float stal;
	float krzem;
	float helium;
	float technet;
    };
struct ladownia ladowniaX={};
struct ladownia ladowniaq[102];

struct ogniwo{
       float nr;
       float pojemnosc;
       float waga;
	float stal;
	float krzem;
	float helium;
	float technet;
    };
struct ogniwo ogniwoX={};
struct ogniwo ogniwoq[102];
       
struct weapon{
		float nr;
		float damage;
		float waga;
	float stal;
	float krzem;
	float helium;
	float technet;
    };
struct weapon weaponX={};
struct weapon weaponq[102];

struct kolektor{
		float nr;
		float szybkosc;
		float waga;
	float stal;
	float krzem;
	float helium;
	float technet;
    };
struct kolektor kolektorX={};
struct kolektor kolektorq[102];
       
struct silnik{
		float nr;
		float moc;
	float stal;
	float krzem;
	float helium;
	float technet;
    };
struct silnik silnikX={};
struct silnik silnikq[102];
       
struct pancerz{
		float nr;
		float wytrzymalosc;
		float waga;
	float stal;
	float krzem;
	float helium;
	float technet;
    };
struct pancerz pancerzX={};
struct pancerz pancerzq[102];

  // W BAZIE
struct generator{
		float nr;
		float efektywnosc;
	float stal;
	float krzem;
	float helium;
	float technet;
    };
struct generator generatorX={};
struct generator generatorq[102];

       
struct teleporter{
		float nr;
		float energia;
	float stal;
	float krzem;
	float helium;
	float technet;
    };
struct teleporter teleporterX={};
struct teleporter teleporterq[102];
