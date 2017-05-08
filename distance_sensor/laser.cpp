

#include "distance_sensor.h" //include the declaration for this class

//<<constructor>> setup the LED, make pin 13 an OUTPUT


 laser::laser( )
        { 
        
        }

 laser::~laser( )
        { 
        
        }

int laser::set_pin(int pin)
		{
			laser_pin=pin;
		}
int laser::get_distance()
        {   
           //int val = analogRead(laser_pin);
           //Serial.println( (int)(val/1.024) );
			float return_set=5;
			float v=0;
			for(int i=0;i<return_set;i++)
					{
							v+=( (analogRead(laser_pin)) /1.024 );
							Serial.println(v);
					}
		
			v=(v/return_set);
			return v+fix;
        }
int laser::chaeck_distance(int distance){}

