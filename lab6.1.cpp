// Lab 6_1
#include <iomanip>
#include <iostream>
#include <ctime>

using namespace std;

int iter_sum(int *a, const int n){
    int s = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > 0 && a[i] % 3)
            s += a[i];
        
    return s;
}

void iter_replace(int *a, const int n){
    cout << "iter replace:" << endl;

    for (int i = 0; i < n; i++)
        if (a[i] > 0 && a[i] % 3)
            a[i] = 0;
}

int recur_sum(int *a, const int n, int i){
    if (i >= n)
        return 0;
    
    int s = 0;
    if (a[i] > 0 && a[i] % 3)
        s = a[i];
    return s + recur_sum(a, n, i+1);
}

int main(){
    srand( time( 0 ) );

    const int MIN = -10;
    const int MAX = 35;
    const int n = 22;

    int a[n];

    int s = 0;

    for (int i = 0; i < n; i++){
        a[i] = MIN + rand() % (MAX - MIN);
        cout << setw(4) << a[i];
    }
    cout << endl;

    cout << "iter s = " << iter_sum(a, n) << endl;
    cout << "recur s = " << recur_sum(a, n, 0) << endl;

    iter_replace(a, n);
    for (int i = 0; i < n; i++){
        cout << setw(4) << a[i];
    }

    return 0;
}