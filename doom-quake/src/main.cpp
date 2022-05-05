 #include <Engine.h>

 // https://learnopengl.com/Getting-started/Shaders
 void framebuffer_size_callback(GLFWwindow* window, int width, int height);

 // this code was first written with the help of following URL: https://learnopengl.com/Getting-started/Hello-Window
 // which was changed everytime we implemented something new

 int width = 800;
 int height = 800;

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
     glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);


     /* Create a windowed mode window and its OpenGL context */
     window = glfwCreateWindow(width, height, "Doom-Quake", NULL, NULL);
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
     //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
     glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);



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
         engine->loop(window, width, height);

         /* Swap front and back buffers */
         glfwSwapBuffers(window);

         /* Poll for and process events */
         glfwPollEvents();
     }

//     engine->remove();
     glfwTerminate();
     return 0;
 }

 void framebuffer_size_callback(GLFWwindow* window, int w, int h)
 {
     // make sure the viewport matches the new window dimensions; note that width and
     // height will be significantly larger than specified on retina displays.
     width = w;
     height = h;
     glViewport(0, 0, w, h);
 }

//
// int main(void) {
//
//
//    BoundingBox box = BoundingBox();
//    box.centre = glm::vec3(0.0,0.0,0.0);
//    box.dimensions = glm::vec3(100.0,100.0,100.0);
//
//
//    Octree octree = Octree(box, 10);
//
//
//     BoundingBox boxm1 = BoundingBox();
//     boxm1.centre = glm::vec3(0.0,0.0,0.0);
//     boxm1.dimensions = glm::vec3(20.0,20.0,20.0);
////     boxm1.centre = glm::vec3(10.0,10.0,10.0);
////     boxm1.dimensions = glm::vec3(20.0,20.0,20.0);
//    BaseModel * m1 = new TestModel(DEFAULT,boxm1);
//
//    octree.addModel(m1);
//
//
//     BoundingBox boxm2 = BoundingBox();
//     boxm2.centre = glm::vec3(15.0,15.0,15.0);
//     boxm2.dimensions = glm::vec3(10.0,10.0,10.0);
//     BaseModel * m2 = new TestModel(DEFAULT,boxm2);
//
//     octree.addModel(m2);
//
// }
