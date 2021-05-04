/**
* @file pres.c
  @brief pers.
* @author wassim
* @version 0.1
* @date  27/04/2021




*/




#include "new.h"
#include "pres.h"




/**

* @brief initialiserperso .
* @param perso  pers

* @return Nothing

*/





void initialiserperso(pers *perso)
{	
	perso->image_p=IMG_Load("hero.bmp");
	perso->pos_perso.x=0;
	perso->pos_perso.y=150;
	perso->pos_perso.w=120;
	perso->pos_perso.h=120;
}

/**

* @brief afficher_perso .
* @param perso  pers
* @param screen the screen
* @return Nothing

*/


void afficher_perso(SDL_Surface *screen,pers perso)
{	
	SDL_BlitSurface(perso.image_p,NULL,screen,&perso.pos_perso);
}
/**

* @brief deplacer_perso .
* @param perso  pers
* @param event SDL_Event
* @return Nothing

*/
void deplacer_perso(pers *perso,SDL_Event event)
{	
	SDL_PollEvent(&event);
         switch(event.type)
            {
                case SDL_KEYDOWN:
                       switch(event.key.keysym.sym)
                        {
                        
                        case SDLK_UP:
                            perso->pos_perso.y=perso->pos_perso.y-10;
                            break;
                        case SDLK_DOWN:
                            perso->pos_perso.y=perso->pos_perso.y+10;
                            break;
                        case SDLK_RIGHT:
                            perso->pos_perso.x=perso->pos_perso.x+10;
                            break;
                        case SDLK_LEFT:
                            perso->pos_perso.x=perso->pos_perso.x-10;
                            break;
                        }
                 break;
             }
}



/**

* @brief free_perso .
* @param perso  pers

* @return Nothing

*/
void free_perso(pers perso)
{
	SDL_FreeSurface(perso.image_p);
}
/**

* @brief initialiser_map .
* @param perso  pers
* @param m  map
* @param screen the screen
* @return Nothing

*/

void initialiser_map (map *m,SDL_Surface *screen,pers *perso)
{
	m->map=IMG_Load("minimap.jpeg");
	m->pos_map.x = 50;
	m->pos_map.y = 50;

	m->mini_perso=SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_DOUBLEBUF,4,21,14,0,0,0,0);
	SDL_FillRect(m->mini_perso,NULL,SDL_MapRGB(screen->format,220,222,25));
	m->perso_pos_map.x=0;
	m->perso_pos_map.y=0;

}


/**

* @brief perso_map .
* @param perso  pers
* @param m  map

* @return Nothing

*/

void perso_map(map *m,pers *perso)
{
	m->perso_pos_map.x=perso->pos_perso.x/5+m->pos_map.x;
	m->perso_pos_map.y=perso->pos_perso.y/5+m->pos_map.y;
}

/**

* @brief affiche_map .
* @param perso  pers
* @param m  map
* @param screen the screen
* @return Nothing

*/
void affiche_map(map *m , SDL_Surface *screen,pers *perso)
{
	SDL_BlitSurface(m->map, NULL, screen,&m->pos_map);
	SDL_BlitSurface(m->mini_perso, NULL, screen,&m->perso_pos_map);
}
/**

* @brief affiche_map .
* @param x  int
* @param y int
* @param pSurface  SDL_Surface

* @return SDL_Color

*/
SDL_Color getpixel(SDL_Surface *pSurface,int x,int y)
{	
	SDL_Color color;
	Uint32 col=0;
	char* pPosition=(char* ) pSurface->pixels;
	pPosition+= (pSurface->pitch * y);
	pPosition+= (pSurface->format->BytesPerPixel *x);
	memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
	SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
	return (color);
}

/**

* @brief collisionparfaite .
* @param perso  pers

* @param pSurface  SDL_Surface

* @return int

*/


