#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int upButton = 10;
int downButton = 9;
int selectButton = 8;

int menu = 1;

int LED = 7;


void setup() {
  lcd.begin(16, 2);

  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  
  pinMode(LED, OUTPUT);

  updateMenu();
}


void loop() {
  if (!digitalRead(downButton)) {
    menu++;
    updateMenu();
    delay(100);
  }

  if (!digitalRead(upButton)) {
    menu--;
    updateMenu();
    delay(100);
    
  }

  if (!digitalRead(selectButton)) {
    execute();
    updateMenu();
    delay(100);
    
  }	
}


// ############# Opciones de menu #############

void updateMenu() {
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      lcd.print(">Encender LED");
      lcd.setCursor(0, 1);
      lcd.print(" Apagar LED");
      break;
    case 2:
      lcd.clear();
      lcd.print(" Encender LED");
      lcd.setCursor(0, 1);
      lcd.print(">Apagar LED");
      break;
   
   }
}

// ############ Ejecucion del menu #############
void execute() {
  switch (menu) {
    case 1:
      action1();
      break;
    case 2:
      action2();
      break;
    
  }
}


// ############## Acciones del menu  #############

void action1() {
  lcd.clear();
  lcd.print(">Encendiendo");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  
  digitalWrite(LED, HIGH);
  
  delay(500);
}

void action2() {
  lcd.clear();
  lcd.print(">Apagando");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  
  digitalWrite(LED, LOW);
  
  delay(500);
}
