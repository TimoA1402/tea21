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
    uint8_t red = 0;
    uint8_t green = 0;
    uint8_t blue = 0;
    uint8_t alpha = 0;
    uint8_t grey()
    {
        return(pixel::red+pixel::green+pixel::blue)/3    ;    
    };
};

struct BITMAPFILEHEADER
{
char bfType[2] = {'X','X'};
uint32_t bfSize = 0;
uint32_t bfReserved = 0;
uint32_t bfOffBits = 0;
void print();
};

struct BITMAPINFOHEADER
{
uint32_t biSize =0;
uint32_t biWidth = 0;
uint32_t biHeight = 0;
uint16_t biPlanes = 0;
uint16_t biBitCount = 0;
uint32_t biCompression = 0;
uint32_t biSizeImage = 0;
uint32_t biXPelsPerMeter = 0;
uint32_t biYPelsPerMeter = 0;
uint32_t biClrUsed = 0;
uint32_t biClrImportant = 0;
};

#pragma pack(pop)

class BMP {
    public:
    bool read(const std::string&  filename);
    bool write(const std::string&  filename);
    void saveAsAsciiArt(const std::vector<uint8_t>& grey_buffer, uint32_t width, uint32_t height, const std::string& output_file);

    private:
    BITMAPFILEHEADER header;
    BITMAPINFOHEADER info;

};

#endif