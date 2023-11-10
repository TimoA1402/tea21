#include <fmt/chrono.h>
#include <fmt/format.h>

#include <CLI/CLI.hpp>
#include <vector>
#include <random>
#include <algorithm>  // für std::sort

#include "config.h"

auto main(int argc, char **argv) -> int
{
    CLI::App app{PROJECT_NAME};

    int count = 20;
    app.add_option("-c,--count", count, "Set the count")->default_val(20);

    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    fmt::print("Hello, {}!\n", app.get_name());
    fmt::print("Count: {}\n", count);

    // Erstelle einen std::vector mit der Größe von 'count' und fülle ihn mit zufälligen Werten von 1 bis 100
    std::vector<int> randomNumbers;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < count; ++i) {
        randomNumbers.push_back(dis(gen));
    }

    // Zeige die zufälligen Zahlen an
    fmt::print("Random Numbers: ");
    for (const auto &num : randomNumbers) {
        fmt::print("{} ", num);
    }
    fmt::print("\n");

    // Sortiere den Vektor
    std::sort(randomNumbers.begin(), randomNumbers.end());

    // Zeige die sortierten Zahlen an
    fmt::print("Sorted Numbers: ");
    for (const auto &num : randomNumbers) {
        fmt::print("{} ", num);
    }
    fmt::print("\n");

    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully */
}
