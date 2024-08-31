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
#include <vector>
#include <sstream>
using namespace std;
struct Laser{
    double x,y;
    double dx,dy;
};
void menu(SDL_Renderer *Renderer);
void filledrect(SDL_Renderer *Renderer, int x,int y, int w, int h , int R, int G, int B, int fill_boolian);
void mode(SDL_Renderer *Renderer);
void setting(SDL_Renderer *Renderer);
void fmusic(SDL_Renderer *Renderer);
void theme(SDL_Renderer *Renderer);
void draw_circle(SDL_Renderer *Renderer);
void random(int &r,int &g,int &b);
void saftoop(SDL_Renderer *Renderer);
void randomt(int &r,int &g,int &b);
void saftoopt(SDL_Renderer *Renderer);
double shib(double mx, double my);
double dis(double x1,double y1,double x2,double y2);
struct Ball {
    double x;
    double y;
    double rr;
    int r;
    int g;
    int b;
    int a;
};
void game_1(SDL_Renderer *Renderer,double mx,double my, Laser &laser, int k, Ball ghofl, Ball lasert, Ball color);

int p=0;
int q=0;
int w=0;
int ur=60;
int ug=179;
int ub=113;
int r1=60;
int g1=179;
int b1=113;

int r2=60;
int g2=179;
int b2=113;
int use=0;
int pc=-1;
int pt=0;
int sc=-1;
int st=0;

struct user{
    string name;
    int scores;
    int scorestimer;
};
bool connected(Ball ball1, Ball ball2);
bool samecolor(Ball ball1, Ball ball2);
int memtiaz(int a, int b);
void scores(SDL_Renderer* m_renderer);

void laserPath(SDL_Renderer *Renderer,Laser &laser,int mx,int my,vector <Ball> stoop,int k);
void flaser(int i);







vector <Ball> balls;
vector <Ball> stoop;
vector <user> users;
vector<user> userss;
vector<Ball> removes;
vector<Ball> removed;
Ball bbal;

void fse(SDL_Renderer *Renderer);

void draw(SDL_Renderer* m_renderer, SDL_Texture* m_img, SDL_Rect img_rect,int x,int y, int w,int h);
void draw_canon(SDL_Renderer* m_renderer, SDL_Texture* m_img, SDL_Rect img_rect,int x,int y, int w,int h,int mx, int my);
void result(SDL_Renderer* m_renderer);
void remove(int i);
void r(int i);
void fr(int i);
int finduser(string esm);
void pauseMenu(SDL_Renderer* m_renderer);
void resultt(SDL_Renderer* m_renderer);
void gh(Ball ghofl, int k, double mx,double my,double s);
void random2(int &r,int &g,int &b);
int x=0;
int y=128;
int z=255;
bool lost=false;
int emtiaz1=0;
int emtiaz2=0;
int b=0;
int t=0;
int rr1=255;
int bb1=255;
int rr2=255;
int bb2=255;
string usernameg="";
SDL_Renderer * m_renderer;

SDL_Rect image_rect;
SDL_Texture* image_img= NULL;

SDL_Rect imagee_rect;
SDL_Texture* imagee_img= NULL;


SDL_Rect image1_rect;
SDL_Texture* image1_img= NULL;

SDL_Rect image2_rect;
SDL_Texture* image2_img= NULL;


SDL_Rect image3_rect;
SDL_Texture* image3_img= NULL;

SDL_Rect image4_rect;
SDL_Texture* image4_img= NULL;

SDL_Rect image5_rect;
SDL_Texture* image5_img= NULL;

SDL_Rect image6_rect;
SDL_Texture* image6_img= NULL;

SDL_Rect image7_rect;
SDL_Texture* image7_img= NULL;

SDL_Rect image16_rect;
SDL_Texture* image16_img= NULL;

SDL_Rect image13_rect;
SDL_Texture* image13_img= NULL;

Mix_Chunk *collision= NULL;

Mix_Chunk *ex= NULL;


SDL_Rect image17_rect;
SDL_Texture* image17_img= NULL;

SDL_Rect image23_rect;
SDL_Texture* image23_img= NULL;

SDL_Rect image24_rect;
SDL_Texture* image24_img= NULL;

SDL_Rect image25_rect;
SDL_Texture* image25_img= NULL;

SDL_Rect image26_rect;
SDL_Texture* image26_img= NULL;


Uint32 startTime=SDL_GetTicks();
Uint32 initialTime=120*1000;
Uint32 elapsedTime=0;
Uint32 remainingTime = (initialTime>elapsedTime)? (initialTime - elapsedTime): 0;
void game_1t(SDL_Renderer *Renderer,double mx,double my, Laser &laser, int k);
bool fire=true;
bool sea=false;
bool win=false;
bool shotsound=false;
bool slowmotion=false;
bool pause=false;
bool sf1=true;
bool sf2=false;
bool pausemotion=false;
bool ghofll=false;
bool colorr=false;
bool laserr=false;
bool shooting = false;
bool touched = false;
int u=0;



