#include <FNT.h>

FNT::FNT(const uint8_t *fd) : Font(fd) {
    _header = (struct fntHeader *)fd;
    _name = (const char *)&fd[_header->dfFace];
    _fontData = &fd[_header->dfBitsOffset];
}


int FNT::getStringWidth(const char *str) {
    int w = 0;
    while (*str) {
        w += getCharacterWidth(*str++);
    }
    return w;
}

int FNT::getStringHeight(const char *str) {
    return _header->dfPixHeight;
}

uint8_t FNT::getCharacterWidth(uint8_t glyph) {
    return _header->dfPixWidth;
}

uint8_t FNT::getStartGlyph() {
    return _header->dfFirstChar;
}

uint8_t FNT::getEndGlyph() {
    return _header->dfLastChar;
}

int FNT::drawChar(DisplayCore *dev, int x, int y, uint8_t c, color_t fg, color_t bg) {

    if (c < _header->dfFirstChar || c > _header->dfLastChar) return 0;

    int lines = _header->dfPixHeight;

    c -= _header->dfFirstChar;

    uint32_t bpl = ((_header->dfPixWidth - 1) / 8) + 1;
    uint32_t bpc = bpl * lines;

    if (fg != bg) {
        for (int py = 0; py < lines; py++) {
            int fy = y + py;
            for (int px = 0; px < _header->dfPixWidth; px++) {
                int fx = x + px;
                uint8_t col = px / 8;
                uint8_t bit = px % 8;
                uint32_t offset = (bpc * c) + (col * lines) + py;
                uint8_t b = _fontData[offset];
                if (b & (0x80 >> bit)) {
                    dev->setPixel(fx, fy, fg);
                } else {
                    dev->setPixel(fx, fy, bg);
                }
            }
        }
    } else {
        dev->openWindow(x, y, _header->dfPixWidth, _header->dfPixHeight);
        for (int py = 0; py < lines; py++) {
            int fy = y + py;
            for (int px = 0; px < _header->dfPixWidth; px++) {
                int fx = x + px;
                uint8_t col = px / 8;
                uint8_t bit = px % 8;
                uint32_t offset = (bpc * c) + (col * lines) + py;
                uint8_t b = _fontData[offset];
                if (b & (0x80 >> bit)) {
                    dev->windowData(fg);
                } else {
                    dev->windowData(bg);
                }
            }
        }
        dev->closeWindow();
    }

    return _header->dfPixWidth;
}
