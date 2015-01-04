vector<string> anagrams(vector<string>& strs)
{
    vector<string> res;
    map<string,vector<string>> mp;
    string tmp;
    for( int i = 0 ; i < strs.size() ; i++ )
    {
        tmp = strs[i];
        sort(tmp.begin(),tmp.end());
        mp[tmp].push_back(strs[i]);
    }
    for( map<string,vector<string>>::iterator itr = mp.begin() ; itr != mp.end() ; itr++ )
    {
        if( itr->second.size() > 1)
        {
            for( int i = 0 ; i < itr->second.size() ; i++ )
                res.push_back(itr->second[i]);
        }
    }
    return res;
}
