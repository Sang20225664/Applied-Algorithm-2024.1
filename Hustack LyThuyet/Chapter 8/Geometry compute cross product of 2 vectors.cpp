#include <iostream>
using namespace std;

int main() {

    int xO, yO, xA, yA, xB, yB;
    cin >> xO >> yO >> xA >> yA >> xB >> yB;

    int crossProduct = (xA - xO) * (yB - yO) - (yA - yO) * (xB - xO);

    cout << crossProduct << endl;

    return 0;
}
