#include <stdio.h>

#define C_BAT  (float)22.5 //Ah
const float c_dis_levels[] = {C_BAT/3, C_BAT/5, C_BAT/10, C_BAT/20, C_BAT/100}; 

//                  0,  10,   20,   30,   40,   50,   60,   70,   80,   90 
float dc_3[]  = {9.5,  10.0, 10.4, 10.7, 11.0, 11.2, 11.3, 11.5, 11.6, 11.7};
float dc_5[]  = {10.2, 10.6, 10.9, 11.2, 11.4, 11.6, 11.7, 11.8, 11,9, 12.0};
float dc_10[] = {11.0, 11.3, 11.5, 11.7, 11.9, 12.0, 12.2, 12.2, 12.3, 12.4};
float dc_20[] = {11.5, 11.7, 11.9, 12.1, 12.2, 12.3, 12.4, 12.5, 12.6, 12.7};
float dc_100[]= {11.7, 11.9, 12.1, 12.3, 12.4, 12.5, 12.55,12.6, 12.65,12.7}; 

float dc[5][10] = {{9.5,  10.0, 10.4, 10.7, 11.0, 11.2, 11.3, 11.5, 11.6, 11.7},
		   {10.2, 10.6, 10.9, 11.2, 11.4, 11.6, 11.7, 11.8, 11.9, 12.0},
		   {11.0, 11.3, 11.5, 11.7, 11.9, 12.0, 12.2, 12.2, 12.3, 12.4},
		   {11.5, 11.7, 11.9, 12.1, 12.2, 12.3, 12.4, 12.5, 12.6, 12.7},
		   {11.7, 11.9, 12.1, 12.3, 12.4, 12.5, 12.55,12.6, 12.65,12.7}};

float ip(float y, float x0, float y0, float x1, float y1){
  return x0+((y-y0)*(x1-x0)/(y1-y0));
}

unsigned char dc2graph(float c){
 unsigned char ret;
 if (c > C_BAT/3) ret = 0;
 else if (c > C_BAT/5) ret = 1;
 else if (c > C_BAT/10) ret = 2;
 else if (c > C_BAT/20) ret = 3;
 else ret = 4;
 return ret;  
}
float voltToChargeLevel(float v, float c){
 float *levels = dc[dc2graph(c)];
 for(unsigned char x; x<9; x++){
  if(v<levels[0]) return 0;
  if((v>=levels[x]) && (v<levels[x+1])) return ip(v, x, levels[x], x+1, levels[x+1])*10;
  if(v>levels[9]) return 100;
 }
}

int main(){
 float v = 12.47;
 for(float c=0.4; c<0.6; c+=0.1){
  printf("i%.2f\t%.0f%%\n", c, voltToChargeLevel(v, c));
 }
 return 0;
}
