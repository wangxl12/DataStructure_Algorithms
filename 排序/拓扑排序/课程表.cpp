#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        if(numCourses == 1) return 1;
        if(prerequisites.size() == 0) return 1;

        vector<int> indegree(numCourses, 0);  // each point's indegree
        vector<int> zeroin; // whose indegree is 0
        int cnt = 0; // the number of deleted point
        for(int i = 0;i<prerequisites.size();i++){
            indegree[prerequisites[i][1]] += 1;
        }
        for(int i = 0;i<indegree.size();i++){
            if(indegree[i] == 0) zeroin.push_back(i);
        }
        while(!zeroin.empty()){
            for(int j = 0;j<prerequisites.size();j++){
                if(prerequisites[j][0] == zeroin.back()){
                    indegree[prerequisites[j][1]]--;
                    if(indegree[prerequisites[j][1]] == 0){
                        zeroin.insert(zeroin.begin(),1,prerequisites[j][1]);
                    }
                }
            }
            indegree[zeroin.at(zeroin.size() - 1)] = -1;
            zeroin.pop_back();
            cnt += 1;
        }
        if(cnt == numCourses) return 1;
        return 0;
    }
};

int main(){
	Solution obj;
	int numCourses=2;
	vector<vector<int> > prerequisites(1,vector<int>(2,0));
	prerequisites[0][0] = 1;
	cout << obj.canFinish(numCourses,prerequisites);
	return 0;
}
