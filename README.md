Simple mouse logger for Linux
=============================

**Compile**
Alter following line to read your device mouse input
```
#define MOUSEFILE "/dev/input/event2"
```
You can check this with `lsinput` tool.

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