#ifndef INTERPRETADOR_HPP
#define INTERPRETADOR_HPP
#include <fstream>
#include <string>
#include <sstream>
#include <cstdarg>
#include "sculptor.hpp"
#include "FiguraGeometrica.hpp"
#include <vector>

class Interpretador
{
    public:
        std::vector<FiguraGeometrica*> parse(const char *filename);
        int getX();
        int getY();
        int getZ();
    protected:
        int nx,ny,nz;
        
};

#endif
