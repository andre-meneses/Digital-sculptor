#include "../include/PutEllipsoid.hpp"
#include <iostream>
#include <cmath>

PutEllipsoid::PutEllipsoid(int _xcenter , int _ycenter ,  int _zcenter,  int _raiox,int _raioy, int _raioz, float _r , float _g , float _b , float _a )
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    rx = _raiox;
    ry = _raioy;
    rz = _raioz;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

void PutEllipsoid::draw(Sculptor &t)
{
    t.setColor(r,g,b,a);

    for(int i = xcenter - rx; i <= xcenter + rx; i++)
    {
        for(int j = ycenter - ry; j <= ycenter + ry; j++)
        {
            for(int k = zcenter - rz; k <= zcenter + rz; k++){
                if(pow((i - xcenter)/(float)rx,2) + pow((j - ycenter)/(float)ry,2) + pow((k - zcenter)/(float)rz,2) <= 1) 
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
