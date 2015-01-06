class Solution {
public:

    // Solution one: Use O(M+N) Space. There're still room for improvement!
    void setZeroes(vector<vector<int> > &matrix) 
    {
        set<int> row;
    	set<int> colume;
    	for( int i = 0 ; i < matrix.size() ; i++ )
	    	for( int j = 0 ; j < matrix[i].size() ; j++)
	    	{
		    	if( matrix[i][j] == 0 )
			    {
				    row.insert(i);
			    	colume.insert(j);
			    }
	    	}
	    for( set<int>::iterator itr = row.begin() ; itr!= row.end() ; itr++ )
	    {
	    	for( int j = 0 ; j < matrix[*itr].size() ; j++ )
		    	matrix[*itr][j] = 0;
    	}

	    for( set<int>::iterator itr = colume.begin() ; itr!= colume.end() ; itr++)
	    {
		    for( int i = 0 ; i < matrix.size() ; i++ )
			    matrix[i][*itr] = 0;
    	}
    }
    
    // Solution2: O(1) space occupation
     void setZeroes2(vector<vector<int> > &matrix) 
     {
     	int col = 1;
	for( int i = 0 ; i < matrix.size() ; i++ )
	{
		if( matrix[i][0] == 0 )
			col = 0;
		for( int j = 1 ; j < matrix[i].size() ; j++ )
			if( matrix[i][j] == 0 )
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
	}
	
	for( int i = matrix.size() - 1 ; i >= 0 ; i-- )
	{
		for( int j = matrix[i].size() - 1 ; j >= 1 ; j-- )
		{
			if( matrix[i][0] == 0 || matrix[0][j] == 0 )
				matrix[i][j] = 0;
		}
		if( col == 0 )
			matrix[i][0] = 0;
	}
     }
    
};
