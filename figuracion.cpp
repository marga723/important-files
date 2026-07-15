#include <iostream>
using namespace std;

int main() {
    
    int arr[5] = {10, 20, 30, 40, 50};
    
   
    cout << "The third element of the array is: " << arr[2] << endl;
    
   
    arr[4] = 100;
    
   
    cout << "Updated array elements: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
