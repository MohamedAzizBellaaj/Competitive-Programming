#
# @lc app=leetcode id=2353 lang=python3
#
# [2353] Design a Food Rating System
#

# @lc code=start
from sortedcontainers import SortedSet


class FoodRatings:
    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.food_rating_map = {}

        self.food_cuisine_map = {}

        self.cuisine_food_map = defaultdict(SortedSet)

        for i in range(len(foods)):
            self.food_rating_map[foods[i]] = ratings[i]
            self.food_cuisine_map[foods[i]] = cuisines[i]

            self.cuisine_food_map[cuisines[i]].add((-ratings[i], foods[i]))

    def changeRating(self, food: str, newRating: int) -> None:
        cuisine_name = self.food_cuisine_map[food]

        old_element = (-self.food_rating_map[food], food)
        self.cuisine_food_map[cuisine_name].remove(old_element)

        self.food_rating_map[food] = newRating

        self.cuisine_food_map[cuisine_name].add((-newRating, food))

    def highestRated(self, cuisine: str) -> str:
        highest_rated = self.cuisine_food_map[cuisine][0]
        return highest_rated[1]


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)
# @lc code=end
