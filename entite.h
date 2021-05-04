#ifndef entite_H_INCLUDED
#define entite_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include<time.h>

typedef struct 
{
	SDL_Surface *entite ;
	SDL_Rect pos_entite;
	SDL_Rect anim_entite[70];
	int frame_entite;
	int direction;
	int maxi_up,maxi_down;
	
}entite ;

typedef struct
{
	SDL_Surface *perso; 
	SDL_Rect perso_pos ;
}personnage ;

	void init_tab_anim_entite(SDL_Rect* clip,entite *e); 
	void initialiser_entite (entite *e) ;
	void afficher_entite(entite * e , SDL_Surface *screen);
	void anim(entite *e);
	void mvt_entite(entite *e,personnage *p);
	void update_entite(entite *e,personnage *p);
	void initialiser_perso(personnage *p);
	//void afficher_perso(personnage * p , SDL_Surface *screen);
	int detect_collision(personnage *p, entite* e);
	int gestion(entite* e);


#endif 
