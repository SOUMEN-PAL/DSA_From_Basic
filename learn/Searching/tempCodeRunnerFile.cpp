// Efficient Solution //
int median_Sorted(vector<int> v1 , vector<int> v2){
    int n1 = v1.size();
    int n2 = v2.size();
    if(n1>n2){
        return Median_sorted(v2 , v1);
    }
    int low = 0 , high = n1;
    int Real_mid = (n1 + n2 + 1)/2;
    while(low<=high){
        int mid1 = low + (high - low)/2;
        int mid2 = Real_mid - mid1;

        int min1 = (mid1<n1)?v1[mid1]:INT_MAX;
        int max1 = (mid1>0)?v1[mid1-1]:INT_MIN;

        int min2 = (mid2<n2)?v2[mid2]:INT_MAX;
        int max2 = (mid2>0)?v2[mid2-1]:INT_MIN;
        
        if(max1<=min2 && max2<=min1){
            if((n1 + n2) % 2==0){
                return (max(max1 , max2) + min(min1 , min2)) / 2.0;
            }
            else{
                return max(max1 , max2);
            }
        }
        else if(max1>min2){
            high  = mid1 - 1;
        }
        else{
            low = mid1 + 1;
        }
    }
    return 0.0;
}