#include <iostream>

#include "vec3.h"

using namespace std;
int main() {
    const int w = 200;
    const int h = 100;
    cout << "P3\n" << w << " " << h << "\n255\n";

    for (int j = h - 1; j >= 0; j--) { /* from top to bottom */
        cerr << "\rScanlines remainging: " << j << " " << flush;
        for (int i = 0; i < w; i++) { /* from left to right */
            vec3 color(double(i) / w, double(j) / h, .2);
            color.write_color(cout);
        }
    }
    cerr << "\nDone\n";
}