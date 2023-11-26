#include <iostream>

using namespace std;
class vec3 {
   public:
    vec3() {
        e[0] = 0;
        e[1] = 0;
        e[2] = 0;
    }
    vec3(double e0, double e1, double e2) {
        e[0] = e0;
        e[1] = e1;
        e[2] = e2;
    }

    /* read only */
    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    double length_squared() const {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }
    double length() const { return sqrt(length_squared()); }

    /* io */
    void write_color(ostream &out) {
        out << static_cast<int>(255.999 * e[0]) << " "
            << static_cast<int>(255.999 * e[1]) << " "
            << static_cast<int>(255.999 * e[2]) << "\n";
    }

    /* arithmetic */
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
    double operator[](int i) const { return e[i]; }
    double &operator[](int i) { return e[i]; }

    vec3 &operator+=(const vec3 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }
    vec3 &operator*=(const double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }
    vec3 &operator/=(const double t) { return *this *= 1 / t; }

   private:
    double e[3];
};

inline ostream &operator<<(ostream &out, const vec3 &v) {
    return out << v.x() << " " << v.y() << " " << v.z();
}
inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}
inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}
inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}
inline vec3 operator*(const vec3 &u, double t) {
    return vec3(u.x() * t, u.y() * t, u.z() * t);
}
inline vec3 operator*(double t, const vec3 &u) { return u * t; }
inline vec3 operator/(vec3 u, double t) { return u * (1 / t); }
/* vector operators */
inline double dot(const vec3 &u, const vec3 &v) {
    return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}
inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.y() * v.z() - u.z() * v.y(), u.z() * v.x() - u.x() * v.z(),
                u.x() * v.y() - u.y() * v.x());
}
inline vec3 normalized(vec3 v) { return v / v.length(); }