//Sleepy Shaun Children's Night Light by Miguel Gutierrez and Nadia Kaheil
//The night light responds to brightness levels using a photoresistor
//It is also possible to cycle through a variety of colors using the button hidden on Shaun's head

//Three tutorials really helped guide us towards achieving this nightlight:
//1. SparkFun's Inventor's Kit Experiment Guide on Photoresistors: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v40/circuit-1c-photoresistor 
//2. An instructable tutorial on how to use a photoresistor: https://www.instructables.com/id/How-to-use-a-photoresistor-or-photocell-Arduino-Tu/
//3. Innovation Lab's tutorial on Push Button RGB LED Color Change: https://create.arduino.cc/projecthub/gol73/innovation-lab-5-push-button-rgb-led-color-change-6f4453

#define COMMON_ANODE
int counter = 0;
int photoresistor;          //variable for storing the photoresistor value
int threshold = 700;        //if the photoresistor reading is lower than this value the light will turn on
//LEDs are connected to these pins

int buttonPin = 3;          //where button is connected to arduino

void setup() {
  pinMode(buttonPin, INPUT);      //sets button to be an input source
  //set the LED pins to output
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}
void loop() {
  // button to control colours
  int buttonState;
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW) {
    counter++;
  }
  
  // using the modulo allows the button to cycle through 
  else if (counter % 6 == 0) { 
    setColor(250,0,0); //RED
  }
  
  else if (counter % 6 == 1) {
    setColor(250,250,0); // YELLOW  
  }
  
  else if (counter % 6 == 2) {
    setColor(0,250,0); // GREEN
  }
  else if (counter % 6 == 3) {
    setColor(0,250,250); // CYAN
    }
  else if (counter % 6 == 4) {
    setColor(0,0,250); // BLUE
    }
  else if (counter % 6 == 5) {
    setColor(250,0,250); // MAGENTA
    }
  else {
    counter = 0;
  }
  
  photoresistor = analogRead(A0);         //reads the value of the photoresistor
  Serial.print(photoresistor);            //prints photocell reading

  
    // when its dark, the resistance value goes UP so as it gets higher, then color must go higher
  if (photoresistor > 600 && photoresistor < 700) {
        setColor(30,30,30);
  } else if (photoresistor > 700 && photoresistor <800) {
        setColor(80,80,80);
    } else if (photoresistor > 800 && photoresistor < 850) {
        setColor(150,150,150);
    }
      else if (photoresistor > 850 && photoresistor < 900) {
        setColor(250,250,250);  
      }
  delay(100);  //short delay so that the printout is easier to read
}

// function to set colors
void setColor(int red, int green, int blue) {
    #ifdef COMMON_ANODE
      red = 255 - red;
      green = 255 - green;
      blue = 255 - blue;
    #endif
      analogWrite(9, red);
      analogWrite(10, green);
      analogWrite(11, blue);
  }
