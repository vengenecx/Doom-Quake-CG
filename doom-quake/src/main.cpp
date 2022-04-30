 #include <Engine.h>

 // https://learnopengl.com/Getting-started/Shaders
 void framebuffer_size_callback(GLFWwindow* window, int width, int height);

 // this code was first written with the help of following URL: https://learnopengl.com/Getting-started/Hello-Window
 // which was changed everytime we implemented something new

 int main(void)
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
//     window = glfwCreateWindow(800, 600, "Doom-Quake",glfwGetPrimaryMonitor(), NULL);



     if (!window)
     {
         glfwTerminate();
         return -1;
     }

     /* Make the window's context current */
     glfwMakeContextCurrent(window);

     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
     {
         std::cout << "Failed to initialize GLAD" << std::endl;
         return -1;
     }


     std::unique_ptr<Engine> engine = std::make_unique<Engine>();




     glfwSetWindowUserPointer(window, engine.get());
     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
     glfwSetCursorPosCallback(window, engine->mouseHandler_static);
     glfwSetScrollCallback(window, engine->scrollHandler_static);


     // tell GLFW to capture our mouse
//     glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);



//     glfwSetCursorPos(window, 800/2, 600/2);
     glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

     //stbi_set_flip_vertically_on_load(true);
     glEnable(GL_DEPTH_TEST);

     // Text

     glEnable(GL_BLEND);
     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

     // Setup Dear ImGui context
     IMGUI_CHECKVERSION();
     ImGui::CreateContext();
     ImGuiIO& io = ImGui::GetIO(); (void)io;

     ImGui::StyleColorsDark();
     ImGui_ImplGlfw_InitForOpenGL(window, true);

     const char* glsl_version = "#version 150";
     ImGui_ImplOpenGL3_Init(glsl_version);



     // Wireframe
     //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

     /* Loop until the user closes the window */
     while (!glfwWindowShouldClose(window))
     {
         /* Render here */
         //glClear(GL_COLOR_BUFFER_BIT);

         /* Render in engine */
         engine->loop(window);

         /* Swap front and back buffers */
         glfwSwapBuffers(window);

         /* Poll for and process events */
         glfwPollEvents();
     }

//     engine->remove();
     glfwTerminate();
     return 0;
 }

 void framebuffer_size_callback(GLFWwindow* window, int width, int height)
 {
     // make sure the viewport matches the new window dimensions; note that width and
     // height will be significantly larger than specified on retina displays.
     glViewport(0, 0, width, height);
 }