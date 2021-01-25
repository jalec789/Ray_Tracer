#include "sphere.h"
#include "ray.h"

using namespace std;

// Determine if the ray intersects with the sphere
//What does part do???
Hit Sphere::Intersection(const Ray& ray, int part) const
{
	//Help from: https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection
    Hit result;
    result.object = NULL;
    
    //a = u.u
    double a = dot(ray.direction, ray.direction);
    //b = 2 * (e-c).u
    double b = 2 * dot(ray.endpoint - center, ray.direction);
    //c = f(x) = (x-c).(x-c)-r^2 = 0
    double c = dot(ray.endpoint - center, ray.endpoint - center) - (radius * radius);
    
    double discriminant = (b * b) - (4 * a * c);
    
    //misses sphere: discriminant < 0
    //single point on sphere: discriminant == 0
    //two points intersect sphere: discriminant > 0
    if(discriminant <= 0) {
    	return result;//return no hit
    }
    else{	//discriminant is > 0
    	double t1 = (-b + sqrt(discriminant)) / (2 * a);
    	double t2 = (-b - sqrt(discriminant)) / (2 * a);
    	
    	// t has to be bigger than small_t to register an intersection with a ray
		if(t2 >= small_t && t1 >= small_t){
			result.object = this;
			//get smallest of the 2
			if(t1 > t2){
				result.dist = t2;
			}
			else {
				result.dist = t1;
			}
		}
		else if(t1 < small_t && t2 >= small_t){
			result.object = this;
			result.dist = t2;
		}
		else if(t2 < small_t && t1 >= small_t){
			result.object = this;
			result.dist = t1;
		}
    }
    return result;
}

vec3 Sphere::Normal(const vec3& point, int part) const
{
    vec3 normal;
    //TODO; // compute the normal direction
    //normal for a sphere = 1 = (point - center) / (point - center).normalized();
    normal = (point - center).normalized();
    return normal;
}

Box Sphere::Bounding_Box(int part) const
{
    Box box;
    TODO; // calculate bounding box
    return box;
}
