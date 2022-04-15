//#include <Engine.h>
//
//// https://learnopengl.com/Getting-started/Shaders
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//
//// this code was first written with the help of following URL: https://learnopengl.com/Getting-started/Hello-Window
//// which was changed everytime we implemented something new
//
//int main(void)
//{
//    GLFWwindow* window;
//
//
//    /* Initialize the library */
//    if (!glfwInit())
//        return -1;
//
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
//    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
//
//
//    /* Create a windowed mode window and its OpenGL context */
//    window = glfwCreateWindow(800, 600, "Doom-Quake", NULL, NULL);
//
//
//    if (!window)
//    {
//        glfwTerminate();
//        return -1;
//    }
//
//    /* Make the window's context current */
//    glfwMakeContextCurrent(window);
//
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//    std::unique_ptr<Engine> engine = std::make_unique<Engine>();
//    glfwSetWindowUserPointer(window, engine.get());
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//    glfwSetCursorPosCallback(window, engine->mouseHandler_static);
//    glfwSetScrollCallback(window, engine->scrollHandler_static);
//
//
//    // tell GLFW to capture our mouse
//    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//    stbi_set_flip_vertically_on_load(true);
//    glEnable(GL_DEPTH_TEST);
//
//    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//    /* Loop until the user closes the window */
//    while (!glfwWindowShouldClose(window))
//    {
//        /* Render here */
//        //glClear(GL_COLOR_BUFFER_BIT);
//
//        /* Render in engine */
//        engine->loop(window);
//
//        /* Swap front and back buffers */
//        glfwSwapBuffers(window);
//
//        /* Poll for and process events */
//        glfwPollEvents();
//
//
//    }
//
//    glfwTerminate();
//    return 0;
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    // make sure the viewport matches the new window dimensions; note that width and
//    // height will be significantly larger than specified on retina displays.
//    glViewport(0, 0, width, height);
//}



#include<iostream>
#include<glad.h>
#include<GLFW/glfw3.h>
#include<stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"Map/Texture.h"
#include"Map/shaderClass.h"
#include"Map/VAO.h"
#include"Map/VBO.h"
#include"Map/EBO.h"
#include"Map/Camera.h"



const unsigned int width = 1000;
const unsigned int height = 800;



// Vertices coordinates
GLfloat vertices[] =
        // I also lowered the Y coordinate to lower the plane so we are already standing/starting on the correct height.
        { //     COORDINATES     /        COLORS        /    TexCoord    /       NORMALS     //
                -10.0f, -5.0f,  10.0f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,		0.0f, 1.0f, 0.0f,
                -10.0f, -5.0f, -10.0f,		0.0f, 0.0f, 0.0f,		0.0f, 1.0f,		0.0f, 1.0f, 0.0f,
                30.0f, -5.0f, -10.0f,		0.0f, 0.0f, 0.0f,		1.0f, 1.0f,		0.0f, 1.0f, 0.0f,
                30.0f, -5.0f,  10.0f,		0.0f, 0.0f, 0.0f,		1.0f, 0.0f,		0.0f, 1.0f, 0.0f
        };

//// trying to add multiple planes!!
GLfloat vertices2[] = 
        { //     COORDINATES     /        COLORS        /    TexCoord    /       NORMALS     //
                20.0f, -5.0f, -10.0f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,		10.0f, 1.0f, 0.0f,
                20.0f, -5.0f, -30.0f,		0.0f, 0.0f, 0.0f,		0.0f, 1.0f,		10.0f, 1.0f, 0.0f,
                30.0f, -5.0f, -30.0f,		0.0f, 0.0f, 0.0f,		1.0f, 1.0f,		10.0f, 1.0f, 0.0f,
                30.0f, -5.0f, -10.0f,		0.0f, 0.0f, 0.0f,		1.0f, 0.0f,		10.0f, 1.0f, 0.0f
        };


GLfloat vertices3[] =
        { //     COORDINATES     /        COLORS        /    TexCoord    /       NORMALS     //
                10.0f, -10.0f, -20.0f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,		10.0f, 1.0f, 0.0f,
                10.0f, -10.0f, -30.0f,		0.0f, 0.0f, 0.0f,		0.0f, 1.0f,		10.0f, 1.0f, 0.0f,
                20.0f, -5.0f, -30.0f,		0.0f, 0.0f, 0.0f,		1.0f, 1.0f,		10.0f, 1.0f, 0.0f,
                20.0f, -5.0f, -20.0f,		0.0f, 0.0f, 0.0f,		1.0f, 0.0f,		10.0f, 1.0f, 0.0f
        };

