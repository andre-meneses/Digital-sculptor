#include "../include/CutBox.hpp"
#include <iostream>

CutBox::CutBox(int _x0 ,int _x, int _y0 ,int _y,  int _z0, int _z)
{
    x0 = _x0;
    x1 = _x;
    y0 = _y0;
    y1 = _y;
    z0 = _z0;
    z1 = _z;
    x0 = _x0;
}

void CutBox::draw(Sculptor &t)
{
    for(int i = x0; i <= x1; i++)
    {
        for(int j = y0; j <= y1; j++)
        {
            for(int k = z0; k <= z1; k++)
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
