FNT
===

This is a Font class which takes the data from a Windows FNT bitmap font
resource. These resources are normally contained within .FON files.

You can extract FNT resources from FON files with:

    $ wrestool -t 8 --raw -x <FON file> > myFont.fnt

Wrestool is part of the `icoutils` packages on Ubuntu / Debian.

Usage
-----

```C++
#include <FNT.h>

const uint8_t *fontData = {
 0xaa, 0xbb, ... 0xff // All the font data (however you want it to be)
};


FNT myFont(fontData);

tft.setFont(myFont);
```
