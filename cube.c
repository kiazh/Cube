#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>

#define NB_COLS 206
#define NB_ROWS 49

uint8_t screen[NB_ROWS][NB_COLS];

float A, B, C;

float calculateX(int i, int j, int k){
  return 0.0f; 
}

float calculateY(int i, int j, int k){
  return 0.0f;
}

float calculateZ(int i, int j, int k){
  return 0.0f;
}

int main(){
  memset(screen, ' ', sizeof(screen));
  
  printf("\x1B[2J\x1B[?25l");
  while(true){
    printf("\x1B[Hhello world!");
  }
  printf("\x1B[2J\x1B[?25h");

  return 0;
}