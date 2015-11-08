/*
 * https://www.hackerrank.com/challenges/quicksort3/submissions/code/2623852
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void printArray(vector<int> print) {
    for(int i=0; i<print.size(); i++)
        cout << print[i] << " ";
    cout << endl;
}

vector<int> inPlaceQuickSort(vector<int> sort, int start, int end) {
    if (sort.size() == 1) {
        printArray(sort);
        return sort;
    } else if (end-start < 1)                  // size == 1
        return sort;
    
    int pivot = sort[end];
    
    int swap;
    queue<int> index;
    
    if (sort[start] > pivot)                 // if first element > pivot, index it
        index.push(start);
    
    for (int it=start+1; it<end; it++) {     // move all < pivot #s left
 
        if (sort[it] <= pivot && !index.empty()) {        // swap < pivot to first > pivot
            swap = sort[index.front()];
            sort[index.front()] = sort[it];
            sort[it] = swap;
            index.pop();
            index.push(it);
        } else if(sort[it] > pivot)
            index.push(it);
            
    } // end for
    

    if (!index.empty()) {
        swap = sort[index.front()];                 // move pivot to left of all > pivots
        sort[index.front()] = pivot;
        sort[end] = swap;
    } else index.push(end);                         // if index empty then pivot is the greatest, index it for rec
    
    printArray(sort);
    
    sort = inPlaceQuickSort(sort, start, index.front()-1);    // LHS from start to element before pivot
    sort = inPlaceQuickSort(sort, index.front()+1, end);      // RHS from element after pivot to end
    
    return sort;
}

int main() {
    int n, temp;
    cin >> n;
    
    vector<int> sort;
    for (int i=0; i<n; i++) {
        cin >> temp;
        sort.push_back(temp);
    }
    
    inPlaceQuickSort(sort, 0, sort.size()-1);

    return 0;
}

