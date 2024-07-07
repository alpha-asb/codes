class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count =0;
        int bottles = numBottles;
        int remaining = 0;
        while(bottles){
            count+=bottles;
            int temp = bottles+remaining;
            bottles = temp/numExchange;
            remaining = temp%numExchange;
        }
        return count;
    }
};
