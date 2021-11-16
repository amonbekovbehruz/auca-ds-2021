#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    const int kNameWidth = 30;
    const int kAvgWidth = 40;

    cout << setfill('.')<< fixed;
    for (string name; cin >> name) 
    {
        double sum = 0;
        int nGrades = 0;
        for (int grades; cin >> grades)
        {
            sum += grades; 
        }

        if(nGrades != 0) {
            cout << left << setw(kNameWidth) << right << "|" << name << setw(kAvgWidth) << setprecision(2) << sum / nGrades << '\n'; 
        } else {
            cout << left << setw(kNameWidth) << name << "|" << right << setw(kAvgWidth + 1) <<"no data\n";
        }

        cout << name << " " << sum << '\n';
        cin.clear();    
    }
}