#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

int main(int argc, char **argv){
  Display *dpy = XOpenDisplay(NULL);
  int screen = DefaultScreen(dpy);
  Window root = RootWindow(dpy, screen);
  char name[] = "/home/florian/GIT/bg_anim/readBitmap/img_test.xbm";
  Pixmap bitmap;
  unsigned int ww, hh;
  int hot_x, hot_y;
  int status = XReadBitmapFile(dpy, root, name, &ww, &hh, &bitmap, &hot_x,
      &hot_y);
  if (status == BitmapSuccess){
    XSetWindowBackgroundPixmap(dpy, root, bitmap);
    XFreePixmap(dpy, bitmap);
  } else
    printf("This is not working \n");
  printf("Status code : %d\n", status);
  XClearWindow(dpy, root);
  XCloseDisplay(dpy);
  return(0);
}
