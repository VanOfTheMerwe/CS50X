#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // dog is for rows
    // cat is for columns
    for (int dog = 0; dog < height; dog++)
    {
        for (int cat = 0; cat < width; cat++)
        {
            RGBTRIPLE house = image[dog][cat];

            // temp is for average
            int temp = round((float) (house.rgbtBlue + house.rgbtGreen + house.rgbtRed) / 3);

            image[dog][cat].rgbtBlue = temp;
            image[dog][cat].rgbtGreen = temp;
            image[dog][cat].rgbtRed = temp;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int dog = 0; dog < height; dog++)
    {
        for (int cat = 0; cat < width; cat++)
        {
            int red = image[dog][cat].rgbtRed;
            int blue = image[dog][cat].rgbtBlue;
            int green = image[dog][cat].rgbtGreen;

            //? What is the new sepia value?
            //*Sepia Red Value
            int sR = round(0.393 * red + 0.769 * green + 0.189 * blue);
            if (sR > 255)
            {
                image[dog][cat].rgbtRed = 255;
            }
            else
            {
                image[dog][cat].rgbtRed = sR;
            }
            //*Sepia Green Value
            int sG = round(0.349 * red + 0.686 * green + 0.168 * blue);
            if (sG > 255)
            {
                image[dog][cat].rgbtGreen = 255;
            }
            else
            {
                image[dog][cat].rgbtGreen = sG;
            }
            //*Sepia Blue Value
            int sB = round(0.272 * red + 0.534 * green + 0.131 * blue);
            if (sB > 255)
            {
                image[dog][cat].rgbtBlue = 255;
            }
            else
            {
                image[dog][cat].rgbtBlue = sB;
            }
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[1][1];
    int laaste = width;
    int eerste = 0;

    for (int dog = 0; dog < height; dog++)
    {
        laaste = width - 1;
        eerste = 0;

        for (int cat = 0; cat < width / 2; cat++)
        {
            temp[0][0] = image[dog][eerste];
            image[dog][eerste] = image[dog][laaste];
            image[dog][laaste] = temp[0][0];

            laaste--;
            eerste++;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_blur[height][width];

    for (int dog = 0; dog < height; dog++)
    {
        for (int cat = 0; cat < width; cat++)
        {
            float avgR = 0, avgG = 0, avgB = 0;
            int count = 0;

            for (int puppy = -1; puppy <= 1; puppy++)
            {
                for (int kitten = -1; kitten <= 1; kitten++)
                {
                    int doggos = dog + puppy;
                    int kattens = cat + kitten;

                    if (doggos >= 0 && doggos < height && kattens >= 0 && kattens < width)
                    {
                        avgR += image[doggos][kattens].rgbtRed;
                        avgG += image[doggos][kattens].rgbtGreen;
                        avgB += image[doggos][kattens].rgbtBlue;
                        count++;
                    }
                }
            }

            image_blur[dog][cat].rgbtRed = round(avgR / count);
            image_blur[dog][cat].rgbtGreen = round(avgG / count);
            image_blur[dog][cat].rgbtBlue = round(avgB / count);
        }
    }

    // Copy blurred image back to original image
    for (int dog = 0; dog < height; dog++)
    {
        for (int cat = 0; cat < width; cat++)
        {
            image[dog][cat] = image_blur[dog][cat];
        }
    }
}
