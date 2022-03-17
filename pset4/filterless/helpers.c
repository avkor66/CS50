#include "helpers.h"
#include <cs50.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i =0; i<height; i++)
    {
        // printf("\n\t");
        for (int j =0; j<width; j++)
        {
        // printf("%i:%i:%i=", image[i][j].rgbtBlue, image[i][j].rgbtGreen, image[i][j].rgbtRed);
        // printf("%#02x%x%x ", image[i][j].rgbtBlue, image[i][j].rgbtGreen, image[i][j].rgbtRed);
        int aver = 0;
        aver = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3;
        image[i][j].rgbtBlue = aver;
        image[i][j].rgbtGreen = aver;
        image[i][j].rgbtRed = aver;
        // printf("%i:%i:%i=", image[i][j].rgbtBlue, image[i][j].rgbtGreen, image[i][j].rgbtRed);
        // printf("%#02x%x%x ", image[i][j].rgbtBlue, image[i][j].rgbtGreen, image[i][j].rgbtRed);

        }
    }
        // printf("\n");

    // printf("%i\n", image[34][34].rgbtBlue);
    // printf("%i\n", image[34][34].rgbtGreen);
    // printf("%i\n", image[34][34].rgbtRed);
    // printf("%04x\n", image[34][34].rgbtBlue);
    // printf("%04x\n", image[34][34].rgbtGreen);
    // printf("%04x\n", image[34][34].rgbtRed);
    // printf("%x\n", image[34][34].rgbtBlue);
    // printf("%x\n", image[34][34].rgbtGreen);
    // printf("%x\n", image[34][34].rgbtRed);
    // printf("%#x\n", image[34][34].rgbtBlue);
    // printf("%#x\n", image[34][34].rgbtGreen);
    // printf("%#x\n", image[34][34].rgbtRed);
    // printf("%#.2x\n", image[100][34].rgbtBlue);
    // printf("%#.2x\n", image[200][34].rgbtGreen);
    // printf("%#.2x\n", image[300][34].rgbtRed);
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i =0; i<height; i++)
    {
        for (int j =0; j<width; j++)
        {
            int sepiaRed = (0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue);
            int sepiaGreen = (0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue);
            int sepiaBlue = (0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue);

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
            if (sepiaRed >255)
            {
                image[i][j].rgbtRed = 255;
                //printf("ijred %i", sepiaRed);
            }
            if (sepiaGreen >255)
            {
                image[i][j].rgbtGreen = 255;
                //printf("ijgreen %i", sepiaGreen);
            }
            if (sepiaBlue >255)
            {
                image[i][j].rgbtBlue = 255;
                //printf("ijblue %i", sepiaBlue);
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i =0; i<height; i++)
    {
        for (int j =1; j<=width/2; j++)
        {
        int temp = image[i][j].rgbtRed;
        image[i][j].rgbtRed = image[i][width-j].rgbtRed;
        image[i][width-j].rgbtRed = temp;
        temp = image[i][j].rgbtGreen;
        image[i][j].rgbtGreen = image[i][width-j].rgbtGreen;
        image[i][width-j].rgbtGreen = temp;
        temp = image[i][j].rgbtBlue;
        image[i][j].rgbtBlue = image[i][width-j].rgbtBlue;
        image[i][width-j].rgbtBlue = temp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i<height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i==0 && j != 0 && i != height-1 && j != width-1)
            {
                image[i][j].rgbtRed = ((image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed)/6);
                image[i][j].rgbtGreen = ((image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen)/6);
                image[i][j].rgbtBlue = ((image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue)/6);
            }
            else if (i==0 && j == 0)
            {
                image[i][j].rgbtRed = (image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed) / 4;
                image[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen) / 4;
                image[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue) / 4;
            }
            else if (j==0 && i != 0 && i != height-1 && j != width-1)
            {
                image[i][j].rgbtRed = (image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed) / 6;
                image[i][j].rgbtGreen = (image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen) / 6;
                image[i][j].rgbtBlue = (image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue) / 6;
            }
            else if (j!=0 && i != 0 && i == height-1 && j != width-1)
            {
                image[i][j].rgbtRed = (image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed) / 6;
                image[i][j].rgbtGreen = (image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen) / 6;
                image[i][j].rgbtBlue = (image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue) / 6;
            }
            else if (j !=0 && i != 0 && i != height-1 && j == width-1)
            {
                image[i][j].rgbtRed = (image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed) / 6;
                image[i][j].rgbtGreen = (image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen) / 6;
                image[i][j].rgbtBlue = (image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue) / 6;
            }
            else if (i == height-1 && j == width-1)
            {
                image[i][j].rgbtRed = (image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j].rgbtRed) / 4;
                image[i][j].rgbtGreen = (image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j].rgbtGreen) / 4;
                image[i][j].rgbtBlue = (image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j].rgbtBlue) / 4;
            }
            else if (j !=0 && i != 0 && i != height-1 && j != width-1)
            {
                image[i][j].rgbtRed = (image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed+ image[i+1][j+1].rgbtRed) / 9;
                image[i][j].rgbtGreen = (image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen) / 9;
                image[i][j].rgbtBlue = (image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue) / 9;
            }
        }
    }



    return;
}
