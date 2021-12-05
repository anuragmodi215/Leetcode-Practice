class Solution {
public:
    vector<int> findAnagrams(string parent, string child) {
        unordered_map<char,int> parent_map;
        unordered_map<char,int> child_map;
        int n1 = parent.size(), n2=child.size();
        for(int i=0; i<n2; i++){
            child_map[child[i]]++;
        }
        int i=0,j=0;
        vector<int>ans;
        while(j<n1){
            if(j-i+1<n2){
                parent_map[parent[j]]++;
                j++;
            }
            else if(j-i+1==n2){
                parent_map[parent[j]]++;
                if(parent_map==child_map){
                    ans.push_back(i);
                }
                parent_map[parent[i]]--;
                if(parent_map[parent[i]]==0) parent_map.erase(parent[i]);
                j++;i++;
            }
        }
        return ans;
    }
};