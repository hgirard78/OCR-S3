#include "SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include "SDL2/SDL_image.h"
#include "pixel_operations.h"
#include "color_operations.h"

//Transform the picture in a grey scale
void grey_scale(SDL_Surface *picture){
    Uint32 pixel;
    for (int i = 0; i < picture->w; i++){
        for (int j = 0; j < picture->h; j++){
            Uint8 r, g, b;
            //Get the pixel of the picture thanks to his coordinates
            pixel = get_pixel(picture, i, j);
            //Get the color in RGB of the pixel
            SDL_GetRGB(pixel, picture->format, &r, &g, &b);
            Uint32 average = 0.3 * r + 0.59 * g + 0.11 * b;
            r = b = g = average;
            //Set the new color in the pixel
            pixel = SDL_MapRGB(picture->format, r, g, b);
            //Replace the old pixel by this new one
            set_pixel(picture, i, j, pixel);
        }
    }
}

//Transform the picture in black and white
//Same procedure as grey_scale
void black_white(SDL_Surface *picture){ 
    Uint32 pixel;
    for (int i = 0; i < picture->w; i++){
        for (int j = 0; j < picture->h; j++){
            Uint8 r, g, b;
            pixel = get_pixel(picture, i, j);
            SDL_GetRGB(pixel, picture->format, &r, &g, &b);
            if (r > 255 / 2)
                r = 255;
            else
                r = 0;
            if (g > 255 / 2)
                g = 255;
            else
                g = 0;
            if (b > 255 / 2)
                b = 255;
            else
                b = 0;
            pixel = SDL_MapRGB(picture->format, r, g, b);
            set_pixel(picture, i, j, pixel);
        }
    } 
}

