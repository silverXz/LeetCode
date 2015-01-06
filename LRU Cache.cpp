// Solution 1: My own lame version without using STL templates. There are a lot of room for improvement!
class LRUCache{
public:

    struct CachePair
    {
        int key;
        int val;
        CachePair(int _key = -1, int _val = -1 ):key(_key),val(_val) {}
    };

    LRUCache(int capacity) : m_capacity(capacity), m_size(0)
    {
        m_pCacheArray = new CachePair[capacity];
    }
    
    ~LRUCache()
    {
        if( m_pCacheArray )
            delete[] m_pCacheArray;
    }
    
    int get(int key) 
    {
        if( m_pCacheArray == 0 || m_size <= 0 )
            return -1;
        int result = -1;
        int i = 0;
        for( ; i < m_size ; i++ )
        {
            if( m_pCacheArray[i].key == key )
            {
                result = m_pCacheArray[i].val;
                break;
            }
        }
        
        if( i != m_size ) // found it!
        {
            remove(key);
            add(key,result);
        }
        
        return result;
    }
    
    int find(int key )
    {
        if( m_pCacheArray == 0 || m_size <= 0 )
            return -1;
        for( int i = 0 ; i < m_size ; i++ )
        {
            if( m_pCacheArray[i].key == key )
                return i;
        }
        return -1;
    }
    
    void remove(int key)
    {
        int pos = find(key);
        if( pos < 0 )
            return;
        for( int i = pos ; i < m_size -1 ; i++ )
            m_pCacheArray[i] = m_pCacheArray[i+1];
        m_size--;
    }
    
    void add(int key, int val)
    {
        if( m_size == m_capacity )
            remove(m_pCacheArray[0].key);
        m_pCacheArray[m_size++] = CachePair(key,val);
    }
    
    void set(int key, int val) 
    {
        remove(key);
        add(key,val);
    }
    
private:
    CachePair* m_pCacheArray;
    int m_capacity;
    int m_size;
    
};

// Solution 2: Using unordered_map and list.
class LRUCache{
public:
    LRUCache(int capacity)
    {
        cache_list.clear();
        cache_map.clear();
        m_capacity = capacity;
    }
    
    int get(int key)
    {
        unordered_map<int,list<pair<int,int>>::iterator>::iterator itr = cache_map.find(key);
        if( itr != cache_map.end()) // found it! we need to move it to the front of the cache list
        {
            cache_list.splice(cache_list.begin(),cache_list,itr->second);
            itr->second = cache_list.begin();
            return (itr->second)->second;
        }
        return -1;
    }
    
    void set(int key, int value) 
    {
        unordered_map<int,list<pair<int,int>>::iterator>::iterator itr = cache_map.find(key);
        if( itr != cache_map.end() )  // found it!
        {
            cache_list.splice(cache_list.begin(),cache_list,itr->second);
            itr->second = cache_list.begin();
            (itr->second)->second = value;
        }
        else    // Coundn't find it, then we need to add it to the front of the list.
        {
            if( cache_list.size() >= m_capacity )
            {
                cache_map.erase(cache_list.rbegin()->first);
                cache_list.pop_back();
            }
            cache_list.push_front(pair<int,int>(key,value));
            cache_map[key] = cache_list.begin();
        }
    }
    
private:
    list<pair<int,int>> cache_list;
    unordered_map<int,list<pair<int,int>>::iterator> cache_map;
    int m_capacity;
};


