#include <iostream>
using namespace std;

void towerOfHanoi(int n, char A, char C, char B){
    if (n==1){
        cout << endl << "Move disk from " << A << " to " << C;
        return;
    }

    towerOfHanoi(n-1, A, B, C);
    cout << endl << "Move disk from " << A << " to " << C;
    towerOfHanoi(n-1, B, C, A);
}

int main(){

    char a = 'A', b = 'B', c = 'C';
    towerOfHanoi(4, a, c, b);

    return 0;
}