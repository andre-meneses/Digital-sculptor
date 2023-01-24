#include "../include/CutSphere.hpp"
#include <iostream>
#include <cmath>

CutSphere::CutSphere(int _xcenter , int _ycenter ,  int _zcenter,  int _raio)
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    radius = _raio;
}

void CutSphere::draw(Sculptor &t)
{
    for(int i = xcenter - radius; i <= xcenter + radius; i++)
    {
        for(int j = ycenter - radius; j <= ycenter + radius; j++)
        {
            for(int k = zcenter - radius; k <= zcenter + radius; k++){
                if(pow((i - xcenter),2) + pow((j - ycenter),2) + pow((k - zcenter),2) <= pow(radius,2)) 
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
