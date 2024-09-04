#include <iostream>
#include <string>
#include <thread>


#include "window.h"




int WIDTH = 800;
int HEIGHT = 600;
static std::string title = "test";




int main() {

  using Window = mywin::XWindow;
  
  Window window(title.c_str(), WIDTH, HEIGHT);

  window.run();



  
  return 0;
}
