#include "ObjFileLoader.h"
#include <fstream>
#include <sstream>
#include <unordered_map>

#include <iostream>
using namespace std;

int ObjFileLoader::loadFile(const char* filename, std::vector<Vertex> &vertices, std::vector<glm::ivec3> &indices) {
  std::fstream fs;
  fs.open(filename);
  if (!fs.is_open()) {
    return -1;
  }
  std::string line;
  std::unordered_map<std::string, int> vertexMap;
  std::vector<glm::vec3> tempVertex;
  std::vector<glm::vec3> tempNormal;
  std::vector<glm::vec2> tempTexture;
  tempVertex.push_back(glm::vec3(0, 0, 0));
  tempNormal.push_back(glm::vec3(0, 0, 0));
  tempTexture.push_back(glm::vec2(0, 0));
  while (getline(fs, line)) {
    if (line.size() == 0) {
      continue;
    }
    std::stringstream ss;
    std::string type;
    float x, y, z;
    ss.str(line);
    ss >> type;
    if (type == "vt") {
      ss >> x >> y;
      tempTexture.push_back(glm::vec2(x, y));
    }
    if (type == "vn") {
      ss >> x >> y >> z;
      tempNormal.push_back(glm::vec3(x, y, z));
    }
    if (type == "v") {
      ss >> x >> y >> z;
      tempVertex.push_back(glm::vec3(x, y, z));
    }
    if (type == "f") {
      std::string vertexStr;
      int faceIndices[3];
      for(int i = 0; i < 3; i++) {
        ss >> vertexStr;
        if (vertexMap.find(vertexStr) != vertexMap.end()) {
          faceIndices[i] = vertexMap[vertexStr];
        } else {
          int vertexIndex, vertexTextureIndex, vertexNormalIndex;
          vertexMap[vertexStr] = vertices.size();
          faceIndices[i] = vertices.size();
          if (vertexStr.find("/") == std::string::npos) {
            vertices.push_back(Vertex(tempVertex.at(stoi(vertexStr))));
            continue;
          }
          int firstSlash = vertexStr.find("/");
          int lastSlash = vertexStr.rfind("/");
          if (firstSlash + 1 == lastSlash) {
            vertexIndex = stoi(vertexStr.substr(0, firstSlash));
            vertexNormalIndex = stoi(vertexStr.substr(lastSlash + 1, vertexStr.size() - lastSlash - 1));
            vertices.push_back(Vertex(tempVertex.at(vertexIndex), tempNormal.at(vertexNormalIndex)));
            continue;
          }
          if (firstSlash == lastSlash) {
            vertexIndex = stoi(vertexStr.substr(0, firstSlash));
            vertexTextureIndex = stoi(vertexStr.substr(lastSlash + 1, vertexStr.size() - lastSlash - 1));
            vertices.push_back(Vertex(tempVertex.at(vertexIndex), tempTexture.at(vertexTextureIndex)));
            continue;
          }
          vertexIndex = stoi(vertexStr.substr(0, firstSlash));
          vertexTextureIndex = stoi(vertexStr.substr(firstSlash + 1, lastSlash - firstSlash - 1));
          vertexNormalIndex = stoi(vertexStr.substr(lastSlash + 1, vertexStr.size() - lastSlash - 1));
          vertices.push_back(Vertex(tempVertex.at(vertexIndex), tempTexture.at(vertexTextureIndex), tempNormal.at(vertexNormalIndex)));
        }
      }
      indices.push_back(glm::ivec3(faceIndices[0], faceIndices[1], faceIndices[2]));
    }
  }

  fs.close();
  return 0;
}