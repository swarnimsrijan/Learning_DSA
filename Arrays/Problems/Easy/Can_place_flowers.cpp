#include <vector>

class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        int count = 0;
        int size = flowerbed.size();
        for (int i = 0; i < size; i++) {
            if (flowerbed[i] == 0) {
                if ((i == size - 1 || flowerbed[i + 1] == 0) && (i == 0 || flowerbed[i - 1] == 0)) {
                    flowerbed[i] = 1;
                    counta++;
                    i++;
                }
            }
        }
        return count >= n;
    }
};
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.insert(flowerbed.end(), 0);
        for(int i = 1; i < flowerbed.size() - 1; i++){
            if(flowerbed[i] != 1 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0){
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
};