#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//Nisam stigao sve da prokomentarisem, ali potrudio sam se sto vise da prokomentarisem kako bi kod bio laksi da pregledanje

//TEKSTOVI
/*
    U prostoru TEKSTOVI se nalaze funkcije ciji je glavni cilj da ispisuju tekst na ekran.
    Nisam sve tekstove koje se ispisuju na ekran stavio u posebne funkcije, ali sam stavio vecinu.
    Ovo sam uradiko kako bih olaksao ponovno pisanje istog teksta.
*/
void dd(); //Ispisuje dobar dan
void c(); //Brise sve sa ekrana
void vi(); //Ovo ispisuje tekst "Vas Izbor", praceno sa strelicom, ocekujuci od korisnika da izabere opciju.
void vu(); //Ovo ispisuje tekst "Vas Unos", praceno sa strelicom, ocekujuci od korisnika da unese niz karaktera.

/*
    Ovo sledece nisu konkretni meniji, vec samo tekst koji se ispise.
    Drugim recima, oni funkcionalno nista ne rade osim sto ispisuju opcije menija.
    Funkcionalnost menija sam realizovao u posebnom prostoru pod imenom "MENIJI".
*/
void izlMTxt(); //Kada se izabere opcija za izlazak iz programa, ovaj meni ce se pojaviti.
void osnMTxt(); //Kada se pokrene program, ovo je prvi meni koji korisnik vidi (sadrzi osnovne opcije).
void datMTxt(); //Kada se izabere opcija za rad sa datotekama, ovaj meni ce se pojaviti.
void sloMTxt(); //Kada se izabere opcija za rad sa slogovima, ovaj meni ce se pojaviti.
void uneMTxt(); //Ovaj meni pita korisnika da li zeli ponovo da unese slog u datoteku (prilikom kreiranja u realnom vremenu).
void sekPTxt(); //Kada se ubaci novi slog u datoteku, ovaj meni ce se pojaviti (da li zelis da tu datoteku pretvoris u sekvencijalnu).
void citSTxt(); //Kada se izabere opcija za trazenje sloga, ovaj meni ce se pojaviti (pita korisnika da li zeli da najde random ili konkretan slog).

void izbOp(int i, char st[50]); //Govori koja je opcija izabrana (pojavljuje se nakon izbora osnovne opcije).
void losOp(); //Ovo se ispise svaki put kada korisnik unese opciju koja nije jedna od ponudjenih.
void kreiF(char st[50]); //Obavestava korisnika da je kreirana nova datoteka i pod kojim je imenom kreirana.
void izbP(); //Ispisuje liniju "Izaberite jednu od ponudjenih opcija:" (ovo sam realizovao kao funkciju cisto da ne bih morao da ponavljam isti printf).
void izabF(char st[50]); //Javlja korisniku da je uspesno selektovana datoteka i ime te datoteke (pojavljuje se prilikom selektovanja datoteke).
void neIzabF(char st[50]); //Javlja se ukoliko ne postoji datoteka sa imenom koje je korisnik naveo.
void prikIme(char st[50]); //Prikazuje ime trenutno aktivne datoteke
void neOtv(); //Ukoliko se izabere neka opcija koja zahteva aktivnu/otvorrenu datoteku (a nijedna datoteka trenutno nije otvorena), ovo ce se pojaviti.
void prikNaz(); //Ispisuje ime trenutno aktivne datoteke.
void uspUpis(); //Obavestava korisnika da su podaci koej je naveo uspesno upisani u datoteku

void ispSlog(); //Ispisuje (random ili konkretno) selektovan slog na ekran.


//MENIJI
/*
    U prostoru MENIJI sam realizovao sta konkretne funkcionalnosti menija.
    U vecini menija, to podrazumeva switch-case pomocu kog korisnik bira opciju.
*/
void izlaz(int i); //Korisnik precizira da li je siguran da hoce da izadje iz programa.
void osnovneOpcije(int i); //Korisnik bira jednu od tri ponudjene osnovne opcije (rad sa datotekama, rad sa slogovima ili izlazak iz programa).
void radSaDatotekama(int i); //Korisnik bira jednu od sest opcija za rad sa datotekaama (trebalo je biti 7, ali nisam stigao/znao da ih sve realizujem).
void radSaSlogovima(int i); //Korisnik bira jednu od 3 opcija za rad sa slogovima (trebalo je biti 9, ali nisam stigao/znao da ih sve realizujem).

