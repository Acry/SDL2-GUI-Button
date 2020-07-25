#pragma GCC diagnostic ignored "-Wunknown-pragmas"
// button.c

#pragma region PROGRAM HEAD
#pragma region DESCRIPTION
/* SDL2-GUI-Button
 * Loads surface, creates Texture, checks rect intersection.
 * Press left mouse button to see mouse coordinates.
 * 
 */
#pragma endregion DESCRIPTION

#pragma region INCLUDES
// local headers
#include "helper.h"
#pragma endregion INCLUDES

/* DEFINED PROGRESS GOALS
 * 
 * todo todo todo
 *
 */
#pragma endregion PROGRAM HEAD

#pragma region MAIN FUNCTION
int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

#pragma region INIT
	init();
	int ww = 400;
	int wh = 200;

	// create and load surface
	SDL_Surface *tempSurface = NULL;
	tempSurface = IMG_Load("push.png");

	// create and define texture
	SDL_Texture *Texture = NULL;
	Texture = SDL_CreateTextureFromSurface(Renderer, tempSurface);
	//clean temp surface
	SDL_FreeSurface(tempSurface);

	// get texture dimensions
	int tw, th;
	SDL_QueryTexture(Texture, NULL, NULL, &tw, &th);

	// scale texture size down
	tw /= 6;
	th /= 6;
	//	set button destination rect centered on screen
	//x		    y		    w	h
	SDL_Rect Texture_dst_rect = {ww / 2 - tw / 2, wh / 2 - th / 2, tw, th};

	int r = 0; //red part of render color
	SDL_SetWindowSize(Window, ww, wh);
	SDL_SetWindowPosition(Window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	SDL_SetWindowTitle(Window, "SDL 2 - GUI Button");
	SDL_ShowWindow(Window);

	SDL_bool background_color_flipped = SDL_FALSE;
	SDL_Point mouse_coords;
	SDL_Event event;
	int running = 1;
#pragma endregion INIT

#pragma region Event Loop
	while (running)
	{
#pragma region EVENT LOOP
		SDL_GetMouseState(&mouse_coords.x, &mouse_coords.y);
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = 0;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					if (SDL_PointInRect(&mouse_coords, &Texture_dst_rect))
					{
						if (background_color_flipped)
							background_color_flipped = SDL_FALSE;
						else
						{
							background_color_flipped = SDL_TRUE;
						}
					}
				}
				if (event.button.button == SDL_BUTTON_RIGHT)
				{
					;
				}
			}
		}
#pragma endregion EVENT LOOP

		if (SDL_PointInRect(&mouse_coords, &Texture_dst_rect))
		{
			r = 255;
		}
		else
			r = 0;

#pragma region RENDERING
		if (background_color_flipped)
			SDL_SetRenderDrawColor(Renderer, GREY);
		else
		{
			SDL_SetRenderDrawColor(Renderer, LTGREY);
		}

		SDL_RenderClear(Renderer);

		SDL_RenderCopy(Renderer, Texture, NULL, &Texture_dst_rect);
		SDL_SetRenderDrawColor(Renderer, r, 0, 0, 255);
		SDL_RenderDrawRect(Renderer, &Texture_dst_rect);
		SDL_RenderPresent(Renderer);
#pragma endregion RENDERING
	}
#pragma endregion Event Loop
	SDL_DestroyTexture(Texture);
	exit_();
	return EXIT_SUCCESS;
}
#pragma endregion MAIN FUNCTION

#pragma region FUNCTIONS
#pragma endregion FUNCTIONS
