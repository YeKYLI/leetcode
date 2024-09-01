// https://github.com/doocs/leetcode/tree/main/solution

// 0. Two Sum
class Solution_0 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_map<int, int> record;
    for (int i = 0; i != nums.size(); ++i) {
        auto found = record.find(nums[i]);
        if (found != record.end())
            return {found->second, i};
        record.emplace(target - nums[i], i);
    }
    return {-1, -1};
}
};

// 1. Add Two Numbers
class Solution_1 {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(0), *tail = &dummy;
        for (div_t sum{0, 0}; sum.quot || l1 || l2; tail = tail->next) {
            if (l1) { sum.quot += l1->val; l1 = l1->next; }
            if (l2) { sum.quot += l2->val; l2 = l2->next; }
            sum = div(sum.quot, 10);
            tail->next = new ListNode(sum.rem);
        }
        return dummy.next;
    }
};

// 2. Longest Substring Without Repeating Characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t ret = 0, start = 0;
        unordered_map<char, size_t> trace;
        for (size_t i = 0; i < s.size(); ++i) {
            auto found = trace.find(s[i]);
            if (found != trace.end() && found->second >= start) {
                ret = max(ret, i - start);
                start = found->second + 1;
            }
            trace[s[i]] = i;
        }
        return max(ret, s.size() - start);
    }
};

// 4. Longest Palindromic Substring
class Solution {
    void longestPalindrome(const string& s, int b, int e, int &start, int &last) {
        int len = s.size();
        while (b >= 0 && e < len && s[b] == s[e])
            --b, ++e;
        ++b, --e;
        if (e - b > last - start) {
            start = b;
            last = e;
        }
    }

public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len == 0) return s;
        int start = 0, last = 0;
        for (int i=0; i<len-1; ++i) {
            longestPalindrome(s, i, i, start, last);
            longestPalindrome(s, i, i+1, start, last);
        }
        return s.substr(start, last-start+1);
    }
};

// 5. ZigZag Conversion
class Solution {
public:
    string convert(string s, int nRows) {
        if (s.empty() || nRows < 2) return s;
        std::vector<string> ret(nRows);
        for (size_t i=0; i<s.size(); ++i) {
            int m = i % (nRows-1), n = i / (nRows-1);
            (n & 0x1 ? ret[nRows-m-1] : ret[m]) += s[i];
        }
        return std::accumulate(ret.cbegin(), ret.cend(), string());
    }
};

// 6. Reverse Integer
class Solution {
public:
    int reverse(int x) {
        long res = 0;
        do {
            res = res*10 + x%10;
        } while (x /= 10);
        return res>INT_MAX ? 0 : res;
    }
};

// 7. Linked List Cycle
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head && head->next)
            for (ListNode *slower = head, *faster = head->next; faster && faster->next; slower = slower->next, faster = faster->next->next)
                if (slower == faster) return true;
        return false;
    }
};

// 8. Palindrome Number
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long rev{0}, origin{x};
        do {
            rev = rev * 10 + x % 10;
        } while (x /= 10);
        return rev == origin;
    }
};

// 9. Regular Expression Matching
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        for (char c=*p; c != '\0'; ++s, c=*p) {
            if (p[1] != '*') ++p;
            else if (isMatch(s, p+2)) return true;
            if (!(c == *s || (c == '.' && *s != '\0'))) return false;
        }
        return *s == '\0';
    }
};

// 10. Container With Most Water
class Solution {
public:
    int maxArea(vector<int> &height) {
        int ret{0};
        for (auto beg = height.begin(), end = prev(height.end()); beg < end; *beg < *end ? ++beg : --end)
            ret = max(ret, static_cast<int>(end - beg)*min(*beg, *end));
        return ret;
    }
};

// 11. Integer to Roman
class Solution {
public:
    string intToRoman(int num) {
        std::map<int, string> map = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, 
                                     {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        string ret;
        for (auto iter = map.rbegin(); iter != map.rend(); ++iter)
            while (num >= iter->first)
            {
                ret += map[iter->first];
                num -= iter->first;
            }
        return ret;
    }
};

// 12. Roman to Integer
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        for (auto iter = s.rbegin(); iter != s.rend(); ++iter)
            switch (*iter)
            {
                case 'I': res += res >= 5 ? -1 : 1; break;
                case 'V': res += 5; break;
                case 'X': res += 10 * (res >= 50 ? -1 : 1); break;
                case 'L': res += 50; break;
                case 'C': res += 100 * (res >= 500 ? -1 : 1); break;
                case 'D': res += 500; break;
                case 'M': res += 1000; break;
            }
        return res;
    }
};

