//
// Created by Lennert Steyaert on 14/03/2022.
//

#include <Engine.h>



// Triangle
//{
//-0.5f, -0.5f, 0.0f,
//0.5f, -0.5f, 0.0f,
//0.0f,  0.5f, 0.0f}

//
//GLfloat floor_[] =
//{ //     COORDINATES     /        COLORS        /    TexCoord    /       NORMALS     //
//        -10.0f, 0.0f, 10.0f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,		10.0f, 1.0f, 0.0f,
//        -10.0f, 0.0f, -10.0f,		0.0f, 0.0f, 0.0f,		0.0f, 1.0f,		10.0f, 1.0f, 0.0f,
//        10.0f, 0.0f, -10.0f,		0.0f, 0.0f, 0.0f,		1.0f, 1.0f,		10.0f, 1.0f, 0.0f,
//        10.0f, 0.0f, 10.0f,		0.0f, 0.0f, 0.0f,		1.0f, 0.0f,		10.0f, 1.0f, 0.0f
//};



Engine::Engine() :
vertices{
//        0.5f,  0.5f, 0.0f,          1.0f, 0.0f, 0.0f,        // top right
//        0.5f, -0.5f, 0.0f,          1.0f, 0.0f, 0.0f,        // bottom right
//        -0.5f, -0.5f, 0.0f,      1.0f, 0.0f, 0.0f,           // bottom left
//        -0.5f,  0.5f, 0.0f,      1.0f, 0.0f, 0.0f            // top left
//        // positions         // colors
//        0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
//        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
//        0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top
        // positions         // colors
//        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,        // top right
//        0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,      // bottom right
//        -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   // bottom left
//        -0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f   // top left
        -10.0f, 0.0f, 10.0f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,		10.0f, 1.0f, 0.0f,
        -10.0f, 0.0f, -10.0f,		0.0f, 0.0f, 0.0f,		0.0f, 1.0f,		10.0f, 1.0f, 0.0f,
        10.0f, 0.0f, -10.0f,		0.0f, 0.0f, 0.0f,		1.0f, 1.0f,		10.0f, 1.0f, 0.0f,
        10.0f, 0.0f, 10.0f,		0.0f, 0.0f, 0.0f,		1.0f, 0.0f,		10.0f, 1.0f, 0.0f
        },
indices{
//        0, 1, 3,   // first triangle
//        1, 2, 3    // second triangle

                0, 1, 2,
                0, 2, 3
}
{
    //initBuffer();
    //initShader();


    // Cube test
    ourShader = std::make_unique<Shader>("shader-files/texture.vs", "shader-files/texture.fs");
//
//    glm::vec3 objectPos = glm::vec3(0.0f, 0.0f, 0.0f);
//    glm::mat4 objectModel = glm::mat4(1.0f);
//    objectModel = glm::translate(objectModel, objectPos);
//
//    ourShader->setMat4("model",objectModel);


    //  Model shader
    //ourShader = std::make_unique<Shader>(shaderPaths[defaultVertex],shaderPaths[defaultFragment]);
    //ourShader = std::make_unique<Shader>(shaderPaths[modelLoadingVertex],shaderPaths[modelLoadingFragment]);

    //model = std::make_unique<Model>("model-files/backpack/backpack.obj");
    //model = std::make_unique<Model>("model-files/body/FinalBaseMesh.obj");
    //model = std::make_unique<Model>("model-files/Humvee_models/Humvee.obj");


    camera = std::make_unique<Camera>(glm::vec3(0.0f, 0.0f, 3.0f));
    //camera = std::make_unique<Camera>(SCR_WIDTH, SCR_HEIGHT, glm::vec3(0.0f, 5.0f, 0.0f));

    cube = std::make_unique<CubeModel>(ourShader.get());


//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
//    glEnableVertexAttribArray(1);

//    // Generates Shader object using shaders default.vert and default.frag
//    Shader shaderProgram("shader-files/default.vert", "shader-files/default.frag");
//    // Generates Vertex Array Object and binds it


//    VAO1 = std::make_unique<VAO>();
//    VAO1->Bind();
//
//    // Generates Vertex Buffer Object and links it to vertices
//    VBO1 = std::make_unique<VBO>(vertices, sizeof(vertices));
//
//    // Generates Element Buffer Object and links it to indices
//    EBO1 =  std::make_unique<EBO>(indices, sizeof(indices));
//
//
//    ourShader = std::make_unique<Shader>("shader-files/default.vert", "shader-files/default.frag");
//    // Links VBO attributes such as coordinates and colors to VAO
//    VAO1->LinkAttrib(*VBO1, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
//    VAO1->LinkAttrib(*VBO1, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
//    VAO1->LinkAttrib(*VBO1, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
//    VAO1->LinkAttrib(*VBO1, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
//    // Unbind all to prevent accidentally modifying them
//    VAO1->Unbind();
//    VBO1->Unbind();
//    EBO1->Unbind();
//
//    std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
//    std::string texPath = "/model-files/plank/";
//
//    // Textures
//    planksTex = std::make_unique<Texture>((parentDir + texPath + "planks.png").c_str(), GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE);
//    planksTex->texUnit(*ourShader.get(), "tex0", 0);
//    // GL_RED because the planksSpec.png image contains only gray values (black and white)
//    planksSpec = std::make_unique<Texture>((parentDir + texPath + "planksSpec.png").c_str(), GL_TEXTURE_2D, 1, GL_RED, GL_UNSIGNED_BYTE);
//    planksSpec->texUnit(*ourShader.get(), "tex1", 1);

}

