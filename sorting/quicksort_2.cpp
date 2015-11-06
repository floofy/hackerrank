'''
https://www.hackerrank.com/challenges/quicksort2/submissions/code/10735536
'''
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void printVect(vector<int> print) {
    for (int i=0; i<print.size(); i++)
        cout << print[i] << " ";
    cout << endl;
}

vector<int> quickSort(vector <int>  ar, int ar_size) {
    
    int pivot = ar[0];
    vector<int> lhs, rhs;
                                                                      // Base Cases
    if (ar_size == 1)                                                 // Return 1 element
        return ar;
    else if (ar_size == 2) {                                          // Sort 2 elements, print, return
        if (ar[0] > ar[1]) {
            ar[0] = ar[1];
            ar[1] = pivot;
        }
        printVect(ar);
        return ar;
    } else if (ar_size == 3) {  
        
        if ((ar[0] > ar[1] && ar[0] < ar[2]) || (ar[0] < ar[1] && ar[0] > ar[2])) { // when pivot is middle
            int swap = ar[0];
            ar[0] = ar[1];
            ar[1] = swap;
        
            if (ar[0] > ar[2]) {
                swap = ar[0];
                ar[0] = ar[2];
                ar[2] = swap;
            }
        
            printVect(ar);
            return ar;
        } else if (ar[0] > ar[1] && ar[0] > ar[2]) {                                // when pivot is greatest
            int swap = ar[0];
            if (ar[1] > ar[2]) {    // put second smallest # at first position
                ar[0] = ar[1];
                ar[1] = ar[2];
                ar[2] = swap;       // and largest last, so it prints first two, then all 3
            } else {
                ar[0] = ar[2];
                ar[2] = swap;
            }
        }

    }
    
    for (int i=0; i<ar_size; i++) {                       // fragment < pivot vector LHS and > pivot vector RHS
        if (ar[i] < pivot)
            lhs.push_back(ar[i]);
        else if (ar[i] != pivot) 
            rhs.push_back(ar[i]);
    }
  
    if (lhs.empty())
        lhs.push_back(pivot);                       // when pivot is smallest element
    else         
        lhs = quickSort(lhs, lhs.size());           // Recursion, build LHS and RHS side

    if (pivot != lhs[0] || rhs.empty())             // avoid duplication when pivot is smallest value
        lhs.push_back(pivot);                       // add pivot to LHS as greatest element
    
    if (rhs.size()>0)
        rhs = quickSort(rhs, rhs.size());

    for (int j=0; j<rhs.size(); j++)                 // combine lists
        lhs.push_back(rhs[j]);
    
    printVect(lhs);
    return lhs;
}

int main(void) {
    vector <int>  _ar;
    int _ar_size;
    cin >> _ar_size;
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp); 
    }

    quickSort(_ar, _ar_size);
   
   return 0;
}

