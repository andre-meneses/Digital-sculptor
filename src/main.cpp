#include "../include/sculptor.hpp"
#include"../include/Interpretador.hpp"
#include <vector>

int main(void)
{
    Sculptor *escultura;
    Interpretador parser;
    std::vector<FiguraGeometrica*> figuras;

    figuras = parser.parse("../input/exemplo.txt");

    escultura = new Sculptor(parser.getX(), parser.getY(), parser.getZ());

    for(size_t i = 0; i < figuras.size(); i++)
    {
        figuras[i]->draw(*escultura);
    }

    escultura->writeOFF("../output/saida_exemplo.off");

    for(size_t i = 0; i <figuras.size();i++)
    {
        delete figuras[i];
    }

    delete escultura;

    return 0;
    
}



