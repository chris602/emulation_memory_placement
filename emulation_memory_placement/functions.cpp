#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <cmath>
#include "functions.h"

extern int hi, lo, T, D, t, S;
extern int sem_vp_message_read, sem_vp_message_write; 
extern struct vp_message *sharedmem_vp_message;


using namespace std;



int semup(int semid){
	struct sembuf sops;
	sops.sem_num = 0;
	sops.sem_op = 1;
	sops.sem_flg = 0; 
	if(semop(semid, &sops, 1) == -1){
		cout << "semop in semup failed" << endl;;
		return -1;
	}
	return 0;
}

int semdown(int semid){
	struct sembuf sops;
	sops.sem_num = 0;
	sops.sem_op = -1;
	sops.sem_flg = 0; 
	if(semop(semid, &sops, 1) == -1){
		cout << "semop in semdown failed" << endl;
		return -1;
	}
	return 0;
}

int arxikopoihsh_shmaforoy(int sem_id, int val){
	union semun arg;
	arg.val = val;
	if((semctl(sem_id, 0, SETVAL, arg)) == -1){
		cout << "semctl failed" << endl;
		return -1;
	}
	else{
		cout << "semctl succeedded" << endl;
		return 0;
	}
}

void diagrafi_shmaforoy(int semid){
	if(semctl(semid, IPC_RMID, 0) == -1){
		printf("H diagrafi shmaforoy apetyxe\n");
	}
}

void diagrafi_koinhs_mnhmhs(int shmid){
	if(shmctl(shmid, IPC_RMID, 0) == -1){
		printf("H diagrafi diamoirazomenhs mnhmhs apetyxe\n");
	}
}

void ektypwsh_Memory_Management(list<memory> a){
	list<memory>::iterator it_a;
	if(a.empty() != 0){
		for(it_a=a.begin() ; it_a!=a.end() ; it_a++){
			cout << "id: " << it_a->id  << " " << " size: " << it_a->size << endl;
		}
	}
}

void ektypwsh_Generator(list<memory> a){	
	list<memory>::iterator it_a;
	if(a.empty() != 0){
		for(it_a=a.begin() ; it_a!=a.end() ; it_a++){
			cout << "id: " << it_a->id  << " " << " size: " << it_a->size << endl;
		}
	}
}

struct diergasia dimioyrgia_neas_diergasias(int i){
	struct diergasia nea_diergasia;
	int megethos;
	int xronos_zwhs;
	double u;
	nea_diergasia.id = i;
	//cout << "HHHHHHHHHHHHHHHHHHHHH" << endl;
	megethos = rand()/(hi - lo) + lo;
	//cout << "SSSSSSSSSSSSSSSSSSSSS" << endl;
	nea_diergasia.size = megethos;
	u = 1.0/rand();
	xronos_zwhs = -1/T*log(u);
	nea_diergasia.duration = xronos_zwhs;
	return nea_diergasia;
} 

int best_fit_eisagwgh(list<struct memory> &lista, struct memory node){
	list<struct memory>::iterator it_lista;
	list<struct memory>::iterator it_temp;
	int current_ypoloipo;
	int min_ypoloipo = -1;
	for(it_lista=lista.begin() ; it_lista!=lista.end() ; it_lista++){
		if(it_lista->id != 0){  //id=0 => keno
			continue;
		}
		current_ypoloipo = it_lista->size - node.size;
		if(min_ypoloipo == -1 && (current_ypoloipo > 0 || current_ypoloipo == 0)){
			min_ypoloipo = current_ypoloipo;
			it_temp = it_lista;
		}
		else{
			if(min_ypoloipo > current_ypoloipo && (current_ypoloipo > 0 || current_ypoloipo == 0)){
				min_ypoloipo = current_ypoloipo;
				it_temp = it_lista;
			}
		}
	}
	if(min_ypoloipo == -1){
		cout << "H diergasia me id: " << node.id << "de mpike sth mnimi" << endl;
		return -1;
	}
	else{
		if(min_ypoloipo != 0){
			lista.insert(it_temp, node);
			it_temp->size = it_temp->size - node.size;  //meiwnw to keno logw eisagwghs ths diergasias
		}
		if(min_ypoloipo == 0){
			it_temp->id = node.id;
		}
	    return 0;
	}
}

