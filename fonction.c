/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * auteur : flavian,mickeal,enzo,paul
 */

#include "fonction.h"
#include  <stdlib.h>
#include <time.h>

void bouger(typeElement *e, directions sens, WINDOW *boite) {

    mvwprintw(boite, e->y, e->x, " "); // on efface l'element en x,y
    if (e->speed == 1) {
        switch (sens) {
            case HAUT:
                if (e->y > 1) {
                    e->y = e->y - 1;
                }
                break;
            case BAS:
                if (e->y < HAUTEUR - 2) {
                    e->y = e->y + 1;
                }

                break;
            case GAUCHE:
                if (e->x > 1) {
                    e->x = e->x - 1;
                }
                break;
            case DROITE:
                if (e->x < LARGEUR - 3) { //-1 car bord gauche prend un emplacement, -1 car bord droite prend un emplacement, et -1 avant bord droite sinonon ne peut pas alle a droite
                    e->x = e->x + 1;
                }
                break;
        }

    } else {
        switch (sens) {
            case HAUT:
                if (e->y > 1) {
                    e->y = e->y - 2;
                }
                break;
            case BAS:
                if (e->y < HAUTEUR - 2) {
                    e->y = e->y + 2;
                }

                break;
            case GAUCHE:
                if (e->x > 1) {
                    e->x = e->x - 2;
                }
                break;
            case DROITE:
                if (e->x < LARGEUR - 3) { //-1 car bord gauche prend un emplacement, -1 car bord droite prend un emplacement, et -1 avant bord droite sinonon ne peut pas alle a droite
                    e->x = e->x + 2;
                }
                break;
        }

    }


    mvwprintw(boite, e->y, e->x, "%lc", e->symbole); // on affiche l'element en x,y
}

void bougerAIhard(typeElement* e, directions sens, WINDOW* boite) {
    mvwprintw(boite, e->y, e->x, " "); // on efface l'element en x,y
    switch (sens) {
        case HAUT:
            if (e->y > 2) {
                e->y = e->y - 2;
            }
            break;
        case BAS:
            if (e->y < HAUTEUR - 3) {
                e->y = e->y + 2;
            }

            break;
        case GAUCHE:
            if (e->x > 2) {
                e->x = e->x - 2;
            }
            break;
        case DROITE:
            if (e->x < LARGEUR - 4) { //-1 car bord gauche prend un emplacement, -1 car bord droite prend un emplacement, et -1 avant bord droite sinonon ne peut pas alle a droite
                e->x = e->x + 2;
            }
            break;
    }

    mvwprintw(boite, e->y, e->x, "%lc", e->symbole); // on affiche l'element en x,y

}

int aleatoire(int min, int max) {
    int a;
    srand(time(NULL));
    a = rand() % max + min;



    return a;




}

void decoince(typeElement *e, WINDOW *boite) {
    if (e->x == LARGEUR - 3) {
        e->x = aleatoire(0, LARGEUR);


    } else
        if (e->x == 3) {

        e->x = aleatoire(0, LARGEUR);
    }

    mvwprintw(boite, e->y, e->x, "%lc", e->symbole);
}

