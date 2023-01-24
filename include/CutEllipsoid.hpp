#ifndef CUTELLIPSOID_HPP
#define CUTELLIPSOID_HPP
#include "sculptor.hpp"
#include "FiguraGeometrica.hpp"

class CutEllipsoid : public FiguraGeometrica
{
    protected:
        int xcenter,ycenter,zcenter,rx,ry,rz; //Coordenadas do voxel
    public:
        ~CutEllipsoid(){};
        CutEllipsoid(int _xcenter = 0, int _ycenter = 0, int _zcenter = 0, int _raiox = 1,int _raioy = 1, int _raioz = 1);
        void draw(Sculptor &t);
};

#endif
