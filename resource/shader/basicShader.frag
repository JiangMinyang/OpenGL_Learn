#version 330
// in vec2 textureCoord;
in vec3 pos;
out vec4 FragColor;
// uniform sampler2D texture1;
// uniform sampler2D texture2;

void main() {
  FragColor = vec4(pos, 1.0);
  // FragColor = mix(texture(texture1, textureCoord), texture(texture2, textureCoord), 0.2);
  // FragColor = texture(texture1, textureCoord);
}