#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

vector<int> construct_nums(int nums_len = 100000) {
    vector<int> nums;
    for (int i = 0; i < nums_len; i ++) {
        nums.push_back(rand());
    }
    return nums;
}

void judge_quick_sort(function<void(vector<int>&, int, int)> f) {
    vector<int> nums = construct_nums();
    f(nums, 0, nums.size() - 1);
    cout << (is_sorted(nums.begin(), nums.end(), less<int>()) ? "Pass quick_sort" : "Fail quick_sort") << endl;
}

/*
数据结构 ｜ 数组 ｜ 链表 ｜ 栈 ｜ 队列 ｜ 树 ｜ 图
算法 ｜ 排序 ｜ 动态规划
递归
55 ｜ 107 ｜ 215 ｜ 268 ｜ 96
快速排序

数据结构与算法竟然满足某种代数性质。。满足某种代数结构

数学推导、技巧体系
Cheat Sheet
*/