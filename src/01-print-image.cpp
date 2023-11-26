#include <iostream>

using namespace std;
int main() {
    const int w = 200;
    const int h = 100;
    cout << "P3\n" << w << " " << h << "\n255\n";

    for (int j = h - 1; j >= 0; j--) { /* from top to bottom */
        cerr << "\rScanlines remainging: " << j << " " << flush;
        for (int i = 0; i < w; i++) { /* from left to right */
            /* range: [0, 1] */
            double r = double(i) / w;
            double g = double(j) / h;
            double b = .2;

            /* range: [0, 255] */
            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);
            cout << ir << " " << ig << " " << ib << "\n";
        }
    }
    cerr << "\nDone\n";
}