#define USERS 10
#define LOGIN 12
#define POKOJE 5
#define WIADOMOSC 128

#include <stdio.h>
#include <string.h>

struct pokoj{
	char nazwa[LOGIN];
	int id;
	int ilosc;
	int uzytkownicy[USERS];
};

char zajety[USERS];
char login[USERS][LOGIN];
char send[WIADOMOSC];
char get[WIADOMOSC];
struct pokoj pokoje[POKOJE];


void wysylanie(int i){


}



void pobieranie(){

}

void logowanie(){


}

wylogowywanie(){


}



int main() {

	char rozkaz[6];

	while (1) {
		memset(get, 0, sizeof(char));
		pobieranie();
		strncpy(get, rozkaz + 2, 6);
		if (strcmp(rozkaz, "/login")) {
			logowanie();

		} else if (strcmp(rozkaz, "/lgout")) {
			wylogowywanie();
		} else if (strcmp(rozkaz, "/rlist")) {

		} else if (strcmp(rozkaz, "/ulist")) {

		} else if (strcmp(rozkaz, "/lgout")) {

		} else if (strcmp(rozkaz, "/eroom")) {

		} else if (strcmp(rozkaz, "/lroom")) {

		} else if (strcmp(rozkaz, "/croom")) {

		} else if (strcmp(rozkaz, "/mroom")) {

		} else if (strcmp(rozkaz, "/muser")) {

		}
		else {
			int i;
			for (i = 0; i < USERS; i++) {

				strncpy(send, get, 128);
				wysylanie(i + 3);
			}
		}
	}
}