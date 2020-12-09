#include "Keyboard.h" // Esta biblioteca só funciona com o Arduino Leonardo

#define VK_F13 0x7C //F13 key
#define VK_F14 0x7D //F14 key
#define VK_F15 0x7E //F15 key
#define VK_F16 0x7F //F16 key
#define VK_F17 0x80 //F17 key
#define VK_F18 0x81 //F18 key
#define VK_F19 0x82 //F19 key
#define VK_F20 0x83 //F20 key
#define VK_F21 0x84 //F21 key
#define VK_F22 0x85 //F22 key
#define VK_F23 0x86 //F23 key
#define VK_F24 0x87 //F24 key

int numbotoes = 6;
int botoes[]={2, 3, 4, 5, 6, 7}; // Pinos 2 a 7

int camadas[][]={
                {VK_F13, VK_F14, VK_F15, VK_F16, VK_F17, VK_F18}, //Teclas F13 a F18 F24
                {}
};  //definição das teclas

int camada = 0 ; //camada das teclas selecionadas
int btcamada = 16; //botao troca camada
int tempoDeResposta = 100; // Aqui você ajusta o tempo de resposta do teclado

void setup(){
  for (int i = 0; i <= numbotoes; i++){
    pinMode(botoes[i],INPUT_PULLUP); //Declara todos os pinos como entradas
  }
    
    pinMode(btcamada, INPUT_PULLUP); // Pino botão troca camada
    
    Keyboard.begin();
}// Fim do Setup

void loop() {
  for(int i = 0; i <= numbotoes; i++){
    if(digitalRead(botoes[i]) == LOW){
      Keyboard.press(camada[camada][i]);
      delay(tempoDeResposta);
      Keyboard.releaseAll();
    }

    if(digitalRead(btcamada == LOW){
      camada++;
      atualizaLCD();
      if (camada > 4){
        camada = 0;
      }
      delay(tempoDeResposta);
    }
   } 
}// Fim do loop

void atualizaLCD(){ // Implementar camada de teclas selecionada no LCD
  return void;
}

//case 1: // Alt-F1: Speaker view
//BootKeyboard.press(KEY_LEFT_ALT);
//BootKeyboard.write(KEY_F1);
//BootKeyboard.release(KEY_LEFT_ALT);
//break;
