#include <iostream>
#include <cmath> 

using namespace std;

int main() {

    double myHeight;
    double myWeight;
    double myBMI;
    bool testing = true;

    while (testing) {
        bool flag = true;

        // step 1
        cout << "Input weight(kg): ";
        cin >> myWeight;
        cout << "Input height(m): ";
        cin >> myHeight;

        //step2
        if ( myWeight < 20 || myWeight > 200) {
            cout << "# Invalid weight (>= 20kg and <= 200kg)\n";
            flag = false;
        }
        if ( myHeight < 0.9 || myHeight > 2.5) {
            cout << "# Invalid height (>= 0.9m and <= 2.5m)\n";
            flag = false;
        }

        if (!flag){
            cout << "\n";
            continue;
        }

        //BMI value
        myBMI = round(myWeight / (myHeight * myHeight) * 10 ) / 10.0;

        // program
        string BMI_level;

        if (myBMI <= 10){
            BMI_level = "unreasonably underweight";
        }

        else if (10 < myBMI && myBMI <= 15) {
            BMI_level = "highly severely underweight";
        }

        else if (15 < myBMI && myBMI <= 16) {
            BMI_level = "severely underweight";
        }

        else if (16 < myBMI && myBMI < 18.5) {
            BMI_level = "underweight";
        }

        else if (18.5 <= myBMI && myBMI <= 25) {
            BMI_level ="normal";
        }

        else if (25 < myBMI && myBMI <= 30) {
            BMI_level = "overweight";
        }
        
        else if (30 < myBMI && myBMI <= 35) {
            BMI_level = "obese";
        }

        else if (35 < myBMI && myBMI <= 40) {
            BMI_level = "severely obsese";
        }

        else if (40 < myBMI && myBMI <= 45) {
            BMI_level = "highly severely obese";
        }

        else if (myBMI > 45) {
            BMI_level = "unreasonably obese";
        }

        //step 3
        cout << "# Your weight(kg): " << myWeight << "\n";
        cout << "# Your height(m): " << myHeight << "\n";
        cout << "# Your BMI: " << myBMI << "\n";
        cout << "# Your BMI level is " << BMI_level << "\n";

        // step 4
        double H, W; 
        flag = true; //reset flag
        // myBMI = round(myWeight / (myHeight * myHeight) * 10 ) / 10.0;
        // H = ( myWeight / myBMI ) ** 0.5 
        // W =  myBMI * ( myHeight * myHeight ) 
        
        
        if (myBMI < 10){
            cout << "# Either weight or height might be wrongly given. (Step 4)." << "\n";
            H = sqrt( myWeight / 10 );
            W =  10 * ( myHeight * myHeight );
            cout << "# If given weight is correct, so the given height should be at most " << H << " m (Step 4).\n";
            cout << "# If given height is correct, so the given weight should be at least " << W << " kg (Step 4).\n";
            cout << "\n";
            flag = false;
        }

        else if(myBMI > 45) {

            cout << "# Either weight or height might be wrongly given (Step 4)." << "\n";
            
            H = sqrt( myWeight / 45 );
            W = 45 * ( myHeight * myHeight );
            cout << "# If given weight is correct, so the given height should be at most " << H << "m (Step 4).\n";
            cout << "# If given height is correct, so the given weight should be at least " << W << "kg (Step 4).\n";
            cout << "\n";
            flag = false;
        }
        

        // step 5
        if (!flag){
            continue;
        }

        if (myBMI < 18.5){
            W = 18.5 * ( myHeight * myHeight );
            cout << "# Increase your weight to " << W << " kg to bring your BMI value to 18.5 (Step 5).\n";
        }
        else if (myBMI > 25) {
            W = 25 * ( myHeight * myHeight );
            cout << "# Decrease your weight to " << W << " kg to bring your BMI value to 25 (Step 5).\n";
        }

        cout << "\n";
    }
    return 0;
} 