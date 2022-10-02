#include<iostream>
#include"GLFW/glfw3.h"
#include"configure.h"
#ifdef USE_ADDER
    #include"Adder/add.h"
#endif
float add(float a, float b);
int main(){
    #ifdef USE_ADDER
        std::cout << "Hello World 1" << add(3.0f, 4.0f);
    #else   
        std::cout << "Turn ON for adding" ;
    #endif
    
    GLFWwindow* window;
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }
    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }
    while( !glfwWindowShouldClose(window) )
    {
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();

    // Exit program
    exit( EXIT_SUCCESS );
}