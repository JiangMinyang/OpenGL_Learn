#version 330
in vec3 vertexColor;
out vec4 FragColor;
uniform float green;
void main() {
  FragColor = vec4(0.0, green, 0.0, 1.0);
}