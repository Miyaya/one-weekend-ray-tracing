#include "ray.h"

// for t=a+b*t:
// t^2*b.dot(b)+2*t*b.dot(a-c)+(a-c).dot(a-c)-r^2=0
// we also need to know the intersect point to calculate normal
double hit_sphere(const vec3& center, double radius, const ray& r) {
    vec3 oc = r.origin() - center;
    double a = dot(r.direction(), r.direction());
    double b = 2 * dot(r.direction(), oc);
    double c = dot(oc, oc) - radius * radius;
    double d = b * b - 4 * a * c;
    if (d < 0) return -1;
    return (-b - sqrt(d)) / (2 * a); /* smaller root: nearest intersect */
}

vec3 ray_color(const ray& r) {
    vec3 c(0, 0, -1);
    double t = hit_sphere(c, .5, r);
    if (t > 0.) {
        vec3 n = normalized(r.at(t) - c);                  /* range: [-1, 1] */
        return .5 * vec3(n.x() + 1, n.y() + 1, n.z() + 1); /* range: [0, 1] */
    }
    vec3 unit_d = normalized(r.direction());
    t = .5 * (unit_d.y() + 1);
    return (1 - t) * vec3(1, 1, 1) + t * vec3(.5, .7, 1.);
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