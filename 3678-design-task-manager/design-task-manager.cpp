class TaskManager {
public:
    using p = pair<int, int>;
    struct Comp{
        bool operator()(const p& a, const p& b) const{
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        }
    };
    unordered_map<int, int> task_user;
    unordered_map<int, int> task_priority;
    priority_queue<p, vector<p>, Comp> pq;
    TaskManager(vector<vector<int>>& tasks) {
        for(int i = 0; i < tasks.size(); i++){
            task_user[tasks[i][1]] = tasks[i][0];
            task_priority[tasks[i][1]] = tasks[i][2];
            pq.push({tasks[i][2], tasks[i][1]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        task_user[taskId] = userId;
        task_priority[taskId] = priority;
        pq.push({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        task_priority[taskId] = newPriority;
        pq.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        task_priority[taskId] = -1;
    }
    
    int execTop() {
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            if(top.first == task_priority[top.second]){
                task_priority[top.second] = -1;
                return task_user[top.second];
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */