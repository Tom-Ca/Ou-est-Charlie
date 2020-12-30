
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



void choix_niveau(SDL_Window* window, SDL_Renderer* renderer)
{


    SDL_Event event;
    int continuer = 1;
    SDL_Surface *picture = NULL;
    SDL_Texture *texture_menu = NULL;
    SDL_Rect dest_rect = {0, 0, 512, 434};
    parametre();


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
                        jouer(window, renderer, img_fond_1, img_GoodCharlie_1, NULL, NULL, speed_charlie_1);

                        break;
                    case SDLK_2: // Demande à jouer
                        //jouer(window, renderer, img_fond_2, img_GoodCharlie_2, NULL, NULL, speed_charlie_2);

                        break;
                    case SDLK_3: // Demande à jouer
                        //jouer(window, renderer, img_fond_3, img_GoodCharlie_3, NULL, NULL, speed_charlie_3);

                        break;
                    case SDLK_4: // Demande à jouer
                        //jouer(window, renderer, img_fond_3, img_GoodCharlie_3, NULL, NULL, speed_charlie_3);

                        break;
                    case SDLK_5: // Demande à jouer
                        //main();

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

void choix_niveau_edite(SDL_Window* window, SDL_Renderer* renderer)
{


    SDL_Event event;
    int continuer = 1;
    SDL_Surface *picture = NULL;
    SDL_Texture *texture_menu = NULL;
    SDL_Rect dest_rect = {0, 0, 512, 434};
    parametre();


    picture = IMG_Load("img/choix_niveau_edite.png");
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
                        //jouer(window, renderer, img_fond_1, img_GoodCharlie_1, NULL, NULL, speed_charlie_1);

                        break;
                    case SDLK_2: // Demande à jouer
                        //jouer(window, renderer, img_fond_2, img_GoodCharlie_2, NULL, NULL, speed_charlie_2);

                        break;
                    case SDLK_3: // Demande à jouer
                        choix_niveau(window, renderer);
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
