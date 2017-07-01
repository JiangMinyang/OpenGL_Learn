#version 330
layout (location = 0) in vec3 position;
layout (location = 2) in vec3 normal;

uniform vec3 lightSource;
uniform vec3 viewPosition;
uniform mat4 transform;
uniform mat4 rotation;
uniform mat4 model;

out vec3 normalVec;
out vec3 lightVec;
out vec3 viewVec;

void main() {
  normalVec = (rotation * vec4(normal, 0.0)).xyz;
  lightVec = lightSource;
  viewVec = viewPosition - position;
  gl_Position = model * transform * vec4(position, 1.0);
}