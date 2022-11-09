#include <iostream>
using namespace std;
 
int main() {
    int x1, y1, x2, y2, dx, dy;

    cout << "Ingresa x1: ";
    cin >> x1;
    cout << endl << endl;

    cout << "Ingresa y1: ";
    cin >> y1;
    cout << endl << endl;

    cout << "Ingresa x2: ";
    cin >> x2;
    cout << endl << endl;

    cout << "Ingresa y2: ";
    cin >> y2;
    cout << endl << endl;

    dx = x2 - x1;
    dy = y2 - y1;

    for(int x = x1; x <= x2; x++){
       int y = y1 + dy * (x - x1) / dx;
       cout << "(" << x  << "," << y << ")" << endl;
    }
}
