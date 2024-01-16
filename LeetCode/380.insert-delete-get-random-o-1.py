#
# @lc app=leetcode id=380 lang=python3
#
# [380] Insert Delete GetRandom O(1)
#


# @lc code=start
class RandomizedSet:
    import random

    def __init__(self):
        self.my_dict = {}
        self.data = []

    def insert(self, val: int) -> bool:
        if val in self.my_dict:
            return False
        else:
            self.my_dict[val] = len(self.data)
            self.data.append(val)
            return True

    def remove(self, val: int) -> bool:
        if val not in self.my_dict:
            return False
        else:
            idx = self.my_dict[val]
            last_val = self.data[-1]
            self.data[idx] = last_val
            self.my_dict[last_val] = idx

            self.data.pop()
            self.my_dict.pop(val)

            return True

    def getRandom(self) -> int:
        return random.choice(self.data)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
# @lc code=end