int worst_fit_eisagwgh(list<struct memory> &lista, struct memory node){
	list<struct memory>::iterator it_lista;
	list<struct memory>::iterator it_temp;
	int current_ypoloipo;
	int max_ypoloipo = -1;
	for(it_lista=lista.begin() ; it_lista!=lista.end() ; it_lista++){
		if(it_lista->id != 0){  //id=0 => keno
			continue;
		}
		current_ypoloipo = it_lista->size - node.size;
		if(max_ypoloipo == -1 && (current_ypoloipo > 0 || current_ypoloipo == 0)){
			max_ypoloipo = current_ypoloipo;
			it_temp = it_lista;
		}
		else{
			if(max_ypoloipo < current_ypoloipo && (current_ypoloipo > 0 || current_ypoloipo == 0)){
				max_ypoloipo = current_ypoloipo;
				it_temp = it_lista;
			}
		}
	}
	if(max_ypoloipo == -1){
		cout << "H diergasia me id: " << node.id << "de mpike sth mnimi" << endl;
		return -1;
	}
	else{
		if(max_ypoloipo != 0){
			lista.insert(it_temp, node);
			it_temp->size = it_temp->size - node.size;  //meiwnw to keno logw eisagwghs ths diergasias
		}
		if(max_ypoloipo == 0){
			it_temp->id = node.id;
		}
	    return 0;
	}
}
	

void diagrafi_apo_th_mnimi(list<struct memory> &lista, struct memory node){  //kai gia best_fit kai gia worst_fit
	list<struct memory>::iterator it_lista;
	list<struct memory>::iterator it_temp;
	list<struct memory>::iterator it_previous;
	list<struct memory>::iterator it_next;
	int total_size;
	for(it_lista=lista.begin() ; it_lista!=lista.end() ; it_lista++){
		if(it_lista->id == node.id){
			it_temp = it_lista;
			break;
		}
	}
	it_previous = it_temp;
	it_previous--;
	it_next = it_temp;
	it_next++;
	if(it_previous->id == 0 && it_next->id == 0){
		total_size = it_previous->size + it_temp->size + it_next->size;
		it_temp = lista.erase(it_temp);
		it_temp = lista.erase(it_next);
		it_previous->size = total_size;
	}
	else if(it_previous->id == 0 && it_next->id != 0){
		total_size = it_previous->size + it_temp->size;
		it_temp = lista.erase(it_temp);
		it_previous->size = total_size;
	}
	else if(it_previous->id != 0 && it_next->id == 0){
		total_size = it_temp->size + it_next->size;
		it_temp = lista.erase(it_temp);
		it_next->size = total_size;
	}
	else if(it_previous->id != 0 && it_next->id != 0){
		it_temp->id = 0;
	}
}

int yparksi_diergasias_sth_mnimi(list<struct memory> lista, struct memory node){
	list<struct memory>::iterator it_lista;
	if(lista.empty() == 0){
		return -1;
	}
	for(it_lista=lista.begin() ; it_lista!=lista.end() ; it_lista++){
		if(it_lista->id == node.id){
			return 0;
		}
	}
	return -1;
}
	
void best_fit(list<struct memory> &lista, int start_or_stop, struct memory node, int i, list<memory> &lista_L){
	int elegxos;
	list<struct memory>::iterator it_lista;
	list<struct memory>::iterator it_temp;
	if(start_or_stop == 0){  //vp_start
		node.start = i;
		elegxos = best_fit_eisagwgh(lista, node);
		if(elegxos == -1){
			lista_L.push_back(node);
		}
	}
	if(start_or_stop == 1){  //vp_stop
		if(yparksi_diergasias_sth_mnimi(lista, node) == 0){  //an yparxei sth mnimi
			for(it_lista=lista.begin() ; it_lista!=lista.end() ; it_lista++){
				if(node.id != it_lista->id){
					continue;
				}
				else{
					if(it_lista->xronos_zwhs_sth_mnimi == i - it_lista->start){
						diagrafi_apo_th_mnimi(lista, *it_lista);
						break;
					}
					else{
						it_lista->stop = i;
						it_lista->xronos_zwhs_sth_mnimi = it_lista->stop - it_lista->start;
						break;
					}
				}
			}
		}
		else{  //an einai sthn L
			for(it_lista=lista_L.begin() ; it_lista!=lista_L.end() ; it_lista++){
				if(node.id != it_lista->id){
					continue;
				}
				else{
					it_lista->stop = i;
					it_lista->xronos_zwhs_sth_mnimi = it_lista->stop - it_lista->start;
					break;
				}		
			}
		}
	}
	if(lista.empty() != 0){
		for(it_lista=lista.begin() ; it_lista!=lista.end() ; it_lista++){ //tsekarw poies diergasies (an yparxoyn) prepei na termatistoyn
			if(it_lista->xronos_zwhs_sth_mnimi == i - it_lista->start){
				diagrafi_apo_th_mnimi(lista, *it_lista);
			}
		}
	}
	if(lista.empty() != 0){
		for(it_lista=lista_L.begin() ; it_lista!=lista_L.end() ; it_lista++){  //tsekarw an mporei kapoia apo tis diergasies poy einai se anamoni sthn L mporoyn na mpoyn sth minimi
			if(best_fit_eisagwgh(lista, *it_lista) == -1){
				continue;
			}
			else{
				it_temp = it_lista;
				diagrafi_apo_th_mnimi(lista_L, *it_lista);
				it_temp->xronos_zwhs_sth_mnimi = 0;
			}
		}
	}
	if(lista.empty() !=0){
		for(it_lista=lista.begin() ; it_lista!=lista.end() ; it_lista++){  //ayksanw toys xronoys zwhs sth mnimi gia oles tis diergasies ektos apaytes poy mpikan sthn prohgoymenh for
			if(it_lista->xronos_zwhs_sth_mnimi != 0){
				it_lista->xronos_zwhs_sth_mnimi++;
			}
		}
	}
	 ektypwsh_Memory_Management(lista);
	 ektypwsh_Memory_Management(lista_L);
}

