#include "ResourceUtils.h"
#include <set>

const std::string ResourceUtils::RESOURCE_DIRECTORY = std::string(RESOURCE_PATH);

std::string ResourceUtils::getResourcePath(const std::string& filename) {
  std::string resultPath = RESOURCE_DIRECTORY + getResourceType(filename) + "/" + filename;
  return resultPath;
}

std::string ResourceUtils::getResourceType(const std::string& filename) {
  int lastDot = filename.rfind(".");
  std::string extension = filename.substr(filename.rfind(".") + 1, filename.size() - lastDot);
  std::string folder = "";
  std::set<std::string> imageExtension;
  std::set<std::string> shaderExtension;
  std::set<std::string> objectExtension;
  imageExtension.insert("jpg");
  imageExtension.insert("png");
  imageExtension.insert("jpeg");
  shaderExtension.insert("vert");
  shaderExtension.insert("frag");
  objectExtension.insert("obj");
  objectExtension.insert("mtl");
  if (imageExtension.find(extension) != imageExtension.end()) {
    folder = "/image";
  } else if (shaderExtension.find(extension) != shaderExtension.end()) {
    folder = "/shader";
  } else if (objectExtension.find(extension) != objectExtension.end()) {
    folder = "/objs";
  }
  return folder;
}