GLfloat floor_[] =
{ //     COORDINATES     /        COLORS        /    TexCoord    /       NORMALS     //
        -10.0f, 0.0f, 10.0f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,		10.0f, 1.0f, 0.0f,
        -10.0f, 0.0f, -10.0f,		0.0f, 0.0f, 0.0f,		0.0f, 1.0f,		10.0f, 1.0f, 0.0f,
        10.0f, 0.0f, -10.0f,		0.0f, 0.0f, 0.0f,		1.0f, 1.0f,		10.0f, 1.0f, 0.0f,
        10.0f, 0.0f, 10.0f,		0.0f, 0.0f, 0.0f,		1.0f, 0.0f,		10.0f, 1.0f, 0.0f
};


GLfloat wall_1[] =
        { //     COORDINATES     /        COLORS        /    TexCoord    /       NORMALS     //
                -10.0f, 0.0f, 10.0f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,		10.0f, 1.0f, 0.0f,
                -10.0f, 10.0f, 10.0f,		0.0f, 0.0f, 0.0f,		0.0f, 1.0f,		10.0f, 1.0f, 0.0f,
                10.0f, 10.0f, 10.0f,		0.0f, 0.0f, 0.0f,		1.0f, 1.0f,		10.0f, 1.0f, 0.0f,
                10.0f, 0.0f, 10.0f,		0.0f, 0.0f, 0.0f,		1.0f, 0.0f,		10.0f, 1.0f, 0.0f
        };

GLfloat wall_2[] =
        { //     COORDINATES     /        COLORS        /    TexCoord    /       NORMALS     //
                10.0f, 0.0f, 10.0f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,		10.0f, 1.0f, 0.0f,
                10.0f, 10.0f, 10.0f,		0.0f, 0.0f, 0.0f,		0.0f, 1.0f,		10.0f, 1.0f, 0.0f,
                10.0f, 10.0f, -10.0f,		0.0f, 0.0f, 0.0f,		1.0f, 1.0f,		10.0f, 1.0f, 0.0f,
                10.0f, 0.0f, -10.0f,		0.0f, 0.0f, 0.0f,		1.0f, 0.0f,		10.0f, 1.0f, 0.0f
        };

GLfloat wall_3[] =
        { //     COORDINATES     /        COLORS        /    TexCoord    /       NORMALS     //
                10.0f, 0.0f, -10.0f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,		10.0f, 1.0f, 0.0f,
                10.0f, 10.0f, -10.0f,		0.0f, 0.0f, 0.0f,		0.0f, 1.0f,		10.0f, 1.0f, 0.0f,
                -10.0f, 10.0f, -10.0f,		0.0f, 0.0f, 0.0f,		1.0f, 1.0f,		10.0f, 1.0f, 0.0f,
                -10.0f, 0.0f, -10.0f,		0.0f, 0.0f, 0.0f,		1.0f, 0.0f,		10.0f, 1.0f, 0.0f
        };

GLfloat wall_4[] =
        { //     COORDINATES     /        COLORS        /    TexCoord    /       NORMALS     //
                -10.0f, 0.0f, -10.0f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,		10.0f, 1.0f, 0.0f,
                -10.0f, 10.0f, -10.0f,		0.0f, 0.0f, 0.0f,		0.0f, 1.0f,		10.0f, 1.0f, 0.0f,
                -10.0f, 10.0f, 10.0f,		0.0f, 0.0f, 0.0f,		1.0f, 1.0f,		10.0f, 1.0f, 0.0f,
                -10.0f, 0.0f, 10.0f,		0.0f, 0.0f, 0.0f,		1.0f, 0.0f,		10.0f, 1.0f, 0.0f
        };


// Indices for vertices order
GLuint indices[] =
        {
                0, 1, 2,
                0, 2, 3
        };



