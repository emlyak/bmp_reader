#ifndef BMP_READER_H
#define BMP_READER_H

#include <cstdint>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <memory>

#pragma pack(1)
// Определим структуру bmp-файла

struct BMPHeader {
    char ID[2];
    uint32_t size;
    uint16_t unused1;
    uint16_t unused2;
    uint32_t offset;

    void toString();
};


struct DIBHeader {
    uint32_t header_size;
    uint32_t width;
    uint32_t height;
    uint16_t color_planes;
    uint16_t bitsPerPixel;
    uint32_t BI_RGB;
    uint32_t data_size;
    uint32_t pWidth;
    uint32_t pHeight;
    uint32_t colors_count;
    uint32_t important_colors_count;

    void toString();
};

struct BMPFile
{
    BMPHeader bmph;
    DIBHeader dibh;

    std::vector<unsigned char> data;

    void toString();
};

#pragma pop

class BMPReader
{
public:
    void show(const std::string& fileName);

private:
    std::unique_ptr<BMPFile> bmpFile;


    std::unique_ptr<BMPFile> getFile();

    void openBMP(const std::string& fileName);
    void displayBMP() const;
    void closeBMP();

    void toString();
};

#endif //BMP_READER_H