# distance_sensor
距離感測器專用函式庫

/*


	distance_sensor version 1.0  2017/5/7
	//-----------------------------------------------
	distance_sensor version 1.1  2017/5/7  7:30
                    adding function
                    1. int get_distance( bool Is_set_0, \
                                      int lower_distance,\
                                      int upper_distance);   
                                             if bool Is_set_0==1 than the distance for which device are currently receiving will be set to zero
                                             int lower_distance :the range of the most lower distance
                                             int lower_distance :the range of the most upper distance
                                             
    //-----------------------------------------------
     distance_sensor version 1.2  2017/5/9
     增加新功能：
                  1. int reset_base(); 重制歸零的動作，可以透過檢查變數確認是否歸零 
                  2. Is_set_base  若為TRUE則代表處於歸零狀態，若為FALSE則為尚未歸零的狀態 
     //----------------------------------------------
     distance_sensor version 1.3   2017/5/9
                  1.改變初始化方式，需先呼叫setup函數才可以呼叫get_distance函數 
*/
