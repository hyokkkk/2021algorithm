#include "select.hpp"

using namespace std;

//TODO: delete
#include <iostream>

int partition(vector<int>&, int, int);

int randomized_select(vector<int> &arr, int begin, int end, int i) {
    // 1. 원소 하나면 그거 return
    if (begin == end){ return arr[begin]; }
    // 2. quick sort partition 한 후 pivot idx 받는다.
    int pidx = partition(arr, begin, end);
    // 3. pidx가 전체에서 k번째 작은 수다.
    int k = pidx - begin + 1;
    // 3. k vs. i
    if (k < i){ return randomized_select(arr, pidx+1, end, i-k); }
    else if (k == i){ return arr[pidx]; }
    else { return randomized_select(arr, begin, pidx-1, i); }
}

/* ---------------------------------------------
 * |  smaller  |  bigger   | undecided | pivot |
 * ---------------------------------------------
 *            ^             ^
 *            |             |
 *            s             u
 */
int partition (vector<int> &arr, int begin, int end){
    int pidx = end;         // 맨 마지막 원소를 항상 pivot
    int pivot = arr[pidx];

    int s = begin -1;       // s = smaller의 last elem
    int u = begin;          // u = undecided의 first elem

    for (; u < pidx; u++){
        // 1. [u] < pivot인 경우, [++s] <-> [u]
        if (arr[u] < pivot){
            int tmp = arr[++s];
            arr[s] = arr[u];
            arr[u] = tmp;
        }
        // 2. u는 매번 ++
    }
    // 3. [pidx] <-> [++s]
    int tmp = arr[pidx];
    arr[pidx] = arr[++s];
    arr[s] = tmp;

    return s;
}



int linear_select(vector<int> &arr, int i) { return -1; }

bool check(vector<int> &arr, int i, int x) { return false; }
