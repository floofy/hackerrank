#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/* Data structures
 * https://www.hackerrank.com/challenges/2d-array
 *
 * Author: Kenny Yee
 */

int NUM_COLS = 6;
int NUM_ROWS = 6;

int main(){
    int arr[6][6];
    int sum = 0;
    int max = 0;
    bool first = true;

    for(int arr_i = 0; arr_i < 6; arr_i++){
       for(int arr_j = 0; arr_j < 6; arr_j++){
          
          scanf("%d",&arr[arr_i][arr_j]);
       }
    }
    
    
    for(int row=0; row<NUM_ROWS-2; ++row) {
        for(int col=0; col<NUM_COLS-2; ++col) {
            sum = 0;
            // Sum row by row
            sum += arr[row][col];
            sum += arr[row][col+1];
            sum += arr[row][col+2];
            
            sum += arr[row+1][col+1];
            
            sum += arr[row+2][col];
            sum += arr[row+2][col+1];
            sum += arr[row+2][col+2];
            
            if(first) {
                max = sum;
                first = false;
            } else if (sum > max) {
                max = sum;
            }
        }
    }
    
    printf("%d\n", max);
    
    return 0;
}
