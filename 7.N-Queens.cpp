#include<bits/stdc++.h>
using namespace std;

#define N 8 

// heuristic value calculation :- 

int getHeuristic(vector<int>& board){
    int h = 0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(board[i]==board[j]|| abs(board[i]-board[j])==abs(i-j)){
                h++;
            }
        }
    }
    return h;
}

//  print the board :- 

void printBoard(vector<int> & board){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[j]==i)cout<<" Q";
            else cout<<" . ";
        }
        cout<<endl;
    }
}


void hillClimbingWithRandomRestart(){
    srand(time(0));
    int attempts = 0;
    while(true){
        attempts++;
        // Generate a random initial board. 
        vector<int>board(N);
        for(int i=0;i<N;i++){
            board[i]=rand()%N;
        }

        while(true){
            int currentH = getHeuristic(board);
            if(currentH==0){
                cout<<"\n solution Found after : "<<attempts<<" attempts \n";
                printBoard(board);
                return;
            }


            vector<int>bestBoard=board;
            int bestH=currentH;

            // try to moving each queen to a different row.

            for(int col = 0; col < N; col++){
                for(int row=0;row<N;row++){
                    if(board[col]==row)continue;
                    vector<int>newBoard = board;
                    newBoard[col]=row;
                    int newH=getHeuristic(newBoard);

                    if(newH<bestH){
                        bestH=newH;
                        bestBoard=newBoard;
                    }
                }
            }

            // if no better neighbor, break and restart
            
            if(bestH>=currentH){
                break;
            }

            board=bestBoard;
        }
    }
}

int main(){
    hillClimbingWithRandomRestart();
    return 0;
}
