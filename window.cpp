#include "window.h"

namespace mywin {


  XWindow::XWindow(std::string title, int width, int height) : width_(width), height_(height), running(false) {

  display = XOpenDisplay(nullptr);
  if (!display)
    exit(1);
  
  int def_screen = DefaultScreen(display);
  X11Window root = RootWindow(display, def_screen);

  window = XCreateSimpleWindow(display, root, 0, 0, width, height, 1, BlackPixel(display, def_screen), BlackPixel(display, def_screen));
  
  XStoreName(display, window, title.c_str());

  surface = cairo_xlib_surface_create(display, window, DefaultVisual(display, def_screen), width, height);
  cr = cairo_create(surface);
}


  void XWindow::run() {

    XSelectInput(display, window, KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask);
    
    XMapWindow(display, window);
    XFlush(display); 
    
    running = true;
    event_loop();

  }

  
  void XWindow::event_loop() {

    XEvent event;

    while(running) {
      XNextEvent(display, &event);
      
      switch(event.type)
	{
	case KeyPress:

	  
        case KeyRelease:
	  //XKeyEvent *keyEvent = reinterpret_cast<XKeyEvent*>(&event);
	  bool pressed = event.type == KeyPress;
	  
	  if(!pressed) {
	    if(event.xkey.keycode == 24) {
	    
	      running = false;
	      break;
	    }
	  }
	    //case :

	  
	    //case :

	  
	    //case :
	}
    }

  }
  

XWindow::~XWindow() {

  cairo_destroy(cr);
  cairo_surface_destroy(surface);

  XDestroyWindow(display, window);
  XCloseDisplay(display);
}


} //namespace mywin 
