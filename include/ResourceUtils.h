#ifndef RESOURCE_UTILS_H
#define RESOURCE_UTILS_H
#include <string>

class ResourceUtils {
public:
  static std::string getResourcePath(const std::string& filename);
private:
  static const std::string RESOURCE_DIRECTORY;
  static std::string getResourceType(const std::string& filename);
};

#endif  //  RESOURCE_UTILS_H