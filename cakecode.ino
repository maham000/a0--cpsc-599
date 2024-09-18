// code that allows you to "blow out" an led and play birthday music once the "candle" led is blown out
// maham fatima
// sept 18 2024
// A0 - CPSC 599 Physical and Tangible HCI
// i adapted the following information and code in this file:
// i adapted the birthday music playing code from : https://forum.arduino.cc/t/playing-happy-birthday-to-you-on-arduino/303601
// and learned how to use sound sensor and the code from: https://kandrproject.blogspot.com/2018/01/arduino-with-sound-sensor-and-led-code.html
// ----------------------------

//https://forum.arduino.cc/t/playing-happy-birthday-to-you-on-arduino/303601 -> bday tune code below from here
int pin[]= {523,523,587,523,698,659,0,   // Notes' array
           523,523,587,523,783,698,0,
           523,523,1046,880,689,658.25,587,
           932,932,880,698,783,698,0};
int time[]={250,250,500,500,500,500,500, // time array for each note
           250,250,500,500,500,500,500,
           250,250,500,500,500,500,1000, 
           250,250,500,500,500,500,500};
// I modified timings for more upbeat version from this code making it double the speed to speed it up

//set pins for mic, led and speaker
const int micpin=7;
const int ledpin=13; 
const int soundpin=A2;
    
// to check if user has blown into the mic (sound sensor) 
// sound sensor code below: https://kandrproject.blogspot.com/2018/01/arduino-with-sound-sensor-and-led-code.html
const int threshold=200; // threshold for the microphone


void setup() {
Serial.begin(9600); // set up serial comunication 
pinMode(ledpin,OUTPUT); // set led to be output
pinMode(soundpin,INPUT); //set microphone to be input
pinMode(micpin, OUTPUT); // set speaker to be output 
}

void loop() {
    // in this loop we check to see if someone has exceeded the threshold and if so the light turns of and music turns on 
    // else the light stays on
    int soundsensor=analogRead(soundpin); // reads analog data from sound sensor

    if (soundsensor>=threshold) {         // check if sound louder then the threshold 
    digitalWrite(ledpin,LOW);           // turns led on when sound registered at higher then threshold
    // loop through and play bday song -> bday music code here https://forum.arduino.cc/t/playing-happy-birthday-to-you-on-arduino/303601
    // modified it to play once instead of continuous loop
    for (int i= 0; i<28; i++){       // loop for the duration of one round of "happy birthday" song
      tone(7, pin[i], time[i]);       // play which note and how long 
      delay (time[i]);                 // add a delay between notes       
    }
    delay(1000);                        // delay so that there is time to see it "blown out" before it starts again
  } 
    else{
      digitalWrite(ledpin,HIGH);        // if not above threshold keep the led on
      
    }
   
  //delay(500); // just for testing
}


