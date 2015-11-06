/*
https://www.hackerrank.com/challenges/quicksort4/submissions/code/10798699
*/

/* Outputs the difference between the swaps of inserstion sort and quicksort


    Kenny Yee */

#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int _count = 0;
int _swaps = 0;

void insertionSortCount(int ar_size, int ar[]) {
    
    int temp;
    for (int i=0; i<ar_size-1; i++) {
        if(ar[i] > ar[i+1]){
            temp = ar[i+1];
            for (int j=i; j >= -1; j--) {
                if (ar[j] > temp && j >= 0) {
                    ar[j+1] = ar[j];
                    _count++;
                }
                else {
                    ar[j+1] = temp;
                    break;
                }
            }
        }
    }
    
} // end insertionSort

vector<int> inPlaceQuickSortSwaps(vector<int> sort, int start, int end) {
    if (sort.size() == 1) {
        _swaps++;
        return sort;
    }
    else if (end-start < 1)                  // size == 1
        return sort;
    
    int pivot = sort[end];
    
    int swap;
    queue<int> index;
    
    if (sort[start] > pivot)                              // if first element > pivot, index it
        index.push(start);
    else _swaps++;                                        // first number < pivot, so it swaps itself, swaps++
    
    for (int it=start+1; it<end; it++) {                  // move all < pivot #s left
 
        if (sort[it] <= pivot && !index.empty()) {        // swap < pivot to first > pivot
            swap = sort[index.front()];
            sort[index.front()] = sort[it];
            sort[it] = swap;
            index.pop();
            index.push(it);
            _swaps++;                                      // count the # of swaps
        } else if (sort[it] <= pivot) {
            _swaps++;                                      // swaps with itself, swaps++
        }else if(sort[it] > pivot)
            index.push(it);
            
    } // end for
    

    if (!index.empty()) {
        swap = sort[index.front()];                 // move pivot to left of all > pivots
        sort[index.front()] = pivot;
        sort[end] = swap;
    } else index.push(end);                         // if index empty then pivot is the greatest, index it for rec
    
    _swaps++;                                       // moving the pivot, swap++
    
    sort = inPlaceQuickSortSwaps(sort, start, index.front()-1);    // LHS from start to element before pivot
    sort = inPlaceQuickSortSwaps(sort, index.front()+1, end);      // RHS from element after pivot to end
    
    return sort;
} // end inPlaceQuickSort

int main(void) {
   
    int _ar_size;
    cin >> _ar_size;
    
    int _ar[_ar_size], _ar_i;
    vector<int> sort;
    
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        cin >> _ar[_ar_i];
        sort.push_back(_ar[_ar_i]);
    }

    //cout << _count << " " << _swaps << " ";
    insertionSortCount(_ar_size, _ar);
    sort = inPlaceQuickSortSwaps(sort, 0, _ar_size-1);
    //cout << _count << " " << _swaps << endl;
    
    cout << _count - _swaps;   
        
   return 0;
}
    
