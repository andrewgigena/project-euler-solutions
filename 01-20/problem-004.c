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
#include <stdbool.h>

int main (void) {
    uint64_t number = 0;
    uint64_t limitAbove = 1E3;
    uint64_t limitBelow = limitAbove - 1E2;
    char numberStr[6];
    bool isPalindrome = false;
    
    for (uint64_t i = limitAbove - 1 ; i >= limitBelow ; i--) {         // Check first [999-900] * [999-900] then [899-800] * [899-800]
        for (uint64_t j = limitAbove - 1 ; j >= limitBelow ; j--  ) {   // and so.
        number = i * j;                                                 // Calculate and convert to string
            sprintf(numberStr, "%lu", number);
            
            for (uint64_t k = 0 ; k < 6 ; k++) {                        // Check if the string and the string reversed is the same
                if (numberStr[5-k] == numberStr[k]) {
                    isPalindrome = true;
                } else {
                    isPalindrome = false;
                    break;
                }
            }

            if (isPalindrome == true) {                                 // After the check if still is considered a Palindrome, then
                printf("%lu = %lu * %lu\n", number, i, j);              // it is the large palindrome for 3 digits factors.
                return 0;
            }
        }
        if (i == limitBelow && limitBelow != 0) {
            limitAbove = limitBelow;                                    // This could be a problem, still an optimization for this case
            limitBelow -= 1E2;
        }
    }
}