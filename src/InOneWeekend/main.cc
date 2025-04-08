#include "rtweekend.h"
#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "material.h"
#include "quad.h"
#include "aabb.h"

int main() {
    hittable_list world;

    auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5));
    shared_ptr<hittable> ground_box = box(point3(-30, -0.01, -30), point3(30, 0, 30), ground_material);
    world.add(ground_box);

    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            auto choose_mat = random_double();
            point3 center(a + 0.9 * random_double(), 0.0, b + 0.9 * random_double());

            if ((center - point3(4, 0.2, 0)).length() > 0.9) {
                shared_ptr<material> mat;

                if (choose_mat < 0.8) {
                    // diffuse
                    auto albedo = color::random() * color::random();
                    mat = make_shared<lambertian>(albedo);
                } else if (choose_mat < 0.95) {
                    // metal
                    auto albedo = color::random(0.5, 1.0);
                    auto fuzz = random_double(0, 0.5);
                    mat = make_shared<metal>(albedo, fuzz);
                } else {
                    // glass
                    mat = make_shared<dielectric>(1.5);
                }

                shared_ptr<hittable> random_box = box(point3(-0.2, 0.0, -0.2), point3(0.2, 0.4, 0.2), mat);
                random_box = make_shared<rotate_y>(random_box, 45);
                random_box = make_shared<translate>(random_box, center);

                world.add(random_box);
            }
        }
    }

    auto material1 = make_shared<dielectric>(1.5);
    shared_ptr<hittable> box1 = box(point3(-0.6, 0.0, -0.6), point3(0.75, 1.5, 0.75), material1);
    box1 = make_shared<rotate_y>(box1, -45);
    box1 = make_shared<translate>(box1, vec3(0, 0, 0));
    world.add(box1);
    
    auto material2 = make_shared<lambertian>(color(0.4, 0.2, 0.1));
    shared_ptr<hittable> box2 = box(point3(-0.6, 0.0, -0.6), point3(0.75, 1.5, 0.75), material2);
    box2 = make_shared<rotate_y>(box2, -45);
    box2 = make_shared<translate>(box2, vec3(-4, 0, 0));
    world.add(box2);
    
    auto material3 = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
    shared_ptr<hittable> box3 = box(point3(-0.6, 0.0, -0.6), point3(0.75, 1.5, 0.75), material3);
    box3 = make_shared<rotate_y>(box3, -45);
    box3 = make_shared<translate>(box3, vec3(4, 0, 0));
    world.add(box3);
    
    

    camera cam;

    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 1200;
    cam.samples_per_pixel = 10;
    cam.max_depth         = 20;

    cam.vfov     = 20;
    cam.lookfrom = point3(13, 2, 3);
    cam.lookat   = point3(0, 0, 0);
    cam.vup      = vec3(0, 1, 0);

    cam.defocus_angle = 0.6;
    cam.focus_dist    = 10.0;

    cam.render(world);
}
