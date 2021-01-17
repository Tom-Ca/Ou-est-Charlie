/*
jeu.h
-----

Par tom et Alexandre , pour projet de où est charlie

Rôle : prototypes des fonctions du jeu.
*/

#ifndef DEF_JEU
#define DEF_JEU

    void jouer(SDL_Window* window, SDL_Renderer* renderer, char *img_fond, char *img_GoodChatlie, char *img_BadChatlie, int *nb_Charlie, int *speed_charlie, int *largeur_good_chalie,int *longeur_good_chalie,int *largeur_bad_chalie,int *longeur_bad_chalie, int *score);
    void clean_resources(SDL_Window *w, SDL_Renderer *r, SDL_Texture *t, SDL_Texture *t2);
    void end_game(SDL_Window* window, SDL_Renderer* renderer, int *Score);


#endif


