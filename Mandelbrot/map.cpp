#include <iostream>
using namespace std;
void GroundColorMix(int* color,int x, int min, int max){
    int posSlope = (int) (max-min)/60;
    int negSlope =(int) (min-max)/60;

    if( x < 60 )
    {
        color[0] = max;
        color[1] = posSlope*x+min;
        color[2] = min;
        return ;
    }
    else if ( x < 120 )
    {
        color[0] = negSlope*x+2*max+min;
        color[1] = max;
        color[2] = min;
        return ;
    }
    else if ( x < 180  )
    {
        color[0] = min;
        color[1] = max;
        color[2] = posSlope*x-2*max+min;
        return;
    }
    else if ( x < 240  )
    {
        color[0] = min;
        color[1] = negSlope*x+4*max+min;
        color[2] = max;
        return ;
    }else
    {
        color[0] = max;
        color[1] = min;
        color[2] = negSlope*x+6*max;
        return ;
    }
}
