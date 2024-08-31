#include <iostream>
#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
#include <string>
#include <cmath>
#include <fstream>
#include <SDL2/SDL_mixer.h>
#include <cstdlib>
using namespace std;
void menu(SDL_Renderer *Renderer);
void filledrect(SDL_Renderer *Renderer, int x,int y, int w, int h , int R, int G, int B, int fill_boolian);
void mode(SDL_Renderer *Renderer);
void setting(SDL_Renderer *Renderer);
void fmusic(SDL_Renderer *Renderer);
void theme(SDL_Renderer *Renderer);


int main(int argc,char*argv[]){

    Uint32 SDL_flags=SDL_INIT_VIDEO | SDL_INIT_TIMER |SDL_INIT_AUDIO| IMG_INIT_JPG|IMG_INIT_PNG;
    Uint32 WND_flags=SDL_WINDOW_SHOWN;
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
    SDL_Init(SDL_flags);
    SDL_CreateWindowAndRenderer(1400,800,WND_flags,&m_window,&m_renderer);
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,1,1024);
    Mix_Music *bgmusic = Mix_LoadMUS(R"(C:\Users\HP\CLionProjects\untitled6\bgmusic.mp3)");





    int v=64;
    bool quit= false;
    bool rmode=false;
    bool mode1=false;
    bool mode2=false;
    bool mode3=false;
    bool mode4=false;
    bool setting1=false;
    bool music=false;
    bool soundeffect=false;
    bool themes=false;
    SDL_Event e ;
    while(!quit) {

        int mx;
        int my;
        int modex;
        int modey;
        int setx;
        int sety;
        int musicx;
        int musicy;

        while (SDL_PollEvent(&e) != 0) {
            Mix_PlayMusic(bgmusic,-1);
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                SDL_GetMouseState(&mx, &my);
            }
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            if (mx >= 500 && mx <= 900 && my >= 100 && my <= 250) {
                std::cout << "start";
                rmode = true;
                while (rmode) {
                    while (SDL_PollEvent(&e) != 0) {
                        if (e.type == SDL_MOUSEBUTTONDOWN) {
                            SDL_GetMouseState(&modex, &modey);
                        }
                        if (e.type == SDL_QUIT) {
                            quit = true;
                            rmode = false;
                        }
                        mode(m_renderer);
                        if (modex >= 500 && modex <= 900 && modey >= 150 && modey <= 250) {
                            std::cout << "1";
                            mode1 = true;
                        }if (modex >= 500 && modex <= 900 && modey >= 300 && modey <= 400) {
                            std::cout << "2";
                            mode2 = true;
                        }if (modex >= 500 && modex <= 900 && modey >= 450 && modey <= 550) {
                            std::cout << "3";
                            mode3 = true;
                            std::cout << "4";
                            mode4 = true;
                        }
                    }
                }

            } else if (mx >= 600 && mx <= 800 && my >= 300 && my <= 400) {
                std::cout << "setting";
                setting1 = true;
                while (setting1) {
                    while (SDL_PollEvent(&e) != 0) {
                        if (e.type == SDL_MOUSEBUTTONDOWN) {
                            SDL_GetMouseState(&setx, &sety);
                        }
                        if (e.type == SDL_QUIT) {
                            quit = true;
                            setting1 = false;
                        }
                        setting(m_renderer);
                        if (setx >= 600 && setx <= 850 && sety >= 200 && sety <= 280) {
                            soundeffect = true;
                        }
                        if (setx >= 600 && setx <= 850 && sety >= 350 && sety <= 430) {
                            cout<<"music";
                            music = true;
                            while(music){
                                while (SDL_PollEvent(&e) != 0) {
                                    if (e.type == SDL_MOUSEBUTTONDOWN) {
                                        SDL_GetMouseState(&musicx, &musicy);
                                    }
                                    if (e.type == SDL_QUIT) {
                                        quit = true;
                                        music = false;
                                        setting1=false;
                                    }

                                    Mix_VolumeMusic(v);
                                    if(musicx>=300 && musicx<=500 && musicy>=300 && musicy<=500){
                                        v=0;
                                    }

                                    if(musicx>=600 && musicx<=800 && musicy>=300 && musicy<=500 && v<=128){
                                        v+=10;
                                        Mix_VolumeMusic(v);
                                    }
                                    if(musicx>=900 && musicx<=1100 && musicy>=300 && musicy<=500 && v>=0){
                                        v-=10;
                                        Mix_VolumeMusic(v);
                                    }
                                    fmusic(m_renderer);
                                }
                            }
                        }
                        else if (setx >= 600 && setx <= 850 && sety >= 500 && sety <= 580) {
                            themes = true;
                            while (themes){
                                while (SDL_PollEvent(&e) != 0) {
                                    if (e.type == SDL_MOUSEBUTTONDOWN) {
                                        SDL_GetMouseState(&musicx, &musicy);
                                    }
                                    if (e.type == SDL_QUIT) {
                                        quit = true;
                                        themes = false;
                                        setting1 = false;
                                    }
                                    theme(m_renderer);
                                }

                            }
                        }
                    }
                }

            }

            else if (mx>=600 && mx<=800 && my>=450 && my<=550){
                std::cout<<"scores";
                //score va esm bazikona
            }
            else if (mx>=600 && mx<=800 && my>=600 && my<=700){
                std::cout<<"exit";
                //exit
            }

        }

        menu(m_renderer);
        SDL_RenderPresent(m_renderer);
        SDL_Delay(25);

    }

}

