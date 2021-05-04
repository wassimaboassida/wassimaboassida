#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "new.h"
int main(void)
{
    SDL_Surface *screen,*texte,*retour;
    SDL_Surface *jouer,*image,*parametre,*quitter,*personnage,*pierre,*jouer1,*parametre1,*quitter1,*volume,*volume1,*f[8];
    SDL_Surface *vol,*reso,*reso1;
    SDL_Rect postionimage,posjouer,posparametre,posquitter,postionjoueur,posretour,posvolume,posvolume1,posvol,posimage1,postexte,posanim;
    SDL_Event event;
    char pause;
    TTF_Init();
    int continuer=1,x=0,done=1,ta2=0,tp2=0,i1=128,p1,done1=1,i=1,re=1,w=1;
    Mix_Chunk *music,*music1;
    Mix_AllocateChannels(2);
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf("%s",Mix_GetError());
    }
    music=Mix_LoadWAV("Click De Souris.wav");
    music1=Mix_LoadWAV("fond.wav");
    Mix_VolumeChunk(music1,i1);
    if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("unable to initialize SDL: %s\n",SDL_GetError());
        return 1;
    }
    screen=SDL_SetVideoMode(1200,675,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        printf("unable to set video mode:%s\n",SDL_GetError());
        return 1;
    }
    vol=IMG_Load("V1.png");
    volume=IMG_Load("volume2.png");
    volume1=IMG_Load("volume3.png");
    SDL_WM_SetCaption("GAME!", NULL);
    f[1]=IMG_Load("tt1.jpg");
    f[2]=IMG_Load("tt2.jpg");
    f[3]=IMG_Load("tt3.jpg");
    f[4]=IMG_Load("tt4.jpg");
    f[5]=IMG_Load("tt5.jpg");
    f[6]=IMG_Load("tt6.jpg");
    f[7]=IMG_Load("tt7.jpg");
    f[8]=IMG_Load("tt8.jpg");
    /*f[9]=IMG_Load("tt9.png");
    f[10]=IMG_Load("tt10.png");
    f[11]=IMG_Load("t11.png");
    f[12]=IMG_Load("t12.png");
    f[13]=IMG_Load("t13.png");*/
    image=IMG_Load("background.jpeg");
    jouer=IMG_Load("12.png");
    jouer1=IMG_Load("11.png");
    parametre1=IMG_Load("21.png");
    parametre=IMG_Load("22.png");
    quitter=IMG_Load("31.png");
    quitter1=IMG_Load("32.png");
    personnage=IMG_Load("per.png");
    postionimage.x=0;
    postionimage.y=0;
    posjouer.x=580;
    posjouer.y=250;
    posparametre.x=580;
    posparametre.y=366;
    posquitter.x=580;
    posquitter.y=480;
    postexte.x=500;
    postexte.y=100;
    posvolume.x=600;
    posvolume.y=125;
    posvolume1.x=882;
    posvolume1.y=120;
    posvol.x=200;
    posvol.y=100;
    postionjoueur.x=5;
    postionjoueur.y=300;
