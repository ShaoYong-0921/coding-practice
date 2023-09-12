#include <iostream>

using namespace std;

int main()
{
    int x, y, result;
    int sum = 0;

    cout << "Input two integers X and Y: ";
    cin >> x >> y ;

    result = x * y;
    cout << "X * Y = " <<  result << endl;
    sum += result;

    
    if (y == 0) {
        cout << "X / Y = " << "NA" << endl;
    }
    else {
        result = x / y;
        cout << "X / Y = " << result << endl;
    }
    sum += result;

    // X % Y 
    if (y == 0) {
        cout << "X % Y = " << "NA" << endl;
    }
    else {
        result = x % y ;
        cout << "X % Y = " << result << endl;
    }
    sum += result;

    // –X % Y
    if (y == 0) {
        cout << "-X / Y = " << "NA" << endl;
    }
    else {
        result = -x % y;
        cout << "-X / Y = " << result << endl;
    }
    sum += result;

    // X % (-Y)
    if (y == 0) {
        cout << "X % (-Y) = " << "NA" << endl;
    }
    else {
        result = x % (-y);
        cout << "X % (-Y) = " << result << endl;
    }
    sum += result;

    // –X % (-Y)
    if (y == 0) {
        cout << "–X % (-Y) = " << "NA" << endl;
    }
    else {
        result = -x % (-y);
        cout << "–X % (-Y) = " << result << endl;
    }
    sum += result;

    cout << "Total Result = " << sum << endl;
    return 0;
}
