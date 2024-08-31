#include <iostream>
#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <cstdlib>
using namespace std;
void menu(SDL_Renderer *Renderer);
void filledrect(SDL_Renderer *Renderer, int x,int y, int w, int h , int R, int G, int B, int fill_boolian);
void mode(SDL_Renderer *Renderer);
void setting(SDL_Renderer *Renderer);
void fmusic(SDL_Renderer *Renderer);
void theme(SDL_Renderer *Renderer);


int x=0;
int y=128;
int z=255;

int main(int argc,char*argv[]){


    Uint32 SDL_flags=SDL_INIT_VIDEO | SDL_INIT_TIMER |SDL_INIT_AUDIO| IMG_INIT_JPG|IMG_INIT_PNG;
    Uint32 WND_flags=SDL_WINDOW_SHOWN;
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
    SDL_Init(SDL_flags);
    SDL_CreateWindowAndRenderer(1400,800,WND_flags,&m_window,&m_renderer);
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,1,1024);

    Mix_Music *bgmusic1= Mix_LoadMUS("C:/Users/Saba/Desktop/project/bgmusic.mp3");
    Mix_Music *bgmusic2 = Mix_LoadMUS("C:/Users/Saba/Desktop/project/bitch.mp3");
    string username="";
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
    int mx;
    int my;
    SDL_Event e;
    Mix_PlayMusic(bgmusic1,-1);
    while(!quit) {
        SDL_RenderClear(m_renderer);
        while (SDL_PollEvent(&e) != 0) {
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
                            SDL_GetMouseState(&mx, &my);
                            if(mx>=100 && mx<=200 && my>=700 && my<=750){
                                rmode = false;
                                mx=0;
                                my=0;
                            }
                        }
                        if (e.type == SDL_QUIT) {
                            quit = true;
                            rmode = false;
                        }
                        mode(m_renderer);
                        if (mx >= 500 && mx <= 900 && my >= 50 && my <= 150){
                            x=255;
                            y=0;
                            z=0;
                            if(e.type==SDL_TEXTINPUT){
                                username += e.text.text;
                            }

                            if(e.type ==SDL_KEYDOWN && e.key.keysym.sym== SDLK_RETURN){
                                ofstream file("username.txt",ios::app);
                                if(file.is_open()){
                                    file<<username<<endl;
                                    file.close();
                                    username="";
                                    x=0;
                                    y=128;
                                    z=255;

                                }
                            }

                        }

                    }
                    if (mx >= 500 && mx <= 900 && my >= 200 && my <= 300) {
                        std::cout << "1";
                        mode1 = true;
                    }if (mx >= 500 && mx <= 900 && my >= 350 && my <= 450) {
                        std::cout << "2";
                        mode2 = true;
                    }if (mx >= 500 && mx <= 900 && my >= 500 && my <= 650) {
                        std::cout << "3";
                        mode3 = true;
                        if (mx >= 500 && mx <= 900 && my >= 500 && my <= 650){
                            std::cout << "4";
                            mode4 = true;
                        }

                    }
                }

            }if (mx >= 600 && mx <= 800 && my >= 300 && my <= 400) {
                std::cout << "setting";
                setting1 = true;
                while (setting1) {
                    while (SDL_PollEvent(&e) != 0) {
                        if (e.type == SDL_MOUSEBUTTONDOWN) {
                            SDL_GetMouseState(&mx, &my);
                            if(mx>=100 && mx<=200 && my>=700 && my<=750){
                                setting1 = false;
                                mx=0;
                                my=0;
                            }
                        }
                        if (e.type == SDL_QUIT) {
                            quit = true;
                            setting1 = false;
                        }
                        setting(m_renderer);
                        if (mx >= 600 && mx <= 850 && my >= 200 && my <= 280) {
                            soundeffect = true;
                        }
                        if (mx >= 600 && mx <= 850 && my >= 350 && my <= 430) {
                            cout<<"music";
                            music = true;
                            while(music) {
                                while (SDL_PollEvent(&e) != 0) {
                                    if (e.type == SDL_MOUSEBUTTONDOWN) {
                                        SDL_GetMouseState(&mx, &my);
                                        if (mx >= 100 && mx <= 200 && my >= 700 && my <= 750) {
                                            music = false;
                                            mx = 0;
                                            my = 0;
                                        }
                                    }
                                    if (e.type == SDL_QUIT) {
                                        quit = true;
                                        music = false;
                                        setting1 = false;
                                    }
                                    Mix_VolumeMusic(v);

                                    if (mx >= 300 && mx <= 500 && my >= 300 && my <= 500) {
                                        v = 0;
                                    }
                                    if (mx >= 600 && mx <= 800 && my >= 300 && my <= 500 && v <= 128) {
                                        v += 10;
                                        Mix_VolumeMusic(v);
                                    }
                                    if (mx >= 900 && mx <= 1100 && my >= 300 && my <= 500 && v >= 0) {
                                        v -= 10;
                                        Mix_VolumeMusic(v);
                                    }
                                    fmusic(m_renderer);
                                }
                                if (mx >= 400 && mx <= 600 && my >= 550 && my <= 750) {
                                    Mix_HaltMusic();
                                    Mix_PlayMusic(bgmusic1, -1);
                                    my = 0;
                                    mx = 0;
                                }
                                if (mx >= 700 && mx <= 900 && my >= 550 && my <= 750) {
                                    Mix_HaltMusic();
                                    Mix_PlayMusic(bgmusic2, -1);
                                    my = 0;
                                    mx = 0;

                                }
                            }
                        }
                        else if (mx >= 600 && mx <= 850 && my >= 500 && my <= 580) {
                            themes = true;
                            while (themes){
                                while (SDL_PollEvent(&e) != 0) {
                                    if (e.type == SDL_MOUSEBUTTONDOWN) {
                                        SDL_GetMouseState(&mx, &my);
                                        if(mx>=100 && mx<=200 && my>=700 && my<=750){
                                            themes = false;
                                            mx=0;
                                            my=0;
                                        }
                                    }
                                    if (e.type == SDL_QUIT) {
                                        quit = true;
                                        themes = false;
                                        setting1 = false;
                                    }if(mx>=100 && mx<=200 && my>=650 && my<=700){
                                        themes = false;
                                        mx=0;
                                        my=0;
                                    }
                                    theme(m_renderer);
                                }

                            }
                        }
                    }
                }

            }

            if (mx>=600 && mx<=800 && my>=450 && my<=550){
                std::cout<<"scores";
                //score va esm bazikona
            }
            if (mx>=600 && mx<=800 && my>=600 && my<=700){
                std::cout<<"exit";
                //exit
            }

        }

        menu(m_renderer);
        SDL_Delay(5);

    }

    Mix_FreeMusic(bgmusic1);
    Mix_FreeMusic(bgmusic2);
    Mix_CloseAudio();

}

