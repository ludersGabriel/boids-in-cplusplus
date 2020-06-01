#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL2_gfxPrimitives.h>

class vec2{
    private:
        float x, y;
    public:
        vec2(int xcoord, int ycoord){
            x = xcoord;
            y = ycoord;
        }

        vec2 operator + (vec2 const &coord){
            return vec2(x + coord.x, y + coord.y);
        }

        vec2 operator - (vec2 const &coord){
            return vec2(x - coord.x, y - coord.y); 
        }

        vec2 operator / (float const &num){
            return vec2(x/num , y/num);
        }

        vec2 operator * (float const &num){
            return vec2(x*num, y*num);
        }

        bool operator == (vec2 const &coord){
            return x == coord.x and y == coord.y;
        }

        float magnitude(){
            return sqrt(pow(x,2) + pow(y,2));
        }

        float distance(vec2 coord){
            return sqrt(pow(x - coord.x, 2) + pow(y - coord.y, 2));
        }

        void print_coord(void){
            std::cout << "coord x,y: " << x << "," << y << "\n";
        }
};

class game_manager{
    public: 
        int width; 
        int height;
        bool isRunning;
        SDL_Window* window;
        SDL_Renderer* renderer;
        int rendR = 0;
        int rendG = 0;
        int rendB = 0;
        int rendA = 0;
    public:
        game_manager(int w, int h, char const * tittle, bool fullscreen){
            if(not SDL_Init(SDL_INIT_EVERYTHING)){
                int flags = 0;
                if(fullscreen){
                    flags = SDL_WINDOW_FULLSCREEN;
                }
                
                width = w;
                height = h;
                window = SDL_CreateWindow(tittle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
                if(window) std::cout << "window created" << std::endl;
                renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
                if(renderer){
                     std::cout << "renderer created" << std::endl;
                }
                std::cout << "subsystems initialized!.." << std::endl; 
                isRunning = true;
            }
            else isRunning = false;
        }

        void render(){
            SDL_RenderClear(renderer);
            filledCircleRGBA(renderer, width/2, height/2, 5, 255, 23, 200, 255);
            // filledCircleColor(renderer, 10, height/2, width/2, 0xFF0000FF);
            SDL_SetRenderDrawColor(renderer, rendR, rendG, rendB, rendA); 
            SDL_RenderPresent(renderer);
        }


        void update(){
            return;
        }

        void clean(){
            isRunning = false;
            SDL_DestroyWindow(window);
            SDL_DestroyRenderer(renderer);
            SDL_Quit();
            std::cout << "game cleaned" << std::endl;
        }

        void handle_events(){
            SDL_Event event;
            
            SDL_PollEvent(&event);
            switch (event.type){
                case SDL_QUIT:
                    clean();
                    break;
                default:
                    break;
            }

        }

        

};

int main(int argc, char* argv[]){
    game_manager game = game_manager(1600, 900, "boid sim", false);
    
    while(game.isRunning){
        game.handle_events();
        game.update();
        game.render();
    }
    
    return 0;
}