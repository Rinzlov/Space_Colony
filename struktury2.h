struct robot{
	int klasa;
	float hp;
	float energia;
	int PB;
	int PB2;
	int PB3;
	};
struct robot rob={1, 50, 400, 0, 0, 0};

struct hangar{
	float odzysk;
	float energia;
	};
struct hangar hang={0.9, 10000};

struct surowce{
	float zlom;
	float stal;
	float krzem;
	float helium;
	float technet;
	};
struct surowce surR={0,0, 0, 0, 0};
struct surowce surH={0,200, 100, 0, 0};

struct ladownia{
       float nr;
       float pojemnosc;
       float waga;
	float stal;
	float krzem;
	float helium;
	float technet;
       char name[40];
       };
struct ladownia ladowniaF={};
struct ladownia ladowniaX={};
struct ladownia ladownia0={0, 60, 20, 0, "standardowa"};
struct ladownia ladownia1={1, 80, 100, 100, "S  "};
struct ladownia ladownia2={2, 120, 140, 140, "M  "};
struct ladownia ladownia3={3, 200, 200, 200, "L  "};
struct ladownia ladownia4={4, 350, 340, 340, "XL "};
struct ladownia ladownia5={5, 700, 500, 500, "XXL"};

struct ogniwo{
       float nr;
       float pojemnosc;
       float efektywnosc;
       float waga;
	float stal;
	float krzem;
	float helium;
	float technet;
       char name[40];
       };
struct ogniwo ogniwoF={};
struct ogniwo ogniwoX={};
struct ogniwo ogniwo0={0, 500, 8, 0, 0, 0, 0, "standardowe"};
struct ogniwo ogniwo1={1, 600, 12, 130, 80, 50, 0, "I C  "};
struct ogniwo ogniwo2={2, 800, 16, 195, 120, 75, 0, "II C "};
struct ogniwo ogniwo3={3, 1000, 22, 280, 160, 120, 10, "III C"};
struct ogniwo ogniwo4={4, 1400, 30, 570, 250, 300, 20, "I B  "};
struct ogniwo ogniwo5={5, 2000, 46, 750, 300, 400, 50,  "II B "};
struct ogniwo ogniwo6={6, 4000, 60, 1050, 350, 600, 100,  "III B"};
struct ogniwo ogniwo7={7, 8000, 100, 1700, 500, 1000, 200, "I A  "};
       
struct weapon{
       float nr;
       float damage;
       float waga;
	float stal;
	float krzem;
	float helium;
	float technet;
       char name[40];
       };
struct weapon weaponF={};
struct weapon weaponX={};
struct weapon weapon0={0, 0, 0, 0, 0, 0, 0, "brak"};
struct weapon weapon1={1, 30, 100, 50, 50, 0, 0, "Tesla Spark"};
struct weapon weapon2={2, 45, 200, 100, 100, 0, 0, "Short Laser Pulse"};
struct weapon weapon3={3, 70, 220, 150, 50, 20, 0, "Particle Wave"};
struct weapon weapon4={4, 120, 500, 300, 200, 0, 0, "Gauss Cannon"};
struct weapon weapon5={5, 240, 570, 300, 200, 40, 30, "Fluctuative Rockets"};
struct weapon weapon6={6, 500, 850, 200, 500, 100, 50, "Electromagnetic Pulse"};
struct weapon weapon7={7, 1200, 1150, 200, 500, 250, 200, "Implosive"};
 
struct silnik{
       float nr;
       float moc;
	float stal;
	float krzem;
	float helium;
	float technet;
       char name[40];
       };
struct silnik silnikF={};
struct silnik silnikX={0, 200, 0, 0, "-"};
struct silnik silnik0={0, 200, 0, 0, "-"};
struct silnik silnik1={1, 360, 100, 0, "silnik1"};
struct silnik silnik2={2, 500, 200, 10, "silnik2"};
struct silnik silnik3={3, 800, 400, 50, "silnik3"};
struct silnik silnik4={4, 1200, 600, 100, "silnik4"};
struct silnik silnik5={5, 2000, 1000, 500, "silnik5"};
struct silnik silnik6={6, 4000, 2000, 1000, "silnik6"};
struct silnik silnik7={7, 7000, 4000, 1500, "silnik7"};
       
struct pancerz{
       float nr;
       float wytrzymalosc;
       float waga;
	float stal;
	float krzem;
	float helium;
	float technet;
       char name[40];
       };
struct pancerz pancerzF={};
struct pancerz pancerzX={0, 50, 20, 0, 0, "standardowy"};
struct pancerz pancerz0={0, 50, 20, 0, 0, "standardowy"};
struct pancerz pancerz1={1, 80, 50, 50, 0, "p1"};
struct pancerz pancerz2={2, 120, 140, 140, 0, "p2"};
struct pancerz pancerz3={3, 340, 260, 250, 10, "p3"};
struct pancerz pancerz4={4, 600, 390, 350, 40, "p4"};
struct pancerz pancerz5={5, 1200, 750, 600, 150, "p5"};

// W BAZIE
struct generator{
       float nr;
       float efektywnosc;
	float stal;
	float krzem;
	float helium;
	float technet;
       char name[40];
       };
struct generator generatorF={};
struct generator generatorX={0, 4, 0, "standardowy"};
struct generator generator0={0, 4, 0, "standardowy"};
struct generator generator1={1, 6, 1000, "V1000"};
struct generator generator2={2, 8, 2000, "V2000"};
struct generator generator3={3, 12, 3000, "V3000"};
struct generator generator4={4, 20, 6000, "V4000"};
struct generator generator5={5, 30, 10000, "V5000"};

       
struct teleporter{
       float nr;
       float energia;
       float waga;
	float stal;
	float krzem;
	float helium;
	float technet;
       char name[40];
       };
struct teleporter teleporterF={};
struct teleporter teleporterX={};
struct teleporter teleporter0={};
struct teleporter teleporter1={};
struct teleporter teleporter2={};
struct teleporter teleporter3={};
struct teleporter teleporter4={};
