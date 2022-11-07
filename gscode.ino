#include <LiquidCrystal.h>


#define ledgreen1 13
#define ledred1 12
#define trigger1 9
#define echo1 8

#define ledgreen2 11
#define ledred2 10
#define trigger2 7
#define echo2 6

float distancia1;
float distancia2;
int vaga1;
int vaga2;
int ocupado1;
int ocupado2;
int vagaLivre;
int vagaOcupada;

LiquidCrystal lcd(0,1,2,3,4,5);


void setup()
{
  lcd.begin(16, 2);
  
  pinMode(ledgreen1, OUTPUT);
  pinMode(ledred1, OUTPUT);
  pinMode(trigger1, OUTPUT);
  pinMode(echo1, INPUT);
  
  pinMode(ledgreen2, OUTPUT);
  pinMode(ledred2, OUTPUT);
  pinMode(trigger2, OUTPUT);
  pinMode(echo2, INPUT);
  
  
  

}

void loop()
{

  digitalWrite(trigger1, HIGH);
  digitalWrite(trigger1, LOW);
  distancia1 = 0.01715 * pulseIn(echo1, HIGH);
  
  digitalWrite(trigger2, HIGH);
  digitalWrite(trigger2, LOW);
  distancia2 = 0.01715 * pulseIn(echo2, HIGH);
 
  
  if(distancia1 < 200){ //ocupado
    digitalWrite(ledgreen1, LOW);
    digitalWrite(ledred1, HIGH);
    vaga1 = 0;
    ocupado1 = 1;
  }else{ //livre
    digitalWrite(ledgreen1, HIGH);
    digitalWrite(ledred1, LOW);
    vaga1 = 1;
    ocupado1 = 0;
  }
  
  if(distancia2 < 200){ //ocupado
    digitalWrite(ledgreen2, LOW);
    digitalWrite(ledred2, HIGH);
    vaga2 = 0;
    ocupado2 = 1;
  }else{ // livre
    digitalWrite(ledgreen2, HIGH);
    digitalWrite(ledred2, LOW);
    vaga2 = 1;
    ocupado2 = 0;
  }
  vagaLivre = vaga1 + vaga2;
  vagaOcupada = ocupado1 + ocupado2;
  lcd.setCursor(0, 0);
  lcd.print("Vagas Livres   "); 
  lcd.print(vagaLivre); 
  
  lcd.setCursor(0, 1);
  lcd.print("Vagas Ocupadas "); 
  lcd.print(vagaOcupada);
  
  Serial.println(distancia1);
    
  
}