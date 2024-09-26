#include <iostream>
#include <iterator>
#include "bmp_reader.h"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cout << "Enter filepath as argument\n";
        return 0;
    }

    BMPReader reader{};
    reader.show(argv[1]);


    return 0;
}