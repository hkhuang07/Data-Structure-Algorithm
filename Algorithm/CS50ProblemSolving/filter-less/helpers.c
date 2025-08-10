#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Loop over all pixels
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            //Take average of red, green and blue
            float avg = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
                //Round avage
                if(avg > ((avg/1)+0.5))
                {
                    avg = (avg/1)+1;
                }
                else
                {
                    avg = (avg/1);
                }
            //Update pixel values
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //Loop over all pixels
    for(int i=0; i< height; i++)
    {
        for(int j=0; j<width; j++)
        {
            //Computer sepia values
            float sepiaRed = 0.393*image[i][j].rgbtRed + 0.769*image[i][j].rgbtGreen + 0.189*image[i][j].rgbtBlue;
            float sepiaGreen = 0.349*image[i][j].rgbtRed + 0.686*image[i][j].rgbtGreen + 0.168*image[i][j].rgbtBlue;
            float sepiaBlue = 0.272*image[i][j].rgbtRed + 0.534*image[i][j].rgbtGreen + 0.131*image[i][j].rgbtBlue;
            //Round the number to the nearest whole number
            if(sepiaRed > (sepiaRed/1)+0.5)
            {
                sepiaRed = (sepiaRed/1)+1;
            }
            else
            {
                sepiaRed = (sepiaRed/1);
            }
            if(sepiaGreen > (sepiaGreen/1)+0.5)
            {
                sepiaGreen = (sepiaGreen/1)+1;
            }
            else
            {
                sepiaGreen = (sepiaGreen/1);
            }
            if(sepiaBlue > (sepiaBlue/1)+0.5)
            {
                sepiaBlue = (sepiaBlue/1)+1;
            }
            else
            {
                sepiaBlue = (sepiaBlue/1);
            }
            //Case the number greather than 255
            if (sepiaRed > 255)
            {
                sepiaRed =255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen =255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue =255;
            }
            //Update pixel with sepia values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Loop over all pixels
    for(int i=0; i<height; i++)
    {
       int left=0;
       int right =width-1;
       while(left < right)
       {
            RGBTRIPLE tmp = image[i][left];
            image[i][left] = image[i][right];
            image[i][right] = tmp;
            left++;
            right--;
       }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Create a copy of image
    RGBTRIPLE copy[height][width];
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width;j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    /*Compute blur values
    float blurRed =
    float blurGreen =
    float blurBlue =
    */

    //Update pixel with sepia values
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            image[i][j].rgbtRed = (copy[i-1][j-1].rgbtRed + copy[i-1][j].rgbtRed + copy[i-1][j+1].rgbtRed +
                                  copy[i][j-1].rgbtRed + copy[i][j].rgbtRed + copy[i][j+1].rgbtRed +
                                  copy[i+1][j-1].rgbtRed + copy[i+1][j].rgbtRed + copy[i+1][j+1].rgbtRed)/9 ;
            image[i][j].rgbtGreen = (copy[i-1][j-1].rgbtGreen + copy[i-1][j].rgbtGreen + copy[i-1][j+1].rgbtGreen +
                                    copy[i][j-1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j+1].rgbtGreen +
                                    copy[i+1][j-1].rgbtGreen + copy[i+1][j].rgbtGreen + copy[i+1][j+1].rgbtGreen)/9 ;
            image[i][j].rgbtBlue = (copy[i-1][j-1].rgbtBlue + copy[i-1][j].rgbtBlue + copy[i-1][j+1].rgbtBlue +
                                  copy[i][j-1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j+1].rgbtBlue +
                                  copy[i+1][j-1].rgbtBlue + copy[i+1][j].rgbtBlue + copy[i+1][j+1].rgbtBlue)/9 ;
        }
    }
    return;
}
