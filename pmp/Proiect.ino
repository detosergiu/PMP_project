int triggerPin = 50 ; //triggering on pin 
int echoPin = 51;    //echo on pin
int LED = 13; //led pin
int info = 0;//variable for the information comming from the bluetooth module
int state = 0;//simple variable for displaying the state

void setup() { 
  
  Serial3.begin(9600);  
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT); //defining pins
  pinMode(echoPin, INPUT);
  pinMode(LED, OUTPUT);    //defining LED pinbnmbnbmnbnbm
  digitalWrite(LED, LOW);  
  
}

void loop(){     
  bluetooth();
  sensor();
}


void bluetooth() { //loop from the bluetooth code is renamed to "bluetooth" void
  if(Serial.available()){  //if there is any information comming from the serial lines...
    info = Serial.read();   
    state = 0;   //...than store it into the "info" variable
  }
  if(info == '1'){                
    digitalWrite(LED, HIGH);    
    if(state == 0){              
      Serial.println("LED ON");  
      state = 1;
    }
   }
  else if(info == '0'){
    digitalWrite(LED, LOW);      
    if(state == 0){
      Serial.println("LED OFF");//display that the LED is off
      state = 1;
     }
  }
}

void sensor() { 
  
  int duration, distance;    
  
  digitalWrite(triggerPin, HIGH); //triggering the wave(like blinking an LED)
  delay(10);
  digitalWrite(triggerPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); //a special function for listening and waiting for the wave
  distance = (duration/2) / 29.1; //transforming the number to cm
  
  Serial.print(distance);   
  Serial.print("cm");       
  Serial.println(" ");      
  
  
  
  if(distance <= 15){ 
    digitalWrite(LED, LOW);
    Serial.println("TOO CLOSE!!!");
    delay(2000); 
  }
}