// 13. Longest Common Prefix
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";
        for (size_t i=0; i<strs.front().size(); ++i) {
            for (const auto &str : strs)
                if (i == str.size() || str.at(i) != strs.front().at(i))
                    return strs.front().substr(0, i); 
        }
        return strs.front();
    }
};

// 15. 3Sum Closest
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        std::sort(num.begin(), num.end());
        int min{INT_MAX}, sum{0}, tmpsum{0};
        for (auto it=num.cbegin(); it!=num.cend(); ++it)
            for (auto b = std::next(it), e = std::prev(num.cend()); b<e; tmpsum > target ? --e : ++b)
                if ((tmpsum = *it + *b + *e) == target) return target;
                else if (std::abs(tmpsum - target) < min) {sum = tmpsum; min = std::abs(tmpsum - target);}
        return sum;
    }
};

// 16. Letter Combinations of a Phone Number
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret{""};
        array<string, 10> map{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (auto digit : digits) {
            vector<string> tmp;
            for (auto c : map[digit - '0'])
                for (const auto &pre : ret)
                    tmp.push_back(pre + c);
            ret = tmp;
        }
        return ret;
    }
};

// 17. 4Sum
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        if (num.size() < 4) return vector<vector<int>>{};
        std::set<vector<int>> ret;
        std::sort(num.begin(), num.end());
        std::unordered_map<int, vector<std::pair<int, int>>> cache;
        
        for (size_t i=0; i<num.size(); ++i)
            for (size_t j=i+1; j<num.size(); ++j)
                cache[num[i]+num[j]].emplace_back(i, j);
        
        for (const auto &rp : cache) {
            auto found = cache.find(target - rp.first);
            if (found != cache.end())
                for (const auto &low : rp.second)
                    for (const auto &high : found->second)
                        if (low.second < high.first) ret.insert(vector<int>{num[low.first], num[low.second], num[high.first], num[high.second]});
        }
        
        return vector<vector<int>>(ret.cbegin(), ret.cend());
    }
};

// 18. Remove Nth Node from End of List
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode **del = &head, *iter = head;
        for (int i=0; i<n; ++i, iter = iter->next) ;
        for (; iter != NULL; del = &((*del)->next), iter = iter->next ) ;
        *del = (*del)->next;
        return head;
    }
};

// 19. Valid Parentheses
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto c : s)
            if (!stk.empty() && ((c == ')' && stk.top() == '(') || (c == '}' && stk.top() == '{') || (c == ']' && stk.top() == '['))) stk.pop();
            else stk.push(c);
        return stk.empty();
    }
};

// 20. Merge Two Sorted Lists
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *header = NULL, **p;
        for (p = &header; l1 && l2; p = &(*p)->next)
        {
            if (l1->val <= l2->val)
            {
                *p = new ListNode(l1->val);
                l1 = l1->next;
            }
            else
            {
                *p = new ListNode(l2->val);
                l2 = l2->next;
            }
        }
        for (ListNode *leave = l1 ? l1 : l2; leave; leave = leave->next, p = &(*p)->next)
            *p = new ListNode(leave->val);
        return header;
    }
};

// 21. Generate Parentheses
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        std::function<void(string, int, int)> addParenthesis = [&](string str, int ln, int rn) {
            if (ln == 0 && rn == 0) vec.push_back(str);
            if (ln > 0) addParenthesis(str+"(", ln-1, rn+1);
            if (rn > 0) addParenthesis(str+")", ln, rn-1);
        };
        addParenthesis("", n, 0);
        return vec;
    }
};

// 22. Merge k Sorted Lists
class Solution {
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL, **lastPtrRef = &head;
        for (;l1 && l2; lastPtrRef = &((*lastPtrRef)->next)) {
            if (l1->val <= l2->val) { *lastPtrRef = l1; l1 = l1->next; }
            else { *lastPtrRef = l2; l2 = l2->next; }
        }
        *lastPtrRef = l1 ? l1 : l2;
        return head;
    }

    using vecNodeCIter = vector<ListNode *>::const_iterator;
    ListNode *mergeKLists(vecNodeCIter beg, vecNodeCIter end) {
        if (beg == end) return NULL;
        else if (std::distance(beg, end) == 1) return *beg;
        else if (std::distance(beg, end) == 2) return mergeTwoLists(*beg, *std::next(beg));
        else return mergeTwoLists(mergeKLists(beg, beg + std::distance(beg, end)/2), mergeKLists(beg + std::distance(beg, end)/2, end));
    }
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return mergeKLists(lists.cbegin(), lists.cend());
    }
};

// 23. Swap Nodes in Pairs
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        for (ListNode *p1 = newHead, *p2 = head; p2 && p2->next; p1 = p2, p2 = p2->next)
        {
            p1->next = p2->next;
            p2->next = p1->next->next;
            p1->next->next = p2;
        }
        return newHead->next;
    }
};

