
// Vinicius - 222240202
// Julian - 222240301
// Manuella - 222240293

// Esse é o codigo referente ao primeirot projeto de Computacao movel
#include <LiquidCrystal.h>

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0


int tempo = 120;

int buzzer = 10;
int melody[] = {

  NOTE_G4,8, NOTE_A4,8, NOTE_B4,4, NOTE_D5,4, NOTE_D5,4, NOTE_B4,4, 
  NOTE_C5,4, NOTE_C5,2, NOTE_G4,8, NOTE_A4,8,
  NOTE_B4,4, NOTE_D5,4, NOTE_D5,4, NOTE_C5,4,

  NOTE_B4,2, REST,8, NOTE_G4,8, NOTE_G4,8, NOTE_A4,8,
  NOTE_B4,4, NOTE_D5,4, REST,8, NOTE_D5,8, NOTE_C5,8, NOTE_B4,8,
  NOTE_G4,4, NOTE_C5,4, REST,8, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8,

  NOTE_A4,4, NOTE_B4,4, REST,8, NOTE_B4,8, NOTE_A4,8, NOTE_G4,8,
  NOTE_G4,2, REST,8, NOTE_G4,8, NOTE_G4,8, NOTE_A4,8,
  NOTE_B4,4, NOTE_D5,4, REST,8, NOTE_D5,8, NOTE_C5,8, NOTE_B4,8,

  NOTE_G4,4, NOTE_C5,4, REST,8, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8,
  NOTE_A4,4, NOTE_B4,4, REST,8, NOTE_B4,8, NOTE_A4,8, NOTE_G4,8,
  NOTE_G4,4, NOTE_F5,8, NOTE_D5,8, NOTE_E5,8, NOTE_C5,8, NOTE_D5,8, NOTE_B4,8,

  NOTE_C5,8, NOTE_A4,8, NOTE_B4,8, NOTE_G4,8, NOTE_A4,8, NOTE_G4,8, NOTE_E4,8, NOTE_G4,8,
  NOTE_G4,4, NOTE_F5,8, NOTE_D5,8, NOTE_E5,8, NOTE_C5,8, NOTE_D5,8, NOTE_B4,8,
  NOTE_C5,8, NOTE_A4,8, NOTE_B4,8, NOTE_G4,8, NOTE_A4,8, NOTE_G4,8, NOTE_E4,8, NOTE_G4,8,
  NOTE_G4,-2, REST,4
  
};

int notes = sizeof(melody) / sizeof(melody[0]) / 2;

int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;


int inicio = 0; //Variavel para logica de mostrar o menu ou desistir 

//Jogo da memoria
int sequencia[10];//Armazena uma sequencia aleatoria 
int comp[10]; //Armazena as respostas que o usuario coloca  
int perc = 0; //Faz as contagens das respostas certas 

//Jogo da perguntas
const char *listaPerguntas[10] = {"Faz 12 anos que o ryu joga baseball?", 
                                "A cor preferida do ryu e azul?",
                                "O ryu ja foi coordenador de TI?",
                                "Faz 8 anos que a manu gosta do bts?",
                                "A comida preferida da manu e macarrao?",
                                "A manu tem blusa que nao e cropped?",
                                "O palmeiras e o maior time do mundo?",
                                "Existe cor mais bonita que verde?",
                                "O nome do gusttavo lima e nivaldo?",
                                "Nos tres participamos da Junior?"
                               };//Banco de perguntas

const int listaRespostas[10] = {2,  // Não
                                1,  // Sim
                                2,
                                1,
                                1,
                                1,
                                1,
                                2,
                                1,
                                1
                               };//Banco das respostas
////////////////////////////////////////////////////////////////////////////////

//setup
LiquidCrystal lcd_1(12, 11, 7, 6, 5, 4);

void setup() {
  pinMode(3, INPUT_PULLUP); // Sim e verde
  pinMode(2, INPUT_PULLUP); // Nao e vermelho
  pinMode(13, INPUT); // LIGA/DESLIGA
  pinMode(10, OUTPUT); // Buzzer
  pinMode(8, OUTPUT); // Verde
  pinMode(9, OUTPUT); // Vermelho

  lcd_1.begin(16, 2);
  lcd_1.print("Seja bem vindo");
  lcd_1.setCursor(0, 1);
  lcd_1.print("Pressione iniciar");
  lcd_1.setCursor(1, 1);
  Serial.begin(9600);
  
  randomSeed(analogRead(0));
}
////////////////////////////////////////////////////////////////////////////////

