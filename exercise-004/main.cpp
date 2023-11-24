#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"
#include "bmp.h"

#include <iostream>


auto main(int argc, char **argv) -> int
{
    std::string filename{DEFAULT_BMP_FILE};
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
            app.add_option("-f,--file",
            filename,
            fmt::format("The filename for the Bitmap,  default: {}", filename));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());
    fmt::print("File: {}\n", filename);

    BMP bmp;
    bmp.read(filename);

    // Vorbereitung der Daten (angenommen)
    std::vector<uint8_t> grey_buffer; // Grauwert-Pixel-Puffer
    uint32_t width = 0; // Breite des Bildes
    uint32_t height = 0; // Höhe des Bildes

    // Annahme: Die Daten wurden gelesen und in grey_buffer, width und height gespeichert

    // Aufruf der Funktion, um als ASCII-Kunst zu speichern
    bmp.saveAsAsciiArt(grey_buffer, width, height, "output.txt");

    return 0; /* exit gracefully*/
}