void menu(SDL_Renderer *Renderer){
    SDL_Texture* image= IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/bgm.png");

    SDL_Rect imageRect;
    imageRect.x=0;
    imageRect.y=0;
    imageRect.w=1400;
    imageRect.h=800;

    SDL_RenderCopy(Renderer,image,NULL,&imageRect);
    filledrect(Renderer,500,100,400,150,0,128,255,1);
    filledrect(Renderer,600,300,200,100,0,128,255,1);
    filledrect(Renderer,600,450,200,100,0,128,255,1);
    filledrect(Renderer,600,600,200,100,0,128,255,1);
    TTF_Init();
    TTF_Font* font= TTF_OpenFont("C:/Users/HP/CLionProjects/untitled6/font.otf",60);
    TTF_Font* font2= TTF_OpenFont("C:/Users/HP/CLionProjects/untitled6/font.otf",30);
    SDL_Color textColor = {255,255,255,255};
    SDL_Surface* textSurface = TTF_RenderText_Solid(font,"START",textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(Renderer,textSurface);
    SDL_Rect textRect = {590,130,textSurface->w,textSurface->h};
    SDL_RenderCopy(Renderer,textTexture,NULL,&textRect);
    SDL_Surface* textSurface2 = TTF_RenderText_Solid(font2,"SETTINGS",textColor);
    SDL_Texture* textTexture2 = SDL_CreateTextureFromSurface(Renderer,textSurface2);
    SDL_Rect textRect2 = {613,330,textSurface2->w,textSurface2->h};
    SDL_RenderCopy(Renderer,textTexture2,NULL,&textRect2);
    SDL_Surface* textSurface3 = TTF_RenderText_Solid(font2,"SCORES",textColor);
    SDL_Texture* textTexture3 = SDL_CreateTextureFromSurface(Renderer,textSurface3);
    SDL_Rect textRect3 = {633,480,textSurface3->w,textSurface3->h};
    SDL_RenderCopy(Renderer,textTexture3,NULL,&textRect3);
    SDL_Surface* textSurface4 = TTF_RenderText_Solid(font2,"EXIT",textColor);
    SDL_Texture* textTexture4 = SDL_CreateTextureFromSurface(Renderer,textSurface4);
    SDL_Rect textRect4 = {658,630,textSurface4->w,textSurface4->h};
    SDL_RenderCopy(Renderer,textTexture4,NULL,&textRect4);
    SDL_RenderPresent(Renderer);






}
void filledrect(SDL_Renderer *Renderer, int x,int y, int w, int h , int R, int G, int B, int fill_boolian){
    SDL_Rect rectangle;
    rectangle.x=x;
    rectangle.y=y;
    rectangle.w=w;
    rectangle.h=h;
    SDL_SetRenderDrawColor(Renderer,R,G,B,255);
    if (fill_boolian==1){
        SDL_RenderFillRect(Renderer, &rectangle);
        SDL_RenderDrawRect(Renderer,&rectangle);

    }
}
void mode(SDL_Renderer *Renderer){
    SDL_Texture* image= IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/bgmode.jpg");

    SDL_Rect imageRect;
    imageRect.x=0;
    imageRect.y=0;
    imageRect.w=1400;
    imageRect.h=800;

    SDL_RenderCopy(Renderer,image,NULL,&imageRect);
    filledrect(Renderer,500,150,400,100,0,128,255,1);
    filledrect(Renderer,500,300,400,100,0,128,255,1);
    filledrect(Renderer,500,450,400,100,0,128,255,1);
    filledrect(Renderer,500,600,400,100,0,128,255,1);

    TTF_Font* font= TTF_OpenFont("C:/Users/HP/CLionProjects/untitled6/font.otf",40);
    SDL_Color textColor = {255,255,255,255};
    SDL_Surface* textSurface = TTF_RenderText_Solid(font,"NORMAL MODE",textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(Renderer,textSurface);
    SDL_Rect textRect = {550,180,textSurface->w,textSurface->h};
    SDL_RenderCopy(Renderer,textTexture,NULL,&textRect);


    SDL_Surface* textSurface2 = TTF_RenderText_Solid(font,"TIMER MODE",textColor);
    SDL_Texture* textTexture2 = SDL_CreateTextureFromSurface(Renderer,textSurface2);
    SDL_Rect textRect2 = {550,320,textSurface2->w,textSurface2->h};
    SDL_RenderCopy(Renderer,textTexture2,NULL,&textRect2);

    SDL_Surface* textSurface3 = TTF_RenderText_Solid(font,"RANDOM MODE",textColor);
    SDL_Texture* textTexture3= SDL_CreateTextureFromSurface(Renderer,textSurface3);
    SDL_Rect textRect3 = {550,470,textSurface3->w,textSurface3->h};
    SDL_RenderCopy(Renderer,textTexture3,NULL,&textRect3);

    SDL_Surface* textSurface4 = TTF_RenderText_Solid(font,"INFINITE MODE",textColor);
    SDL_Texture* textTexture4= SDL_CreateTextureFromSurface(Renderer,textSurface4);
    SDL_Rect textRect4= {550,620,textSurface4->w,textSurface4->h};
    SDL_RenderCopy(Renderer,textTexture4,NULL,&textRect4);
    SDL_Texture* image4= IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/BACK.png");

    SDL_Rect image4Rect;
    image4Rect.x=100;
    image4Rect.y=650;
    image4Rect.w=100;
    image4Rect.h=50;
    SDL_RenderCopy(Renderer,image4,NULL,&image4Rect);
    SDL_RenderPresent(Renderer);

}

void setting(SDL_Renderer *Renderer){

    SDL_Texture* image= IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/bspace.jpg");

    SDL_Rect imageRect;
    imageRect.x=0;
    imageRect.y=0;
    imageRect.w=1400;
    imageRect.h=800;

    SDL_RenderCopy(Renderer,image,NULL,&imageRect);
    SDL_Texture* image2= IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/sf.png");

    SDL_Rect image2Rect;
    image2Rect.x=600;
    image2Rect.y=200;
    image2Rect.w=250;
    image2Rect.h=80;
    SDL_RenderCopy(Renderer,image2,NULL,&image2Rect);

    SDL_Texture* image3= IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/musics.png");

    SDL_Rect image3Rect;
    image3Rect.x=600;
    image3Rect.y=350;
    image3Rect.w=250;
    image3Rect.h=80;
    SDL_RenderCopy(Renderer,image3,NULL,&image3Rect);

    SDL_Texture* image4= IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/themes.png");

    SDL_Rect image4Rect;
    image4Rect.x=600;
    image4Rect.y=500;
    image4Rect.w=250;
    image4Rect.h=80;
    SDL_RenderCopy(Renderer,image4,NULL,&image4Rect);

    SDL_Texture* image5= IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/BACK.png");

    SDL_Rect image5Rect;
    image5Rect.x=100;
    image5Rect.y=650;
    image5Rect.w=100;
    image5Rect.h=50;
    SDL_RenderCopy(Renderer,image5,NULL,&image5Rect);

    SDL_RenderPresent(Renderer);



}

void fmusic(SDL_Renderer *Renderer){

    SDL_Texture* image= IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/bspace.jpg");

    SDL_Rect imageRect;
    imageRect.x=0;
    imageRect.y=0;
    imageRect.w=1400;
    imageRect.h=800;
    SDL_RenderCopy(Renderer,image,NULL,&imageRect);

    SDL_Texture* image1= IMG_LoadTexture(Renderer,R"(C:\Users\HP\CLionProjects\untitled6\vx.png)");

    SDL_Rect image1Rect;
    image1Rect.x=300;
    image1Rect.y=300;
    image1Rect.w=200;
    image1Rect.h=200;
    SDL_RenderCopy(Renderer,image1,NULL,&image1Rect);

    SDL_Texture* image2= IMG_LoadTexture(Renderer,R"(C:\Users\HP\CLionProjects\untitled6\v+.png)");

    SDL_Rect image2Rect;
    image2Rect.x=600;
    image2Rect.y=300;
    image2Rect.w=200;
    image2Rect.h=200;
    SDL_RenderCopy(Renderer,image2,NULL,&image2Rect);

    SDL_Texture* image3= IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/v-.png");

    SDL_Rect image3Rect;
    image3Rect.x=900;
    image3Rect.y=300;
    image3Rect.w=200;
    image3Rect.h=200;
    SDL_RenderCopy(Renderer,image3,NULL,&image3Rect);

    SDL_Texture* image4= IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/BACK.png");

    SDL_Rect image4Rect;
    image4Rect.x=100;
    image4Rect.y=650;
    image4Rect.w=100;
    image4Rect.h=50;
    SDL_RenderCopy(Renderer,image4,NULL,&image4Rect);


    SDL_Texture* image5= IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/untitled1.png");

    SDL_Rect image5Rect;
    image5Rect.x=400;
    image5Rect.y=600;
    image5Rect.w=200;
    image5Rect.h=200;
    SDL_RenderCopy(Renderer,image5,NULL,&image5Rect);


    SDL_Texture* image6= IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/untitled2.png");

    SDL_Rect image6Rect;
    image6Rect.x=700;
    image6Rect.y=600;
    image6Rect.w=200;
    image6Rect.h=200;
    SDL_RenderCopy(Renderer,image6,NULL,&image6Rect);


    SDL_RenderPresent(Renderer);

}

void theme(SDL_Renderer *Renderer){

    SDL_Texture* image= IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/bspace.jpg");

    SDL_Rect imageRect;
    imageRect.x=0;
    imageRect.y=0;
    imageRect.w=1400;
    imageRect.h=800;
    SDL_RenderCopy(Renderer,image,NULL,&imageRect);

    SDL_Texture* image1= IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/FIRE.png");

    SDL_Rect image1Rect;
    image1Rect.x=200;
    image1Rect.y=200;
    image1Rect.w=400;
    image1Rect.h=400;
    SDL_RenderCopy(Renderer,image1,NULL,&image1Rect);

    SDL_Texture* image2= IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/SEA.png");

    SDL_Rect image2Rect;
    image2Rect.x=800;
    image2Rect.y=200;
    image2Rect.w=400;
    image2Rect.h=400;
    SDL_RenderCopy(Renderer,image2,NULL,&image2Rect);


    SDL_Texture* image4= IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/BACK.png");

    SDL_Rect image4Rect;
    image4Rect.x=100;
    image4Rect.y=650;
    image4Rect.w=100;
    image4Rect.h=50;
    SDL_RenderCopy(Renderer,image4,NULL,&image4Rect);



    SDL_RenderPresent(Renderer);

}