// decidimos segregar o nosso código em funcoes, por esse motivo
// a funcao loop esta bem curta. 
void loop() {
  start(); //Vai pra funcao que inicializa o jogo

  if (digitalRead(3)) { //Recebe a cor verde como resposta para o jogo da memoria
    digitalWrite(8, HIGH);
    delay(500);
    digitalWrite(8, LOW);
    delay(500);
    verde();
    delay(200);
  }

  if (digitalRead(2)) { //Recebe a cor vermelha como resposta para o jogo da memoria
    digitalWrite(9, HIGH);
    delay(500);
    digitalWrite(9, LOW);
    delay(500);
    vermelho();
    delay(200);
  }
}
////////////////////////////////////////////////////////////////////////////////

//menu
void menu() {
  lcd_1.clear();
  lcd_1.print("Seja bem vindo");
  lcd_1.setCursor(0, 1);
  lcd_1.print("Pressione iniciar");
  lcd_1.setCursor(1, 1);
}
////////////////////////////////////////////////////////////////////////////////

// A logica da funcao iniciar consiste em verificar o resto da 
// divisao por 2 da variavel int inicio. se o resto for 0, o
// programa se encerra e reinicia, se for 1, o programa inicia.
int start() {
  if (digitalRead(13)) {
    inicio++;
    if (inicio % 2 == 0) { 
      lcd_1.clear();
      lcd_1.setCursor(0, 0);
      lcd_1.print("Ate logo");
      tone(10, 400, 500);
      delay(500);
      noTone(10);

      delay(1000);

      lcd_1.clear();
      lcd_1.print("Seja bem vindo");
      lcd_1.setCursor(0, 1);
      lcd_1.print("Pressione iniciar");
      lcd_1.setCursor(1, 1);
      perc = 0;
    } else {
      lcd_1.display();
      lcd_1.clear();
      lcd_1.setCursor(0, 0);
      lcd_1.print("Iniciando o jogo");

      delay(1000);

      seqaleatoria();
      perc = 0;
      //pergResp();
      //ultPergunta();
    }
  }
}
////////////////////////////////////////////////////////////////////////////////

// a logica do jogo da memoria dos leds consiste em, primeiramente,
// armazenar em uma lista de caracteres uma sequencia aleatoria.
// posteriormente, com a nossa lista ja criada, ele mostra ao usu-
// ario a sequencia, piscando os leds.

// mais abaixo, você perceberá a funcao de verificar a sequencia.
// continuarei os comentarios por la.
void seqaleatoria() {
  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print("Memorize as");
  lcd_1.setCursor(0, 1);
  lcd_1.print("cores dos LEDs ");

  for (int i = 0; i < 10; i++) { // Coloca uma sequencia aleatoria entre 0 e 1 
    sequencia[i] = random(0, 2);
  }

  for (int i = 0; i < 10; i++) { //Mostra a sequencia que foi armazenada com os leds
    if (sequencia[i] == 0) {
      digitalWrite(8, HIGH);
      delay(500);
      digitalWrite(8, LOW);
      delay(500);
    }
    if (sequencia[i] == 1) {
      digitalWrite(9, HIGH);
      delay(500);
      digitalWrite(9, LOW);
      delay(500);
    }
  }
  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print("Agora repita");
  lcd_1.setCursor(0, 1);
  lcd_1.print("a sequencia");
}
////////////////////////////////////////////////////////////////////////////////

//Verde e vermelho
void verde() { //Usuario clica no led verde
  comp[perc] = 0;
  verificaSeque();
}

void vermelho() { //Usuario clica no led vermelho
  comp[perc] = 1;
  verificaSeque();
}
////////////////////////////////////////////////////////////////////////////////

// nesse momento, verificsremos se o usuario acertou a sequencia.
// colocamos todas as respostas do usuário dentro de uma outra
// lista. assim, comparamos as duas. todas as vezes que uma posicao
// é igual em ambas as listas, incrementamos a variavel percurso,
// que armazena quantos acertos o usuario teve.
void verificaSeque() { //Verifica a sequencia aleatoria no jogo da memoria
  int note = 200;
  for (int i = 0; i <= perc; i++) { //A variavel perc é usada para limitar ate onde o usuario respondeu
    if (sequencia[i] == comp[i]) { //Compara a resposta do usuario com a resposta armazenada
      lcd_1.clear();
      lcd_1.setCursor(0, 0);
      lcd_1.print("Sequencia: ");
      lcd_1.print(perc + 1);
      lcd_1.setCursor(0, 1);
      lcd_1.print("Correto");
      tone(10, note, 100);
      note += 50;
      delay(100);
      noTone(10);
    } else { //Caso alguma comparacao esteja incorreta
      lcd_1.clear();
      lcd_1.setCursor(0, 0);
      lcd_1.print("Errou");
      tone(10, 500, 200);
      delay(200);
      noTone(10);
      delay(1000);
      lcd_1.clear();
      lcd_1.setCursor(3, 0);
      lcd_1.print("Reiniciando");
      lcd_1.setCursor(5, 1);
      lcd_1.print("o jogo");
      delay(1000);
      inicio++;
      menu();
    }
  }
  perc++;
  delay(500);
  vitoriaMemoria(perc);
}
////////////////////////////////////////////////////////////////////////////////

