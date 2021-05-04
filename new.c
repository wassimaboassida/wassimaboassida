/**
* @file main.c
* @brief lot3.
* @author wassim
* @version 0.1
* @date  27/04/2021
*
* Testing program for lot3
*/









#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "entite.h"
#include "pres.h"

void newgame (SDL_Surface *screen ) 
{	int hauteur_fenetre = 1000,
	largeur_fenetre = 1500,a=1,b=0,done=1;
		int continuer=1;
	SDL_Surface *backg,*backgm;
	SDL_Rect backg_pos,backgm_pos;

	//SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	//screen=SDL_SetVideoMode(1200,675,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	//if(screen==NULL)
	//{
	//	printf("unable to set video mode:%s\n",SDL_GetError());
	//	return 1;
	//}

	backg = SDL_LoadBMP("map.bmp");
	backg_pos.x = 0;
	backg_pos.y = 0;
	backgm = SDL_LoadBMP("mapMasque.bmp");
	backgm_pos.x = 0;
	backgm_pos.y = 0;
//initialisation du temps et de map et du perso 

	Time temps;
	map m;
	pers perso;
	
	inittemps(&temps);
	initialiser_map (&m,screen,&perso) ;
	initialiserperso(&perso);
	entite e;
	initialiser_entite (&e) ;
	SDL_Event event;
	while (continuer)
	{	
	SDL_PollEvent(&event);
     
		update_time(&temps);
		deplacer_perso(&perso,event);
		collision(backgm,&perso);
		perso_map(&m,&perso);
		SDL_BlitSurface(backg,NULL,screen,&backg_pos);
		
		displaytime(temps,screen);
		affiche_map(&m,screen,&perso);
		afficher_perso(screen,perso);
		
	update_entite(&e,&perso);
	
	//SDL_BlitSurface(background,NULL,screen,&background_pos);
	
	b=detect_collision(&perso,&e);
 	if(b) a=gestion(&e);
	if (a){ afficher_entite(&e ,screen);}

		afficher_perso(screen,perso);
		
		
		SDL_Flip(screen);
		SDL_Delay(100);
	}

	freeTexttime(temps.temps);
	free_perso(perso);
	SDL_Quit();

	//return 1;
}
