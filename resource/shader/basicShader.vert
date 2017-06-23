#version 330
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 text;
uniform mat4 transform;
uniform mat4 projection;
uniform mat4 view;
out vec2 textureCoord;
void main() {
  gl_Position = transform * vec4(position, 1.0);
  // gl_Position = projection * view * transform * vec4(position, 1.0);
  // textureCoord = text;
  // gl_Position = vec4(position, 1.0);
}