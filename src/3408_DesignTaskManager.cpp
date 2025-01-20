#include <local_leetcode.hpp>

class TaskManager {
  private:
    typedef pair<int, int> ii_t;

    // task -> (user, priority)
    unordered_map<int, ii_t> tasks;

    // (priority, task)
    set<ii_t, greater<ii_t>> priority_tasks;
  
  public:
    TaskManager(vector<vector<int>>& _tasks) {
      for (auto& t : _tasks)
        add(t[0], t[1], t[2]);
    }
    
    void add(int userId, int taskId, int priority) {
      tasks[taskId] = {userId, priority};
      priority_tasks.emplace(priority, taskId);
    }
    
    // task -> priority
    void edit(int taskId, int newPriority) {
      auto iter = tasks.find(taskId);

      // update task info
      int priority = iter->second.second;
      iter->second.second = newPriority;

      // update (priority, task) pair
      priority_tasks.erase({priority, taskId});
      priority_tasks.emplace(newPriority, taskId);
    }
    
    void rmv(int taskId) {
      auto iter = tasks.find(taskId);

      // update (priority, task) pair
      priority_tasks.erase({iter->second.second, taskId});

      // update task info
      tasks.erase(iter);
    }
    
    int execTop() {
      if (priority_tasks.empty())
        return -1;

      int taskId = priority_tasks.begin()->second;

      auto iter = tasks.find(taskId);

      int userId = iter->second.first;
      tasks.erase(iter);

      priority_tasks.erase(priority_tasks.begin());

      return userId;
    }
};


int main() {
  EXECX(
    CTOR(vector<vector<int>>&),
    &TaskManager::add,
    &TaskManager::edit,
    &TaskManager::rmv,
    &TaskManager::execTop
  );
  return 0;
}
