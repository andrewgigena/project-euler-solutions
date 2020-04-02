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
#include <stdbool.h>
#include <math.h>

int main (int argc, char *argv[]) {
    uint64_t number = strtol(argv[1], NULL, 10);
    uint64_t factor = 0;
    for (uint64_t i = 3; i <= sqrt(number) ; i += 2) {              // Find if /i/ is a factor of /number/, skipping odds, from 3 to
        if ((number % i) == 0) {                                    // the squareroot of /number/
            bool isPrime = true;                                    // Assume that /i/ is a prime number.
                
            for (uint64_t j = i - 1 ; j > 1 ; j--) {                // The prime numbers only can be divided by itself and 1, so
                if ((i % j) == 0){                                  // they're excluded. Then we check if the /i/ is indeed a prime,
                    isPrime = false;                                // otherwise we mark it as false.
                    break;
                }
            }

            if (isPrime == true) {                                  // If /i/ pass the prime number check, save it for later. 
                factor = i;
            }
        }
    } 
    printf("The largest prime factor is: %lu\n", factor);           // Print the last prime factor of /number/

    return 0;
}