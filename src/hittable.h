#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

typedef struct {
    vec3 p;          /* hit point */
    vec3 n;          /* normal */
    double t;        /* parameter of hit point function a+b*t */
    bool front_face; /* if ray is outside the hittable object */

    inline void set_face_normal(const ray& r, const vec3& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        n = front_face ? outward_normal : -outward_normal;
    }
} hit_record;

class hittable {
   public:
    /* pure virtual function */
    virtual bool hit(const ray& r, double t_min, double t_max,
                     hit_record& rec) const = 0;
};

#endif