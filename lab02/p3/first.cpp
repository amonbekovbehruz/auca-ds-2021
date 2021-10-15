    #include <bits/stdc++.h>

    using namespace std;

    int main()
    {
        int number_of_tests;
        cin >> number_of_tests;
        int CORNER_SIDES = 2;

        for(int i = 0; i < number_of_tests; i++) {
            int x, y;
            cin >> x >> y;
            int total_number_of_trapes = 0;
            int number_of_horizontal_trape = 0;
            int number_of_vertical_trape = 0;
                

            int number_of_squares = ((y - CORNER_SIDES) / 3)*((x - CORNER_SIDES) / 3);
            
            if(((y - CORNER_SIDES) % 3 == 0) && ((x - CORNER_SIDES) % 3 == 0)) {
                total_number_of_trapes = number_of_squares; 
            } 
            if((x - CORNER_SIDES) % 3 == 0) {
                number_of_vertical_trape = 0;
                number_of_horizontal_trape = (x - CORNER_SIDES) / 3;

                total_number_of_trapes = number_of_horizontal_trape + 
                                        number_of_vertical_trape + 
                                        number_of_squares;
            } 
            if ((y - CORNER_SIDES) % 3 == 0) {
                number_of_vertical_trape = (y - CORNER_SIDES) / 3;
                number_of_horizontal_trape = 0;

                total_number_of_trapes = number_of_horizontal_trape + 
                                        number_of_vertical_trape + 
                                        number_of_squares;
            } 
            if((y - CORNER_SIDES) % 3 != 0 && (x - CORNER_SIDES) % 3 != 0) {
                number_of_vertical_trape = (y - CORNER_SIDES) / 3 + 1;
                number_of_horizontal_trape = (x - CORNER_SIDES) / 3 ;
            
                total_number_of_trapes = number_of_horizontal_trape + 
                                        number_of_vertical_trape + 
                                        number_of_squares;
            }
        
            cout << total_number_of_trapes << '\n';
    }   
    }