#ifndef PUTELLIPSOID_HPP
#define PUTELLIPSOID_HPP
#include "sculptor.hpp"
#include "FiguraGeometrica.hpp"

class PutEllipsoid : public FiguraGeometrica
{
    protected:
        int xcenter,ycenter,zcenter,rx,ry,rz; //Coordenadas do voxel
        float r,g,b,a; //Cor e transparência
    public:
        ~PutEllipsoid(){};
        PutEllipsoid(int _xcenter = 0, int _ycenter = 0, int _zcenter = 0, int _raiox = 1,int _raioy = 1, int _raioz = 1, float _r = 0, float _g = 0, float _b = 0, float _a = 0);
        void draw(Sculptor &t);
};

#endif
