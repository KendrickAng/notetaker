#include <iostream>
#include <vector>
#include <string>

#include "app.hpp"

int main() {
    Application app;
    app.init();

    while (1) {
        app.render();
    }
    return 0;
}