/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <random>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++) {
        arr[i] = rand() % 256;
    }
    
    int i = 0;
    int j = 0;
    while (i < N) {
        while (j < N - 1 - i) {
            if (arr[j] > arr[j+1]) {
                arr[j]   = arr[j] + arr[j+1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j]   = arr[j] - arr[j+1];
            }
            j++;
        } j = 0;
        i++;
    }

    for(int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
