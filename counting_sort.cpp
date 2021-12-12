#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) (for(int i=a;i<b;++i))
#define fr freopen("input.txt", 'r', stdin)
#define fw freopen("output.txt", 'w', stdout)

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define CLS system("cls");

int main()
{
    FAST
    int arr[10] = {0, 5, 7, 4, 8, 5, 1, 2, 6, 9};
    int temp[10] = {0};

    for(int i:arr)
        temp[i]++;
   
    for(int i=0 ; i < 10; i++)
        while(temp[i]--)
            cout << i << " ";

    return 0;
}