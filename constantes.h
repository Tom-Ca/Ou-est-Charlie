/*
constantes.h
------------

Par tom et Alexandre , pour projet de où est charlie

Rôle : définit des constantes et des macros pour tout le programme
*/
#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

    #define parametre()     char img_fond_1[] = "img/fond_1.jpg";\
                            char img_GoodCharlie_1[] = "img/charlie_1.png";\
                            char img_BadCharlie_1[] = "img/bad_charlie_1.png";\
                            int speed_charlie_1 = 25;\
                            int nb_Charlie_1 = 15;\
                            int largeur_good_chalie_1 = 46;\
                            int longeur_good_chalie_1 = 64;\
                            int largeur_bad_chalie_1 = 46;\
                            int longeur_bad_chalie_1 = 54;\
                            \
                            char img_fond_2[] = "img/fond_2.png";\
                            char img_GoodCharlie_2[] = "img/charlie_2.png";\
                            char img_BadCharlie_2[] = "img/bad_charlie_2.png";\
                            int speed_charlie_2 = 9;\
                            int nb_Charlie_2 = 10;\
                            int largeur_good_chalie_2 = 46;\
                            int longeur_good_chalie_2 = 52;\
                            int largeur_bad_chalie_2 = 46;\
                            int longeur_bad_chalie_2 = 92;\
                            \
                            char img_fond_3[] = "img/fond_3.jpg";\
                            char img_GoodCharlie_3[] = "img/charlie_3.png";\
                            char img_BadCharlie_3[] = "img/bad_charlie_3.png";\
                            int speed_charlie_3 = 1;\
                            int nb_Charlie_3 = 5;\
                            int largeur_good_chalie_3 = 55;\
                            int longeur_good_chalie_3 = 43;\
                            int largeur_bad_chalie_3 = 46;\
                            int longeur_bad_chalie_3 = 52;\
                            \
                            int map;\
                            int skin_goodcharlie;\
                            int skin_badcharlie;\
                            int lengths_goodcharlie;\
                            int width_goodcharlie;\
                            int lengths_badcharlie;\
                            int width_badcharlie;\
                            int nbofcharlie;\
                            int speedofcharlie;\
                            int easyspeed = speed_charlie_1;\
                            int normalspeed = speed_charlie_2 ;\
                            int hardcorespeed = speed_charlie_3;\
                            int easynb = nb_Charlie_1;\
                            int normalnb = nb_Charlie_2;\
                            int hardcorenb = nb_Charlie_3;\




    #define bad_charlie()   SDL_Rect bad_charlie1 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie2 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie3 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie4 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie5 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie6 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie7 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie8 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie9 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie10 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie11 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie12 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie13 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie14 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie15 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie16 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie17 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie18 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie19 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie20 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie21 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie22 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie23 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie24 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie25 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie26 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie27 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie28 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie29 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie30 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie31 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie32 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie33 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie34 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie35 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie36 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie37 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie38 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie39 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie40 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie41 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie42 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie43 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie44 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie45 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie46 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie47 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie48 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie49 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            SDL_Rect bad_charlie50 = {rand() % 466,  rand() % 292+50, LargeurBadChalie, LongeurBadChalie};\
                            int *tab_bad_charlie[] = {&bad_charlie1, &bad_charlie2, &bad_charlie3,&bad_charlie4,&bad_charlie5,\
                                                      &bad_charlie6,&bad_charlie7,&bad_charlie8,&bad_charlie9,&bad_charlie10, \
                                                      &bad_charlie11, &bad_charlie12, &bad_charlie13,&bad_charlie14,&bad_charlie15,\
                                                      &bad_charlie16,&bad_charlie17,&bad_charlie18,&bad_charlie19,&bad_charlie20,\
                                                      &bad_charlie21, &bad_charlie22, &bad_charlie23,&bad_charlie24,&bad_charlie25,\
                                                      &bad_charlie26,&bad_charlie27,&bad_charlie28,&bad_charlie29,&bad_charlie30,\
                                                      &bad_charlie31, &bad_charlie32, &bad_charlie33,&bad_charlie34,&bad_charlie35,\
                                                      &bad_charlie36,&bad_charlie37,&bad_charlie38,&bad_charlie39,&bad_charlie40,\
                                                      &bad_charlie41, &bad_charlie42, &bad_charlie43,&bad_charlie44,&bad_charlie45,\
                                                      &bad_charlie46,&bad_charlie47,&bad_charlie48,&bad_charlie49,&bad_charlie50};\
                            int *tab_bad_charliex[] = {&bad_charlie1.x, &bad_charlie2.x, &bad_charlie3.x,&bad_charlie4.x,&bad_charlie5.x,\
                                                      &bad_charlie6.x,&bad_charlie7.x,&bad_charlie8.x,&bad_charlie9.x,&bad_charlie10.x, \
                                                      &bad_charlie11.x, &bad_charlie12.x, &bad_charlie13.x,&bad_charlie14.x,&bad_charlie15.x,\
                                                      &bad_charlie16.x,&bad_charlie17.x,&bad_charlie18.x,&bad_charlie19.x,&bad_charlie20.x,\
                                                      &bad_charlie21.x, &bad_charlie22.x, &bad_charlie23.x,&bad_charlie24.x,&bad_charlie25.x,\
                                                      &bad_charlie26.x,&bad_charlie27.x,&bad_charlie28.x,&bad_charlie29.x,&bad_charlie30.x,\
                                                      &bad_charlie31.x, &bad_charlie32.x, &bad_charlie33.x,&bad_charlie34.x,&bad_charlie35.x,\
                                                      &bad_charlie36.x,&bad_charlie37.x,&bad_charlie38.x,&bad_charlie39.x,&bad_charlie40.x,\
                                                      &bad_charlie41.x, &bad_charlie42.x, &bad_charlie43.x,&bad_charlie44.x,&bad_charlie45.x,\
                                                      &bad_charlie46.x,&bad_charlie47.x,&bad_charlie48.x,&bad_charlie49.x,&bad_charlie50.x};\
                            int *tab_bad_charliey[] = {&bad_charlie1.y, &bad_charlie2.y, &bad_charlie3.y,&bad_charlie4.y,&bad_charlie5.y,\
                                                      &bad_charlie6.y,&bad_charlie7.y,&bad_charlie8.y,&bad_charlie9.y,&bad_charlie10.y, \
                                                      &bad_charlie11.y, &bad_charlie12.y, &bad_charlie13.y,&bad_charlie14.y,&bad_charlie15.y,\
                                                      &bad_charlie16.y,&bad_charlie17.y,&bad_charlie18.y,&bad_charlie19.y,&bad_charlie20.y,\
                                                      &bad_charlie21.y, &bad_charlie22.y, &bad_charlie23.y,&bad_charlie24.y,&bad_charlie25.y,\
                                                      &bad_charlie26.y,&bad_charlie27.y,&bad_charlie28.y,&bad_charlie29.y,&bad_charlie30.y,\
                                                      &bad_charlie31.y, &bad_charlie32.y, &bad_charlie33.y,&bad_charlie34.y,&bad_charlie35.y,\
                                                      &bad_charlie36.y,&bad_charlie37.y,&bad_charlie38.y,&bad_charlie39.y,&bad_charlie40.y,\
                                                      &bad_charlie41.y, &bad_charlie42.y, &bad_charlie43.y,&bad_charlie44.y,&bad_charlie45.y,\
                                                      &bad_charlie46.y,&bad_charlie47.y,&bad_charlie48.y,&bad_charlie49.y,&bad_charlie50.y};

    #define dep()           int deplacement1 = 0;\
                            int deplacement2 = 0;\
                            int deplacement3 = 0;\
                            int deplacement4 = 0;\
                            int deplacement5 = 0;\
                            int deplacement6 = 0;\
                            int deplacement7 = 0;\
                            int deplacement8 = 0;\
                            int deplacement9 = 0;\
                            int deplacement10 = 0;\
                            int deplacement11 = 0;\
                            int deplacement12 = 0;\
                            int deplacement13 = 0;\
                            int deplacement14 = 0;\
                            int deplacement15 = 0;\
                            int deplacement16 = 0;\
                            int deplacement17 = 0;\
                            int deplacement18 = 0;\
                            int deplacement19 = 0;\
                            int deplacement20 = 0;\
                            int deplacement21 = 0;\
                            int deplacement22 = 0;\
                            int deplacement23 = 0;\
                            int deplacement24 = 0;\
                            int deplacement25 = 0;\
                            int deplacement50 = 0;\
                            int deplacement49 = 0;\
                            int deplacement48= 0;\
                            int deplacement47= 0;\
                            int deplacement46= 0;\
                            int deplacement45= 0;\
                            int deplacement44= 0;\
                            int deplacement43= 0;\
                            int deplacement42= 0;\
                            int deplacement41= 0;\
                            int deplacement40= 0;\
                            int deplacement39= 0;\
                            int deplacement38= 0;\
                            int deplacement37= 0;\
                            int deplacement36= 0;\
                            int deplacement35= 0;\
                            int deplacement34= 0;\
                            int deplacement33= 0;\
                            int deplacement32= 0;\
                            int deplacement31= 0;\
                            int deplacement30= 0;\
                            int deplacement29= 0;\
                            int deplacement28= 0;\
                            int deplacement27= 0;\
                            int deplacement26= 0;\
                            int *deplacement[] = {    &deplacement1, &deplacement2, &deplacement3,&deplacement4,&deplacement5,\
                                                      &deplacement6,&deplacement7,&deplacement8,&deplacement9,&deplacement10,\
                                                      &deplacement11, &deplacement12, &deplacement13,&deplacement14,&deplacement15,\
                                                      &deplacement16,&deplacement17,&deplacement18,&deplacement19,&deplacement20,\
                                                      &deplacement21, &deplacement22, &deplacement23,&deplacement24,&deplacement25,\
                                                      &deplacement26,&deplacement27,&deplacement28,&deplacement29,&deplacement30,\
                                                      &deplacement31, &deplacement32, &deplacement33,&deplacement34,&deplacement35,\
                                                      &deplacement36,&deplacement37,&deplacement38,&deplacement39,&deplacement40,\
                                                      &deplacement41, &deplacement42, &deplacement43,&deplacement44,&deplacement45,\
                                                      &deplacement46,&deplacement47,&deplacement48,&deplacement49,&deplacement50};


    #define straightmov()   if((*tab_bad_charliex[l] <= 0 && *tab_bad_charliey[l] <= y_mid && *tab_bad_charliey[l] >= 50) || (*tab_bad_charliey[l] <= 50 && *tab_bad_charliex[l] <= x_mid && *tab_bad_charliex[l] >= 0))\
                            {\
                                *deplacement[l] = 1;\
                                random_vall_x = rand ()%2;\
                                random_vall_y = rand ()%2+1;\
                            }\
                            else if((*tab_bad_charliex[l] <= 0 && *tab_bad_charliey[l] <= y_max && *tab_bad_charliey[l] >= y_mid) || (*tab_bad_charliey[l] >= y_max && *tab_bad_charliex[l] <= x_mid && *tab_bad_charliex[l] >= 0))\
                            {\
                                *deplacement[l] = 2;\
                                random_vall_x = rand ()%2;\
                                random_vall_y = rand ()%2+1 ;\
                            }\
                            else if((*tab_bad_charliex[l] >= x_max && *tab_bad_charliey[l] <= y_max && *tab_bad_charliey[l] >= y_mid) || (*tab_bad_charliey[l] >= y_max && *tab_bad_charliex[l] <= x_max && *tab_bad_charliex[l] >= x_mid))\
                            {\
                                *deplacement[l] = 3;\
                                random_vall_x = rand ()%2;\
                                random_vall_y = rand ()%2+1 ;\
                            }\
                            else if((*tab_bad_charliex[l] >= x_max && *tab_bad_charliey[l] <= y_mid && *tab_bad_charliey[l] >= 50) || (*tab_bad_charliey[l] <= 50 && *tab_bad_charliex[l] <= x_max && *tab_bad_charliex[l] >= x_mid))\
                            {\
                                *deplacement[l] = 4;\
                                random_vall_x = rand ()%2;\
                                random_vall_y = rand ()%2+1;\
                            }\
                            if(*deplacement[l] == 1)\
                            {\
                                *tab_bad_charliex[l] = *tab_bad_charliex[l]+ random_vall_x ;\
                                *tab_bad_charliey[l] = *tab_bad_charliey[l] + random_vall_y ;\
                                tempsPrecedent = tempsActuel;\
                            }\
                            if(*deplacement[l] == 2)\
                            {\
                              *tab_bad_charliex[l] = *tab_bad_charliex[l] + random_vall_x ;\
                              *tab_bad_charliey[l] = *tab_bad_charliey[l]  - random_vall_y ;\
                              tempsPrecedent = tempsActuel;\
                            }\
                            if(*deplacement[l] == 3)\
                            {\
                                *tab_bad_charliex[l] = *tab_bad_charliex[l]  - random_vall_x ;\
                                *tab_bad_charliey[l] = *tab_bad_charliey[l]  - random_vall_y ;\
                                tempsPrecedent = tempsActuel;\
                            }\
                            if(*deplacement[l] == 4)\
                            {\
                                *tab_bad_charliex[l] = *tab_bad_charliex[l]  - random_vall_x ;\
                                *tab_bad_charliey[l] = *tab_bad_charliey[l] + random_vall_y ;\
                                tempsPrecedent = tempsActuel;\
                            }


    #define straightmovgood()   if((good_charlie.x <= 0 && good_charlie.y <= y_mid && good_charlie.y >= 50) || (good_charlie.y <= 50 && good_charlie.x <= x_mid && good_charlie.x >= 0))\
                                {\
                                    deplacementgood = 1;\
                                    random_vall_x = rand ()%2+1;\
                                    random_vall_y = rand ()%2;\
                                }\
                                else if((good_charlie.x <= 0 && good_charlie.y <= y_max && good_charlie.y >= y_mid) || (good_charlie.y >= y_max && good_charlie.x <= x_mid && good_charlie.x >= 0))\
                                {\
                                    deplacementgood = 2;\
                                    random_vall_x = rand ()%2;\
                                    random_vall_y = rand ()%2+1 ;\
                                }\
                                else if((good_charlie.x >= x_max && good_charlie.y <= y_max && good_charlie.y >= y_mid) || (good_charlie.y >= y_max && good_charlie.x <= x_max && good_charlie.x >= x_mid))\
                                {\
                                    deplacementgood = 3;\
                                    random_vall_x = rand ()%2;\
                                    random_vall_y = rand ()%2+1 ;\
                                }\
                                else if((good_charlie.x >= x_max && good_charlie.y <= y_mid && good_charlie.y >= 50) || (good_charlie.y <= 50 && good_charlie.x <= x_max && good_charlie.x >= x_mid))\
                                {\
                                    deplacementgood = 4;\
                                    random_vall_x = rand ()%2+1;\
                                    random_vall_y = rand ()%2;\
                                }\
                                if(deplacementgood == 1)\
                                {\
                                    good_charlie.x = good_charlie.x+ random_vall_x ;\
                                    good_charlie.y = good_charlie.y + random_vall_y ;\
                                    tempsPrecedent = tempsActuel;\
                                }\
                                if(deplacementgood == 2)\
                                {\
                                  good_charlie.x = good_charlie.x + random_vall_x ;\
                                  good_charlie.y = good_charlie.y  - random_vall_y ;\
                                  tempsPrecedent = tempsActuel;\
                                }\
                                if(deplacementgood == 3)\
                                {\
                                    good_charlie.x = good_charlie.x  - random_vall_x ;\
                                    good_charlie.y = good_charlie.y  - random_vall_y ;\
                                    tempsPrecedent = tempsActuel;\
                                }\
                                if(deplacementgood == 4)\
                                {\
                                    good_charlie.x = good_charlie.x  - random_vall_x ;\
                                    good_charlie.y = good_charlie.y + random_vall_y ;\
                                    tempsPrecedent = tempsActuel;\
                                }