GLfloat lightVertices[] =
        { //     COORDINATES     //
          // 8 coordinates to define the cube that is emitting light
                -0.1f, 7.0f,  0.1f,
                -0.1f, 7.0f, -0.1f,
                0.1f, 7.0f, -0.1f,
                0.1f, 7.0f,  0.1f,
                -0.1f,  7.2f,  0.1f,
                -0.1f,  7.2f, -0.1f,
                0.1f,  7.2f, -0.1f,
                0.1f,  7.2f,  0.1f
        };


GLfloat lightVertices2[] =
{ //     COORDINATES     //
  // 8 coordinates to define the cube that is emitting light
        13.0f, 10.0f,  -14.0f,
        13.0f, 10.0f, -16.0f,
        15.0f, 10.0f, -16.0f,
        15.0f, 10.0f,  -14.0f,
        13.0f,  14.0f,  -14.0f,
        13.0f,  14.0f, -16.0f,
        15.0f,  14.0f, -16.0f,
        15.0f,  14.0f,  -14.0f
};


GLuint lightIndices[] =
        {
                0, 1, 2,
                0, 2, 3,
                0, 4, 7,
                0, 7, 3,
                3, 7, 6,
                3, 6, 2,
                2, 6, 5,
                2, 5, 1,
                1, 5, 4,
                1, 4, 0,
                4, 5, 6,
                4, 6, 7
        };


int main()
{
    GLFWwindow* window;


    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 600, "Doom-Quake", NULL, NULL);


    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    // Introduce the window into the current context
    glfwMakeContextCurrent(window);

    //Load GLAD so it configures OpenGL
    gladLoadGL();
    // Specify the viewport of OpenGL in the Window
    // In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
    glViewport(0, 0, width, height);



    // Generates Shader object using shaders default.vert and default.frag
    ShaderMap shaderProgram("shader-files/default.vert", "shader-files/default.frag");
    // Generates Vertex Array Object and binds it
