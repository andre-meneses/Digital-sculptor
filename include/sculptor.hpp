#ifndef SCULPTOR_HPP
#define SCULPTOR_HPP
#include "/home/andre/aulas/prog_avan/prog_oo/unidade2/include/voxel.hpp"

class Sculptor
{
    protected:
        Voxel ***v; //3d Matrix
        int nx, ny, nz; //Dimensions
        float r,g,b,a; // Current Drawing color
        int qntVox;
    public:
        Sculptor(int _nx = 1, int _ny = 1, int _nz = 1);
        ~Sculptor();
        void setColor(float r, float g, float b, float alpha);
        void putVoxel(int x, int y, int z);
        void cutVoxel(int x, int y, int z);
        void writeOFF(const char* filename);
};


#endif
