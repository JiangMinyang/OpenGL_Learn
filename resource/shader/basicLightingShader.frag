#version 330
in vec3 normalVec;
in vec3 lightVec;
in vec3 viewVec;

out vec4 FragColor;

void main() {
  float diffuse = max(dot(normalize(normalVec), normalize(lightVec)), 0.0);
  float specular = pow(max(dot(normalize(viewVec), normalize(reflect(-lightVec, normalVec))), 0.0), 16);
  FragColor = (diffuse + specular) * vec4(1.0, 0.0, 0.0, 1.0);
}