int main(int argc,char*argv[]){
    Ball ghofl;
    Ball color;
    Ball lasert;

    ghofl.x=1050;
    ghofl.y=700;
    ghofl.rr=50.0;

    color.x=1150;
    color.y=700;
    color.rr=50.0;

    lasert.x=1250;
    lasert.y=700;

    bbal.y=900;
    bbal.x=1500;
    users.empty();
    ifstream f("username.txt");
    if(f.is_open()){
        string line;
        while(getline(f,line)){
            istringstream iss(line);
            user userdata;
            if(iss>> userdata.name>>userdata.scores>>userdata.scorestimer){
                users.push_back(userdata);
            }
        }
    }


    int k=0;
    int count = 54;
    Uint32 SDL_flags=SDL_INIT_VIDEO | SDL_INIT_TIMER |SDL_INIT_AUDIO| IMG_INIT_JPG|IMG_INIT_PNG;
    Uint32 WND_flags=SDL_WINDOW_SHOWN;
    Uint32 prevTicks=SDL_GetTicks();
    SDL_Window * m_window;

    SDL_Init(SDL_flags);
    SDL_CreateWindowAndRenderer(1400,800,WND_flags,&m_window,&m_renderer);
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,1,1024);
    Mix_Music *bgmusic1= Mix_LoadMUS(R"(C:\Users\HP\CLionProjects\untitled6\bgmusic.mp3)");
    Mix_Music *bgmusic2 = Mix_LoadMUS(R"(C:\Users\HP\CLionProjects\untitled6\b.mp3)");
    collision= Mix_LoadWAV(R"(C:\Users\HP\CLionProjects\untitled6\zarbe.wav)");
    ex= Mix_LoadWAV(R"(C:\Users\HP\CLionProjects\untitled6\ex.wav)");
    image_img= IMG_LoadTexture(m_renderer,"C:/Users/HP/CLionProjects/untitled6/firebg.png");
    imagee_img= IMG_LoadTexture(m_renderer,"C:/Users/HP/CLionProjects/untitled6/seabg.jpg");
    image1_img= IMG_LoadTexture(m_renderer,"C:/Users/HP/CLionProjects/untitled6/canon.png");
    image2_img= IMG_LoadTexture(m_renderer,"C:/Users/HP/CLionProjects/untitled6/go.png");
    image3_img= IMG_LoadTexture(m_renderer,"C:/Users/HP/CLionProjects/untitled6/coin.png");
    image4_img= IMG_LoadTexture(m_renderer,"C:/Users/HP/CLionProjects/untitled6/wi.png");
    image5_img= IMG_LoadTexture(m_renderer,"C:/Users/HP/CLionProjects/untitled6/EXIT.png");
    image6_img= IMG_LoadTexture(m_renderer,"C:/Users/HP/CLionProjects/untitled6/music.png");
    image7_img= IMG_LoadTexture(m_renderer,"C:/Users/HP/CLionProjects/untitled6/resume.png");
    image16_img= IMG_LoadTexture(m_renderer,"C:/Users/HP/CLionProjects/untitled6/slowmotion.png");
    image13_img= IMG_LoadTexture(m_renderer,"C:/Users/HP/CLionProjects/untitled6/RETURN.png");
    image17_img= IMG_LoadTexture(m_renderer,"C:/Users/HP/CLionProjects/untitled6/soundeffect.png");
    image23_img= IMG_LoadTexture(m_renderer,"C:/Users/HP/CLionProjects/untitled6/exp.png");
    image24_img= IMG_LoadTexture(m_renderer,"C:/Users/HP/CLionProjects/untitled6/color.jpg");
    image25_img= IMG_LoadTexture(m_renderer,"C:/Users/HP/CLionProjects/untitled6/laser.jpg");
    image26_img= IMG_LoadTexture(m_renderer,"C:/Users/HP/CLionProjects/untitled6/BACK.png");
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
    bool color_change = false;
    bool score=false;
    bool ex1 = false;
    int mx;
    int my;
    SDL_Event e;
    Mix_PlayMusic(bgmusic1,-1);
    draw_circle(m_renderer);
    saftoop(m_renderer);
    while(!quit) {
        Uint32 currentTicks=SDL_GetTicks();
        Uint32 delaTime=currentTicks - prevTicks;
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
                                mode1=mode2=mode3=mode4=false;
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
                            user player;
                            x=255;
                            y=0;
                            z=0;
                            if(e.type==SDL_TEXTINPUT){
                                username += e.text.text;
                            }

                            if(e.type ==SDL_KEYDOWN && e.key.keysym.sym== SDLK_RETURN){
                                player.name=username;
                                player.scores=0;
                                player.scorestimer=0;
                                users.push_back(player);
                                username="";
                                x=0;
                                y=128;
                                z=255;
                                mx=my=0;
                            }

                        }

                    }
                    if (mx >= 500 && mx <= 900 && my >= 200 && my <= 300) {
                        my=mx=0;
                        mode1 = true;
                        while (mode1) {
                            SDL_PollEvent(&e);
                            SDL_GetMouseState(&mx, &my);
                            if (e.type == SDL_QUIT) {
                                quit = true;
                                rmode = false;
                                mode1 = false;
                            }
                            Laser laser;
                            game_1(m_renderer, mx, my,laser,k-1,ghofl,lasert,color);
                            if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
                                SDL_GetMouseState(&mx, &my);
                                Mix_PlayChannel(-1,collision,0);
                                shotsound=true;
                                if(shotsound && Mix_Playing(-1)==0){
                                    shotsound=false;
                                    Mix_FreeChunk(collision);
                                }

                                double s = shib(mx, my);

                                if(my<=640){
                                    shooting = true;
                                    touched = false;
                                    if (shooting) {
                                        removes.empty();
                                        while (!touched) {
                                            if(mx>=700){
                                                if(stoop[k].x<1350){
                                                    stoop[k].x+=2;
                                                } else{
                                                    stoop[k].x-=2;
                                                }
                                            }
                                            if(mx<700){
                                                if(stoop[k].x>50){
                                                    stoop[k].x-=2;
                                                } else{
                                                    stoop[k].x+=2;
                                                }
                                            }
                                            if(stoop[k].y>50){
                                                stoop[k].y -= (2*s);
                                            }
                                            else{
                                                stoop[k].y += (2*s);
                                            }
                                            for (int i = 0; i < balls.size(); i++) {
                                                if (dis(stoop[k].x,stoop[k].y,balls[i].x,balls[i].y) <= 100 && balls[i].a==255) {
                                                    if((i>=0 && i<=13) || (i>=27 && i<=40) || (i>=54 && i<=67) || (i>=81 && i<=94) ){
                                                        balls[i+13].r=stoop[k].r;
                                                        balls[i+13].g=stoop[k].g;
                                                        balls[i+13].b=stoop[k].b;
                                                        balls[i+13].a=255;
                                                        q=0;
                                                        removes.empty();
                                                        removed.empty();
                                                        if(stoop[k].r=255 && stoop[k].g==255 && stoop[k].b==255){
                                                            colorr=true;
                                                            color.x=stoop[k].x;
                                                            color.y=stoop[k].y;
                                                            r(i);
                                                            ex1 = true;
                                                            if(ex1) {
                                                                Mix_PlayChannel(-1,ex,0);
                                                                if(ex1 && Mix_Playing(-1)==0){
                                                                    ex1=false;
                                                                    Mix_FreeChunk(ex);
                                                                }
                                                                for (double j = 1; j <= 5; j += 0.1) {
                                                                    color.rr = j * 50;
                                                                }
                                                            }
                                                        }
                                                        else if(stoop[k].r=255 && stoop[k].g==0 && stoop[k].b==0){
                                                            ghofll=true;
                                                            ghofl.x=stoop[k].x;
                                                            ghofl.y=stoop[k].y;
                                                            if(i-1>0){
                                                                balls[i-1].a=0;
                                                            }
                                                            if(i+1>0){
                                                                balls[i+1].a=0;
                                                            }
                                                            if(i+13>0){
                                                                balls[i+13].a=0;
                                                            }
                                                            if(i+14>0){
                                                                balls[i+14].a=0;
                                                            }
                                                            if(i-13>0){
                                                                balls[i-13].a=0;
                                                            }
                                                            if(i-14>0){
                                                                balls[i-14].a=0;
                                                            }
                                                            ex1 = true;
                                                            if(ex1) {
                                                                Mix_PlayChannel(-1,ex,0);
                                                                if(ex1 && Mix_Playing(-1)==0){
                                                                    ex1=false;
                                                                    Mix_FreeChunk(ex);
                                                                }
                                                                for (double j = 1; j <= 5; j += 0.1) {
                                                                    ghofl.rr = j * 50;
                                                                }
                                                            }
                                                        }else{
                                                            r(i+13);
                                                        }
                                                    }
                                                    else if((i>=14 && i<=26) || (i>=41 && i<=53) || (i>=68 && i<=80) || (i>=95 && i<=107)){
                                                        balls[i+14].r=stoop[k].r;
                                                        balls[i+14].g=stoop[k].g;
                                                        balls[i+14].b=stoop[k].b;
                                                        balls[i+14].a=255;
                                                        q=0;
                                                        removes.empty();
                                                        removed.empty();
                                                        if(stoop[k].r=255 && stoop[k].g==255 && stoop[k].b==255){
                                                            colorr=true;
                                                            color.x=stoop[k].x;
                                                            color.y=stoop[k].y;
                                                            r(i);
                                                            ex1 = true;
                                                            if(ex1) {
                                                                Mix_PlayChannel(-1,ex,0);
                                                                if(ex1 && Mix_Playing(-1)==0){
                                                                    ex1=false;
                                                                    Mix_FreeChunk(ex);
                                                                }
                                                                for (double j = 1; j <= 5; j += 0.1) {
                                                                    color.rr = j * 50;
                                                                }
                                                            }
                                                        }
                                                        else if(stoop[k].r=255 && stoop[k].g==0 && stoop[k].b==0){
                                                            ghofll=true;
                                                            ghofl.x=stoop[k].x;
                                                            ghofl.y=stoop[k].y;
                                                            if(i-1>0){
                                                                balls[i-1].a=0;
                                                            }
                                                            if(i+1>0){
                                                                balls[i+1].a=0;
                                                            }
                                                            if(i+13>0){
                                                                balls[i+13].a=0;
                                                            }
                                                            if(i+14>0){
                                                                balls[i+14].a=0;
                                                            }
                                                            if(i-13>0){
                                                                balls[i-13].a=0;
                                                            }
                                                            if(i-14>0){
                                                                balls[i-14].a=0;
                                                            }
                                                            ex1 = true;
                                                            if(ex1) {
                                                                Mix_PlayChannel(-1,ex,0);
                                                                if(ex1 && Mix_Playing(-1)==0){
                                                                    ex1=false;
                                                                    Mix_FreeChunk(ex);
                                                                }
                                                                for (double j = 1; j <= 5; j += 0.1) {
                                                                    ghofl.rr = j * 50;
                                                                }
                                                            }
                                                        }

                                                        else{
                                                            r(i+14);
                                                        }




                                                    }
                                                    touched = true;
                                                    shooting = false;

                                                    k++;

                                                    count++;


                                                }
                                            }
                                        }
                                    }
                                }

                                if(my<=640 && ghofll){
                                    gh(ghofl,k,mx,my,s);
                                    SDL_RenderPresent(m_renderer);
                                }

                                if(mx>=1000 && mx<=1100 && my>=650 && my<=750){
                                    ghofll=true;
                                    stoop[k].a=0;
                                    filledCircleRGBA(m_renderer, stoop[k].x, stoop[k].y, 50, stoop[k].r, stoop[k].g, stoop[k].b,stoop[k].a);
                                    SDL_RenderPresent(m_renderer);
                                    ghofl.x=stoop[k].x;
                                    ghofl.y=stoop[k].y;

                                }

                                if(mx>=1100 && mx<=1200 && my>=650 && my<=750){
                                    colorr=true;
                                    stoop[k].a=0;
                                    filledCircleRGBA(m_renderer, stoop[k].x, stoop[k].y, 50, stoop[k].r, stoop[k].g, stoop[k].b,stoop[k].a);
                                    SDL_RenderPresent(m_renderer);
                                    color.x=stoop[k].x;
                                    color.y=stoop[k].y;

                                }

                                if(mx>=1200 && mx<=1300 && my>=650 && my<=750){
                                    laserr=true;
                                    stoop[k].a=0;
                                    filledCircleRGBA(m_renderer, stoop[k].x, stoop[k].y, 50, stoop[k].r, stoop[k].g, stoop[k].b,stoop[k].a);
                                    SDL_RenderPresent(m_renderer);
                                    lasert.x=stoop[k].x;
                                    lasert.y=stoop[k].y;

                                }


                            }




                            else{
                                for (int i = 0; i < balls.size(); i++) {
                                    filledCircleRGBA(m_renderer, balls[i].x, balls[i].y, 50, balls[i].r, balls[i].g,balls[i].b, balls[i].a);
                                }
                                for (int j = 1; j < removes.size(); j++) {
                                    filledCircleRGBA(m_renderer, removes[j].x, removes[j].y, 50, removes[j].r, removes[j].g,removes[j].b, 255);
                                }
                                filledCircleRGBA(m_renderer, stoop[k].x, stoop[k].y, 50, stoop[k].r, stoop[k].g, stoop[k].b,255);
                                filledCircleRGBA(m_renderer, 700, 775, 50, stoop[k+1].r, stoop[k+1].g,stoop[k+1].b, 255);
                                if(e.type ==SDL_KEYDOWN && e.key.keysym.sym== SDLK_SPACE){
                                    swap(stoop[k].r,stoop[k+1].r);
                                    swap(stoop[k].g,stoop[k+1].g);
                                    swap(stoop[k].b,stoop[k+1].b);


                                }
                                if(slowmotion && sc==0){
                                    for (int i = 0; i < balls.size(); ++i) {
                                        balls[i].y += 0.1;
                                    }
                                    u++;
                                    if(u>100){
                                        slowmotion=false;
                                    }
                                }
                                else if(pausemotion && pc==0){
                                    for (int i = 0; i < balls.size(); ++i) {
                                        balls[i].y += 0.0;
                                    }
                                    pt++;
                                    if(pt>100){
                                        pausemotion=false;
                                    }
                                }


                                else{
                                    for (int i = 0; i < balls.size(); ++i) {
                                        balls[i].y += 0.75;
                                    }
                                }
                                for (int j = 1; j < removes.size(); j++) {
                                    removes[j].y+=8.0;
                                    if(colorr){
                                        color.y+=8.0;
                                    }
                                    if(ghofll){
                                        ghofl.y+=8.0;
                                    }
                                }

                                for (int i = 0; i <balls.size() ; ++i) {
                                    if(balls[i].a==255){
                                        w++;
                                    }

                                }
                                if(w==0){
                                    win= true;
                                }
                                while (win){
                                    result(m_renderer);

                                }

                                for (int i = balls.size()-1; i >=0 ; --i) {
                                    fr(i);
                                }


                                if(e.type == SDL_KEYDOWN){
                                    if(e.key.keysym.sym == SDLK_ESCAPE){
                                        pause = true;
                                        mx=my=0;
                                        while (pause) {
                                            while (SDL_PollEvent(&e) != 0) {
                                                if (e.type == SDL_MOUSEBUTTONDOWN) {
                                                    SDL_GetMouseState(&mx, &my);
                                                }
                                                if (e.type == SDL_QUIT) {
                                                    quit = true;
                                                    pause = rmode = mode1 = false;
                                                }
                                                pauseMenu(m_renderer);
                                                if (mx >= 500 && mx <= 900 && my >= 100 && my <= 250) {
                                                    music = true;
                                                    while (music) {
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
                                                                mx = my = 0;
                                                            }
                                                            if (mx >= 600 && mx <= 800 && my >= 300 && my <= 500 &&
                                                                v <= 128) {
                                                                v += 10;
                                                                mx = my = 0;
                                                                Mix_VolumeMusic(v);
                                                            }
                                                            if (mx >= 900 && mx <= 1100 && my >= 300 && my <= 500 &&
                                                                v >= 0) {
                                                                v -= 10;
                                                                mx = my = 0;
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
                                                if(mx >= 500 && mx <= 900 && my >= 300 && my <= 450){
                                                    pause = false;
                                                    mx=my=0;
                                                }
                                                if(mx >= 500 && mx <= 900 && my >= 500 && my <= 650){
                                                    pause=mode1=rmode=false;
                                                    mx=my=0;
                                                }
                                                if(mx >= 200 && mx <= 350 && my >= 300 && my <= 450){
                                                    slowmotion = true;
                                                    sc++;
                                                    mx=my=0;
                                                    r1=250;
                                                    g1=0;
                                                    b1=0;
                                                    pause = false;
                                                }

                                                if(mx >= 200 && mx <= 350 && my >= 500 && my <= 650){
                                                    pausemotion = true;
                                                    pc++;
                                                    mx=my=0;
                                                    r2=250;
                                                    g2=0;
                                                    b2=0;
                                                    pause = false;
                                                }
                                                if(mx >= 500 && mx <= 900 && my >= 700 && my <= 800){
                                                    soundeffect = true;
                                                    while (soundeffect) {
                                                        while (SDL_PollEvent(&e) != 0) {
                                                            if (e.type == SDL_MOUSEBUTTONDOWN) {
                                                                SDL_GetMouseState(&mx, &my);
                                                                if (mx >= 100 && mx <= 200 && my >= 700 && my <= 750) {
                                                                    soundeffect = false;
                                                                    mx = 0;
                                                                    my = 0;
                                                                }
                                                            }
                                                            if (e.type == SDL_QUIT) {
                                                                quit = true;
                                                                music = false;
                                                                setting1 = false;
                                                            }
                                                            Mix_VolumeChunk(collision,v);
                                                            if (mx >= 300 && mx <= 500 && my >= 300 && my <= 500) {
                                                                v = 0;
                                                                mx = my = 0;
                                                            }
                                                            if (mx >= 600 && mx <= 800 && my >= 300 && my <= 500 && v <= 128) {
                                                                v += 10;
                                                                mx = my = 0;
                                                                Mix_VolumeChunk(collision,v);
                                                            }
                                                            if (mx >= 900 && mx <= 1100 && my >= 300 && my <= 500 && v >= 0) {
                                                                v -= 10;
                                                                mx = my = 0;
                                                                Mix_VolumeChunk(collision,v);
                                                            }
                                                            fse(m_renderer);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }

                                for (int j = balls.size()-1; j >=0 && !lost; --j ) {
                                    if(balls[j].y>=600 && balls[j].a==255){
                                        for (int i = 0; i <54 ; ++i) {
                                            if(balls[i].a==0){
                                                emtiaz2+=10;
                                            }

                                        }
                                        cout<<emtiaz2;
                                        SDL_Delay(25);
                                        lost=true;
                                        usernameg="";
                                        while(lost){

                                            result(m_renderer);
                                            int tcoin=emtiaz2/50;
                                            mx=my=0;
                                            if (e.type == SDL_MOUSEBUTTONDOWN){
                                                SDL_GetMouseState(&mx, &my);
                                                if(mx>=600 && mx<=800 && my >=500 && my<=700){
                                                    if(tcoin >0 && use<1){
                                                        use++;
                                                        lost=false;
                                                        tcoin=0;
                                                        emtiaz2=0;
                                                        for (int i = 0; i <balls.size() ; ++i) {
                                                            balls[i].y-=200.0;

                                                        }

                                                    }
                                                }

                                            }

                                            if (e.type == SDL_QUIT) {
                                                quit = true;
                                                rmode = false;
                                                mode1 = false;
                                                lost = false;
                                            }

                                            while (SDL_PollEvent(&e) != 0) {

                                                if (e.type == SDL_MOUSEBUTTONDOWN){
                                                    SDL_GetMouseState(&mx, &my);

                                                }
                                                if(mx>=200 && mx<=400 && my>=500 && my<=700){
                                                    balls.empty();
                                                    stoop.empty();
                                                    lost=mode1=rmode=false;
                                                    mx=my=0;
                                                }



                                                    if(mx>=550 && mx<=850 && my>=100 && my<=200){
                                                        ur=255;
                                                        ub=0;
                                                        ug=0;
                                                        if(e.type==SDL_TEXTINPUT){
                                                            usernameg += e.text.text;
                                                            if(e.type ==SDL_KEYDOWN && e.key.keysym.sym== SDLK_RETURN){
                                                                cout<<"m";
                                                                ur=60;
                                                                ug=179;
                                                                ub=113;
                                                                cout<<usernameg;
                                                                int l= finduser(usernameg);
                                                                users[l].scores= memtiaz(users[l].scores,emtiaz2);
                                                                ofstream file("username.txt", ios::trunc);
                                                                if(p<1){
                                                                    for (int i = 0; i <users.size(); ++i) {
                                                                        file<<users[i].name<<" "<<users[i].scores<<" "<<users[i].scorestimer<<endl;

                                                                    }
                                                                    p++;

                                                                }

                                                            }
                                                        }


                                                    }


                                            }





                                        }

                                    }

                                }
                            }
                            if(!ghofll && !colorr && !laserr){
                                filledCircleRGBA(m_renderer, stoop[k].x, stoop[k].y, 50, stoop[k].r, stoop[k].g, stoop[k].b,stoop[k].a);
                                filledCircleRGBA(m_renderer, 700, 775, 50, stoop[k+1].r, stoop[k+1].g,stoop[k+1].b, stoop[k+1].a);
                            }


                            draw(m_renderer,image23_img,image23_rect,ghofl.x-50,ghofl.y-50,2*ghofl.rr,2*ghofl.rr);
                            draw(m_renderer,image24_img,image24_rect,color.x-50,color.y-50,2*color.rr,2*color.rr);
                            draw(m_renderer,image25_img,image25_rect,lasert.x-50,lasert.y-50,100,100);

                            SDL_RenderPresent(m_renderer);
                            e.type = NULL;
                        }
                    }if (mx >= 500 && mx <= 900 && my >= 350 && my <= 450) {
                        mx=my=0;
                        mode2 = true;
                        while (mode2){

                            elapsedTime=SDL_GetTicks() - startTime;
                            remainingTime = (initialTime>elapsedTime)? (initialTime - elapsedTime): 0;
                            SDL_PollEvent(&e);
                            SDL_GetMouseState(&mx, &my);
                            if (e.type == SDL_QUIT) {
                                quit = true;
                                rmode = false;
                                mode2 = false;
                                score=false;
                                setting1=false;
                                mode1=false;
                            }
                            Laser laser;
                            game_1t(m_renderer, mx, my,laser,k-1);
                            filledCircleRGBA(m_renderer, stoop[k].x, stoop[k].y, 50, stoop[k].r, stoop[k].g, stoop[k].b,255);
                            filledCircleRGBA(m_renderer, 700, 775, 50, stoop[k+1].r, stoop[k+1].g,stoop[k+1].b, 255);
                            if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
                                SDL_GetMouseState(&mx, &my);
                                Mix_PlayChannel(-1,collision,0);
                                shotsound=true;
                                if(shotsound && Mix_Playing(-1)==0){
                                    shotsound=false;
                                    Mix_FreeChunk(collision);
                                }
                                double s = shib(mx, my);
                                shooting = true;
                                touched = false;
                                if (shooting) {
                                    removes.empty();
                                    while (!touched) {
                                        if(mx>=700){
                                            if(stoop[k].x<1350){
                                                stoop[k].x+=2;
                                            } else{
                                                stoop[k].x-=2;
                                            }
                                        }
                                        if(mx<700){
                                            if(stoop[k].x>50){
                                                stoop[k].x-=2;
                                            } else{
                                                stoop[k].x+=2;
                                            }
                                        }
                                        if(stoop[k].y>50){
                                            stoop[k].y -= (2*s);
                                        }
                                        else{
                                            stoop[k].y += (2*s);
                                        }
                                        for (int i = 0; i < balls.size(); i++) {
                                            if (dis(stoop[k].x,stoop[k].y,balls[i].x,balls[i].y) <= 100 && balls[i].a==255) {
                                                if((i>=0 && i<=13) || (i>=27 && i<=40) || (i>=54 && i<=67) || (i>=81 && i<=94) ){
                                                    balls[i+13].r=stoop[k].r;
                                                    balls[i+13].g=stoop[k].g;
                                                    balls[i+13].b=stoop[k].b;
                                                    balls[i+13].a=255;
                                                    q=0;
                                                    removes.empty();
                                                    removed.empty();

                                                    if(stoop[k].r=255 && stoop[k].g==255 && stoop[k].b==255){
                                                        colorr=true;
                                                        color.x=stoop[k].x;
                                                        color.y=stoop[k].y;
                                                        r(i);
                                                        ex1 = true;
                                                        if(ex1) {
                                                            Mix_PlayChannel(-1,ex,0);
                                                            if(ex1 && Mix_Playing(-1)==0){
                                                                ex1=false;
                                                                Mix_FreeChunk(ex);
                                                            }
                                                            for (double j = 1; j <= 5; j += 0.1) {
                                                                color.rr = j * 50;
                                                            }
                                                        }
                                                    }
                                                    else if(stoop[k].r=255 && stoop[k].g==0 && stoop[k].b==0){
                                                        ghofll=true;
                                                        ghofl.x=stoop[k].x;
                                                        ghofl.y=stoop[k].y;
                                                        if(i-1>0){
                                                            balls[i-1].a=0;
                                                        }
                                                        if(i+1>0){
                                                            balls[i+1].a=0;
                                                        }
                                                        if(i+13>0){
                                                            balls[i+13].a=0;
                                                        }
                                                        if(i+14>0){
                                                            balls[i+14].a=0;
                                                        }
                                                        if(i-13>0){
                                                            balls[i-13].a=0;
                                                        }
                                                        if(i-14>0){
                                                            balls[i-14].a=0;
                                                        }
                                                        ex1 = true;
                                                        if(ex1) {
                                                            Mix_PlayChannel(-1,ex,0);
                                                            if(ex1 && Mix_Playing(-1)==0){
                                                                ex1=false;
                                                                Mix_FreeChunk(ex);
                                                            }
                                                            for (double j = 1; j <= 5; j += 0.1) {
                                                                ghofl.rr = j * 50;
                                                            }
                                                        }
                                                    }else{
                                                        r(i+13);
                                                    }

                                                }
                                                else if((i>=14 && i<=26) || (i>=41 && i<=53) || (i>=68 && i<=80) || (i>=95 && i<=107)){
                                                    balls[i+14].r=stoop[k].r;
                                                    balls[i+14].g=stoop[k].g;
                                                    balls[i+14].b=stoop[k].b;
                                                    balls[i+14].a=255;
                                                    q=0;
                                                    removes.empty();
                                                    removed.empty();

                                                    if(stoop[k].r=255 && stoop[k].g==255 && stoop[k].b==255){
                                                        colorr=true;
                                                        color.x=stoop[k].x;
                                                        color.y=stoop[k].y;
                                                        r(i);
                                                        ex1 = true;
                                                        if(ex1) {
                                                            Mix_PlayChannel(-1,ex,0);
                                                            if(ex1 && Mix_Playing(-1)==0){
                                                                ex1=false;
                                                                Mix_FreeChunk(ex);
                                                            }
                                                            for (double j = 1; j <= 5; j += 0.1) {
                                                                color.rr = j * 50;
                                                            }
                                                        }
                                                    }
                                                    else if(stoop[k].r=255 && stoop[k].g==0 && stoop[k].b==0){
                                                        ghofll=true;
                                                        ghofl.x=stoop[k].x;
                                                        ghofl.y=stoop[k].y;
                                                        if(i-1>0){
                                                            balls[i-1].a=0;
                                                        }
                                                        if(i+1>0){
                                                            balls[i+1].a=0;
                                                        }
                                                        if(i+13>0){
                                                            balls[i+13].a=0;
                                                        }
                                                        if(i+14>0){
                                                            balls[i+14].a=0;
                                                        }
                                                        if(i-13>0){
                                                            balls[i-13].a=0;
                                                        }
                                                        if(i-14>0){
                                                            balls[i-14].a=0;
                                                        }
                                                        ex1 = true;
                                                        if(ex1) {
                                                            Mix_PlayChannel(-1,ex,0);
                                                            if(ex1 && Mix_Playing(-1)==0){
                                                                ex1=false;
                                                                Mix_FreeChunk(ex);
                                                            }
                                                            for (double j = 1; j <= 5; j += 0.1) {
                                                                ghofl.rr = j * 50;
                                                            }
                                                        }
                                                    }else{
                                                        r(i+14);
                                                    }



                                                }
                                                touched = true;
                                                shooting = false;

                                                k++;

                                                count++;


                                            }
                                        }
                                    }
                                }

                            }


                            else{
                                for (int i = 0; i < balls.size(); i++) {
                                    filledCircleRGBA(m_renderer, balls[i].x, balls[i].y, 50, balls[i].r, balls[i].g,balls[i].b, balls[i].a);
                                }
                                for (int j = 1; j < removes.size(); j++) {
                                    filledCircleRGBA(m_renderer, removes[j].x, removes[j].y, 50, removes[j].r, removes[j].g,removes[j].b, 255);
                                }
                                filledCircleRGBA(m_renderer, stoop[k].x, stoop[k].y, 50, stoop[k].r, stoop[k].g, stoop[k].b,255);
                                filledCircleRGBA(m_renderer, 700, 775, 50, stoop[k+1].r, stoop[k+1].g,stoop[k+1].b, 255);
                                if(e.type ==SDL_KEYDOWN && e.key.keysym.sym== SDLK_SPACE){
                                    swap(stoop[k].r,stoop[k+1].r);
                                    swap(stoop[k].g,stoop[k+1].g);
                                    swap(stoop[k].b,stoop[k+1].b);


                                }
                                if(slowmotion && sc==0){
                                    for (int i = 0; i < balls.size(); ++i) {
                                        balls[i].y += 0.2;
                                    }
                                    st++;
                                    if(st>100){
                                        slowmotion=false;
                                    }
                                }
                                else if(pausemotion && pc==0){
                                    for (int i = 0; i < balls.size(); ++i) {
                                        balls[i].y += 0.0;
                                    }
                                    pt++;
                                    if(pt>100){
                                        pausemotion=false;
                                    }
                                }


                                else{
                                    for (int i = 0; i < balls.size(); ++i) {
                                        balls[i].y += 0.8;
                                    }
                                }
                                for (int j = 1; j < removes.size(); j++) {
                                    removes[j].y+=8.0;
                                    if(colorr){
                                        color.y+=8.0;
                                    }
                                    if(ghofll){
                                        ghofl.y+=8.0;
                                    }
                                }

                                for (int i = balls.size()-1; i >=0 ; --i) {
                                    fr(i);
                                }


                                if(e.type == SDL_KEYDOWN){
                                    if(e.key.keysym.sym == SDLK_ESCAPE){
                                        pause = true;
                                        mx=my=0;
                                        while (pause) {
                                            while (SDL_PollEvent(&e) != 0) {
                                                if (e.type == SDL_MOUSEBUTTONDOWN) {
                                                    SDL_GetMouseState(&mx, &my);
                                                }
                                                if (e.type == SDL_QUIT) {
                                                    quit = true;
                                                    pause = rmode = mode2 = false;
                                                }
                                                pauseMenu(m_renderer);
                                                if (mx >= 500 && mx <= 900 && my >= 100 && my <= 250) {
                                                    music = true;
                                                    while (music) {
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
                                                                mx = my = 0;
                                                            }
                                                            if (mx >= 600 && mx <= 800 && my >= 300 && my <= 500 &&
                                                                v <= 128) {
                                                                v += 10;
                                                                mx = my = 0;
                                                                Mix_VolumeMusic(v);
                                                            }
                                                            if (mx >= 900 && mx <= 1100 && my >= 300 && my <= 500 &&
                                                                v >= 0) {
                                                                v -= 10;
                                                                mx = my = 0;
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
                                                if(mx >= 500 && mx <= 900 && my >= 300 && my <= 450){
                                                    pause = false;
                                                    mx=my=0;
                                                }
                                                if(mx >= 500 && mx <= 900 && my >= 500 && my <= 650){
                                                    pause=mode2=rmode=false;
                                                    mx=my=0;
                                                }
                                                if(mx >= 200 && mx <= 350 && my >= 300 && my <= 450){
                                                    slowmotion = true;
                                                    mx=my=0;
                                                    pause = false;
                                                }
                                                if(mx >= 200 && mx <= 350 && my >= 500 && my <= 650){
                                                    pausemotion = true;
                                                    pc++;
                                                    mx=my=0;
                                                    r2=250;
                                                    g2=0;
                                                    b2=0;
                                                    pause = false;
                                                }
                                                if(mx >= 500 && mx <= 900 && my >= 700 && my <= 800){
                                                    soundeffect = true;
                                                    while (soundeffect) {
                                                        while (SDL_PollEvent(&e) != 0) {
                                                            if (e.type == SDL_MOUSEBUTTONDOWN) {
                                                                SDL_GetMouseState(&mx, &my);
                                                                if (mx >= 100 && mx <= 200 && my >= 700 && my <= 750) {
                                                                    soundeffect = false;
                                                                    mx = 0;
                                                                    my = 0;
                                                                }
                                                            }
                                                            if (e.type == SDL_QUIT) {
                                                                quit = true;
                                                                music = false;
                                                                setting1 = false;
                                                            }
                                                            Mix_VolumeChunk(collision,v);
                                                            if (mx >= 300 && mx <= 500 && my >= 300 && my <= 500) {
                                                                v = 0;
                                                                mx = my = 0;
                                                            }
                                                            if (mx >= 600 && mx <= 800 && my >= 300 && my <= 500 && v <= 128) {
                                                                v += 10;
                                                                mx = my = 0;
                                                                Mix_VolumeChunk(collision,v);
                                                            }
                                                            if (mx >= 900 && mx <= 1100 && my >= 300 && my <= 500 && v >= 0) {
                                                                v -= 10;
                                                                mx = my = 0;
                                                                Mix_VolumeChunk(collision,v);
                                                            }
                                                            fse(m_renderer);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }


                                for (int j = balls.size()-1; j >=0 && !lost; --j ) {
                                    if(balls[j].y>=600 && balls[j].a==255){
                                        for (int i = 0; i <54 ; ++i) {
                                            if(balls[i].a==0){
                                                emtiaz1+=10;
                                            }

                                        }
                                        cout<<emtiaz1;
                                        SDL_Delay(25);
                                        lost=true;
                                        usernameg="";
                                        while(lost){
                                            resultt(m_renderer);
                                            if (e.type == SDL_QUIT) {
                                                quit = true;
                                                rmode = false;
                                                mode2 = false;
                                                lost = false;
                                            }

                                            while (SDL_PollEvent(&e) != 0) {

                                                if (e.type == SDL_MOUSEBUTTONDOWN){
                                                    SDL_GetMouseState(&mx, &my);
                                                    if(mx>=200 && mx<=400 && my>=500 && my<=700){
                                                        lost=mode2=rmode=false;
                                                        mx=my=0;
                                                    }

                                                }
                                            }


                                                if(mx>=550 && mx<=850 && my>=100 && my<=200){
                                                    ur=255;
                                                    ub=0;
                                                    ug=0;
                                                    while (SDL_PollEvent(&e)!=0){
                                                        if(e.type==SDL_TEXTINPUT){
                                                            cout<<"k";
                                                            usernameg += e.text.text;
                                                        }


                                                        if(e.type ==SDL_KEYDOWN && e.key.keysym.sym== SDLK_RETURN){
                                                            ur=60;
                                                            ug=179;
                                                            ub=113;
                                                            cout<<usernameg;
                                                            int l= finduser(usernameg);
                                                            users[l].scorestimer= memtiaz(users[l].scorestimer,emtiaz1);
                                                            ofstream file("username.txt", ios::trunc);

                                                            for (int i = 0; i <users.size(); ++i) {
                                                                file<<users[i].name<<" "<<users[i].scores<<" "<<users[i].scorestimer<<endl;
                                                            }

                                                        }
                                                    }
                                                }

                                        }

                                    }

                                }
                            }
                            draw(m_renderer,image23_img,image23_rect,ghofl.x-50,ghofl.y-50,2*ghofl.rr,2*ghofl.rr);
                            draw(m_renderer,image24_img,image24_rect,color.x-50,color.y-50,2*color.rr,2*color.rr);
                            draw(m_renderer,image25_img,image25_rect,lasert.x-50,lasert.y-50,100,100);

                            SDL_RenderPresent(m_renderer);
                            e.type = NULL;

                    }}if (mx >= 500 && mx <= 900 && my >= 500 && my <= 650) {
                        std::cout << "3";
                        mode3 = true;
                    }
                    if (mx >= 500 && mx <= 900 && my >= 500 && my <= 650){
                        std::cout << "4";
                        mode4 = true;
                    }
                }

            }if (mx >= 600 && mx <= 800 && my >= 300 && my <= 400) {
                std::cout << "setting";
                setting1 = true;
                mx=my=0;
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
                            while (soundeffect) {
                                while (SDL_PollEvent(&e) != 0) {
                                    if (e.type == SDL_MOUSEBUTTONDOWN) {
                                        SDL_GetMouseState(&mx, &my);
                                        if (mx >= 100 && mx <= 200 && my >= 700 && my <= 750) {
                                            soundeffect = false;
                                            mx = 0;
                                            my = 0;
                                        }
                                    }
                                    if (e.type == SDL_QUIT) {
                                        quit = true;
                                        music = false;
                                        setting1 = false;
                                    }

                                    Mix_VolumeChunk(collision,v);


                                    if (mx >= 300 && mx <= 500 && my >= 300 && my <= 500 ) {
                                        v = 0;
                                        mx = my = 0;
                                    }
                                    if (mx >= 600 && mx <= 800 && my >= 300 && my <= 500 && v <= 128 ) {
                                        v += 10;
                                        mx = my = 0;
                                        Mix_VolumeChunk(collision,v);
                                    }
                                    if (mx >= 900 && mx <= 1100 && my >= 300 && my <= 500 && v >= 0) {
                                        v -= 10;
                                        mx = my = 0;
                                        Mix_VolumeChunk(collision,v);
                                    }

                                    fse(m_renderer);
                                }
                            }
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
                                        mx=my=0;
                                    }
                                    if (mx >= 600 && mx <= 800 && my >= 300 && my <= 500 && v <= 128) {
                                        v += 10;
                                        mx=my=0;
                                        Mix_VolumeMusic(v);
                                    }
                                    if (mx >= 900 && mx <= 1100 && my >= 300 && my <= 500 && v >= 0) {
                                        v -= 10;
                                        mx=my=0;
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
                                    }if(mx>=100 && mx<=200 && my>=700 && my<=750){
                                        themes = false;
                                        mx=0;
                                        my=0;
                                    }if(mx>=200 && mx<=600 && my>=200 && my<=600){
                                        fire = true;
                                        sea=false;
                                        rr1=255;
                                        bb1=0;
                                        rr2=255;
                                        bb2=255;

                                    }else if (mx>=800 && mx<=1200 && my>=200 && my<=600){
                                        sea = true;
                                        fire= false;
                                        rr2=255;
                                        bb2=0;
                                        rr1=255;
                                        bb1=255;
                                    }
                                    theme(m_renderer);
                                }

                            }
                        }
                    }
                }

            }

            if (mx>=600 && mx<=800 && my>=450 && my<=550){
                score=true;
                while(score){
                    while (SDL_PollEvent(&e) != 0){
                        if(e.type==SDL_MOUSEBUTTONDOWN){
                            SDL_GetMouseState(&mx,&my);
                            if(mx>=100 && mx<=200 && my>=700 && my<=750){
                                score=false;
                                mx=my=0;
                            }
                        }
                        if (e.type == SDL_QUIT) {
                            quit = true;
                            setting1 = false;
                            score=false;
                        }
                        scores(m_renderer);

                    }
                }
            }
            if (mx>=600 && mx<=800 && my>=600 && my<=700){
                quit = true;
            }

        }

        menu(m_renderer);
        prevTicks=currentTicks;

    }

    Mix_FreeMusic(bgmusic1);
    Mix_FreeMusic(bgmusic2);
    Mix_CloseAudio();

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

    SDL_Texture* image= IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/bgmode.jpg");
    SDL_Rect imageRect;
    imageRect.x=0;
    imageRect.y=0;
    imageRect.w=1400;
    imageRect.h=800;

    SDL_RenderCopy(Renderer,image,NULL,&imageRect);
    filledrect(Renderer,500,50,400,100,x,y,z,1);
    filledrect(Renderer,500,200,400,100,0,128,255,1);
    filledrect(Renderer,500,350,400,100,0,128,255,1);


    TTF_Font* font= TTF_OpenFont("C:/Users/HP/CLionProjects/untitled6/font.otf",40);
    SDL_Color textColor = {255,255,255,255};

    SDL_Surface* textSurface5 = TTF_RenderText_Solid(font,"USERNAME",textColor);
    SDL_Texture* textTexture5 = SDL_CreateTextureFromSurface(Renderer,textSurface5);
    SDL_Rect textRect5 = {565,80,textSurface5->w,textSurface5->h};
    SDL_RenderCopy(Renderer,textTexture5,NULL,&textRect5);

    SDL_Surface* textSurface = TTF_RenderText_Solid(font,"RANDOM MODE",textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(Renderer,textSurface);
    SDL_Rect textRect = {550,230,textSurface->w,textSurface->h};
    SDL_RenderCopy(Renderer,textTexture,NULL,&textRect);


    SDL_Surface* textSurface2 = TTF_RenderText_Solid(font,"TIMER MODE",textColor);
    SDL_Texture* textTexture2 = SDL_CreateTextureFromSurface(Renderer,textSurface2);
    SDL_Rect textRect2 = {550,380,textSurface2->w,textSurface2->h};
    SDL_RenderCopy(Renderer,textTexture2,NULL,&textRect2);


    SDL_Texture* image4 = IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/BACK.png");
    SDL_Rect image4Rect;
    image4Rect.x=100;
    image4Rect.y=700;
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

    SDL_Texture* image5 = IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/BACK.png");
    SDL_Rect image5Rect;
    image5Rect.x=100;
    image5Rect.y=700;
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

    SDL_Texture* image4 = IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/BACK.png");
    SDL_Rect image4Rect;
    image4Rect.x=100;
    image4Rect.y=700;
    image4Rect.w=100;
    image4Rect.h=50;
    SDL_RenderCopy(Renderer,image4,NULL,&image4Rect);


    SDL_Texture* image5= IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/untitled1.png");

    SDL_Rect image5Rect;
    image5Rect.x=400;
    image5Rect.y=550;
    image5Rect.w=200;
    image5Rect.h=200;
    SDL_RenderCopy(Renderer,image5,NULL,&image5Rect);


    SDL_Texture* image6= IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/untitled2.png");

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

void fse(SDL_Renderer *Renderer){

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

    SDL_Texture* image4 = IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/BACK.png");
    SDL_Rect image4Rect;
    image4Rect.x=100;
    image4Rect.y=700;
    image4Rect.w=100;
    image4Rect.h=50;
    SDL_RenderCopy(Renderer,image4,NULL,&image4Rect);



    SDL_RenderPresent(Renderer);
    SDL_DestroyTexture(image);
    SDL_DestroyTexture(image1);
    SDL_DestroyTexture(image2);
    SDL_DestroyTexture(image3);
    SDL_DestroyTexture(image4);

}
void theme(SDL_Renderer *Renderer){

    SDL_Texture* image= IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/bspace.jpg");

    SDL_Rect imageRect;
    imageRect.x=0;
    imageRect.y=0;
    imageRect.w=1400;
    imageRect.h=800;
    SDL_RenderCopy(Renderer,image,NULL,&imageRect);
    TTF_Font* font= TTF_OpenFont("C:/Users/HP/CLionProjects/untitled6/font.otf",40);
    SDL_Color textColor = {255,255,255,255};

    SDL_Texture* image1= IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/firebg.png");

    SDL_Rect image1Rect;
    image1Rect.x=200;
    image1Rect.y=200;
    image1Rect.w=400;
    image1Rect.h=400;
    SDL_RenderCopy(Renderer,image1,NULL,&image1Rect);

    filledrect(Renderer,300,300,200,200,rr1,0,bb1,1);

    SDL_Surface* textSurface5 = TTF_RenderText_Solid(font,"FIRE",textColor);
    SDL_Texture* textTexture5 = SDL_CreateTextureFromSurface(Renderer,textSurface5);
    SDL_Rect textRect5 = {355,350,textSurface5->w,textSurface5->h};
    SDL_RenderCopy(Renderer,textTexture5,NULL,&textRect5);


    SDL_Texture* image2= IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/seabg.jpg");

    SDL_Rect image2Rect;
    image2Rect.x=800;
    image2Rect.y=200;
    image2Rect.w=400;
    image2Rect.h=400;
    SDL_RenderCopy(Renderer,image2,NULL,&image2Rect);

    filledrect(Renderer,900,300,200,200,rr2,0,bb2,1);

    SDL_Surface* textSurface6 = TTF_RenderText_Solid(font,"SEA",textColor);
    SDL_Texture* textTexture6= SDL_CreateTextureFromSurface(Renderer,textSurface6);
    SDL_Rect textRect6= {950,350,textSurface6->w,textSurface6->h};
    SDL_RenderCopy(Renderer,textTexture6,NULL,&textRect6);

    SDL_Texture* image3 = IMG_LoadTexture(Renderer,"C:/Users/HP/CLionProjects/untitled6/BACK.png");
    SDL_Rect image3Rect;
    image3Rect.x=100;
    image3Rect.y=700;
    image3Rect.w=100;
    image3Rect.h=50;
    SDL_RenderCopy(Renderer,image3,NULL,&image3Rect);
    SDL_RenderPresent(Renderer);
}

void game_1(SDL_Renderer *Renderer,double mx,double my, Laser &laser, int k, Ball ghofl, Ball lasert, Ball color){
    if(fire){
        draw(Renderer,image_img,image_rect,0,0,1400,800);
    }

    else if(sea){
        draw(Renderer,imagee_img,imagee_rect,0,0,1400,800);

    }
    draw_canon(Renderer,image1_img,image1_rect,600,650,200,250,mx,my);
    laserPath(Renderer,laser, mx, my,stoop,k);
    filledrect(Renderer,0,640,1400,10,255,0,0,1);
    filledrect(Renderer,1000,650,300,100,255,255,255,1);




}




void game_1t(SDL_Renderer *Renderer,double mx,double my, Laser &laser,int k){
    if(fire){
        draw(Renderer,image_img,image_rect,0,0,1400,800);
    }

    else if(sea){
        draw(Renderer,imagee_img,imagee_rect,0,0,1400,800);

    }
    draw_canon(Renderer,image1_img,image1_rect,600,650,200,250,mx,my);
    laserPath(Renderer,laser, mx, my,stoop,k);
    filledrect(Renderer,0,640,1400,10,255,0,0,1);
    filledrect(m_renderer,100,650,100,100,255,0,0,1);
    int seconds = remainingTime /1000;
    seconds%=60;
    stringstream textStream10;
    if(seconds==0){
        for (int i = 0; i <balls.size() ; ++i) {
            if(balls[i].a==255){
                lost= true;
                win=false;
            }
            else{
                lost=false;
                win=true;
            }

        }
        result(m_renderer);

    }
    textStream10<<seconds;
    string text10= textStream10.str();
    TTF_Font* font10= TTF_OpenFont("C:/Users/HP/CLionProjects/untitled6/font.otf",30);
    SDL_Color textColor10= {255,255,255,255};
    SDL_Surface* textSurface10 = TTF_RenderText_Solid(font10,text10.c_str() ,textColor10);
    SDL_Texture* textTexture10 = SDL_CreateTextureFromSurface(m_renderer,textSurface10);
    SDL_Rect textRect10 = {140,680,textSurface10->w,textSurface10->h};
    SDL_RenderCopy(m_renderer,textTexture10,NULL,&textRect10);
    filledrect(Renderer,1000,650,300,100,255,255,255,1);

}

void draw_circle(SDL_Renderer *Renderer){
    int x=50;
    double y=50;
    Ball ball;
    for(int i=0; i<=13 ; i++){

        ball.x=x;
        ball.y=y;
        random(ball.r,ball.g,ball.b);
        ball.a=255;
        balls.push_back(ball);
        x+=100;
    }
    y+=50 * sqrt(3);
    x=100;
    for(int i=14; i<=26; i++){
        ball.x=x;
        ball.y=y;
        random(ball.r,ball.g,ball.b);
        ball.a=255;
        balls.push_back(ball);

        x+=100;
    }
    y+=50*sqrt(3);
    x=50;
    for(int i=27; i<=40 ; i++){
        ball.x=x;
        ball.y=y;
        random(ball.r,ball.g,ball.b);
        ball.a=255;
        balls.push_back(ball);
        x+=100;
    }
    y+=50 * sqrt(3);
    x=100;
    for(int i=41; i<=53 ; i++){
        ball.x=x;
        ball.y=y;
        random(ball.r,ball.g,ball.b);
        ball.a=255;
        balls.push_back(ball);
        x+=100;
    }
    y+=50 * sqrt(3);
    x=50;
    for(int i=54; i<=67 ; i++){
        ball.x=x;
        ball.y=y;
        random(ball.r,ball.g,ball.b);
        ball.a=0;
        balls.push_back(ball);
        x+=100;
    }
    y+=50 * sqrt(3);
    x=100;
    for(int i=68; i<=80 ; i++){
        ball.x=x;
        ball.y=y;
        random(ball.r,ball.g,ball.b);
        ball.a=0;
        balls.push_back(ball);
        x+=100;
    }
    y+=50 * sqrt(3);
    x=50;
    for(int i=81; i<=94 ; i++){
        ball.x=x;
        ball.y=y;
        random(ball.r,ball.g,ball.b);
        ball.a=0;
        balls.push_back(ball);
        x+=100;
    }
    y+=50 * sqrt(3);
    x=100;
    for(int i=95; i<=107 ; i++){
        ball.x=x;
        ball.y=y;
        random(ball.r,ball.g,ball.b);
        ball.a=0;
        balls.push_back(ball);
        x+=100;
    }



}
int m = 1;
void random(int &r,int &g,int &b){
    int rc = rand() % 6;
    if (rc == 0)
    {
        r = 106;
        g = 90;
        b = 205;
    }
    else if (rc == 1)
    {
        r = 255;
        g = 165;
        b = 0;
    }
    else if (rc == 2)
    {
        r = 60;
        g = 179;
        b = 113;
    }
    else if (rc == 3)
    {
        r = 0;
        g = 255;
        b = 242;
    }
    else if(rc==4){
        r = 255;
        g = 0;
        b = 173;
    }
    else if(rc==5 && m<=2){
        r=0;
        g=0;
        b=0;
        m++;
    }
}
int ee=0;
int zz=0;

void random2(int &r,int &g,int &b){
    int rc = rand() % 7;
    if (rc == 0)
    {
        r = 106;
        g = 90;
        b = 205;
    }
    else if (rc == 1)
    {
        r = 255;
        g = 165;
        b = 0;
    }
    else if (rc == 2)
    {
        r = 60;
        g = 179;
        b = 113;
    }
    else if (rc == 3)
    {
        r = 0;
        g = 255;
        b = 242;
    }
    else if(rc==4){
        r = 255;
        g = 0;
        b = 173;
    }
    else if(rc==5 && zz<1){
        r=255;
        g=255;
        b=255;
        zz++;
    }

    else if(rc==5 && ee<1){
        r=255;
        g=0;
        b=0;
        ee++;
    }
}
void saftoop(SDL_Renderer *Renderer){
    Ball toop;
    for(int i=0; i<100; i++){
        toop.x = 700;
        toop.y = 700;
        toop.a=255;
        random2(toop.r,toop.g,toop.b);
        stoop.push_back(toop);
    }
}
double shib(double mx, double my){
    if(mx!=700){
        double shib1 = abs(730-my) / abs(700-mx);
        return shib1;

    }
    else{
        double shib1 = abs(730-my) / abs(701-mx);
        return shib1;

    }


}
double dis(double x1,double y1,double x2,double y2){
    double d=sqrt((pow((x2-x1),2))+(pow((y2-y1),2)));
    return d;
}

bool connected(Ball ball1, Ball ball2){
    if(dis(ball1.x,ball1.y,ball2.x,ball2.y)<=100){
        return true;
    }

    else{
        return false;
    }
}
bool samecolor(Ball ball1, Ball ball2){
    if(ball1.r==ball2.r && ball1.g==ball2.g && ball1.b==ball2.b ){
        return true;
    }
    else{
        return false;
    }
}
void draw(SDL_Renderer* m_renderer, SDL_Texture* m_img, SDL_Rect img_rect,int x,int y, int w,int h){
    img_rect.x=x;
    img_rect.y=y;
    img_rect.w=w;
    img_rect.h=h;
    SDL_RenderCopy(m_renderer,m_img,NULL,&img_rect);

}

void draw_canon(SDL_Renderer* m_renderer, SDL_Texture* m_img, SDL_Rect img_rect,int x,int y, int w,int h,int mx, int my){
    img_rect.x=x;
    img_rect.y=y;
    img_rect.w=w;
    img_rect.h=h;
    double tetha = atan((my-700)/(mx-650));
    if ((my - 700 > 0) && (mx - 650 > 0))
    {
        tetha = (3.1415 / 2) - tetha;
    }
    if ((my - 700 < 0) && (mx - 650 > 0))
    {
        tetha = (3.1415 / 2) - tetha;
    }
    if ((my - 700 < 0) && (mx - 650 < 0))
    {
        tetha = (3 * 3.1415 / 2) - tetha;
    }
    if ((my - 700 > 0) && (mx - 650 < 0))
    {
        tetha = (3 * 3.1415 / 2) - tetha;
    }
    SDL_RenderCopyEx(m_renderer, m_img,NULL, &img_rect,-(tetha*57.3), NULL, SDL_FLIP_NONE);




}
void result(SDL_Renderer* m_renderer){
    TTF_Font* font= TTF_OpenFont("C:/Users/HP/CLionProjects/untitled6/font.otf",60);
    SDL_Color textColor = {255,255,255,255};
    if(lost){
        filledrect(m_renderer,0,0,1400,800,0,0,0,1);
        draw(m_renderer,image2_img,image2_rect,200,100,1000,600);
        draw(m_renderer,image3_img,image3_rect,600,500,200,200);
        filledrect(m_renderer,550,100,300,100,ur, ug, ub,1);

        SDL_Surface* textSurface = TTF_RenderText_Solid(font,"username",textColor);
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(m_renderer,textSurface);
        SDL_Rect textRect = {580,130,textSurface->w,textSurface->h};
        SDL_RenderCopy(m_renderer,textTexture,NULL,&textRect);

        draw(m_renderer,image13_img,image13_rect,200,500,200,200);

        filledrect(m_renderer,550,200,300,100,60, 179, 113,1);
        string s= to_string(emtiaz2);
        SDL_Surface* surface = TTF_RenderText_Blended(font,s.c_str(),textColor);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer,surface);

        SDL_Rect destRect = {700,230,surface->w, surface->w};
        SDL_RenderCopy(m_renderer,texture, nullptr,&destRect);

        SDL_RenderPresent(m_renderer);

    }

    if(win){
        filledrect(m_renderer,0,0,1400,800,0,0,0,1);
        draw(m_renderer,image4_img,image4_rect,200,100,1000,600);
        draw(m_renderer,image13_img,image13_rect,200,500,200,200);
        string st= to_string(emtiaz2);
        SDL_Surface* surface = TTF_RenderText_Blended(font,st.c_str(),textColor);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer,surface);

        SDL_Rect destRect = {550,280,surface->w, surface->w};
        SDL_RenderCopy(m_renderer,texture, nullptr,&destRect);
        SDL_RenderPresent(m_renderer);

    }
}

void resultt(SDL_Renderer* m_renderer){
    TTF_Font* font= TTF_OpenFont("C:/Users/HP/CLionProjects/untitled6/font.otf",60);
    SDL_Color textColor = {255,255,255,255};
    if(lost){
        filledrect(m_renderer,0,0,1400,800,0,0,0,1);
        draw(m_renderer,image2_img,image2_rect,200,100,1000,600);
        draw(m_renderer,image3_img,image3_rect,600,500,200,200);
        filledrect(m_renderer,550,100,300,100,ur, ug, ub,1);

        SDL_Surface* textSurface = TTF_RenderText_Solid(font,"username",textColor);
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(m_renderer,textSurface);
        SDL_Rect textRect = {580,130,textSurface->w,textSurface->h};
        SDL_RenderCopy(m_renderer,textTexture,NULL,&textRect);

        draw(m_renderer,image13_img,image13_rect,200,500,200,200);

        filledrect(m_renderer,550,200,300,100,60, 179, 113,1);
        string sr= to_string(emtiaz1);
        SDL_Surface* surface = TTF_RenderText_Blended(font,sr.c_str(),textColor);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer,surface);

        SDL_Rect destRect = {700,230,surface->w, surface->w};
        SDL_RenderCopy(m_renderer,texture, nullptr,&destRect);

        SDL_RenderPresent(m_renderer);

    }

    if(win){
        filledrect(m_renderer,0,0,1400,800,0,0,0,1);
        draw(m_renderer,image4_img,image4_rect,200,100,1000,600);
        draw(m_renderer,image13_img,image13_rect,200,500,200,200);
        string sd= to_string(emtiaz1);
        SDL_Surface* surface = TTF_RenderText_Blended(font,sd.c_str(),textColor);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer,surface);

        SDL_Rect destRect = {550,280,surface->w, surface->w};
        SDL_RenderCopy(m_renderer,texture, nullptr,&destRect);
        SDL_RenderPresent(m_renderer);

    }
}

void r(int i){
    if(i<0 || i>94){
        return;
    }

    if(i>41 && i<53){
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+13]);
                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;

            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+14]);
                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }

        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+1]);
                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-1]);
                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }

        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-13]);
                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }
        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-14]);
                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }

    }

    if(i==41){
        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+1]);
                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+13]);
                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+14]);
                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }
        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-14]);
                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }
        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-13]);
                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }

    }

    if(i==53){
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-1]);
                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+13]);
                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+14]);
                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }

        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-14]);
                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }

        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-13]);
                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }

    }

    if(i>54 && i<67){
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+13]);
                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+14]);
                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }

        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+1]);
                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-1]);
                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }

        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-13]);
                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }
        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-14]);
                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }

    }

    if(i==54){
        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+1]);
                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+14]);
                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }
        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(q>0){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-13]);
                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }

    }

    if(i==67){
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-1]);
                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+13]);
                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }


        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-14]);
                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }


    }

    if(i>68 && i<80){
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+13]);
                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+14]);
                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }

        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+1]);
                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-1]);
                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }

        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-13]);
                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }
        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-14]);
                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }

    }

    if(i==68){
        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+1]);
                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+13]);
                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+14]);
                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }
        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-14]);
                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }
        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-13]);
                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }

    }

    if(i==80){
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-1]);
                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+13]);
                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+14]);
                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }

        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-14]);
                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }

        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-13]);
                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }

    }
    if(i>0 && i<13){
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+13]);
                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+14]);
                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }

        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+1]);
                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-1]);
                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }
    }

    if(i==0){
        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+1]);
                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+14]);
                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }

    }

    if(i==13){
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+1]);
                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+13]);
                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

    }

    if(i>14 && i<26){
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+13]);
                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+14]);
                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }

        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+1]);
                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-1]);
                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }

        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-13]);
                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }
        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-14]);
                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }

    }

    if(i==14){
        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+1]);
                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+13]);
                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+14]);
                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }
        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-14]);
                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }
        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-13]);
                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }

    }

    if(i==26){
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-1]);
                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+13]);
                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+14]);
                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);

        }

        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-14]);
                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }

        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-13]);
                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }

    }

    if(i>27 && i<40){
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+13]);
                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+14]);
                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }

        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+1]);
                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-1]);
                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }

        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-13]);
                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }
        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-14]);
                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }

    }

    if(i==27){
        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+1]);
                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+14]);
                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }
        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-13]);
                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }

    }

    if(i==40){
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-1]);
                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+13]);
                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }


        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-14]);
                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }


    }

    if(i>81 && i<94){

        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+1]);
                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-1]);
                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }

        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-13]);
                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }
        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-14]);
                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }

    }

    if(i==81){
        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i+1]);
                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }

        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-13]);
                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }

    }

    if(i==94){
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-1]);
                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }


        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(q>1){
                removes.push_back(balls[i]);
                removes.push_back(balls[i-14]);
                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }


    }



}

