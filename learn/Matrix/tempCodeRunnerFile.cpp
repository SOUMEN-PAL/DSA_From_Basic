void spiral_Traversal(vector<vector<int>> &arr , int r , int c){
    int top = 0 , bottom = r-1 , left = 0 , right = c-1;
    while(top<=bottom && left<=right)
    {
        for(int i = left ; i<=right ; i++){
            cout<<arr[top][i]<<" ";
        }
        top++;
        for(int i = top ; i<=bottom ; i++){
            cout<<arr[i][right]<<" ";
        }
        right--;
        for(int i = right ; i>=left ; i--){
            cout<<arr[bottom][i]<<" ";
        }
        bottom--;
        for(int i = bottom ; i>=top ; i--){
            cout<<arr[i][left]<<" ";
        }
        left++;
    }
}