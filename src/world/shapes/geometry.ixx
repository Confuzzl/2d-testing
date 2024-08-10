export module world.geometry;

import glm;
import poly;

import <vector>;
import <stdexcept>;

export namespace geometry {
struct Shape {
protected:
  glm::vec2 position;
  float rotation;

public:
  Shape(const glm::vec2 position = {}, const float rotation = 0)
      : position{position}, rotation{rotation} {};

  glm::vec2 getPos() const { return position; }
  void translate(const glm::vec2 v) { position += v; }
  void setPos(const glm::vec2 v) { position = v; }
  float getRotation() const { return rotation; }
  void rotate(const float r) { rotation += r; }
  void setRot(const float r) { rotation = r; }
};

struct Circle : Shape {
private:
  float radius = 1;

public:
  Circle(Shape &&shape, const float radius)
      : Shape(std::move(shape)), radius{radius} {}

  float getRadius() const { return radius; }
};

struct Polygon : Shape {
private:
  std::vector<glm::vec2> vertices;

  static bool isCCW(const std::vector<glm::vec2> &vertices) {
    // https://stackoverflow.com/questions/1165647/how-to-determine-if-a-list-of-polygon-points-are-in-clockwise-order

    const auto size = vertices.size();
    auto sum = 0u;
    for (auto i = 0; i < size; i++) {
      const glm::vec2 e = vertices[(i + 1) % size] - vertices[i];
      sum += e.x * e.y;
    }
    return sum < 0;
  }

protected:
  Polygon(Shape &&shape, std::vector<glm::vec2> &&vertices)
      : Shape(std::move(shape)), vertices{std::move(vertices)} {}

public:
  const auto &getVertices() const { return vertices; }

  static Polygon from(Shape &&shape, std::vector<glm::vec2> &&vertices) {
    if (vertices.size() < 3)
      throw std::runtime_error{"POLYGON MUST HAVE MORE THAN 3 VERTICES"};
    if (!isCCW(vertices))
      throw std::runtime_error{"POLYGON MUST HAVE COUNTER CLOCKWISE VERTICES"};
    return fromUnchecked(std::move(shape), std::move(vertices));
  }
  static Polygon fromUnchecked(Shape &&shape,
                               std::vector<glm::vec2> &&vertices) {
    return {std::move(shape), std::move(vertices)};
  }
};
} // namespace geometry