class Solution {
public:

    //Bohot dhyaan se, kyunki agar koi pehle -ve hai toh vo left me jaayega or right se collide
    //Nahi karega
    //Collison will only ouccr jab right right jaa rha ho or left aage kahin mil jaaye.

    //Mtlb stack.top() is positive and asteroids[i] is negative --> <--

    vector<int> asteroidCollision(vector<int>& astroids) {
        stack<int>st;

        for(int i=0; i<astroids.size();i++){

            if(!st.empty() && (st.top()>=0 && astroids[i]<=0)){
                
                if(abs(st.top()) == abs(astroids[i])){
                    st.pop();
                    continue;
                }

                while(!st.empty() && st.top() > 0 && abs(st.top()) < abs(astroids[i])){
                    st.pop();
                }

                if (!st.empty() && st.top() > 0 && abs(st.top()) == abs(astroids[i])) {
                    st.pop();
                    continue;
                }

                if(st.empty()){
                    st.push(astroids[i]);
                    continue;
                }
                else if(st.top()<0 && astroids[i]<0){
                    st.push(astroids[i]);
                    continue;
                }
                else{
                    continue;
                }
            }

            st.push(astroids[i]);    

        }

        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};