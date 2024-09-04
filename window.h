#pragma once

#include <string>

#include <cairo/cairo.h>
#include <cairo-xlib.h>

#include <X11/Xlib.h>
#include <X11/X.h>


typedef XID Window;

using X11Window = ::Window;

//struct Display;

namespace mywin {

class XWindow {
 private:
  Display* display;
  X11Window window;

  cairo_surface_t *surface;
  cairo_t *cr;
  
  int width_;
  int height_;

  bool running;
  
 public:
  XWindow(std::string title, int width, int height);
  ~XWindow();

  void run();
  void event_loop();
  
};

 
} //namespace Window
