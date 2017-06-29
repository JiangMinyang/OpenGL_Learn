#version 330
in vec3 normalVec;
in vec3 lightVec;

out vec4 FragColor;

void main() {
  float diffuse = max(dot(normalize(normalVec), normalize(lightVec)), 0.0);
  FragColor = vec4(diffuse, diffuse, diffuse, 0.5);
}