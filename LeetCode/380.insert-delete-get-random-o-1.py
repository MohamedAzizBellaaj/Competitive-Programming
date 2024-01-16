#
# @lc app=leetcode id=380 lang=python3
#
# [380] Insert Delete GetRandom O(1)
#


# @lc code=start
class RandomizedSet:
    import random

    def __init__(self):
        self.my_set = set()

    def insert(self, val: int) -> bool:
        if val not in self.my_set:
            self.my_set.add(val)
            return True
        else:
            return False

    def remove(self, val: int) -> bool:
        if val in self.my_set:
            self.my_set.remove(val)
            return True
        else:
            return False

    def getRandom(self) -> int:
        idx = random.randint(0, len(self.my_set) - 1)
        return list(self.my_set)[idx]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
# @lc code=end
