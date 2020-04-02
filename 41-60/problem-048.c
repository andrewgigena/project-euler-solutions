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
#include <gmp.h>

int main(void) {
  mpz_t x,y,result;
    
  mpz_init_set_str(x, "0", 10);
  mpz_init_set_str(y, "0", 10);
  mpz_init(result);

  while ( mpz_cmp_ui(x, 1000)) {
    // Add 1 to x
    mpz_add_ui(x, x, 1);

    // Set y as x*x,
    mpz_pow_ui(y, x, mpz_get_ui(x));
    
    /* Sum 1^1 + 2^2 + 3^3 + ... + 1000^1000 */
    mpz_add(result, result, y);    
    if ( mpz_get_ui(x) == 1000 ) {  
      printf ("1000^1000: ");
      mpz_out_str(stdout, 10, result);
      printf ("\n");
    }
  }
  
  /* Clean up */
  mpz_clear(x);
  mpz_clear(y);
  mpz_clear(result);
  return 0;
}
