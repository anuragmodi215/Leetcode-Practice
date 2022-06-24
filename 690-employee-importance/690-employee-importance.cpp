/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        queue<Employee*>q;
        unordered_map<int,Employee*>mp;
        for(auto i:employees){
            mp[i->id] = i;
        }
        q.push(mp[id]);
        int imp=0;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            imp = imp + front->importance;
            for(auto neig:front->subordinates){
                q.push(mp[neig]);
            }
        }
        return imp;
    }
};