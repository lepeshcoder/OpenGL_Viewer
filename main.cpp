#include <iostream>
#include "ModelStorage/ModelStorage.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

int screenWidth = 1200;
int screenHeight = 800;

//timing
double deltaTime = 0;
double lastFrame = 0;

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

int main() {

    if (!glfwInit())
        std::cout << "Failed to load glfw!";

    auto window = glfwCreateWindow(screenWidth, screenHeight,
                                   "OpenGL + ImGui", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        std::cout << "Failed to create GLFW window";
    }

    //glfw штуки
    glfwMakeContextCurrent(window);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSwapInterval(1);

    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    stbi_set_flip_vertically_on_load(true);

    glEnable(GL_DEPTH_TEST);

    Shader shaderProgram("..//Shader//Shaders//vertexShader.s",
                         "..//Shader//Shaders//fragmentShader.s");

    ModelStorage modelStorage;
    std::string model1FilePath = R"(C:\Users\Lepesh\Desktop\models\survival-guitar-backpack\source\Survival_BackPack_2\model.fbx)";
    std::string model2FilePath = R"(C:\Users\Lepesh\Desktop\models\robo-obj-pose4\source\model.obj)";
    std::string model3FilePath = R"(C:\Users\Lepesh\Desktop\models\model1\source\model.glb)";
    std::string model4FilePath = R"(C:\Users\Lepesh\Desktop\models\backpack\backpack.obj)";

    modelStorage.LoadModel(model1FilePath);
    modelStorage.LoadModel(model2FilePath);
    modelStorage.LoadModel(model3FilePath);
    modelStorage.LoadModel(model4FilePath);
    modelStorage.LoadModel(model1FilePath);

    auto model1 = modelStorage.GetModelByPath(model1FilePath);
    auto model2 = modelStorage.GetModelByPath(model2FilePath);
    auto model3 = modelStorage.GetModelByPath(model3FilePath);
    auto model4 = modelStorage.GetModelByPath(model4FilePath);


    float radius = 10;
    float angle = 0;
    glm::vec3 eye = glm::vec3(radius * cos(angle),0,radius * sin(angle));
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    while (!glfwWindowShouldClose(window)) {

        double currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window);

        glViewport(0, 0, screenWidth, screenHeight);
        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderProgram.use();

        glm::mat4 projection = glm::perspective(glm::radians(45.0f),
                                                (float) screenWidth / (float) screenHeight,
                                                0.1f,
                                                100.0f);

        angle += 40.0f * deltaTime;
        angle = fmod(angle,360.0f);
        eye = glm::vec3 (radius * sin(glm::radians(angle)),0, radius * cos(glm::radians(angle)));
        glm::vec3 center = glm::vec3(0,0,0);
        glm::vec3 up = glm::vec3(0,1,0);

        glm::mat4 view = glm::lookAt(eye,center,up);

        auto model = glm::mat4(1.0f);
        model = glm::translate(model,
                               glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
        model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));    // it's a bit too big for our scene, so scale it down
        model = glm::rotate(model,glm::radians(45.0f),glm::vec3(1,0,0));


        shaderProgram.setUniform("projection", projection);
        shaderProgram.setUniform("view", view);
        shaderProgram.setUniform("model", model);



        // to Render

        model4.Draw(shaderProgram);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    screenWidth = width;
    screenHeight = height;
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
