#include "game.h"
#include "util.h"
#include "gridarea.h"
#include "polygon.h"
#include "scrollarea.h"
#include "math2d.h"
#include <stdio.h>
#include <curses.h>
#include <math.h>

float generateRandomFloat(float min, float max);

int generateRandomInt(int min, int max);


static Vec2 spaceship[] = {0,0, 5,-5, 10,0};
static int p[3] = {3,0,1};

static float speed = 0;
static float accelleration = 1.2;

//static void asteroid_count = 5;

void init_font();

void shoot();

/*
struct Asteroid {
    float speed;
    float[2] direction;
    int[2] position;
    int size;
};

Asteroid asteroids[asteroid_count] = { NULL };*/

void init() {    
    // init ASCII gfx
    init_gfx();
    init_color();

    // game area setup     
    int sx = 52, sy = 28;
    set_area_size(COLS, LINES);
    set_window_size(COLS, LINES);
    set_grid_wraparound(true);
    translate(sx/2, sy/2);
   
}

/*
void render_asteroids() {    
    for (int i=0; i<asteroid_count; i++) {
        if (asteroids[i] == NULL) {
            Asteroid ast = {
                speed       = generateRandomFloat(0.5, 2);
                direction   = {generateRandomInt(-1,1), generateRandomInt(-1,1)};
                position    = {generateRandomInt(10, COLS-10), generateRandomInt(10, LINES-10)}
                size        = generateRandomInt(3, 10);
            }
            asteroids[i] = ast;
            
            render_
            
        }
    }
}*/


void game_loop(){
    
    init();
    //sound_init();
    //sound_play("asteroids.wav", 0.1);
    clear();
    
    while (true) {
        
        int c = getch();    
        clear_area();
        render_frame(0, 0, COLS -1, LINES - 1);        
        
        // Move spaceship:
        if (c == 'w') {
            if (speed == 0) 
                speed = 0.2;              
            else 
                speed *= accelleration;
        } else if (c == 's') {
            if (speed > 0) 
                speed *= 2 - (accelleration);
        } else if (c == 'a')
            rotate(-20);
        else if (c == 'd') 
            rotate(20);
        // Shoot
        else if (c == 32)
            shoot();
        // Exit game loop
        else if (c == 'q') 
            return;
        
        // Check and update position
        /*if (spaceship[2].x < 0 || spaceship[2].x > COLS || 
            spaceship[2].y < 0 || spaceship[2].y > LINES) {
        
            spaceship[2].x = ((int) spaceship[2].x + COLS) % COLS;
            spaceship[2].y = ((int) spaceship[2].y + LINES) % LINES;
        }*/
        
        //log_vec2(spaceship[2]);
        
        /*
        Mat3 transform = top();
        if (transform.r1z < 0 || transform.r1z > COLS ||
            transform.r2z < 0 || transform.r2z > LINES){
            
            transform.r1z = ((int) transform.r1z + COLS) % COLS;
            transform.r2z = ((int) transform.r2z + COLS) % COLS;
            
        }*/       
        
        
        // Move and render ship
        translate(0,-speed);        
        render_polygon(p[0], &spaceship[p[1]], ACS_CKBOARD | COLOR_PAIR(p[2]));
        
        //render_ellipse(COLS/2, LINES/2, 5, 5, ACS_CKBOARD, 2);
        
        //translate(1,1);
        
        
        //log_mat3(top());

        center_window(COLS/2, LINES/2);
        
        refresh();
        msleep(25);
    }
    
    //sound_exit();

}

void shoot() {
    ///Vec2 shoot[] = {0,0, 0,-1};
    //p[3] = {2,0,1};
    
    
    
}

/*
float generateRandomFloat(float min, float max) {
    float randomNum = (float)rand() / (float)RAND_MAX;
    return min + randomNum * (max - min);
}


int generateRandomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}*/

    
    
    