posanim.x=500;
posanim.y=400;
    TTF_Font *fontTest;
    fontTest=TTF_OpenFont("LemonMilk.ttf",80);
    SDL_Color fontColor= {0,0,0};
    texte= TTF_RenderText_Solid(fontTest,"MAJESTY TEAM",fontColor);
    while(i!=8)
    {

        ta2 = SDL_GetTicks();


        if (ta2 - tp2 >= 250)
        {
            i++;

            SDL_BlitSurface(f[i],NULL,screen,&posanim);
            SDL_Flip(screen);
            tp2 = ta2;

        }
    }
    posjouer.x=250;
    posjouer.y=280;
    posparametre.x=250;
    posparametre.y=380;
    posquitter.x=250;
    posquitter.y=480;
    Mix_PlayChannel(2,music1,-1);

    SDL_BlitSurface(image,NULL,screen,&postionimage);
    SDL_BlitSurface(texte,NULL,screen,&postexte);
    SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
    SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
    SDL_BlitSurface(quitter,NULL,screen,&posquitter);
    SDL_Flip(screen);
    while(continuer)
    {

        done=1;
        done1=1;
        SDL_WaitEvent(&event);
        switch(event.type)
        {

        case SDL_QUIT:
            continuer=0;
            break;
        case SDL_KEYUP:
            switch(event.key.keysym.sym)
            {
            case SDLK_k:
                screen=SDL_SetVideoMode(1360,765,0,SDL_HWSURFACE|SDL_DOUBLEBUF);
                break ;
            case SDLK_j:
                screen=SDL_SetVideoMode(1360,765,0,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
                break ;//case

            case SDLK_UP:
                if(x==0)
                {
                    x=2;
                    break;
                }
                if(x==2)
                {
                    x=1;
                    break;
                }
                if(x==1)
                {
                    x=0;
                    break;
                }

                break;
            case SDLK_DOWN:

                x++;
                x=x%3;

                break;
            case SDLK_SPACE:
                if(x==0)
                    continuer=0;
                if(x==2)
                {
                    Mix_PlayChannel(1,music,0);
                    while(done1)
                    {
                        SDL_PollEvent(&event);
                        SDL_BlitSurface(image,NULL,screen,&postionimage);
                        SDL_BlitSurface(volume,NULL,screen,&posvolume);
                        SDL_BlitSurface(volume1,NULL,screen,&posvolume1);
                        SDL_BlitSurface(vol,NULL,screen,&posvol);
                        SDL_Flip(screen);
                        switch(event.type)
                        {
                        case SDL_MOUSEBUTTONDOWN :
                            if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<900&&event.button.x>600)&&(event.button.y<133&&event.button.y>125))
                            {
                                posvolume1.x=event.button.x;
                                if(((posvolume1.x-600)/2)>22)
                                    i1 = ((posvolume1.x-600)/2)-22;
                                if(((posvolume1.x-600)/2)<=22)
                                    i1 = - (((posvolume1.x-600)/2)-22);
                            }
                            Mix_VolumeChunk(music1,i1);
                            break;
                        case SDL_KEYDOWN:
                            switch(event.key.keysym.sym)
                            {
                            case SDLK_ESCAPE:
                                done1=0;
                                break;
                            }
                            break;
                        }

                    }
                }
                if(x==1)
                {
                    Mix_PlayChannel(1,music,0);
                    x=1;
                    while(done)
                    {



                    }
                }
                break;

                done=1;
            }
            if(x==1)
            {
                SDL_BlitSurface(image,NULL,screen,&postionimage);
                SDL_BlitSurface(texte,NULL,screen,&postexte);
                SDL_BlitSurface(jouer,NULL,screen,&posjouer);
                SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
                SDL_BlitSurface(quitter,NULL,screen,&posquitter);
                SDL_Flip(screen);
            }
            if(x==2)
            {
                SDL_BlitSurface(image,NULL,screen,&postionimage);
                SDL_BlitSurface(texte,NULL,screen,&postexte);
                SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
                SDL_BlitSurface(parametre,NULL,screen,&posparametre);
                SDL_BlitSurface(quitter,NULL,screen,&posquitter);
                SDL_Flip(screen);
            }
            if(x==0)
            {
                SDL_BlitSurface(image,NULL,screen,&postionimage);
                SDL_BlitSurface(texte,NULL,screen,&postexte);
                SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
                SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
                SDL_BlitSurface(quitter1,NULL,screen,&posquitter);
                SDL_Flip(screen);
            }
            break;
         case SDL_MOUSEMOTION:
        
        
        
        
        if ((event.motion.x<posjouer.x+jouer->w&&event.motion.x>posjouer.x)&&(event.motion.y<posjouer.y+jouer->h&&event.motion.y>posjouer.y))
        

            {
            
                SDL_BlitSurface(image,NULL,screen,&postionimage);
                SDL_BlitSurface(texte,NULL,screen,&postexte);
                SDL_BlitSurface(jouer,NULL,screen,&posjouer);
                SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
                SDL_BlitSurface(quitter,NULL,screen,&posquitter);
                SDL_Flip(screen);
            
            }
       
           else if((event.motion.x<posparametre.x+parametre->w&&event.motion.x>posparametre.x)&&(event.motion.y<posparametre.y+parametre->h &&event.motion.y>posparametre.y))
                 {
                SDL_BlitSurface(image,NULL,screen,&postionimage);
                SDL_BlitSurface(texte,NULL,screen,&postexte);
                SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
                SDL_BlitSurface(parametre,NULL,screen,&posparametre);
                SDL_BlitSurface(quitter,NULL,screen,&posquitter);
                SDL_Flip(screen);
                 }
           else if((event.motion.x<posquitter.x+quitter->w&&event.motion.x>posquitter.x)&&(event.motion.y<posquitter.y+quitter->h&&event.motion.y>posquitter.y))
            {
                SDL_BlitSurface(image,NULL,screen,&postionimage);
                SDL_BlitSurface(texte,NULL,screen,&postexte);
                SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
                SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
                SDL_BlitSurface(quitter1,NULL,screen,&posquitter);
                SDL_Flip(screen);
            }
            else 
             
            {
            
            
            
                SDL_BlitSurface(image,NULL,screen,&postionimage);
                SDL_BlitSurface(texte,NULL,screen,&postexte);
                SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
                SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
                SDL_BlitSurface(quitter,NULL,screen,&posquitter);
                SDL_Flip(screen);
                
                

            }
            break;
        case SDL_MOUSEBUTTONDOWN :
            //play
            if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posjouer.x+jouer->w&&event.button.x>posjouer.x)&&(event.button.y<posjouer.y+jouer->h&&event.button.y>posjouer.y))
            {   
           
                                  newgame (screen )  ; 
             
            }
            re=1;
            SDL_Flip(screen);
            //settings
            if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posparametre.x+parametre->w&&event.button.x>posparametre.x)&&(event.button.y<posparametre.y+parametre->h &&event.button.y>posparametre.y))
            {
                Mix_PlayChannel(1,music,0);

                while((done1)&&(re))
                {
                    retour=IMG_Load("retour.png");
                    posretour.x=1000;
                    posretour.y=50;
                    SDL_PollEvent(&event);
                    SDL_BlitSurface(image,NULL,screen,&postionimage);
                    SDL_BlitSurface(volume,NULL,screen,&posvolume);
                    SDL_BlitSurface(volume1,NULL,screen,&posvolume1);
                    SDL_BlitSurface(vol,NULL,screen,&posvol);
                    SDL_BlitSurface(retour,NULL,screen,&posretour);
                    SDL_Flip(screen);
                    switch(event.type)
                    {
                    case SDL_MOUSEBUTTONDOWN :
                        if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<900&&event.button.x>600)&&(event.button.y<133&&event.button.y>125))
                        {
                            posvolume1.x=event.button.x;
                            if(((posvolume1.x-600)/2)>22)
                                i1=((posvolume1.x-600)/2)-22;
                            if(((posvolume1.x-600)/2)<=22)
                                i1=-(((posvolume1.x-600)/2)-22);
                        }
                        Mix_VolumeChunk(music1,i1);


                        if((event.button.x>1000&&event.button.x<1100)&&(event.button.y>50&&event.button.y<200))
                        {


                            Mix_PlayChannel(1,music,0);
                            re=0;

                        }

                        break;


                    case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                        {
                        case SDLK_ESCAPE:
                            done1=0;
                            break;
                        }
                        break;
                    }

                }


            }
            re=1;

            SDL_Flip(screen);

            if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posquitter.x+quitter->w&&event.button.x>posquitter.x)&&(event.button.y<posquitter.y+quitter->h&&event.button.y>posquitter.y))
            {
                Mix_PlayChannel(1,music,0);
                continuer=0;
                SDL_Flip(screen);
            }
        }
    }

    SDL_FreeSurface(image);
    SDL_FreeSurface(texte);
    SDL_FreeSurface(jouer1);
    SDL_FreeSurface(parametre1);
    SDL_FreeSurface(quitter);
    SDL_Quit();
    return 1;
}


