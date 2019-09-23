#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h> 
#include <sys/shm.h> 
#include <unistd.h>
#include <list>

using namespace std;

union semun{
	int val;
    struct semid_ds *buf;
    ushort *array;
};

struct diergasia{
	int id;
	int size;
	int duration;
};

struct vp_message{
	int start_or_stop;   //0 vp_start, 1 vp_stop
	int id; 
	int size;
	int loop;
};

struct memory{
	int id;
	int size;
	int start;
	int stop;
	int xronos_zwhs_sth_mnimi;
};

struct id_vp_stop{
	int id;
	int wra_termatismoy;
};

int semup(int);

int semdown(int);

int arxikopoihsh_shmaforoy(int, int);

void diagrafi_shmaforoy(int);

void diagrafi_koinhs_mnhmhs(int);


void ektypwsh_Memory_Management(list<memory>);

void ektypwsh_Generator(list<memory>);


struct diergasia dimioyrgia_neas_diergasias(int);


int best_fit_eisagwgh(list<struct memory> &, struct memory);

int worst_fit_eisagwgh(list<struct memory> &, struct memory);

void diagrafi_apo_th_mnimi(list<struct memory> &, struct memory);


int yparksi_diergasias_sth_mnimi(list<struct memory>, struct memory);


void best_fit(list<memory> &, int, struct memory, int, list<memory> &);

void worst_fit(list<memory> &, int, struct memory, int, list<memory> &);

//void buddy_fit(list<memory> &, int, struct memory , int, list<memory> &);
