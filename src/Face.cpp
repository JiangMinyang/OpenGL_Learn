#include "Face.h"

Face::Face(const glm::ivec3 &face) : face(face) {} 
glm::ivec3 Face::getFace() {
	return face;
}