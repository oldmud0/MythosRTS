#include "MythosRTS.hpp"

int main(int argc, char** argv) {
    // Loading must happen BEFORE initializing the Renderer object
    ResManager resources;
    resources.loadModel("../res/suzanne.3DO");
    
    Renderer renderer(&argc, argv);

    return 0;
}