//it is a program for 4 pin to get the distance from which we see

#include "distance_sensor.h" //include the declaration for this class

//<<constructor>> setup the LED, make pin 13 an OUTPUT


 UltraSonic::UltraSonic(int trigPin_out, int echoPin_out )
        { 
              trigPin=  trigPin_out;
              echoPin=  echoPin_out;
              pinMode(trigPin ,OUTPUT);
              pinMode(echoPin ,INPUT);
        }

//<<destructor>>
 UltraSonic::~UltraSonic()
        {
              max_distance=150;
        }


int UltraSonic::get_distance()
        {   
          /*  digitalWrite(trigPin , HIGH);
            delayMicroseconds(5);
            digitalWrite(trigPin , LOW);
            now_distance=(pulseIn(echoPin , HIGH))/58;
            
            if(now_distance>max_distance  ) return before_distance;

            before_distance=now_distance;
           
            return now_distance;*/
          
                 digitalWrite(trigPin, LOW); 
                 delayMicroseconds(2); 
                
                 digitalWrite(trigPin, HIGH);
                 delayMicroseconds(10); 
                 
                 digitalWrite(trigPin, LOW);
                 duration = pulseIn(echoPin, HIGH);
                 
                 //Calculate the distance (in cm) based on the speed of sound.
                 distance = duration/58.2;
                 
                 if (distance >= maximumRange || distance <= minimumRange )
                    {
                         /* Send a negative number to computer and Turn LED ON 
                         to indicate "out of range" */
                         return get_distance();
                
                     }
                 else 
                     {
                         /* Send the distance to the computer using Serial protocol, and
                         turn LED OFF to indicate successful reading. */
                         Serial.println(distance);
                         return distance;
                     }
                 return get_distance();
                 //Delay 50ms before next reading.
               
              
        }

int UltraSonic::chaeck_distance(int distance)
        {
        }

