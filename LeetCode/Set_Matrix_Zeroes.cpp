#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool>rowVisit(matrix.size(),false);
        vector<bool>colVisit(matrix[0].size(),false);
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0){
                    rowVisit[i] = true;
                }
                if(matrix[i][j]==0){
                    colVisit[j]=true;
                }
            }
        }
        for(int i=0;i<r;i++){
            if(rowVisit[i]==true){
                for(int j=0;j<c;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=0;i<c;i++){
            if(colVisit[i]==true){
                for(int j=0;j<r;j++){
                    matrix[j][i]=0;
                }
            }
        }
    }
};

int main(){

    return 0;
}