void unesiIme(int i); //Korisnik treba da unese zeljeno ime datoteke
void dalDaUne(int i); //Korisnik bira da li zeli da unese novi podatak u datoteku
void dalDaPravSek(int i); //Korisnik bira da li zeli iz serijske datoteke (u koju je ubacio slog) da napravi sekvencijalnu datoteku

//FUNKCIONALNOSTI
/*
    Ovde su "glavne" funkcionalnosti.
    Podrazumevaju konkretno pravljenje datoteka, upisivanje slogova, formiranje serijskih i sekvencijalnih datoteka i ostale opcije.
*/
void kreiDat(int i, char st[50]); //Funkcija namenjena za kreiranje nove datoteke
void izabDat(int i, char st[50]); //Funkcija namenjena za biranje postojece datoteke
void prikNazDat(int i); //Funkcija namenjena za prikaz imena datoteke
void unePod(int i);
void napElem(int i);
void sorLis();
int porKlj(char st1[50], char st2[50]);
//void zamElem(struct elem * l1, struct elem * l2);
void upiElem(int i);
void dodSlog(int i);
void citSlog(int i);
void randSlog(int i);
void konkSlog(int i);

void prikElem(int i);

//KREIRANJE PODATKA

void e();
void p();
void d();
void v();
void o();
void t();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct osoba {
    char evibro[8];
    char pozbro[17];
    char datbro[9];
    char vrebro[7];
    char oznbro[4];
    char trabro[7];
};

struct blok {
    char check;
    struct osoba oo1;
    struct osoba oo2;
    struct osoba oo3;
};

typedef struct elem {
    struct blok o;
    struct elem * sledeci;
} lista;

struct aktivna_datoteka {
   FILE *aktivna;
   char *aktIme[50];
};

struct aktivna_datoteka aktiv;
struct blok os,os0;

lista * prvi;

int brojElem = 0;

