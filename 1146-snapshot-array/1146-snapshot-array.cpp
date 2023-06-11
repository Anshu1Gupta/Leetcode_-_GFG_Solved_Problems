class SnapshotArray {
public:
    vector<vector<pair<int,int>>>arr;
    
    int snap1=0;
    SnapshotArray(int length) {
        arr.resize(length);
    }
    
    void set(int index, int val) {
        arr[index].push_back({snap1,val});
    }
    
    int snap() {
        snap1++;
        return snap1-1;
    }
    
    int get(int index, int snap_id) {
        
        int i=0;
        int j=arr[index].size()-1;
        int ans=0;
        while(i<=j){
            int mid=(i+j)/2;
            if(arr[index][mid].first<=snap_id){
            ans=arr[index][mid].second; 
              i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */