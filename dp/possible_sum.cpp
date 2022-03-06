
vector<int> subsum(vector<int> v,int sum)
    {
        int n=v.size();
        bool t[n+1][sum+1];
        
        for(int i=0;i<n+1;i++)
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                    t[i][j]=false;
                if(j==0)
                    t[i][j]=true;
            }
        
        for(int i=1;i<n+1;i++)
            for(int j=1;j<sum+1;j++)
            {
                if(v[i-1]<=j)
                    t[i][j]=t[i-1][j-v[i-1]] || t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
            }
        vector<int> res;
        for(int i=0;i<sum+1;i++)
          if(t[n][i])
            res.push_back(i);
          
        return res;
        
    }
