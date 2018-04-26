#include <FNT.h>
#include <Picadillo.h>
#include <Wyse700b.h>

Picadillo tft;
FNT myFont(Wyse700b);

void setup() {
    tft.initializeDevice();
    tft.setBacklight(255);
    tft.setRotation(1);
    tft.fillScreen(Color::Black);
    tft.setFont(myFont);
    tft.println("The quick brown fox jumped over the lazy dog.");
}

void loop() {
}
