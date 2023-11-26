#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
   public:
    ray() {}
    ray(const vec3& origin, const vec3& direction) : o(origin), d(direction) {}

    vec3 origin() const { return o; }
    vec3 direction() const { return d; }

    vec3 at(double t) const { return o + t * d; }

   private:
    vec3 o;
    vec3 d;
};

#endif