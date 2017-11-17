#include <LiquidCrystal.h>
String code = "";
long freq,t1,t2;
const int rs = 12, en = 11, d4 = 6, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void mario(void);
long frequency(void);
void convertor(void);
void sendLcd(char);
int col = 0;
void setup () {
    lcd.begin(16, 2);
    lcd.setCursor(0,0);
    lcd.print("Wireless Morse!");
    Serial.begin(115200);       
    Serial.println("Morse Decoder");
    pinMode(4,OUTPUT);
    //lcd.setCursor(0, 1);

  } // end of setup

void loop(){
  char temp;
// stamp:
  freq = frequency();
    Serial.println(freq);
    while(freq < 750 || freq>950){
      freq = frequency();
    } //wait till frequency crosses 700
    if (freq > 750 && freq <950){ // lower limit 700 ,upper linmit 1000 
      t1 = millis();
      while(( millis() - t1) < 5000){
        temp = readio();
        if(temp != '~'){code+=temp;} 
        Serial.println(code);//function to read dot or dash
          delay(400);
        //break;
       }
       convertor();
       tone(9,5000,1500);
    }
    //if(code == ""){goto stamp;}
    
}

long frequency (void){

  unsigned int fx;
    fx = (930000/pulseIn(5,HIGH));
    return(fx);
}

 void convertor(void){
  char tolcd;
  Serial.println("Converter Entered");
  static String letters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
                             ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "E"
                            };
  int i = 0;

    if (code == "....."){
      Serial.print("."); 
      sendLcd(' ');//for break
    }
    else if (code == "----"){
      col = 16;
      sendLcd(' ');
    }
      else if (code == "-----"){mario();}
    
    else{
        while (letters[i] != "E"){  //Loop to compare
            if (letters[i] == code){   
              tolcd = (char('A' + i));
              Serial.print(tolcd);
              sendLcd(tolcd);
              break;
            } 
         i++;
      }
      if (letters[i] == "E")
      {
         //sendLcd('#');
         Serial.println("<Wrong input>");  //if input code doesn't match any letter, error
      }
    }
    code = "";
} 


char readio(){ 
  //Serial.println("Char Read");
    freq = frequency();
    if (freq>700 && freq<800){
      //Serial.println(".");
      tone(9,500);
      delay(200);
      noTone(9);
       return '.';                        //if freq less than 800, it is a dot
    }
    else if (freq > 800&& freq<950){
      //Serial.println("-");
      tone(9,1000);
      delay(200);
      noTone(9);
      return '-';                        //if more than 800 and less than 900, it is a dash
  }
  delay(100);
    return '~';
}

