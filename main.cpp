#include <string>

#include "Application.hpp"

int main(int argc, char** argv) {
    unsigned long fps;
    if(argc > 1) {
        fps = std::stoul(std::string(*(argv+1)));
    } else {
        fps = 50;
    }
    Application app("Pong!");
    app.start(fps);

    return 0;
}
