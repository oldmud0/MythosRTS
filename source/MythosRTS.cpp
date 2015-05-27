#include "MythosRTS.hpp"

int main(int argc, char** argv) {
    std::cout << "Started." << std::endl;

    Renderer::globalRenderer = new Renderer(&argc, argv);
    std::cout << "Created global renderer." << std::endl;

    ResManager* resources = new ResManager();
    std::cout << "Set up resource manager." << std::endl;

    int modelId = resources->loadModel("../res/suzanne.3DO");
    std::cout << "Loaded suzanne.3DO." << std::endl;

    Model* suzanne = (Model*)(resources->getResource(modelId));
    std::cout << "Got suzanne." << std::endl;

    //TODO make this a resource that can be loaded.
    Shader* suzanne_shader = new Shader("../res/sample_shader.vs", "../res/sample_shader.frag");

    suzanne->shader = suzanne_shader;
    std::cout << "Created new shader." << std::endl;

    Renderer::globalRenderer->addModel(resources, modelId);
    std::cout << "Added suzanne to renderer." << std::endl;

    Renderer::globalRenderer->startLoop();
    
    return 0;
}