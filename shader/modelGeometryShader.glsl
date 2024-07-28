#version 410 core

layout (triangles) in;
layout (triangle_strip, max_vertices = 6) out;

uniform bool u_explodeMode;

vec3 getNormal()
{
    vec3 a = vec3(gl_in[0].gl_Position) - vec3(gl_in[1].gl_Position);
    vec3 b = vec3(gl_in[2].gl_Position) - vec3(gl_in[1].gl_Position);
    return normalize(cross(a, b));
}

vec4 explode(vec4 position, vec3 normal)
{
    float magnitude = 0.3;
    vec3 direction = normal * magnitude;
    return position + vec4(direction, 0.0);
}

void main()
{
    if (u_explodeMode) {
        vec3 normal = getNormal();

        gl_Position = explode(gl_in[0].gl_Position, normal);
        EmitVertex();
        gl_Position = explode(gl_in[1].gl_Position, normal);
        EmitVertex();
        gl_Position = explode(gl_in[2].gl_Position, normal);
        EmitVertex();
        EndPrimitive();
    } else {
        gl_Position = gl_in[0].gl_Position;
        EmitVertex();
        gl_Position = gl_in[1].gl_Position;
        EmitVertex();
        gl_Position = gl_in[2].gl_Position;
        EmitVertex();
        EndPrimitive();
    }
}
