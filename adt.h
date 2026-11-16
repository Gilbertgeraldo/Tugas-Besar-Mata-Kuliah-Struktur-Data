#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED
#include<iostream>
#include<string>
using namespace std;
typedef struct elmVertec *adrVertex;
typedef struct elmEdge *adrEdge;
typedef struct elmArea *adrArea;
typedef struct elmLokArea *adrLokArea;
typedef struct elmAgent *adrAgent;
typedef struct elmAnggota *adrAnggota;
typedef struct elmRiwayat *adrRiwayat;
typedef struct elmAkun *adrAkun;
typedef struct elmBantu *adrBantu;

struct elmBantu{
    adrVertex lokasi;
    int nilai;
    adrBantu next;
};

struct ListBantu{
    adrBantu first;
    adrBantu last;
};

const int UMUM = 0,SPAWN_ATK = 1,SPAWN_DEF = 2,SITE=3; 
struct Lokasi{
    string nama;
    int tipe;
    int kunjungan;
};

struct elmEdge{
    adrVertex tujuan;
    int waktu;
    int sisaSmoke;
    adrEdge next;
};

struct elmVertex{
    Lokasi info;
    adrEdge firstEdge;
    adrArea area;
    int trap;
    bool visited;
    int jarak;
    adrVertex parent;
    adrVertex next;
};

struct Graph{
    adrVertex first;
};

struct elmLokArea{
    adrVertex Lokasi;
    adrLokArea next;
    adrLokArea prev;
};

struct ListLokArea{
    adrLokArea first;
    adrLokArea last;
};

struct elmArea{
    string nama;
    ListLokArea child;
    adrArea next;
    adrArea prev;
};

struct ListArea{
    adrArea first;
    adrArea last;
};

const int DUELIST = 0,CONTROLLER = 1,INITIATOR = 2,SENTINEL=3;

struct Agent{
    string nama;
    int role;
};

struct elmAgent{
    Agent info;
    adrAgent next;
    adrAgent prev;
};

struct ListAgent{
    adrAgent first;
    adrAgent last;
};

struct StatAgent{
    int jMain;
    int kills;
    int death;
    int plant;
    int defuse;
};

struct StatusMain{
    adrVertex posisi;
    bool isLive;
    bool BringSpike;
    bool UseSkill;
    bool getTrap;
    int killRonde;
    ListBantu langkah;
};

struct elmAnggota{
    adrAgent agent;
    StatAgent stat;
    StatusMain status;
    adrAnggota next;
    adrAnggota prev;
};

struct ListTim{
    adrAnggota first;
    adrAnggota last;
    int jumlah;
}; 

struct Pertandingan{
    int nomor;
    int sisi;
    int done;
    int giliran;
    int kills;
    int deaths;
    bool win;
    string mvp;
};

struct elmRiwayat{
    Pertandingan info;
    adrRiwayat next;
    adrRiwayat prev;
};

struct ListRiwayat{
    adrRiwayat first;
    adrRiwayat last;
};

const int ADMIN = 0,PEMAIN = 1;

struct Akun{
    string username;
    string password;
    int role;
    int JMain;
    int menang;
    int kalah;
    int kills;
    int deaths;
};

struct elmAkun{
    Akun info;
    ListTim Tim;
    ListRiwayat riwayat;
    int nextBattle; //nomor pertandingan berikutnya
    adrAkun next;
};

struct ListAkun{
    adrAkun first;
};

struct Ronde{
    ListTim *atk; //attacker team;
    ListTim *def; //defender team;
    adrAnggota lastAtk;
    adrAnggota lastDef;
    bool atkTurn; //true = sisi attacker berjalan
    int GlobalTurn;
    bool SpikeDitanam;
    int timerSpike;
    int progresDefuse; 
};
#endif // ADT_H_INCLUDED