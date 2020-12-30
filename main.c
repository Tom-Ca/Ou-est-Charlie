#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "constantes.h"
#include "jeu.h"



int main(int argc, char* argv[])
{

    SDL_Event event;
    int continuer = 1;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Surface *picture = NULL;
    SDL_Texture *texture_menu = NULL;
    SDL_Rect dest_rect = {0, 0, 512, 434};



    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(NULL, NULL, NULL, NULL);
        exit(EXIT_FAILURE);
    }

    window = SDL_CreateWindow("affichage de fond",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, dest_rect.w, dest_rect.h, 0);
    if(window == NULL)
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(NULL, NULL, NULL, NULL);
        exit(EXIT_FAILURE);
    }

    renderer  = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if(renderer == NULL)
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, NULL, NULL, NULL);
        exit(EXIT_FAILURE);
    }

    picture = IMG_Load("img/menu.jpg");
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
                        choix_niveau(window, renderer);

                        break;
                    //case SDLK_KP2: // Demande l'éditeur de niveaux
                       // editeur(ecran);
                       // break;
                }
                break;
        }
    ////

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
