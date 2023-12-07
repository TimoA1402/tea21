#include "CLI/CLI.hpp"
#include <fmt/format.h>

int main(int argc, char **argv) {
    CLI::App app{"App description"};

    // Define options
    int p = 0;
    app.add_option("-p", p, "Parameter");

    CLI11_PARSE(app, argc, argv);

    fmt::println("Parameter value: {}",p);
    return 0;
}