void sendLcd(char data){
  if(col < 16){
    lcd.setCursor(col,1);
    lcd.write(data);
    col++;
  }
  if(col > 15){
    for(int i=0;i<16;i++){
      lcd.setCursor(i,1);
      lcd.write(' ');
    }
    col = 0;
    lcd.setCursor(col,1);
    lcd.write(data);
  }
}
void mario(void){
tone(9,660,100);
delay(150);
tone(9,660,100);
delay(300);
tone(9,660,100);
delay(300);
tone(9,510,100);
delay(100);
tone(9,660,100);
delay(300);
tone(9,770,100);
delay(550);
tone(9,380,100);
delay(575);

tone(9,510,100);
delay(450);
tone(9,380,100);
delay(400);
tone(9,320,100);
delay(500);
tone(9,440,100);
delay(300);
tone(9,480,80);
delay(330);
tone(9,450,100);
delay(150);
tone(9,430,100);
delay(300);
tone(9,380,100);
delay(200);
tone(9,660,80);
delay(200);
tone(9,760,50);
delay(150);
tone(9,860,100);
delay(300);
tone(9,700,80);
delay(150);
tone(9,760,50);
delay(350);
tone(9,660,80);
delay(300);
tone(9,520,80);
delay(150);
tone(9,580,80);
delay(150);
tone(9,480,80);
delay(500);

tone(9,510,100);
delay(450);
tone(9,380,100);
delay(400);
tone(9,320,100);
delay(500);
tone(9,440,100);
delay(300);
tone(9,480,80);
delay(330);
tone(9,450,100);
delay(150);
tone(9,430,100);
delay(300);
tone(9,380,100);
delay(200);
tone(9,660,80);
delay(200);
tone(9,760,50);
delay(150);
tone(9,860,100);
delay(300);
tone(9,700,80);
delay(150);
tone(9,760,50);
delay(350);
tone(9,660,80);
delay(300);
tone(9,520,80);
delay(150);
tone(9,580,80);
delay(150);
tone(9,480,80);
delay(500);

tone(9,500,100);
delay(300);

tone(9,760,100);
delay(100);
tone(9,720,100);
delay(150);
tone(9,680,100);
delay(150);
tone(9,620,150);
delay(300);

tone(9,650,150);
delay(300);
tone(9,380,100);
delay(150);
tone(9,430,100);
delay(150);

tone(9,500,100);
delay(300);
tone(9,430,100);
delay(150);
tone(9,500,100);
delay(100);
tone(9,570,100);
delay(220);

tone(9,500,100);
delay(300);

tone(9,760,100);
delay(100);
tone(9,720,100);
delay(150);
tone(9,680,100);
delay(150);
tone(9,620,150);
delay(300);

tone(9,650,200);
delay(300);

tone(9,1020,80);
delay(300);
tone(9,1020,80);
delay(150);
tone(9,1020,80);
delay(300);

tone(9,380,100);
delay(300);
tone(9,500,100);
delay(300);

tone(9,760,100);
delay(100);
tone(9,720,100);
delay(150);
tone(9,680,100);
delay(150);
tone(9,620,150);
delay(300);

tone(9,650,150);
delay(300);
tone(9,380,100);
delay(150);
tone(9,430,100);
delay(150);

tone(9,500,100);
delay(300);
tone(9,430,100);
delay(150);
tone(9,500,100);
delay(100);
tone(9,570,100);
delay(420);

tone(9,585,100);
delay(450);

tone(9,550,100);
delay(420);

tone(9,500,100);
delay(360);

tone(9,380,100);
delay(300);
tone(9,500,100);
delay(300);
tone(9,500,100);
delay(150);
tone(9,500,100);
delay(300);

tone(9,500,100);
delay(300);

tone(9,760,100);
delay(100);
tone(9,720,100);
delay(150);
tone(9,680,100);
delay(150);
tone(9,620,150);
delay(300);

tone(9,650,150);
delay(300);
tone(9,380,100);
delay(150);
tone(9,430,100);
delay(150);

tone(9,500,100);
delay(300);
tone(9,430,100);
delay(150);
tone(9,500,100);
delay(100);
tone(9,570,100);
delay(220);

tone(9,500,100);
delay(300);

tone(9,760,100);
delay(100);
tone(9,720,100);
delay(150);
tone(9,680,100);
delay(150);
tone(9,620,150);
delay(300);

tone(9,650,200);
delay(300);

tone(9,1020,80);
delay(300);
tone(9,1020,80);
delay(150);
tone(9,1020,80);
delay(300);

tone(9,380,100);
delay(300);
tone(9,500,100);
delay(300);

tone(9,760,100);
delay(100);
tone(9,720,100);
delay(150);
tone(9,680,100);
delay(150);
tone(9,620,150);
delay(300);

tone(9,650,150);
delay(300);
tone(9,380,100);
delay(150);
tone(9,430,100);
delay(150);

tone(9,500,100);
delay(300);
tone(9,430,100);
delay(150);
tone(9,500,100);
delay(100);
tone(9,570,100);
delay(420);

tone(9,585,100);
delay(450);

tone(9,550,100);
delay(420);

tone(9,500,100);
delay(360);

tone(9,380,100);
delay(300);
tone(9,500,100);
delay(300);
tone(9,500,100);
delay(150);
tone(9,500,100);
delay(300);

tone(9,500,60);
delay(150);
tone(9,500,80);
delay(300);
tone(9,500,60);
delay(350);
tone(9,500,80);
delay(150);
tone(9,580,80);
delay(350);
tone(9,660,80);
delay(150);
tone(9,500,80);
delay(300);
tone(9,430,80);
delay(150);
tone(9,380,80);
delay(600);

tone(9,500,60);
delay(150);
tone(9,500,80);
delay(300);
tone(9,500,60);
delay(350);
tone(9,500,80);
delay(150);
tone(9,580,80);
delay(150);
tone(9,660,80);
delay(550);

tone(9,870,80);
delay(325);
tone(9,760,80);
delay(600);

tone(9,500,60);
delay(150);
tone(9,500,80);
delay(300);
tone(9,500,60);
delay(350);
tone(9,500,80);
delay(150);
tone(9,580,80);
delay(350);
tone(9,660,80);
delay(150);
tone(9,500,80);
delay(300);
tone(9,430,80);
delay(150);
tone(9,380,80);
delay(600);

tone(9,660,100);
delay(150);
tone(9,660,100);
delay(300);
tone(9,660,100);
delay(300);
tone(9,510,100);
delay(100);
tone(9,660,100);
delay(300);
tone(9,770,100);
delay(550);
tone(9,380,100);
delay(575);

}