void multiPlayer() {
    typeElement el, el1, el2;
    char touche, rejouer;
    char pseudo[255], pseudo1[255];
    WINDOW *boite;
    time_t depart, arrivee;
    time(&depart);
    int speed = 0;

    printf("%soooooooooo.    .oooooo.   ooooo      ooo    oooo   .oooooo.   ooooo     ooo ooooooooo.   \n", GREEN);
    printf("`888'   `Y8b  d8P'  `Y8b  `888b.     `8'    888  d8P'  `Y8b  `888'     `8' `888   `Y88. \n");
    printf("888     888 888      888  8 `88b.    8      888 888      888  888       8   888   .d88' \n");
    printf("888oooo888' 888      888  8   `88b.  8      888 888      888  888       8   888ooo88P'  \n");
    printf("888    `88b 888      888  8     `88b.8      888 888      888  888       8   888`88b.    \n");
    printf("888    .88P `88b    d88'  8       `888      888 `88b    d88'  `88.    .8'   888  `88b.  \n");
    printf("o888bood8P'   `Y8bood8P'  o8o        `8  .o.88P  `Y8bood8P'     `YbodP'    o888o  o888o \n");
    printf("                                        `Y888P                                          \n");

    printf("\n");
    printf("%s8ooooooooo.   oooooooooooo   .oooooo.    ooooo        oooooooooooo    .oooooo..o \n", CYAN);
    printf("`888   `Y88. `888'     `8  d8P'  `Y8b   `888'        `888'       `8 d8P'    `Y8 \n");
    printf("888   .d88'  888         888            888          888           Y88bo.      \n");
    printf("888ooo88P'   888oooo8    888            888          888oooo8       `Y8888o.  \n");
    printf("888`88b.     888         888     ooooo  888          888               `Y88b \n");
    printf("888  `88b.   888       o `88.    .88'   888       o  888       o oo       .d8P \n");
    printf("o888o  o888o o888ooooood8  `Y8bood8P'   o888ooooood8 o888ooooood8   8""88888P'  \n");
    printf("\n");
    printf("essayez de survivre le plus longtemps possible à l'attaque de l'ovni\n");
    printf("Prenez l'étoile pour aller aussi vite que la lumière !");
    printf("\n");



    printf("%s Donnez le nom du premier joueur  :", BLUE);
    scanf("%s", pseudo);
    printf("%s Donnez le nom du deuxieme joueur : ", BLUE);
    scanf("%s", pseudo1);
    do {

        setlocale(LC_ALL, ""); // mettre la console en compatibilité d'affichage unicode sous linux
        initscr(); // Initialise la structure WINDOW et autres paramètres 
        el.symbole = 0x1F680; // symbole est une flamme 
        el.x = 15;
        el.y = 15;
        el.speed = 1;
        el1.symbole = 0x1F6F8;
        el1.x = 5;
        el1.y = 5;
        el1.speed = 1;
        el2.symbole = 0x2605;
        el2.x = 20;
        el2.y = 5;
        el2.speed = 1;




        boite = subwin(stdscr, HAUTEUR, LARGEUR, 1, 1); // boite positionnee en 1,1 avec comme dimension LARGEURxHAUTEUR
        box(boite, ACS_VLINE, ACS_HLINE); // dessiner le contour de la boite
        wrefresh(boite); // mettre a jour l'affichage de la boite



        mvwprintw(boite, el.y, el.x, "%lc", el.symbole); // on affiche l'element en x,y dans la boite
        mvwprintw(boite, el1.y, el1.x, "%lc", el1.symbole);
        mvwprintw(boite, el2.y, el2.x, "%lc", el2.symbole);
        mvprintw(0, 1, " Joueur 1 : %s      Joueur 2 : %s", pseudo, pseudo1);
        mvprintw(21, 2, "SPACE WAR");
        mvprintw(21, 57, "By SpaceXmas");
        curs_set(0); //curseur invisible
        noecho(); // pas d'echo de la touche appuyée
        time(&depart);
        do {
            time(&arrivee);
            mvprintw(0, 50, "Temps : %.0f secondes", difftime(arrivee, depart));

            touche = getch(); // recupérer la valeur de la touche appuyée
            if (speed > 0) {

            }
            switch (touche) {
                case '4':bouger(&el, GAUCHE, boite);

                    break;
                case '6':bouger(&el, DROITE, boite);

                    break;
                case '8':bouger(&el, HAUT, boite);

                    break;
                case '2':bouger(&el, BAS, boite);

                    break;
            }
            switch (touche) {
                case 'q':bouger(&el1, GAUCHE, boite);
                    bouger(&el2, DROITE, boite);

                    break;
                case 'd':bouger(&el1, DROITE, boite);
                    bouger(&el2, GAUCHE, boite);

                    break;
                case 'z':bouger(&el1, HAUT, boite);
                    bouger(&el2, BAS, boite);

                    break;
                case 's':bouger(&el1, BAS, boite);
                    bouger(&el2, HAUT, boite);

                    break;
            }
            if (el.x == el1.x && el.y == el1.y) {
                time(&arrivee);
                mvprintw(0, 50, "Temps : %.0f secondes", difftime(arrivee, depart));
                touche = 'k';
            }
            if (el.x == el2.x && el.y == el2.y) {
                el.speed = 2;
                //el2.symbole = NULL;
            }
            if (el.x == el1.x && el.y == el1.y) {
                el.symbole = 0x1F525;
            }

            refresh(); // mise a jour de l'affichage
            wrefresh(boite);

        } while (touche != 'k'&& difftime(arrivee, depart) <= 60);
        endwin();
        /*for(int i=0;i<LARGEUR;i++){
            for(int i=0;i<HAUTEUR;i++) {
                mvwprintw(boite, LARGEUR, HAUTEUR,"% ");
            }
        }*/
        do {
            printf("%sVoulez vous rejouer (o/n)?\n", GREY);
            scanf(" %c", &rejouer);
            wrefresh(boite);
        } while (rejouer != 'n' && rejouer != 'o');

    } while (rejouer != 'n');
    if(difftime(arrivee, depart)){
        printf("la fusée a survécu à l'attaque de l'ovni!");
        
    }

    endwin(); // remettre le terminal dans son état initial
    printf("La fusée à survecu %.0f secondes\n", difftime(arrivee, depart));

}

