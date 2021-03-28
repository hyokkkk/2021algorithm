#include "select.hpp"
#include "time.h"
#include "stdlib.h"

using namespace std;

//TODO: delete
#include <iostream>

int rpartition(vector<int>&, int, int);
int lpartition(vector<int>&, int, int, int);
void swap(vector<int>&, int, int);

int randomized_select(vector<int> &arr, int begin, int end, int i) {
    // 1. 원소 하나면 그거 return
    if (begin == end){ return arr[begin]; }
    // 2. quick sort partition 한 후 pivot idx 받는다.
    int pidx = rpartition(arr, begin, end);
    // 3. pidx가 지금 돈 arr에서 k번째 작은 수다.
    int k = pidx - begin + 1;
    // 4. k vs. i
    if (k < i){ return randomized_select(arr, pidx+1, end, i-k); }
    else if (k == i){ return arr[pidx]; }
    else { return randomized_select(arr, begin, pidx-1, i); }
}

/* ---------------------------------------------
 * |  smaller  |  bigger   | undecided | pivot |
 * ---------------------------------------------
 *            ^             ^
 *            s             u
 */
int rpartition (vector<int> &arr, int begin, int end){
    // 0. [begin] ~ [end] 원소 random하게 뽑아서 pivot.
    srand(time(NULL));
    int ridx = rand() % (end - begin + 1) + begin;
    // [ridx] <-> [end]. pivot을 맨 뒤로 보냄.
    swap(arr, ridx, end);

    int pivot = arr[end];

    int s = begin -1;       // s = smaller의 last elem
    int u = begin;          // u = undecided의 first elem

    for (; u < end; u++){
        // 1. [u] < pivot인 경우, [++s] <-> [u]
        if (arr[u] < pivot){
            s++;
            swap(arr, s, u);
        }
        // 2. u는 매번 ++
    }
    // 3. [pidx] <-> [++s]
    s++;
    swap(arr, end, s);
    return s;
}


int linear_select(vector<int> &arr, int begin, int end, int i) {
    // 1. elem이 5개 이하면 i번째 원소를 찾고 끝냄.
    int n = end - begin + 1;
    if (n <= 5){
        return randomized_select(arr, begin, end, i);
    }
    // 2. 전체를 5개의 원소를 가진 그룹으로 나눔 -> n/5 + 1개
    int grpcnt= n % 5 ? n/5 + 1 : n/5;
    //TODO:
    cout << "grp cnt: " << grpcnt << endl;
    // 3. 각 그룹의 median을 찾음.
    for (int j = 0; j < grpcnt; j++){
        int start = begin + 5*j;
        int fin = start+4 > end ? end : start+4;
        int mid = (fin-start) / 2 + 1; // 해당 부분배열의 중간idx
        //TODO:
        cout << "start:" << start << " fin:" << fin << " mid:" << mid << endl;
        int tm = randomized_select(arr, start, fin, mid);
        // [start+mid-1] <-> [j]. 중간값 찾으면 앞쪽으로 차곡차곡 몬다.
        // 다 완성되면 [0]~[grpcnt-1] 까지는 각 grp의 midean들임.
        //TODO:
        cout << "median들: "<<tm<<endl;
        swap(arr, start+mid-1, j);
    }
    //TODO:
    cout << ""<< endl;
    // 4. 3에서 찾은 median들의 median을 찾음. [grpcnt-1 /2]에 위치함.
    // 맨 마지막 arg에는 idx가 아니라 th니까 +1해줌.
    cout << "m of m:"<< linear_select(arr, 0, grpcnt-1, (grpcnt-1) /2 + 1) << endl;
    // 5. median을 기준원소로 삼아 전체원소를 분할한다.
    int pidx = lpartition(arr, begin, end, (grpcnt-1) /2 +1);
    // 지금 돈 arr에서 k번째로 작은 idx이다.
    int k = pidx - begin + 1;
    //6. 분할 후 적합한 쪽을 선택해 재귀반복.
    if (k < i){ return linear_select(arr, pidx+1, end, i-k); }
    else if(k == i){ return arr[pidx]; }
    else { return linear_select(arr, begin, pidx-1, i); }
}

int lpartition (vector<int> &arr, int begin, int end, int pidx){
    swap(arr, pidx, end);

    int pivot = arr[end];

    int s = begin -1;       // s = smaller의 last elem
    int u = begin;          // u = undecided의 first elem

    for (; u < end; u++){
        // 1. [u] < pivot인 경우, [++s] <-> [u]
        if (arr[u] < pivot){
            s++;
            swap(arr, s, u);
        }
        // 2. u는 매번 ++
    }
    // 3. [pidx] <-> [++s]
    s++;
    swap(arr, end, s);
    return s;
}
void swap(vector<int>& arr, int idx1, int idx2){
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}
bool check(vector<int> &arr, int i, int x) { return false; }