#define random()   int random_vall_x1 = rand ()%2+1;\
                    int random_vall_x2 = rand ()%2+1;\
                    int random_vall_x3 = rand ()%2+1;\
                    int random_vall_x4 = rand ()%2+1;\
                    int random_vall_x5 = rand ()%2+1;\
                    int random_vall_x6 = rand ()%2+1;\
                    int random_vall_x7 = rand ()%2+1;\
                    int random_vall_x8 = rand ()%2+1;\
                    int random_vall_x9 = rand ()%2+1;\
                    int random_vall_x10 = rand ()%2+1;\
                    int random_vall_x11 = rand ()%2+1;\
                    int random_vall_x12 = rand ()%2+1;\
                    int random_vall_x13 = rand ()%2+1;\
                    int random_vall_x14 = rand ()%2+1;\
                    int random_vall_x15 = rand ()%2+1;\
                    int random_vall_x16 = rand ()%2+1;\
                    int random_vall_x17 = rand ()%2+1;\
                    int random_vall_x18 = rand ()%2+1;\
                    int random_vall_x19 = rand ()%2+1;\
                    int random_vall_x20 = rand ()%2+1;\
                    int random_vall_x21 = rand ()%2+1;\
                    int random_vall_x22 = rand ()%2+1;\
                    int random_vall_x23 = rand ()%2+1;\
                    int random_vall_x24 = rand ()%2+1;\
                    int random_vall_x25 = rand ()%2+1;\
                    int random_vall_x26 = rand ()%2+1;\
                    int random_vall_x27 = rand ()%2+1;\
                    int random_vall_x28 = rand ()%2+1;\
                    int random_vall_x29 = rand ()%2+1;\
                    int random_vall_x30 = rand ()%2+1;\
                    int random_vall_x31 = rand ()%2+1;\
                    int random_vall_x32 = rand ()%2+1;\
                    int random_vall_x33 = rand ()%2+1;\
                    int random_vall_x34 = rand ()%2+1;\
                    int random_vall_x35 = rand ()%2+1;\
                    int random_vall_x36 = rand ()%2+1;\
                    int random_vall_x37 = rand ()%2+1;\
                    int random_vall_x38 = rand ()%2+1;\
                    int random_vall_x39 = rand ()%2+1;\
                    int random_vall_x40 = rand ()%2+1;\
                    int random_vall_x41 = rand ()%2+1;\
                    int random_vall_x42 = rand ()%2+1;\
                    int random_vall_x43 = rand ()%2+1;\
                    int random_vall_x44 = rand ()%2+1;\
                    int random_vall_x45 = rand ()%2+1;\
                    int random_vall_x46 = rand ()%2+1;\
                    int random_vall_x47 = rand ()%2+1;\
                    int random_vall_x48 = rand ()%2+1;\
                    int random_vall_x49 = rand ()%2+1;\
                    int random_vall_x50 = rand ()%2+1;\
                    int *tab_random_vall_x[] = {&random_vall_x1, &random_vall_x2, &random_vall_x3,&random_vall_x4,&random_vall_x5,\
                                                 &random_vall_x6,&random_vall_x7,&random_vall_x8,&random_vall_x9,&random_vall_x10, \
                                                 &random_vall_x11, &random_vall_x12, &random_vall_x13,&random_vall_x14,&random_vall_x15,\
                                                 &random_vall_x16,&random_vall_x17,&random_vall_x18,&random_vall_x19,&random_vall_x20,\
                                                 &random_vall_x21, &random_vall_x22, &random_vall_x23,&random_vall_x24,&random_vall_x25,\
                                                 &random_vall_x26,&random_vall_x27,&random_vall_x28,&random_vall_x29,&random_vall_x30,\
                                                 &random_vall_x31, &random_vall_x32, &random_vall_x33,&random_vall_x34,&random_vall_x35,\
                                                 &random_vall_x36,&random_vall_x37,&random_vall_x38,&random_vall_x39,&random_vall_x40,\
                                                 &random_vall_x41, &random_vall_x42, &random_vall_x43,&random_vall_x44,&random_vall_x45,\
                                                 &random_vall_x46,&random_vall_x47,&random_vall_x48,&random_vall_x49,&random_vall_x50};\
