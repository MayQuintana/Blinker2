#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
char BotonPresionado;       // almacena la tecla pulsada
int  contador = 1;    // cuenta el nivel del menu en el que se esta
const byte ROWS = 4;  //Cuatro Filas
const byte COLS = 4;  //Cuatro Columnas 
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9,8,7,6}; //Puntos de conexion del teclado al arduino FILAS
byte colPins[COLS] = {5,4,3,2}; //Puntos de conexion del teclado al arduino COLUMNAS
Keypad Teclado1 = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //Configuracion del teclado
LiquidCrystal_I2C lcd(0x27,16,2); // dependiendo del fabricante del I2C el codigo 0x27 cambiar a
                                  // 0x3F , 0x20 , 0x38 , 

void Display_Menu();
void Deteccion_Boton();

void Display_Luz_Tiempo();
void Opciones_Menu();


////////////////////////////////// Void Setup() ///////////
void setup () { 
 lcd.init();
 lcd.backlight();
 pinMode(12, OUTPUT);
          
} 
////////////////////////// Void loop() ///////////////////////
void loop(){
BotonPresionado = Teclado1.getKey() ;  // Lee la tecla pulsada
 if (BotonPresionado != 0) {      
    lcd.clear();
    delay(100);
 } 
  if(contador == 2){ Display_Luz_Tiempo();Opciones_Menu();}
 if(contador == 1){Display_Menu();Deteccion_Boton();}
 
}  


/////////////////////Display_Menu  //////////////////////////////////
void Display_Menu(){ 
   lcd.setCursor(0,0);
   lcd.print("ON    >1  ");
   lcd.setCursor(10,0);
   lcd.print("OFF >2");   
   lcd.setCursor(10,1);
   lcd.print("MAS >*");
}
/////////////////////Deteccion_Boton//////////////////////////////
void Deteccion_Boton(){ 
  if(BotonPresionado == '1') digitalWrite(12,HIGH);
  if(BotonPresionado == '2') digitalWrite(12,LOW);
  if(BotonPresionado == '*') contador=2;
}
/////////////////////Display_Luz_Tiempo//////////////////////////////////
void Display_Luz_Tiempo(){ 
   lcd.setCursor(0,0);
   lcd.print("LUZ  >1   ");
   lcd.setCursor(8,0);
   lcd.print("TIEMPO>2");
   lcd.setCursor(0,1);
   lcd.print("MENU >#          ");
}
/////////////////////Opciones_Menu //////////////////////////////////
void Opciones_Menu(){ 
  if(BotonPresionado == '1') contador=3;
  if(BotonPresionado == '2') contador=4;
  if(BotonPresionado == '#') contador=1;
}
