#include <iostream>

using namespace std;

int main(){
	int number_of_tests;
	cin >> number_of_tests;
	for (int i = 0; i < number_of_tests; i++)
    {
        int N, M;
		cin >> N >> M;
		cout << (N/3) * (M/3) << endl;
    }
    
    return 0;
}