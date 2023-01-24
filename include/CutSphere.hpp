#ifndef CUTSPHERE_HPP
#define CUTSPHERE_HPP
#include "sculptor.hpp"
#include "FiguraGeometrica.hpp"

class CutSphere : public FiguraGeometrica
{
    protected:
        int xcenter,ycenter,zcenter,radius; //Coordenadas do voxel
    public:
        ~CutSphere(){};
        CutSphere(int _xcenter = 0, int _ycenter = 0, int _zcenter = 0, int _raio = 1);
        void draw(Sculptor &t);
};

#endif
