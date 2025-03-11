class Solution {
public:
    int numberOfSubstrings(string s) {
        //s only consists of a, b or c characters.
        //I think this might be helpful, as once u find out the a specific a,b,c is present
        //Then from that onwards all other will be a substring so just size()-j can be added
        //For count we can use a hash map


        //Steps
        // Take a hashmap
        // We have to iterate for eavh index to check till how much it is valid
        // i,j pointers to start and j should not cross n(length) also the while should not
        // Stop till the i reaches to j so that we do iterate for each index
        // Condition for checking will include map's count as if the count is ==3 means it has
        // All what we need for a valid condition.
        //When we reach a condition where j is pointing to some index and size of map==3 then
        //We can simply add s.length()-j to out answer.
        // Then iterate i++ 

        map<char,int>mp;
        int n=s.length();
        int i=0; int j=0; int ans=0;

        while(j<n){
            mp[s[j]]++;
            while(mp.size()==3){
                ans= ans+(n-j);
                if(mp[s[i]]==1)mp.erase(s[i]);
                else mp[s[i]]--;
                i++;
            }
            j++;
        }

        return ans;

    }
};