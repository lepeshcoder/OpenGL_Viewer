#include <iostream>
#include "ModelStorage/ModelStorage.h"
#include "Camera/Implementations/ArcBallCamera/ArcBallCamera.h"
#include "Camera/Contracts/ICamera/ICamera.h"
#include "Camera/Implementations/FPSCamera/FPSCamera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

int screenWidth = 1200;
int screenHeight = 800;

//timing
double deltaTime = 0;
double lastFrame = 0;

//mouse input
float lastX = 0;
float lastY = 0;
float deltaX = 0;
float deltaY = 0;
float deltaWheel = 0;
bool isPressed = false;
//etc
int frameCounter = 0;

glm::vec3 dir{};
double counter = 0;


void framebuffer_size_callback(GLFWwindow *window, int width, int height);

void processInput(GLFWwindow *window);

void mouse_callback(GLFWwindow *window, double xpoxsIn, double yposIn);

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);

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
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    //  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSwapInterval(1);

    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    stbi_set_flip_vertically_on_load(true);

    glEnable(GL_DEPTH_TEST);

    Shader shaderProgram("..//Shader//Shaders//WireFrameShaders//vertexShader.s",
                         "..//Shader//Shaders//WireFrameShaders//fragmentShader.s");

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

    ICamera *camera = new ArcBallCamera(10, 0, 0, 50, 100);
    //ICamera *camera = new FPSCamera();
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    auto model = glm::mat4(1.0f);
    glm::mat4 projection = glm::perspective(glm::radians(45.0f),
                                            (float) screenWidth / (float) screenHeight,
                                            0.1f,
                                            100.0f);


    while (!glfwWindowShouldClose(window)) {

        // timing
        double currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        //fps
        counter += deltaTime;
        frameCounter++;
        if (counter > 1)
        {
            std::cout << "FPS: " << frameCounter << std::endl;
            counter = frameCounter = 0;
        }



        // camera update
        CameraMouseInput cmi{deltaX, deltaY, deltaWheel};
        CameraKeyboardInput cki{ dir };
        camera->Update(cmi, cki, deltaTime);
        deltaX = deltaY = deltaWheel = 0;
        dir = {0,0,0};

        // events
        processInput(window);

        // clear screen

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glViewport(0, screenHeight * 1.0f / 7.0f , screenWidth * 5.0f / 7.0f, screenHeight * 6.0f / 7.0f);

        glEnable(GL_SCISSOR_TEST);
        glScissor(0, screenHeight * 1.0f / 7.0f, screenWidth * 5.0f / 7.0f, screenHeight * 6.0f / 7.0f);
        glClearColor(0.3f, 0.3f, 0.3f, 1.0f); // Белый цвет для сцены
        glClear(GL_COLOR_BUFFER_BIT);


        // use shader
        shaderProgram.use();

        glm::mat4 view = camera->GetViewMatrix();

        // set uniforms
        shaderProgram.setUniform("projection", projection);
        shaderProgram.setUniform("view", view);
        shaderProgram.setUniform("model", model);

        // to Render
        model4.Draw(shaderProgram);


        glDisable(GL_SCISSOR_TEST);
        // glfw things
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    delete camera;
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
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        dir.x += 1;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        dir.x -= 1;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        dir.z -= 1;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        dir.z += 1;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        dir.y -= 1;
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        dir.y += 1;
}

void mouse_callback(GLFWwindow *window, double xposIn, double yposIn) {
    if (isPressed) {
        deltaX = xposIn - lastX;
        deltaY = yposIn - lastY;
    }
    lastX = xposIn;
    lastY = yposIn;
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
    deltaWheel = -yoffset;
}

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        isPressed = true;
    } else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
        isPressed = false;
    }
}
