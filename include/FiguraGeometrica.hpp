#ifndef FIGURAGEOMETRICA_HPP
#define FIGURAGEOMETRICA_HPP
#include "sculptor.hpp"

class FiguraGeometrica
{
    protected:
        float r,g,b,a;
    public:
        virtual ~FiguraGeometrica(){};
        virtual void draw(Sculptor &t) = 0;
};

#endif
