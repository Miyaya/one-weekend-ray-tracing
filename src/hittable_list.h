#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include <memory>
#include <vector>

#include "hittable.h"

using namespace std;

class hittable_list : public hittable {
   public:
    hittable_list() {}
    hittable_list(shared_ptr<hittable> object) { add(object); }

    void clear() { objects.clear(); }
    void add(shared_ptr<hittable> object) { objects.push_back(object); }

    virtual bool hit(const ray& r, double t_min, double t_max,
                     hit_record& rec) const {
        hit_record tmp_rec;
        bool hit_anything = false;
        double closest = t_max;
        for (const auto& obj : objects) {
            if (obj->hit(r, t_min, closest, tmp_rec)) {
                hit_anything = true;
                closest = tmp_rec.t;
                rec = tmp_rec;
            }
        }
        return hit_anything;
    }

   private:
    vector<shared_ptr<hittable>> objects;
};

#endif