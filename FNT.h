#ifndef _FNT_H
#define _FNT_H

#include <DisplayCore.h>

struct fntHeader {
  uint16_t  dfVersion; 
  uint32_t  dfSize;   
  char      dfCopyright[60]; 
  uint16_t  dfType; 
  uint16_t  dfPoints; 
  uint16_t  dfVertRes; 
  uint16_t  dfHorizRes; 
  uint16_t  dfAscent; 
  uint16_t  dfInternalLeading; 
  uint16_t  dfExternalLeading; 
  uint8_t   dfItalic; 
  uint8_t   dfUnderline; 
  uint8_t   dfStrikeOut; 
  uint16_t  dfWeight; 
  uint8_t   dfCharSet; 
  uint16_t  dfPixWidth; 
  uint16_t  dfPixHeight; 
  uint8_t   dfPitchAndFamily; 
  uint16_t  dfAvgWidth; 
  uint16_t  dfMaxWidth; 
  uint8_t   dfFirstChar; 
  uint8_t   dfLastChar; 
  uint8_t   dfDefaultChar; 
  uint8_t   dfBreakChar; 
  uint16_t  dfWidthBytes; 
  uint32_t  dfDevice; 
  uint32_t  dfFace; 
  uint32_t  dfBitsPointer;
  uint32_t  dfBitsOffset;
  uint8_t   dfReserved; 
  uint32_t  dfFlags;
} __attribute__((packed));

class FNT : public Font {
    private:
        struct fntHeader *_header;
        const char *_name;
        const uint8_t *_fontData;
    public:
        FNT(const uint8_t *fd);

        int getStringWidth(const char *str);
        int getStringHeight(const char *str);
        uint8_t getCharacterWidth(uint8_t glyph);
        uint8_t getStartGlyph();
        uint8_t getEndGlyph();
        int drawChar(DisplayCore *dev, int x, int y, uint8_t c, color_t fg, color_t bg);
        const char *getName() { return _name; }

};   

#endif
