
/*
	distance_sensor version 1.0  2017/5/7
	//-----------------------------------------------
	distance_sensor version 1.0  2017/5/7  7:30
                    adding function
                    1. int get_distance( bool Is_set_0, \
                                      int lower_distance,\
                                      int upper_distance);   
                                             if bool Is_set_0==1 than the distance to which device are receiving will be set to zero
                                             int lower_distance :the range of most lower distance
                                             int lower_distance :the range of most upper distance
*/

#ifndef SENSOE_H
#define SENSOR_H

#include "Wire.h"
#include "Arduino.h"
#include <VL53L0X.h>
#include <Wire.h>
class sensor 
          { 
            public:   
                 sensor();
                 ~sensor();
                 virtual int get_distance()=0;
                 virtual int chaeck_distance(int distance)=0;
                 int max_distance;  //150cm
                 int now_distance;
                 int before_distance;
                 //sensor(int trigPin_out, int echoPin );     
           };
class UltraSonic :public sensor
          {
             public:
                 byte trigPin;
                 int echoPin;
                
                 
                int maximumRange = 200; // Maximum range needed
                int minimumRange = 0; // Minimum range needed
                long duration, distance; // Duration used to calculate distance
                 UltraSonic(int trigPin_out, int echoPin_out );
                 
                 ~UltraSonic();
                 int get_distance();
                 int chaeck_distance(int distance);
          };
class UltraSonic_3_pin :public sensor
          {
            public:
              UltraSonic_3_pin(int pin_set);
              ~UltraSonic_3_pin();
              int pingPin =23;
          
              long duration, cm;
              int get_distance();
              int chaeck_distance(int distance);
              long microsecondsToCentimeters(long microseconds);
          };
class laser :public sensor
          {
            public:
              laser();
              laser( int set_pin );
              ~laser();
              int fix=-3;
              int laser_pin=A0;
              int get_distance();
              int chaeck_distance(int distance);
              int set_pin(int pin);
              
          };
class laser_VL53L0X : public sensor
          {
               private:
                    VL53L0X sensor;
                    bool Is_set_base=false;
                    int base_distance;
                    int upper_distance;
                    int lower_distance;
                    
                    int chaeck_distance(int distance);
                public:
					laser_VL53L0X(int Address, int Pin);
                    ~laser_VL53L0X();
                    int get_distance();
                    int get_distance(bool Is_set_0);
                    int get_distance( bool Is_set_0, \
                                      int lower_distance,\
                                      int upper_distance);
          };
           
#endif
