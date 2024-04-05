#include <Wire.h> //INCLUSÃO DE BIBLIOTECA
#include <Adafruit_GFX.h> //INCLUSÃO DE BIBLIOTECA
#include <Adafruit_SSD1306.h> //INCLUSÃO DE BIBLIOTECA

#define SCREEN_I2C_ADDR 0x3D // or 0x3C
#define SCREEN_WIDTH 128     // OLED display width, in pixels
#define SCREEN_HEIGHT 64     // OLED display height, in pixels
#define OLED_RST_PIN -1      // Reset pin (-1 if not available)

 void button_reading();
 void top_bottom_bar();
int estadobotao = 0;
int var = 0;
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RST_PIN);

void setup(){
  Wire.begin(); //INICIALIZA A BIBLIOTECA WIRE
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //INICIALIZA O DISPLAY COM ENDEREÇO I2C 0x3C
  display.setTextColor(WHITE); //DEFINE A COR DO TEXTO
  display.setTextSize(0.5); //DEFINE O TAMANHO DA FONTE DO TEXTO
  display.clearDisplay(); //LIMPA AS INFORMAÇÕES DO DISPLAY
  Serial.begin(9600);

  // ===== Pins do botão para teste =====
  pinMode(9, INPUT);
}

void loop() {
  top_bottom_bar();
  button_reading();

  // ================ MIDDLE SCREEN  ===============
  display.setCursor(3,30); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
  display.print("STATUS BOTAO: "); //ESCREVE O TEXTO NO DISPLAY
  display.display(); //EFETIVA A ESCRITA NO DISPLAY
  
  
  // ================ END MIDDLE SCREEN ===============

  top_bottom_bar();
}

void button_reading(){

  estadobotao = digitalRead(9); // ler estadobotao
  Serial.println(estadobotao);
  
  if(estadobotao == 0) {
    display.setCursor(80, 30); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
    display.print("Ligado"); //ESCREVE O TEXTO NO DISPLAY
    display.display(); //EFETIVA A ESCRITA NO DISPLAY
    delay(200); //INTERVALO DE 1,5 SEGUNDOS
    display.clearDisplay(); //LIMPA AS INFORMAÇÕES DO DISPLAY
  }
  delay(15); //somente para melhorar a simulação
}

void top_bottom_bar(){
  
  // ================ TOP BAR ===============
  display.setCursor(3, 3); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
  display.print("Lucas Cappra"); //ESCREVE O TEXTO NO DISPLAY
  //delay(50); //INTERVALO DE 1,5 SEGUNDOS
  // ================ END TOP BAR ===============
  

  // ================ BOTTOM BAR ===============
  display.setCursor(128, 45); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
  display.print("Lucas Cappra"); //ESCREVE O TEXTO NO DISPLAY
  display.display(); //EFETIVA A ESCRITA NO DISPLAY
  //delay(50); //INTERVALO DE 1,5 SEGUNDOS
  //display.clearDisplay(); //LIMPA AS INFORMAÇÕES DO DISPLAY
  // ================ END BOTTOM BAR ===============
}