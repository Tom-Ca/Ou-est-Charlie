#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>

void clean_resources(SDL_Window *w, SDL_Renderer *r, SDL_Texture *t)
{
    if(t != NULL)
        SDL_DestroyTexture(t);

    if(r != NULL)
        SDL_DestroyRenderer(r);

    if(w != NULL)
        SDL_DestroyWindow(w);
    SDL_Quit();
}

int main(int argc, char** argv)
{

    SDL_Event event;
    int continuer = 1;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Surface *picture =NULL;
    SDL_Texture *texture = NULL, *texture2 = NULL;
    SDL_Rect dest_rect = {0, 50, 512, 384};
    SDL_Rect dest_rect2 = {0, 50, 46, 64};
    int tempsPrecedent = 0, tempsActuel = 0;
    srand( time( NULL ) );


    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(NULL, NULL, NULL);
        exit(EXIT_FAILURE);
    }

    window = SDL_CreateWindow("affichage de fond",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 512, 424, 0);
    if(window == NULL)
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(NULL, NULL, NULL);
        exit(EXIT_FAILURE);
    }

    renderer  = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if(renderer == NULL)
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, NULL, NULL);
        exit(EXIT_FAILURE);
    }

    while (continuer)
    {
        SDL_PollEvent(&event); /* On utilise PollEvent et non WaitEvent pour ne pas bloquer le programme */
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }




    picture = IMG_Load("img/imageBMP.png");
    if(picture == NULL)
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, NULL);
        exit(EXIT_FAILURE);
    }

    texture = SDL_CreateTextureFromSurface(renderer, picture);
    SDL_FreeSurface(picture);
    if(texture == NULL)
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, NULL);
        exit(EXIT_FAILURE);
    }

        if(SDL_QueryTexture(texture, NULL, NULL, &dest_rect.w, &dest_rect.h) != 0)
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, texture);
        exit(EXIT_FAILURE);
    }

    if(SDL_RenderCopy(renderer,texture,NULL,&dest_rect) != 0)
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, texture);
        exit(EXIT_FAILURE);
    }

    ////////////////////////////////////////////////////

    picture = IMG_Load("img/charlie6.png");
    if(picture == NULL)
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, NULL);
        exit(EXIT_FAILURE);
    }

    texture2 =SDL_CreateTextureFromSurface(renderer, picture);
    SDL_FreeSurface(picture);
    if(texture == NULL)
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, NULL);
        exit(EXIT_FAILURE);
    }

    tempsActuel = SDL_GetTicks();
    if (tempsActuel - tempsPrecedent > 1) /* Si 30 ms se sont écoulées depuis le dernier tour de boucle */
    {
            int n = rand ()%4;
            if (n==0)
            {
                do
                {
                    dest_rect2.x++;
                    tempsPrecedent = tempsActuel;
                }while (dest_rect2.x > 466);
            }

            if (n==1)
            {
                do
                {
                    dest_rect2.x--;
                    tempsPrecedent = tempsActuel;
                }while (dest_rect2.x < 0);
            }

            if (n==2)
            {
                do
                {
                    dest_rect2.y++;
                    tempsPrecedent = tempsActuel;
                }while (dest_rect2.y > 320);
            }

            if (n==3)
            {
                do
                {
                    dest_rect2.y--;
                    tempsPrecedent = tempsActuel;
                }while (dest_rect2.y < 0);
            }
            tempsPrecedent = tempsActuel;

        /*if(dest_rect2.x == 512 || dest_rect2.y == 384 || dest_rect2.x == -47 || dest_rect2.y == 50)
        {
            dest_rect2.x = -46;
            dest_rect2.y = rand() % 301 +50;
        }*/

    }
    else /* Si ça fait moins de 30 ms depuis le dernier tour de boucle, on endort le programme le temps qu'il faut */
    {
        SDL_Delay(30 - (tempsActuel - tempsPrecedent));
    }

    if(SDL_QueryTexture(texture2, NULL, NULL, &dest_rect2.w, &dest_rect2.h) != 0)
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, texture);
        exit(EXIT_FAILURE);
    }

    if(SDL_RenderCopy(renderer,texture2,NULL,&dest_rect2) != 0)
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        clean_resources(window, renderer, texture);
        exit(EXIT_FAILURE);
    }

    //////////////////////////////////////////////////
    SDL_RenderPresent(renderer);

    }

    clean_resources(window, renderer, texture);
    return EXIT_SUCCESS;
}
