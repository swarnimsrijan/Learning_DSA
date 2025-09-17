class FoodRatings {
public:
    using p = pair<int, string>;
    struct Comp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        }
    };
    // using pq = priority_queue;
    unordered_map<string, priority_queue<p, vector<p>, Comp>> mp;
    unordered_map<string, string> food_cuisine;
    unordered_map<string, int> food_rating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++){
            mp[cuisines[i]].push({ratings[i], foods[i]});
            food_cuisine[foods[i]] = cuisines[i];
            food_rating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food_cuisine[food];
        food_rating[food] = newRating;
        mp[cuisine].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto &pq = mp[cuisine];
        while(!pq.empty()){
            if(food_rating[mp[cuisine].top().second] == mp[cuisine].top().first){
                return mp[cuisine].top().second;
            }
            pq.pop();
        }
        return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */


 /** Time limit Exceed Code O(m + n)
 unordered_map<string, vector<pair<string, int>>> mp;
    unordered_map<string, string> food_cuisine;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++){
            mp[cuisines[i]].push_back({foods[i], ratings[i]});
        }
        for(int i = 0; i < foods.size(); i++){
            food_cuisine[foods[i]] = cuisines[i];
        }
    }
    void changeRating(string food, int newRating) {
        string cuisine = "";
        for(auto &it: food_cuisine){
            if(it.first == food){
                cuisine = it.second;
                break;
            }
        }
        for(auto &it: mp[cuisine]){
            if(it.first == food){
                it.second = newRating;
            }
        }
    }
    string highestRated(string cuisine) {
        int max_rating = INT_MIN;
        string max_rated_food = "";
        vector<pair<string, int>> temp = mp[cuisine];
        for(int i = 0; i < temp.size(); i++){
            max_rating = max(max_rating, temp[i].second);
            if(max_rating == temp[i].second){
                max_rated_food = temp[i].first;
            }
        }
        for(int i = 0; i < temp.size(); i++){
            if((max_rating == temp[i].second) && (max_rated_food > temp[i].first)){
                max_rated_food = temp[i].first;
            }
        }
        for (auto &it : mp) {
            cout << it.first << " -> "; 
            for (auto &p : it.second) { 
                cout << "(" << p.first << ", " << p.second << ") ";
            }
            cout << endl;
        }
        return max_rated_food;
    }
*/