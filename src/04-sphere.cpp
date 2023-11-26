// sphere: (x-cx)^2+(y-cy)^2+(z-cz)^2=r^2
// vector form: (p-c).dot(p-c)=(x-cx)^2+(y-cy)^2+(z-cz)^2=r^2
// note: p(t)=a+t*b
// now it becomes: (a+t*b-c).dot(a+t*b-c)=r^2
// explicitly: t^2*b.dot(b)+2*t*b.dot(a-c)+(a-c).dot(a-c)-r^2=0
// conculsion:
// we can use discriminant (b^2-4ac) to see
// how many intersections between ray and sphere

#include "ray.h"
bool hit_sphere(const vec3& center, double radius, const ray& r) {
    vec3 oc = r.origin() - center;
    double a = dot(r.direction(), r.direction());
    double b = 2. * dot(oc, r.direction());
    double c = dot(oc, oc) - radius * radius;
    double d = b * b - 4 * a * c;
    return d > 0;
}

vec3 ray_color(const ray& r) {
    if (hit_sphere(vec3(0, 0, -1), .5, r)) {
        return vec3(1, 0, 0);
    }
    vec3 unit_d = normalized(r.direction());
    double t = .5 * (unit_d.y() + 1);
    return (1 - t) * vec3(1., 1., 1.) + t * vec3(.5, .7, 1.);
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