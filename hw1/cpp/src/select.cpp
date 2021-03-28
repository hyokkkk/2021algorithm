#include "select.hpp"

using namespace std;

//TODO: delete
#include <iostream>

int partition(vector<int>&, int, int);

int randomized_select(vector<int> &arr, int begin, int end, int i) {
    //1. 원소 하나면 그거 return
    if (begin == end){ return arr[begin]; }
    // 2. quick sort partition 한 후 pivot idx 받는다.
    int pidx = partition(arr, begin, end);

    //TODO: delete
    cout << "기준점: " << pidx << endl;



    return -1;
}

/* ---------------------------------------------
 * |  smaller  |  bigger   | undecided | pivot |
 * ---------------------------------------------
 *            ^             ^
 *            |             |
 *            s             u
 */
int partition (vector<int> &arr, int begin, int end){
        cout << "before" << endl;
    for (int i = begin; i <= end; i++){
        cout << arr[i] << " " << endl;
    }
        cout << "" << endl;



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
