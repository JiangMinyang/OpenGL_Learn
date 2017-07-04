#version 330
in vec3 normalVec;
in vec3 lightVec;
in vec3 viewVec;

out vec4 FragColor;

void main() {
  vec3 ambientFactor = vec3(0.24725, 0.1995, 0.0745);
  vec3 diffuseFactor = vec3(0.75164, 0.60648, 0.22648);
  vec3 specularFactor = vec3(0.628281, 0.555802, 0.366065);
  float shininess = 0.4;
  float diffuse = max(dot(normalize(normalVec), normalize(lightVec)), 0.0);
  float specular = pow(max(dot(normalize(viewVec), normalize(reflect(-lightVec, normalVec))), 0.0), shininess * 128);
  FragColor = vec4((ambientFactor + diffuse * diffuseFactor + specular * specularFactor), 1.0) * vec4(1.0, 1.0, 1.0, 1.0);
}