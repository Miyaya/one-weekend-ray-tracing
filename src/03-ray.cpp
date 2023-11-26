// ray trace
// main concept:
// from pixel cast a ray to the camera -> calculate a color
// main algorithm:
// transform the ray from view port (camera) to pixel position
// calculate if the ray intersects with objects in the scene
// if yes, obtain the color
// notice: [y-axis] up is position;
//         [x-axis] right is position; [z-axis] far is NEGATIVE

#include <iostream>

#include "ray.h"

using namespace std;
/* vertical linear interpolation of blue and white */
vec3 ray_color(const ray& r) {
    vec3 unit_d = normalized(r.direction());
    double t = .5 * (unit_d.y() + 1); /* 0<=y<=1 */
    return (1. - t) * vec3(1., 1., 1.) + t * vec3(.5, .7, 1.);
}

int main() {
    const int w = 200;
    const int h = 100;
    cout << "P3\n" << w << " " << h << "\n255\n";
    vec3 lower_left_corner(-2, -1, -1);
    vec3 horizontal(4, 0, 0);
    vec3 vertical(0, 2, 0);
    vec3 origin(0, 0, 0);
    for (int j = h - 1; j >= 0; j--) {
        // cerr << "\nScanlines remaining: " << j << " " << flush;
        for (int i = 0; i < w; i++) {
            double u = double(i) / w;
            double v = double(j) / h;
            ray r(origin, lower_left_corner + u * horizontal + v * vertical);
            vec3 color = ray_color(r);
            color.write_color(cout);
        }
    }
    cerr << "\nDone\n";
}
