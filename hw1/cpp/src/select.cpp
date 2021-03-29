#include "select.hpp"
#include "time.h"
#include "stdlib.h"

using namespace std;

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
    // 0. decide pivot by random select.
    // always put pivot at the end of the array. [ridx] <-> [end].
    srand(time(NULL));
    int ridx = rand() % (end - begin + 1) + begin;
    swap(arr, ridx, end);

    int pivot = arr[end];
    int s = begin -1;       // s = smaller의 last elem
    int u = begin;          // u = undecided의 first elem

    for (; u < end; u++){
        if (arr[u] < pivot){ swap(arr, ++s, u); }
    }
    swap(arr, end, ++s);
    return s;
}


int linear_select(vector<int> &arr, int begin, int end, int i) {

    // 1. elem이 5개 이하면 i번째 원소를 찾고 끝냄.
    int n = end - begin + 1;
    if (n <= 5){ return randomized_select(arr, begin, end, i); }

    // 2. 전체를 5개의 원소를 가진 그룹으로 나눔 -> n/5 + 1개
    int grpcnt= n % 5 ? n/5 + 1 : n/5;

    // 3. find medians of each group, and push into vector.
    vector<int> medians;
    for (int j = 0; j < grpcnt; j++){
        int start = begin + 5*j;
        int fin = start+4 > end ? end : start+4;
        int mid = (fin-start) / 2 + 1; // 해당 부분배열의 중간idx

        medians.push_back(randomized_select(arr, start, fin, mid));
    }

    // 4. find median of "medians".
    int median_of_medians = linear_select(medians, 0, grpcnt-1, (grpcnt-1)/2 + 1);

    // 5. find where median_of_medians is located in the original array.
    int midx;
    for (int a = begin; a <= end; a++){
        if (arr[a] == median_of_medians){ midx = a; }
    }

    // 6. median을 기준원소로 삼아 전체원소를 분할한다.
    int pidx = lpartition(arr, begin, end, midx);

    //6. 분할 후 적합한 쪽을 선택해 재귀반복.
    int k = pidx - begin + 1;
    if (k < i){ return linear_select(arr, pidx+1, end, i-k); }
    else if(k == i){ return arr[pidx]; }
    else { return linear_select(arr, begin, pidx-1, i); }
}


int lpartition (vector<int> &arr, int begin, int end, int pidx){
    // not a random partition. argument "pidx" is the fixed idx of pivot value.
    swap(arr, pidx, end);

    int pivot = arr[end];
    int s = begin -1;       // s = smaller의 last elem
    int u = begin;          // u = undecided의 first elem

    for (; u < end; u++){
        if (arr[u] < pivot){ swap(arr, ++s, u); }
    }
    swap(arr, end, ++s);
    return s;
}


void swap(vector<int>& arr, int idx1, int idx2){
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}


bool check(vector<int> &arr, int i, int x) { return false; }
