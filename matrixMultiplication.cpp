#include<bits/stdc++.h>
using namespace std;

int naive(int arr[], int n){
    int inv = 0;

    for (int i = 0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]) 
                inv++;
        }
    }
    return inv;
}

int mergex(int arr[], int l, int m, int r, int sorted[]){
    int x = l;
    int y = m+1;
    int z = l;

    int inv = 0;

    while(x <= m && y <= r){
        if(arr[x] > arr[y]){
            sorted[z] = arr[y];
            z++;
            y++;
            inv += m - x + 1;
            }
        else{
            sorted[z] = arr[x];
            x++;
            z++;
        }
    }

    while(x <= m){
        sorted[z] = arr[x];
        z++;
        x++;
    }
    while(y <= r){
        sorted[z] = arr[y];
        z++;
        y++;
    }
    for(int i = l; i <= r; i++)
        arr[i] = sorted[i];

    return inv;
}

int dNc(int arr[], int l, int r, int sorted[]){
    int inv = 0;
    if(l>=r) 
        return 0;

    else{
        int m = (r + l) / 2;
        inv += dNc(arr, l, m, sorted);
        inv += dNc(arr, m+1, r, sorted);

        inv += mergex(arr, l, m, r, sorted);
    }
    return inv;
}


int main(){
    int n;
    cout<<"the length of the array : ";
    cin >> n;
    cout<<"Array elements : ";
    int arr[n];
    for(int i=0; i < n; i++)
        cin>>arr[i];
    
    cout << "Naive : " << naive(arr, n) << endl;

    int sorted[n];
    cout << "Divide & Conquer : " << dNc(arr, 0, n-1, sorted) << endl;  
}