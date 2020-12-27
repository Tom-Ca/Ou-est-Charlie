
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>

#include "constantes.h"
#include "jeu.h"

void clean_resources(SDL_Window *w, SDL_Renderer *r, SDL_Texture *t, SDL_Texture *t2){
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

void jouer(SDL_Window* window, SDL_Renderer* renderer)
{
//variables
    SDL_Event event;
    int continuer = 1;
    SDL_Surface *picture =NULL;
    SDL_Texture *texture = NULL, *texture2 = NULL;
    SDL_Rect dest_rect = {0, 50, 512, 384};
    SDL_Rect dest_rect2 = {0, 50, 46, 64};
    int tempsPrecedent = 0, tempsActuel = 0;
    srand( time( NULL ) );
    int haut_gauche = 0;
    int haut_droite = 0;
    int bas_gauche = 0;
    int bas_droite = 0;
    int x_max = dest_rect.w - dest_rect2.w;
    int y_max = dest_rect.h - dest_rect2.h + 50;
    int x_mid = x_max/2;
    int y_mid = y_max/2;
    int random_vall_x;
    int random_vall_y;

//image de fond
    picture = IMG_Load("img/imageBMP.png");
    if(picture == NULL)
    {
        fprintf(stdout,"6Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, NULL, NULL);
        exit(EXIT_FAILURE);
    }

    texture = SDL_CreateTextureFromSurface(renderer, picture);
    SDL_FreeSurface(picture);
    if(texture == NULL)
    {
        fprintf(stdout,
                "5Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, NULL, NULL);
        exit(EXIT_FAILURE);
    }

//image de charlie
    picture = IMG_Load("img/charlie6.png");
    if(picture == NULL)
    {
        fprintf(stdout,"2Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, texture, NULL);
        exit(EXIT_FAILURE);
    }

    texture2 =SDL_CreateTextureFromSurface(renderer, picture);
    SDL_FreeSurface(picture);
    if(texture2 == NULL)
    {
        fprintf(stdout,"1Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, texture, NULL);
        exit(EXIT_FAILURE);
    }

//boucle
    while (continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }

//image de fond
    if(SDL_QueryTexture(texture, NULL, NULL, &dest_rect.w, &dest_rect.h) != 0)
    {
        fprintf(stdout,"4Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, texture, NULL);
        exit(EXIT_FAILURE);
    }

    if(SDL_RenderCopy(renderer,texture,NULL,&dest_rect) != 0)
    {
        fprintf(stdout,"3Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, texture, NULL);
        exit(EXIT_FAILURE);
    }

//image de charlie
    tempsActuel = SDL_GetTicks();
    if (tempsActuel - tempsPrecedent > 1) /* Si 30 ms se sont écoulées depuis le dernier tour de boucle */
    {

        if((dest_rect2.x <= 0 && dest_rect2.y <= y_mid && dest_rect2.y >= 50) || (dest_rect2.y <= 50 && dest_rect2.x <= x_mid && dest_rect2.x >= 0))
        {
            haut_droite = 0;
            bas_droite = 0;
            bas_gauche = 0;
            haut_gauche=1;
            random_vall_x = rand ()%2;
            random_vall_y = rand ()%2 + 1;
        }

        else if((dest_rect2.x <= 0 && dest_rect2.y <= y_max && dest_rect2.y >= y_mid) || (dest_rect2.y >= y_max && dest_rect2.x <= x_mid && dest_rect2.x >= 0))
        {
            haut_droite = 0;
            haut_gauche = 0;
            bas_droite = 0;
            bas_gauche = 1;
            random_vall_x = rand ()%2;
            random_vall_y = rand ()%2 + 1;
        }

        else if((dest_rect2.x >= x_max && dest_rect2.y <= y_max && dest_rect2.y >= y_mid) || (dest_rect2.y >= y_max && dest_rect2.x <= x_max && dest_rect2.x >= x_mid))
        {
            haut_droite = 0;
            haut_gauche=0;
            bas_gauche = 0;
            bas_droite = 1;
            random_vall_x = rand ()%2;
            random_vall_y = rand ()%2 + 1;
        }

        else if((dest_rect2.x >= x_max && dest_rect2.y <= y_mid && dest_rect2.y >= 50) || (dest_rect2.y <= 50 && dest_rect2.x <= x_max && dest_rect2.x >= x_mid))
        {
            bas_droite = 0;
            bas_gauche = 0;
            haut_gauche=0;
            haut_droite = 1;
            random_vall_x = rand ()%2;
            random_vall_y = rand ()%2 + 1;
        }
        /////
        if(haut_gauche == 1)
            {
                dest_rect2.x = dest_rect2.x + random_vall_x ;
                dest_rect2.y = dest_rect2.y + random_vall_y ;
                tempsPrecedent = tempsActuel;
            }
        if(bas_gauche == 1)
            {
                dest_rect2.x = dest_rect2.x + random_vall_x ;
                dest_rect2.y = dest_rect2.y - random_vall_y ;
                tempsPrecedent = tempsActuel;
            }
        if(bas_droite == 1)
            {
                dest_rect2.x = dest_rect2.x - random_vall_x ;
                dest_rect2.y = dest_rect2.y - random_vall_y ;
                tempsPrecedent = tempsActuel;
            }
        if(haut_droite == 1)
            {
                dest_rect2.x = dest_rect2.x - random_vall_x ;
                dest_rect2.y = dest_rect2.y + random_vall_y ;
                tempsPrecedent = tempsActuel;
            }
    }
    else /* Si ça fait moins de 30 ms depuis le dernier tour de boucle, on endort le programme le temps qu'il faut */
    {
        SDL_Delay(30 - (tempsActuel - tempsPrecedent));
    }

    if(SDL_QueryTexture(texture2, NULL, NULL, &dest_rect2.w, &dest_rect2.h) != 0)
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, texture, texture2);
        exit(EXIT_FAILURE);
    }

    if(SDL_RenderCopy(renderer,texture2,NULL,&dest_rect2) != 0)
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, texture, texture2);
        exit(EXIT_FAILURE);
    }

    //////////////////////////////////////////////////
    SDL_RenderPresent(renderer);
    }

    clean_resources(window, renderer, texture, texture2);
    return EXIT_SUCCESS;
}
