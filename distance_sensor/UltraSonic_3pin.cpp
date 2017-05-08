

#include "distance_sensor.h" //include the declaration for this class

//<<constructor>> setup the LED, make pin 13 an OUTPUT


 UltraSonic_3_pin::UltraSonic_3_pin( int pin_set)
        { 
            max_distance=200;
            pingPin=pin_set;
        }

//<<destructor>>
 UltraSonic_3_pin::~UltraSonic_3_pin()
        {
             
        }


int UltraSonic_3_pin::get_distance()
        {   
            pinMode(pingPin, OUTPUT);
            digitalWrite(pingPin, LOW);
            delayMicroseconds(2);
            digitalWrite(pingPin, HIGH);
            delayMicroseconds(5);
            digitalWrite(pingPin, LOW);
          
            // The same pin is used to read the signal from the PING))): a HIGH
            // pulse whose duration is the time (in microseconds) from the sending
            // of the ping to the reception of its echo off of an object.
            pinMode(pingPin, INPUT);
            duration = pulseIn(pingPin, HIGH  );
            cm = microsecondsToCentimeters(duration);
           
            // convert the time into a distance
            return cm;
          
        }

long UltraSonic_3_pin::microsecondsToCentimeters(long microseconds) 
    {
            // The speed of sound is 340 m/s or 29 microseconds per centimeter.
            // The ping travels out and back, so to find the distance of the
            // object we take half of the distance travelled.
            return microseconds / 29 / 2;
    }

int UltraSonic_3_pin::chaeck_distance(int distance)
        {
            now_distance=distance;
            if(now_distance >max_distance  )    now_distance=max_distance;
            before_distance=now_distance;
            return now_distance;
        }

