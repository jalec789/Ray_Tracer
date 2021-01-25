#include "light.h"
#include "phong_shader.h"
#include "ray.h"
#include "render_world.h"
#include "object.h"

vec3 Phong_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& normal,int recursion_depth) const
{
    vec3 color;
    //TODO; //determine the color
    //need to calculate color for all lights in the world and a recusion count
    color = world.ambient_color * world.ambient_intensity * color_ambient;
    
    //I = I_amb + I_diff + I_spec
    //= R_a * L_a + R_d * L_d * max(n.1, 0) + R_s * L_s * max(cos(phi), 0) ^ alpha
    
    //Add phong shading diffuse only and point lights
    //diffuse component only for now
    vec3 diffuse_component;
    
    int n = world.lights.size();
    for(int i = 0; i < n; i++){
    	Light* light = world.lights[i];
    	
    	vec3 light_intersection = light->position - intersection_point;
    	vec3 R_d = color_diffuse;
    	// this should be the light color / intersection
    	vec3 L_d = light->Emitted_Light(ray.direction) / light_intersection.magnitude_squared();
    	//Avoid Bug diffuse = L*R*max(n.1,0)
    	diffuse_component = L_d * R_d * std::max(0.0, dot(normal, light_intersection.normalized()));
    }
    
    return color + diffuse_component;
}
