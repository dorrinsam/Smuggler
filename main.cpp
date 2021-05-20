#define Q1
#ifdef Q1

#include<bits/stdc++.h>
using namespace std;

vector<int> vec;

int partition (int low, int high)
{
    int pivot =  vec[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if ( vec[j] < pivot)
        {
            i++;
            int t = vec[i];
            vec[i] = vec[j];
            vec[j] = t;
        }
    }
    int t = vec[i + 1];
    vec[i + 1] = vec[high];
    vec[high] = t;
    return (i + 1);
}

void quickSort( int low, int high)
{
    if (low < high)
    {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int main(){

    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vec.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    quickSort(0, n - 1);
    vector<int> vec1, ans;
    int sum = 0;
    for (int i = n - 1; i >= 0; --i) {
        vec1.push_back(vec[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (i){
            int j = 0;
            while(ans[j] <= vec1[i])
                j++;
            if (j < ans.size())
                ans[j] = vec1[i];
            else {
                ans.push_back(vec1[i]);
                sum++;
            }
        }
        else{
            ans.push_back(vec1[i]);
            sum++;
        }
    }
    cout << sum << endl;


    return 0;
}

#endif
