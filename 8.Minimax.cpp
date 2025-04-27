#include<bits/stdc++.h>
using namespace std;

int minimax(vector<int> & gameTree,int depth,bool isMax,int index,int height){
    // base case, if we reach a leaf node, return its value. 

    if(depth==height){
        return gameTree[index];
    }

    // max player's turn 

    if(isMax){
        return max(
            minimax(gameTree, depth + 1, false, index * 2, height),
            minimax(gameTree, depth + 1, false, index * 2 + 1, height)
        );
    }

    // min players' turn, 

    else {
        return min(
            minimax(gameTree, depth + 1, true, index * 2, height),
            minimax(gameTree, depth + 1, true, index * 2 + 1, height)
        );
    }

}


// determine the tree height, 

int log2(int n){
    return (n==1)? 0:1+log2(n/2);
}

int main(){

    // leaf values (terminal nodes)
    vector<int>gameTree = {-1,4,2,6,-3,-5,0,7};

    int treeHeight = log2(gameTree.size());
    cout<<"Optimal value for Max : "<< minimax(gameTree,0,true,0,treeHeight)<<endl;
    return 0; 
}

