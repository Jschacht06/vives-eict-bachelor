#include <iostream>

using namespace std;

int main(){

    int matrix [3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
    int vector [3] = {2,1,3};
    
    //berekening matrix * vector
    int resultVector [3] = {0,0,0};
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            resultVector[i] += matrix[i][j] * vector[j];
        }
    }
    cout << "Result vector: "<< endl;
    for (int i = 0; i < 3; i++){
        cout << "[" << resultVector[i] << "] " << endl;
    }

}
