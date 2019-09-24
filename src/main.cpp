//#define GLFW_INCLUDE_VULKAN
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//#define GLM_FORCE_RADIANS
//#define GLM_FORCE_DEPTH_ZERO_TO_ONE
//#include <glm/vec4.hpp>
//#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>

#include <iostream>
#include <string>
#include <vector>

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

namespace i6
{
    GLFWwindow* get_window(std::string mode = "windowed", std::string project_name = "i6_engine", int screen_width = 1280, int screen_height = 720);

    GLFWwindow* get_window(std::string mode, std::string project_name, int screen_width, int screen_height)
    {
        GLFWmonitor* primary = glfwGetPrimaryMonitor();
        glfwGetMonitorWorkarea(primary, nullptr, nullptr, &screen_width, &screen_height);

        if (mode == "fullscreen")
            return glfwCreateWindow(screen_width, screen_height, project_name.c_str(), primary, nullptr);
        else if (mode == "windowed")
            return glfwCreateWindow(screen_width, screen_height, project_name.c_str(), nullptr, nullptr);
        else
            return nullptr;
    }
}

int main()
{
    std::string project_name = "i6_engine";
    std::string screen_mode = "windowed";
    int opengl_version_major = 3; // 4
    int opengl_version_minor = 0; // 1

    glfwSetErrorCallback(error_callback);

    //Init GLFW
    if(!glfwInit())
        exit(EXIT_FAILURE);

    // GLFW Hints
    //glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    //glfwWindowHint(GLFW_VISIBLE, GL_TRUE);
    //glfwWindowHint(GLFW_DECORATED, GL_TRUE);
    //glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, opengl_version_major);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, opengl_version_minor);

    // Old GLFW Hints
    //glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    GLFWwindow* window = i6::get_window();
    if(window == nullptr)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    /* uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::cout << extensionCount << " extensions supported" << std::endl;

    glm::mat4 matrix;
    glm::vec4 vec;
    auto test = matrix * vec; */


    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);
    gladLoadGL();
    glfwSwapInterval(1);

    // Game Loop
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        //glfwGetKey(window, GLFW_KEY_W);
        //glfwGetKey(window, GLFW_KEY_A);
        //glfwGetKey(window, GLFW_KEY_S);
        //glfwGetKey(window, GLFW_KEY_D);

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}