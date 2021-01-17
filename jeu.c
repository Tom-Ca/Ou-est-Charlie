/*
jeux.c
------------

Par tom et Alexandre , pour projet de où est charlie

Rôle : fonctions du jeux
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>

#include "constantes.h"
#include "jeu.h"
#include "menu.h"




void clean_resources(SDL_Window *w, SDL_Renderer *r, SDL_Texture *t, SDL_Texture *t2)
{
    if(t != NULL)
        SDL_DestroyTexture(t);

    if(t2 != NULL)
        SDL_DestroyTexture(t2);

    if(r != NULL)
        SDL_DestroyRenderer(r);

    if(w != NULL)
        SDL_DestroyWindow(w);
    SDL_Quit();
}


void jouer(SDL_Window* window, SDL_Renderer* renderer, char *img_fond, char *img_GoodChatlie, char *img_BadChatlie, int *nb_Charlie, int *speed_charlie, int *largeur_good_chalie,int *longeur_good_chalie,int *largeur_bad_chalie,int *longeur_bad_chalie, int *score )
{
//variables
    SDL_Event event;
    srand( time( NULL ) );
    int tempsDeDepart = SDL_GetTicks();
    int fin = 0;
    random();
// on passe de int* a int
    int continuer = 1;
    int LargeurGoodChalie = largeur_good_chalie;
    int LongeurGoodChalie = longeur_good_chalie;
    int LargeurBadChalie = largeur_bad_chalie;
    int LongeurBadChalie = longeur_bad_chalie;
    int NBCharlie = nb_Charlie;
    int Nb_Charlieplus = NBCharlie;
    int SpeedCharlie = speed_charlie;
    int Score_int = score;

//variable d'affichage
    SDL_Surface *picture =NULL;
    SDL_Texture *texture_fond = NULL, *texture_good_Charlie = NULL, *texture_bad_Charlie = NULL;
    SDL_Rect dest_rect = {0, 50, 512, 384};
    int x_rand_good = dest_rect.w - LargeurGoodChalie;
    int y_rand_good = dest_rect.h - LongeurGoodChalie;
    SDL_Rect good_charlie = {rand() % x_rand_good,  rand () % y_rand_good +50, LargeurGoodChalie, LongeurGoodChalie};
    int tempsPrecedent = 0, tempsActuel = 0;
    dep();
//random();
    int x_max = dest_rect.w - LargeurBadChalie;
    int y_max = dest_rect.h - LongeurBadChalie + 50;
    int x_mid = x_max/2;
    int y_mid = y_max/2;
    int random_vall_x = rand ()%2+1;
    int random_vall_y = rand ()%2+1;
    int l = 0;
    bad_charlie();
    int deplacementgood;
    SDL_Rect rect_back = {0, 0, 512, 50};
    SDL_Rect charlie_ex = {466, 0, 44, 45};
//initialisation des deplacements de bad chalie suivant leur positions
    for(l=0;l <= NBCharlie-1 ;l++)
    {
        if(*tab_bad_charliex[l] <= x_mid && *tab_bad_charliey[l] <= y_mid)
            *deplacement[l] = 1;
        if(*tab_bad_charliex[l] <= x_mid && *tab_bad_charliey[l] >= y_mid)
            *deplacement[l] = 2;
        if(*tab_bad_charliex[l] >= x_mid && *tab_bad_charliey[l] >= y_mid)
            *deplacement[l] = 3;
        if(*tab_bad_charliex[l] >= x_mid && *tab_bad_charliey[l] <= y_mid)
            *deplacement[l] = 4;
        //printf("dep ini de %d = %d \n",l, *deplacement[l]);
    }
//initialisation des deplacements de good chalie suivant leur positions
    if(good_charlie.x <= x_mid && good_charlie.y <= y_mid)
        deplacementgood = 1;
    if(good_charlie.x <= x_mid && good_charlie.y >= y_mid)
        deplacementgood = 2;
    if(good_charlie.x >= x_mid && good_charlie.y >= y_mid)
        deplacementgood = 3;
    if(good_charlie.x >= x_mid && good_charlie.y <= y_mid)
        deplacementgood = 4;
// variable txt
    if(TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
//score
    TTF_Font *font = TTF_OpenFont("arlrdbd.ttf",20);
    SDL_Color color = { 255, 255, 255, 255};
    char Score_char[100] = "";
    sprintf(Score_char, "Score : %d", Score_int);
    SDL_Surface *textSurface = TTF_RenderText_Blended(font, Score_char ,color);
    SDL_Texture *textscore = SDL_CreateTextureFromSurface(renderer, textSurface );
    SDL_Rect textRectScore;
    textRectScore.x = 12;
    textRectScore.y = 12;
    SDL_FreeSurface(textSurface);
    textSurface = NULL;
    SDL_QueryTexture(textscore, NULL, NULL, &textRectScore.w, &textRectScore.h);
//chrono
    char Chrono_char[100] = "";
    int Chrono_int;
    SDL_Rect textRectChrono;
    textRectChrono.x = 200;
    textRectChrono.y = 12;
//txt charlie a trouver

    textSurface = TTF_RenderText_Blended(font, "Find :" ,color);
    SDL_Texture *textcharlie = SDL_CreateTextureFromSurface(renderer, textSurface );
    SDL_Rect textRectcharlie;
    textRectcharlie.x = 410;
    textRectcharlie.y = 12;
    SDL_FreeSurface(textSurface);
    textSurface = NULL;
    SDL_QueryTexture(textcharlie, NULL, NULL, &textRectcharlie.w, &textRectcharlie.h);


//image de fond
    picture = IMG_Load(img_fond);
    if(picture == NULL)
    {
        fprintf(stdout,"6Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, NULL, NULL);
        exit(EXIT_FAILURE);
    }

    texture_fond = SDL_CreateTextureFromSurface(renderer, picture);
    SDL_FreeSurface(picture);
    if(texture_fond == NULL)
    {
        fprintf(stdout,
                "5Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, NULL, NULL);
        exit(EXIT_FAILURE);
    }

//image de good charlie
    picture = IMG_Load(img_GoodChatlie);
    if(picture == NULL)
    {
        fprintf(stdout,"2Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, texture_fond, NULL);
        exit(EXIT_FAILURE);
    }

    texture_good_Charlie =SDL_CreateTextureFromSurface(renderer, picture);
    SDL_FreeSurface(picture);
    if(texture_good_Charlie == NULL)
    {
        fprintf(stdout,"1Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, texture_fond, NULL);
        exit(EXIT_FAILURE);
    }
//image de bad charlie
    picture = IMG_Load(img_BadChatlie);
    if(picture == NULL)
    {
        fprintf(stdout,"2Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, texture_fond, NULL);
        exit(EXIT_FAILURE);
    }

    texture_bad_Charlie =SDL_CreateTextureFromSurface(renderer, picture);
    SDL_FreeSurface(picture);
    if(texture_bad_Charlie == NULL)
    {
        fprintf(stdout,"1Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, texture_fond, NULL);
        exit(EXIT_FAILURE);
    }

//boucle
    while (continuer)
    {
        tempsActuel = SDL_GetTicks();
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_MOUSEBUTTONDOWN :
                for(int r=0;r < good_charlie.h ;r++)
                {
                    for(int x =0;x < good_charlie.w ;x++)
                    {
                        if (event.button.x == good_charlie.x + r && event.button.y == good_charlie.y + x  )
                        {
                            Score_int++;
                            if (Nb_Charlieplus < 49)
                            {
                                Nb_Charlieplus++;
                            }
                            //printf("%d \n", Nb_Charlieplus);
                            jouer(window, renderer, img_fond, img_GoodChatlie, img_BadChatlie, Nb_Charlieplus, SpeedCharlie, LargeurGoodChalie, LongeurGoodChalie, LargeurBadChalie, LongeurBadChalie, Score_int);
                            break;
                        }
                        else if(event.button.x != good_charlie.x + r && event.button.y != good_charlie.y + x)
                        {
                            continuer = 0;
                            fin = 1;
                            break;
                        }

                    }
                }
                break;

        }

        if(tempsActuel >= 30000 + tempsDeDepart)
        {
            fin = 1;
        }
        if(fin)
        {
            end_game(window, renderer, Score_int);
        }
        //printf("%d \n", (30-(tempsActuel/1000)) + tempsDeDepart/1000);
        Chrono_int = (30-(tempsActuel/1000)) + tempsDeDepart/1000;
        sprintf(Chrono_char, "Time : %d", Chrono_int);
        textSurface = TTF_RenderText_Blended(font, Chrono_char ,color);
        SDL_Texture *textchrono = SDL_CreateTextureFromSurface(renderer, textSurface );
        SDL_FreeSurface(textSurface);
        textSurface = NULL;


//image de fond
    if(SDL_QueryTexture(texture_fond, NULL, NULL, &dest_rect.w, &dest_rect.h) != 0)
    {
        fprintf(stdout,"4Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, texture_fond, NULL);
        exit(EXIT_FAILURE);
    }

    if(SDL_RenderCopy(renderer,texture_fond,NULL,&dest_rect) != 0)
    {
        fprintf(stdout,"3Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, texture_fond, NULL);
        exit(EXIT_FAILURE);
    }



//image de charlie
        if (tempsActuel - tempsPrecedent > SpeedCharlie) /* Si 30 ms se sont écoulées depuis le dernier tour de boucle */
        {
            for(l=0;l <= NBCharlie-1 ;l++)
            {
                //straightmov()
                straightmovrand();

            }
            straightmovgood()

        }
        //printf("%d \n", good_charlie);

        if(SDL_QueryTexture(texture_bad_Charlie, NULL, NULL, &LargeurBadChalie, &LongeurBadChalie) != 0)
        {
            fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
            clean_resources(window, renderer, texture_fond, texture_bad_Charlie);
            exit(EXIT_FAILURE);
        }

        if(SDL_QueryTexture(texture_good_Charlie, NULL, NULL, &good_charlie.w, &good_charlie.h) != 0)
        {
            fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
            clean_resources(window, renderer, texture_fond, texture_bad_Charlie);
            exit(EXIT_FAILURE);
        }

        for(int i = 0; i < NBCharlie/2;i++)
        {
            if(SDL_RenderCopy(renderer,texture_bad_Charlie,NULL,tab_bad_charlie[i]) != 0)
            {
                fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
                clean_resources(window, renderer, texture_fond, texture_bad_Charlie);
                exit(EXIT_FAILURE);
            }
        }

        if(SDL_RenderCopy(renderer,texture_good_Charlie,NULL,&good_charlie) != 0)
        {
            fprintf(stdout,"3Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
            clean_resources(window, renderer, texture_fond, NULL);
            exit(EXIT_FAILURE);
        }

        for(int i = NBCharlie/2; i < NBCharlie;i++)
        {
            if(SDL_RenderCopy(renderer,texture_bad_Charlie,NULL,tab_bad_charlie[i]) != 0)
            {
                fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
                clean_resources(window, renderer, texture_fond, texture_bad_Charlie);
                exit(EXIT_FAILURE);
            }
        }

//image de rectangle de fond
    SDL_SetRenderDrawColor (renderer, 0, 0, 0, 255);
    SDL_RenderFillRect (renderer, &rect_back);

//txt
    SDL_RenderCopy(renderer,textscore,NULL,&textRectScore);
    SDL_QueryTexture(textchrono, NULL, NULL, &textRectChrono.w, &textRectChrono.h);
    SDL_RenderCopy(renderer,textchrono,NULL,&textRectChrono);
    SDL_RenderCopy(renderer,textcharlie,NULL,&textRectcharlie);


    if(SDL_RenderCopy(renderer,texture_good_Charlie,NULL,&charlie_ex) != 0)
        {
            fprintf(stdout,"3Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
            clean_resources(window, renderer, texture_fond, NULL);
            exit(EXIT_FAILURE);
        }

    SDL_RenderPresent(renderer);

    }

    clean_resources(window, renderer, texture_fond, texture_good_Charlie);
    IMG_Quit();    SDL_DestroyTexture(texture_bad_Charlie);

    SDL_DestroyTexture(textscore);

    return EXIT_SUCCESS;
}