void ri(int i){
    if(i<0 || i>94){
        return;
    }

    if(i>41 && i<53){
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+13].x!=removes[j].x && balls[i+13].y!=removes[j].y){
                        removes.push_back(balls[i+13]);

                    }

                }


                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;

            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(removes.size()>3){
                 for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+14].x!=removes[j].x && balls[i+14].y!=removes[j].y){
                        removes.push_back(balls[i+14]);

                    }

                }

                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }

        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+1].x!=removes[j].x && balls[i+1].y!=removes[j].y){
                        removes.push_back(balls[i+1]);

                    }

                }

                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-1].x!=removes[j].x && balls[i-1].y!=removes[j].y){
                        removes.push_back(balls[i-1]);

                    }

                }

                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }

        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-13].x!=removes[j].x && balls[i-13].y!=removes[j].y){
                        removes.push_back(balls[i-13]);

                    }

                }

                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }
        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-14].x!=removes[j].x && balls[i-14].y!=removes[j].y){
                        removes.push_back(balls[i-14]);

                    }

                }

                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }

    }

    if(i==41){
        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+1].x!=removes[j].x && balls[i+1].y!=removes[j].y){
                        removes.push_back(balls[i+1]);

                    }

                }

                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+13].x!=removes[j].x && balls[i+13].y!=removes[j].y){
                        removes.push_back(balls[i+13]);

                    }

                }

                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+14].x!=removes[j].x && balls[i+14].y!=removes[j].y){
                        removes.push_back(balls[i+14]);

                    }

                }

                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }
        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-14].x!=removes[j].x && balls[i-14].y!=removes[j].y){
                        removes.push_back(balls[i-14]);

                    }

                }

                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }
        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-13].x!=removes[j].x && balls[i-13].y!=removes[j].y){
                        removes.push_back(balls[i-13]);

                    }

                }

                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }

    }

    if(i==53){
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-1].x!=removes[j].x && balls[i-1].y!=removes[j].y){
                        removes.push_back(balls[i-1]);

                    }

                }

                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+13].x!=removes[j].x && balls[i+13].y!=removes[j].y){
                        removes.push_back(balls[i+13]);

                    }

                }

                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+14].x!=removes[j].x && balls[i+14].y!=removes[j].y){
                        removes.push_back(balls[i+14]);

                    }

                }

                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }

        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-14].x!=removes[j].x && balls[i-14].y!=removes[j].y){
                        removes.push_back(balls[i-14]);

                    }

                }

                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }

        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-13].x!=removes[j].x && balls[i-13].y!=removes[j].y){
                        removes.push_back(balls[i-13]);

                    }

                }

                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }

    }

    if(i>54 && i<67){
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+13].x!=removes[j].x && balls[i+13].y!=removes[j].y){
                        removes.push_back(balls[i+13]);

                    }

                }

                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+14].x!=removes[j].x && balls[i+14].y!=removes[j].y){
                        removes.push_back(balls[i+14]);

                    }

                }

                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }

        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+1].x!=removes[j].x && balls[i+1].y!=removes[j].y){
                        removes.push_back(balls[i+1]);

                    }

                }

                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-1].x!=removes[j].x && balls[i-1].y!=removes[j].y){
                        removes.push_back(balls[i-1]);

                    }

                }

                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }

        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-13].x!=removes[j].x && balls[i-13].y!=removes[j].y){
                        removes.push_back(balls[i-13]);

                    }

                }

                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }
        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-14].x!=removes[j].x && balls[i-14].y!=removes[j].y){
                        removes.push_back(balls[i-14]);

                    }

                }

                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }

    }

    if(i==54){
        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+1].x!=removes[j].x && balls[i+1].y!=removes[j].y){
                        removes.push_back(balls[i+1]);

                    }

                }

                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+14].x!=removes[j].x && balls[i+14].y!=removes[j].y){
                        removes.push_back(balls[i+14]);

                    }

                }

                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }
        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-13].x!=removes[j].x && balls[i-13].y!=removes[j].y){
                        removes.push_back(balls[i-13]);

                    }

                }

                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }

    }

    if(i==67){
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-1].x!=removes[j].x && balls[i-1].y!=removes[j].y){
                        removes.push_back(balls[i-1]);

                    }

                }

                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+13].x!=removes[j].x && balls[i+13].y!=removes[j].y){
                        removes.push_back(balls[i+13]);

                    }

                }

                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }


        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-14].x!=removes[j].x && balls[i-14].y!=removes[j].y){
                        removes.push_back(balls[i-14]);

                    }

                }

                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }


    }

    if(i>68 && i<80){
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+13].x!=removes[j].x && balls[i+13].y!=removes[j].y){
                        removes.push_back(balls[i+13]);

                    }

                }

                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+14].x!=removes[j].x && balls[i+14].y!=removes[j].y){
                        removes.push_back(balls[i+14]);

                    }

                }

                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }

        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+1].x!=removes[j].x && balls[i+1].y!=removes[j].y){
                        removes.push_back(balls[i+1]);

                    }

                }

                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-1].x!=removes[j].x && balls[i-1].y!=removes[j].y){
                        removes.push_back(balls[i-1]);

                    }

                }

                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }

        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-13].x!=removes[j].x && balls[i-13].y!=removes[j].y){
                        removes.push_back(balls[i-13]);

                    }

                }

                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }
        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-14].x!=removes[j].x && balls[i-14].y!=removes[j].y){
                        removes.push_back(balls[i-14]);

                    }

                }

                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }

    }

    if(i==68){
        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+1].x!=removes[j].x && balls[i+1].y!=removes[j].y){
                        removes.push_back(balls[i+1]);

                    }

                }

                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+13].x!=removes[j].x && balls[i+13].y!=removes[j].y){
                        removes.push_back(balls[i+13]);

                    }

                }

                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+14].x!=removes[j].x && balls[i+14].y!=removes[j].y){
                        removes.push_back(balls[i+14]);

                    }

                }

                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }
        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-14].x!=removes[j].x && balls[i-14].y!=removes[j].y){
                        removes.push_back(balls[i-14]);

                    }

                }

                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }
        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-13].x!=removes[j].x && balls[i-13].y!=removes[j].y){
                        removes.push_back(balls[i-13]);

                    }

                }

                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }

    }

    if(i==80){
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-1].x!=removes[j].x && balls[i-1].y!=removes[j].y){
                        removes.push_back(balls[i-1]);

                    }

                }

                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+13].x!=removes[j].x && balls[i+13].y!=removes[j].y){
                        removes.push_back(balls[i+13]);

                    }

                }

                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+14].x!=removes[j].x && balls[i+14].y!=removes[j].y){
                        removes.push_back(balls[i+14]);

                    }

                }

                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }

        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-14].x!=removes[j].x && balls[i-14].y!=removes[j].y){
                        removes.push_back(balls[i-14]);

                    }

                }

                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }

        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-13].x!=removes[j].x && balls[i-13].y!=removes[j].y){
                        removes.push_back(balls[i-13]);

                    }

                }

                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }

    }
    if(i>0 && i<13){
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+13].x!=removes[j].x && balls[i+13].y!=removes[j].y){
                        removes.push_back(balls[i+13]);

                    }

                }

                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+14].x!=removes[j].x && balls[i+14].y!=removes[j].y){
                        removes.push_back(balls[i+14]);

                    }

                }

                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }

        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+1].x!=removes[j].x && balls[i+1].y!=removes[j].y){
                        removes.push_back(balls[i+1]);

                    }

                }

                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-1].x!=removes[j].x && balls[i-1].y!=removes[j].y){
                        removes.push_back(balls[i-1]);

                    }

                }
                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }
    }

    if(i==0){
        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+1].x!=removes[j].x && balls[i+1].y!=removes[j].y){
                        removes.push_back(balls[i+1]);

                    }

                }
                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+14].x!=removes[j].x && balls[i+14].y!=removes[j].y){
                        removes.push_back(balls[i+14]);

                    }

                }
                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }

    }

    if(i==13){
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+1].x!=removes[j].x && balls[i+1].y!=removes[j].y){
                        removes.push_back(balls[i+1]);

                    }

                }
                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+13].x!=removes[j].x && balls[i+13].y!=removes[j].y){
                        removes.push_back(balls[i+13]);

                    }

                }
                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

    }

    if(i>14 && i<26){
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+13].x!=removes[j].x && balls[i+13].y!=removes[j].y){
                        removes.push_back(balls[i+13]);

                    }

                }
                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+14].x!=removes[j].x && balls[i+14].y!=removes[j].y){
                        removes.push_back(balls[i+14]);

                    }

                }
                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }

        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+1].x!=removes[j].x && balls[i+1].y!=removes[j].y){
                        removes.push_back(balls[i+1]);

                    }

                }
                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-1].x!=removes[j].x && balls[i-1].y!=removes[j].y){
                        removes.push_back(balls[i-1]);

                    }

                }
                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }

        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-13].x!=removes[j].x && balls[i-13].y!=removes[j].y){
                        removes.push_back(balls[i-13]);

                    }

                }
                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }
        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-14].x!=removes[j].x && balls[i-14].y!=removes[j].y){
                        removes.push_back(balls[i-14]);

                    }

                }
                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }

    }

    if(i==14){
        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+1].x!=removes[j].x && balls[i+1].y!=removes[j].y){
                        removes.push_back(balls[i+1]);

                    }

                }
                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+13].x!=removes[j].x && balls[i+13].y!=removes[j].y){
                        removes.push_back(balls[i+13]);

                    }

                }
                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+14].x!=removes[j].x && balls[i+14].y!=removes[j].y){
                        removes.push_back(balls[i+14]);

                    }

                }
                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }
        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-14].x!=removes[j].x && balls[i-14].y!=removes[j].y){
                        removes.push_back(balls[i-14]);

                    }

                }
                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }
        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-13].x!=removes[j].x && balls[i-13].y!=removes[j].y){
                        removes.push_back(balls[i-13]);

                    }

                }
                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }

    }

    if(i==26){
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-1].x!=removes[j].x && balls[i-1].y!=removes[j].y){
                        removes.push_back(balls[i-1]);

                    }

                }
                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+13].x!=removes[j].x && balls[i+13].y!=removes[j].y){
                        removes.push_back(balls[i+13]);

                    }

                }
                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+14].x!=removes[j].x && balls[i+14].y!=removes[j].y){
                        removes.push_back(balls[i+14]);

                    }

                }
                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);

        }

        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-14].x!=removes[j].x && balls[i-14].y!=removes[j].y){
                        removes.push_back(balls[i-14]);

                    }

                }
                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }

        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-13].x!=removes[j].x && balls[i-13].y!=removes[j].y){
                        removes.push_back(balls[i-13]);

                    }

                }
                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }

    }

    if(i>27 && i<40){
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+13].x!=removes[j].x && balls[i+13].y!=removes[j].y){
                        removes.push_back(balls[i+13]);

                    }

                }
                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+14].x!=removes[j].x && balls[i+14].y!=removes[j].y){
                        removes.push_back(balls[i+14]);

                    }

                }
                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }

        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+1].x!=removes[j].x && balls[i+1].y!=removes[j].y){
                        removes.push_back(balls[i+1]);

                    }

                }
                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-1].x!=removes[j].x && balls[i-1].y!=removes[j].y){
                        removes.push_back(balls[i-1]);

                    }

                }
                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }

        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-13].x!=removes[j].x && balls[i-13].y!=removes[j].y){
                        removes.push_back(balls[i-13]);

                    }

                }
                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }
        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+14].x!=removes[j].x && balls[i+14].y!=removes[j].y){
                        removes.push_back(balls[i+14]);

                    }

                }
                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }

    }

    if(i==27){
        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+1].x!=removes[j].x && balls[i+1].y!=removes[j].y){
                        removes.push_back(balls[i+1]);

                    }

                }
                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }

        if(samecolor(balls[i],balls[i+14]) && balls[i+14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+14].x!=removes[j].x && balls[i+14].y!=removes[j].y){
                        removes.push_back(balls[i+14]);

                    }

                }
                balls[i].a=0;
                balls[i+14].a=0;
                b+=10;
            }
            q++;
            r(i+14);
        }
        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-13].x!=removes[j].x && balls[i-13].y!=removes[j].y){
                        removes.push_back(balls[i-13]);

                    }

                }
                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }

    }

    if(i==40){
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-1].x!=removes[j].x && balls[i-1].y!=removes[j].y){
                        removes.push_back(balls[i-1]);

                    }

                }
                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }
        if(samecolor(balls[i],balls[i+13]) && balls[i+13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+13].x!=removes[j].x && balls[i+13].y!=removes[j].y){
                        removes.push_back(balls[i+13]);

                    }

                }
                balls[i].a=0;
                balls[i+13].a=0;
                b+=10;
            }
            q++;
            r(i+13);
        }


        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-14].x!=removes[j].x && balls[i-14].y!=removes[j].y){
                        removes.push_back(balls[i-14]);

                    }

                }
                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }


    }

    if(i>81 && i<94){

        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+1].x!=removes[j].x && balls[i+1].y!=removes[j].y){
                        removes.push_back(balls[i+1]);

                    }

                }
                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-1].x!=removes[j].x && balls[i-1].y!=removes[j].y){
                        removes.push_back(balls[i-1]);

                    }

                }
                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }

        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-13].x!=removes[j].x && balls[i-13].y!=removes[j].y){
                        removes.push_back(balls[i-13]);

                    }

                }
                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }
        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-14].x!=removes[j].x && balls[i-14].y!=removes[j].y){
                        removes.push_back(balls[i-14]);

                    }

                }
                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }

    }

    if(i==81){
        if(samecolor(balls[i],balls[i+1]) && balls[i+1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i+1].x!=removes[j].x && balls[i+1].y!=removes[j].y){
                        removes.push_back(balls[i+1]);

                    }

                }
                balls[i].a=0;
                balls[i+1].a=0;
                b+=10;
            }
            q++;
            r(i+1);
        }

        if(samecolor(balls[i],balls[i-13]) && balls[i-13].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-13].x!=removes[j].x && balls[i-13].y!=removes[j].y){
                        removes.push_back(balls[i-13]);

                    }

                }
                balls[i].a=0;
                balls[i-13].a=0;
                b+=10;
            }
            q++;
            r(i-13);
        }

    }

    if(i==94){
        if(samecolor(balls[i],balls[i-1]) && balls[i-1].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-1].x!=removes[j].x && balls[i-1].y!=removes[j].y){
                        removes.push_back(balls[i-1]);

                    }

                }
                balls[i].a=0;
                balls[i-1].a=0;
                b+=10;
            }
            q++;
            r(i-1);
        }


        if(samecolor(balls[i],balls[i-14]) && balls[i-14].a==255){
            if(removes.size()>3){
                for (int j = 0; j <removes.size() ; ++j) {
                    if(balls[i].x!=removes[j].x && balls[i].y!=removes[j].y){
                        removes.push_back(balls[i]);

                    }

                }
                for (int j = 0; j <removes.size(); ++j) {
                    if(balls[i-14].x!=removes[j].x && balls[i-14].y!=removes[j].y){
                        removes.push_back(balls[i-14]);

                    }

                }
                balls[i].a=0;
                balls[i-14].a=0;
                b+=10;
            }
            q++;
            r(i-14);
        }


    }



}

