#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avg = (image [i] [j].rgbtRed + image [i] [j].rgbtGreen + image [i] [j].rgbtBlue) / 3.0;
            avg = round (avg);
            image [i] [j].rgbtRed = image [i] [j].rgbtGreen = image [i] [j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sepiaRed = 0.393 * image [i] [j].rgbtRed + 0.769 * image [i] [j].rgbtGreen + 0.189 * image [i] [j].rgbtBlue;
            float sepiaGreen = 0.349 * image [i] [j].rgbtRed + 0.686 * image [i] [j].rgbtGreen + 0.168 * image [i] [j].rgbtBlue;
            float sepiaBlue = 0.272 * image [i] [j].rgbtRed + 0.534 * image [i] [j].rgbtGreen + 0.131 * image [i] [j].rgbtBlue;

            sepiaRed = round (sepiaRed);
            sepiaGreen = round (sepiaGreen);
            sepiaBlue = round (sepiaBlue);

            sepiaRed = sepiaRed > 255 ? 255 : sepiaRed;
            sepiaGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
            sepiaBlue = sepiaBlue > 255 ? 255 : sepiaBlue;

            image [i] [j].rgbtRed = sepiaRed;
            image [i] [j].rgbtGreen = sepiaGreen;
            image [i] [j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width - j - 1; j++)
        {
            int tempRed = image [i] [j].rgbtRed;
            int tempGreen = image [i] [j].rgbtGreen;
            int tempBlue = image [i] [j].rgbtBlue;

            image [i] [j].rgbtRed = image [i] [width - j - 1].rgbtRed;
            image [i] [j].rgbtGreen = image [i] [width - j - 1].rgbtGreen;
            image [i] [j].rgbtBlue = image [i] [width - j - 1].rgbtBlue;

            image [i] [width - j - 1].rgbtRed = tempRed;
            image [i] [width - j - 1].rgbtGreen = tempGreen;
            image [i] [width - j - 1].rgbtBlue = tempBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy [height] [width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy [i] [j] = image [i] [j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            int count = 0;

            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if ((k >= 0 && k < height) && (l >= 0 && l < width))
                    {
                        sumRed += copy [k] [l].rgbtRed;
                        sumGreen += copy [k] [l].rgbtGreen;
                        sumBlue += copy [k] [l].rgbtBlue;
                        count ++;
                    }
                }
            }

            float avgRed = sumRed / (float) count;
            float avgGreen = sumGreen / (float) count;
            float avgBlue = sumBlue / (float) count;

            avgRed = round (avgRed);
            avgGreen = round (avgGreen);
            avgBlue = round (avgBlue);

            image [i] [j].rgbtRed = avgRed;
            image [i] [j].rgbtGreen = avgGreen;
            image [i] [j].rgbtBlue = avgBlue;
        }
    }
    return;
}