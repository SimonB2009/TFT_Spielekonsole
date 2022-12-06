#include <MCUFRIEND_kbv.h>
//#include "draw.h"
#include <Adafruit_GFX.h>
#include <TouchScreen.h>
#define YP A1  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 7   // can be a digital pin
#define XP 6   // can be a digital pinvoid TickTackToebild();
void TickTackToefunktionen();
void malen();
TSPoint getPoint();

MCUFRIEND_kbv tft(A3, A2, A1, A0, A4);
TouchScreen ts(XP,YP, XM, YM, 0);
Adafruit_GFX_Button button_spielen;
Adafruit_GFX_Button button_malen;
Adafruit_GFX_Button button_menu;
Adafruit_GFX_Button button_farbe_wechseln;

int status = 0; // 2 Button: 0. Menu, 1. TickTAckToe , 2. malen , 5. nichts

void setup() {
  
  //tft2.initLCD();
  tft.begin(tft.readID());
  tft.fillScreen(TFT_WHITE);  //Hintergrund wird auf weiß gesetzt
  button_menu.initButton(&tft,160,80,380,100, TFT_BLACK,TFT_YELLOW,TFT_BLACK,"Hauptmenu",3); //Kordinaten vom Menuezeile
  button_spielen.initButton(&tft,110,390,250,80, TFT_BLACK,TFT_LIGHTGREY,TFT_BLACK,"Spielen",2); //Kordinaten vom Spielen Butten im Menue
  button_malen.initButton(&tft,110,260,250,80, TFT_BLACK,TFT_LIGHTGREY,TFT_BLACK,"Malen",2); //Kordinaten vom Malen Butten im Menue
  button_farbe_wechseln.initButton(&tft,160,430,180,80,TFT_BLACK,TFT_RED,TFT_BLACK,"Farbe",2);
  
}

void loop() {
  
    TSPoint p = ts.getPoint();
    pinMode(YP, OUTPUT);      //restore shared pins
    pinMode(XM, OUTPUT);
    digitalWrite(YP, HIGH);   //because TFT control pins
    digitalWrite(XM, HIGH);

if (status==0) { //Hauptmenu
  
  button_spielen.drawButton();  
  button_malen.drawButton();
  button_menu.drawButton();
  status = 5;

}

if (p.y <470 && p.y > 390 && p.x <360 && p.x >110) { //TickTackToe wird gestartet

  status = 1;
}

if (p.y <340 && p.y > 260 && p.x <360 && p.x >110) { //malen wird gestatrtet
   
  status = 2;
  }

if (status == 1) {
   TickTackToebild(); //TickTackToe Spielfeld anzeigen
  
   if (status==5) {
  
        TickTackToefunktionen(); //funktionsfähigen Button und Schrift ausgeben (malen)
  }
}  
  
if (status == 2) {

  malen();
  }
}

void TickTackToebild() {
  
  tft.fillScreen(TFT_WHITE);  //Hintergrund auf weiß setzen
  tft.drawFastHLine(10,140,290,TFT_BLACK); //zweite Linie zeichnen
  tft.drawFastHLine(10,260,290,TFT_BLACK); //dritte Linie zeichnen
  tft.drawFastVLine(95,50,300,TFT_BLACK);  //vierte Linie zeichnen
  tft.drawFastVLine(205,50,300,TFT_BLACK); //fünfte Linie zeichnen
  status = 5;
}

void TickTackToefunktionen() {
  
    button_farbe_wechseln.drawButton();
    tft.drawPixel(p.x,p.y);
    
    /*int farbe=TFT_BLUE;
   if (Butten == gedrueckt && Button == TFT_BLUE) { // ?

     farbe=TFT_RED;
   }

   if (Button == gedrueckt && Button == TFT_RED) { // ?

     farbe=TFT_BLUE;
   }
   tft.drawPixel(?,?,farbe); //malen ,,,,, ? = Tuch read x/y
   tft.drawButton(?); //Button blau/rot, zum farbe wechseln
*/
}

void malen() {

  for (int i=5, i=0, i++) {
    
  tft.drawPixel(p.x,p.y,TFT_RED);
  }
}