int  collisionparfaite(SDL_Surface *psurface,pers perso)
{	
	int tabx[7],taby[7],i;
	SDL_Color color1,color;
	color1.r = 0;
	color1.g = 0;
	color1.b = 0;
	tabx[0]=perso.pos_perso.x;
	tabx[1]=(perso.pos_perso.x)+((perso.pos_perso.w)/2);
	tabx[2]=(perso.pos_perso.x+perso.pos_perso.w);
	tabx[3]=perso.pos_perso.x;
	tabx[4]=perso.pos_perso.x;
	tabx[5]=(perso.pos_perso.x)+((perso.pos_perso.w)/2);
	tabx[6]=(perso.pos_perso.x+perso.pos_perso.w);
        tabx[7]=(perso.pos_perso.x+perso.pos_perso.w);
	taby[0]=perso.pos_perso.y;
	taby[1]=perso.pos_perso.y;
	taby[2]=perso.pos_perso.y;
	taby[3]=(perso.pos_perso.y)+((perso.pos_perso.h)/2);
	taby[4]=(perso.pos_perso.y+perso.pos_perso.h);
	taby[5]=(perso.pos_perso.y+perso.pos_perso.h);
	taby[6]=(perso.pos_perso.y+perso.pos_perso.h);
        taby[7]=(perso.pos_perso.y)+((perso.pos_perso.h)/2);
	
	for(i=0;i<8;i++)
	{
	color=getpixel(psurface,tabx[i],taby[i]);
	if(color.r==color1.r && color.b==color1.b && color.g==color1.g)
	{
		return i;

	}
	}
	return 10;
	
}	
/**

* @brief collision .
* @param perso  pers

* @param pSurface  SDL_Surface

* @return NOTHING

*/
void collision(SDL_Surface *psurface,pers *perso)
{	int i;
	i=collisionparfaite(psurface,*perso);

	switch (i)
	{
		case 0 :perso->pos_perso.y=perso->pos_perso.y+10;
			break;
		case 1 :perso->pos_perso.y=perso->pos_perso.y+10;
			 break;
		case 2 :perso->pos_perso.y=perso->pos_perso.y+10;
			break;
		case 3 :perso->pos_perso.x=perso->pos_perso.x+10;
			break;
		case 4 :perso->pos_perso.y=perso->pos_perso.y-10;
			break;
		case 5 :perso->pos_perso.y=perso->pos_perso.y-10; 
			break;
		case 6 :perso->pos_perso.y=perso->pos_perso.y-10; 
			break;
		case 7 :perso->pos_perso.x=perso->pos_perso.x-10;
			break;
		

	}
}
/**

* @brief Timer .
* @param tempsdebut  int



* @return NOTHING

*/
void Timer(int *tempsdebut)
{
    
   if( SDL_GetTicks() - *tempsdebut >= 1000 )
    {
        *tempsdebut = SDL_GetTicks() ;
      
      
    }
  
}
/**

* @brief inittemps .
* @param t  Time



* @return NOTHING

*/
void inittemps(Time *t)
{   int test; 
	t->tempsdebut=SDL_GetTicks();
	t->mm=0;
	t->ss=0;
	test=initTexttime(&t->temps);
}
/**

* @brief initTexttime .
* @param T  Text



* @return NOTHING

*/
int initTexttime(Text* T)
{ int testload;
    T->couleurTxt.r = 55; 
    T->couleurTxt.g = 25; 
    T->couleurTxt.b = 55;

    strcpy(T->txt, "");
    T->positionText.x = 900;
    T->positionText.y = 20; 
    testload=loadFonttime(T,"Semibold.ttf");
    T->textSurface=NULL;
    return testload;   
}



/**

* @brief loadFonttime .
* @param T  Text
* @param ch  char


* @return int

*/



int loadFonttime(Text* T, char* ch)
{
    TTF_Font* police = NULL;

    if(TTF_Init() == -1) {
        printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        return -1;
    }
    T->police= TTF_OpenFont(ch,60);
    if (police == NULL) {
        printf("Unable to load Font: %s\n", SDL_GetError());
        return (-1);
    }
    return (0);
}
/**

* @brief update_time .
* @param T  Text



* @return Nothing

*/

void update_time(Time* T)
{   int ts;
    Timer(&T->tempsdebut);
    ts=T->tempsdebut/1000;


    T->mm=ts/ 60;
    T->ss=ts % 60;
    
    if(T->mm<10&&T->ss<10)
       sprintf(T->temps.txt," 0%d:0%d  ",T->mm,T->ss);
    else if(T->mm<10&&T->ss>10)
        sprintf(T->temps.txt," 0%d:%d  ",T->mm,T->ss);
    else if(T->mm>10&&T->ss<10)
          sprintf(T->temps.txt," %d:0%d  ",T->mm,T->ss);
    
    T->temps.textSurface=TTF_RenderText_Solid(T->temps.police,T->temps.txt,T->temps.couleurTxt);
}

/**

* @brief displaytime .
* @param T  Time
* @param screen the screen


* @return Nothing

*/



void displaytime(Time T,SDL_Surface *screen)
{
    
     
     SDL_BlitSurface(T.temps.textSurface,NULL,screen,&(T.temps.positionText));

}
/**

* @brief freeTexttime .
* @param T  Text



* @return Nothing

*/



void freeTexttime(Text T)
{
    TTF_CloseFont(T.police); 
    TTF_Quit();    
}













