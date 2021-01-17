/*
menu.c
------------

Par tom et Alexandre , pour projet de où est charlie

Rôle : fonctions des menus
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>

#include "constantes.h"
#include "jeu.h"
#include "menu.h"


void menu(SDL_Window* window, SDL_Renderer* renderer)
{


    SDL_Event event;
    int continuer = 1;
    SDL_Surface *picture = NULL;
    SDL_Texture *texture_menu = NULL;
    SDL_Rect dest_rect = {0, 0, 512, 434};
    parametre();


    picture = IMG_Load("img/MENU.png");
    if(picture == NULL)
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, NULL, NULL);
        exit(EXIT_FAILURE);
    }

    texture_menu = SDL_CreateTextureFromSurface(renderer, picture);
    SDL_FreeSurface(picture);
    if(texture_menu == NULL)
    {
        fprintf(stdout,"5Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, NULL, NULL);
        exit(EXIT_FAILURE);
    }

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE: // Veut arrêter le jeu
                        continuer = 0;
                        break;
                    case SDLK_1: // Demande à jouer
                        choix_niveau(window, renderer);
                        break;
                    case SDLK_KP_1: // Demande à jouer
                        choix_niveau(window, renderer);
                        break;
                    case SDLK_2: // Demande à jouer
                        customlv(window, renderer);
                        break;
                    case SDLK_KP_2: // Demande à jouer
                        customlv(window, renderer);
                        break;
                    //case SDLK_2: // Demande l'éditeur de niveaux
                       // editeur(window, rendereur);
                       // break;
                }
                break;
        }

        if(SDL_QueryTexture(texture_menu, NULL, NULL, &dest_rect.w, &dest_rect.h) != 0)
    {
        fprintf(stdout,"4Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, texture_menu, NULL);
        exit(EXIT_FAILURE);
    }

    if(SDL_RenderCopy(renderer,texture_menu,NULL,&dest_rect) != 0)
    {
        fprintf(stdout,"3Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, texture_menu, NULL);
        exit(EXIT_FAILURE);
    }


    SDL_RenderPresent(renderer);
    }

    clean_resources(window, renderer, texture_menu, NULL);
    return EXIT_SUCCESS;

}
/////////////////
void choix_niveau(SDL_Window* window, SDL_Renderer* renderer)
{


    SDL_Event event;
    int continuer = 1;
    SDL_Surface *picture = NULL;
    SDL_Texture *texture_menu = NULL;
    SDL_Rect dest_rect = {0, 0, 512, 434};
    parametre();
    int score = 0;
    FILE * savedlv;


    picture = IMG_Load("img/choix_niveau.png");
    if(picture == NULL)
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, NULL, NULL);
        exit(EXIT_FAILURE);
    }

    texture_menu = SDL_CreateTextureFromSurface(renderer, picture);
    SDL_FreeSurface(picture);
    if(texture_menu == NULL)
    {
        fprintf(stdout,
                "5Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, NULL, NULL);
        exit(EXIT_FAILURE);
    }

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE: // Veut arrêter le jeu
                        continuer = 0;
                        break;
                    case SDLK_1: // Demande à jouer
                        jouer(window, renderer, img_fond_1, img_GoodCharlie_1, img_BadCharlie_1, nb_Charlie_1, speed_charlie_1, largeur_good_chalie_1, longeur_good_chalie_1, largeur_bad_chalie_1, longeur_bad_chalie_1, score);
                        break;
                    case SDLK_KP_1: // Demande à jouer
                        jouer(window, renderer, img_fond_1, img_GoodCharlie_1, img_BadCharlie_1, nb_Charlie_1, speed_charlie_1, largeur_good_chalie_1, longeur_good_chalie_1, largeur_bad_chalie_1, longeur_bad_chalie_1, score);
                        break;

                    case SDLK_2: // Demande à jouer
                        jouer(window, renderer, img_fond_2, img_GoodCharlie_2, img_BadCharlie_2, nb_Charlie_2, speed_charlie_2, largeur_good_chalie_2, longeur_good_chalie_2, largeur_bad_chalie_2, longeur_bad_chalie_2, score);
                        break;
                    case SDLK_KP_2: // Demande à jouer
                        jouer(window, renderer, img_fond_2, img_GoodCharlie_2, img_BadCharlie_2, nb_Charlie_2, speed_charlie_2, largeur_good_chalie_2, longeur_good_chalie_2, largeur_bad_chalie_2, longeur_bad_chalie_2, score);
                        break;

                    case SDLK_3: // Demande à jouer
                        jouer(window, renderer, img_fond_3, img_GoodCharlie_3, img_BadCharlie_3, nb_Charlie_3, speed_charlie_3, largeur_good_chalie_3, longeur_good_chalie_3, largeur_bad_chalie_3, longeur_bad_chalie_3, score);
                        break;
                    case SDLK_KP_3: // Demande à jouer
                        jouer(window, renderer, img_fond_3, img_GoodCharlie_3, img_BadCharlie_3, nb_Charlie_3, speed_charlie_3, largeur_good_chalie_3, longeur_good_chalie_3, largeur_bad_chalie_3, longeur_bad_chalie_3, score);
                        break;

                    case SDLK_4:
                        menu(window, renderer);
                        break;
                    case SDLK_KP_4:
                        menu(window, renderer);
                        break;

                    case SDLK_5:
                      savedlv = fopen("savedlv.txt", "r+" ) ;
                                if (savedlv != NULL){
                                fscanf(savedlv, "%d %d %d %d %d %d %d %d %d",&map,&skin_goodcharlie,&skin_badcharlie,nbofcharlie,&speedofcharlie,&width_goodcharlie,&lengths_goodcharlie,&width_badcharlie,&lengths_badcharlie);
                                fclose(savedlv);
                                }
                        jouer(window, renderer, map, skin_goodcharlie, skin_badcharlie, nbofcharlie, speedofcharlie, width_goodcharlie, lengths_goodcharlie, width_badcharlie, lengths_badcharlie, score);
                        break;
                    case SDLK_KP_5:
                                savedlv= fopen("savedlv.txt", "r+" ) ;
                               if (savedlv != NULL){
                               fscanf(savedlv, "%d %d %d %d %d %d %d %d %d",&map,&skin_goodcharlie,&skin_badcharlie,&nbofcharlie,&speedofcharlie,&width_goodcharlie,&lengths_goodcharlie,&width_badcharlie,&lengths_badcharlie);
                               printf("ok");
                               fclose(savedlv) ;

                                }
                        jouer(window, renderer, map, skin_goodcharlie, skin_badcharlie, nbofcharlie, speedofcharlie, width_goodcharlie, lengths_goodcharlie, width_badcharlie, lengths_badcharlie, score);
                        break;
                }
                break;
        }

        if(SDL_QueryTexture(texture_menu, NULL, NULL, &dest_rect.w, &dest_rect.h) != 0)
    {
        fprintf(stdout,"4Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, texture_menu, NULL);
        exit(EXIT_FAILURE);
    }

    if(SDL_RenderCopy(renderer,texture_menu,NULL,&dest_rect) != 0)
    {
        fprintf(stdout,"3Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, texture_menu, NULL);
        exit(EXIT_FAILURE);
    }


    SDL_RenderPresent(renderer);
    }

    clean_resources(window, renderer, texture_menu, NULL);
    return EXIT_SUCCESS;

}
void customlv(SDL_Window* window, SDL_Renderer* renderer)
{


    SDL_Event event;
    int continuer = 1;
    SDL_Surface *picture = NULL;
    SDL_Texture *texture_menu = NULL;
    SDL_Rect dest_rect = {0, 0, 512, 434};
    parametre();
    int score = 0;
    int i =0;





    picture = IMG_Load("img/customize.png");   //////////////////////////
    if(picture == NULL)
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, NULL, NULL);
        exit(EXIT_FAILURE);
    }

    texture_menu = SDL_CreateTextureFromSurface(renderer, picture);
    SDL_FreeSurface(picture);
    if(texture_menu == NULL)
    {
        fprintf(stdout,
                "5Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, NULL, NULL);
        exit(EXIT_FAILURE);
    }

    while (continuer)
    {
        SDL_WaitEvent(&event);

        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {

                    case SDLK_ESCAPE: // Veut arrêter le jeu
                        continuer = 0;
                        break;
                    case SDLK_1: // Demande à jouer
                         map = img_fond_1;
                         i = 1;
                        break;
                    case SDLK_KP_1: // Demande à jouer
                         map = img_fond_1;
                         i = 1;
                        break;
                    case SDLK_2: // Demande à jouer
                         map = img_fond_2;
                         i = 1;
                        break;
                    case SDLK_KP_2: // Demande à jouer
                         map = img_fond_2;
                         i = 1;
                        break;
                    case SDLK_3: // Demande à jouer
                         map= img_fond_3;
                         i = 1;
                        break;
                    case SDLK_KP_3: // Demande à jouer
                         map = img_fond_3;
                         i = 1;
                        break;
                    case SDLK_m:
                        menu(window, renderer);
                        break;
                }
            break;
        }

        if (i == 1)
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    continuer = 0;
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_4: // Demande à jouer
                            skin_goodcharlie  = img_GoodCharlie_1;
                            lengths_goodcharlie = longeur_good_chalie_1 ;
                            width_goodcharlie = largeur_good_chalie_1;
                            i = 2;
                            break;
                                    case SDLK_KP_4: // Demande à jouer
                                        skin_goodcharlie  = img_GoodCharlie_1;
                                        lengths_goodcharlie = longeur_good_chalie_1 ;
                                        width_goodcharlie = largeur_good_chalie_1;
                                        i = 2;
                                        break;
                                    case SDLK_5: // Demande à jouer
                                        skin_goodcharlie  = img_GoodCharlie_2;
                                        lengths_goodcharlie = longeur_good_chalie_2;
                                        width_goodcharlie = largeur_good_chalie_2;
                                        i = 2;
                                        break;
                                    case SDLK_KP_5: // Demande à jouer
                                        skin_goodcharlie  = img_GoodCharlie_2;
                                        lengths_goodcharlie = longeur_good_chalie_2 ;
                                        width_goodcharlie = largeur_good_chalie_2;
                                        i = 2;
                                        break;
                                    case SDLK_6: // Demande à jouer
                                        skin_goodcharlie  = img_GoodCharlie_3;
                                        lengths_goodcharlie = longeur_good_chalie_3 ;
                                        width_goodcharlie = largeur_good_chalie_3;
                                        i = 2;
                                        break;
                                    case SDLK_KP_6: // Demande à jouer
                                        skin_goodcharlie  = img_GoodCharlie_3;
                                        lengths_goodcharlie = longeur_good_chalie_3;
                                        width_goodcharlie = largeur_good_chalie_3;
                                        i = 2;
                                        break;
                        case SDLK_m:
                            menu(window, renderer);
                            break;
                    }
                break;
            }

        }

        if (i == 2)
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    continuer = 0;
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                                        case SDLK_7: // Demande à jouer
                                            skin_badcharlie  = img_BadCharlie_1;
                                            lengths_badcharlie = longeur_bad_chalie_1 ;
                                            width_badcharlie = largeur_bad_chalie_1;
                                            i = 3;
                                            break;
                                        case SDLK_KP_7: // Demande à jouer
                                            skin_badcharlie  = img_BadCharlie_1;
                                            lengths_badcharlie = longeur_bad_chalie_1 ;
                                            width_badcharlie = largeur_bad_chalie_1;
                                            i = 3;
                                            break;
                                        case SDLK_8: // Demande à jouer
                                            skin_badcharlie  = img_BadCharlie_2;
                                            lengths_badcharlie = longeur_bad_chalie_2 ;
                                            width_badcharlie = largeur_bad_chalie_2;
                                            i = 3;
                                            break;
                                        case SDLK_KP_8: // Demande à jouer
                                            skin_badcharlie  = img_BadCharlie_2;
                                            lengths_badcharlie = longeur_bad_chalie_2 ;
                                            width_badcharlie = largeur_bad_chalie_2;
                                            i = 3;
                                            break;

                                        case SDLK_9: // Demande à jouer
                                            skin_badcharlie  = img_BadCharlie_3;
                                            lengths_badcharlie = longeur_bad_chalie_3 ;
                                            width_badcharlie = largeur_bad_chalie_3;
                                            i = 3;
                                            break;
                                        case SDLK_KP_9: // Demande à jouer
                                            skin_badcharlie  = img_BadCharlie_3;
                                            lengths_badcharlie = longeur_bad_chalie_3 ;
                                            width_badcharlie = largeur_bad_chalie_3;
                                            i = 3;
                                            break;
                        case SDLK_m:
                            menu(window, renderer);
                            break;
                    }
                    break;
            }

        }
        if(i==3)
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    continuer = 0;
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_e: // Demande à jouer
                            nbofcharlie  = easynb;
                                                    speedofcharlie = normalspeed;
                                                    i = 4;
                                                    break;
                                                case SDLK_n: // Demande à jouer
                                                    nbofcharlie  = normalnb;
                                                    speedofcharlie = normalspeed;
                                                    i = 4;
                                                    break;
                                                case SDLK_h: // Demande à jouer
                                                    nbofcharlie  = hardcorenb;
                                                    speedofcharlie = hardcorespeed;
                                                    i = 4;
                                                    break;
                        case SDLK_m:
                            menu(window, renderer);
                            break;
                    }
                    break;
            }

        }
        if(i==4)
        {
            newlv();
            jouer(window, renderer, map, skin_goodcharlie, skin_badcharlie, nbofcharlie, speedofcharlie, width_goodcharlie, lengths_goodcharlie, width_badcharlie, lengths_badcharlie, score);
        }



        if(SDL_QueryTexture(texture_menu, NULL, NULL, &dest_rect.w, &dest_rect.h) != 0)
    {
        fprintf(stdout,"4Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, texture_menu, NULL);
        exit(EXIT_FAILURE);
    }

    if(SDL_RenderCopy(renderer,texture_menu,NULL,&dest_rect) != 0)
    {
        fprintf(stdout,"3Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, texture_menu, NULL);
        exit(EXIT_FAILURE);
    }


    SDL_RenderPresent(renderer);
    }

    clean_resources(window, renderer, texture_menu, NULL);
    return EXIT_SUCCESS;

}
