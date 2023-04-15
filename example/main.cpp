#include "BoleroConfig.h"
#include "main_glfw.h"
#include <iostream>

int main(){
	std::cout << "hello bolero" << std::endl;
	return bolero::MainGlfwLoop();
}