#include "../include/sculptor.hpp"
#include"../include/Interpretador.hpp"
#include <vector>
#include <iostream>
#include <string>

int main(void)
{
    Sculptor *escultura;
    Interpretador parser;
    std::vector<FiguraGeometrica*> figuras;

    /* figuras = parser.parse("./input/exemplo.txt"); */
    
    std::string filePath;
    std::cout << "Filepath: ";
    std::getline(std::cin,filePath);

    figuras = parser.parse(filePath.c_str());

    escultura = new Sculptor(parser.getX(), parser.getY(), parser.getZ());

    for(size_t i = 0; i < figuras.size(); i++)
    {
        figuras[i]->draw(*escultura);
    }

    escultura->writeOFF("./output/output.off");

    for(size_t i = 0; i <figuras.size();i++)
    {
        delete figuras[i];
    }

    delete escultura;

    return 0;
    
}



