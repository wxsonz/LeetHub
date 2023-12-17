from collections import defaultdict
from sortedcontainers import SortedDict

class FoodRatings:
    def __init__(self, foods, cuisines, ratings):
        self.food_ratings = defaultdict(SortedDict)
        self.food_indices = {}
        
        for idx, (food, cuisine, rating) in enumerate(zip(foods, cuisines, ratings)):
            self.food_ratings[cuisine][rating] = self.food_ratings[cuisine].get(rating, []) + [food]
            self.food_indices[food] = (cuisine, rating)

    def changeRating(self, food, newRating):
        cuisine, oldRating = self.food_indices[food]
        self.food_ratings[cuisine][oldRating].remove(food)
        if not self.food_ratings[cuisine][oldRating]:
            del self.food_ratings[cuisine][oldRating]
        self.food_ratings[cuisine][newRating] = self.food_ratings[cuisine].get(newRating, []) + [food]
        self.food_indices[food] = (cuisine, newRating)

    def highestRated(self, cuisine):
        if cuisine in self.food_ratings and self.food_ratings[cuisine]:
            highest_rated_food = self.food_ratings[cuisine].peekitem(-1)
            return sorted(highest_rated_food[1])[0]
        return ""

# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)