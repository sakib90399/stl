class SnapshotArray {
public:
    vector<unordered_map<int,int>>A;
    int snap_id= -1;

    SnapshotArray(int length) {
        A.clear();
        A=vector<unordered_map<int,int>>(length);
        
    }
    
    void set(int index, int val) {
        A[index][snap_id]=val;
        
    }
    
    int snap() {
        snap_id++;
        return snap_id;
        
    }
    
    int get(int index, int snap_id) {
        int temp=snap_id-1;
        while(temp>=-1)
        {
            if(A[index].find(temp)==A[index].end())
            {
                temp--;
            }
            else
            {
                return A[index][temp];
            }
        }

        return 0;

        
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */