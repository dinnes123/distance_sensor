

#include "distance_sensor.h" //include the declaration for this class




 laser_VL53L0X::laser_VL53L0X(int Address, int Pin)
        { 
            
           /* delay(500);
            Wire.begin();
            pinMode(Pin, OUTPUT);
            digitalWrite(Pin, LOW);
            pinMode(Pin, INPUT);
            delay(150);
            sensor.init(true);
            delay(100);
            sensor.setAddress((uint16_t)Address);
            sensor.setSignalRateLimit(0.1);
            sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange,18);
            sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange,10);
            sensor.setTimeout(500);
            sensor.startContinuous(100);*/
            
        }

 laser_VL53L0X::~laser_VL53L0X()
        { 
        
        }
laser_VL53L0X::setup(int Address, int Pin)
        { 
            delay(500);
            Wire.begin();
            pinMode(Pin, OUTPUT);
            digitalWrite(Pin, LOW);
            pinMode(Pin, INPUT);
            delay(150);
            sensor.init(true);
            delay(100);
            sensor.setAddress((uint16_t)Address);
            sensor.setSignalRateLimit(0.1);
            sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange,18);
            sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange,10);
            sensor.setTimeout(500);
            sensor.startContinuous(100);
        }
int laser_VL53L0X::get_distance()
        {   
            
           return sensor.readRangeSingleMillimeters();
        }
int laser_VL53L0X::get_distance(bool Is_set_0)
        {   
            
              if(Is_set_0==1) 
                 {
                     if(Is_set_base==0)  
                      {
                         base_distance=sensor.readRangeSingleMillimeters();
                         
                         Is_set_base=true;
                      }
                  }
               return sensor.readRangeSingleMillimeters()-base_distance;
          
        }
int laser_VL53L0X::get_distance(      bool Is_set_0, \
                                      int lower_distance,\
                                      int upper_distance  )
        {   
              
              if(sensor.readRangeSingleMillimeters()>lower_distance && sensor.readRangeSingleMillimeters()<upper_distance )
                  {
                      
                      if(Is_set_0==1) 
                         {
                             if(Is_set_base==0)  
                                  {
                                     Serial.println();Serial.println("set zero secuues!");
                                     base_distance=sensor.readRangeSingleMillimeters();
                                     Is_set_base=true;
                                     
                                  }
                          }
                   }
                   
               return sensor.readRangeSingleMillimeters()-base_distance;
          
        } 

int laser_VL53L0X::chaeck_distance(int distance){}
int laser_VL53L0X::reset_base()
       {
          Serial.println("reset!");
          base_distance=0;
          Is_set_base=0;
          Serial.print(" sensor.readRangeSingleMillimeters()= "); Serial.println( sensor.readRangeSingleMillimeters() );
       }
