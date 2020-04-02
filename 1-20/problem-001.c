/*
 *  The MIT License
 * 
 *  Copyright (C) 2019 Andrew Gigena <andrewgigenadev@gmail.com>
 * 
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the
 *  "Software"), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject to
 *  the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 *  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 *  ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 *  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint64_t sum3 (uint64_t x);
uint64_t sum5 (uint64_t y);
uint64_t check (uint64_t z);

int main (void)
{
  uint64_t * s3 = malloc(sizeof(uint64_t[1000]));
  uint64_t * s5 = malloc(sizeof(uint64_t[1000]));
    
  uint64_t a = 0;
  for (uint64_t i = 1; a < 1000; i++) {
    s3[i] = sum3(i);
    a = s3[i];
  }
  
  uint64_t b = 0;
  uint64_t sumb = 0;
  for (uint64_t i = 1; b < 1000; i++) {
    s5[i] = sum5(i);
    b = s5[i];
    if (b < 1000)
      sumb += s5[i];
  }
  
  uint64_t c = 0;
  uint64_t suma = 0;
  for(uint64_t i = 1; c < 1000;i++) {
    c = s3[i];
    s3[i] = check(c);
    if (c < 1000)
      suma += s3[i];
  }
  
  printf("Sum: %lu\n", (suma + sumb));

  free(s3);
  free(s5);
  return 0;
}

uint64_t sum3 (uint64_t x) {return x*3;}
uint64_t sum5 (uint64_t y) {return y*5;}

uint64_t check (uint64_t z) {
  if ((z % 10) == 5){
    return 0;
  } else if ((z % 10) == 0) {
    return 0;
  } else {
    return z;
  }
}
