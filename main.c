#include <stdio.h>

float dc_3[] = {9.5, 10.0, 10.4, 10.7, 11.2, 11.3, 11.5, 11.6, 11.7, 11.8};

float ip(float y, float x0, float y0, float x1, float y1){
  return x0+((y-y0)*(x1-x0)/(y1-y0));
}

float voltToChargeLevel(float v){
 float *levels = &dc_3[0];
 for(unsigned char x; x<9; x++){
  if(v<levels[0]) return 0;
  if((v>=levels[x]) && (v<levels[x+1])) return ip(v, x, levels[x], x+1, levels[x+1])*10;
  if(v>levels[9]) return 100;
 }
}

int main(){
 for(float x=11.2; x<11.5; x+=0.01){
  printf("v%.2f\t%.0f%%\n", x, voltToChargeLevel(x));
 }
 return 0;
}