int niv1IA() {


    typeElement el;
    typeElement el1;
    typeElement el2;
    typeElement el3;
    typeElement el4, vie;
    time_t depart, arrive;
    int touche, mort = 1;
    WINDOW *boite;
    int x = 0;

    setlocale(LC_ALL, ""); // mettre la console en compatibilité d'affichage unicode sous linux
    initscr(); // Initialise la structure WINDOW et autres paramètres 

    vie.symbole = 0x1F49A;
    el1.symbole = 0x1F419;
    el.symbole = 0x1F610; // symbole est une flamme
    el2.symbole = 0x1F419;
    el3.symbole = 0x1F419;
    el4.symbole = 0x1F419;
    el.x = 10;
    el.speed = 1;
    el1.speed = 1;
    el2.speed = 1;
    el3.speed = 1;
    el4.speed = 1;
    el.y = 10;
    el1.x = 5;
    el1.y = 5;
    el2.x = 15;
    el2.y = 15;
    el3.x = 3;
    el3.y = 3;
    el4.x = 17;
    el4.y = 17;


    boite = subwin(stdscr, HAUTEUR, LARGEUR, 1, 1); // boite positionnee en 1,1 avec comme dimension LARGEURxHAUTEUR
    box(boite, ACS_VLINE, ACS_HLINE); // dessiner le contour de la boite
    wrefresh(boite); // mettre a jour l'affichage de la boite

    mvwprintw(boite, el.y, el.x, "%lc", el.symbole); // on affiche l'element en x,y dans la boite
    mvwprintw(boite, el1.y, el1.x, "%lc", el1.symbole);
    mvwprintw(boite, el2.x, el2.y, "%lc", el2.symbole);
    mvwprintw(boite, el3.x, el3.y, "%lc", el3.symbole);
    mvwprintw(boite, el4.x, el4.y, "%lc", el4.symbole);
    mvprintw(0, 1, "Vie %lc", vie.symbole);


    curs_set(0); //curseur invisible
    noecho(); // pas d'echo de la touche appuyée
    time(&depart);
    do {
        touche = getch(); // recupérer la valeur de la touche appuyée
        switch (touche) {
            case '4':bouger(&el, GAUCHE, boite);
                bouger(&el1, aleatoire(0, 4), boite);
                bouger(&el2, aleatoire(0, 4), boite);
                bouger(&el3, aleatoire(0, 4), boite);
                bouger(&el4, aleatoire(0, 4), boite);
                break;
            case '6':bouger(&el, DROITE, boite);
                bouger(&el1, aleatoire(0, 4), boite);
                bouger(&el2, aleatoire(0, 4), boite);
                bouger(&el3, aleatoire(0, 4), boite);
                bouger(&el4, aleatoire(0, 4), boite);
                break;
            case '8':bouger(&el, HAUT, boite);
                bouger(&el1, aleatoire(0, 4), boite);
                bouger(&el2, aleatoire(0, 4), boite);
                bouger(&el3, aleatoire(0, 4), boite);
                bouger(&el4, aleatoire(0, 4), boite);
                break;
            case '2':bouger(&el, BAS, boite);
                bouger(&el1, aleatoire(0, 4), boite);
                bouger(&el2, aleatoire(0, 4), boite);
                bouger(&el3, aleatoire(0, 4), boite);
                bouger(&el4, aleatoire(0, 4), boite);
                break;
        }
        if ((el.x == el1.x && el.y == el1.y)
                || (el.x == el2.x && el.y == el2.y)
                || (el.x == el3.x && el.y == el3.y)
                || (el.x == el4.x && el.y == el4.y)) {
            mort++;
            el.symbole = 0x1F915;
            vie.symbole = 0x1F9E1;
            mvprintw(0, 1, "Vie %lc", vie.symbole);

        }
        refresh(); // mise a jour de l'affichage
        wrefresh(boite);
        time(&arrive);
        mvprintw(0, 40, "Temps : %.2f", difftime(arrive, depart));
    } while (touche != 'x' && mort < 3 && difftime(arrive, depart) < 20);

    endwin(); // remettre le terminal dans son état initial
    if (difftime(arrive, depart) >= 20) {
        //printf(" Vous avez gagné ! \n");
        x = 1;
    } else {
        printf("GAME OVER \n");
        x = 0;
    }

    return x;
}

