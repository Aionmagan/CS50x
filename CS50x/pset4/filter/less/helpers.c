#include <math.h>
#include <stdio.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //temp variables
    RGBTRIPLE rgbTemp;
    BYTE grays;

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            rgbTemp = image[i][j];

            //create grayscale value and round it up
            //check for 255 limit with ternary
            //i prefer luma grayscale but cs50 throws a fit
            //grays = round((0.21f * rgbTemp.rgbtRed + 0.72f * rgbTemp.rgbtGreen + 0.07f * rgbTemp.rgbtBlue));
            grays = round((rgbTemp.rgbtRed + rgbTemp.rgbtGreen + rgbTemp.rgbtBlue) / 3.0f);
            grays = grays > 255 ? 255 : grays;

            //inject back in the values for grayscale
            image[i][j].rgbtRed = grays;
            image[i][j].rgbtGreen = grays;
            image[i][j].rgbtBlue = grays;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //temp variables
    RGBTRIPLE rgbTemp;
    int r, g, b;

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            rgbTemp = image[i][j];

            //collecting values for sepia
            r = round((0.393f * rgbTemp.rgbtRed) + (0.769f * rgbTemp.rgbtGreen) + (0.189f * rgbTemp.rgbtBlue));
            g = round((0.349f * rgbTemp.rgbtRed) + (0.686f * rgbTemp.rgbtGreen) + (0.168f * rgbTemp.rgbtBlue));
            b = round((0.272f * rgbTemp.rgbtRed) + (0.534f * rgbTemp.rgbtGreen) + (0.131f * rgbTemp.rgbtBlue));

            //checking limit with terany
            r = r > 255 ? 255 : r;
            g = g > 255 ? 255 : g;
            b = b > 255 ? 255 : b;

            //injecting values back in
            image[i][j].rgbtRed = r;
            image[i][j].rgbtGreen = g;
            image[i][j].rgbtBlue = b;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //temp variables, was thinking of using pointer to pointer (**temp)
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0, k = width - 1; j < width; ++j, --k)
        {
            //store image in temp in reverse width
            //but repecting height
            temp[i][k] = image[i][j];
        }
    }

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            //put temp reversed image back in to
            //original arry images
            image[i][j] = temp[i][j];
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int avarage = 0;
    int r, g, b;
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; ++i)
    {
        /* getting pixels around
         * center pixel
         * X X X
         * X p X
         * X X X
         */

        for (int j = 0; j < width; ++j)
        {
            avarage = 0;
            //center pixel
            r = 0;
            g = 0;
            b = 0;

        
            //collding center and all surounding pixels
            for (int row = -1; row < 2; ++row)
            {
                for (int col = -1; col < 2; ++col)
                {
                    if (i + row < 0 || j + col < 0 || i + row >= height || j + col >= width)
                    {
                        continue;
                    }
                    
                    avarage++;

                    r += temp[i + row][j + col].rgbtRed;
                    g += temp[i + row][j + col].rgbtGreen;
                    b += temp[i + row][j + col].rgbtBlue;
                    
                }
            }
            

            image[i][j].rgbtRed   = round(r / (float)avarage);
            image[i][j].rgbtGreen = round(g / (float)avarage);
            image[i][j].rgbtBlue  = round(b / (float)avarage);
        }
    }

    return;
}
