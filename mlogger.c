#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <linux/input.h>
#include <fcntl.h>
#include <X11/Xlib.h>

#define MOUSEFILE "/dev/input/event2"

#define _LMB 272
#define _RMB 273

int main()
{
	int fd;
	FILE *flog;
	struct input_event ie;
	Display *dpy;
	Window root, child;
	int rootX, rootY, winX, winY;
	unsigned int mask;

	dpy = XOpenDisplay(NULL);
	XQueryPointer(dpy, DefaultRootWindow(dpy), &root, &child, &rootX, &rootY, &winX, &winY, &mask);

	if((fd = open(MOUSEFILE, O_RDONLY)) == -1) {
		perror("opening device");
		exit(EXIT_FAILURE);
	}

	flog = fopen("mouse.log", "a");

	while(read(fd, &ie, sizeof(struct input_event))) {
		if ((ie.code == _LMB || ie.code == _RMB) && ie.value == 1) {
			XQueryPointer(dpy, DefaultRootWindow(dpy), &root, &child, &rootX, &rootY, &winX, &winY, &mask);
			fprintf(flog, "%d\t%d\t%d\n", ie.code, rootX, rootY);
			fflush(flog);
		}
	}

	return 0;
}