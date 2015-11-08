/*
 * https://www.hackerrank.com/challenges/palindrome-index
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define size 100006

/*
 * Detect a palindrome. Can work with a single
 * null character signifying to skip that index
 * by adding 1 to either the left or right side. 
 */
bool isPalindrome(char *str_ptr, int len) {
    int half_len = len/2;
    int i=0, index1, index2;
    bool skip1 = false;
    bool skip2 = false;
    for (i; i<len/2; i++) {
        if ( !(skip1 || skip2) ) {
            if ( *(str_ptr + i)  == '\0')
                skip1 = true;
            else if (*(str_ptr + len - i - 1) == '\0')
                skip2 = true;
        }
        
        if ( !(skip1 || skip2) ) {
            index1 = i;
            index2 = len - i -1;
        }
        else if (skip1) {
            index1 = i + 1;
            index2 = len - i - 1;
        }
        else if(skip2) {
            index1 = i;
            index2 = len - i - 2;
        }

        if ( *(str_ptr + index1) != *(str_ptr + index2))
            return false;
    }
    return true;
}

/* 
 * Scan halves until they don't match, then determine
 * which one should be removed to create a palindrome by
 * by removing the left character and check if it turns
 * into a palindrome. Otherwise it must be the right index.
 */
int findPalIndx(char *str_ptr, int len) {
    int half_len = len/2;
    int i = 0;
    int index = -1;
    int left, right;
    for (i; i<len/2; i++) {
        left = i;
        right = len - i - 1;
        if ( *(str_ptr + left) != *(str_ptr + right) ) {
            *(str_ptr + left) = '\0';
            if (isPalindrome(str_ptr, len))
                index = left;
            else
                index = right;
            break;
        }
    }
    return index;
}

int main() {
    int T;
    scanf("%d", &T);
    char str[100006];
    int length;
    while (T--) {
        scanf("%100006s", str);
        length = strlen(str);
        printf( "%d\n", findPalIndx(str, length) );
    }
    
    return 0;
}

