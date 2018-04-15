//BEGIN PROGRAM HEAD
//BEGIN DESCRIPTION
/* SDL2-GUI-Button
 * Loads surface, creates Texture, checks rect intersection.
 * Press left mouse button to see mouse coordinates.
 * 
 */
//END   DESCRIPTION

//BEGIN INCLUDES
//local headers
#include "helper.h"
//END   INCLUDES

//BEGIN CPP DEFINITIONS
//END   CPP DEFINITIONS

//BEGIN DATASTRUCTURES
//END	DATASTRUCTURES

//BEGIN GLOBALS
//END   GLOBALS

//BEGIN FUNCTION PROTOTYPES
//END	FUNCTION PROTOTYPES

/* DEFINED PROGRESS GOALS
 * 
 * todo todo todo
 *
 */
//END 	PROGRAM HEAD

//BEGIN MAIN FUNCTION
int main(int argc, char *argv[])
{

(void)argc;
(void)argv;

//BEGIN INIT
init();

//create and load surface
SDL_Surface *tempSurface = NULL;
tempSurface=IMG_Load("push.png");
//create and define texture
SDL_Texture *Texture	 = NULL;
Texture = SDL_CreateTextureFromSurface( Renderer, tempSurface );
//get Texture dimensions
int tw, th;
SDL_QueryTexture(Texture, NULL, NULL, &tw, &th);
SDL_Log("tw: %d, th: %d", tw, th);
//clean temp surface
SDL_FreeSurface( tempSurface );

//for mouse position
SDL_Point mouse_coords;
//render rect centered on screen
				//x		    y		    w	h		
SDL_Rect  Texture_dst_rect = {(540/2)-(tw/5/2), (540/2)-(th/5/2), tw/5,th/5};

int r=0; //red part of render color
SDL_SetWindowPosition(Window,0,0);
SDL_SetWindowSize(Window,540,540);
SDL_SetWindowTitle(Window, "SDL 2 - GUI Button");
SDL_ShowWindow(Window);

SDL_Event event;
int running = 1;
//END   INIT

//BEGIN Event Loop
while(running){
//BEGIN EVENT LOOP
	SDL_GetMouseState(&mouse_coords.x,&mouse_coords.y);
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			running = 0;
		}
		if(event.type == SDL_MOUSEBUTTONDOWN){
			if(event.button.button == SDL_BUTTON_LEFT){
				SDL_Log("mouse_coords.x: %d, mouse_coords.y: %d", mouse_coords.x, mouse_coords.y);
			}
			if(event.button.button == SDL_BUTTON_RIGHT){
				;
			}
		}

	}
//END   EVENT LOOP

if (SDL_PointInRect(&mouse_coords,&Texture_dst_rect)){
	SDL_Log("hit!");
	r=255;
}else
	r=0;

//BEGIN RENDERING
SDL_Delay(66);//~15fps
SDL_SetRenderDrawColor(Renderer, 255, 255, 250, 255);
SDL_RenderClear(Renderer);

SDL_RenderCopy(Renderer, Texture, NULL, &Texture_dst_rect);
SDL_SetRenderDrawColor(Renderer, r, 0, 0, 255);
SDL_RenderDrawRect(Renderer,&Texture_dst_rect);
SDL_RenderPresent(Renderer);
//END   RENDERING

}
//END   Event Loop
SDL_DestroyTexture(Texture);
exit_();
return EXIT_SUCCESS;

}
//END   MAIN FUNCTION

//BEGIN FUNCTIONS
//END   FUNCTIONS
