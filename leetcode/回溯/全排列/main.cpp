/**
 * 给定一个数字列表，将数字列表中的数字进行全排列，并输出全排列的所有情况
 * 参考教程：
 * https://mp.weixin.qq.com/s/nMUHqvwzG2LmWA9jMIHwQQ
 */
#include<iostream>
#include<vector>

using namespace std;

/**
 * 判断num是否在routine内，是返回true，否返回false
 * @param routine
 * @param num
 * @return
 */
bool contains(vector<int> &routine, int num) {
    for (int i = 0; i < routine.size(); i++) {
        if (routine[i] == num) return true;
    }
    return false;
}

/**
 * 回溯
 * @param routine
 * @param choices
 */
void backTrace(vector<int> &routine, vector<int> &choices) {
    // 判断是否到达叶子节点，可能会想到用choices.empty()，但是我们并没有删除或添加choices里的元素，耗时
    if (routine.size() == choices.size()) {
        for (int i = 0; i < routine.size(); i++)
            cout << routine[i];
        cout << endl;
        return;
    }

    for (int i = 0; i < choices.size(); i++) {
        // do not remove from choices to avoid insert operation,
        // so we have to judge if it contains the num that should have been erased.
        if (contains(routine, choices[i])) continue;
        // remove the choice currently and add to routine
        //choices.erase(choices.begin() + i, choices.begin() + i + 1);
        routine.push_back(choices[i]);
        // start the subtree
        backTrace(routine, choices);
        // add back
        routine.pop_back();
    }
}

void result(vector<int> &nums) {
    vector<int> routine;
    backTrace(routine, nums);
}

int main() {
    vector<int> nums = {1, 2, 3, 4};

    result(nums);
    return 0;
}