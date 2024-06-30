#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;

uniform vec3 lightPos;
uniform vec3 lightPos1;
uniform vec3 lightPos2;
uniform vec3 lightPos3;
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

void main()
{
    vec3 res;
    {
        // 环境光
        float ambientStrength = 0.5;
        vec3 ambient = ambientStrength * lightColor;

        // 漫反射光
        vec3 norm = normalize(Normal);
        vec3 lightDir = normalize(lightPos - FragPos);
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = diff * lightColor;

        // 镜面反射光
        float specularStrength = 0.5;
        vec3 viewDir = normalize(viewPos - FragPos);
        vec3 reflectDir = reflect(-lightDir, norm);
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
        vec3 specular = specularStrength * spec * lightColor;

        vec3 result = (ambient + diffuse + specular) * objectColor;
        res += result;
    }

    // {
    //     // 环境光
    //     float ambientStrength = 0.1;
    //     vec3 ambient = ambientStrength * lightColor;

    //     // 漫反射光
    //     vec3 norm = normalize(Normal);
    //     vec3 lightDir = normalize(lightPos1 - FragPos);
    //     float diff = max(dot(norm, lightDir), 0.0);
    //     vec3 diffuse = diff * lightColor;

    //     // 镜面反射光
    //     float specularStrength = 0.5;
    //     vec3 viewDir = normalize(viewPos - FragPos);
    //     vec3 reflectDir = reflect(-lightDir, norm);
    //     float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    //     vec3 specular = specularStrength * spec * lightColor;

    //     vec3 result = (ambient + diffuse + specular) * objectColor;
    //             res += result;
    // }

    // {
    //     // 环境光
    //     float ambientStrength = 0.1;
    //     vec3 ambient = ambientStrength * lightColor;

    //     // 漫反射光
    //     vec3 norm = normalize(Normal);
    //     vec3 lightDir = normalize(lightPos2 - FragPos);
    //     float diff = max(dot(norm, lightDir), 0.0);
    //     vec3 diffuse = diff * lightColor;

    //     // 镜面反射光
    //     float specularStrength = 0.5;
    //     vec3 viewDir = normalize(viewPos - FragPos);
    //     vec3 reflectDir = reflect(-lightDir, norm);
    //     float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    //     vec3 specular = specularStrength * spec * lightColor;

    //     vec3 result = (ambient + diffuse + specular) * objectColor;
    //             res += result;
    // }

    // {
    //     // 环境光
    //     float ambientStrength = 0.1;
    //     vec3 ambient = ambientStrength * lightColor;

    //     // 漫反射光
    //     vec3 norm = normalize(Normal);
    //     vec3 lightDir = normalize(lightPos3 - FragPos);
    //     float diff = max(dot(norm, lightDir), 0.0);
    //     vec3 diffuse = diff * lightColor;

    //     // 镜面反射光
    //     float specularStrength = 0.5;
    //     vec3 viewDir = normalize(viewPos - FragPos);
    //     vec3 reflectDir = reflect(-lightDir, norm);
    //     float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    //     vec3 specular = specularStrength * spec * lightColor;

    //     vec3 result = (ambient + diffuse + specular) * objectColor;
    //             res += result;
    // }





    FragColor = vec4(res, 1.0);
}
