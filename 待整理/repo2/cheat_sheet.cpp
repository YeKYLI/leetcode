#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

// TRICK
// 一般只能一端访问数据时用top函数 而两端访问数据时用front和back函数 但是vector除外

// 整数
// #include <cstdlib> atoi atol atoll 字符串转整数
// to_string 整数转字符串
// INT32_MIN INT32_MAX
// abs 整数绝对值

// 最大公约数算法
int gcd(int a, int b) {
	return (a % b == 0) ? b : gcd(b, a % b);
}

// 树状数组
int n;
vector<int> nums(n, 0);
int lowbit(int x) {
	return x & -x;
}
void update(int x, int val) {
	while(x <= n) {
		nums[x] += val;
	}
}
int query(int x) {
	int output;
	while(x > 0) {
		output += nums[x];
	}
	return output;
}


int main() {

// vector
vector<int> nums({1, 34, 35, 43, 45634, 473, 373});
vector<int> nums_1(100, 0);

// sort
sort(nums.begin(), nums.end(), [](const int& x, const int& y) {return x < y; }); // 从小到大

// find
cout << " || " << *lower_bound(nums.begin(), nums.end(), 34) << " || " <<  endl; // 返回第一个大于等于某个值的迭代器的函数
cout << " || " << *upper_bound(nums.begin(), nums.end(), 34) << " || " <<  endl; // 返回第一个大于某个值的迭代器的函数

// reverse
reverse(nums.begin(), nums.end());

// stringstream
// #include <sstream>
std::string input ="41 3.14 false hello world";
std::istringstream  stream(input); 
int n;double f;bool b; 
stream >> n >> f >> std::boolalpha >> b;
cout << n << " || " <<  f << " || " <<  b << endl;

return 1;
}
