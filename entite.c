#include "entite.h"

int 
	nb_frame=12 ,
	entite_h=195,
	entite_w=135,
	entite_y=0,
	pos_init_x=700,
	pos_init_y=200,
	entite_x=0;



void init_tab_anim_entite(SDL_Rect *clip,entite *e)
{	
	for (int j=0;j<nb_frame; j++)
	{
		clip[j].h=entite_h;
		clip[j].w=entite_w;
		clip[j].x = j*entite_w;
		clip[j].y = 0;
        }  
}

void initialiser_entite(entite *e)
{
	e->entite = IMG_Load("ES4.png");
	e->pos_entite.x = pos_init_x;
	e->pos_entite.y = pos_init_y;
	init_tab_anim_entite(e->anim_entite,e);
	e->frame_entite=0;
	e->direction=0;  
	
}


void afficher_entite(entite * e , SDL_Surface *screen)
{
	SDL_BlitSurface(e->entite,&e->anim_entite[e->frame_entite], screen, &e->pos_entite);
}


void mvt_entite(entite *e,personnage *p)
{
	int diff_x=e->pos_entite.x-p->perso_pos.x;	
  	int diff_y=p->perso_pos.y-e->pos_entite.y;
	if (diff_x<350 && diff_x>50 )
	{
		e->pos_entite.x-=3;

		if(diff_y<350 && diff_y>50)
	{
		e->pos_entite.y+=3;
	}
	else if (diff_y >350)
	{
		e->pos_entite.y = pos_init_y;
	}


		if (diff_y >-350 && diff_y < 0 )
	{
		e->pos_entite.y-=3;
	} 

	else if (diff_y < -350)
	{
		e->pos_entite.y = pos_init_y;
	}


  	}
	else if (diff_x > 350 )
	{
		e->pos_entite.x = pos_init_x;
	}

	if (diff_x >-350 && diff_x < 0)
	{
  		e->pos_entite.x+=3;

		if(diff_y<350 && diff_y>50)
	{
		e->pos_entite.y+=3;
	}
	else if (diff_y >350)
	{
		e->pos_entite.y = pos_init_y;
	}


		if (diff_y >-350 && diff_y < 0 )
	{
		e->pos_entite.y-=3;
	} 

	else if (diff_y < -350)
	{
		e->pos_entite.y = pos_init_y;
	}

  	}
	else if (diff_x <-350 )
	{
		e->pos_entite.x = pos_init_x;
	}
	
	
	
	

}


void anim(entite *e)
{   
	if (e->frame_entite >=0 && e->frame_entite <(nb_frame-1)) {
 		e->frame_entite++;
		}
	if ( e->frame_entite ==(nb_frame-1)) {
		e->frame_entite=0;
		}
}


void update_entite(entite *e,personnage *p)
{	
	if (e->pos_entite.x!=0&&e->pos_entite.y!=0)
	{ 	
		mvt_entite(e,p);
		anim(e);
	}	
}

void initialiser_perso(personnage *p)
{
	p->perso= IMG_Load("perso1.png");
	p->perso_pos.x = 100;
	p->perso_pos.y = 100;
	p->perso_pos.h = 281;
	p->perso_pos.w = 217;  
}


int detect_collision(personnage *p, entite* e)
{

	if ((p->perso_pos.x + p->perso_pos. w< e->pos_entite. x) || (p->perso_pos.x> e->pos_entite. x + e->pos_entite. w) ||
		(p->perso_pos.y + p->perso_pos.h< e->pos_entite. y) || (p->perso_pos.y> e->pos_entite. y + e->pos_entite. h ))
		return 0;
	else 
		return 1;
}

int gestion(entite* e)
{ 	
	return 0;
}
