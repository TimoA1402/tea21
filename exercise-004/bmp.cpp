#include "bmp.h"
#include<fstream>
#include <vector>
#include <iostream>



//bool BMP::read(const std::string& filename)
//{
//    auto ret = false;
//    std::ifstream infile;
//    infile.open(filename, std::ios::binary | std::ios::in);
//
//    if(!infile.is_open()){
//        return ret;
//    }
//    
//    BITMAPFILEHEADER file_header;
//
//    infile >> file_header.bfType;
//    infile >> file_header.bfSize;
//    infile >> file_header.bfReserved;
//    infile >> file_header.bfOffBits;
//
//    BITMAPINFOHEADER info_header;
/*
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
    auto buffer_size = info_header.biWidth*info_header.biHeight;
    std::vector<pixel> pixel_buffer(buffer_size);
    for(int i = 0; i < buffer_size; i++)
    {
    infile >> pixel_buffer[i].red;
    infile >> pixel_buffer[i].green;
    infile >> pixel_buffer[i].blue;
    auto x = pixel_buffer[i];
    fmt::print("R: {}, G: {}, B: {}\n",pixel_buffer[i].red, pixel_buffer[i].green, pixel_buffer[i].blue);
    }

    std::vector <uint8_t> grey_buffer(buffer_size);

    for (int i = 0; i < buffer_size;i++)
    {
    grey_buffer[i] = pixel_buffer[i].grey();
    fmt::print("-{}-", grey_buffer[i]);
    }

    return ret;
}
*/

// Function to convert grayscale value to ASCII character
    char getAsciiChar(uint8_t grey) {
    //const char ascii_chars[] = "@%#*+=-:. "; // ASCII-Zeichen von dunkel nach hell
    const char ascii_chars[] = ".:-=+#%@"; // ASCII-Zeichen von hell nach dunkel
    int index = static_cast<int>(grey * 10 / 255); // Skalierung des Grauwerts auf den Bereich der ASCII-Liste
    return ascii_chars[index];
    }



bool BMP::read(const std::string& filename) {
    bool ret = false;
    std::ifstream infile(filename, std::ios::binary);
    
    if (!infile.is_open()) {
        return ret; // File couldn't be opened
    }

    // Read file header
    infile.read(reinterpret_cast<char*>(&header), sizeof(BITMAPFILEHEADER));

    // Read info header
    infile.read(reinterpret_cast<char*>(&info), sizeof(BITMAPINFOHEADER));

    // Calculate buffer size
    uint32_t buffer_size = info.biWidth * info.biHeight;

    // Read pixel buffer
    std::vector<pixel> pixel_buffer(buffer_size);
    infile.read(reinterpret_cast<char*>(pixel_buffer.data()), buffer_size * sizeof(pixel));

    // Process pixel buffer
    for (uint32_t i = 0; i < buffer_size; ++i) {
        //fmt::print("R: {}, G: {}, B: {}\n", pixel_buffer[i].red, pixel_buffer[i].green, pixel_buffer[i].blue);
    }

    // Calculate and process grey values
    std::vector<uint8_t> grey_buffer(buffer_size);
    for (uint32_t i = 0; i < buffer_size; ++i) {
        grey_buffer[i] = pixel_buffer[i].grey();
        //fmt::print("-{}-", grey_buffer[i]);
    }

    

    for (uint32_t i = 0; i < info.biHeight; ++i) {
        for (uint32_t j = 0; j < info.biWidth; ++j) {
            char ascii_char = getAsciiChar(grey_buffer[i * info.biWidth+ j]);
            //outfile << ascii_char << ascii_char; // Double characters to adjust aspect ratio
            //fmt::print("{}", ascii_char);
            std::cout << ascii_char;
        }
        std::cout << std::endl; // Neue Zeile für jede Bildzeile
    }

    ret = true; // Successfully read the file
    return ret;
}



bool BMP::write(const std::string& filename)
{
    auto ret= false;
    //std::ifstream()
    // aus info -> pixels -> grey -> ascii -> print
    return ret;
}

// Function to convert grayscale value to ASCII character
/*char getAsciiChar(uint8_t grey) {
    const char ascii_chars[] = "@%#*+=-:. "; // ASCII-Zeichen von dunkel nach hell
    int index = static_cast<int>(grey * 10 / 255); // Skalierung des Grauwerts auf den Bereich der ASCII-Liste
    return ascii_chars[index];
}*/

// Function to convert grayscale image to ASCII art and save it to a file
void BMP::saveAsAsciiArt(const std::vector<uint8_t>& grey_buffer, uint32_t width, uint32_t height, const std::string& output_file) {
    std::ofstream outfile(output_file);
    
    if (!outfile.is_open()) {
        std::cerr << "Unable to open the output file." << std::endl;
        return;
    }
    
    for (uint32_t i = 0; i < height; ++i) {
        for (uint32_t j = 0; j < width; ++j) {
            char ascii_char = getAsciiChar(grey_buffer[i * width + j]);
            outfile << ascii_char << ascii_char; // Double characters to adjust aspect ratio
            //fmt::print("{}", ascii_char);
        }
        outfile << "\n"; // Newline for each row
    }

    outfile.close();
}

