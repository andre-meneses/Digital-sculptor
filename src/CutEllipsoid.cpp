#include "../include/CutEllipsoid.hpp"
#include <iostream>
#include <cmath>

CutEllipsoid::CutEllipsoid(int _xcenter , int _ycenter ,  int _zcenter,  int _raiox,int _raioy, int _raioz)
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    rx = _raiox;
    ry = _raioy;
    rz = _raioz;
}

void CutEllipsoid::draw(Sculptor &t)
{
    for(int i = xcenter - rx; i <= xcenter + rx; i++)
    {
        for(int j = ycenter - ry; j <= ycenter + ry; j++)
        {
            for(int k = zcenter - rz; k <= zcenter + rz; k++){
                if(pow((i - xcenter)/(float)rx,2) + pow((j - ycenter)/(float)ry,2) + pow((k - zcenter)/(float)rz,2) <= 1) 
                {
                    try
                    {
                        t.cutVoxel(i,j,k);
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