void menu(SDL_Renderer *Renderer){
    SDL_Texture* image= IMG_LoadTexture(Renderer,"C:/Users/Saba/Desktop/project/bgm.png");

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
    TTF_Font* font= TTF_OpenFont("C:/Users/Saba/Desktop/project/font.otf",60);
    TTF_Font* font2= TTF_OpenFont("C:/Users/Saba/Desktop/project/font.otf",30);
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

    SDL_DestroyTexture(image);
    TTF_CloseFont(font);
    TTF_CloseFont(font2);

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

    SDL_Texture* image= IMG_LoadTexture(Renderer,"C:/Users/Saba/Desktop/project/bgmode.jpg");
    SDL_Rect imageRect;
    imageRect.x=0;
    imageRect.y=0;
    imageRect.w=1400;
    imageRect.h=800;

    SDL_RenderCopy(Renderer,image,NULL,&imageRect);
    filledrect(Renderer,500,50,400,100,x,y,z,1);
    filledrect(Renderer,500,200,400,100,0,128,255,1);
    filledrect(Renderer,500,350,400,100,0,128,255,1);
    filledrect(Renderer,500,500,400,100,0,128,255,1);
    filledrect(Renderer,500,650,400,100,0,128,255,1);

    TTF_Font* font= TTF_OpenFont("C:/Users/Saba/Desktop/project/font.otf",40);
    SDL_Color textColor = {255,255,255,255};

    SDL_Surface* textSurface5 = TTF_RenderText_Solid(font,"USERNAME",textColor);
    SDL_Texture* textTexture5 = SDL_CreateTextureFromSurface(Renderer,textSurface5);
    SDL_Rect textRect5 = {565,80,textSurface5->w,textSurface5->h};
    SDL_RenderCopy(Renderer,textTexture5,NULL,&textRect5);

    SDL_Surface* textSurface = TTF_RenderText_Solid(font,"NORMAL MODE",textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(Renderer,textSurface);
    SDL_Rect textRect = {550,230,textSurface->w,textSurface->h};
    SDL_RenderCopy(Renderer,textTexture,NULL,&textRect);


    SDL_Surface* textSurface2 = TTF_RenderText_Solid(font,"TIMER MODE",textColor);
    SDL_Texture* textTexture2 = SDL_CreateTextureFromSurface(Renderer,textSurface2);
    SDL_Rect textRect2 = {550,380,textSurface2->w,textSurface2->h};
    SDL_RenderCopy(Renderer,textTexture2,NULL,&textRect2);

    SDL_Surface* textSurface3 = TTF_RenderText_Solid(font,"RANDOM MODE",textColor);
    SDL_Texture* textTexture3= SDL_CreateTextureFromSurface(Renderer,textSurface3);
    SDL_Rect textRect3 = {550,530,textSurface3->w,textSurface3->h};
    SDL_RenderCopy(Renderer,textTexture3,NULL,&textRect3);

    SDL_Surface* textSurface4 = TTF_RenderText_Solid(font,"INFINITE MODE",textColor);
    SDL_Texture* textTexture4= SDL_CreateTextureFromSurface(Renderer,textSurface4);
    SDL_Rect textRect4= {550,680,textSurface4->w,textSurface4->h};
    SDL_RenderCopy(Renderer,textTexture4,NULL,&textRect4);

    SDL_Texture* image4 = IMG_LoadTexture(Renderer,"C:/Users/Saba/Desktop/project/BACK.png");
    SDL_Rect image4Rect;
    image4Rect.x=100;
    image4Rect.y=650;
    image4Rect.w=100;
    image4Rect.h=50;
    SDL_RenderCopy(Renderer,image4,NULL,&image4Rect);

    SDL_RenderPresent(Renderer);

}

void setting(SDL_Renderer *Renderer){

    SDL_Texture* image= IMG_LoadTexture(Renderer,"C:/Users/Saba/Desktop/project/bspace.jpg");

    SDL_Rect imageRect;
    imageRect.x=0;
    imageRect.y=0;
    imageRect.w=1400;
    imageRect.h=800;

    SDL_RenderCopy(Renderer,image,NULL,&imageRect);
    SDL_Texture* image2= IMG_LoadTexture(Renderer,"C:/Users/Saba/Desktop/project/sf.png");

    SDL_Rect image2Rect;
    image2Rect.x=600;
    image2Rect.y=200;
    image2Rect.w=250;
    image2Rect.h=80;
    SDL_RenderCopy(Renderer,image2,NULL,&image2Rect);

    SDL_Texture* image3= IMG_LoadTexture(Renderer,"C:/Users/Saba/Desktop/project/musics.png");

    SDL_Rect image3Rect;
    image3Rect.x=600;
    image3Rect.y=350;
    image3Rect.w=250;
    image3Rect.h=80;
    SDL_RenderCopy(Renderer,image3,NULL,&image3Rect);

    SDL_Texture* image4= IMG_LoadTexture(Renderer,"C:/Users/Saba/Desktop/project/themes.png");

    SDL_Rect image4Rect;
    image4Rect.x=600;
    image4Rect.y=500;
    image4Rect.w=250;
    image4Rect.h=80;
    SDL_RenderCopy(Renderer,image4,NULL,&image4Rect);

    SDL_Texture* image5 = IMG_LoadTexture(Renderer,"C:/Users/Saba/Desktop/project/BACK.png");
    SDL_Rect image5Rect;
    image5Rect.x=100;
    image5Rect.y=700;
    image5Rect.w=100;
    image5Rect.h=50;
    SDL_RenderCopy(Renderer,image5,NULL,&image5Rect);

    SDL_RenderPresent(Renderer);

}

void fmusic(SDL_Renderer *Renderer){

    SDL_Texture* image= IMG_LoadTexture(Renderer,"C:/Users/Saba/Desktop/project/bspace.jpg");

    SDL_Rect imageRect;
    imageRect.x=0;
    imageRect.y=0;
    imageRect.w=1400;
    imageRect.h=800;
    SDL_RenderCopy(Renderer,image,NULL,&imageRect);

    SDL_Texture* image1= IMG_LoadTexture(Renderer,"C:/Users/Saba/Desktop/project/vx.png");

    SDL_Rect image1Rect;
    image1Rect.x=300;
    image1Rect.y=300;
    image1Rect.w=200;
    image1Rect.h=200;
    SDL_RenderCopy(Renderer,image1,NULL,&image1Rect);

    SDL_Texture* image2= IMG_LoadTexture(Renderer,"C:/Users/Saba/Desktop/project/v+.png");

    SDL_Rect image2Rect;
    image2Rect.x=600;
    image2Rect.y=300;
    image2Rect.w=200;
    image2Rect.h=200;
    SDL_RenderCopy(Renderer,image2,NULL,&image2Rect);

    SDL_Texture* image3= IMG_LoadTexture(Renderer,"C:/Users/Saba/Desktop/project/v-.png");

    SDL_Rect image3Rect;
    image3Rect.x=900;
    image3Rect.y=300;
    image3Rect.w=200;
    image3Rect.h=200;
    SDL_RenderCopy(Renderer,image3,NULL,&image3Rect);

    SDL_Texture* image4 = IMG_LoadTexture(Renderer,"C:/Users/Saba/Desktop/project/BACK.png");
    SDL_Rect image4Rect;
    image4Rect.x=100;
    image4Rect.y=700;
    image4Rect.w=100;
    image4Rect.h=50;
    SDL_RenderCopy(Renderer,image4,NULL,&image4Rect);


    SDL_Texture* image5= IMG_LoadTexture(Renderer,"C:/Users/Saba/Desktop/project/untitled1.png");

    SDL_Rect image5Rect;
    image5Rect.x=400;
    image5Rect.y=550;
    image5Rect.w=200;
    image5Rect.h=200;
    SDL_RenderCopy(Renderer,image5,NULL,&image5Rect);


    SDL_Texture* image6= IMG_LoadTexture(Renderer,"C:/Users/Saba/Desktop/project/untitled2.png");

    SDL_Rect image6Rect;
    image6Rect.x=700;
    image6Rect.y=550;
    image6Rect.w=200;
    image6Rect.h=200;
    SDL_RenderCopy(Renderer,image6,NULL,&image6Rect);



    SDL_RenderPresent(Renderer);
    SDL_DestroyTexture(image);
    SDL_DestroyTexture(image1);
    SDL_DestroyTexture(image2);
    SDL_DestroyTexture(image3);
    SDL_DestroyTexture(image4);

}

void theme(SDL_Renderer *Renderer){

    SDL_Texture* image= IMG_LoadTexture(Renderer,"C:/Users/Saba/Desktop/project/bspace.jpg");

    SDL_Rect imageRect;
    imageRect.x=0;
    imageRect.y=0;
    imageRect.w=1400;
    imageRect.h=800;
    SDL_RenderCopy(Renderer,image,NULL,&imageRect);

    SDL_Texture* image1= IMG_LoadTexture(Renderer,"C:/Users/Saba/Desktop/project/FIRE.png");

    SDL_Rect image1Rect;
    image1Rect.x=200;
    image1Rect.y=200;
    image1Rect.w=400;
    image1Rect.h=400;
    SDL_RenderCopy(Renderer,image1,NULL,&image1Rect);

    SDL_Texture* image2= IMG_LoadTexture(Renderer,"C:/Users/Saba/Desktop/project/SEA.png");

    SDL_Rect image2Rect;
    image2Rect.x=800;
    image2Rect.y=200;
    image2Rect.w=400;
    image2Rect.h=400;
    SDL_RenderCopy(Renderer,image2,NULL,&image2Rect);

    SDL_Texture* image3 = IMG_LoadTexture(Renderer,"C:/Users/Saba/Desktop/project/BACK.png");
    SDL_Rect image3Rect;
    image3Rect.x=100;
    image3Rect.y=700;
    image3Rect.w=100;
    image3Rect.h=50;
    SDL_RenderCopy(Renderer,image3,NULL,&image3Rect);

    SDL_RenderPresent(Renderer);
}