﻿#version 410 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
//layout (location = 2) in vec2 aTexCoords;

//out vec2 TexCoords;
out vec3 FragPos;
out vec3 Normal;
out VS_OUT {
    vec3 normal;
} vs_out;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 mv;

void main()
{
    FragPos = vec3(model * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(model))) * aNormal;

    // gl_Position = projection * view * vec4(FragPos, 1.0);
    gl_Position = projection * mv * vec4(aPos, 1.0f);
    vs_out.normal = normalize(Normal);
}
