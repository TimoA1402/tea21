#ifndef MY_BMP
#define MY_BMP

#include <fmt/format.h>
#include <functional>
#include <string>

#include <cstdint>

#include <iostream>

#pragma pack (push, 1)

struct pixel
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t grey()
    {
        return(pixel::red+pixel::green+pixel::blue)/3    ;    
    };
};

struct BITMAPFILEHEADER
{
    BITMAPFILEHEADER(){

    }
uint16_t bfType;
uint32_t bfSize;
uint32_t bfReserved;
uint32_t bfOffBits;
};

struct BITMAPINFOHEADER
{
uint32_t biSize;
uint32_t biWidth;
uint32_t biHeight;
uint16_t biPlanes;
uint16_t biBitCount;
uint32_t biCompression;
uint32_t biSizeImage;
uint32_t biXPelsPerMeter;
uint32_t biYPelsPerMeter;
uint32_t biClrUsed;
uint32_t biClrImportant;
};

#pragma pack(pop)

class BMP {
    public:
    bool read(const std::string&  filename);
    bool write(const std::string&  filename);


    private:
    BITMAPFILEHEADER header;
    BITMAPINFOHEADER info;

};

#endif