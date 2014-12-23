#include "parser.hpp"

#include <iostream>
#include <sstream>
#include <fstream>

namespace
{
    std::string slurp( std::ifstream& in )
    {
        return static_cast<std::stringstream const&>(std::stringstream() << in.rdbuf()).str();
    }
}

int main(int argc, char** argv)
{
    if ( argc <= 1 )
    {
        // This example needs a file having lines of this kind:
        // 12*3-4*1
        // 2+3-4*3
        // 2+3*4*3
        // Then it put all computed results in a vector<double>
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        std::cerr << "Exemple: " << argv[0] << " spiritzExample1.input" << std::endl;
        return -1;
    }

    std::ifstream filein( argv[1], std::ios::in );
    if ( filein.good() )
    {
        std::cout << "Parsing vector of operations" << std::endl;
        const std::string content = slurp( filein );
        std::cout << "Processing: " << std::endl << content << std::endl;
        std::vector<double> vOut = example1::parse( content );
        std::cout << "Now displaying results:" << std::endl;
        for( const auto v: vOut )
        {
            std::cout << v << std::endl;
        }
        std::cout << "End" << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "Error while reading file!" << std::endl;
        return 1;
    }
}
