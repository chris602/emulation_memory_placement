#include <iostream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h> 
#include <sys/shm.h> 
#include <sys/wait.h>
#include <sys/time.h>
#include <unistd.h>
#include <list>
#include "functions.h"

//int hi = 10, lo = 5, T = 4, D = 5, t = 2, S = 20;
int hi, lo, T, D, t, S;
int sem_vp_message_read, sem_vp_message_write; 
struct vp_message *sharedmem_vp_message;

using namespace std;


int main(int argc, char *argv[]){
	int pid, i, j = 0, k; 
	int leitoyrgia_start_or_stop;
	int xronos_afiksis_epomenhs_diergasias;
	double u;
	int shmid_vp_message;
	struct diergasia nea_diergasia;
	struct id_vp_stop node_id_vp_stop;
	struct memory arxiki_mnimi;
	struct memory antigrafo_neas_diergasias;
	list<struct id_vp_stop> lista_generator;	
	list<struct id_vp_stop>::iterator it_lista_generator;
	list<struct memory> lista_best_fit, lista_worst_fit, lista_buddy;  //listes mnimis
	list<struct memory>::iterator it_lista_best_fit;
	list<struct memory>::iterator it_lista_worst_fit;
	list<struct memory>::iterator it_lista_buddy;
	list<struct memory> lista_best_fit_L, lista_worst_fit_L, lista_buddy_L;  //listes anamonhs
	list<struct memory>::iterator it_lista_best_fit_L;
	list<struct memory>::iterator it_lista_worst_fit_L;
	list<struct memory>::iterator it_lista_buddy_L;
	if(argc != 7){
		cout << "Dwste orismata" << endl;
		exit(1);
	}
	hi = atoi(argv[1]);
	lo = atoi(argv[2]);
	T = atoi(argv[3]);
	D = atoi(argv[4]);
	t = atoi(argv[5]);
	S = atoi(argv[6]);
	if((sem_vp_message_read = semget(IPC_PRIVATE, 1, 0666 | IPC_CREAT)) == -1){
		cout << "semget_sem_vp_message_read failed" << endl;
		exit(1);
	}	
	else{
		cout << "semget_sem_vp_message_read succeeded " << endl;
	}
	if((sem_vp_message_write = semget(IPC_PRIVATE, 1, 0666 | IPC_CREAT)) == -1){
		cout << "semget_sem_vp_message_write failed" << endl;
		exit(1);
	}	
	else{
		cout << "semget_sem_vp_message_write succeeded " << endl;
	}
	if((arxikopoihsh_shmaforoy(sem_vp_message_read, 0)) == -1){
		cout << "arxikopoihsh sem_vp_message_read failed" << endl;
	}
	else{
		cout << "arxikopoihsh sem_vp_message_read succeeded" << endl;
	}
	
	if((arxikopoihsh_shmaforoy(sem_vp_message_write, 1)) == -1){
		cout << "arxikopoihsh sem_vp_message_write failed" << endl;
	}
	else{
		cout << "arxikopoihsh sem_vp_message_write succeeded" << endl;
	}
	if((shmid_vp_message = shmget(IPC_PRIVATE, sizeof(struct vp_message), IPC_CREAT | 0666)) == -1){    //desmeysh mnhmhs gia ta IN kai OUT
		cout << "shmget_shmid_vp_message failed" << endl;
		exit(1);
	}
	else{
		cout << "shmget_shmid_vp_message succeeded" << endl;
	}
	if((int) (sharedmem_vp_message = (struct vp_message *) shmat(shmid_vp_message, NULL, 0)) == -1){
		printf("shmat_sharedmem_vp_message failed\n");
	}
	else{
		printf("shmat_sharedmem_vp_message succeeded\n");
	}
	srand(time(NULL));
	pid = fork();
	switch(pid){
			case -1:
					cout << "Fork failed";
					exit(1);
					
					
			case 0:  //Memory Management
					cout << "Eimai h Memory Management" << endl;
					arxiki_mnimi.id = 0;
					arxiki_mnimi.size = S;
					//cout << "AAAAAAAAAAAAAAAA" << endl;
					lista_best_fit.push_back(arxiki_mnimi);
					lista_worst_fit.push_back(arxiki_mnimi);
					lista_buddy.push_back(arxiki_mnimi);
					//cout << "bbbbbbbbbbbbbbbbb" << endl;
						//cout << "CCCCCCCCCCCCCCC" << endl;
						if((semdown(sem_vp_message_read)) == -1){
							cout << "down_sem_vp_message_read failed" << endl;
							exit(1);
						}
						//cout << "DDDDDDDDDDDDDDDDDDD" << endl;
						antigrafo_neas_diergasias.id = sharedmem_vp_message->id;
						antigrafo_neas_diergasias.size = sharedmem_vp_message->size;
						antigrafo_neas_diergasias.xronos_zwhs_sth_mnimi = 0;
						leitoyrgia_start_or_stop = sharedmem_vp_message->start_or_stop;
						 k = sharedmem_vp_message->loop;
						//cout << "EEEEEEEEEEEEEEEEEEEEE" << endl;
						if((semup(sem_vp_message_write)) == -1){
							cout << "down_sem_vp_message_write failed" << endl;
							exit(1);
						}
					//	cout << "FFFFFFFFFFFFFFFFFFFFFF" << endl;
						best_fit(lista_best_fit, leitoyrgia_start_or_stop, antigrafo_neas_diergasias, k, lista_best_fit_L);
					//	worst_fit(lista_worst_fit, leitoyrgia_start_or_stop, antigrafo_neas_diergasias, k, lista_worst_fit_L);					
					//	buddy_fit(lista_buddy, leitoyrgia_start_or_stop, antigrafo_neas_diergasias, k, lista_buddy_L;
					break;				
					
					
					
			default:  //Generator
					cout << "Eimai h Generator" << endl;
					xronos_afiksis_epomenhs_diergasias = 0; //To kanw 0 mono gia thn 1h fora, gia na ftiaxtei h 1h diergasia
					for(i=0 ; i<D ; i++){
						if(i == xronos_afiksis_epomenhs_diergasias){
							//cout << "HHHHHHHHHHHHHHHHHHHHHH" << endl;
							nea_diergasia = dimioyrgia_neas_diergasias(++j);
							if((semdown(sem_vp_message_write)) == -1){
								cout << "down_sem_vp_message_write failed" << endl;
								exit(1);
							}
							//cout << "IIIIIIIIIIIIIIIIIIII" << endl;
							sharedmem_vp_message->start_or_stop = 0;
							sharedmem_vp_message->id = j;
							sharedmem_vp_message->size = nea_diergasia.size;
							sharedmem_vp_message->loop = i;
							//cout << "JJJJJJJJJJJJJJJJJJJ" << endl;						
							if((semup(sem_vp_message_read)) == -1){
								cout << "up_sem_vp_message_read failed" << endl;
								exit(1);
							}
							//cout << "KKKKKKKKKKKKKKKKKKKKKK" << endl;
							u = 1.0/rand();
							xronos_afiksis_epomenhs_diergasias = -(1/t)*log(u);
							node_id_vp_stop.id = nea_diergasia.id;
							node_id_vp_stop.wra_termatismoy = i + nea_diergasia.duration;
							lista_generator.push_back(node_id_vp_stop);
						}
						//cout << "GGGGGGGGGGGGGGGGGGGGGGGG" << endl;
						if(lista_generator.empty() != 0){
							for(it_lista_generator = lista_generator.begin() ; it_lista_generator != lista_generator.end() ; it_lista_generator++){
								if(it_lista_generator->wra_termatismoy == i){
									if((semdown(sem_vp_message_write)) == -1){
										cout << "down_sem_vp_message_write failed" << endl;
										exit(1);
									}
									sharedmem_vp_message->start_or_stop = 1;
									sharedmem_vp_message->id = it_lista_generator->id;
									sharedmem_vp_message->loop = i;						
									if((semup(sem_vp_message_read)) == -1){
										cout << "up_sem_vp_message_read failed" << endl;
										exit(1);
									}								
									it_lista_generator = lista_generator.erase(it_lista_generator);
									it_lista_generator--;
								}
							}
						}
					}
					break;					
	}
	while(wait(0) > 0){}
	diagrafi_shmaforoy(sem_vp_message_write);
	diagrafi_shmaforoy(sem_vp_message_read);
	diagrafi_koinhs_mnhmhs(shmid_vp_message);
	return 0;
		
}
