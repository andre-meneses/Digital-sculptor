#include "../include/Interpretador.hpp"
#include "../include/PutVoxel.hpp"
#include "../include/CutVoxel.hpp"
#include "../include/PutBox.hpp"
#include "../include/CutBox.hpp"
#include "../include/PutSphere.hpp"
#include "../include/CutSphere.hpp"
#include "../include/PutEllipsoid.hpp"
#include "../include/CutEllipsoid.hpp"
#include <iostream>

int Interpretador::getX()
{
    return nx;    
}

int Interpretador::getY()
{
    return ny;    
}

int Interpretador::getZ()
{
    return nz;    
}

std::vector<FiguraGeometrica*> Interpretador::parse(const char *filename)
{
    std::ifstream fin;
    std::string s;
    std::stringstream sstream;
    std::vector<FiguraGeometrica*> figuras;

    fin.open(filename);
    
    if(!fin.is_open()) exit(0);
    
    while(std::getline(fin,s))
    {
        sstream.clear();
        sstream.str(s);
        sstream >> s;

        if(s.compare("dim") == 0)
        {
            int x,y,z;
            sstream >> x >> y >> z;
            nx = x;
            ny = y;
            nz = z;
        }
        else if(s.compare("putvoxel") == 0)
        {
            int x0,y0,z0;
            float r,g,b,a;
            sstream >> x0 >> y0 >> z0 >> r >> g >> b >> a;
            figuras.push_back(new PutVoxel(x0,y0,z0,r,g,b,a));
        }
        else if(s.compare("cutvoxel") == 0)
        {
            int x0,y0,z0;
            sstream >> x0 >> y0 >> z0; 
            figuras.push_back(new CutVoxel(x0,y0,z0));

        }
        else if(s.compare("putbox") == 0)
        {
            int x0,x1,y0,y1,z0,z1;
            float r,g,b,a;
            sstream >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            figuras.push_back(new PutBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
        }
        else if(s.compare("cutbox") == 0)
        {
            int x0,x1,y0,y1,z0,z1;
            sstream >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            figuras.push_back(new CutBox(x0,x1,y0,y1,z0,z1));
 
        }
        else if(s.compare("putsphere") == 0)
        {
            int x0,y0,z0,raio;
            float r,g,b,a;
            sstream >> x0 >> y0 >> z0 >> raio >> r >> g >> b >> a;
            figuras.push_back(new PutSphere(x0,y0,z0,raio,r,g,b,a));
 
        }
        else if(s.compare("cutsphere") == 0)
        {
            int x0,y0,z0,raio;
            sstream >> x0 >> y0 >> z0 >> raio ;
            figuras.push_back(new CutSphere(x0,y0,z0,raio));
        }
        else if(s.compare("putellipsoid") == 0)
        {
            int x0,y0,z0,rx,ry,rz;
            float r,g,b,a;
            sstream >> x0 >> y0 >> z0 >> rx >> ry >> rz >> r >> g >> b >> a;
            figuras.push_back(new PutEllipsoid(x0,y0,z0,rx,ry,rz,r,g,b,a));
        }
        else if(s.compare("cutellipsoid") == 0)
        {
            int x0,y0,z0,rx,ry,rz;
            sstream >> x0 >> y0 >> z0 >> rx >> ry >> rz;
            figuras.push_back(new CutEllipsoid(x0,y0,z0,rx,ry,rz));
        }
        else
        {
            std::cout << "Invalid instruction" << std::endl;
        }
    }

    fin.close();

    return figuras;
}