void worst_fit(list<struct memory> &lista, int start_or_stop, struct memory node, int i, list<memory> &lista_L){
	int elegxos;
	list<struct memory>::iterator it_lista;
	list<struct memory>::iterator it_temp;
	if(start_or_stop == 0){  //vp_start
		node.start = i;
		elegxos = worst_fit_eisagwgh(lista, node);
		if(elegxos == -1){
			lista_L.push_back(node);
		}
	}
	if(start_or_stop == 1){  //vp_stop
		if(yparksi_diergasias_sth_mnimi(lista, node) == 0){  //an yparxei sth mnimi
			for(it_lista=lista.begin() ; it_lista!=lista.end() ; it_lista++){
				if(node.id != it_lista->id){
					continue;
				}
				else{
					if(it_lista->xronos_zwhs_sth_mnimi == i - it_lista->start){
						diagrafi_apo_th_mnimi(lista, *it_lista);
						break;
					}
					else{
						it_lista->stop = i;
						it_lista->xronos_zwhs_sth_mnimi = it_lista->stop - it_lista->start;
						break;
					}
				}
			}
		}
		else{  //an einai sthn L
			for(it_lista=lista_L.begin() ; it_lista!=lista_L.end() ; it_lista++){
				if(node.id != it_lista->id){
					continue;
				}
				else{
					it_lista->stop = i;
					it_lista->xronos_zwhs_sth_mnimi = it_lista->stop - it_lista->start;
					break;
				}		
			}
		}
	}
	if(lista.empty() != 0){
		for(it_lista=lista.begin() ; it_lista!=lista.end() ; it_lista++){ //tsekarw poies diergasies (an yparxoyn) prepei na termatistoyn
			if(it_lista->xronos_zwhs_sth_mnimi == i - it_lista->start){
				diagrafi_apo_th_mnimi(lista, *it_lista);
			}
		}
	}
	if(lista.empty() != 0){
		for(it_lista=lista_L.begin() ; it_lista!=lista_L.end() ; it_lista++){  //tsekarw an mporei kapoia apo tis diergasies poy einai se anamoni sthn L mporoyn na mpoyn sth minimi
			if(worst_fit_eisagwgh(lista, *it_lista) == -1){
				continue;
			}
			else{
				it_temp = it_lista;
				diagrafi_apo_th_mnimi(lista_L, *it_lista);
				it_temp->xronos_zwhs_sth_mnimi = 0;
			}
		}
	}
	if(lista.empty() !=0){
		for(it_lista=lista.begin() ; it_lista!=lista.end() ; it_lista++){  //ayksanw toys xronoys zwhs sth mnimi gia oles tis diergasies ektos apaytes poy mpikan sthn prohgoymenh for
			if(it_lista->xronos_zwhs_sth_mnimi != 0){
				it_lista->xronos_zwhs_sth_mnimi++;
			}
		}
	}
	 ektypwsh_Memory_Management(lista);
	 ektypwsh_Memory_Management(lista_L);
}	
	
	
	
	
	
	
	
	
	
	
				
