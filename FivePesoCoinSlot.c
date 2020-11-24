//constants and PIN Declarations
const byte interruptPin = 3;
volatile int val5 = 0;
volatile int cnt5 = 0; 
volatile int totl = 0;

const int rPin01 = 8;
const int rPin02 = 7;
const int ledP01 = 12;
const int ledP02 = 11;

unsigned long previousMillis = 0;
const long interval = 1000;

int mins;   
int secs;

//debug settings
double water_timer = 0;
int water_value = 0;
int timer_count = 0;
double buffer_vals = 0;


//initial run of ARDUINO
void setup() {
  // put your setup code here, to run once:
  pinMode(interruptPin, INPUT_PULLUP);
  pinMode(rPin01, OUTPUT);
  pinMode(rPin02, OUTPUT);
  pinMode(ledP01, OUTPUT);
  pinMode(ledP02, OUTPUT);
  
  
  Serial.begin(9600);
  
  Serial.println("Coin Detection: ");
  Serial.println("AMOUNT");
  
  
  attachInterrupt(digitalPinToInterrupt(interruptPin), coinFive, RISING);
  water_timer = 0;
  buffer_vals = 0;
  digitalWrite(rPin01, HIGH);
  digitalWrite(rPin02, HIGH);
}

void loop() {

  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

  
    if(water_timer >= 60000) {
      water_timer = water_timer - 1000;
      digitalWrite(ledP02, HIGH);
      digitalWrite(ledP01, HIGH);
      Serial.println(water_timer);
      digitalWrite(rPin01, LOW);
      digitalWrite(rPin02, LOW);
      
    } else if(water_timer >= 5000) {
      water_timer = water_timer - 1000;
      digitalWrite(ledP02, LOW);
      digitalWrite(ledP01, HIGH);
      Serial.println(water_timer);
      digitalWrite(rPin01, LOW);
      digitalWrite(rPin02, LOW);

    } else if(water_timer < 5000 && water_timer >= 1000){
      digitalWrite(ledP02, LOW);
      digitalWrite(ledP01, LOW);
      digitalWrite(rPin01, HIGH);
      digitalWrite(rPin02, HIGH);
      
    } else {
      water_timer = 0;
      digitalWrite(ledP02, LOW);
      digitalWrite(ledP01, LOW);
      digitalWrite(rPin01, HIGH);
      digitalWrite(rPin02, HIGH);
      
    }
  
  } 
}


void coinFive() {
  cnt5++;
  val5 = (cnt5 * 5);
  
  water_timer = 130000;

  
  
  Serial.println("\n");
  Serial.println("5 Peso coin = \r ");
  Serial.print(val5);
  Serial.print(" Pesos");
  Serial.println("\n");
  Serial.println("Total Time is: ");
  
  Serial.print(water_timer);

}