/*
    elem1(vrednost=v1, sledeci=elem2(vrednost=v2, sledeci=elem3(vrednost=v3, sledeci)))
    elem1(vrednost=v1, sledeci=elem1(vrednost=v1, sledeci=elem1(vrednost=v1, sledeci=elem1(vrednost=v1, sledeci=elem1(vrednost=v1, sledeci)))))
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void dd()
{
	printf("Dobar dan!\n");
	printf("Dobrodosli u program za rad sa pozivima gradjana.\n\n");
}

void c()
{
	system("@cls||clear");
}

void vi()
{
    printf("\nVas izbor ---> ");
}

void vu()
{
    printf("\nVas unos ---> ");
}

void izlMTxt()
{
    printf("Da li ste sigurni da zelite da izadjete iz programa?\n");
    printf("1 ----- Da\n");
    printf("2 ----- Ne\n");
    vi();
}

void osnMTxt()
{
    printf("1 ----- Rad sa datotekama\n");
    printf("2 ----- Rad sa slogovima\n");
    printf("0 ----- Izadji iz programa\n");
    vi();
}

void datMTxt()
{
    printf("1 ----- Kreiraj praznu datoteku\n");
    printf("2 ----- Izaberi aktivnu datoteku\n");
    printf("3 ----- Prikazi naziv aktivne datoteke\n");
    printf("4 ----- Formiraj serijsku datoteku i upisi u nju podatke\n");
    printf("5 ----- Uzmi podatke iz serijske datoteke i stavi u sekvencijalnu datoteku\n");
    printf("6 ----- Test citanja\n");
    //printf("6 ----- Formiraj aktivnu datoteku\n");
    printf("0 ----- Nazad\n");
    vi();
}

void sloMTxt()
{
    printf("1 ----- Upisi novi slog u serijsku/sekvencijalnu datoteku\n");
    printf("2 ----- Nadji i prikazi proizvoljni slog iz serijske/sekvencijalne datoteke\n");
    //printf("3 ----- Izbrisi aktuelan slog iz serijske/sekvencijalne datoteke\n");
    //printf("4 ----- Promeni datum i vreme sloga serijske/sekvencijalne datoteke\n");
    //printf("5 ----- Upisi novi slog u ind-sek datoteku\n");
    //printf("6 ----- Nadji i prikazi proizvoljni slog iz ind-sek datoteke\n");
    //printf("7 ----- Izbrisi aktuelan slog iz ind-sek datoteke\n");
    //printf("8 ----- Promeni datum i vreme sloga ind-sek datoteke\n");
    printf("0 ----- Nazad\n");
    vi();
}

void uneMTxt()
{
    printf("Da li zelite da unesete novi podatak u ovu datoteku?\n");
    printf("1 ----- Da\n");
    printf("2 ----- Ne\n");
    vi();
}

void sekPTxt()
{
    printf("Da li zelite iz ove datoteke da napravite sekvencijalnu datoteku?\n");
    printf("1 ----- Da\n");
    printf("2 ----- Ne\n");
    vi();
}

void citSTxt()
{
    printf("Da li zelite da nadjete random slog ili konkretan slog?\n");
    printf("1 ----- Random slog\n");
    printf("2 ----- Konkretan slog\n");
    vi();
}

void izbOp(int i, char st[50])
{
	char *ptr = (char*)malloc((strlen(st)+1) * sizeof(char));
	if(ptr == NULL)
    {
        printf("Nema dovoljno memorije!");
        exit(0);
    }
	printf("Izabrali ste opciju %d: %s", i, st);
	free(ptr);
}

void losOp()
{
	printf("Izabrali ste nepostojecu opciju!\n\n");
}

void kreiF(char st[50])
{
	printf("Kreirali ste novu datoteku pod imenom %s.\n\n", st);
}

void izbP()
{
	printf("Izaberite jednu od ponudjenih opcija:\n");
}

void izabF(char st[50])
{
	printf("Selektovali ste datoteku pod imenom %s.\n\n", st);
}

void neIzabF(char st[50])
{
	printf("Ne postoji nijedna datoteka koja je kreirana pod imenom %s!\n\n", st);
}

void prikIme(char st[50])
{
    printf("Trenutno aktivna datoteka se zove %s.\n\n", st);
}

void neOtv()
{
    printf("Nije otvorena nijedna datoteka!\n\n");
}

void prikNaz()
{
    printf("Ime trenutno aktivne datoteke je: %s.\n\n",aktiv.aktIme);
}

void uspUpis()
{
    printf("Navedeni podaci su uspesno upisani u datoteku!\n\n");
}

void ispSlog()
{
    printf("Evidencioni broj: %s\n", os.oo1.evibro);
    printf("Telefonski broj pozivaoca: %s\n", os.oo1.pozbro);
    printf("Datum poziva: %s\n", os.oo1.datbro);
    printf("Vreme poziva: %s\n", os.oo1.vrebro);
    printf("Oznaka poziva: %s\n", os.oo1.oznbro);
    printf("Duzina trajanja poziva: %s\n", os.oo1.trabro);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void izlaz(int i)
{
    /*
        Realizovao sam na sledeci nacin:
            - Ispise se text menija
            - Korisnik izabere opciju
            - Ako je izabrao 1, izlazi se iz programa
            - Ako je izabrao 2, program ga vraca na meni sa osnovnim opcijama
    */
	c();
	do
	{
		izlMTxt();
		scanf("%d", &i);
		switch(i)
		{
			case 1:
				exit(0);
				break;
			case 2:
			    c();
			    dd();
				osnovneOpcije(i);
				break;
			default:
				i = 999999;
				c();
				losOp();
				break;
		}
	}
	while (i == 999999);

}

void osnovneOpcije(int i)
{
    /*
        Realizovao sam na sledeci nacin:
            - Ispisuje se text menija
            - Korisnik izabere opciju
            - Ako je izabrao 1, program ga prebacuje na meni za rad sa datotekama
            - Ako je izabrao 2, program ga prebacuje na meni za rad sa slogovima
            - Ako je izabrao 3, program ga prebacuje na meni za izlaz iz programa
    */
	do
	{
		izbP();
		osnMTxt();
		scanf("%d", &i);
		switch(i)
		{
			case 1:
				c();
				dd();
				izbOp(i,"Rad sa datotekama.\n\n");
				radSaDatotekama(i);
				break;
			case 2:
				c();
				dd();
				izbOp(i,"Rad sa slogovima.\n\n");
				radSaSlogovima(i);
				break;
			case 0:
			    izlaz(i);
				break;
			default:
				i = 999999;
				c();
				dd();
				losOp();
				break;
		}
	}
	while (i == 999999);
}

