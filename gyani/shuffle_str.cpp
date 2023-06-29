class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        bool swapped;
        for(int i = 0; i < s.size()-1;i++)
        {
            swapped = false;
            for(int j = 0; j < s.size()-i-1; j++)
            {
                if(indices[j] > indices[j+1]) 
                {
                    swap(indices[j], indices[j+1]);
                    swap(s[j], s[j+1]);
                    swapped = true;
                }
            }

            if(swapped == false)
                break;
        }
        return s;
    }
};