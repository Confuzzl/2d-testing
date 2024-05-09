module;

#include "gl_wrapper/shaders/uniform.h"

export module shaders:geometry;

import glm;

export namespace shaders {
namespace geom {
struct line {
  uniform<float> thickness;

  void createUniforms(const GLuint ID) { CREATE_UNIFORM(thickness); }
};
} // namespace geom
} // namespace shaders