#include "bmp_reader.h"

void BMPReader::openBMP(const std::string& fileName)
{
    std::ifstream input{fileName, std::ios_base::binary};
    if (!input.is_open())
    {
        std::cout << "Can't open this file: " << fileName << "\n";
        return;
    }

    bmpFile = std::move(std::make_unique<BMPFile>());

    input.read((char*)&bmpFile->bmph, sizeof(BMPHeader));
    input.read((char*)&bmpFile->dibh, sizeof(DIBHeader));

    int data_size = bmpFile->dibh.width * bmpFile->dibh.height *
        bmpFile->dibh.bitsPerPixel / 8;
    
    input.seekg(bmpFile->bmph.offset);
    
    std::copy(std::istream_iterator<unsigned char>(input),
        std::istream_iterator<unsigned char>(),
        std::back_inserter(bmpFile->data));

    input.close();
}

void BMPReader::displayBMP() const
{
    int bytesPerPixel = bmpFile->dibh.bitsPerPixel / 8;
    int usefullRowSize = bytesPerPixel * bmpFile->dibh.width;
    int rowPadding = (4 - (usefullRowSize % 4)) % 4;
    int rowSize = usefullRowSize + rowPadding;

    for (int i (bmpFile->dibh.data_size - rowSize);
        i > -1; i -= rowSize)
        {
            for (int j = i; j < i + usefullRowSize; j += bytesPerPixel)
                if (bmpFile->data[j] == 255) {std::cout << "@";}
                else {std::cout << "_";}
            std::cout << "\n";
        }
}

void BMPReader::closeBMP()
{
    bmpFile.reset();
}

void BMPReader::show(const std::string& fileName)
{
    openBMP(fileName);
    displayBMP();
    closeBMP();
}