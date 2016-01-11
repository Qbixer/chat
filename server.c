#define USERS 10
#define LOGIN 12
#define POKOJE 5
#define WIADOMOSC 128
char zajeta[USERS];
char login[USERS][LOGIN];

struct pokoj{
char nazwa[LOGIN];
int id;
int ilosc;
};

#include <stdio.h>
#include <string.h>



char send[WIADOMOSC];
char get[WIADOMOSC];
struct pokoj pokoje[POKOJE];


void wysylanie(int i){


}



void pobieranie(){

}





int main(){

char rozkaz[6];

while(1){
	memset(get,0,sizeof(char));
	get();
	strncpy(get, rozkaz+2,6);
	if(strcmp(rozkaz,"\login")){
		logowanie();

	} else if(strcmp(rozkaz,"\lgout")){
		logout();
	} else if(strcmp(rozkaz,"\rlist")){

	} else if(strcmp(rozkaz,"\ulist")){

	} else if(strcmp(rozkaz,"\lgout")){

	} else if(strcmp(rozkaz,"\eroom")){

	} else if(strcmp(rozkaz,"\lroom")){

	} else if(strcmp(rozkaz,"\croom")){

	}else if(strcmp(rozkaz,"\mroom")){

	}else if(strcmp(rozkaz,"\muser")){

	}
	else{
		for(int i = 0; i<USERS;i++){
			
			strncpy(send, get,128);
			send(i+3);
		}	
	}

}
