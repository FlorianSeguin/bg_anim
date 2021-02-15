#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

int main(int argc, char **argv){
  Display *dpy = XOpenDisplay(NULL);
  if (dpy == NULL){
    printf("Connection failed\n");
    exit(1);
  }
  int screen = DefaultScreen(dpy);
  Window root = RootWindow(dpy, screen);
  XWindowAttributes winattr;
  XGCValues gc_val;
  char name[] = "/home/florian/GIT/bg_anim/readBitmap/img_test.xbm";
  unsigned int ww, hh;
  int hot_x, hot_y;
  Pixmap bitmap, newpix;
  GC gc = XCreateGC(dpy, root, GCForeground|GCBackground, &gc_val);
  int status = XReadBitmapFile(dpy, root, name, &ww, &hh, &bitmap, &hot_x,
      &hot_y);
  if (status != BitmapSuccess){
    printf("This is not working \n");
    exit(1);
  }
  newpix = XCreatePixmap(dpy, root, ww, hh,
      (unsigned int)DefaultDepth(dpy, screen));
  XCopyPlane(dpy, bitmap, newpix, gc, 0, 0, ww, hh, 0, 0,
      (unsigned long)1);
  XSetWindowBackgroundPixmap(dpy, root, newpix);
  XFreePixmap(dpy, bitmap);
  XCloseDisplay(dpy);
  return(0);
}
