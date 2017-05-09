#include "distance_sensor.h"
int i=0;
laser_VL53L0X laser_VL53L0X_1(255,5);
void setup() 
    {
        Serial.begin(9600);
        laser_VL53L0X_1.setup(255,5);
    }
void loop() 
    {
         
             // (int Address , int pin )
         Serial.print(  "distance=" ) ; Serial.print( laser_VL53L0X_1.get_distance (1,500,600) ); 
         Serial.print(  "  Is_set_base=" ) ; Serial.println( laser_VL53L0X_1.Is_set_base  );
         
         i++;
         if(i>100)
            {
              i=0;
              laser_VL53L0X_1.reset_base();
            } 
    }
