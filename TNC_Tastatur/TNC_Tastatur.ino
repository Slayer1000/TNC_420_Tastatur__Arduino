
#include <stdio.h>
//#include "stm32h7xx_hal.h"
#include <string.h>
#include <iostream>
#include <algorithm>
#include <iterator>

using std::cout; using std::endl;
using std::string; using std::reverse;


// Define the row and scan line pins
#define RL0 22
#define RL1 24
#define RL2 26
#define RL3 28
#define RL4 30
#define RL5 32
#define RL6 34
#define RL7 36
#define RL8 38
#define RL9 40
#define RL10 42
#define RL11 43
#define RL12 45
#define RL13 47
#define RL14 49
#define RL15 50
#define RL16 51
#define RL17 52
#define RL18 53
#define RL19 39
#define RL20 41
#define RL21 44
#define RL22 46
#define RL23 48

#define SL0 23
#define SL1 25
#define SL2 27
#define SL3 29
#define SL4 31
#define SL5 33
#define SL6 35
#define SL7 37


#define RLS 24
#define SLS 8

  char* keys[RLS][SLS] = {
  {"END", "+-", "3", "6", "9","ENT","HAND","Lenkrad"},
  {"Leer_neben_Lenkrad", "0", "2", "5", "8","NO_ENT","Load_Hand","HELP"},
  {"Q_Num_Pad", ".", "1", "4", "5","Zentrieren_Num_Pad","Load_Einzelsatz","RUN_Prog"},
  {"Touch_Probe", "IV", "Z", "Y", "X","DEl_NUM_PAD","Load_Programm","P_NUM_PAD"},
  {"PGM_Call", "LBL_CALL", "STOP", "C", "CALC", "CE", "Load_Prog", "I_NUM_PAD"},
    {"Leer_neben_Tool_Call", "LBL_SET", "MOD", "CC", "ERR", "Kreuz_Links", "Kreuz_Unten", "48"},
    {"Tool_Call", "CYCL_CALL", "RND", "CR", "Leer_neben_PGM", "GOTO", "55", "56"},
    {"Tool_Def", "CYCL_DEF", "CT", "Linear", "PGM_MGT", "Kreuz_Oben", "Kreuz_Rechts", "64"},
    {"APPR_DEP", "FK", "Leer_neben_FK", "CHF", "Achse_V", "leer_Num_PAD", "71", "72"},
    {"73", "74", "75", "76", "77", "78", "79", "80"},
    {"81", "82", "83", "84", "85", "86", "87", "88"},
    {"89", "90", "91", "92", "93", "94", "95", "96"},
    {"97", "98", "99", "100", "101", "102", "103", "104"},
    {"105", "106", "107", "108", "109", "110", "111", "112"},
    {"113", "114", "115", "116", "117", "118", "119", "120"},
    {"121", "122", "123", "124", "125", "126", "127", "128"},
    {"!", "#", "Ausrufezeichen", "Q", "Shift", "A", "Space", "Z"},
    {"$", "%", "W", "E", "S", "D", "X", "C"},
    {"Dach", "&", "R", "T", "F", "G", "V", "B"},
    {"*", "(", "Y", "U", "H", "J", "N", "M"},
    {")", "-", "I", "O", "K", "L", ",", "."},
    {"+", "=", "P", "Pfeilnl", ";", "Pfeilnr", "?", "sond_backslash_und_anderer"},
    {"Back", "178", "RET", "180", ":", "182", "Space", "184"},
    {"185", "186", "187", "188", "189", "190", "191", "192"}
};

// Define the pin mapping for RLS and scan lines
uint32_t row_pins[RLS] = {RL0, RL1, RL2, RL3, RL4, RL5, RL6, RL7, RL8, RL8, RL10, RL11, RL12, RL13, RL14, RL15, RL16, RL17, RL18, RL19, RL20, RL21, RL22, RL23 };
uint32_t col_pins[SLS] = {SL0, SL1, SL2, SL3, SL4, SL5, SL6, SL7};

void keypad_init() {
  // Setze alle Zeilen-Pins auf Eingang mit Pull-Up-Widerständen
  for (int i = 0; i < RLS; i++) {
    pinMode(row_pins[i], INPUT_PULLUP);
  }

  // Setze alle Spalten-Pins auf Ausgang
  for (int i = 0; i < SLS; i++) {
    pinMode(col_pins[i], OUTPUT);
  }
}

// Scanne die Tastatur und gib die gedrückte Taste zurück
string keypad_scan() {

  for (int col = 0; col < SLS; col++) {
    // Setze die aktuelle Spalte auf LOW
    digitalWrite(col_pins[col], LOW);

    for (int row = 0; row < RLS; row++) {
      // Überprüfe, ob die aktuelle Zeile LOW ist
      if (digitalRead(row_pins[row]) == LOW) {
        // Eine Taste wurde gedrückt, geben Sie die entsprechende Zeichen zurück
        delay(50); // Entprellung
        while (digitalRead(row_pins[row]) == LOW); // Warten bis Taste losgelassen wird
        digitalWrite(col_pins[col], HIGH);
        string Taste = keys[row][col];
        return Taste;

      }
    }

    // Setze die aktuelle Spalte wieder auf HIGH
    digitalWrite(col_pins[col], HIGH);
  }

  // Keine Taste gedrückt
  return "";
}


void setup(){
  Serial.begin(9600);
    keypad_init();
}

void loop() {
  string key = keypad_scan();

  if (key != "") {
    // Mache etwas mit der gedrückten Taste
      Serial.println(key.c_str());
  }

  //(key == "156") ? Serial.println("test156") : "";

    if (key == "IV") {
      //Serial.println("IV");
    };
        if (key == "1") {
      //Serial.println("1");
    }
   
}
