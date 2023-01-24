#include "../include/sculptor.hpp"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <math.h>

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx;
    ny = _ny;
    nz = _nz;

    //Alocação de memória para o bloco de Voxels
    v = new Voxel**[nx];
    v[0] = new Voxel*[nx*ny];

    for(int i = 1; i < nx; i++) v[i] = v[i - 1] + ny;

    v[0][0] = new Voxel[nx*ny*nz];
    
    for(int i = 0; i < nx; i++)
    {
        if(i != 0) v[i][0] = v[i - 1][0] + nx*ny;

        for(int j = 1; j < ny; j++)
        {
            v[i][j] = v[i][j-1] + nz;
        }
    }

    for(int i = 0; i < nx; i++)
    {
        for(int j = 0; j < ny; j++)
        {
            for(int k = 0; k < nz; k++) v[i][j][k].isOn = false;
        }
    }

    qntVox = 0;
        
}

Sculptor::~Sculptor()
{
    delete[] v[0][0];
    delete[] v[0];
    delete[] v;
}

void Sculptor::setColor(float r_, float g_, float b_, float alpha_)
{
    r = r_;
    g = g_;
    b = b_;
    a = alpha_;
}

void Sculptor::putVoxel(int x, int y, int z)
{
    if(x < 0 || y < 0 || z < 0)
    {
        throw "voxel inválido, índice < 0";
    }
    if(x > nx || y > ny || z > nz)
    {
        throw "voxel inválido, out of range";
    }

    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    qntVox++;
}

void Sculptor::cutVoxel(int x, int y, int z)
{
    if(x < 0 || y < 0 || z < 0)
    {
        throw "voxel inválido, índice < 0";
    }
    if(x > nx || y > ny || z > nz)
    {
        throw "voxel inválido, out of range";
    }

    if(v[x][y][z].isOn)
    {
        v[x][y][z].isOn = false; 
        qntVox--;
    }
}


void Sculptor::writeOFF(const char* filename)
{
    std::ofstream fout;
    fout.open(filename);

    if(!fout.is_open()) exit(0);

    fout << "OFF" << std::endl;  
    fout << qntVox * 8 << " " << qntVox * 6 << " " << 0 << std::endl;
    
    //Escrever as coordenadas dos vértices no arquivo OFF
    for(int i = 0; i < nx; i++)
    {
       for(int j = 0; j < ny; j++)
       {
           for(int k = 0; k < nz; k++)
           {
                if(v[i][j][k].isOn)
                {
                    fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
                    fout << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
                    fout << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
                    fout << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
                    fout << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
                    fout << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
                    fout << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
                    fout << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
                }
           }
       }
    }

    //Escrever os índices dos vértices e os dados rgba.
    int cont = 0;

    for(int i = 0; i < nx; i++)
    {
       for(int j = 0; j < ny; j++)
       {
           for(int k = 0; k < nz; k++)
           {
                if(v[i][j][k].isOn)
                {
                    fout << 4 << " " << 0+(cont*8)  << " " << 3+(cont*8)  << " " << 2+(cont*8)  << " " << 1+(cont*8)  << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a <<std::endl;
                    fout << 4 << " " << 4+(cont*8) << " " << 5+(cont*8)  << " " << 6+(cont*8)  << " " << 7+(cont*8)  << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a <<std::endl;
                    fout << 4  << " " << 0+(cont*8)  << " " << 1+(cont*8)  << " " << 5+(cont*8)  << " " << 4+(cont*8)  << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a <<std::endl;
                    fout << 4  << " " << 0+(cont*8)  << " " << 4+(cont*8)  << " " << 7+(cont*8)  << " " << 3+(cont*8)  << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a <<std::endl;
                    fout << 4  << " " << 3+(cont*8)  << " " << 7+(cont*8)  << " " << 6+(cont*8)  << " " << 2+(cont*8)  << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a <<std::endl;
                    fout << 4  << " " << 1+(cont*8)  << " " << 2+(cont*8)  << " " << 6+(cont*8)  << " " << 5+(cont*8)  << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a <<std::endl;
                    cont++;
                }
           }
       }
    }

    fout.close();
}


