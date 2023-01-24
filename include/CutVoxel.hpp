#ifndef CUTVOXEL_HPP
#define CUTVOXEL_HPP
#include "sculptor.hpp"
#include "FiguraGeometrica.hpp"

class CutVoxel : public FiguraGeometrica
{
    protected:
        int x,y,z; //Coordenadas do voxel
    public:
        ~CutVoxel(){};
        CutVoxel(int _x = 0, int _y = 0, int _z = 0);
        void draw(Sculptor &t);
};

#endif
