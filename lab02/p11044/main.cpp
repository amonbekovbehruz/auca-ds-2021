#include <iostream>

using namespace std;

int main(){
	int number_of_tests;
	cin >> number_of_tests;
	for (int i = 0; i < number_of_tests; i++)
    {
        int x, y;
		cin >> x >> y; 
		cout << (x/3) * (y/3) << endl;
    }
    
    return 0;
}