void end_game(SDL_Window* window, SDL_Renderer* renderer, int *Score)
{
    SDL_Event event;
    int continuer = 1;
    SDL_Surface *picture = NULL;
    SDL_Texture *texture_menu = NULL;
    SDL_Rect dest_rect = {0, 0, 512, 434};
    int Score_int = Score;

    TTF_Font *font = TTF_OpenFont("arlrdbd.ttf",20);
    SDL_Color color = { 255, 255, 255, 255};
    char Score_char[100] = "";
    sprintf(Score_char, "Your Score : %d", Score_int);
    SDL_Surface *textSurface = TTF_RenderText_Blended(font, Score_char ,color);
    SDL_Texture *textscore = SDL_CreateTextureFromSurface(renderer, textSurface );
    SDL_Rect textRectScore;
    textRectScore.x = 190;
    textRectScore.y = 200;
    SDL_FreeSurface(textSurface);
    textSurface = NULL;
    SDL_QueryTexture(textscore, NULL, NULL, &textRectScore.w, &textRectScore.h);


    picture = IMG_Load("img/img_end.png");
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
                    case SDLK_RETURN: // Demande à jouer
                        menu(window, renderer);
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
    SDL_RenderCopy(renderer,textscore,NULL,&textRectScore);

    SDL_RenderPresent(renderer);
    }

    clean_resources(window, renderer, texture_menu, NULL);
    return EXIT_SUCCESS;
}

