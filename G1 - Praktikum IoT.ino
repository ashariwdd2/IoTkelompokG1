#define redLedA 16
#define pirA 5
#define greenLedA 4

#define redLedB 0
#define pirB 2
#define greenLedB 14

#define redLedC 12
#define pirC 13
#define greenLedC 15

int car = 5;

int redTimeA = 0, greenTimeA = 20;
int redTimeB = 20, greenTimeB = 0;
int redTimeC = 40, greenTimeC = 0;

int getPirA = 0;
int getPirB = 0;
int getPirC = 0;

void setup()
{
  pinMode(redLedA, OUTPUT);
  pinMode(pirA, INPUT);
  pinMode(greenLedA, OUTPUT);
  
  pinMode(redLedB, OUTPUT);
  pinMode(pirB, INPUT);
  pinMode(greenLedB, OUTPUT);
  
  pinMode(redLedC, OUTPUT);
  pinMode(pirC, INPUT);
  pinMode(greenLedC, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  getPirA = digitalRead(pirA);
  getPirB = digitalRead(pirB);
  getPirC = digitalRead(pirC);
  if(greenTimeA > 0) {
    digitalWrite(redLedA, LOW);
      digitalWrite(greenLedA, HIGH);
    
      digitalWrite(redLedB, HIGH);
      digitalWrite(greenLedB, LOW);
      
      digitalWrite(redLedC, HIGH);
      digitalWrite(greenLedC, LOW);
    } else if(greenTimeB > 0) {
      digitalWrite(redLedA, HIGH);
      digitalWrite(greenLedA, LOW);
    
      digitalWrite(redLedB, LOW);
      digitalWrite(greenLedB, HIGH);
      
      digitalWrite(redLedC, HIGH);
      digitalWrite(greenLedC, LOW);
    } else if(greenTimeC > 0) {
      digitalWrite(redLedA, HIGH);
      digitalWrite(greenLedA, LOW);
    
      digitalWrite(redLedB, HIGH);
      digitalWrite(greenLedB, LOW);
      
      digitalWrite(redLedC, LOW);
      digitalWrite(greenLedC, HIGH);
    }
  
  if(getPirA == HIGH) {
    if(greenTimeB > 0) {
      greenTimeB = greenTimeB - car;
      redTimeC = redTimeC - car;
      redTimeA = redTimeA - car - car;
    } else if(greenTimeC > 0) {
      greenTimeC = greenTimeC - car;
      redTimeA = redTimeA - car;
      redTimeB = redTimeB - car - car;
    } else {
      greenTimeA = greenTimeA + car;
    
      redTimeB = redTimeB + car;
      
      redTimeC = redTimeC + car + car;
    } 
  } else if(getPirB == HIGH) {
    if(greenTimeA > 0) {
      greenTimeA = greenTimeA - car;
      redTimeB = redTimeB - car;
      redTimeC = redTimeC - car - car;
    } else if(greenTimeC > 0) {
      greenTimeC = greenTimeC - car;
      redTimeA = redTimeA - car;
      redTimeB = redTimeB - car - car;
    } else {
      redTimeA = redTimeA + car + car;
    
      greenTimeB = greenTimeB + car;
        
      redTimeC = redTimeC + car;
    }
  } else if(getPirC == HIGH) {
    if(greenTimeA > 0) {
      greenTimeA = greenTimeA - car;
      redTimeB = redTimeB - car;
      redTimeC = redTimeC - car - car;
    } else if(greenTimeB > 0) {
      greenTimeB = greenTimeB - car;
      redTimeC = redTimeC - car;
      redTimeA = redTimeA - car - car;
    } else {
      redTimeA = redTimeA + car;
      
      redTimeB = redTimeB + car + car;
        
      greenTimeC = greenTimeC + car;
    }
  }
  
  if(greenTimeA == 1 && redTimeC > 0) {
    redTimeA = 40;
    greenTimeA = 0;
    
    redTimeB = 0;
    greenTimeB = 20;
    
    redTimeC = 20;
    greenTimeC = 0;
  } else if(greenTimeB == 1 && redTimeA > 0) {
    redTimeA = 20;
    greenTimeA = 0;
    
    redTimeB = 40;
    greenTimeB = 0;
    
    redTimeC = 0;
    greenTimeC = 20;
  } else if(greenTimeC == 1 && redTimeB > 0) {
    redTimeA = 0;
    greenTimeA = 20;
    
    redTimeB = 20;
    greenTimeB = 0;
    
    redTimeC = 40;
    greenTimeC = 0;
  }
  
  if(redTimeA > 0) {
    redTimeA = redTimeA - 1;
  } else if (greenTimeA > 0) {
    greenTimeA = greenTimeA - 1;
  }
  
  if(redTimeB > 0) {
    redTimeB = redTimeB - 1;
  } else if (greenTimeB > 0) {
    greenTimeB = greenTimeB - 1;
  }
  
  if(redTimeC > 0) {
    redTimeC = redTimeC - 1;
  } else if (greenTimeC > 0) {
    greenTimeC = greenTimeC - 1;
  }
  
  
  
  delay(1000);
  if (getPirA == HIGH) {
    Serial.println("pirA: masuk");
  } else {
    Serial.println("pirA: mati");
  }
  Serial.print("redTimeA: ");
  Serial.println(redTimeA);
  Serial.print("greenTimeA: ");
  Serial.println(greenTimeA);

  if (getPirB == HIGH) {
    Serial.println("pirB: masuk");
  } else {
    Serial.println("pirB: mati");
  }
  Serial.print("redTimeB: ");
  Serial.println(redTimeB);
  Serial.print("greenTimeB: ");
  Serial.println(greenTimeB);

  if (getPirC == HIGH) {
    Serial.println("pirC: masuk");
  } else {
    Serial.println("pirC: mati");
  }
  Serial.print("redTimeC: ");
  Serial.println(redTimeC);
  Serial.print("greenTimeC: ");
  Serial.println(greenTimeC);
  
  Serial.println("=======================\n");
  getPirA = 0;
  getPirB = 0;
  getPirC = 0;
}
