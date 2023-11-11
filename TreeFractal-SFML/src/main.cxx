#include <algorithm>
#include <array>

#ifdef _WIN32
#define _USE_MATH_DEFINES
#include <math.h>
#else
#include <cmath>
#endif

#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>

constexpr auto tau = static_cast<float>(M_PI) * 2.f;

struct TreeSegment {
    sf::Vector2f start;
    sf::Vector2f end;
    float length;
    float angle;
    unsigned int depth;

    TreeSegment() = delete;
};

void drawTrees(sf::RenderWindow& window, std::stack<TreeSegment>& segments) {
    constexpr auto branchLengthRatio = .6f;
    constexpr auto maxDepth = 8u;
    constexpr auto deltaAngle = tau / 6.f;
    const auto& color1 = sf::Color{ 0xffaa00ffu };
    const auto& color2 = sf::Color::Green;

    while (!segments.empty()) {
        const auto& currentSegment = segments.top();
        segments.pop();

        const auto& startColor = currentSegment.depth < 5u ? color1 : color2;
        const auto& endColor = startColor;
        const auto line = std::array<sf::Vertex, 2u>{
            sf::Vertex{ currentSegment.start, startColor },
                sf::Vertex{ currentSegment.end, endColor }
        };

        window.draw(line.data(), 2u, sf::PrimitiveType::Lines);

        if (currentSegment.depth < maxDepth) {
            const auto newStart = currentSegment.end;
            const auto newLength = currentSegment.length * branchLengthRatio;
            const auto rightAngle = currentSegment.angle - deltaAngle;
            const auto leftAngle = currentSegment.angle + deltaAngle;
            const auto rightNewEnd = currentSegment.end + sf::Vector2f{ std::cos(rightAngle) * newLength, std::sin(rightAngle) * newLength };
            const auto leftNewEnd = currentSegment.end + sf::Vector2f{ std::cos(leftAngle) * newLength, std::sin(leftAngle) * newLength };
            const auto newDepth = currentSegment.depth + 1u;

            segments.push({ newStart, rightNewEnd, newLength, rightAngle, newDepth });
            segments.push({ newStart, leftNewEnd, newLength, leftAngle, newDepth });
        }
    }
}

void redraw(sf::RenderWindow& window, const float windowWidth, const float windowHeight) {
    window.clear(sf::Color::Black);

    const auto trunkStart = sf::Vector2f{ windowWidth / 2.f, windowHeight / 2.f };
    constexpr auto numTrees = 3u;
    auto initialLength = std::min(windowWidth, windowHeight) / 6.f;
    constexpr auto trunkDeltaAngle = tau / numTrees;
    std::stack<TreeSegment> segments;
    for (auto t = 0u; t < numTrees; t++) {
        const auto angle = -tau / 4.f + trunkDeltaAngle * t;
        const auto trunkEnd = trunkStart + sf::Vector2f{
          std::cos(angle) * initialLength,
          std::sin(angle) * initialLength
        };
        segments.push({
          trunkStart,
          trunkEnd,
          initialLength,
          angle,
          0u
        });
    }
    drawTrees(window, segments);

    window.display();
}

int main() {
    constexpr auto windowWidth = 600u;
    constexpr auto windowHeight = 600u;
    const auto windowMode = sf::VideoMode{ windowWidth, windowHeight };
    constexpr auto windowTitle = "Tree Fractal";

    auto&& window = sf::RenderWindow{ windowMode, windowTitle };
    auto view = window.getDefaultView();

    redraw(window, windowWidth, windowHeight);
    while (window.isOpen()) {
        auto event = sf::Event();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::Resized) {
                const auto width = static_cast<float>(event.size.width);
                const auto height = static_cast<float>(event.size.height);
                view.setSize(width, height);
                view.setCenter(width / 2.f, height / 2.f);
                window.setView(view);
                redraw(window, width, height);
            }
        }
    }

    return 0;
}
