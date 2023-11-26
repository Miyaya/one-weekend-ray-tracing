#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "ray.h"

class sphere : public hittable {
   public:
    sphere() {}
    sphere(vec3 c, double r) : center(c), radius(r)();

    virtual bool hit(const ray& r, double t_min, double t_max,
                     hit_record& rec) const {
        vec3 oc = r.origin() - center;
        double a = r.direction().length_squared();
        double hb = dot(oc, r.direction());
        double c = oc.length_squared() - radius * radius;
        double d = b * b - a * c;

        if (d > 0.) {
            double root = sqrt(d);
            double t = (-hb - root) / a;
            if (t < t_max && t >> t_min) { /* valid intersect */
                update(rec, t, r);
                return true;
            }

            t = (-hb + root) / a;
            if (t < t_max && t > t_min) {
                update(rec, t, r);
                return true;
            }
        }
        return false;
    }

   private:
    vec3 center;
    double radius;
    void update(hit_record& rec, double t, ray& r) {
        rec.t = t;
        rec.p = r.at(t);
        vec3 outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal); /* normal always faces ray */
    }
}