void fr(int i) {
    if (i > 41 && i < 53) {
        if (balls[i + 13].a == 0 && balls[i + 14].a == 0 && balls[i - 14].a == 0 && balls[i - 13].a == 0 &&
            balls[i - 1].a == 0 && balls[i + 1].a == 0) {
            balls[i].a = 0;
        }
    }

    if (i == 41) {
        if (balls[i + 13].a == 0 && balls[i + 14].a == 0 && balls[i - 14].a == 0 && balls[i - 13].a == 0 &&
            balls[i + 1].a == 0) {
            balls[i].a = 0;
        }
    }

    if (i == 53) {
        if (balls[i + 13].a == 0 && balls[i + 14].a == 0 && balls[i - 14].a == 0 && balls[i - 13].a == 0 &&
            balls[i - 1].a == 0) {
            balls[i].a = 0;
        }

    }

    if (i > 54 && i < 67) {
        if (balls[i + 13].a == 0 && balls[i + 14].a == 0 && balls[i - 14].a == 0 && balls[i - 13].a == 0 &&
            balls[i - 1].a == 0 && balls[i + 1].a == 0) {
            balls[i].a = 0;
        }

    }

    if (i == 54) {
        if (balls[i + 14].a == 0 && balls[i - 13].a == 0 && balls[i + 1].a == 0) {
            balls[i].a = 0;
        }

    }

    if (i == 67) {
        if (balls[i + 13].a == 0 && balls[i - 14].a == 0 && balls[i - 1].a == 0) {
            balls[i].a = 0;
        }

    }

    if (i > 68 && i < 80) {
        if (balls[i + 13].a == 0 && balls[i + 14].a == 0 && balls[i - 14].a == 0 && balls[i - 13].a == 0 &&
            balls[i - 1].a == 0 && balls[i + 1].a == 0) {
            balls[i].a = 0;
        }
    }

    if (i == 68) {
        if (balls[i + 13].a == 0 && balls[i + 14].a == 0 && balls[i - 14].a == 0 && balls[i - 13].a == 0 &&
            balls[i + 1].a == 0) {
            balls[i].a = 0;
        }
    }

    if (i == 80) {
        if (balls[i + 13].a == 0 && balls[i + 14].a == 0 && balls[i - 14].a == 0 && balls[i - 13].a == 0 &&
            balls[i - 1].a == 0) {
            balls[i].a = 0;
        }
    }
    if (i > 0 && i < 13) {
        if (balls[i + 13].a == 0 && balls[i + 14].a == 0 && balls[i - 1].a == 0 && balls[i + 1].a == 0) {
            balls[i].a = 0;
        }
    }

    if (i == 0) {
        if (balls[i + 14].a == 0 && balls[i + 1].a == 0) {
            balls[i].a = 0;
        }

    }

    if (i == 13) {
        if (balls[i + 13].a == 0 && balls[i - 1].a == 0) {
            balls[i].a = 0;
        }

    }

    if (i > 14 && i < 26) {
        if (balls[i + 13].a == 0 && balls[i + 14].a == 0 && balls[i - 14].a == 0 && balls[i - 13].a == 0 &&
            balls[i - 1].a == 0 && balls[i + 1].a == 0) {
            balls[i].a = 0;
        }
    }

    if (i == 14) {
        if (balls[i + 13].a == 0 && balls[i + 14].a == 0 && balls[i - 14].a == 0 && balls[i - 13].a == 0 &&
            balls[i + 1].a == 0) {
            balls[i].a = 0;
        }

    }

    if (i == 26) {
        if (balls[i + 13].a == 0 && balls[i + 14].a == 0 && balls[i - 14].a == 0 && balls[i - 13].a == 0 &&
            balls[i - 1].a == 0) {
            balls[i].a = 0;
        }
    }

    if (i > 27 && i < 40) {
        if (balls[i + 13].a == 0 && balls[i + 14].a == 0 && balls[i - 14].a == 0 && balls[i - 13].a == 0 &&
            balls[i - 1].a == 0 && balls[i + 1].a == 0) {
            balls[i].a = 0;
        }
    }

    if (i == 27) {
        if (balls[i + 14].a == 0 && balls[i - 13].a == 0 && balls[i + 1].a == 0) {
            balls[i].a = 0;
        }
    }

    if (i == 40) {
        if (balls[i + 13].a == 0 && balls[i - 14].a == 0 && balls[i - 1].a == 0) {
            balls[i].a = 0;
        }


    }

    if (i > 81 && i < 94) {
        if (balls[i - 14].a == 0 && balls[i - 13].a == 0 && balls[i - 1].a == 0 && balls[i + 1].a == 0) {
            balls[i].a = 0;
        }

    }

    if (i == 81) {
        if (balls[i - 13].a == 0 && balls[i + 1].a == 0) {
            balls[i].a = 0;
        }
    }

    if (i == 94) {
        if (balls[i - 14].a == 0 && balls[i - 1].a == 0) {
            balls[i].a = 0;
        }
    }
}

