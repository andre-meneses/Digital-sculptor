#ifndef CUTBOX
#define CUTBOX
#include "sculptor.hpp"
#include "FiguraGeometrica.hpp"

class CutBox : public FiguraGeometrica
{
    protected:
        int x0,x1,y0,y1,z0,z1; //Coordenadas do voxel
    public:
        ~CutBox(){};
        CutBox(int _x0 = 0, int _x = 1,int _y0 = 0,int _y = 1, int _z0 = 0,int _z = 1);
        void draw(Sculptor &t);
};

#endif
