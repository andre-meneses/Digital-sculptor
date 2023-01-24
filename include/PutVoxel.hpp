#ifndef PUTVOXEL_HPP
#define PUTVOXEL_HPP
#include "sculptor.hpp"
#include "FiguraGeometrica.hpp"

class PutVoxel : public FiguraGeometrica
{
    protected:
        int x,y,z; //Coordenadas do voxel
        float r,g,b,a; //Cor e transparência
    public:
        ~PutVoxel(){};
        PutVoxel(int _x = 0, int _y = 0, int _z = 0, float _r = 0, float _g = 0, float _b = 0, float _a = 0);
        void draw(Sculptor &t);
};

#endif
