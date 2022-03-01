#include "PartsBinCore.h"

#include <iostream>
#include <cstdlib>

int main() {
    PartsBinApp app;

    try {
        app.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}