void radSaDatotekama(int i)
{
    /*
        Realizovao sam na sledeci nacin:
            - Ispisuje se text menija
            - Korisnik izabere opciju
            - Ako je izabrao 1, bice upucen na kreiranje prazne datoteke
            - Ako je izabrao 2, bice upucen na biranje aktivne datoteke
            - Ako je izabrao 3, bice mu prikazan naziv aktivne datoteke (ako postoji)
            - Ako je izabrao 4, bice upucen na kreiranje serijske datoteke
            - Ako je izabrao 5, bice upucen na kreiranje sekvencijalne datoteke uz pomoc serijske
            - Ako je izabrao 0, vratice se meni sa osnovnim opcijama
    */
	do
	{
		izbP();
		datMTxt();
		scanf("%d", &i);
		switch(i)
		{
			case 1:
				unesiIme(i);
				break;
			case 2:
				unesiIme(i);
				break;
			case 3:
				prikNazDat(i);
				break;
			case 4:
				unesiIme(i);
				break;
			case 5:
				unesiIme(i);
				break;
			case 6:
				prikElem(i);
				break;
			case 0:
				c();
				dd();
				osnovneOpcije(i);
				break;
			default:
				i = 999999;
				c();
				dd();
				losOp();
				break;
		}
	}
	while (i == 999999);
}

void radSaSlogovima(int i)
{
    /*
        Realizovao sam na sledeci nacin:
            - Ispisuje se text menija
            - Korisnik izabere opciju
            - Ako je izabrao 1, bice upucen na kreiranje novog sloga kako bi ga stavio u aktivnu datoteku
            - Ako je izabrao 2, bice upucen na trazenje sloga iz aktivne datoteke
            - Ako je izabrao 0, vratice se na meni sa osnovnim opcijama
    */
	do
	{
		izbP();
		sloMTxt();
		scanf("%d", &i);
		switch(i)
		{
			case 1:
				i = 10;
				dodSlog(i);
				break;
			case 2:
			    c();
				citSlog(i);
				break;
				/*
			case 3:
				//
				break;
			case 4:
				//
				break;
            case 5:
				//
				break;
			case 6:
				//
				break;
			case 7:
				//
				break;
			case 8:
				//
				break;
				*/
			case 0:
				c();
				dd();
				osnovneOpcije(i);
				break;
			default:
				i = 999999;
				c();
				dd();
				losOp();
				break;
		}
	}
	while (i == 999999);
}

void unesiIme(int i)
{
    /*
        Realizovao sam na sledeci nacin:
            - Opcije 1, 2, 4 i 5 ocekuju od korisnika da unese ime datoteke
            - Drugacije se stvari dese u zavisnosti od toga kojom opcijom se pristupilo funkciji
            - Opcija 1 ----- unosi se ime fajla i kreira prazna datoteka
            - Opcija 2 ----- unosi se ime fajla i BIRA datoteka
            - Opcija 4 ----- isto kao opcija 1
            - Kod opcije 5 krecu razlike
            - Prvo se isto pristupa biranju datoteke kao i u opciji dva
            - Zatim se, unutar izabDat, opet pristupa ovoj funkciji, ali, ovaj put, sa opcijom 55
            - Opcija 55 osigurava da ce se sad od korisnika traziti da unese ime sekvencijalne datoteke
            - Jedini razlog zasto i == 55 postoji je zato sto nisam hteo da realizujem posebnu funkciju za unosenje imena sekvencijalne datoteke
            * Nisam bio siguran da li da stavim u menije ili funkcionalnosti, ali sam ipak stavio u menije
    */
	char ime[50];
	c();
	if(i == 55)
    {
        printf("Unesite ime sekvencijalnog fajla:\n");
    }
    else
    {
    	printf("Unesite ime fajla:\n");
    }
	scanf("%s", ime);
	if(i == 1 || i == 4 || i == 55)
	{
		kreiDat(i, ime);
	}
	else if (i == 2 || i == 5)
	{
		izabDat(i, ime);
	}
}

