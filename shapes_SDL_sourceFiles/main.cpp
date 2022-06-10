#include <SDL2/SDL.h>
#include <iostream>
#include "Rectangle.h"
#include "circle.h"
#include "square.h"
#include <vector>
#include <numeric>
#include <math.h>

//function for resizing
void resizeAllCircles(std :: vector<Shape*>& cont, double coef)
{
    for(std :: vector<Shape*> :: iterator it = cont.begin(); it != cont.end(); ++it)
    {
        if(dynamic_cast<circle*>(*it))
        {
            double rad = dynamic_cast<circle*>(*it)->getRadius();
            dynamic_cast<circle*>(*it)->setRadius(rad * coef);
        }
    }
}
// void resizeAllRectangles(std :: vector<Shape*>& cont, double coef)
// {

//     for(std :: vector<Shape*> :: iterator it = cont.begin(); it != cont.end(); ++it)
//     {
//         if(dynamic_cast<Rectangle*>(*it) && !dynamic_cast<square*>(*it))
//         {
//             double x = dynamic_cast<Rectangle*>(*it)->getRx();
//             double y = dynamic_cast<Rectangle*>(*it)->getRy();
//             dynamic_cast<Rectangle*>(*it)->setterRec(x + coef, y + (1-coef));
//         }
//     }
// }
int main(int argv, char** args)
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std :: cout <<" Failed to initialize the SDL2 library " << std :: endl;
        return -1;
    }
    SDL_Window * window = SDL_CreateWindow("SDL Window",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    750, 750,
    0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);;
    if(!window)
    {
        std :: cout << " Failed to create window " << std :: endl;
    }

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

    if(!window_surface)
    {
        std :: cout << "Failed to get the surface from the window " << std :: endl;
        return -1;
    }

    SDL_UpdateWindowSurface(window);
    
    bool keep_window_open = true;
    double theArea = 0.0;
    Rectangle *temp = new Rectangle(50, 60, 120, 200);
    circle *temC = new circle(49, 375, 150);
    square *tems = new square(150, 60, 50);
    Rectangle *rec = new Rectangle(0,0,0,0);
    circle *cir = new circle(0,0,0);
    square *sqr = new square(0,0,0);
    std :: vector<Shape*> con;
    con.push_back(temp);
    con.push_back(temC);
    con.push_back(tems);
    std :: vector<Rectangle*> well;
    std :: vector<circle*> well2;
    std :: vector<square*> well3;
    int pop = 0;
    int xstart = 0, ystart = 0;
    int xfin = 0, yfin = 0;
    bool drawing = false;
    SDL_Event e;
    while(keep_window_open)
    {
        
        //SDL_RenderClear(renderer);
        while(SDL_PollEvent(&e) > 0)
        {
            switch(e.type)
            {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
                case SDL_KEYDOWN:
                    switch (e.key.keysym.sym)
                    {
                        case SDLK_r:
                            pop = 1;
                            break;
                        case SDLK_s:
                            pop = 2;
                            break;
                        case SDLK_c:
                            pop = 3;
                            break;
                        case SDLK_ESCAPE:
                            keep_window_open = false;
                            break;
                        case SDLK_DOWN:
                            resizeAllCircles(con, 0.9);
                            break;
                        case SDLK_UP:
                            resizeAllCircles(con, 1.2);
                            break;
                        case SDLK_LEFT:
                            resizeAllRectangles(con, 0.95);
                            break;
                        case SDLK_RIGHT:
                            resizeAllRectangles(con, 1.1);
                            break;

                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                        switch(e.button.button)
                        {
                            case SDL_BUTTON_LEFT:
                                xstart = e.motion.x;
                                ystart = e.motion.y;
                                xfin = e.motion.x;
                                yfin = e.motion.y;
                                drawing = true;
                                break;
                        }
                    break;
                case SDL_MOUSEBUTTONUP:
                    switch(e.button.button)
                        {
                            case SDL_BUTTON_LEFT:
                                switch(pop)
                                {
                                    case 1:
                                        con.push_back(rec);
                                        break;
                                    case 2:
                                        con.push_back(sqr);
                                        break;
                                    case 3:
                                        con.push_back(cir);
                                        break;
                                }
                                drawing = false;	
                                break;
                        }
                    break;
                case SDL_MOUSEMOTION:
                    if(drawing)
                    {
                        xfin = e.motion.x;
                        yfin = e.motion.y;
                        switch(pop)
                                {
                                    case 1:
                                        rec->setterShape(xstart, ystart);
                                        rec->setterRec(xfin, yfin);
                                        well.push_back(rec);
                                        break;
                                    case 2:
                                        sqr->setsqr(xstart, ystart, yfin - ystart);
                                        well3.push_back(sqr);
                                        break;
                                    case 3:
                                        cir->setterShape(xstart, ystart);
                                        cir->setRadius(sqrt(pow((xfin - xstart),2)+ pow((yfin - ystart),2)));
                                        well2.push_back(cir);
                                        break;
                                }
                    }
                    break;
            }
            //SDL_UpdateWindowSurface(window);
        }
        SDL_RenderClear(renderer);
        if(drawing)
        {   
            for(std :: vector<Rectangle*> :: iterator it = well.begin(); it != well.end(); ++it)
            {
                (*it)->draw(renderer, window);
            }
            for(std :: vector<circle*> :: iterator it = well2.begin(); it != well2.end(); ++it)
            {
                (*it)->draw(renderer, window);
            }
            for(std :: vector<square*> :: iterator it = well3.begin(); it != well3.end(); ++it)
            {
                (*it)->draw(renderer, window);
            }
            
        }
        
        for(std :: vector<Shape*> :: iterator it = con.begin(); it != con.end(); ++it)
        {
            (*it)->draw(renderer, window);
        }
        SDL_RenderPresent(renderer);
    }

    //TO DO
    //use <algorithm> for area sum
    theArea = std :: accumulate(con.begin(), con.end(), 0.0,[]( double i, Shape *a){return i + abs(a->area());});
    std :: cout << "The accumulated area is " << abs(temp->area()) << " + " << abs(temC->area()) << " + " << abs(tems->area()) << " + " << abs(rec->area()) << " + " <<
    abs(sqr->area()) << " + " << abs(cir->area()) <<  " = " << theArea << std :: endl;
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    delete temp;
    delete temC;
    delete tems;
    delete rec;
    delete cir;
    delete sqr;
    //delete rec;
    SDL_Quit();
    return 0;
}