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

uint64_t fibonacci (uint64_t x, uint64_t y, uint64_t z);

int main (void)
{
  // Set an array of 100 elements and then add the first two.
  uint64_t * f = malloc(sizeof(uint64_t[100]));
  printf("[0] - %lu\n[1] - %lu\n", (f[0] = 1), (f[1] = 2));
  
  // Calculates a new element to the succession and then adds it to the arrangement. 
  // Finally it stops if it exceeds the number of 4 million.
  for (uint64_t i = 2; i < 101; i++) {
    uint64_t new_sucession = fibonacci(f[i-2], f[i-1], f[i]);
    f[i] = new_sucession;
    if (new_sucession < 4E6) {
      printf("[%lu] - %lu\n", i, f[i]);
    } else {
      break;
    }
  }

  // Sum all the even numbers of the succession
  uint64_t sum = 0;
  for (uint64_t i = 0; i < 101; i++) {
    if (f[i] % 2 == 0)
      sum += f[i];  
  }
  printf("Sum of even fibonacci number is: %lu\n", sum);

  free(f);
  return 0;
}

uint64_t fibonacci (uint64_t x, uint64_t y, uint64_t z) {
  return (z = x + y);
}
