#include<bits/stdc++.h>
using namespace std;

#define INF 1000


void printStep(int depth,int index,int alpha,int beta, string action){
    cout<<"Depth : "<<depth<<" | Node : "<<index <<" | alha : "<<alpha<<" | Beta : "<<beta<< " Action : "<<action<<endl;
}

// alpha-beta pruning minimax function, 

int alphaBetaMinimax(vector<int> &gameTree,int depth,int index,bool isMax, int alpha, int beta, int height){
    // base case , if we reach a leaf node, return it's value

    if(depth==height){
        printStep(depth,index,alpha,beta,"Leaf Node");
        return gameTree[index];
    }

    // max player turn, 

     if (isMax) {
        int best = -INF;
        for (int i = 0; i < 2; i++) { // Max can choose from two children
            int val = alphaBetaMinimax(gameTree, depth + 1, index * 2 + i, false, alpha, beta, height);
            best = max(best, val);
            alpha = max(alpha, best);

            printStep(depth, index, alpha, beta, "Max Node");

            // Alpha-Beta Pruning: Stop searching further
            if (beta <= alpha) {
                printStep(depth, index, alpha, beta, "Pruned");
                break;
            }
        }
        return best;
    }
    
    // min player turn 
    
    else {
        int best = INF;
        for (int i = 0; i < 2; i++) { // Min can choose from two children
            int val = alphaBetaMinimax(gameTree, depth + 1, index * 2 + i, true, alpha, beta, height);
            best = min(best, val);
            beta = min(beta, best);

            printStep(depth, index, alpha, beta, "Min Node");

            // Alpha-Beta Pruning: Stop searching further
            if (beta <= alpha) {
                printStep(depth, index, alpha, beta, "Pruned");
                break;
            }
        }
        return best;
    }
}

int log2(int n){
    return (n==1)? 0:1 + log2(n/2);
}

int main(){

    // game tree , leaft values (terminal nodes)
    vector<int>gameTree = {3,2,5,9,0,1,7,5};

    int treeHeight = log2(gameTree.size());

    cout<<"Alpha-Beta Pruning Execution : \n";

    int optimalValue = alphaBetaMinimax(gameTree,0,0,true,-INF,INF,treeHeight);
    cout<<"\n Optimal value for Max "<< optimalValue<<endl;

    return 0;
}
