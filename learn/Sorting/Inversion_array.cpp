#include<bits/stdc++.h>
using namespace std;

// naive solution //
int Count_Inversion(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }
    return count;
}



//___________Efficient Solution_____________//
int mergeCount(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1, n2 = high - mid;
    int leftArray[n1], rightArray[n2];
    for (int i = 0; i < n1; i++)
    {
        leftArray[i] = arr[low + i];
    }
    for (int i = 0; i < n2; i++)
    {
        rightArray[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = low, res = 0;
    while (i<n1 && j<n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            arr[k++] = leftArray[i++];
        }
        else
        {
            arr[k++] = rightArray[j++];
            res += n1 - i;
        }
    }
    while (i < n1)
    {
        arr[k++] = leftArray[i++];
    }
    while (j < n2)
    {
        arr[k++] = rightArray[j++];
    }

    return res;
}

int inverseCount(int arr[], int l, int r)
{
    int res = 0;
    if (l < r) {
        int mid = l + (r - l) / 2;
        res += inverseCount(arr, l, mid);
        res += inverseCount(arr, mid + 1, r);
        res += mergeCount(arr, l, mid, r);
    }
    return res;
}


int main() {
    int arr[] = {468 ,335 ,1 ,170 ,225 ,479 ,359 ,463 ,465 ,206 ,146 ,282 ,328 ,462 ,492 ,496 ,443 ,328 ,437 ,392 ,105 ,403 ,154 ,293 ,383 ,422 ,217 ,219 ,396 ,448 ,227 ,272 ,39 ,370 ,413 ,168 ,300 ,36 ,395 ,204 ,312 ,323};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << Count_Inversion(arr, n)<<endl;
    cout<<inverseCount(arr , 0 , n-1)<<endl;
    return 0;
}