int niv2IA() {
    typeElement el;
    typeElement el1;
    typeElement el2;
    typeElement el3;
    typeElement el4;
    typeElement el5;
    typeElement el6;
    typeElement el7;
    typeElement el8, vie;
    int touche, x = 0;
    WINDOW *boite;
    time_t depart, arrive;
    int mort = 1;


    setlocale(LC_ALL, ""); // mettre la console en compatibilité d'affichage unicode sous linux
    initscr(); // Initialise la structure WINDOW et autres paramètres 

    el.symbole = 0x1F603; // symbole est un humain
    el.x = 35;
    el.y = 10;
    el.speed = 1;

    el3.symbole = 0x1F419;
    el3.x = 65;
    el3.y = 8;
    el3.speed = 1;

    el4.symbole = 0x1F419;
    el4.x = 15;
    el4.y = 2;
    el4.speed = 1;

    el5.symbole = 0x1F419;
    el5.x = 57;
    el5.y = 8;
    el5.speed = 1;

    el6.symbole = 0x1F419;
    el6.x = 22;
    el6.y = 16;
    el6.speed = 1;

    el7.symbole = 0x1F419;
    el7.x = 10;
    el7.y = 1;
    el7.speed = 1;

    el8.symbole = 0x1F419;
    el8.x = 49;
    el8.y = 13;
    el8.speed = 1;

    vie.symbole = 0x1F49A;



    boite = subwin(stdscr, HAUTEUR, LARGEUR, 1, 1); // boite positionnee en 1,1 avec comme dimension LARGEURxHAUTEUR
    box(boite, ACS_VLINE, ACS_HLINE); // dessiner le contour de la boite
    wrefresh(boite); // mettre a jour l'affichage de la boite





    mvwprintw(boite, el.y, el.x, "%lc", el.symbole); // on affiche l'element en x,y dans la boite

    mvwprintw(boite, el3.y, el3.x, "%lc", el3.symbole);
    mvwprintw(boite, el4.y, el4.x, "%lc", el4.symbole);
    mvwprintw(boite, el5.y, el5.x, "%lc", el5.symbole);
    mvwprintw(boite, el6.y, el5.x, "%lc", el6.symbole);
    mvwprintw(boite, el7.y, el5.x, "%lc", el7.symbole);
    mvwprintw(boite, el8.y, el5.x, "%lc", el8.symbole);
    mvprintw(0, 1, "Vie %lc", vie.symbole);


    curs_set(0); //curseur invisible
    noecho(); // pas d'echo de la touche appuyée
    time(&depart);
    do {
        touche = getch(); // recupérer la valeur de la touche appuyée
        switch (touche) {
            case '4':bouger(&el, GAUCHE, boite);

                bouger(&el3, aleatoire(0, 4), boite);
                bouger(&el4, aleatoire(0, 4), boite);
                bouger(&el5, aleatoire(0, 4), boite);
                bouger(&el6, aleatoire(0, 4), boite);
                bouger(&el7, aleatoire(0, 4), boite);
                bouger(&el8, aleatoire(0, 4), boite);
                break;
            case '6':bouger(&el, DROITE, boite);

                bouger(&el3, aleatoire(0, 4), boite);
                bouger(&el4, aleatoire(0, 4), boite);
                bouger(&el5, aleatoire(0, 4), boite);
                bouger(&el6, aleatoire(0, 4), boite);
                bouger(&el7, aleatoire(0, 4), boite);
                bouger(&el8, aleatoire(0, 4), boite);
                break;
            case '8':bouger(&el, HAUT, boite);

                bouger(&el3, aleatoire(0, 4), boite);
                bouger(&el4, aleatoire(0, 4), boite);
                bouger(&el5, aleatoire(0, 4), boite);
                bouger(&el6, aleatoire(0, 4), boite);
                bouger(&el7, aleatoire(0, 4), boite);
                bouger(&el8, aleatoire(0, 4), boite);
                break;
            case '2':bouger(&el, BAS, boite);

                bouger(&el3, aleatoire(0, 4), boite);
                bouger(&el4, aleatoire(0, 4), boite);
                bouger(&el5, aleatoire(0, 4), boite);
                bouger(&el6, aleatoire(0, 4), boite);
                bouger(&el7, aleatoire(0, 4), boite);
                bouger(&el8, aleatoire(0, 4), boite);
                break;
        }
        if ((el.x == el1.x && el.y == el1.y)
                || (el.x == el2.x && el.y == el2.y)
                || (el.x == el3.x && el.y == el3.y)
                || (el.x == el4.x && el.y == el4.y)
                || (el.x == el5.x && el.y == el5.y)
                || (el.x == el6.x && el.y == el6.y)
                || (el.x == el7.x && el.y == el7.y)
                || (el.x == el8.x && el.y == el8.y)) {
            mort++;
            el.symbole = 0x1F637;


            vie.symbole = 0x1F9E1;
            mvprintw(0, 1, "Vie %lc", vie.symbole);


        }
        refresh(); // mise a jour de l'affichage
        wrefresh(boite);
        time(&arrive);
        mvprintw(0, 40, "Temps : %.2f", difftime(arrive, depart));
    } while (touche != 'x' && mort < 3 && difftime(arrive, depart) < 40);


    endwin(); // remettre le terminal dans son état initial
    if (difftime(arrive, depart) >= 40) {
        // printf(" Vous avez gagné ! \n");
        x = 1;
    } else {
        printf("GAME OVER \n");
        x = 0;

    }
    return x;


}

