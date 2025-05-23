#ifndef HITTABLE_H
#define HITTABLE_H

#include "aabb.h"
#include <memory>

class material;

class hit_record {
public:
    point3 p;
    vec3 normal;
    std::shared_ptr<material> mat;
    double t;
    double u;
    double v;
    bool front_face;

    void set_face_normal(const ray& r, const vec3& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable {
public:
    virtual ~hittable() = default;

    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;

    virtual aabb bounding_box() const = 0;

    virtual double pdf_value(const point3& origin, const vec3& direction) const {
        return 0.0;
    }

    virtual vec3 random(const point3& origin) const {
        return vec3(1, 0, 0);
    }
};

class translate : public hittable {
public:
    translate(std::shared_ptr<hittable> object, const vec3& offset)
        : object(object), offset(offset) {
        bbox = object->bounding_box() + offset;
    }

    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        ray offset_r(r.origin() - offset, r.direction(), r.time());

        if (!object->hit(offset_r, ray_t, rec))
            return false;

        rec.p += offset;
        rec.set_face_normal(offset_r, rec.normal);

        return true;
    }

    aabb bounding_box() const override { return bbox; }

private:
    std::shared_ptr<hittable> object;
    vec3 offset;
    aabb bbox;
};

class rotate_y : public hittable {
public:
    rotate_y(std::shared_ptr<hittable> object, double angle)
        : object(object) {
        auto radians = degrees_to_radians(angle);
        sin_theta = std::sin(radians);
        cos_theta = std::cos(radians);
        bbox = object->bounding_box();

        point3 min(infinity, infinity, infinity);
        point3 max(-infinity, -infinity, -infinity);

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    auto x = i * bbox.x.max + (1 - i) * bbox.x.min;
                    auto y = j * bbox.y.max + (1 - j) * bbox.y.min;
                    auto z = k * bbox.z.max + (1 - k) * bbox.z.min;

                    auto newx = cos_theta * x + sin_theta * z;
                    auto newz = -sin_theta * x + cos_theta * z;

                    vec3 tester(newx, y, newz);

                    for (int c = 0; c < 3; c++) {
                        min[c] = std::fmin(min[c], tester[c]);
                        max[c] = std::fmax(max[c], tester[c]);
                    }
                }
            }
        }

        bbox = aabb(min, max);
    }

    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        auto origin = r.origin();
        auto direction = r.direction();

        point3 rotated_origin(
            cos_theta * origin.x() - sin_theta * origin.z(),
            origin.y(),
            sin_theta * origin.x() + cos_theta * origin.z()
        );

        vec3 rotated_direction(
            cos_theta * direction.x() - sin_theta * direction.z(),
            direction.y(),
            sin_theta * direction.x() + cos_theta * direction.z()
        );

        ray rotated_r(rotated_origin, rotated_direction, r.time());

        if (!object->hit(rotated_r, ray_t, rec))
            return false;

        auto p = rec.p;
        auto normal = rec.normal;

        rec.p = point3(
            cos_theta * p.x() + sin_theta * p.z(),
            p.y(),
            -sin_theta * p.x() + cos_theta * p.z()
        );

        rec.normal = vec3(
            cos_theta * normal.x() + sin_theta * normal.z(),
            normal.y(),
            -sin_theta * normal.x() + cos_theta * normal.z()
        );

        rec.set_face_normal(rotated_r, rec.normal);

        return true;
    }

    aabb bounding_box() const override { return bbox; }

private:
    std::shared_ptr<hittable> object;
    double sin_theta;
    double cos_theta;
    aabb bbox;
};

#endif
