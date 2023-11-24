#include "bmp.h"
#include<fstream>


bool BMP::read(const std::string& filename)
{
    auto ret = false;
    std::ifstream infile;
    infile.open(filename);
    
    BITMAPFILEHEADER file_header;

    infile >> file_header.bfType;
    infile >> file_header.bfSize;
    infile >> file_header.bfReserved;
    infile >> file_header.bfOffBits;

    BITMAPINFOHEADER info_header;

    infile >> info_header.biSize;
    infile >> info_header.biWidth;
    infile >> info_header.biHeight;
    infile >> info_header.biPlanes;
    infile >> info_header.biBitCount;
    infile >> info_header.biCompression;
    infile >> info_header.biSizeImage;
    infile >> info_header.biXPelsPerMeter;
    infile >> info_header.biYPelsPerMeter;
    infile >> info_header.biClrUsed;
    infile >> info_header.biClrImportant;

    //Vektor für Pixel-Buffer
    std::vector<pixel> pixel_buffer(100/*breite*höhe*/);
    for(int i; i < buffer_size(buffer_size);

    infile >> pixel_buffer[0].red;
    infile >> pixel_buffer[0].green;
    infile >> pixel_buffer[0].blue;

    return ret;
}

bool BMP::write(const std::string& filename)
{
    auto ret= false;
    
    // aus info -> pixels -> grey -> ascii -> print
    return ret;
}

