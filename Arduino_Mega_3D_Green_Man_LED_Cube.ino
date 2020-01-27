/*
  4x4x4 LED Cube
  Connection Setup: 
  Columns
  [(x,y)-Pin]
  (1,1)-13
  (1,2)-12
  (1,3)-11
  (1,4)-10
  (2,1)-9
  (2,2)-8
  (2,3)-7
  (2,4)-6
  (3,1)-5
  (3-2)-4
  (3-3)-3
  (3,4)-2
  (4,1)-1
  (4,2)-0
  (4,3)-A5
  (4,4)-A4
  Layers
  [layer-Pin]
  a-A0
  b-A1
  c-A2
  d-A3
*/
#include <Wire.h>
const int SLAVE_ADDRESS = 1;

//initializing and declaring led rows
  int column[100]; //Cathode columns
//initializing and declaring led layers
  int layer[10]={A0,A1,A2,A3,A4,A5,A6,A7,A8,A9}; //Anode layers

  int time = 250;
 
void setup()
{
  Wire.begin();         // join I2C bus as a Master 

  
  for(int i = 0; i<46; i++)
  {
    column[i]=i+8;
  }
  for(int i = 0; i<4; i++)
  {
  column[i+54]=i;
  }
  column[12]=A10;
  column[13]=A11;
  column[46]=A12;
  column[47]=A13;
  column[53]=A14;
  column[63]=4;
  column[64]=5;
  column[65]=6;
  column[74]=7;
  
  //setting rows to ouput
  for(int i = 0; i<48; i++)
  {
    pinMode(column[i], OUTPUT);
  }
  
  for(int i = 53; i<58; i++)
  {
    pinMode(column[i], OUTPUT);
  }
  
  for(int i = 63; i<66; i++)
  {
    pinMode(column[i], OUTPUT);
  }
  
 //pinMode(column[54], OUTPUT);
  pinMode(column[74], OUTPUT);
  
   
  //setting layers to output
  for(int i = 0; i<10; i++)
  {
    pinMode(layer[i], OUTPUT);
  }
  //seeding random for random pattern
  //randomSeed(analogRead(10));

  turnEverythingOff();

}
//xxxxxxxxxxxxxxxxxxxxFUNCTION LOOPxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void loop()
{
//digitalWrite(layer[0],1);
//digitalWrite(column[39],0);
for(int i=0;i<20;i++)
greenMan();

//slavegreenMan(1);

/*
turnEverythingOff();//turn all off
slaveTurnEverythingOff(2);

  flickerOn();
  slaveFlickerOn(4);
  
  turnEverythingOn();//turn all on
  slaveTurnEverythingOn(3);
  delay(time);
 */
//slavegreenMan(1);
  turnEverythingOff();//turn all off
  flickerOn();
  turnEverythingOn();//turn all on
  delay(time);
  
  turnOnAndOffAllByLayerUpAndDownNotTimed();
  layerstompUpAndDown();
  turnOnAndOffAllByColumnSideways();
  delay(time);
  
  aroundEdgeDown();
  turnEverythingOff();
  randomflicker();
  randomRain();
  diagonalRectangle();
  goThroughAllLedsOneAtATime();
  propeller();
  spiralInAndOut();
  flickerOff();
  turnEverythingOff();
  delay(2000);
  
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx I2C
void slavegreenMan(byte value)
{
  // send data to slave
  Wire.beginTransmission(SLAVE_ADDRESS);
  Wire.write(value);
  Wire.endTransmission();
}

void slaveTurnEverythingOff(byte value){
   // send data to slave
  Wire.beginTransmission(SLAVE_ADDRESS);
  Wire.write(value);
  Wire.endTransmission();
}

void slaveTurnEverythingOn(byte value){
   // send data to slave
  Wire.beginTransmission(SLAVE_ADDRESS);
  Wire.write(value);
  Wire.endTransmission();
}

void slaveFlickerOn(byte value){
   // send data to slave
  Wire.beginTransmission(SLAVE_ADDRESS);
  Wire.write(value);
  Wire.endTransmission();
}
//xxxxxxxxxxxxxxxxxxxxFUNCTIONSxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void greenMan(){
  /*
  firstImg();//A3.A4不見
  delay(10);
  firstImg();
  delay(10);
  firstImg();
  delay(10);
  */
  secondImg();
  delay(10);
 secondImg();
  delay(10);
  secondImg();
  delay(10); 
  thirdImg();
  delay(10);
  thirdImg();
  delay(10);
  thirdImg();
  delay(10); 
  forthImg();
   delay(10);
   forthImg();
   delay(10);
   forthImg();
   delay(10);
   fifthImg();
   delay(10);
   fifthImg();
   delay(10);
   fifthImg();
   delay(10);
   sixthImg();
   delay(10);
   sixthImg();
   delay(10);
   sixthImg();
   delay(10);
   seventhImg();
   delay(10);
   seventhImg();
   delay(10);
   seventhImg();
   delay(10);
   
   eighthImg();//A3.A4不見
   delay(10);
   eighthImg();
   delay(10);
   eighthImg();
   delay(10);

    ninethImg();
   delay(10);
   ninethImg();
   delay(10);
   ninethImg();
   delay(10);
   tenthImg();
   delay(10);
   tenthImg();
   delay(10);
   tenthImg();
   delay(10);
   elevenImg();
    delay(10);
   elevenImg();
    delay(10);
   elevenImg();
   delay(10);
   twelveImg();
   delay(10);
    twelveImg();
   delay(10);
   twelveImg();
   delay(10);
   thirteenImg();
    delay(10);
     thirteenImg();
    delay(10);
   thirteenImg();
   delay(10);
   fourteenImg();
   delay(10);
   fourteenImg();
   delay(10);
   fourteenImg();
   delay(10);
   fifteenImg();
   delay(10);
   fifteenImg();
   delay(10);
   fifteenImg();
   delay(10);
   sixteenImg();
   delay(10);
   sixteenImg();
   delay(10);
    sixteenImg();
   delay(10);
   seventeenImg();
   delay(10);
   seventeenImg();
   delay(10);
    seventeenImg();
   delay(10);
   eighteenImg();
   delay(10);
   eighteenImg();
   delay(10);
   eighteenImg();
   delay(10);
   nineteenImg();
   delay(10);
   nineteenImg();
   delay(10);
   nineteenImg();
   delay(10);
   twentyImg();
   delay(10);
   twentyImg();
   delay(10);
   twentyImg();
   delay(10);
}
////////////////////////////////////////////////////////////////////////////////////First Image
void firstImg(){
/*
A0,34,
A0,44,
A0,45,
A0,46,
A0,54,
A0,55,
*/  
digitalWrite(layer[0],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[34],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();

/*
A1,44,
A1,b0,
A1,b1,
A1,b2,
*/
digitalWrite(layer[1],1);
digitalWrite(column[44],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
digitalWrite(column[56],0);
delay(1);
turnEverythingOff();

//A3,44,
digitalWrite(layer[3],1);
digitalWrite(column[44],0);
delay(1);
turnEverythingOff();

/*
A4,35,
A4,44,
A4,45,
A4,47,
*/
digitalWrite(layer[4],1);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[47],0);
delay(1);
turnEverythingOff();

/*
A5,34  534,
A5,35  535,
A5,43  543,
A5,44  544,
A5,46  546,
A5,b0  554,
A5,b1  555,
A5,b3  557,
*/
digitalWrite(layer[5],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
digitalWrite(column[57],0);
delay(1);
turnEverythingOff();

/*
A6,34  634,
A6,35  635,
A6,43  643,
A6,44  644,
A6,45  645,
A6,46  646,
A6,b0  654,
A6,b1  655,
*/
digitalWrite(layer[6],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();

/*
A7,34  734,
A7,35  735,
A7,43  743,
A7,44  744,
A7,45  745,
A7,46  746,
A7,b0  754,
A7,b1  755,
*/
digitalWrite(layer[7],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();

/*
A8,44  844,
A8,45  845,
A8,46  846,
*/
digitalWrite(layer[8],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
delay(1);
turnEverythingOff();

//A9,44  944
digitalWrite(layer[9],1);
digitalWrite(column[44],0);
delay(1);
turnEverythingOff();
}


////////////////////////////////////////////////////////////////////////////////////Second Image
void secondImg(){
 /*////////////////////////////////////////////////會影響A2 
A0,15  15,
A0,25  25,
A0,b10  64,
A0,b11  65,
*/
digitalWrite(layer[0],1);
digitalWrite(column[15],0);
digitalWrite(column[25],0);
digitalWrite(column[64],0);
digitalWrite(column[65],0);
delay(1);
turnEverythingOff();
////////////////////////////////////////////////

/*
A1,15  115,
A1,25  125,
A1,35  135,
A1,b0  154,
A1,b10  164,
*/
digitalWrite(layer[1],1);
digitalWrite(column[15],0);
digitalWrite(column[25],0);
digitalWrite(column[35],0);
digitalWrite(column[54],0);
digitalWrite(column[64],0);
delay(1);
turnEverythingOff();

/*////////////////////////怪怪的
A2,35  235,
A2,36  236,
A2,b0  254,
A2,b10  264,
*/
digitalWrite(layer[2],1);
digitalWrite(column[35],0);
digitalWrite(column[36],0);
digitalWrite(column[54],0);
digitalWrite(column[64],0);
delay(1);
turnEverythingOff();


/*
A3,35  335,
A3,44  344,
A3,b0  354,
*/
digitalWrite(layer[3],1);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[54],0);
delay(1);
turnEverythingOff();

/*
A4,44  444,
A4,45  445,
A4,b0  454,
A4,b3  457,
*/
digitalWrite(layer[4],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[54],0);
digitalWrite(column[57],0);
delay(1);
turnEverythingOff();

/*
A5,34  534,
A5,35  535,
A5,43  543,
A5,44  544,
A5,46  546,
A5,b0  554,
A5,b1  555,
A5,b3  557,
*/
digitalWrite(layer[5],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
digitalWrite(column[57],0);
delay(1);
turnEverythingOff();

/*
A6,34  634,
A6,35  635,
A6,43  643,
A6,44  644,
A6,45  645,
A6,46  646,
A6,b0  654,
A6,b1  655,
A6,b2  656,
*/
digitalWrite(layer[6],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
digitalWrite(column[56],0);
delay(1);
turnEverythingOff();

/*
A7,34  734,
A7,35  735,
A7,44  744,
A7,45  745,
A7,46  746,
A7,b0  754,
A7,b1  755,
*/
digitalWrite(layer[7],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();

/*
A8,43  843,
A8,44  844,
A8,45  845,
*/
digitalWrite(layer[8],1);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();

/*
A9,44  944
*/
digitalWrite(layer[9],1);
digitalWrite(column[44],0);
delay(1);
turnEverythingOff();
}

////////////////////////////////////////////////////////////////////////////////////Third Image 

void thirdImg(){
  /*////////////////////////怪怪的
A0,15  15,
A0,24  24,
A0,35  35,
A0,B20  74,
*/
digitalWrite(layer[0],1);
digitalWrite(column[15],0);
digitalWrite(column[24],0);
digitalWrite(column[35],0);
digitalWrite(column[74],0);
delay(1);
turnEverythingOff();


/*////////////////////////////////////////////////會影響A0
A1,35  135,
A1,b0  154,
A1,b10  164,
A1,b20  174,
*/
digitalWrite(layer[1],1);
digitalWrite(column[35],0);
digitalWrite(column[54],0);
digitalWrite(column[64],0);
digitalWrite(column[74],0);
delay(1);
turnEverythingOff();


/*
A2,25  225,
A2,35  235,
A2,b0  254,
A2,b10  264,
*/
digitalWrite(layer[2],1);
digitalWrite(column[25],0);
digitalWrite(column[35],0);
digitalWrite(column[54],0);
digitalWrite(column[64],0);
delay(1);
turnEverythingOff();


/*
A3,35  335,
A3,44  344,
A3,b0  354,
*/
digitalWrite(layer[3],1);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[54],0);
delay(1);
turnEverythingOff();


/*////////////////////////////////////////////////會影響A0
A4,34  434,
A4,35  435,
A4,44  444,
A4,45  445,
A4,b0  454,
*/
digitalWrite(layer[4],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[54],0);
delay(1);
turnEverythingOff();


/*
A5,34  534,
A5,35  535,
A5,42  542,
A5,44  544,
A5,46  546,
A5,b0  554,
A5,b1  555,
*/
digitalWrite(layer[5],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[42],0);
digitalWrite(column[44],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
A6,33  633,
A6,34  634,
A6,35  635,
A6,43  643,
A6,44  644,
A6,45  645,
A6,b0  654,
A6,b1  655,
A6,b2  656,
*/
digitalWrite(layer[6],1);
digitalWrite(column[33],0);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
digitalWrite(column[56],0);
delay(1);
turnEverythingOff();



/*
A7,34  734,
A7,35  735,
A7,44  744,
A7,45  745,
A7,46  746,
A7,b0  754,
*/
digitalWrite(layer[7],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
delay(1);
turnEverythingOff();

/*
A8,34  834,
A8,44  844,
A8,45  845,
*/
digitalWrite(layer[8],1);
digitalWrite(column[34],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();


/*
A9,44  944,
*/
digitalWrite(layer[9],1);
digitalWrite(column[44],0);
delay(1);
turnEverythingOff();

}
////////////////////////////////////////////////////////////////////////////////////Forth Image
void forthImg(){
/*
24,
34,
35,
*/
digitalWrite(layer[0],1);
digitalWrite(column[24],0);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
delay(1);
turnEverythingOff();

/*////////////////////////////////////////////////會影響A0
135,
144,
164,
174,
*/
digitalWrite(layer[1],1);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[64],0);
digitalWrite(column[74],0);
delay(1);
turnEverythingOff();

/*
235,
*/
digitalWrite(layer[2],1);
digitalWrite(column[35],0);
delay(1);
turnEverythingOff();


/*
335,
344,
*/
digitalWrite(layer[3],1);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
delay(1);
turnEverythingOff();

/*////////////////////////////////////////////////會影響A0
434,
435,
444,
445,
454,
*/
digitalWrite(layer[4],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[54],0);
delay(1);
turnEverythingOff();


/*
534
535,
542,
544,
554,
555,
*/
digitalWrite(layer[5],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[42],0);
digitalWrite(column[44],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
633,
634,
635,
643,
644,
645,
654,
655,
656,
*/
digitalWrite(layer[6],1);
digitalWrite(column[33],0);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
digitalWrite(column[56],0);
delay(1);
turnEverythingOff();

/*
734
,735,
744,
745,
746,
754,
*/
digitalWrite(layer[7],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
delay(1);
turnEverythingOff();


/*
834,
844,
845,
*/
digitalWrite(layer[8],1);
digitalWrite(column[34],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();

/*
944,
*/
digitalWrite(layer[9],1);
digitalWrite(column[44],0);
delay(1);
turnEverythingOff();
}
////////////////////////////////////////////////////////////////////////////////////Fifth Image
void fifthImg(){
/* ////////////////////////怪怪的
34,
45,
*/
digitalWrite(layer[0],1);
digitalWrite(column[34],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();


/*////////////////////////////////////////////////會影響A0
135,
145,
164,
*/
digitalWrite(layer[1],1);
digitalWrite(column[35],0);
digitalWrite(column[45],0);
digitalWrite(column[64],0);
delay(1);
turnEverythingOff();



/*
235,
244,
254,
264,
274,
*/
digitalWrite(layer[2],1);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[54],0);
digitalWrite(column[65],0);
digitalWrite(column[74],0);
delay(1);
turnEverythingOff();



/*
335,
344,
*/
digitalWrite(layer[3],1);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
delay(1);
turnEverythingOff();



/*
442,
444,
445,
457,
*/
digitalWrite(layer[4],1);
digitalWrite(column[42],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[57],0);
delay(1);
turnEverythingOff();


/*
534,
535,
543,
544,
554,
555,
557,
*/
digitalWrite(layer[5],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
digitalWrite(column[57],0);
delay(1);
turnEverythingOff();



/*
634,
635,
643,
644,
645,
646,
654,
655,
*/
digitalWrite(layer[6],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();



/*
734,
735,
744,
745
,746,
754,
755,
*/
digitalWrite(layer[7],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
834,
844,
845,
*/
digitalWrite(layer[8],1);
digitalWrite(column[34],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();



/*
944,
*/
digitalWrite(layer[9],1);
digitalWrite(column[44],0);
delay(1);
turnEverythingOff();
}
////////////////////////////////////////////////////////////////////////////////////Sixth Image
void sixthImg(){

/*
44
45,
53,
54,
55
*/
digitalWrite(layer[0],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[53],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();

/*
145
154
164
*/
digitalWrite(layer[1],1);
digitalWrite(column[45],0);
digitalWrite(column[54],0);
digitalWrite(column[64],0);
delay(1);
turnEverythingOff();


/*
234
245,
254,
*/
digitalWrite(layer[2],1);
digitalWrite(column[34],0);
digitalWrite(column[45],0);
digitalWrite(column[54],0);
delay(1);
turnEverythingOff();


/*
334,
335,
344,
345,
*/
digitalWrite(layer[3],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();

/*
444
445,
457,
*/
digitalWrite(layer[4],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[57],0);
delay(1);
turnEverythingOff();


/*
534,
535,
544,
545,
546,
554
555,
557,
*/
digitalWrite(layer[5],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
digitalWrite(column[57],0);
delay(1);
turnEverythingOff();

/*
634,
635,
643,
644,
645
,646,
654,
655,
*/
digitalWrite(layer[6],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();

/*
734,
735,
744,
745,
746,
754,
755,
*/
digitalWrite(layer[7],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
843,
844,
845,
*/
digitalWrite(layer[8],1);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();



/*
944,
945,
*/
digitalWrite(layer[9],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();
}

 ////////////////////////////////////////////////////////////////////////////////////Seventh Image
 void seventhImg(){

/*
43,
44,
54,
55,
*/
digitalWrite(layer[0],1);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
144,
145,
154,
155,
*/
digitalWrite(layer[1],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
234,
245,
*/
digitalWrite(layer[2],1);
digitalWrite(column[34],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();


/*
334,
345,
*/
digitalWrite(layer[3],1);
digitalWrite(column[34],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();

/*
434,
444,
447,
453,
*/
digitalWrite(layer[4],1);
digitalWrite(column[34],0);
digitalWrite(column[44],0);
digitalWrite(column[47],0);
digitalWrite(column[53],0);
delay(1);
turnEverythingOff();

/*
534,
535,
544,
545,
553,
554,
555,
557,
*/
digitalWrite(layer[5],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[53],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
digitalWrite(column[57],0);
delay(1);
turnEverythingOff();


/*
634,
635,
643,
644,
645
,646,
653,
654,
655,
*/
digitalWrite(layer[6],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[53],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();

/*
734,
735,
743,
744,
745,
746,
754,
755,
*/
digitalWrite(layer[7],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
844,
845,
846,
*/
digitalWrite(layer[8],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
delay(1);
turnEverythingOff();

/*
944,
945,
*/
digitalWrite(layer[9],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();
}
////////////////////////////////////////////////////////////////////////////////////Eighth Image
void eighthImg(){

/*
24,
34,
44,
54,
55,
*/
digitalWrite(layer[0],1);
digitalWrite(column[24],0);
digitalWrite(column[34],0);
digitalWrite(column[44],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
134,
144,
155,
*/
digitalWrite(layer[1],1);
digitalWrite(column[34],0);
digitalWrite(column[44],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();



/*
234
,245,
255,
*/
digitalWrite(layer[2],1);
digitalWrite(column[34],0);
digitalWrite(column[45],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();



/*
334
345,
*/
digitalWrite(layer[3],1);
digitalWrite(column[34],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();



/*
434,
444,
447,
453,
*/
digitalWrite(layer[4],1);
digitalWrite(column[34],0);
digitalWrite(column[44],0);
digitalWrite(column[47],0);
digitalWrite(column[53],0);
delay(1);
turnEverythingOff();


/*
534,
535
544,
545,
547,
553,
554,
555,
*/
digitalWrite(layer[5],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[47],0);
digitalWrite(column[53],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
634,
635,
644,
645,
646,
653,
654,
655,
*/
digitalWrite(layer[6],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[53],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
734,
735,
743,
744,
745,
746,
754
,755
*/
digitalWrite(layer[7],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
,844,
845,
846,
*/
digitalWrite(layer[8],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
delay(1);
turnEverythingOff();


/*
944,
945,
*/
digitalWrite(layer[9],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();
}
////////////////////////////////////////////////////////////////////////////////////Nineth Image
void ninethImg(){

/*
24,
34,
54,
55,
65,
*/
digitalWrite(layer[0],1);
digitalWrite(column[24],0);
digitalWrite(column[34],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
digitalWrite(column[65],0);
delay(1);
turnEverythingOff();


/*
124,
155,
165,
*/
digitalWrite(layer[1],1);
digitalWrite(column[24],0);
digitalWrite(column[55],0);
digitalWrite(column[65],0);
delay(1);
turnEverythingOff();


/*
234,
255,
*/
digitalWrite(layer[2],1);
digitalWrite(column[34],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
334
345
*/
digitalWrite(layer[3],1);
digitalWrite(column[34],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();


/*
,434,
444,
445,
447,
*/
digitalWrite(layer[4],1);
digitalWrite(column[34],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[47],0);
delay(1);
turnEverythingOff();


/*
534,
535,
544,
547,
553,
554,
555,
*/
digitalWrite(layer[5],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[47],0);
digitalWrite(column[53],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
634,
635,
644,
645,
646,
647,
653,
654,
655,
*/
digitalWrite(layer[6],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[47],0);
digitalWrite(column[53],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
734,
735,
744,
745,
746
,754,
755,
*/
digitalWrite(layer[7],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
844,
845,
846,
*/
digitalWrite(layer[8],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
delay(1);
turnEverythingOff();


/*
944,
945,
*/
digitalWrite(layer[9],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();
}
////////////////////////////////////////////////////////////////////////////////////Tenth Image
void tenthImg(){
/*
14,
24,
54,
64,
65,
*/
digitalWrite(layer[0],1);
digitalWrite(column[14],0);
digitalWrite(column[24],0);
digitalWrite(column[54],0);
digitalWrite(column[64],0);
digitalWrite(column[65],0);
delay(1);
turnEverythingOff();


/*
114,
124
165,
*/
digitalWrite(layer[1],1);
digitalWrite(column[14],0);
digitalWrite(column[24],0);
digitalWrite(column[65],0);
delay(1);
turnEverythingOff();


/*
224,
234,
255,
265,
*/
digitalWrite(layer[2],1);
digitalWrite(column[24],0);
digitalWrite(column[34],0);
digitalWrite(column[55],0);
digitalWrite(column[65],0);
delay(1);
turnEverythingOff();


/*
334,
345,
*/
digitalWrite(layer[3],1);
digitalWrite(column[34],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();


/*
434,
437
,444
,445,
447,
463,
*/
digitalWrite(layer[4],1);
digitalWrite(column[34],0);
digitalWrite(column[37],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[47],0);
digitalWrite(column[63],0);
delay(1);
turnEverythingOff();


/*
534,
535,
546
,547,
553,
554
,555,
*/
digitalWrite(layer[5],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[46],0);
digitalWrite(column[47],0);
digitalWrite(column[53],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
634,
635,
644
,645
,646,
647,
653,
654,
655,
*/
digitalWrite(layer[6],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[47],0);
digitalWrite(column[53],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
734,
735,
744,
745,
746,
754,
755,
*/
digitalWrite(layer[7],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
844,
845,
846,
*/
digitalWrite(layer[8],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
delay(1);
turnEverythingOff();


/*
944,
*/
digitalWrite(layer[9],1);
digitalWrite(column[44],0);
delay(1);
turnEverythingOff();
}
////////////////////////////////////////////////////////////////////////////////////Eleventh Image
void elevenImg(){


/*
14,
25,
34,
35,
75,
*/
digitalWrite(layer[0],1);
digitalWrite(column[14],0);
digitalWrite(column[25],0);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[75],0);
delay(1);
turnEverythingOff();

/*
165,
*/
digitalWrite(column[65],0);
delay(1);
turnEverythingOff();

/*
224,
234,
255,
265,
*/
digitalWrite(layer[2],1);
digitalWrite(column[24],0);
digitalWrite(column[34],0);
digitalWrite(column[55],0);
digitalWrite(column[65],0);
delay(1);
turnEverythingOff();


/*
344,
345,
*/
digitalWrite(layer[3],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();


/*
437,
444,
445,
447,
455,
463,
*/
digitalWrite(layer[4],1);
digitalWrite(column[37],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[47],0);
digitalWrite(column[55],0);
digitalWrite(column[63],0);
delay(1);
turnEverythingOff();


/*
534,
535,
546,
547,
553,
554,
555,
*/
digitalWrite(layer[5],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[46],0);
digitalWrite(column[47],0);
digitalWrite(column[53],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
634,
635,
643,
644,
645,
646,
647,
653,
654,
655,
*/
digitalWrite(layer[6],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[47],0);
digitalWrite(column[53],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
734,
735,
744,
745,
746,
754,
755,
*/
digitalWrite(layer[7],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
844,
845,
*/
digitalWrite(layer[8],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();


/*
944,
*/
digitalWrite(layer[9],1);
digitalWrite(column[44],0);
delay(1);
turnEverythingOff();
}
////////////////////////////////////////////////////////////////////////////////////Twelveth Image
void twelveImg(){

/*
25,
34,
35,
*/
digitalWrite(layer[0],1);
digitalWrite(column[25],0);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
delay(1);
turnEverythingOff();


/*
135,
165,
166,
175,
176,
*/
digitalWrite(layer[1],1);
digitalWrite(column[35],0);
digitalWrite(column[65],0);
//digitalWrite(column[66],0);
//digitalWrite(column[75],0);
//digitalWrite(column[76],0);
delay(1);
turnEverythingOff();


/*
224,
234,
246,
256,
*/
digitalWrite(layer[2],1);
digitalWrite(column[24],0);
digitalWrite(column[34],0);
digitalWrite(column[46],0);
digitalWrite(column[56],0);
delay(1);
turnEverythingOff();


/*
345,
346,
*/
digitalWrite(layer[3],1);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
delay(1);
turnEverythingOff();


/*
434,
435,
444,
445,
446,
447,
455,
463,
*/
digitalWrite(layer[4],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[47],0);
digitalWrite(column[55],0);
digitalWrite(column[63],0);
delay(1);
turnEverythingOff();


/*
534,
535,
546,
547,
553,
554,
555,
556,
*/
digitalWrite(layer[5],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[46],0);
digitalWrite(column[47],0);
digitalWrite(column[53],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
digitalWrite(column[56],0);
delay(1);
turnEverythingOff();


/*
634,
635,
644,
645,
646,
647,
654,
655,
*/
digitalWrite(layer[6],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[47],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
734,
735,
744,
745,
746,
747,
755,
*/
digitalWrite(layer[7],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[47],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
844,
845,
*/
digitalWrite(layer[8],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();
}
////////////////////////////////////////////////////////////////////////////////////Thirteenth Image
void thirteenImg(){

/*
25,
34,
44,
45,
*/
digitalWrite(layer[0],1);
digitalWrite(column[25],0);
digitalWrite(column[34],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();


/*
135,
146,
155,
156,
165,
*/
digitalWrite(layer[1],1);
digitalWrite(column[35],0);
digitalWrite(column[46],0);
digitalWrite(column[55],0);
digitalWrite(column[56],0);
digitalWrite(column[65],0);
delay(1);
turnEverythingOff();


/*
234,
235,
246,
*/
digitalWrite(layer[2],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[46],0);
delay(1);
turnEverythingOff();


/*
344,
345,
346,
*/
digitalWrite(layer[3],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
delay(1);
turnEverythingOff();


/*
434,
444,
445,
447,
453,
455,
*/
digitalWrite(layer[4],1);
digitalWrite(column[34],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[47],0);
digitalWrite(column[53],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
534,
535,
546,
547,
553,
554,
555,
556,
*/
digitalWrite(layer[5],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[46],0);
digitalWrite(column[47],0);
digitalWrite(column[53],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
digitalWrite(column[56],0);
delay(1);
turnEverythingOff();


/*
634,
635,
643,
644,
645,
646,
647,
654,
655,
*/
digitalWrite(layer[6],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[47],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
734,
735,
744,
745,
746,
754,
755,
*/
digitalWrite(layer[7],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
844,
845,
*/
digitalWrite(layer[8],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();


/*
944,
*/
digitalWrite(layer[9],1);
digitalWrite(column[44],0);
delay(1);
turnEverythingOff();
}
////////////////////////////////////////////////////////////////////////////////////Fourteenth Image
void fourteenImg(){

/*
44,
45,
55,
*/
digitalWrite(layer[0],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
144,
155,
165,
*/
digitalWrite(layer[1],1);
digitalWrite(column[44],0);
digitalWrite(column[55],0);
digitalWrite(column[65],0);
delay(1);
turnEverythingOff();


/*
234,
235,
244,
245,
255,
265,
*/
digitalWrite(layer[2],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[55],0);
digitalWrite(column[65],0);
delay(1);
turnEverythingOff();


/*
335,
344,
345,
*/
digitalWrite(layer[3],1);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();


/*
444,
445,
447,
453,
454,
*/
digitalWrite(layer[4],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[47],0);
digitalWrite(column[53],0);
digitalWrite(column[54],0);
delay(1);
turnEverythingOff();


/*
534,
535,
543,
546,
547,
553,
554,
555,
*/
digitalWrite(layer[5],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[46],0);
digitalWrite(column[47],0);
digitalWrite(column[53],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
634,
635,
643,
644,
645,
646,
654,
655,
*/
digitalWrite(layer[6],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
734,
735,
744,
745,
746,
754,
755,
*/
digitalWrite(layer[7],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
834,
844,
845,
846,
*/
digitalWrite(layer[8],1);
digitalWrite(column[34],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
delay(1);
turnEverythingOff();


/*
944,
*/
digitalWrite(layer[9],1);
digitalWrite(column[44],0);
delay(1);
turnEverythingOff();
}
////////////////////////////////////////////////////////////////////////////////////Fifteenth Image
void fifteenImg(){

/*
44,
45,
46,
54,
55,
*/
digitalWrite(layer[0],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
144,
145,
155,
*/
digitalWrite(layer[1],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
235,
244,
245,
*/
digitalWrite(layer[2],1);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();


/*
335,
344,
*/
digitalWrite(layer[3],1);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
delay(1);
turnEverythingOff();


/*
444,
445,
447,
*/
digitalWrite(layer[4],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[47],0);
delay(1);
turnEverythingOff();


/*
534,
535,
543,
546,
554,
555,
557,
*/
digitalWrite(layer[5],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
digitalWrite(column[57],0);
delay(1);
turnEverythingOff();


/*
634,
635,
643,
644,
645,
654,
655,
*/
digitalWrite(layer[6],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
734,
735,
744,
745,
746,
754,
755,
*/
digitalWrite(layer[7],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
834,
844,
845,
846,
*/
digitalWrite(layer[8],1);
digitalWrite(column[34],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
delay(1);
turnEverythingOff();


/*
944,
*/
digitalWrite(layer[9],1);
digitalWrite(column[44],0);
delay(1);
turnEverythingOff();
}
////////////////////////////////////////////////////////////////////////////////////Sixteenth Image
void sixteenImg(){

/*
15,
25,
35,
64,
65,
74,
*/
digitalWrite(layer[0],1);
digitalWrite(column[15],0);
digitalWrite(column[25],0);
digitalWrite(column[35],0);
digitalWrite(column[64],0);
digitalWrite(column[65],0);
digitalWrite(column[74],0);
delay(1);
turnEverythingOff();


/*
115,
125,
135,
154,
164,
*/
digitalWrite(layer[1],1);
digitalWrite(column[15],0);
digitalWrite(column[25],0);
digitalWrite(column[35],0);
digitalWrite(column[54],0);
digitalWrite(column[64],0);
delay(1);
turnEverythingOff();


/*
235,
254,
264,
*/
digitalWrite(layer[2],1);
digitalWrite(column[35],0);
digitalWrite(column[54],0);
digitalWrite(column[64],0);
delay(1);
turnEverythingOff();


/*
335,
344,
354,
*/
digitalWrite(layer[3],1);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[54],0);
delay(1);
turnEverythingOff();


/*
444,
445,
454,
455,
*/
digitalWrite(layer[4],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
534,
535,
543,
546,
554,
555,
*/
digitalWrite(layer[5],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
634,
635,
643,
644,
645,
654,
655,
656,
*/
digitalWrite(layer[6],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
digitalWrite(column[56],0);
delay(1);
turnEverythingOff();


/*
734,
735,
744,
745,
746,
754,
755,
*/
digitalWrite(layer[7],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
834,
843,
844,
845,
*/
digitalWrite(layer[8],1);
digitalWrite(column[34],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();


/*
944,
*/
digitalWrite(layer[9],1);
digitalWrite(column[44],0);
delay(1);
turnEverythingOff();
}
////////////////////////////////////////////////////////////////////////////////////Seventeenth Image
void seventeenImg(){

/*
34,
35,
45,
*/
digitalWrite(layer[0],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();


/*
135,
144,
154,
164,
174,
*/
digitalWrite(layer[1],1);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[54],0);
digitalWrite(column[64],0);
digitalWrite(column[74],0);
delay(1);
turnEverythingOff();


/*
235,
244,
274,
*/
digitalWrite(layer[2],1);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[74],0);
delay(1);
turnEverythingOff();


/*
335,
344,
*/
digitalWrite(layer[3],1);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
delay(1);
turnEverythingOff();


/*
434,
435,
442,
444,
445,
454,
457,
*/
digitalWrite(layer[4],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[42],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[54],0);
digitalWrite(column[57],0);
delay(1);
turnEverythingOff();


/*
534,
535,
542,
543,
554,
555,
*/
digitalWrite(layer[5],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[42],0);
digitalWrite(column[43],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
633,
634,
635,
643,
644,
645,
654,
655,
656,
*/
digitalWrite(layer[6],1);
digitalWrite(column[33],0);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
digitalWrite(column[56],0);
delay(1);
turnEverythingOff();


/*
734,
735,
744,
745,
746,
754,
*/
digitalWrite(layer[7],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
delay(1);
turnEverythingOff();


/*
834,
844,
845,
*/
digitalWrite(layer[8],1);
digitalWrite(column[34],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();


/*
944,
*/
digitalWrite(layer[9],1);
digitalWrite(column[44],0);
delay(1);
turnEverythingOff();
}
////////////////////////////////////////////////////////////////////////////////////Eighteenth Image
void eighteenImg(){

/*
44,
45,
53,
54,
55,
*/
digitalWrite(layer[0],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[53],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();



/*
145,
154,
164,
*/
digitalWrite(layer[1],1);
digitalWrite(column[45],0);
digitalWrite(column[54],0);
digitalWrite(column[64],0);
delay(1);
turnEverythingOff();


/*
234,
244,
245,
254,
*/
digitalWrite(layer[2],1);
digitalWrite(column[34],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[54],0);
delay(1);
turnEverythingOff();


/*
334,
335,
344,
345,
*/
digitalWrite(layer[3],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();


/*
444,
445,
457,
*/
digitalWrite(layer[4],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[57],0);
delay(1);
turnEverythingOff();


/*
534,
535,
543,
544,
545,
546,
554,
555,
557,
*/
digitalWrite(layer[5],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
digitalWrite(column[57],0);
delay(1);
turnEverythingOff();


/*
634,
635,
643,
644,
645,
646,
654,
655,
*/
digitalWrite(layer[6],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
734,
735,
744,
745,
746,
754,
755,
*/
digitalWrite(layer[7],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
843,
844,
845,
*/
digitalWrite(layer[8],1);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();


/*
944,
945,
*/
digitalWrite(layer[9],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();
}
////////////////////////////////////////////////////////////////////////////////////Nineteenth Image
void nineteenImg(){

/*
24,(A0,24)
34,(A0,34)
44,(A0,44)
54,(A0,b0)
55,(A0,b1)
*/
digitalWrite(layer[0],1);
digitalWrite(column[24],0);
digitalWrite(column[34],0);
digitalWrite(column[44],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
134,(A1,34)
144,(A1,44)
155,(A1,b1)
*/
digitalWrite(layer[1],1);
digitalWrite(column[34],0);
digitalWrite(column[44],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
234,(A2,34)
245,(A2,45)
255,(A2,b1)
*/
digitalWrite(layer[2],1);
digitalWrite(column[34],0);
digitalWrite(column[45],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
334,(A3,34)
345,(A3,45)
*/
digitalWrite(layer[3],1);
digitalWrite(column[34],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();


/*
434,(A4,34)
444,(A4,44)
447,(A4,47)
*/
digitalWrite(layer[4],1);
digitalWrite(column[34],0);
digitalWrite(column[44],0);
digitalWrite(column[47],0);
delay(1);
turnEverythingOff();


/*
534,(A5,34)
535,(A5,35)
543,(A5,43)
544,(A5,44)
547,(A5,47)
553,(A5,53)
554,(A5,b0)
555,(A5,b1)
*/
digitalWrite(layer[5],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[47],0);
digitalWrite(column[53],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
634,(A6,34)
635,(A6,35)
644,(A6,44)
645,(A6,45)
646,(A6,46)
653,(A6,53)
654,(A6,b0)
655,(A6,b1)
*/
digitalWrite(layer[6],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[53],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
734,(A7,34)
735,(A7,35)
743,(A7,43)
744,(A7,44)
745,(A7,45)
746,(A7,46)
754,(A7,b0)
755,(A7,b1)
*/
digitalWrite(layer[7],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
844,(A8,44)
845,(A8,45)
846,(A8,46)
*/
digitalWrite(layer[8],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
delay(1);
turnEverythingOff();


/*
944,(A9,44)
945,(A9,45)
*/
digitalWrite(layer[9],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();
}
////////////////////////////////////////////////////////////////////////////////////Twentieth Image
void twentyImg(){

/*
24,(A0,24)
54,(A0,b1)
64,(A0,b10)
65,(A0,b11)
*/
digitalWrite(layer[0],1);
digitalWrite(column[24],0);
digitalWrite(column[54],0);
digitalWrite(column[64],0);
digitalWrite(column[65],0);
delay(1);
turnEverythingOff();


/*
114,(A1,14)
124,(A1,24)
155,(A1,b1)
165,(A1,b11)
*/
digitalWrite(layer[1],1);
digitalWrite(column[14],0);
digitalWrite(column[24],0);
digitalWrite(column[55],0);
digitalWrite(column[65],0);
delay(1);
turnEverythingOff();


/*
224,(A2,24)
234,(A2,34)
245,(A2,45)
255,(A2,b1)
265,(A2,b11)
*/
digitalWrite(layer[2],1);
digitalWrite(column[24],0);
digitalWrite(column[34],0);
digitalWrite(column[45],0);
digitalWrite(column[55],0);
digitalWrite(column[65],0);
delay(1);
turnEverythingOff();


/*
334,(A3,34)
345,(A3,45)
*/
digitalWrite(layer[3],1);
digitalWrite(column[34],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();


/*
434,(A4,34)
444,(A4,44)
445,(A4,45)
447,(A4,47)
463,(A4,b9)
*/
digitalWrite(layer[4],1);
digitalWrite(column[34],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[47],0);
digitalWrite(column[63],0);
delay(1);
turnEverythingOff();


/*
534,(A5,34)
535,(A5,35)
543,(A5,43)
546,(A5,46)
547,(A5,47)
553,(A5,53)
554,(A5,b0)
555,(A5,b1)
*/
digitalWrite(layer[5],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[43],0);
digitalWrite(column[46],0);
digitalWrite(column[47],0);
digitalWrite(column[53],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
634,(A6,34)
635,(A6,35)
644,(A6,44)
645,(A6,45)
646,(A6,46)
647,(A6,47)
653,(A6,53)
654,(A6,b0)
655,(A6,b1)
*/
digitalWrite(layer[6],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[47],0);
digitalWrite(column[53],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
734,(A7,34)
735,(A7,35)
744,(A7,44)
745,(A7,45)
746,(A7,46)
754,(A7,b0)
755,(A7,b1)
*/
digitalWrite(layer[7],1);
digitalWrite(column[34],0);
digitalWrite(column[35],0);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
digitalWrite(column[54],0);
digitalWrite(column[55],0);
delay(1);
turnEverythingOff();


/*
844,(A8,44)
845,(A8,45)
846,(A8,46)
*/
digitalWrite(layer[8],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
digitalWrite(column[46],0);
delay(1);
turnEverythingOff();


/*
944,(A9,44)
945,(A9,45)
*/
digitalWrite(layer[9],1);
digitalWrite(column[44],0);
digitalWrite(column[45],0);
delay(1);
turnEverythingOff();
}
///////////////////////////////////////////////////////////turn all off
void turnEverythingOff()
 {
   for(int i = 0; i<100; i++)
   {
     digitalWrite(column[i], 1); //Cathode columns
   }
   for(int i = 0; i<10; i++)
   {
     digitalWrite(layer[i], 0); //Anode layers
   }
 }

////////////////////////////////////////////////////////////turn all on
void turnEverythingOn()
{
  for(int i = 0; i<100; i++)
  {
    digitalWrite(column[i], 0);
  }
  //turning on layers
  for(int i = 0; i<10; i++)
  {
    digitalWrite(layer[i], 1);
  }
}
///////////////////////////////////////////////////////turn columns off
void turnColumnsOff()
{
  for(int i = 0; i<100; i++)
  {
    digitalWrite(column[i], 1);
  }
}
/////////////////////////////////////////////////////////////flicker on
void flickerOn()
{
  int i = 150;
  while(i != 0)
  {
    turnEverythingOn();
    delay(i);
    turnEverythingOff();
    delay(i);
    i-= 5;
  }
}
//////////////turn everything on and off by layer up and down NOT TIMED
void turnOnAndOffAllByLayerUpAndDownNotTimed()
{
  int x = 75;
  for(int i = 11; i != 0; i--)
  {
    turnEverythingOn();
    for(int i = 10; i!=0; i--)
    {
      digitalWrite(layer[i-1], 0);
      delay(x);
    }
    for(int i = 0; i<10; i++)
    {
      digitalWrite(layer[i], 1);
      delay(x);
    }
      for(int i = 0; i<10; i++)
    {
      digitalWrite(layer[i], 0);
      delay(x);
    }
    for(int i = 10; i!=0; i--)
    {
      digitalWrite(layer[i-1], 1);
      delay(x);
    }
  }
}
//////////////////////////turn everything on and off by column sideways
void turnOnAndOffAllByColumnSideways()
{
  int x = 75;
  turnEverythingOff();
  //turn on layers
  for(int i = 0; i<10; i++)
  {
    digitalWrite(layer[i], 1);
  }
  for(int y = 0; y<9; y++)
  {
    //turn on 0-3
    for(int i = 0; i<10; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    //turn on 4-7
    for(int i = 10; i<20; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    //turn on 8-11
    for(int i = 20; i<30; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    //turn on 12-15
    for(int i = 30; i<40; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
     for(int i = 40; i<50; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
     for(int i = 50; i<60; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
      for(int i = 60; i<70; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
      for(int i = 70; i<80; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
      for(int i = 80; i<90; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
      for(int i = 90; i<100; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    //turn off 0-3
    for(int i = 0; i<10; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    //turn off 4-7
    for(int i = 10; i<20; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    //turn off 8-11
    for(int i = 20; i<30; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    //turn off 12-15
    for(int i = 30; i<40; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
   
    for(int i = 40; i<50; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    for(int i = 50; i<60; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    for(int i = 60; i<70; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    for(int i = 70; i<80; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    for(int i = 80; i<90; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    for(int i = 90; i<100; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    //turn on 8-11
    for(int i = 90; i<100; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    //turn on 4-7
    for(int i = 80; i<90; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    //turn on 0-3
    for(int i = 70; i<80; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    for(int i = 70; i<80; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    for(int i = 60; i<70; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    for(int i = 50; i<60; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    for(int i = 40; i<50; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    for(int i = 30; i<40; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    for(int i = 20; i<30; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    for(int i = 10; i<20; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    for(int i = 0; i<10; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    //turn off 12-15
    for(int i = 90; i<100; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    //turn off 8-11
    for(int i = 80; i<90; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    //turn off 4-7
    for(int i = 70; i<80; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    //turn off 0-3
    for(int i = 60; i<70; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
     for(int i = 50; i<60; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    //turn off 8-11
    for(int i = 40; i<50; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    //turn off 4-7
    for(int i = 30; i<40; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    //turn off 0-3
    for(int i = 20; i<30; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    for(int i = 10; i<20; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
  }
}
/////////////////////////////////////////up and down single layer stomp
void layerstompUpAndDown()
{
  int x = 75;
  for(int i = 0; i<10; i++)
  {
    digitalWrite(layer[i], 0);
  }
  for(int y = 0; y<11; y++)
  {
    for(int count = 0; count<1; count++)
    { 
      for(int i = 0; i<10; i++)
      {
        digitalWrite(layer[i], 1);
        delay(x);
        digitalWrite(layer[i], 0);
      }
      for(int i = 10; i !=0; i--)
      {
        digitalWrite(layer[i-1], 1);
        delay(x);
        digitalWrite(layer[i-1], 0);
      }
    }
    for(int i = 0; i<10; i++)
    {
      digitalWrite(layer[i], 1);
      delay(x);
    }
    for(int i = 10; i!=0; i--)
    {
      digitalWrite(layer[i-1], 0);
      delay(x);
    }
  }
}
////////////////////////////////////////////////////////////flicker off
void flickerOff()
{
  turnEverythingOn();
  for(int i = 0; i!= 150; i+=5)
  {
    turnEverythingOff();
    delay(i+50);
    turnEverythingOn();
    delay(i);
  }
}
///////////////////////////////////////////around edge of the cube down
void aroundEdgeDown()
{
  for(int x = 200; x != 0; x -=50)
  {
    turnEverythingOff();
    for(int i = 10; i != 0; i--)
    {
      digitalWrite(layer[i-1], 1);
      digitalWrite(column[5], 0);
      digitalWrite(column[6], 0);
      digitalWrite(column[9], 0);
      digitalWrite(column[10], 0);
      
      digitalWrite(column[0], 0);
      delay(x);
      digitalWrite(column[0], 1);
      digitalWrite(column[4], 0);
      delay(x);
      digitalWrite(column[4], 1);
      digitalWrite(column[8], 0);
      delay(x);
      digitalWrite(column[8], 1);
      digitalWrite(column[12], 0);
      delay(x);
      digitalWrite(column[12], 1);
      digitalWrite(column[13], 0);
      delay(x);
      digitalWrite(column[13], 1);
      digitalWrite(column[15], 0);
      delay(x);
      digitalWrite(column[15], 1);
      digitalWrite(column[14], 0);
      delay(x);
      digitalWrite(column[14], 1);
      digitalWrite(column[11], 0);
      delay(x);
      digitalWrite(column[11], 1);
      digitalWrite(column[7], 0);
      delay(x);
      digitalWrite(column[7], 1);
      digitalWrite(column[3], 0);
      delay(x);
      digitalWrite(column[3], 1);
      digitalWrite(column[2], 0);
      delay(x);
      digitalWrite(column[2], 1);
      digitalWrite(column[1], 0);
      delay(x);
      digitalWrite(column[1], 1);
    }
  }
}
/////////////////////////////////////////////////////////random flicker
void randomflicker()
{
  turnEverythingOff();
  int x = 10;
  for(int i = 0; i !=750; i+=2)
  {
  int randomLayer = random(0,10);
  int randomColumn = random(0,100);
  
  digitalWrite(layer[randomLayer], 1);
  digitalWrite(column[randomColumn], 0);
  delay(x);
  digitalWrite(layer[randomLayer], 0);
  digitalWrite(column[randomColumn], 1);
  delay(x); 
  }
}
////////////////////////////////////////////////////////////random rain
void randomRain()
{
  turnEverythingOff();
  int x = 100;
  for(int i = 0; i!=60; i+=2)
  {
    int randomColumn = random(0,100);
    digitalWrite(column[randomColumn], 0);
    digitalWrite(layer[0], 1);
    delay(x+50);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[1], 1);
    delay(x);
    digitalWrite(layer[1], 0);
    digitalWrite(layer[2], 1);
    delay(x);
    digitalWrite(layer[2], 0);
    digitalWrite(layer[3], 1);
    delay(x);
    digitalWrite(layer[3], 0);
    digitalWrite(layer[4], 1);
    delay(x);
    digitalWrite(layer[4], 0);
    digitalWrite(layer[5], 1);
    delay(x);
    digitalWrite(layer[5], 0);
    digitalWrite(layer[6], 1);
    delay(x);
    digitalWrite(layer[6], 0);
    digitalWrite(layer[7], 1);
    delay(x);
    digitalWrite(layer[7], 0);
    digitalWrite(layer[8], 1);
    delay(x);
    digitalWrite(layer[8], 0);
    digitalWrite(layer[9], 1);
    delay(x+50);
    digitalWrite(layer[9], 0);
    digitalWrite(column[randomColumn], 1);
  }
}
/////////////////////////////////////////////////////diagonal rectangle
void diagonalRectangle()
{
  int x = 350;
  turnEverythingOff();
  for(int count = 0; count<11; count++)
  {
    //top left
    for(int i = 0; i<20; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[3], 1);
    digitalWrite(layer[2], 1);
    delay(x);
    turnEverythingOff();
    //middle middle
    for(int i = 10; i<30; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[1], 1);
    digitalWrite(layer[2], 1);
    delay(x);
    turnEverythingOff();
    //bottom right
    for(int i = 20; i<40; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[0], 1);
    digitalWrite(layer[1], 1);
    delay(x);
    turnEverythingOff();
    //bottom middle
    for(int i = 10; i<30; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[0], 1);
    digitalWrite(layer[1], 1);
    delay(x);
    turnEverythingOff();
    //bottom left
    for(int i = 0; i<20; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[0], 1);
    digitalWrite(layer[1], 1);
    delay(x);
    turnEverythingOff();
    //middle middle
    for(int i = 10; i<30; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[1], 1);
    digitalWrite(layer[2], 1);
    delay(x);
    turnEverythingOff();
    //top right
    for(int i = 20; i<40; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[2], 1);
    digitalWrite(layer[3], 1);
    delay(x);
    turnEverythingOff();
    //top middle
    for(int i = 10; i<30; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[2], 1);
    digitalWrite(layer[3], 1);
    delay(x);
    turnEverythingOff();
  }
  //top left
  for(int i = 0; i<20; i++)
  {
    digitalWrite(column[i], 0);
  }
  digitalWrite(layer[3], 1);
  digitalWrite(layer[2], 1);
  delay(x);
  turnEverythingOff();
}
//////////////////////////////////////////////////////////////propeller
void propeller()
{
  turnEverythingOff();
  int x = 90;
  for(int y = 10; y>0; y--)
  {
    for(int i = 0; i<6; i++)
    {
      //turn on layer
      digitalWrite(layer[y-1], 1);
      //a1
      turnColumnsOff();
      digitalWrite(column[0], 0);
      digitalWrite(column[5], 0);
      digitalWrite(column[10], 0);
      digitalWrite(column[15], 0);
      delay(x);
      //b1
      turnColumnsOff();
      digitalWrite(column[4], 0);
      digitalWrite(column[5], 0);
      digitalWrite(column[10], 0);
      digitalWrite(column[11], 0);
      delay(x);
      //c1
      turnColumnsOff();
      digitalWrite(column[6], 0);
      digitalWrite(column[7], 0);
      digitalWrite(column[8], 0);
      digitalWrite(column[9], 0);
      delay(x);
      //d1
      turnColumnsOff();
      digitalWrite(column[3], 0);
      digitalWrite(column[6], 0);
      digitalWrite(column[9], 0);
      digitalWrite(column[12], 0);
      delay(x);
      //d2
      turnColumnsOff();
      digitalWrite(column[2], 0);
      digitalWrite(column[6], 0);
      digitalWrite(column[9], 0);
      digitalWrite(column[13], 0);
      delay(x);
      //d3
      turnColumnsOff();
      digitalWrite(column[1], 0);
      digitalWrite(column[5], 0);
      digitalWrite(column[10], 0);
      digitalWrite(column[14], 0);
      delay(x);
    }
  }
  //d4
  turnColumnsOff();
  digitalWrite(column[0], 0);
  digitalWrite(column[5], 0);
  digitalWrite(column[10], 0);
  digitalWrite(column[15], 0);
  delay(x);
}
//////////////////////////////////////////////////////spiral in and out
void spiralInAndOut()
{
  turnEverythingOn();
  int x = 60;
  for(int i = 0; i<6; i++)
  {
    //spiral in clockwise
    digitalWrite(column[0], 1);
    delay(x);
    digitalWrite(column[1], 1);
    delay(x);
    digitalWrite(column[2], 1);
    delay(x);
    digitalWrite(column[3], 1);
    delay(x);
    digitalWrite(column[7], 1);
    delay(x);
    digitalWrite(column[11], 1);
    delay(x);
    digitalWrite(column[15], 1);
    delay(x);
    digitalWrite(column[14], 1);
    delay(x);
    digitalWrite(column[13], 1);
    delay(x);
    digitalWrite(column[12], 1);
    delay(x);
    digitalWrite(column[8], 1);
    delay(x);
    digitalWrite(column[4], 1);
    delay(x);
    digitalWrite(column[5], 1);
    delay(x);
    digitalWrite(column[6], 1);
    delay(x);
    digitalWrite(column[10], 1);
    delay(x);
    digitalWrite(column[9], 1);
    delay(x);
    ///////////////////////////////////////spiral out counter clockwise
    digitalWrite(column[9], 0);
    delay(x);
    digitalWrite(column[10], 0);
    delay(x);
    digitalWrite(column[6], 0);
    delay(x);
    digitalWrite(column[5], 0);
    delay(x);
    digitalWrite(column[4], 0);
    delay(x);
    digitalWrite(column[8], 0);
    delay(x);
    digitalWrite(column[12], 0);
    delay(x);
    digitalWrite(column[13], 0);
    delay(x);
    digitalWrite(column[14], 0);
    delay(x);
    digitalWrite(column[15], 0);
    delay(x);
    digitalWrite(column[11], 0);
    delay(x);
    digitalWrite(column[7], 0);
    delay(x);
    digitalWrite(column[3], 0);
    delay(x);
    digitalWrite(column[2], 0);
    delay(x);
    digitalWrite(column[1], 0);
    delay(x);
    digitalWrite(column[0], 0);
    delay(x);
    ///////////////////////////////////////spiral in counter clock wise
    digitalWrite(column[0], 1);
    delay(x);
    digitalWrite(column[4], 1);
    delay(x);
    digitalWrite(column[8], 1);
    delay(x);
    digitalWrite(column[12], 1);
    delay(x);
    digitalWrite(column[13], 1);
    delay(x);
    digitalWrite(column[14], 1);
    delay(x);
    digitalWrite(column[15], 1);
    delay(x);
    digitalWrite(column[11], 1);
    delay(x);
    digitalWrite(column[7], 1);
    delay(x);
    digitalWrite(column[3], 1);
    delay(x);
    digitalWrite(column[2], 1);
    delay(x);
    digitalWrite(column[1], 1);
    delay(x);
    digitalWrite(column[5], 1);
    delay(x);
    digitalWrite(column[9], 1);
    delay(x);
    digitalWrite(column[10], 1);
    delay(x);
    digitalWrite(column[6], 1);
    delay(x);
    //////////////////////////////////////////////spiral out clock wise
    digitalWrite(column[6], 0);
    delay(x);
    digitalWrite(column[10], 0);
    delay(x);
    digitalWrite(column[9], 0);
    delay(x);
    digitalWrite(column[5], 0);
    delay(x);
    digitalWrite(column[1], 0);
    delay(x);
    digitalWrite(column[2], 0);
    delay(x);
    digitalWrite(column[3], 0);
    delay(x);
    digitalWrite(column[7], 0);
    delay(x);
    digitalWrite(column[11], 0);
    delay(x);
    digitalWrite(column[15], 0);
    delay(x);
    digitalWrite(column[14], 0);
    delay(x);
    digitalWrite(column[13], 0);
    delay(x);
    digitalWrite(column[12], 0);
    delay(x);
    digitalWrite(column[8], 0);
    delay(x);
    digitalWrite(column[4], 0);
    delay(x);
    digitalWrite(column[0], 0);
    delay(x);
  }
}
//////////////////////////////////////go through all leds one at a time
void goThroughAllLedsOneAtATime()
{
  int x = 15;
  turnEverythingOff();
  for(int y = 0; y<11; y++)
  {
    //0-3
    for(int count = 10; count != 0; count--)
    {
      digitalWrite(layer[count-1], 1);
      for(int i = 0; i<10; i++)
      {
        digitalWrite(column[i], 0);
        delay(x);
        digitalWrite(column[i], 1);
        delay(x);
      }
    digitalWrite(layer[count-1], 0);
    }
    //4-7
    for(int count = 0; count < 10; count++)
    {
      digitalWrite(layer[count], 1);
      for(int i = 10; i<20; i++)
      {
        digitalWrite(column[i], 0);
        delay(x);
        digitalWrite(column[i], 1);
        delay(x);
      }
    digitalWrite(layer[count], 0);
    }
    //8-11
    for(int count = 10; count != 0; count--)
    {
      digitalWrite(layer[count-1], 1);
      for(int i = 20; i<30; i++)
      {
        digitalWrite(column[i], 0);
        delay(x);
        digitalWrite(column[i], 1);
        delay(x);
      }
    digitalWrite(layer[count-1], 0);
    }
    //12-15
    for(int count = 0; count < 10; count++)
    {
      digitalWrite(layer[count], 1);
      for(int i = 30; i<40; i++)
      {
        digitalWrite(column[i], 0);
        delay(x);
        digitalWrite(column[i], 1);
        delay(x);
      }
    digitalWrite(layer[count], 0);
    }
  }
}