void Engine::initBuffer(){
//    glGenBuffers(1, &VBO);
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &EBO);
}

//void Engine::initShader(){
//    vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//    glCompileShader(vertexShader);
//
//    int  success;
//    char infoLog[512];
//    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//
//    if(!success)
//    {
//        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//    glCompileShader(fragmentShader);
//
//    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//
//    if(!success)
//    {
//        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//
//    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//    if(!success) {
//        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    glUseProgram(shaderProgram);
//
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);
//}


void Engine::setupVBO(){
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void Engine::setupVAO(){
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void Engine::setupEBO(){
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void Engine::loop(GLFWwindow *window) {
    // per-frame time logic
    // --------------------
    float currentFrame = static_cast<float>(glfwGetTime());
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    this->keyHandler(window);

    glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//    camera->Inputs(window);
//    camera->updateMatrix(45.0f, 0.1f, 100.0f);

    //glUseProgram(shaderProgram);

    //ourShader->use();
    cube->draw(ourShader.get());

//    glUniform3f(glGetUniformLocation(ourShader->ID, "camPos"), camera->Position.x, camera->Position.y, camera->Position.z);
//    camera->Matrix(*ourShader, "camMatrix");
//    planksTex->Bind();
//    planksSpec->Bind();
//    // Bind the VAO so OpenGL knows to use it
//    VAO1->Bind();
//    // Draw primitives, number of indices, datatype of indices, index of indices
//    glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);


    //    ourShader->setFloat("someUniform", 1.0f);
//    glBindVertexArray(VAO);
//    //glDrawArrays(GL_TRIANGLES, 0, 3);
//    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//    glBindVertexArray(0);




//    // view/projection transformations
//    glm::mat4 projection = glm::perspective(glm::radians(camera->Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//    glm::mat4 view = camera->GetViewMatrix();
//    ourShader->setMat4("projection", projection);
//    ourShader->setMat4("view", view);
//
//    // render the loaded model
//    glm::mat4 m = glm::mat4(1.0f);
//    m = glm::translate(m, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
//    m = glm::scale(m, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
//    ourShader->setMat4("model", m);
//    Shader* test = ourShader.get();
//    this->model->Draw(test);
}

void Engine::keyHandler(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        std::cout << "W pressed" << std::endl;
        camera->ProcessKeyboard(FORWARD, deltaTime);
    }

    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        std::cout << "S pressed" << std::endl;
        camera->ProcessKeyboard(BACKWARD, deltaTime);
    }

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        std::cout << "A pressed" << std::endl;
       camera->ProcessKeyboard(LEFT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        std::cout << "D pressed" << std::endl;
        camera->ProcessKeyboard(RIGHT, deltaTime);
    }
}
// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void Engine::mouseHandler(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera->ProcessMouseMovement(xoffset, yoffset);
    std::cout << "mouse movement" << std::endl;
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void Engine::scrollHandler(GLFWwindow* window, double xoffset, double yoffset)
{
    std::cout << "mouse scroll" <<  std::endl;
    camera->ProcessMouseScroll(static_cast<float>(yoffset));
}

void Engine::mouseHandler_static(GLFWwindow *window, double xposIn, double yposIn)
{
    Engine *engine = static_cast<Engine *>(glfwGetWindowUserPointer(window));
    engine->mouseHandler(window,xposIn,yposIn);
}

void Engine::scrollHandler_static(GLFWwindow* window, double xoffset, double yoffset)
{
    Engine *engine = static_cast<Engine *>(glfwGetWindowUserPointer(window));
    engine->scrollHandler(window,xoffset,yoffset);
}