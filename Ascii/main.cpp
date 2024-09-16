#include <iostream>
#include <unistd.h>

[[noreturn]] int main()
{
    //variables
    const int width = 64;
    const int height = 20;
    int currentLine = 0;
    std::string palette[8]={" ",".",",", "/", "\\", "[", "]", "|"};
    int screen[width * height];
    std::string final[width * height];

    //update
    while(true)
    {
        //set bottom layer
        for(int i = 0; i <= width-1; i++)
        {
            screen[i] = rand()%5+3;
            if(screen[i]<=4)
            {
                screen[i]=0;
            }
            //std::cout << palette[screen[i]];
        }
        //set higher layers
        for (int i = width; i < width*height; i++)
        {
            //new line and decrease brightness
            /*if (i%width == 0)
            {
                std::cout << std::endl;

            }*/

            if(i%width != 0 || i%width != width-1 && i<width*height-width)
            {
                screen[i] = (
                            screen[i]+
                            screen[i + 1]+
                            screen[i-1]+
                            screen[i-width]+
                            screen[i-width+1]+
                            screen[i-width-1]
                            )/5.4;
            }
            if(i%width == 0)
            {
                screen[i] = (screen[i-width]+
                             screen[i-width+1]
                            )/3;
            }
            if(i%width == width-1)
            {
                screen[i] = (screen[i-width]+
                             screen[i-width-1]
                            )/3;
            }

            //std::cout << palette[screen[i]%8];
        }
        for(int i = width*height; i > 1; i--)
        {
            if(i%width == 0)
            {
                currentLine += 1;
                std::cout << std::endl;
            }
            std::cout << palette[screen[i]%8];

        }
        usleep(50000);
        system("clear");
        currentLine = 0;
    }
}