//    VAO VAO1;
//
//
//    VAO1.Bind();
//
//    // Generates Vertex Buffer Object and links it to vertices
//    VBO VBO1(vertices, sizeof(vertices));
//
//    // Generates Element Buffer Object and links it to indices
//    EBO EBO1(indices, sizeof(indices));
//
//
//
//
//    // Links VBO attributes such as coordinates and colors to VAO
//    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
//    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
//    VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
//    VAO1.LinkAttrib(VBO1, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
//    // Unbind all to prevent accidentally modifying them
//    VAO1.Unbind();
//    VBO1.Unbind();
//    EBO1.Unbind();
//
//
//    ///////////////////////////////////////////////////////////////////////////////////////////
//    VAO VAO2; // added to create a second plane
//    VAO2.Bind();
//
//    VBO VBO2(vertices2, sizeof(vertices2)); // added to try to create a second plane!
//    // added to try and create a second plane
//    EBO EBO2(indices, sizeof(indices));
//    // added to try and create a second plane
//    VAO2.LinkAttrib(VBO2, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
//    VAO2.LinkAttrib(VBO2, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
//    VAO2.LinkAttrib(VBO2, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
//    VAO2.LinkAttrib(VBO2, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
//
//    VAO2.Unbind();
//    VBO2.Unbind();
//    EBO2.Unbind();
//
//
//
//    ///////////////////////////////////////////////////////////////////////////////////////////
//    VAO VAO3;
//    VAO3.Bind();
//
//    VBO VBO3(vertices3, sizeof(vertices3)); // added to try to create a second plane!
//    // added to try and create a second plane
//    EBO EBO3(indices, sizeof(indices));
//    // added to try and create a second plane
//    VAO3.LinkAttrib(VBO3, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
//    VAO3.LinkAttrib(VBO3, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
//    VAO3.LinkAttrib(VBO3, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
//    VAO3.LinkAttrib(VBO3, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
//
//    VAO3.Unbind();
//    VBO3.Unbind();
//    EBO3.Unbind();


    ///////////////////////////////////////////////////////////////////////////////////////////
    VAO VAO4; 
    VAO4.Bind();

    VBO VBO4(floor_, sizeof(floor_));
    EBO EBO4(indices, sizeof(indices));
    VAO4.LinkAttrib(VBO4, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
    VAO4.LinkAttrib(VBO4, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
    VAO4.LinkAttrib(VBO4, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
    VAO4.LinkAttrib(VBO4, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));

    VAO4.Unbind();
    VBO4.Unbind();
    EBO4.Unbind();

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    VAO VAO5;
    VAO5.Bind();

    VBO VBO5(wall_1, sizeof(wall_1));
    EBO EBO5(indices, sizeof(indices));
    VAO5.LinkAttrib(VBO5, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
    VAO5.LinkAttrib(VBO5, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
    VAO5.LinkAttrib(VBO5, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
    VAO5.LinkAttrib(VBO5, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));

    VAO5.Unbind();
    VBO5.Unbind();
    EBO5.Unbind();

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    VAO VAO6;
    VAO6.Bind();

    VBO VBO6(wall_2, sizeof(wall_2));
    EBO EBO6(indices, sizeof(indices));
    VAO6.LinkAttrib(VBO6, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
    VAO6.LinkAttrib(VBO6, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
    VAO6.LinkAttrib(VBO6, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
    VAO6.LinkAttrib(VBO6, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));

    VAO6.Unbind();
    VBO6.Unbind();
    EBO6.Unbind();

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    VAO VAO7;
    VAO7.Bind();

    VBO VBO7(wall_3, sizeof(wall_3));
    EBO EBO7(indices, sizeof(indices));
    VAO7.LinkAttrib(VBO7, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
    VAO7.LinkAttrib(VBO7, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
    VAO7.LinkAttrib(VBO7, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
    VAO7.LinkAttrib(VBO7, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));

    VAO7.Unbind();
    VBO7.Unbind();
    EBO7.Unbind();

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    VAO VAO8;
    VAO8.Bind();

    VBO VBO8(wall_4, sizeof(wall_4));
    EBO EBO8(indices, sizeof(indices));
    VAO8.LinkAttrib(VBO8, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
    VAO8.LinkAttrib(VBO8, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
    VAO8.LinkAttrib(VBO8, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
    VAO8.LinkAttrib(VBO8, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));

    VAO8.Unbind();
    VBO8.Unbind();
    EBO8.Unbind();


    // Shader for light cube
    ShaderMap lightShader("shader-files/light.vert", "shader-files/light.frag");
    // Generates Vertex Array Object and binds it
    VAO lightVAO;
    lightVAO.Bind();
    // Generates Vertex Buffer Object and links it to vertices
    VBO lightVBO(lightVertices, sizeof(lightVertices));
    // Generates Element Buffer Object and links it to indices
    EBO lightEBO(lightIndices, sizeof(lightIndices));
    // Links VBO attributes such as coordinates and colors to VAO
    lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
    // Unbind all to prevent accidentally modifying them
    lightVAO.Unbind();
    lightVBO.Unbind();
    lightEBO.Unbind();



    glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
    glm::mat4 lightModel = glm::mat4(1.0f);
    lightModel = glm::translate(lightModel, lightPos);

    glm::vec3 objectPos = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::mat4 objectModel = glm::mat4(1.0f);
    objectModel = glm::translate(objectModel, objectPos);


    lightShader.Activate();
    glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
    glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
    shaderProgram.Activate();
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(objectModel));
    glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
    glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);


    /////////////////////////////////////////////////////////////////////////
    // trying to make a second light source
    // Shader for light cube
    // Generates Vertex Array Object and binds it
    VAO lightVAO2;
    lightVAO2.Bind();
    // Generates Vertex Buffer Object and links it to vertices
    VBO lightVBO2(lightVertices2, sizeof(lightVertices2));
    // Generates Element Buffer Object and links it to indices
    EBO lightEBO2(lightIndices, sizeof(lightIndices));
    // Links VBO attributes such as coordinates and colors to VAO
    lightVAO2.LinkAttrib(lightVBO2, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
    // Unbind all to prevent accidentally modifying them
    lightVAO2.Unbind();
    lightVBO2.Unbind();
    lightEBO2.Unbind();
    glm::vec4 lightColor2 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    glm::vec3 lightPos2 = glm::vec3(0.5f, 0.5f, 0.5f);
    glm::mat4 lightModel2 = glm::mat4(1.0f);
    lightModel2 = glm::translate(lightModel2, lightPos2);
    glm::vec3 objectPos2 = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::mat4 objectModel2 = glm::mat4(1.0f);
    objectModel2 = glm::translate(objectModel2, objectPos2);

    lightShader.Activate();
    glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel2));
    glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
    shaderProgram.Activate();
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(objectModel));
    glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
    glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
    ///////////////////////////////////////////////////////////////////////////////////////////////////

    /*
    * I'm doing this relative path thing in order to centralize all the resources into one folder and not
    * duplicate them between tutorial folders. You can just copy paste the resources from the 'Resources'
    * folder and then give a relative path from this folder to whatever resource you want to get to.
    * Also note that this requires C++17, so go to Project Properties, C/C++, Language, and select C++17
    */
    //std::string parentDir = (fs::current_path().fs::path::parent_path()).string();

    //std::string parentDir =  "C:/Users/Beno�t/Documents/Doom-Quake-CG/doom-quake";
    //std::string parentDir =  "C:/Users/Benoît/Documents/Doom-Quake-CG/doom-quake";
    std::string parentDir =  "/Users/lennertsteyaert/Documents/GitHub/Doom-Quake-CG/doom-quake";
    std::string texPath = "/model-files/plank/";

    // Textures
    Texture planksTex((parentDir + texPath + "planks.png").c_str(), GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE);
    planksTex.texUnit(shaderProgram, "tex0", 0);
    // GL_RED because the planksSpec.png image contains only gray values (black and white)
    Texture planksSpec((parentDir + texPath + "planksSpec.png").c_str(), GL_TEXTURE_2D, 1, GL_RED, GL_UNSIGNED_BYTE);
    planksSpec.texUnit(shaderProgram, "tex1", 1);

    // Original code from the tutorial
    /*Texture planksTex("planks.png", GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE);
    planksTex.texUnit(shaderProgram, "tex0", 0);
    Texture planksSpec("planksSpec.png", GL_TEXTURE_2D, 1, GL_RED, GL_UNSIGNED_BYTE);
    planksSpec.texUnit(shaderProgram, "tex1", 1);*/



    // Enables the Depth Buffer
    glEnable(GL_DEPTH_TEST);

    // Creates camera object
    CameraMap camera(width, height, glm::vec3(0.0f, 5.0f, 0.0f));

    // Main while loop
    while (!glfwWindowShouldClose(window))
    {
        // Specify the color of the background
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        // Clean the back buffer and depth buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Handles camera inputs
        camera.Inputs(window);
        // Updates and exports the camera matrix to the Vertex Shader
        camera.updateMatrix(45.0f, 0.1f, 100.0f);


//        // Tells OpenGL which Shader Program we want to use
//        shaderProgram.Activate();
//        // Exports the camera Position to the Fragment Shader for specular lighting
//        glUniform3f(glGetUniformLocation(shaderProgram.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
//        // Export the camMatrix to the Vertex Shader of the pyramid
//        camera.Matrix(shaderProgram, "camMatrix");
//        // Binds textures so that they appear in the rendering
//        planksTex.Bind();
//        planksSpec.Bind();
//        // Bind the VAO so OpenGL knows to use it
//        VAO1.Bind();
//        // Draw primitives, number of indices, datatype of indices, index of indices
//        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
//
//
//        // Tells OpenGL which Shader Program we want to use
//        shaderProgram.Activate();
//        // Exports the camera Position to the Fragment Shader for specular lighting
//        glUniform3f(glGetUniformLocation(shaderProgram.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
//        // Export the camMatrix to the Vertex Shader of the pyramid
//        camera.Matrix(shaderProgram, "camMatrix");
//        // Binds textures so that they appear in the rendering
//        planksTex.Bind();
//        planksSpec.Bind();
//        VAO2.Bind();
//        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);


//        // Tells OpenGL which Shader Program we want to use
//        shaderProgram.Activate();
//        // Exports the camera Position to the Fragment Shader for specular lighting
//        glUniform3f(glGetUniformLocation(shaderProgram.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
//        // Export the camMatrix to the Vertex Shader of the pyramid
//        camera.Matrix(shaderProgram, "camMatrix");
//        // Binds textures so that they appear in the rendering
//        planksTex.Bind();
//        planksSpec.Bind();
//        VAO3.Bind();
//        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);


        // Tells OpenGL which Shader Program we want to use
        shaderProgram.Activate();
        // Exports the camera Position to the Fragment Shader for specular lighting
        glUniform3f(glGetUniformLocation(shaderProgram.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
        // Export the camMatrix to the Vertex Shader of the pyramid
        camera.Matrix(shaderProgram, "camMatrix");
        // Binds textures so that they appear in the rendering
        planksTex.Bind();
        planksSpec.Bind();
        VAO4.Bind();
        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);

        // Tells OpenGL which Shader Program we want to use
        shaderProgram.Activate();
        // Exports the camera Position to the Fragment Shader for specular lighting
        glUniform3f(glGetUniformLocation(shaderProgram.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
        // Export the camMatrix to the Vertex Shader of the pyramid
        camera.Matrix(shaderProgram, "camMatrix");
        // Binds textures so that they appear in the rendering
        planksTex.Bind();
        planksSpec.Bind();
        VAO5.Bind();
        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);

        // Tells OpenGL which Shader Program we want to use
        shaderProgram.Activate();
        // Exports the camera Position to the Fragment Shader for specular lighting
        glUniform3f(glGetUniformLocation(shaderProgram.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
        // Export the camMatrix to the Vertex Shader of the pyramid
        camera.Matrix(shaderProgram, "camMatrix");
        // Binds textures so that they appear in the rendering
        planksTex.Bind();
        planksSpec.Bind();
        VAO6.Bind();
        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);

        // Tells OpenGL which Shader Program we want to use
        shaderProgram.Activate();
        // Exports the camera Position to the Fragment Shader for specular lighting
        glUniform3f(glGetUniformLocation(shaderProgram.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
        // Export the camMatrix to the Vertex Shader of the pyramid
        camera.Matrix(shaderProgram, "camMatrix");
        // Binds textures so that they appear in the rendering
        planksTex.Bind();
        planksSpec.Bind();
        VAO7.Bind();
        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);

        // Tells OpenGL which Shader Program we want to use
        shaderProgram.Activate();
        // Exports the camera Position to the Fragment Shader for specular lighting
        glUniform3f(glGetUniformLocation(shaderProgram.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
        // Export the camMatrix to the Vertex Shader of the pyramid
        camera.Matrix(shaderProgram, "camMatrix");
        // Binds textures so that they appear in the rendering
        planksTex.Bind();
        planksSpec.Bind();
        VAO8.Bind();
        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);


        // Tells OpenGL which Shader Program we want to use
        lightShader.Activate();
        // Export the camMatrix to the Vertex Shader of the light cube
        camera.Matrix(lightShader, "camMatrix");
        // Bind the VAO so OpenGL knows to use it
        lightVAO.Bind();
        lightVAO.Bind();
        // Draw primitives, number of indices, datatype of indices, index of indices
        glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);


        // Tells OpenGL which Shader Program we want to use
        lightShader.Activate();
        // Export the camMatrix to the Vertex Shader of the light cube
        camera.Matrix(lightShader, "camMatrix");
        // Bind the VAO so OpenGL knows to use it
        lightVAO2.Bind();
        lightVAO2.Bind();
        // Draw primitives, number of indices, datatype of indices, index of indices
        glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);


        // Swap the back buffer with the front buffer
        glfwSwapBuffers(window);
        // Take care of all GLFW events
        glfwPollEvents();
    }



//    // Delete all the objects we've created
//    VAO1.Delete();
//    VBO1.Delete();
//    EBO1.Delete();
//
//    VAO2.Delete();
//    VBO2.Delete();
//    EBO2.Delete();
//
//    VAO3.Delete();
//    VBO3.Delete();
//    EBO3.Delete();

    VAO4.Delete();
    VBO4.Delete();
    EBO4.Delete();

    VAO5.Delete();
    VBO5.Delete();
    EBO5.Delete();

    VAO6.Delete();
    VBO6.Delete();
    EBO6.Delete();

    VAO7.Delete();
    VBO7.Delete();
    EBO7.Delete();

    VAO8.Delete();
    VBO8.Delete();
    EBO8.Delete();

    planksTex.Delete();
    planksSpec.Delete();
    shaderProgram.Delete();
    lightVAO.Delete();
    lightVBO.Delete();
    lightEBO.Delete();
    lightShader.Delete();
    // Delete window before ending the program
    glfwDestroyWindow(window);
    // Terminate GLFW before ending the program
    glfwTerminate();
    return 0;
}