int memtiaz(int a, int b){
    if(a==b){
        return a;
    }
    if(a>b){
        return a;
    }
    if(b>a){
        return b;
    }
}

void scores(SDL_Renderer* m_renderer){
    filledrect(m_renderer,100,50,1200,700,60, 179, 113,1);
    TTF_Font* font= TTF_OpenFont("C:/Users/HP/CLionProjects/untitled6/font.otf",40);
    SDL_Color textColor = {255,255,255,255};
    SDL_Surface* textSurface5 = TTF_RenderText_Solid(font,"username",textColor);
    SDL_Texture* textTexture5 = SDL_CreateTextureFromSurface(m_renderer,textSurface5);
    SDL_Rect textRect5 = {200,100,textSurface5->w,textSurface5->h};
    SDL_RenderCopy(m_renderer,textTexture5,NULL,&textRect5);

    SDL_Surface* textSurface6= TTF_RenderText_Solid(font,"random mode",textColor);
    SDL_Texture* textTexture6 = SDL_CreateTextureFromSurface(m_renderer,textSurface6);
    SDL_Rect textRect6 = {450,100,textSurface6->w,textSurface6->h};
    SDL_RenderCopy(m_renderer,textTexture6,NULL,&textRect6);

    SDL_Surface* textSurface2 = TTF_RenderText_Solid(font,"username",textColor);
    SDL_Texture* textTexture2 = SDL_CreateTextureFromSurface(m_renderer,textSurface2);
    SDL_Rect textRect2 = {800,100,textSurface2->w,textSurface2->h};
    SDL_RenderCopy(m_renderer,textTexture2,NULL,&textRect2);

    SDL_Surface* textSurface4= TTF_RenderText_Solid(font,"timer mode",textColor);
    SDL_Texture* textTexture4 = SDL_CreateTextureFromSurface(m_renderer,textSurface4);
    SDL_Rect textRect4 = {1050,100,textSurface4->w,textSurface4->h};
    SDL_RenderCopy(m_renderer,textTexture4,NULL,&textRect4);
    for (int i = 0; i <users.size()-1 ; ++i) {
        for (int j = 0; j <users.size()-i-1 ; ++j) {
            if(users[j].scores<users[j+1].scores){
                swap(users[j],users[j+1]);
            }


        }

    }

    for (int i = 0; i <users.size() ; ++i) {
        const string& line=users[i].name;
        string numberText= to_string(users[i].scores);


        SDL_Surface* surface = TTF_RenderText_Blended(font,line.c_str(),textColor);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer,surface);

        SDL_Rect destRect = {200,150+static_cast<int>(i* 70),surface->w, surface->w};
        SDL_RenderCopy(m_renderer,texture, nullptr,&destRect);

        SDL_Surface* surface9= TTF_RenderText_Solid(font,numberText.c_str(),textColor);
        SDL_Texture* texture9= SDL_CreateTextureFromSurface(m_renderer,surface9);
        int tw,th;
        SDL_QueryTexture(texture9,NULL,NULL,&tw,&th);
        SDL_Rect dstRect= {500,170+static_cast<int>(i* 70),50,50};
        SDL_RenderCopy(m_renderer,texture9,NULL,& dstRect);

    }
    for (int i = 0; i <users.size()-1 ; ++i) {
        for (int j = 0; j <users.size()-i-1 ; ++j) {
            if(users[j].scorestimer<users[j+1].scorestimer){
                swap(users[j],users[j+1]);
            }


        }

    }

    for (int i = 0; i <users.size() ; ++i) {
        const string& line=users[i].name;
        string numberText2= to_string(users[i].scorestimer);


        SDL_Surface* surface = TTF_RenderText_Blended(font,line.c_str(),textColor);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer,surface);

        SDL_Rect destRect = {800,150+static_cast<int>(i* 70),surface->w, surface->w};
        SDL_RenderCopy(m_renderer,texture, nullptr,&destRect);

        int tw,th;

        SDL_Surface* surface3= TTF_RenderText_Solid(font,numberText2.c_str(),textColor);
        SDL_Texture* texture3= SDL_CreateTextureFromSurface(m_renderer,surface3);
        SDL_QueryTexture(texture3,NULL,NULL,&tw,&th);
        SDL_Rect dstRect3= {1100,170+static_cast<int>(i* 70),50,50};
        SDL_RenderCopy(m_renderer,texture3,NULL,& dstRect3);

    }

    draw(m_renderer,image26_img,image26_rect,100,700,100,50);





    SDL_RenderPresent(m_renderer);

}
int finduser(string esm){
    for (int i = 0; i <users.size() ; ++i) {
        if(esm==users[i].name){
            return i;
        }

    }

}

