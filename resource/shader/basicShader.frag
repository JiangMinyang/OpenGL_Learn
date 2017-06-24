#version 330
in vec2 textureCoord;
out vec4 FragColor;
uniform sampler2D texture1;
uniform sampler2D texture2;

void main() {
  // FragColor = vec4(0.0f, 0.9f, 0.1f, 1.0);
  FragColor = mix(texture(texture1, textureCoord), texture(texture2, textureCoord), 0.2);
  // FragColor = texture(texture1, textureCoord);
}