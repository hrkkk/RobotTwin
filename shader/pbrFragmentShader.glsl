uniform sampler2D s_albedoTexture;       // 基本颜色贴图
uniform sampler2D s_metallicTexture;        // 金属度贴图
uniform sampler2D s_roughnessTexture;         // 粗糙度贴图
uniform sampler2D s_normalTexture;   // 法线贴图
uniform sampler2D s_aoTexture;       // 环境光遮蔽贴图

in vec2 textureCoord;
in vec3 fragPos;
in vec3 normalVec;

// struct Light {
//     vec3 lightPos;
//     vec3 lightColor;
// };
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

// uniform Light u_light;
// uniform vec3 u_cameraPos;

const float PI = 3.14159265359;

float DistributionGGX(vec3 N, vec3 H, float roughness)
{
    float a      = roughness*roughness;
    float a2     = a*a;
    float NdotH  = max(dot(N, H), 0.0);
    float NdotH2 = NdotH*NdotH;

    float num   = a2;
    float denom = (NdotH2 * (a2 - 1.0) + 1.0);
    denom = PI * denom * denom;

    return num / denom;
}

float GeometrySchlickGGX(float NdotV, float roughness)
{
    float r = (roughness + 1.0);
    float k = (r*r) / 8.0;

    float num   = NdotV;
    float denom = NdotV * (1.0 - k) + k;

    return num / denom;
}
float GeometrySmith(vec3 N, vec3 V, vec3 L, float roughness)
{
    float NdotV = max(dot(N, V), 0.0);
    float NdotL = max(dot(N, L), 0.0);
    float ggx2  = GeometrySchlickGGX(NdotV, roughness);
    float ggx1  = GeometrySchlickGGX(NdotL, roughness);

    return ggx1 * ggx2;
}

vec3 fresnelSchlick(float cosTheta, vec3 F0)
{
    return F0 + (1.0 - F0) * pow(clamp(1.0 - cosTheta, 0.0, 1.0), 5.0);
}

void main(void)
{
    vec3 N = normalize(normalVec);
    vec3 V = normalize(viewPos - fragPos);
    vec3 L = normalize(lightPos - fragPos);
    vec3 H = normalize(V + L);

    // float albedo = pow(texture2D(s_albedoTexture, textureCoord).r, 2.2);
    // float metallic = texture2D(s_metallicTexture, textureCoord).r;
    // float roughness = texture2D(s_roughnessTexture, textureCoord).r;
    // float ao = pow(texture2D(s_aoTexture, textureCoord).r, 2.2);
    vec3 albedo = objectColor;
    float metallic = 1.0;
    float roughness = 0.111;
    vec3 ao = vec3(1.0);

    // 计算基础颜色
    vec3 F0 = vec3(0.04);
    F0 = mix(F0, albedo, metallic);

    // 计算漫反射 + 镜面反射
    vec3 Lo = vec3(0.0);
    float distance = length(lightPos - fragPos);
    float attenuation = 1.0 / (distance * distance);
    vec3 radiance = lightPos * attenuation;

    // Cook-Torrance BRDF方程
    float NDF = DistributionGGX(N, H, roughness);
    float G = GeometrySmith(N, V, L, roughness);
    vec3 F = fresnelSchlick(max(dot(H, V), 0.0), F0);

    vec3 Ks = F;
    vec3 Kd = vec3(1.0) - Ks;
    Kd *= 1.0 - metallic;

    vec3 nominator = NDF * G * F;
    float denominator = 4.0 * max(dot(N, V), 0.0) * max(dot(N, L), 0.0) + 0.001;
    vec3 specular = nominator / denominator;

    float NdotL = max(dot(N, L), 0.0);      // 计算法线与入射光线之间的夹角余弦值，如果小于0，则代表光线与法线夹角超过90°，则光照不起作用
    Lo += (Kd * albedo / PI + specular) * radiance * NdotL;

    // 计算环境光反射
    vec3 ambient = vec3(0.03) * albedo * ao;
    vec3 color = ambient + Lo;

    // 色调映射
    color = color / (color + vec3(1.0));

    // gamma校正
    color = pow(color, vec3(1.0 / 2.2));

    gl_FragColor = vec4(color, 1.0);
}