void pauseMenu(SDL_Renderer* m_renderer){
    draw(m_renderer,image_img,image_rect,0,0,1400,800);
    draw(m_renderer,image6_img,image6_rect,500,100,400,150);
    draw(m_renderer,image7_img,image7_rect,500,300,400,150);
    draw(m_renderer,image5_img,image5_rect,500,500,400,150);
    draw(m_renderer,image17_img,image17_rect,500,700,400,100);
    filledrect(m_renderer,200,300,150,150,r1,g1,b1,1);
    filledrect(m_renderer,200,500,150,150,r2,g2,b2,1);
    TTF_Font* font= TTF_OpenFont("C:/Users/HP/CLionProjects/untitled6/font.otf",40);
    SDL_Color textColor = {255,255,255,255};
    SDL_Surface* textSurface5 = TTF_RenderText_Solid(font,"pause",textColor);
    SDL_Texture* textTexture5 = SDL_CreateTextureFromSurface(m_renderer,textSurface5);
    SDL_Rect textRect5 = {230,570,textSurface5->w,textSurface5->h};
    SDL_RenderCopy(m_renderer,textTexture5,NULL,&textRect5);

    SDL_Surface* textSurface77 = TTF_RenderText_Solid(font,"slowmotion",textColor);
    SDL_Texture* textTexture77 = SDL_CreateTextureFromSurface(m_renderer,textSurface77);
    SDL_Rect textRect77 = {230,370,textSurface77->w,textSurface77->h};
    SDL_RenderCopy(m_renderer,textTexture77,NULL,&textRect77);
    SDL_RenderPresent(m_renderer);
}

