//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

//  Screen dimensions
const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;

// Constants for directional keypress surfaces
enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

const char* media[5]{ "default.bmp", "up.bmp", "down.bmp","left.bmp","right.bmp" };
//  Start SDL and create window
bool initSDL();

//  Load media
bool loadMedia();

// Frees media and shuts down SDL
void close();

void deallocateSurfaces();

// Load an image
SDL_Surface* loadSurface(std::string path);

//  The window we will render to
SDL_Window* gWindow = NULL;
// The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
//Current displayed image
SDL_Surface* gCurrentSurface = NULL;

/*An SDL surface is just an image data type that contains the pixels
of an image along with all data needed to render it. SDL surfaces use
software rendering which means it uses the CPU to render. It is possible
to render hardware images but it's a bit more difficult so we're going
to learn it the easy way first.*/

bool initSDL()
{
	//  Initialisation flag
	bool success = true;

	//  Intiialise SDL - Returns 0 on success or a negative error code on failure
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL did not initialise, SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//  Create our window
		gWindow = SDL_CreateWindow("My First Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window was not created, SDL_Error(): %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			int imgFlags = IMG_INIT_PNG;
			// Initialise PNG loading
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL Image did not initialise, SDL Image Error: %s", IMG_GetError());
				success = false;
			}
			else
			{
				//  Get the window surface
				gScreenSurface = SDL_GetWindowSurface(gWindow);
			}
		}
	}
	return success;
}
bool loadMedia()
{
	//  Success flag
	bool success = true;

	//  Load keypress images
	for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i)
	{
		gKeyPressSurfaces[i] = loadSurface(media[i]);
		if (gKeyPressSurfaces[i] == NULL)
		{
			printf("Failed to load default image!\n");
			success = false;
		}
	}
	return success;
}
void close()
{
	// Deallocate surfaces
	deallocateSurfaces();

	// Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	// Quit SDL subsystems
	SDL_Quit();
}
void deallocateSurfaces()
{
	for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i)
	{
		SDL_FreeSurface(gKeyPressSurfaces[i]);
		gKeyPressSurfaces[i] = NULL;
	}
}

SDL_Surface* loadSurface(std::string path)
{
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL) printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
	return loadedSurface;
}

int main(int argc, char* args[])
{
	// Start up SDL and create window
	if (!initSDL())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		// Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			// Main loop flag
			bool quit = false;

			// Event Handler
			SDL_Event event;

			//Set default current surface
			gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

			// While the application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&event) != 0)
				{
					//User requests quit
					if (event.type == SDL_QUIT)
					{
						quit = true;
					}
					//User presses a key
					else if (event.type == SDL_KEYDOWN)
					{
						//Select surfaces based on key press
						switch (event.key.keysym.sym)
						{
						case SDLK_UP:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
							break;

						case SDLK_DOWN:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
							break;

						case SDLK_LEFT:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
							break;

						case SDLK_RIGHT:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
							break;

						default:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
							break;
						}
					}
				}
				// Apply the image
				SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);

				// Update the surface
				SDL_UpdateWindowSurface(gWindow);
			}

		}
	}

	// Free resources and close SDL
	close();

	return 0;
}