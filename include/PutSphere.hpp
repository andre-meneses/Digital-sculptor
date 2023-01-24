#ifndef PUTSPHERE_HPP
#define PUTSPHERE_HPP
#include "sculptor.hpp"
#include "FiguraGeometrica.hpp"

class PutSphere : public FiguraGeometrica
{
    protected:
        int xcenter,ycenter,zcenter,radius; //Coordenadas do voxel
        float r,g,b,a; //Cor e transparência
    public:
        ~PutSphere(){};
        PutSphere(int _xcenter = 0, int _ycenter = 0, int _zcenter = 0, int _raio = 1, float _r = 0, float _g = 0, float _b = 0, float _a = 0);
        void draw(Sculptor &t);
};

#endif
