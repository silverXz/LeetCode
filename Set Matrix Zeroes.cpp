class Solution {
public:

    // Solution one: Use O(M+N) Space. There're still room for improvement!
    void setZeroes(vector<vector<int> > &matrix) {
        
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
};
