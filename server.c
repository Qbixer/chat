#define USERS 10 //Maksymalna ilosc uzytkownikow
#define LOGIN 12 //Dlugosc loginu - stala
#define POKOJE 5 //Mozliwa ilosc pokojow
#define WIADOMOSC 180 //Maksymalna dlugosc wiadomosci


#include <stdio.h>
#include <string.h>

struct pokoj{
	char nazwa[LOGIN]; //nazwa pokoju
	char dostepny[USERS];//czy dany uzytkownik jest dostepny
	unsigned char uzytkownicy[USERS];//lista uzytkownikow
};

char zalogowany[USERS]; //1 jesli uzytkownik jest zalogowany 0 jewli nie, nr w tablicy to identyfikator użytkownika
char login[USERS][LOGIN]; //Przechowuje nazwy użytkowników, nr w tablicy to identyfikator użytkownika
char send[WIADOMOSC];//Wiadomosc do wyslania
char get[WIADOMOSC];//wiadomosc otrzymana
char pokoj_dostepny[POKOJE];//czy dany pokoj jest dostepny nr w tablicy identyfikatorem pokoju
struct pokoj pokoje[POKOJE];//struktura pokoju numer w tablicy jest identyfikatorem pokoju

//Wysylanie wiadomosci
void wysylanie(){


}


//Pobieranie
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

/*
 *Zwraca listę pokojów
 *
 *przykładowa informacja zwrotna:
 * "Pokoje: pokoj_a pokoj_b pokoj_c\0"
 */

void listapokojow() {
	int i;
	strcpy(send, "Pokoje: ");
	for (i = 0; i < POKOJE; i++) {
		if(pokoj_dostepny[i]){
			strcat(send,pokoje[i].nazwa);
			strcat(send," ");
		}
	}
}


/*
 *Zwraca listę zalogowanych uzytkownikow
 *
 *przykładowa wiadomość zwrotna:
 * "Zalogowani: Marek Zenon Tomasz\0"
 */
void listauzytkownikow(){
	int i;
	strcpy(send, "Zalogowani: ");
	for (i = 0; i < USERS; i++) {
		if(zalogowany[i]){
			strcat(send,login[i]);
			strcat(send," ");
		}
	}
}

/*
 * Return 0 jeśli nie musi wysyłać informacji zwrotnej
 * return 1 jeśli musi
 */
int wykonywanie(){
	char rozkaz[6];
	strncpy(get+1, rozkaz, 6);
	if (strcmp(rozkaz, "/login")) {
		logowanie();
	} else if (strcmp(rozkaz, "/lgout")) {
		wylogowywanie();
	} else if (strcmp(rozkaz, "/rlist")) {
		listapokojow();
	} else if (strcmp(rozkaz, "/ulist")) {
		listauzytkownikow();
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
 * Przykladowa wiadomość od uzytkownika
 *  Identyfikator użytkownika, dodawany automatycznie przez program klienta, 1 char
 *  |
 *  |  _________rozkaz 6 charów
 *  | |   |
 *  | |   |
 *  "c/login Zenon\0"
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