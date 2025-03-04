class Solution {
public:
    //So the intution is this that as we have been given a range of 6 possible transitions
    //We can explore things in the same way...Meaning, this hints towards Recursion.

    //Now things to notice->

    //Here transition is not per table it has only be asked about the miniumum number of dice rolls
    //So we actually do not have to iterate on the table in some zig-zac manner 
    //Rather we can just take 1-n^2 possible values and iterate for every possible transition on them
    
    //Also to check for ladder or snake we just have to think of something mathematical to get value in O(1)
    //What I can see is, if the number we are at is present as a ladder/snake/-1, also to get there
    //THe maths could be about %,/and -n for row col finding also a even and odd will also contribute to know
    //The row to traverse leftwise or rightwise for our number

    //The last thing to remeber is taking a bool variable so that if we end up from a ladder/snake
    //to another ladder/snake we first mark it true and if again thing appears we return from there
    //Else if it is -1 then mark it again false.
    
    pair<int,int> solve(int x,int n){
        int a = (x-1)/n;
        int b = (n-1)-a;

        int col=(x-1)%n;

        if((n%2==1 && b%2==1)||(n%2==0 && b%2==0)){
            col=(n-1)-col;
        }
        return make_pair(b,col);
    }


    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int>q;
        q.push(1);
        int steps=0;
        int n=board.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        while(!q.empty()){
            int ni=q.size();
            while(ni--){
                int x=q.front();
                q.pop();   

                if(x==n*n)return steps;

                for(int k=1; k<=6; k++){
                    if (x + k > n * n) break;
                    pair<int,int>comp=solve(x+k,n);

                    int a=comp.first;
                    int b=comp.second;

                    if(vis[a][b])continue;
                    vis[a][b] = true;

                    if(board[a][b]==-1){
                        q.push(x+k);
                    }
                    else{
                        q.push(board[a][b]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};