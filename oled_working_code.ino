#include <Wire.h> //INCLUSÃO DE BIBLIOTECA
#include <Adafruit_GFX.h> //INCLUSÃO DE BIBLIOTECA
#include <Adafruit_SSD1306.h> //INCLUSÃO DE BIBLIOTECA


#define SCREEN_I2C_ADDR 0x3D // or 0x3C
#define SCREEN_WIDTH 128     // OLED display width, in pixels
#define SCREEN_HEIGHT 64     // OLED display height, in pixels
#define OLED_RST_PIN -1      // Reset pin (-1 if not available)


Adafruit_SSD1306 display(128, 64, &Wire, OLED_RST_PIN);

void setup(){
  Wire.begin(); //INICIALIZA A BIBLIOTECA WIRE
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //INICIALIZA O DISPLAY COM ENDEREÇO I2C 0x3C
  display.setTextColor(WHITE); //DEFINE A COR DO TEXTO
  display.setTextSize(1); //DEFINE O TAMANHO DA FONTE DO TEXTO
  display.clearDisplay(); //LIMPA AS INFORMAÇÕES DO DISPLAY
}
void loop() {

  
  // ================ TOP BAR ===============
  display.setCursor(3, 3); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
  display.print("Lucas Cappra"); //ESCREVE O TEXTO NO DISPLAY
  display.display(); //EFETIVA A ESCRITA NO DISPLAY
  delay(50); //INTERVALO DE 1,5 SEGUNDOS
  // ================ END TOP BAR ===============
  

  // ================ MIDDLE SCREEN  ===============
  display.setCursor(30,30); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
  display.print("Lucas Cappra"); //ESCREVE O TEXTO NO DISPLAY
  display.display(); //EFETIVA A ESCRITA NO DISPLAY
  delay(50); //INTERVALO DE 1,5 SEGUNDOS

  //display.clearDisplay(); //LIMPA AS INFORMAÇÕES DO DISPLAY
  
  // ================ END MIDDLE SCREEN ===============

  // ================ BOTTOM BAR ===============

  display.setCursor(128, 45); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
  display.print("Lucas Cappra"); //ESCREVE O TEXTO NO DISPLAY
  display.display(); //EFETIVA A ESCRITA NO DISPLAY
  delay(50); //INTERVALO DE 1,5 SEGUNDOS
  //display.clearDisplay(); //LIMPA AS INFORMAÇÕES DO DISPLAY
  // ================ END BOTTOM BAR ===============
}