void dalDaUne(int i)
{
    /*
        Realizovao sam na sledeci nacin:
            - Ispisuje se text menija
            - Korisnik izabere opciju
            - Ako je izabrao 1, bice upucen na kreiranje novog podatka (sloga)
            - Ako je izabrao 2, vratice se u meni za rad sa datotekama
    */
    do
	{
        uneMTxt();
        scanf("%d", &i);
        switch(i)
        {
            case 1:
                unePod(i);
                break;
            case 2:
                fclose(aktiv.aktivna);
                c();
                dd();
                radSaDatotekama(i);
                break;
            default:
                i = 999999;
                c();
                losOp();
                break;
        }
    }
	while (i == 999999);
}

void dalDaPravSek(int i)
{
    /*
        Realizovao sam na sledeci nacin:
            - Ispisuje se text menija
            - Korisnik izabere opciju
            - Ako je izabrao 1, pokrecu se funkcije vezane za stvaranje sekvencijalne datoteke
            - Ovo podrazumeva unos podataka u dinamicku listu, njihovo sortiranje i upis u novi fajl cije ime navede korisnik
            - Ovde se takodje pristupa funkciji unesiIme sa opcijom 55
            - Ako je izabrao 2, precizirao je da nece da formira novu sekvencijalnu datoteku
            - Zatim se vraca na meni za rad sa slogovima
    */
    char ime[50];
    do
    {
        sekPTxt();
        scanf("%d", &i);
        switch(i)
        {
            case 1:
                napElem(i);
                unesiIme(55);
                break;
            case 2:
                c();
                dd();
                uspUpis();
                radSaSlogovima(i);
                break;
            default:
                i = 999999;
                c();
                losOp();
                break;
        }
    }
    while (i == 999999);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void kreiDat(int i, char st[50])
{
    /*
        Realizovao sam na sledeci nacin:
            - Ovoj funkciji je prosledjeno ime koje je precizirao korisnik
            - String imena se spoji sa stringom ".dat" kako bi se kreirao dat file
            - Ovim korisnik ne treba da precizira "prvi.dat" prilikom unosa imena, vec samo "prvi"
            - Sa fopen kreiram datoteku
            - Odmah je zatvorim jer mi trenutno ne treba
            - U zavisnosti od toga odakle sam pristupio funkciji ce se drugacije stvari desiti
            - Ako zelim da kreiram praznu, desice se i == 1 i korisnik ce se vratiti na rad sa datotekama
            - Ako zelim da kreiram serijsku, desice se i == 4 i program ce pitati korisnika da kreira podatke
            - Prilikom kreiranja sekvencijalne datoteke se takodje pristupa ovoj funkciji
            - Ako sam izabrao tu funkciju, onda ce se desiti i == 55 i formirace se sekvencijalna datoteka sortiranjem i upisom podataka
    */
	//FILE *fh;
	char ime[50] = "";

	strncat(ime, st, sizeof ime);
	//printf("%s\n", ime);
	strncat(ime, ".dat", sizeof ime - strlen(ime));
	printf("%s\n", ime);
	aktiv.aktivna = fopen (ime, "w+b");
	fclose (aktiv.aktivna);

	strcpy(aktiv.aktIme,"");
    strcpy(aktiv.aktIme,ime);

    c();
    if(i == 1)
    {
        dd();
        kreiF(ime);
        radSaDatotekama(i);
    }
    else if (i == 4)
    {
        kreiF(ime);
        aktiv.aktivna = fopen(aktiv.aktIme,"w+b");
        dalDaUne(i);
    }
    else if (i == 55)
    {
        kreiF(ime);
        sorLis();
        //aktiv.aktivna = fopen(aktiv.aktIme,"w+b");
        upiElem(i);
    }
}

void izabDat(int i, char st[50])
{
	char *ime[50];

	strncat(ime, st, sizeof ime);
	strncat(ime, ".dat", sizeof ime - strlen(ime));

	if( access(ime, F_OK) != -1 )
	{
        strcpy(aktiv.aktIme,"");
        strcpy(aktiv.aktIme,ime);

        //aktiv.aktivna = fopen(aktiv.aktIme, "wb");
        c();
        if(i == 2)
        {
            dd();
            izabF(ime);
            radSaDatotekama(i);
        }
        else if (i == 5)
        {
            //izabF(ime);
            napElem(i);
            unesiIme(55);
        }
    } else {
        c();
        dd();
        neIzabF(ime);
        radSaDatotekama(i);
    }
}

void prikNazDat(int i)
{
    if(aktiv.aktIme[0] == 0)
    {
        c();
        dd();
        neOtv();
        radSaDatotekama(i);
    }
    else
    {
        c();
        dd();
        prikNaz();
        radSaDatotekama(i);
    }
}

void unePod(int i)
{
    struct blok b;
    struct blok b2;
    struct osoba ooo;
    fclose(aktiv.aktivna);
    aktiv.aktivna = fopen(aktiv.aktIme,"w+");
    if(fseek(aktiv.aktivna,-sizeof(b),SEEK_END)!= 0)
    {
        fread(&b, sizeof(b), 1,aktiv.aktivna);
        /*
        if(b.check == '0')
        {
            e(b.oo1);
            p(b.oo1);
            d(b.oo1);
            v(b.oo1);
            o(b.oo1);
            t(b.oo1);
            c(b.oo1);
            b.check = '1';
        }
        */
        if(b.check == '1')
        {
            e(b.oo2);
            p(b.oo2);
            d(b.oo2);
            v(b.oo2);
            o(b.oo2);
            t(b.oo2);
            c(b.oo2);
            b.check = '2';
            fwrite(&b,sizeof(b),1,aktiv.aktivna);
        }
        else if(b.check == '2')
        {
            e(b.oo3);
            p(b.oo3);
            d(b.oo3);
            v(b.oo3);
            o(b.oo3);
            t(b.oo3);
            c(b.oo3);
            b.check = '2';
            fwrite(&b,sizeof(b),1,aktiv.aktivna);
        }
        else
        {
            fseek(aktiv.aktivna,0,SEEK_END);
            e(b2.oo1);
            p(b2.oo1);
            d(b2.oo1);
            v(b2.oo1);
            o(b2.oo1);
            t(b2.oo1);
            c(b2.oo1);
            b2.check = '1';
            fwrite(&b,sizeof(b),1,aktiv.aktivna);
        }
        //fseek(aktiv.aktivna,-sizeof(blok),SEEK_END);
        //fwrite(&b,sizeof(blok),1,aktiv.aktivna);
    }
    else
    {
        fseek(aktiv.aktivna,0,SEEK_END);
        e(b.oo1);
        p(b.oo1);
        d(b.oo1);
        v(b.oo1);
        o(b.oo1);
        t(b.oo1);
        c(b.oo1);
        b2.check = '1';
        fwrite(&b2,sizeof(b2),1,aktiv.aktivna);
    }

    /*
    e();
    p();
    d();
    v();
    o();
    t();
    c();
    */

    //printf("%s %s %s %s %s %s\n",os.evibro, os.pozbro, os.datbro, os.vrebro, os.oznbro, os.vrebro);

    if(i == 10)
    {
        aktiv.aktivna = fopen(aktiv.aktIme,"a+b");
        fseek(aktiv.aktivna,0,SEEK_END);
        fwrite(&os, sizeof(os),1,aktiv.aktivna);
        fclose(aktiv.aktivna);

        uspUpis();

        dalDaPravSek(i);
    }
    else
    {
        /*
        fseek(aktiv.aktivna,0,SEEK_END);
        fwrite(&os, sizeof(os),1,aktiv.aktivna);
        */
        uspUpis();

        //fclose(aktiv.aktivna);

        //fopen(aktiv.aktIme,"w+b");

        //int n = fread(&os0, sizeof(os0),1,aktiv.aktivna);
        //printf("%s %s %s %s %s %d\n",os0.evibro, os0.pozbro, os0.datbro, os0.vrebro, os0.oznbro, os0.vrebro);

        //fclose(aktiv.aktivna);


        dalDaUne(i);
    }
}

void napElem(int i)
{
    //kljucCount = 1;

    prvi = NULL;

    prvi = malloc(sizeof(lista));
    if(prvi == NULL) {
        printf("Nema dovoljno memorije!");
        exit(0);
    }

    prvi -> sledeci = NULL;

    lista * trenutni = prvi;


    aktiv.aktivna = fopen(aktiv.aktIme,"r+b");

    while(fread(&os0, sizeof(os0),1,aktiv.aktivna))
    {
        brojElem++;
        while (trenutni->sledeci != NULL)
        {
            trenutni = trenutni->sledeci;
        }
        trenutni->sledeci = malloc(sizeof(lista));
        trenutni->sledeci->sledeci = NULL;

        trenutni->o = os0;
        //trenutni->kljuc = kljucCount;
        //kljucCount++;
    }
    //trenutni = NULL;
    fclose(aktiv.aktivna);
}

void sorLis()
{
    lista * trenutnia = prvi;
    lista * trenutnib = NULL;
    struct osoba temp;
    int a = 0;
    while (a == 0)
    {
        a = 1;
        while (trenutnia != NULL)
        {
            trenutnib = trenutnia->sledeci;
            while (trenutnib != NULL)
            {
               if(porKlj(trenutnia->o.oo1.evibro, trenutnib->o.oo1.evibro) == 0)
               {
                   a = 0;
                   temp = trenutnia->o.oo1;
                   trenutnia->o.oo1 = trenutnib->o.oo1;
                   trenutnib->o.oo1 = temp;
               }
               trenutnib = trenutnib->sledeci;
            }
            trenutnia = trenutnia->sledeci;
        }
    }

}

int porKlj(char st1[50], char st2[50])
{
    int a = 2;
    for(int i = 0; i < 7; i++)
    {
        if(st1[i] < st2[i])
        {
            a = 1;
            return a;
        }
        else if(st1[i] > st2[i])
        {
            a = 0;
            return a;
        }
    }
    return a;
}
/*
void zamElem(struct lista * l1, struct lista * l2)
{
    lista * temp = NULL;
    temp = l1;
    l1 = l2;
    l2 = temp;
}
*/
void upiElem(int i)
{
    lista * trenutni = prvi;
    trenutni = trenutni->sledeci;
    aktiv.aktivna = fopen(aktiv.aktIme,"w+b");
    while (trenutni != NULL)
        {
            //printf("%s %s %s %s %s %d\n",trenutni->o.evibro, trenutni->o.pozbro, trenutni->o.datbro, trenutni->o.vrebro, trenutni->o.oznbro, trenutni->o.vrebro);
            fwrite(&(trenutni->o), sizeof(trenutni->o),1,aktiv.aktivna);
            trenutni = trenutni->sledeci;
        }
    fclose(aktiv.aktivna);

        //c();
        //dd();
        printf("Kreirana je sekvencijalna datoteka!");
        radSaDatotekama(i);

}

void dodSlog(int i)
{
    if(aktiv.aktIme[0] == 0)
    {
        c();
        dd();
        neOtv();
        radSaSlogovima(i);
    }
    else
    {
        unePod(i);
    }
}

void citSlog(int i)
{
    if(aktiv.aktIme[0] == 0)
    {
        c();
        dd();
        neOtv();
        radSaSlogovima(i);
    }
    else
    {
        brojElem = 0;
        napElem(i);
        do
        {
            citSTxt();
            scanf("%d", &i);
            switch(i)
            {
                case 1:
                    randSlog(i);
                    break;
                case 2:
                    konkSlog(i);
                    break;
                default:
                    i = 999999;
                    c();
                    losOp();
                    break;
            }
        }
        while (i == 999999);
    }
}

void randSlog(int i)
{
    struct osoba o4;
    int r = rand() % brojElem;
    aktiv.aktivna = fopen(aktiv.aktIme,"r+b");
    fseek(aktiv.aktivna,r*sizeof(o4),SEEK_SET);
    //fseek(aktiv.aktivna,sizeof(os.evibro),SEEK_CUR);
    /*
    fread(&(os.evibro), sizeof(os.evibro),1,aktiv.aktivna);
    os.evibro[7] = '\0';
    fread(&(os.pozbro), sizeof(os0.pozbro),1,aktiv.aktivna);
    fread(&(os.datbro), sizeof(os0.datbro),1,aktiv.aktivna);
    fread(&(os.vrebro), sizeof(os0.vrebro),1,aktiv.aktivna);
    fread(&(os.oznbro), sizeof(os0.oznbro),1,aktiv.aktivna);
    fread(&(os.trabro), sizeof(os0.trabro),1,aktiv.aktivna);
    */
    fread(&os.oo1.evibro, sizeof(os.oo1.evibro),1,aktiv.aktivna);
    fread(&os.oo1.pozbro, sizeof(os.oo1.pozbro),1,aktiv.aktivna);
    fread(&os.oo1.datbro, sizeof(os.oo1.datbro),1,aktiv.aktivna);
    fread(&os.oo1.vrebro, sizeof(os.oo1.vrebro),1,aktiv.aktivna);
    fread(&os.oo1.oznbro, sizeof(os.oo1.oznbro),1,aktiv.aktivna);
    fread(&os.oo1.trabro, sizeof(os.oo1.trabro),1,aktiv.aktivna);

    //fread(&os.evibro, sizeof(os.evibro),1,aktiv.aktivna);
    //os.evibro[7] = '\0';
    //os0.evibro[7] = '\0';
    //os0.pozbro[16] = '\0';
    //os0.datbro[8] = '\0';
    //os0.vrebro[6] = '\0';
    //os0.oznbro[3] = '\0';
    //os0.trabro;
    fclose(aktiv.aktivna);
    c();
    dd();
    ispSlog();
    radSaSlogovima(i);
}

void konkSlog(int i)
{
    char evi[50];
    int provera = 0;
    c();
    printf("Upisite evidencioni broj zeljenog sloga:\n");
    scanf("%s", evi);

    lista * trenutni = prvi;
    while (trenutni != NULL)
    {
        os = trenutni->o;
        if(porKlj(os.oo1.evibro, evi) == 2)
        {
            provera = 1;
            break;
        }
        else
        {
            trenutni = trenutni->sledeci;
        }
    }
    c();
    dd();
    if(provera == 0)
    {
        printf("Ne postoji slog koji ima taj evidencioni broj.\n");
    }
    else
    {
        ispSlog();
    }
    radSaSlogovima(i);
}

void prikElem(i)
{
    //struct blok
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void e(struct blok b)
{
    c();
    printf("Unesite evidencioni broj poziva (uneti 7 cifara):");
    vu();
    scanf("%s", &b.oo1.evibro);
}
void p(struct blok b)
{
    c();
    printf("Unesite telefonski broj pozivaoca (uneti 16 cifara):");
    vu();
    scanf("%s", &b.oo1.pozbro);
}
void d(struct blok b)
{
    c();
    printf("Unesite datum poziva (u formatu ddmmgggg):");
    vu();
    scanf("%s", &b.oo1.datbro);
}
void v(struct blok b)
{
    c();
    printf("Unesite vreme poziva (u formatu hhmmss):");
    vu();
    scanf("%s", &b.oo1.vrebro);
}
void o(struct blok b)
{
    c();
    printf("Unesite oznaku poziva (uneti 3 karaktera):");
    vu();
    scanf("%s", &b.oo1.oznbro);
}
void t(struct blok b)
{
    c();
    printf("Unesite duzinu trajanja poziva (uneti 6 karaktera, max = 100000):");
    vu();
    scanf("%s", &b.oo1.trabro);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    srand(time(NULL));
    //aktiv = malloc(sizeof(struct aktivna_datoteka));
    aktiv.aktIme[0] = 0;

    //os = malloc(sizeof(struct osobaUpis));
	int izbor = 0;
	int *ptr = (int*) malloc(izbor * sizeof(int));
	if(ptr == NULL)
    {
        printf("Nema dovoljno memorije!");
        exit(0);
    }

    prvi = NULL;

	c();
	dd();
	osnovneOpcije(izbor);
	free(ptr);
	//free(aktiv);
	return 0;
}
