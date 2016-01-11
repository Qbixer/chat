#define USERS 10
#define LOGIN 12
#define POKOJE 5
#define WIADOMOSC 128

#include <stdio.h>
#include <string.h>

struct pokoj{
	char nazwa[LOGIN];
	int ilosc;
	int uzytkownicy[USERS];
};

char zalogowany[USERS];
char login[USERS][LOGIN];
char send[WIADOMOSC];
char get[WIADOMOSC];
char pokoj_dostepny[POKOJE];
struct pokoj pokoje[POKOJE];


void wysylanie(){


}



void pobieranie(){

}

// return 1,gdy nie ma użytkownika w bazie
// return 0,gdy pomyślnie zalogowano
// return 2, gdy jest już zalogowany
int logowanie(){
	char Login[12];
	strncpy(get + 8, Login , 12);
	int i;
	for(i = 0;i<USERS;i++){
		if(!strcmp(Login,login[i])){
			if(zalogowany[i] == 1)
				return 2;
			else{
				zalogowany[i] = 1;
				return 0;
			}
		}
	}
	return 1;
}


/*
 * 0 użytkownik pomyślnie wylogowany
 * 1 użytkownik nie był zalogowany
 */
int wylogowywanie(){
	if(zalogowany[get[0]]){
		zalogowany[get[0]] = 0;
		return 0;
	}else
		return 1;
}

void listapokojow(){
	for(int<)
}

/*
 * Return 0 jeśli nie musi wysyłać informacji zwrotnej
 * return 1 jeśli musi
 */
int wykonaj(){
	char rozkaz[6];
	strncpy(get+1, rozkaz, 6);
	if (strcmp(rozkaz, "/login")) {
		logowanie();
	} else if (strcmp(rozkaz, "/lgout")) {
		wylogowywanie();
	} else if (strcmp(rozkaz, "/rlist")) {
		listapokojow();
	} else if (strcmp(rozkaz, "/ulist")) {

	} else if (strcmp(rozkaz, "/lgout")) {

	} else if (strcmp(rozkaz, "/eroom")) {

	} else if (strcmp(rozkaz, "/lroom")) {

	} else if (strcmp(rozkaz, "/croom")) {

	} else if (strcmp(rozkaz, "/mroom")) {

	} else if (strcmp(rozkaz, "/muser")) {

	}
	else {

	}
}


/*
 *  Identyfikator użytkownika, dodawany automatycznie przez program klienta, 1 char
 *  |
 *  |  _________rozkaz 6 charów
 *  | |   |
 *  | |   |
 *  c/login Zenon
 */


int main() {

	while (1) {

		memset(get, 0, sizeof(char)*WIADOMOSC);
		memset(send, 0, sizeof(char)*WIADOMOSC);
		pobieranie();
		if(wykonywanie()) {
			wysylanie();
		}

	}
}