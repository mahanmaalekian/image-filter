#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmp[i][j] = image[i][j];
        }
    }
    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            tmp[i][j].rgbtRed = round((image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
                                       image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                       image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) /
                                      9.0);

            tmp[i][j].rgbtGreen =
                round((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                       image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                       image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) /
                      9.0);

            tmp[i][j].rgbtBlue = round((image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                                        image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                                        image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) /
                                       9.0);
        }
    }

    // vertical edges
    for (int i = 1; i < height - 1; i++)
    {
        tmp[i][0].rgbtRed = round((image[i - 1][0].rgbtRed + image[i][0].rgbtRed + image[i + 1][0].rgbtRed +
                                   image[i - 1][1].rgbtRed + image[i][1].rgbtRed + image[i + 1][1].rgbtRed) /
                                  6.0);
        tmp[i][0].rgbtGreen = round((image[i - 1][0].rgbtGreen + image[i][0].rgbtGreen + image[i + 1][0].rgbtGreen +
                                     image[i - 1][1].rgbtGreen + image[i][1].rgbtGreen + image[i + 1][1].rgbtGreen) /
                                    6.0);
        tmp[i][0].rgbtBlue = round((image[i - 1][0].rgbtBlue + image[i][0].rgbtBlue + image[i + 1][0].rgbtBlue +
                                    image[i - 1][1].rgbtBlue + image[i][1].rgbtBlue + image[i + 1][1].rgbtBlue) /
                                   6.0);

        tmp[i][width - 1].rgbtRed =
            round((image[i - 1][width - 1].rgbtRed + image[i][width - 1].rgbtRed + image[i + 1][width - 1].rgbtRed +
                   image[i - 1][width - 2].rgbtRed + image[i][width - 2].rgbtRed + image[i + 1][width - 2].rgbtRed) /
                  6.0);
        tmp[i][width - 1].rgbtGreen =
            round((image[i - 1][width - 1].rgbtGreen + image[i][width - 1].rgbtGreen + image[i + 1][width - 1].rgbtGreen +
                   image[i - 1][width - 2].rgbtGreen + image[i][width - 2].rgbtGreen + image[i + 1][width - 2].rgbtGreen) /
                  6.0);
        tmp[i][width - 1].rgbtBlue =
            round((image[i - 1][width - 1].rgbtBlue + image[i][width - 1].rgbtBlue + image[i + 1][width - 1].rgbtBlue +
                   image[i - 1][width - 2].rgbtBlue + image[i][width - 2].rgbtBlue + image[i + 1][width - 2].rgbtBlue) /
                  6.0);
    }

    // horizontal edges
    for (int i = 1; i < width - 1; i++)
    {
        tmp[0][i].rgbtRed = round((image[0][i - 1].rgbtRed + image[0][i].rgbtRed + image[0][i + 1].rgbtRed +
                                   image[1][i - 1].rgbtRed + image[1][i].rgbtRed + image[1][i + 1].rgbtRed) /
                                  6.0);
        tmp[0][i].rgbtGreen = round((image[0][i - 1].rgbtGreen + image[0][i].rgbtGreen + image[0][i + 1].rgbtGreen +
                                     image[1][i - 1].rgbtGreen + image[1][i].rgbtGreen + image[1][i + 1].rgbtGreen) /
                                    6.0);
        tmp[0][i].rgbtBlue = round((image[0][i - 1].rgbtBlue + image[0][i].rgbtBlue + image[0][i + 1].rgbtBlue +
                                    image[1][i - 1].rgbtBlue + image[1][i].rgbtBlue + image[1][i + 1].rgbtBlue) /
                                   6.0);

        tmp[height - 1][i].rgbtRed =
            round((image[height - 1][i - 1].rgbtRed + image[height - 1][i].rgbtRed + image[height - 1][i + 1].rgbtRed +
                   image[height - 2][i - 1].rgbtRed + image[height - 2][i].rgbtRed + image[height - 2][i + 1].rgbtRed) /
                  6.0);
        tmp[height - 1][i].rgbtGreen =
            round((image[height - 1][i - 1].rgbtGreen + image[height - 1][i].rgbtGreen + image[height - 1][i + 1].rgbtGreen +
                   image[height - 2][i - 1].rgbtGreen + image[height - 2][i].rgbtGreen + image[height - 2][i + 1].rgbtGreen) /
                  6.0);
        tmp[height - 1][i].rgbtBlue =
            round((image[height - 1][i - 1].rgbtBlue + image[height - 1][i].rgbtBlue + image[height - 1][i + 1].rgbtBlue +
                   image[height - 2][i - 1].rgbtBlue + image[height - 2][i].rgbtBlue + image[height - 2][i + 1].rgbtBlue) /
                  6.0);
    }
    // top left corner
    tmp[0][0].rgbtRed = round((image[0][0].rgbtRed + image[0][1].rgbtRed + image[1][1].rgbtRed + image[1][0].rgbtRed) / 4.0);
    tmp[0][0].rgbtGreen =
        round((image[0][0].rgbtGreen + image[0][1].rgbtGreen + image[1][1].rgbtGreen + image[1][0].rgbtGreen) / 4.0);
    tmp[0][0].rgbtBlue = round((image[0][0].rgbtBlue + image[0][1].rgbtBlue + image[1][1].rgbtBlue + image[1][0].rgbtBlue) / 4.0);

    // top right corner
    tmp[0][width - 1].rgbtRed = round(
        (image[0][width - 1].rgbtRed + image[0][width - 2].rgbtRed + image[1][width - 1].rgbtRed + image[1][width - 2].rgbtRed) /
        4.0);
    tmp[0][width - 1].rgbtGreen = round((image[0][width - 1].rgbtGreen + image[0][width - 2].rgbtGreen +
                                         image[1][width - 1].rgbtGreen + image[1][width - 2].rgbtGreen) /
                                        4.0);
    tmp[0][width - 1].rgbtBlue = round((image[0][width - 1].rgbtBlue + image[0][width - 2].rgbtBlue + image[1][width - 1].rgbtBlue +
                                        image[1][width - 2].rgbtBlue) /
                                       4.0);

    // bottom left corner
    tmp[height - 1][0].rgbtRed = round((image[height - 1][0].rgbtRed + image[height - 2][0].rgbtRed + image[height - 1][1].rgbtRed +
                                        image[height - 2][1].rgbtRed) /
                                       4.0);
    tmp[height - 1][0].rgbtGreen = round((image[height - 1][0].rgbtGreen + image[height - 2][0].rgbtGreen +
                                          image[height - 1][1].rgbtGreen + image[height - 2][1].rgbtGreen) /
                                         4.0);
    tmp[height - 1][0].rgbtBlue = round((image[height - 1][0].rgbtBlue + image[height - 2][0].rgbtBlue +
                                         image[height - 1][1].rgbtBlue + image[height - 2][1].rgbtBlue) /
                                        4.0);

    // bottom right corner
    tmp[height - 1][width - 1].rgbtRed = round((image[height - 1][width - 1].rgbtRed + image[height - 2][width - 1].rgbtRed +
                                                image[height - 1][width - 2].rgbtRed + image[height - 2][width - 2].rgbtRed) /
                                               4.0);
    tmp[height - 1][width - 1].rgbtGreen = round((image[height - 1][width - 1].rgbtGreen + image[height - 2][width - 1].rgbtGreen +
                                                  image[height - 1][width - 2].rgbtGreen + image[height - 2][width - 2].rgbtGreen) /
                                                 4.0);
    tmp[height - 1][width - 1].rgbtBlue = round((image[height - 1][width - 1].rgbtBlue + image[height - 2][width - 1].rgbtBlue +
                                                 image[height - 1][width - 2].rgbtBlue + image[height - 2][width - 2].rgbtBlue) /
                                                4.0);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tmp[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    RGBTRIPLE tmp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmp[i][j] = image[i][j];
        }
    }
    int gxRed, gyRed, gxGreen, gyGreen, gxBlue, gyBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            gxRed = 0;
            gyRed = 0;
            gxGreen = 0;
            gyGreen = 0;
            gxBlue = 0;
            gyBlue = 0;

            for (int m = 0; m < 3; m++)
            {
                for (int n = 0; n < 3; n++)
                {
                    if ((i - 1 + m) >= 0 && (i - 1 + m) <= height - 1 && (j - 1 + n) >= 0 && (j - 1 + n) <= width - 1)
                    {
                        gxRed += image[i - 1 + m][j - 1 + n].rgbtRed * gx[m][n];
                        gxGreen += image[i - 1 + m][j - 1 + n].rgbtGreen * gx[m][n];
                        gxBlue += image[i - 1 + m][j - 1 + n].rgbtBlue * gx[m][n];
                        gyRed += image[i - 1 + m][j - 1 + n].rgbtRed * gx[n][m];
                        gyGreen += image[i - 1 + m][j - 1 + n].rgbtGreen * gx[n][m];
                        gyBlue += image[i - 1 + m][j - 1 + n].rgbtBlue * gx[n][m];
                    }
                }
            }
            if (sqrt((double) (gxRed * gxRed + gyRed * gyRed)) > 255)
            {
                tmp[i][j].rgbtRed = 255;
            }
            else
            {
                tmp[i][j].rgbtRed = round(sqrt((double) (gxRed * gxRed + gyRed * gyRed)));
            }

            if (sqrt((double) (gxGreen * gxGreen + gyGreen * gyGreen)) > 255)
            {
                tmp[i][j].rgbtGreen = 255;
            }
            else
            {
                tmp[i][j].rgbtGreen = round(sqrt((double) (gxGreen * gxGreen + gyGreen * gyGreen)));
            }

            if (sqrt((double) (gxBlue * gxBlue + gyBlue * gyBlue)) > 255)
            {
                tmp[i][j].rgbtBlue = 255;
            }
            else
            {
                tmp[i][j].rgbtBlue = round(sqrt((double) gxBlue * gxBlue + gyBlue * gyBlue));
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tmp[i][j];
        }
    }

    return;
}