// aqui fizemos essa funcaozinha apenas para tocar a musica
// da vitoria de chamar a proxima funcsao
void vitoriaMemoria(int perc) { //Vitoria no jogo da memoria
  if (perc == 10) {
    lcd_1.clear();
    lcd_1.setCursor(4, 0);
    lcd_1.print("Parabens");

    tone(10, 1500, 200);
    delay(200);
    noTone(10);
    delay(500);

    tone(10, 262, 300);
    delay(300);
    noTone(10);
    delay(100);

    tone(10, 294, 300);
    delay(300);
    noTone(10);
    delay(100);

    tone(10, 330, 300);
    delay(300);
    noTone(10);
    delay(100);

    tone(10, 349, 300);
    delay(300);
    noTone(10);
    delay(100);

    tone(10, 392, 300);
    delay(300);
    noTone(10);
    delay(100);

    tone(10, 440, 300);
    delay(300);
    noTone(10);
    delay(100);

    tone(10, 494, 300);
    delay(300);
    noTone(10);
    delay(100);

    tone(10, 523, 300);
    delay(300);
    noTone(10);
    delay(100);

    tone(10, 784, 500);
    delay(500);
    noTone(10);

    delay(500);

    pergResp();
  }
}
////////////////////////////////////////////////////////////////////////////////

// a logica do jogo das perguntas consinste tambem em uma lista.
// montamos uma lista que funciona como um banco de perguntas.
// atraves de um laco de repeticao, tratamos uma pergunta de cada
// vez. o laco se repete apenas 5 vezes.
// a cada vez que o usuario pressiona o botao de resposta, o valor
// é armazenado na variavel resposta, e assim comparado com o gaba-
// rito que é uma lista já criada.
// caso o usuário erre alguma resposta, a funcao é terminada e
// o fluxo retorna para o LOOP. se o usuário acertar todas, a funcao
// é executada até o fim, e assim, chama-se a funcao da ultima
// pergunta.

