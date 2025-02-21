class Solution {
public:
    int characterReplacement(string s, int k) {
        
        //Window Length-maxfreq<=K 
        //Kyunki itna hi replace kar paaoge!

        int n = s.size();
        int left = 0, right = 0, maxFreq = 0, maxLen = 0;
        int hash[26] = {0};
        while(right<n){
            hash[s[right]-'A']++; 
            
            maxFreq = max(maxFreq,hash[s[right]-'A']); //Abhi tak ka maxfreq us window me
            
            if((right-left+1)-maxFreq > k){// Not possible to convert more than K toh kam karo 
            //Also neeche padho pehle
            //Haan it means that if i have got a length 5 then i will only have to check for 5<
            //Means we dont have to put a for loop and reduce the length.. rather just left++ once
            //And let the window be of 5 and then find for 6 further why would u go to shrink it to 4..3.2 something
            //Then again increase it till 5...possibly 6 for your answer...SO yahan hamne while loop bacha liya
                hash[s[left]-'A']--;
                left++;
            }
        //Acha ek point yaad rkhna suppose we have answer as 5 then we will not move towards 4 for less
        //WE will try to maximise it to 6

        //Len-Freq<=K suppose k=2
        //5  - 3  <=k, Now if im looking for a better length 6 will 3 contribute to it?? OFC not cause 6-3>K(2)
        //Isiliye ham kam karne ke baad check nahi karenge ki 5 se kam hua kya koi peeche se
        //Mtlb hash mein traverse nahi karna padega when we do hash[s[left]-'A']


            maxLen = max(maxLen, right-left+1);
            right++;
        }
        return maxLen;
    }
};

