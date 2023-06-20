/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: flavian , enzo , paul , mickael
 *
 * Created on 16 December 2020, 19:17
 */

#include <stdio.h>
#include <stdlib.h>

#include "fonction.h"

/*
 * 
 */
int main(int argc, char** argv) {
    int x, niv1, niv2, niv3;
    x = afficherMenu();

    if (x == 1) {
        niv1 = niv1IA();
        if (niv1 == 1) {
            niv2 = niv2IA();
            if (niv2 == 1) {
                niv3 == niv3IA();
                if (niv3 == 1) {
                    printf("Tu a sauvé la galaxie du mal !\n");
                } else {
                    printf("Tu seras oublié à jamais\n");
                }
            } else {
                printf("Si proche du but....\n");
            }
        } else {

            printf("Tu y étais presque !\n");
        }
    }

    if (x == 2) {
        multiPlayer();
    }


    return (EXIT_SUCCESS);
}