\
                    int random_vall_y1 = rand ()%2+1;\
                    int random_vall_y2 = rand ()%2+1;\
                    int random_vall_y3 = rand ()%2+1;\
                    int random_vall_y4 = rand ()%2+1;\
                    int random_vall_y5 = rand ()%2+1;\
                    int random_vall_y6 = rand ()%2+1;\
                    int random_vall_y7 = rand ()%2+1;\
                    int random_vall_y8 = rand ()%2+1;\
                    int random_vall_y9 = rand ()%2+1;\
                    int random_vall_y10 = rand ()%2+1;\
                    int random_vall_y11 = rand ()%2+1;\
                    int random_vall_y12 = rand ()%2+1;\
                    int random_vall_y13 = rand ()%2+1;\
                    int random_vall_y14 = rand ()%2+1;\
                    int random_vall_y15 = rand ()%2+1;\
                    int random_vall_y16 = rand ()%2+1;\
                    int random_vall_y17 = rand ()%2+1;\
                    int random_vall_y18 = rand ()%2+1;\
                    int random_vall_y19 = rand ()%2+1;\
                    int random_vall_y20 = rand ()%2+1;\
                    int random_vall_y21 = rand ()%2+1;\
                    int random_vall_y22 = rand ()%2+1;\
                    int random_vall_y23 = rand ()%2+1;\
                    int random_vall_y24 = rand ()%2+1;\
                    int random_vall_y25 = rand ()%2+1;\
                    int random_vall_y26 = rand ()%2+1;\
                    int random_vall_y27 = rand ()%2+1;\
                    int random_vall_y28 = rand ()%2+1;\
                    int random_vall_y29 = rand ()%2+1;\
                    int random_vall_y30 = rand ()%2+1;\
                    int random_vall_y31 = rand ()%2+1;\
                    int random_vall_y32 = rand ()%2+1;\
                    int random_vall_y33 = rand ()%2+1;\
                    int random_vall_y34 = rand ()%2+1;\
                    int random_vall_y35 = rand ()%2+1;\
                    int random_vall_y36 = rand ()%2+1;\
                    int random_vall_y37 = rand ()%2+1;\
                    int random_vall_y38 = rand ()%2+1;\
                    int random_vall_y39 = rand ()%2+1;\
                    int random_vall_y40 = rand ()%2+1;\
                    int random_vall_y41 = rand ()%2+1;\
                    int random_vall_y42 = rand ()%2+1;\
                    int random_vall_y43 = rand ()%2+1;\
                    int random_vall_y44 = rand ()%2+1;\
                    int random_vall_y45 = rand ()%2+1;\
                    int random_vall_y46 = rand ()%2+1;\
                    int random_vall_y47 = rand ()%2+1;\
                    int random_vall_y48 = rand ()%2+1;\
                    int random_vall_y49 = rand ()%2+1;\
                    int random_vall_y50 = rand ()%2+1;\
                    int *tab_random_vall_y[] = {&random_vall_y1, &random_vall_y2, &random_vall_y3,&random_vall_y4,&random_vall_y5,\
                                                 &random_vall_y6,&random_vall_y7,&random_vall_y8,&random_vall_y9,&random_vall_y10, \
                                                 &random_vall_y11, &random_vall_y12, &random_vall_y13,&random_vall_y14,&random_vall_y15,\
                                                 &random_vall_y16,&random_vall_y17,&random_vall_y18,&random_vall_y19,&random_vall_y20,\
                                                 &random_vall_y21, &random_vall_y22, &random_vall_y23,&random_vall_y24,&random_vall_y25,\
                                                 &random_vall_y26,&random_vall_y27,&random_vall_y28,&random_vall_y29,&random_vall_y30,\
                                                 &random_vall_y31, &random_vall_y32, &random_vall_y33,&random_vall_y34,&random_vall_y35,\
                                                 &random_vall_y36,&random_vall_y37,&random_vall_y38,&random_vall_y39,&random_vall_y40,\
                                                 &random_vall_y41, &random_vall_y42, &random_vall_y43,&random_vall_y44,&random_vall_y45,\
                                                 &random_vall_y46,&random_vall_y47,&random_vall_y48,&random_vall_y49,&random_vall_y50};\


    #define straightmovrand()   if((*tab_bad_charliex[l] <= 0 && *tab_bad_charliey[l] <= y_mid && *tab_bad_charliey[l] >= 50) || (*tab_bad_charliey[l] <= 50 && *tab_bad_charliex[l] <= x_mid && *tab_bad_charliex[l] >= 0))\
                            {\
                                *deplacement[l] = 1;\
                                *tab_random_vall_x[l] = rand ()%2;\
                                *tab_random_vall_y[l] = rand ()%2+1;\
                            }\
                            else if((*tab_bad_charliex[l] <= 0 && *tab_bad_charliey[l] <= y_max && *tab_bad_charliey[l] >= y_mid) || (*tab_bad_charliey[l] >= y_max && *tab_bad_charliex[l] <= x_mid && *tab_bad_charliex[l] >= 0))\
                            {\
                                *deplacement[l] = 2;\
                                *tab_random_vall_x[l] = rand ()%2;\
                                *tab_random_vall_y[l] = rand ()%2+1 ;\
                            }\
                            else if((*tab_bad_charliex[l] >= x_max && *tab_bad_charliey[l] <= y_max && *tab_bad_charliey[l] >= y_mid) || (*tab_bad_charliey[l] >= y_max && *tab_bad_charliex[l] <= x_max && *tab_bad_charliex[l] >= x_mid))\
                            {\
                                *deplacement[l] = 3;\
                                *tab_random_vall_x[l] = rand ()%2;\
                                *tab_random_vall_y[l] = rand ()%2+1 ;\
                            }\
                            else if((*tab_bad_charliex[l] >= x_max && *tab_bad_charliey[l] <= y_mid && *tab_bad_charliey[l] >= 50) || (*tab_bad_charliey[l] <= 50 && *tab_bad_charliex[l] <= x_max && *tab_bad_charliex[l] >= x_mid))\
                            {\
                                *deplacement[l] = 4;\
                                *tab_random_vall_x[l] = rand ()%2;\
                                *tab_random_vall_y[l] = rand ()%2+1;\
                            }\
                            if(*deplacement[l] == 1)\
                            {\
                                *tab_bad_charliex[l] = *tab_bad_charliex[l]+ *tab_random_vall_x[l] ;\
                                *tab_bad_charliey[l] = *tab_bad_charliey[l] + *tab_random_vall_y[l] ;\
                                tempsPrecedent = tempsActuel;\
                            }\
                            if(*deplacement[l] == 2)\
                            {\
                              *tab_bad_charliex[l] = *tab_bad_charliex[l] + *tab_random_vall_x[l] ;\
                              *tab_bad_charliey[l] = *tab_bad_charliey[l]  - *tab_random_vall_y[l] ;\
                              tempsPrecedent = tempsActuel;\
                            }\
                            if(*deplacement[l] == 3)\
                            {\
                                *tab_bad_charliex[l] = *tab_bad_charliex[l]  - *tab_random_vall_x[l] ;\
                                *tab_bad_charliey[l] = *tab_bad_charliey[l]  - *tab_random_vall_y[l] ;\
                                tempsPrecedent = tempsActuel;\
                            }\
                            if(*deplacement[l] == 4)\
                            {\
                                *tab_bad_charliex[l] = *tab_bad_charliex[l]  - *tab_random_vall_x[l] ;\
                                *tab_bad_charliey[l] = *tab_bad_charliey[l] + *tab_random_vall_y[l] ;\
                                tempsPrecedent = tempsActuel;\
                            }





    #define newlv();    FILE * savedlv = NULL;\
                            savedlv = fopen("savedlv.txt", "r+" );\
                            if (savedlv != NULL)\
                            { fseek(savedlv, 0, SEEK_SET);\
                              fprintf(savedlv, "%d %d %d %d %d %d %d %d %d", map, skin_goodcharlie,skin_badcharlie, nbofcharlie, speedofcharlie, width_goodcharlie, lengths_goodcharlie, width_badcharlie, lengths_badcharlie  );\
                              fclose(savedlv);\
                            }




#endif




