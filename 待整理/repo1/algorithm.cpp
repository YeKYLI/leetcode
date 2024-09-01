// 快速排序
// 堆排序
// 归并排序
// 桶排序
// 基数排序
// 递归
// 最大公约数
// KMP算法
// AC自动机
// 字典树
// 线段树
// 树状数组
// 红黑树
// 并查集
// dijkstra
// prim
// kuraskal
// 拓扑排序
// 最大流
// 匈牙利算法
// 强连通分量
// 欧拉回路

// https://oi-wiki.org/
// https://github.com/ailyanlu1/ACM-10/blob/master/吉林大学ACM模板.pdf

#include <iostream>
#include <numeric>
#include "common.h"

using namespace std;

// 快速排序                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
void quick_sort(vector<int>& nums, int left, int right) {
    if(left >= right) return ;

    int pivot = nums[left];
    int lp = left;
    int rp = right;
    while(lp < rp) {
        while(lp < rp && nums[rp] > pivot) rp --;
        while(lp < rp && nums[lp] <= pivot) lp ++;
        if(lp < rp) swap(nums[lp], nums[rp]);
    }
    swap(nums[lp], nums[left]);
    quick_sort(nums, left, lp - 1);
    quick_sort(nums, lp + 1, right);
}

// 堆排序
void keep_heap(vector<int>& nums, int curr, int right) {
    int max_index = curr;
    if(curr * 2 <= right && nums[curr * 2] > nums[max_index]) max_index = curr * 2;
    if(curr * 2 + 1 <= right && nums[curr * 2 + 1] > nums[max_index]) max_index = curr * 2 + 1;
    if(curr != max_index) {
        swap(nums[curr], nums[max_index]);
        keep_heap(nums, max_index, right);
    }
}
void heap_sort(vector<int>& nums) {
    for(int i = nums.size() / 2 - 1; i >= 0; i --) {
        keep_heap(nums, i, nums.size() - 1);
    }
    for(int i = nums.size() - 1; i > 0; i --) {
        swap(nums[0], nums[i]);
        keep_heap(nums, 0, i - 1);
    }
}

// 归并排序

// 桶排序

// 基数排序

// 最大公约数
int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

// KMP
/*
vector<int> get_next(string p) {
    int i = 0, j = -1;
    vector<int> next(p.size(), -1);
    while(i < p.size()) {
        if(j == -1 || p[i] == p[j])
            next[++ i] = ++ j;
        else
            j = next[j];
    }
    return next;
}
int kmp(string s, string p) {
    vector<int> next = get_next(p);
    int i = 0, j = 0;
    while(i < s.size() && j < p.size()) {
        if(j == -1 || s[i] == p[j]) {
            i ++;
            j ++;
        } else 
            j = next[j];
    }
    if(j == p.size())
        return i - j;
    else
        return -1;
}
*/

// AC自动机

// 树状数组

// B+树

// Lsm树

// 红黑树

// 最大流

// 匈牙利算法

// 凸包

// // prim - krusal - dijkstra

// 线段树

// 树状数组

// 并查集
class dsu {

    vector<int> pa;

    int find(int x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }

    void unite(int x, int y) { pa[find(x)] = find(y); }

public:

    explicit dsu(int size) : pa(size) { iota(pa.begin(), pa.end(), 0); }
};

/*
void judge_heap_sort() {
    vector<int> nums;
    int nums_len = 100;
    for (int i = 0; i < nums_len; i ++) {

        int x = int(rand());
        // cout << x << " " ;
        nums.push_back(x);
    }
    heap_sort(nums);
    for (int i = 1; i < nums.size(); i ++)
        if (nums[i] < nums[i - 1]) {
            cout << "Fail heap_sort !!!" << endl;
            return ;
        }
    cout << "Sucess heap_sort" << endl;
}


void judge_gcd() {
    assert(gcd(1, 2) == 1);
    assert(gcd(2, 1) == 1);
    assert(gcd(4, 2) == 2);
    assert(gcd(3, 6) == 3);
    assert(gcd(6, 3) == 3);
    assert(gcd(9, 9) == 9);
    cout << "Sucess gcd" << endl;
}

void judge_kmp() {
    string s;
    int nums_len = 10000;
    for (int i = 0; i < nums_len; i ++) {
        s.push_back(int(rand()) % 10000);
    }

    int test_case = 0;
    while(true) {
        int left = int(rand()) % nums_len, right = int(rand()) % nums_len;
        if(left > right) continue;
        if(test_case ++ > 1) {
            break;
        }
        string p = s.substr(left, right - left);
        int start = kmp(s, p);
        cout << p << " || " << s.substr(start, right - left);
        if(p != s.substr(start, right - left)) {
            cout << "Kmp Fail" << endl;
            return ;
        }
    }
    cout << "Kmp Pass" << endl;
}
*/

// prim - krusal - dijkstra

int main() {
    judge_quick_sort(quick_sort);
    cout << "Hello, world" << endl;
    return 1;
}