Simple mouse logger for Linux
=============================

**Compile**

Alter following line in `mlogger.c`:
```c
#define MOUSEFILE "/dev/input/event2"
```
You can check the correct mouse device this with `lsinput` tool.

Then:
```
gcc mlogger.c -lX11 -o mlogger
```

**Run**
```
sudo ./mlogger
```

**Generate image**
```
php mimage.php
```
