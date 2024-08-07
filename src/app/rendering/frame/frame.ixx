module;

#include "util/gl.h"

export module frame;

import glm;
import color;
import dimensions;

// import buffer_object;

import vertex_layout;
import mesh;

import <format>;

export struct BaseFrame {
  glm::mat4 matrix{1.0f};

  virtual void render() = 0;

  void drawPoint(const glm::vec2 &point, const float size = 10,
                 const color_t &color = colors::WHITE) const;
  void drawPointFixed(const glm::vec2 &point, const float size = 10,
                      const color_t &color = colors::WHITE) const;

  void drawLine(const dimension_t &dimensions, const float size = 0.1,
                const color_t &color = colors::WHITE) const;
  void drawLineFixed(const dimension_t &dimensions,
                     const color_t &color = colors::WHITE) const;

  void drawArrow(const dimension_t &dimensions,
                 const color_t &color = colors::WHITE) const;

  void drawCircle(const glm::vec2 &center, const float radius,
                  const color_t &color = colors::WHITE) const;

  void drawBox(const dimension_t &dimensions, const float lineSize = 5,
               const color_t &color = colors::WHITE) const;
  void drawBoxFixed(const dimension_t &dimensions, const float lineSize = 5,
                    const color_t &color = colors::WHITE) const;
  void drawQuad(const dimension_t &dimensions,
                const color_t &color = colors::WHITE) const;

  void drawMesh(const Mesh &mesh, const glm::vec2 &pos = {},
                const float rot = 0) const;
};