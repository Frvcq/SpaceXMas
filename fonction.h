/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fonction.h
 * Author: flavian , mickeal , enzo , Paul
 *
 * Created on 16 December 2020, 19:18
 */

#ifndef FONCTION_H
#define FONCTION_H
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <string.h>
#include <time.h>

#define BLACK    "\033[1;30m"
#define RED      "\033[1;31m"
#define GREEN    "\033[1;32m"
#define YELLOW   "\033[1;33m"
#define BLUE     "\033[1;34m"
#define PURPLE   "\033[1;35m"
#define CYAN     "\033[1;36m"
#define GREY     "\033[1;37m"


#ifdef __cplusplus
extern "C" {
#endif
#define LARGEUR 70
#define HAUTEUR 20

    typedef enum {
        HAUT, BAS, GAUCHE, DROITE
    } directions;

    typedef struct {
        int x;
        int y;
        int speed;
        wchar_t symbole;
    } typeElement;

    void bouger(typeElement *e, directions sens, WINDOW *boite);
    void bougerAIhard(typeElement *e, directions sens, WINDOW *boite);
    int aleatoire(int, int);
    void decoince(typeElement *e, WINDOW *boite);
    void multiPlayer();
    int niv1IA();
    int niv2IA();
    int niv3IA();
    int afficherMenu();

#ifdef __cplusplus
}
#endif

#endif /* FONCTION_H */