int niv3IA() {
    int mort = 1;
    typeElement el, ia1, ia2, ia3, ia4, ia5, vie;
    int touche;
    WINDOW *boite;
    time_t depart, arrive;
    int x = 0;



    setlocale(LC_ALL, ""); // mettre la console en compatibilité d'affichage unicode sous linux
    initscr(); // Initialise la structure WINDOW et autres paramètres 

    el.symbole = 0x1F637; // symbole est une flamme 
    el.x = 1;
    el.y = 1;
    el.speed = 1;

    ia1.symbole = 0x1F419;
    ia1.x = 5;
    ia1.y = 15;
    ia1.speed = 1;

    ia2.symbole = 0x1F419;
    ia2.x = 3;
    ia2.y = 15;
    ia2.speed = 1;

    ia3.symbole = 0x1F419;
    ia3.x = 35;
    ia3.y = 5;
    ia3.speed = 1;

    ia4.symbole = 0x1F419;
    ia4.x = 4;
    ia4.y = 4;
    ia4.speed = 1;

    ia5.symbole = 0x1F419;
    ia5.x = 8;
    ia5.y = 8;
    ia5.speed = 1;

    vie.symbole = 0x1F49A;


    boite = subwin(stdscr, HAUTEUR, LARGEUR, 1, 1); // boite positionnee en 1,1 avec comme dimension LARGEURxHAUTEUR


    box(boite, ACS_VLINE, ACS_HLINE); // dessiner le contour de la boite



    wrefresh(boite); // mettre a jour l'affichage de la boite


    mvwprintw(boite, el.y, el.x, "%lc", el.symbole); // on affiche l'element en x,y dans la boite
    mvwprintw(boite, ia1.y, ia1.x, "%lc", ia1.symbole);
    mvwprintw(boite, ia2.y, ia2.x, "%lc", ia2.symbole);
    mvwprintw(boite, ia3.y, ia3.x, "%lc", ia3.symbole);
    mvwprintw(boite, ia4.y, ia4.x, "%lc", ia4.symbole);
    mvprintw(0, 1, "Vie %lc", vie.symbole);



    curs_set(0); //curseur invisible
    noecho(); // pas d'echo de la touche appuyée

    time(&depart);

    do {

        touche = getch(); // recupérer la valeur de la touche appuyée
        switch (touche) {
            case '4':bouger(&el, GAUCHE, boite);
                bougerAIhard(&ia1, aleatoire(0, 4), boite);
                bougerAIhard(&ia2, aleatoire(0, 4), boite);
                bougerAIhard(&ia3, aleatoire(0, 4), boite);
                bougerAIhard(&ia4, aleatoire(0, 4), boite);
                break;
            case '6':bouger(&el, DROITE, boite);
                bougerAIhard(&ia1, aleatoire(0, 4), boite);
                bougerAIhard(&ia2, aleatoire(0, 4), boite);
                bougerAIhard(&ia3, aleatoire(0, 4), boite);
                bougerAIhard(&ia4, aleatoire(0, 4), boite);
                break;
            case '8':bouger(&el, HAUT, boite);
                bougerAIhard(&ia1, aleatoire(0, 4), boite);
                bougerAIhard(&ia2, aleatoire(0, 4), boite);
                bougerAIhard(&ia3, aleatoire(0, 4), boite);
                bougerAIhard(&ia4, aleatoire(0, 4), boite);
                break;
            case '2':bouger(&el, BAS, boite);
                bougerAIhard(&ia1, aleatoire(0, 4), boite);
                bougerAIhard(&ia2, aleatoire(0, 4), boite);
                bougerAIhard(&ia3, aleatoire(0, 4), boite);
                bougerAIhard(&ia4, aleatoire(0, 4), boite);
                break;
        }

        if ((el.x == ia1.x && el.y == ia1.y)
                || (el.x == ia2.x && el.y == ia2.y)
                || (el.x == ia3.x && el.y == ia3.y)
                || (el.x == ia4.x && el.y == ia4.y)) {
            mort++;
            el.symbole = 0x1F915;
            vie.symbole = 0x1F9E1;
            mvprintw(0, 1, "Vie %lc", vie.symbole);


        }
        refresh(); // mise a jour de l'affichage

        wrefresh(boite);
        time(&arrive);
        mvprintw(0, 40, "Temps : %.2f", difftime(arrive, depart));
    } while (touche != 'x' && mort < 3 && difftime(arrive, depart) < 60);

    endwin(); // remettre le terminal dans son état initial
    if (difftime(arrive, depart) >= 60) {
        //printf(" Vous avez gagné ! \n");
        x = 1;
    } else {
        printf("GAME OVER \n");
        x = 0;
    }

    return x;



}

