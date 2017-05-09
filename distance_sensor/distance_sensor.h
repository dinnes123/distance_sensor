
/*
	該檔案是距離相關的感測器的標頭檔，引入後，就可以使用像是3pin超音波、4pin超音波、雷射測距儀...等基本的感測器

        編輯日期 2017/5/7 張恩典 
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
                    
                    int chaeck_distance(int distance);
                public:
					laser_VL53L0X(int Address, int Pin);
                    ~laser_VL53L0X();
                    int get_distance();
                    int get_distance(bool Is_set_0);
          };
           
#endif
