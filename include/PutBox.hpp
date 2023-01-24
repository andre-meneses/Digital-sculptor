#ifndef PUTBOX
#define PUTBOX
#include "sculptor.hpp"
#include "FiguraGeometrica.hpp"

class PutBox : public FiguraGeometrica
{
    protected:
        int x1,x0,y1,y0,z1,z0; //Coordenadas do voxel
        float r,g,b,a; //Cor e transparência
    public:
        ~PutBox(){};
        PutBox(int _x0 = 0, int _x = 1,int _y0 = 0,int _y = 1, int _z0 = 0,int _z = 1, float _r = 0, float _g = 0, float _b = 0, float _a = 0);
        void draw(Sculptor &t);
};

#endif