void pergResp() { //Jogo de pergunta e resposta
  lcd_1.clear();
  lcd_1.setCursor(4, 0);
  lcd_1.print("Fase de");
  lcd_1.setCursor(3, 1);
  lcd_1.print("Perguntas");
  delay(2000);
  
  lcd_1.clear();
  lcd_1.setCursor(2, 0);
  lcd_1.print("Responda Sim");
  lcd_1.setCursor(5, 1);
  lcd_1.print("ou nao");
  delay(2000);
  
  int vidas = 1;
  int respondidas = 0;
  
  while (respondidas < 5) {  //Enquanto o usuario nao responder 5 perguntas certas ele nao sai do laco, apenas se ele responder errado ou pular 2 perguntas
    int randNumber = random(10);
    lcd_1.clear();
    lcd_1.setCursor(3, 0);
   
    lcd_1.print(listaPerguntas[randNumber]);
    for (int j = 0; j < strlen(listaPerguntas[randNumber]) - 13; j++) { //Mostrar a pergunta
        lcd_1.scrollDisplayLeft();
        delay(300);
    }
    delay(1000);

    lcd_1.clear();
    lcd_1.setCursor(1, 0);
    lcd_1.print("Questao ");
    lcd_1.print(respondidas + 1);
    lcd_1.print(" de 5");
    lcd_1.setCursor(3, 1);
    lcd_1.print("Sim ou Nao");
    delay(1000);
    
    int resposta = 0;
    bool pular = false;
    unsigned long tempoInicial = millis();
    unsigned long tempoLimite = 10000; // 10 segundos de tempo para responder
    
    lcd_1.clear();
    // Loop para aguardar a resposta ou o tempo esgotar
    while ((millis() - tempoInicial) < tempoLimite) {
      lcd_1.setCursor(4, 0);
      lcd_1.print("Tempo: ");
      int tempo = (tempoLimite - (millis() - tempoInicial)) / 1000;
      lcd_1.print(tempo); // Atualiza cronômetro
      lcd_1.print("   "); // Espaços extras para limpar os dígitos antigos
      lcd_1.setCursor(3, 1);
      lcd_1.print("Sim ou Nao");
      
      if(tempo < 5){
        tone(10, 1000, 100);
        delay(100);
        noTone(10);
      }

      if (digitalRead(3)) { // Botão 'Sim' pressionado
        resposta = 1;
        break;
      }
      if (digitalRead(2)) { // Botão 'Não' pressionado
        resposta = 2;
        break;
      }
    }
    
    if (resposta == 0) {
      lcd_1.clear();
      lcd_1.setCursor(0, 0);
      lcd_1.print("Questao pulada");
      tone(10, 500, 500);
      delay(500);
      noTone(10);
      delay(1500);
      vidas--;
      pular = true;
      if (vidas < 0) {
        lcd_1.clear();
        lcd_1.setCursor(0, 0);
        lcd_1.print("Fim de jogo");
        delay(2000);
        inicio++;
        menu();
        return;
      }
     }else {
      if (resposta == listaRespostas[randNumber]) { 
        lcd_1.clear();
        lcd_1.setCursor(0, 0);
        lcd_1.print("Correto!");
        tone(10, 1000, 500);
        delay(500);
        noTone(10);
        delay(1500);
      } else {
        lcd_1.clear();
        lcd_1.setCursor(0, 0);
        lcd_1.print("Errado!");
        tone(10, 400, 500);
        delay(500);
        noTone(10);
        delay(1500);
        lcd_1.clear();
        lcd_1.setCursor(0, 0);
        lcd_1.print("Fim de jogo");
        delay(2000);
        inicio++;
        menu();
        return;
      }
    }
    if (!pular) { 
      respondidas++;
    }
    
    noTone(10);
    delay(2000);
  }

  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print("Fim das perguntas!");
  tone(10, 2000, 500);
  delay(500);
  noTone(10);
  delay(2000);
  ultPergunta();
}

// para a ultima pergunta, criamos uma logica unica, pois nao
// precisaremos tratar de multiplas respostas.
// portanto, removemos o laco de repeticao, deixando o codigo
// unitario.
void ultPergunta(){
  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print("Ultima pergunta");
  delay(2000);
  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print("Teste sua sorte");
  delay(2000);

  int resposta = 0;
  unsigned long tempoInicial = millis(); 
  unsigned long tempoLimite = 10000; 
  
  lcd_1.clear();
  while ((millis() - tempoInicial) < tempoLimite) {
  	lcd_1.setCursor(4, 0);
    lcd_1.print("Tempo: ");
    lcd_1.print((tempoLimite - (millis() - tempoInicial)) / 1000);
    lcd_1.print("  ");
    lcd_1.setCursor(3, 1);
    lcd_1.print("Sim ou Nao");
    if (digitalRead(3)) {
      resposta = 1; 
      delay(50);
    }
    if (digitalRead(2)) {
      resposta = 2; 
      delay(50);
    }
  
    if (resposta == 1) {
      lcd_1.clear();
      lcd_1.setCursor(0, 0);
      lcd_1.print("Errado!");
      tone(10, 400, 500);
      delay(500);
      noTone(10);
      delay(2000);
  	  inicio++;
 	  menu();
      return;
	} else if (resposta == 2) {
  	  lcd_1.clear();
  	  lcd_1.setCursor(0, 0);
  	  lcd_1.print("Correto!");
  	  tone(10, 1000, 500);
  	  delay(500);
  	  noTone(10);
  	  delay(1000);
      vitoria();
      return;
	}
  }
  
  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print("Tempo Esgotado!");
  tone(10, 300, 1000); 
  delay(1000);
  noTone(10);
  delay(2000);
  inicio++;
  menu(); 

}

void vitoria() { //Vitoria no jogo da memoria
    lcd_1.clear();
    lcd_1.setCursor(4, 0);
    lcd_1.print("Parabens");
  	delay(1000);

    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    divider = melody[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; 
    }

    tone(buzzer, melody[thisNote], noteDuration * 0.9);

    delay(noteDuration);

    noTone(buzzer);
  }
  	
  	lcd_1.clear();
  	lcd_1.setCursor(2, 0);
  	lcd_1.print("Fim de jogo");
  	delay(2000);
  	inicio++;
  	menu();
}
////////////////////////////////////////////////////////////////////////////////
