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
    void helper(int id, unordered_map<int,Employee*>mp,int&sum){
        sum+=mp[id]->importance;
        for(auto neig: mp[id]->subordinates){
            helper(neig, mp, sum);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*>mp;
        for(auto i: employees){
            mp[i->id] = i;
        }
        int sum=0;
        helper(id,mp,sum);
        return sum;
    }
};