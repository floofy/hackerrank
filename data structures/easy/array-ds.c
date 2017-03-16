#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/* Data Structures
 * https://www.hackerrank.com/challenges/arrays-ds
 *
 * Author: Kenny Yee
 */

int main(){
    unsigned int n; 

    scanf("%u",&n);
    int *arr = malloc(sizeof(int) * n);

    for(int arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
    }

    for(unsigned int i = n; i > 0; --i) {
        printf("%d ", *(arr + (i-1)));
    }
  
    return 0;
}
