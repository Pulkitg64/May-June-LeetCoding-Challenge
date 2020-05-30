void heapify(double *arr, int *first,int *second,int n,int index)
{
    int left = 2*index+1;
    int right = 2*index+2;
    int greatest = index;
    if(left<=n && arr[left]>arr[greatest])
    {
        greatest = left;
    }
    if(right<=n && arr[right]>arr[greatest])
    {
        greatest = right;
    }
    
    if(greatest !=index)
    {
        swap(arr[index],arr[greatest]);
        swap(first[index],first[greatest]);
        swap(second[index],second[greatest]);
        heapify(arr,first,second,n,greatest);
    }
    return;
}

void max_heap(double *arr, int *first,int *second,int n)
{
    for(int i = (n-1)/2 ;i>=0;i--)
    {
         heapify(arr,first,second,n,i);
    }
}
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        double *arr = new double [k];
        int *first = new int[k];
        int *second = new int[k];
        
        for(int i=0;i<k;i++)
        {
            arr[i] = double(sqrt(double(points[i][0]*points[i][0] + points[i][1]*points[i][1])));
            first[i] = points[i][0];
            second[i] = points[i][1];
        }
        
  
        max_heap(arr,first,second,k-1);
        
        for(int i=k;i<points.size();i++)
        {
            
            if(arr[0]>double(sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1])))
            {
                
                arr[0] = double(sqrt(double(points[i][0]*points[i][0] + points[i][1]*points[i][1])));
                first[0] = points[i][0];
                second[0] = points[i][1]; 
                heapify(arr,first,second,k-1,0);
            }
            
        }
        
        vector<vector<int>> result;
        
        for(int i=0;i<k;i++)
        {
            result.push_back({first[i],second[i]});
        }
        
        return result;
        
        
        
    }
};