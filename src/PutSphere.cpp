#include "../include/PutSphere.hpp"
#include <cmath>
#include <iostream>

PutSphere::PutSphere(int _xcenter , int _ycenter ,  int _zcenter,  int _raio, float _r , float _g , float _b , float _a )
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    radius = _raio;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

void PutSphere::draw(Sculptor &t)
{
    t.setColor(r,g,b,a);

    for(int i = xcenter - radius; i <= xcenter + radius; i++)
    {
        for(int j = ycenter - radius; j <= ycenter + radius; j++)
        {
            for(int k = zcenter - radius; k <= zcenter + radius; k++){
                if(pow((i - xcenter),2) + pow((j - ycenter),2) + pow((k - zcenter),2) <= pow(radius,2)) 
                {
                    try
                    {
                        t.putVoxel(i,j,k);
                    }
                    catch(const char *e)
                    {
                        std::cout << "Error: " << e << std::endl;
                    }
                }
            }
        }
    }
    
}