int afficherMenu() {
    int mode;
    printf("%s .oooooo..o                                          %sooooooo  ooooo                                      \n", RED, GREY);
    printf("%sd8P'    `Y8                                           %s`8888    d8'                                       \n", RED, GREY);
    printf("%sY88bo.      oo.ooooo.   .oooo.    .ooooo.   .ooooo.     %sY888..8P    ooo. .oo.  .oo.    .oooo.    .oooo.o \n", RED, GREY);
    printf(" %s` Y8888o.   888' `88b `P  )88b  d88' ` Y8 d88' `88b     %s`8888'     `888P Y88bP Y88b  `P  )88b  d88(   8 \n", RED, GREY);
    printf("     %s` Y88b  888   888  .oP 888  888       888ooo888    %s.8PY888.     888   888   888   .oP 888  ` Y88b.  \n", RED, GREY);
    printf("%soo     .d8P  888   888 d8(  888  888   .o8 888    .o   %sd8'  `888b    888   888   888  d8(  888  o.  )88b \n", RED, GREY);
    printf(" %s8 88888P'   888bod8P' `Y8888888o `Y8bod8P' `Y8bod8P' %so888o  o88888o o888o o888o o888o `Y888 8o8  888P' \n", RED, GREY);
    printf("  %s           888                                                                                         \n", RED);
    printf("            o888o                                                                                        \n");


    do {
        printf("%sMode de jeu :\n %s1.Mode solo\n %s2.Mode multijoueur\n %s3.Quitter le jeu\n", GREY, RED, GREEN, PURPLE);
        scanf("%d", &mode);
    } while (mode != 1 && mode != 2 && mode != 3);
    if (mode == 1) {
        printf("%sVous avez selectionné le mode solo\n", RED);
    }
    if (mode == 2) {
        printf("Vous avez selectionné le mode multijoueur\n");
    } else {
        printf("Vous avez quitté le jeu\n");
    }
    return mode;
}
