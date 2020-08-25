const int LED=2; //Define o pino 2 como pino do LED
const int PinSensor=A5; //Define o pino 5 como pino do sensor
int LeituraSensor;  // Define um inteiro para Leitura do sensor
float Temperatura, VoltagemSensor;  // Define um número real para temperatura e voltagem
void setup()
{
  pinMode(LED,OUTPUT); // Define o Led como saida
  pinMode(PinSensor, INPUT); // Define a entrada do sensor
}
void Piscar(int tempo)  // Função para piscar um LED
{
 digitalWrite(LED,HIGH); // Liga o LED
 delay(tempo);   		// Aguarda um tempo
 digitalWrite(LED,LOW); //Desliga o LED
 delay(tempo);          //Aguarda um tempo
}
void loop()
{
  LeituraSensor=analogRead(PinSensor); // Faz a leitura da entrda
  VoltagemSensor=LeituraSensor*4.887; //Regra de três -> 5000/1023
  // 1023  - > 5000 mv
  // Leitura -> ?   mv
  Temperatura=((VoltagemSensor)-500)/10;//Equação do sensor TMP36
  if (Temperatura>40) //Pergunta se a temperatura é maior de 40
  {
    Piscar(300);  //Chama a função piscar com 300ms de tempo
  }
  else
  {
    Piscar(1000); //Chama a função piscar com 1000ms de tempo
  }
}