void laserPath(SDL_Renderer *Renderer,Laser &laser,int mx,int my,vector <Ball> stoop,int k){
    laser.x = mx;
    laser.y = my;
    if(laser.x>=1350 || laser.x<=20){
        lineRGBA(Renderer,700,775,laser.x,laser.y,255,255,25,255);
        lineRGBA(Renderer,laser.x,laser.y,stoop[k].x,stoop[k].y,255,255,25,255);
    }
    else{
        lineRGBA(Renderer,700,775,laser.x,laser.y,255,255,25,255);
    }
}

void gh(Ball ghofl, int k, double mx,double my,double s){
    shooting=true;
    touched = false;
    if (shooting) {
        while (!touched) {
            if(mx>=700){
                if(stoop[k].x<1350){
                    stoop[k].x+=2;
                    ghofl.x+=2;
                } else{
                    stoop[k].x-=2;
                    ghofl.x-=2;
                }
            }
            if(mx<700){
                if(stoop[k].x>50){
                    stoop[k].x-=2;
                    ghofl.x-=2;
                } else{
                    stoop[k].x+=2;
                    ghofl.x+=2;
                }
            }
            if(stoop[k].y>50){
                stoop[k].y -= (2*s);
                ghofl.y -= (2*s);

            }
            else{
                stoop[k].y += (2*s);
                ghofl.y += (2*s);
            }
            for (int i = 0; i < balls.size(); i++) {
                if (dis(stoop[k].x,stoop[k].y,balls[i].x,balls[i].y) <= 100 && balls[i].a==255) {
                    balls[i].a=0;
                    if(i-13>0) {
                        balls[i-13].a=0;
                    }
                    if(i-14>0) {
                        balls[i-14].a=0;
                    }

                    if(i+13>0) {
                        balls[i+13].a=0;
                    }
                    if(i+14>0) {
                        balls[i+14].a=0;
                    }

                    if(i-1>0) {
                        balls[i-1].a=0;
                    }

                    if(i+1>0) {
                        balls[i+1].a=0;
                    }
                    }
                    touched = true;
                    shooting = false;

                    k++;



                }
            }
        }
    SDL_RenderPresent(m_renderer);
    }

void flaser(int i){
    if(i>=95 && i<=107){
        for(int k=95; k<=107 ;k++){
            balls[i].a=0;
        }
    }
    else if(i>=81 && i<=94){
        for(int k=81; k<=94 ;k++){
            balls[i].a=0;
        }
    }
    else if(i>=68 && i<=80){
        for(int k=68; k<=80 ;k++){
            balls[i].a=0;
        }
    }
    else if(i>=54 && i<=67){
        for(int k=54; k<=67 ;k++){
            balls[i].a=0;
        }
    }
    else if(i>=41 && i<=53){
        for(int k=41; k<=53 ;k++){
            balls[i].a=0;
        }
    }
    else if(i>=27 && i<=40){
        for(int k=27; k<=40 ;k++){
            balls[i].a=0;
        }
    }
    else if(i>=14 && i<=26){
        for(int k=14; k<=26 ;k++){
            balls[i].a=0;
        }
    }
    else if(i>=0 && i<=13){
        for(int k=0; k<=13 ;k++){
            balls[i].a=0;
        }
    }

}













