#include "plane.h"
#include "ray.h"
#include <cfloat>
#include <limits>

// Intersect with the half space defined by the plane.  The plane's normal
// points outside.  If the ray starts on the "inside" side of the plane, be sure
// to record a hit with t=0 as the first entry in hits.
Hit Plane::Intersection(const Ray& ray, int part) const
{
    //TODO;
    double denom = dot(ray.direction, normal);
    Hit result;
    result.object = NULL;
    //Ray defined by point e and direction u
    vec3 u = ray.direction;
    vec3 e = ray.endpoint;
    //plane defined by point: x1 
    //	and the normal: normal
    //	defined in Plane object already
    if(denom != 0){
    	double t = dot(x1 - e, normal) / dot(u, normal);
    	// t has to be bigger than small_t to register an intersection with a ray
    	if(t > small_t){
    		result.object = this;
    		result.dist = t;
    	}
    }
    return result;//returns Null if no hit?
}

vec3 Plane::Normal(const vec3& point, int part) const
{
    //Already created in object.h vec3 Normal(vec3, int) and called in the constructor
    return normal;
}

// There is not a good answer for the bounding box of an infinite object.
// The safe thing to do is to return a box that contains everything.
Box Plane::Bounding_Box(int part) const
{
    Box b;
    b.hi.fill(std::numeric_limits<double>::max());
    b.lo=-b.hi;
    return b;
}
