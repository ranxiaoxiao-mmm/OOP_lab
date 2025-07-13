#include "shapes.h"
#include "rnd.h"
#include <cmath>

sf::Shape *create(char type)
{
    // 创建随机形状：圆形或矩形
    sf::Shape *shape = nullptr;
    
    if (type == 'c' || (type != 'r' && rnd() < 0.5f))
    {
        // 创建圆形
        float radius = 5.0f + rnd() * 25.0f; // 半径在5到30之间
        sf::CircleShape *circle = new sf::CircleShape(radius);
        shape = circle;
    }
    else
    {
        // 创建矩形
        float width = 10.0f + rnd() * 40.0f; // 宽度在10到50之间
        float height = 10.0f + rnd() * 40.0f; // 高度在10到50之间
        sf::RectangleShape *rectangle = new sf::RectangleShape(sf::Vector2f(width, height));
        shape = rectangle;
    }
    
    // 设置随机位置
    shape->setPosition(rnd() * 800.0f, rnd() * 600.0f);
    
    // 设置随机颜色
    sf::Color color(
        static_cast<sf::Uint8>(rnd() * 255),
        static_cast<sf::Uint8>(rnd() * 255),
        static_cast<sf::Uint8>(rnd() * 255),
        static_cast<sf::Uint8>(100 + rnd() * 155) // 半透明效果
    );
    shape->setFillColor(color);
    
    // 设置随机旋转角度
    shape->setRotation(rnd() * 360.0f);
    
    return shape;
}

Shapes::~Shapes()
{
    // 释放所有形状对象内存
    for (auto shape : items_)
    {
        delete shape;
    }
    items_.clear();
}

void Shapes::generate()
{
    // 清除现有的形状
    for (auto shape : items_)
    {
        delete shape;
    }
    items_.clear();
    
    // 生成指定数量的随机形状
    for (size_t i = 0; i < nums_; ++i)
    {
        // 随机决定创建圆形还是矩形
        char type = (rnd() < 0.5f) ? 'c' : 'r';
        sf::Shape *shape = create(type);
        items_.push_back(shape);
    }
}

void Shapes::update()
{
    for (auto shape : items_)
    {
        // 随机移动形状
        float dx = (rnd() - 0.5f) * 2.0f; // -1.0到1.0之间的随机值
        float dy = (rnd() - 0.5f) * 2.0f;
        
        sf::Vector2f pos = shape->getPosition();
        pos.x += dx;
        pos.y += dy;
        
        // 确保形状不会移出窗口边界
        float size = std::max(shape->getLocalBounds().width, shape->getLocalBounds().height);
        pos.x = std::max(0.0f, std::min(pos.x, 800.0f - size));
        pos.y = std::max(0.0f, std::min(pos.y, 600.0f - size));
        
        shape->setPosition(pos);
        
        // 随机旋转形状
        if (rnd() < 0.05f) // 5%的概率旋转
        {
            float rotation = shape->getRotation() + (rnd() - 0.5f) * 10.0f;
            shape->setRotation(rotation);
        }
        
        // 随机改变颜色
        if (rnd() < 0.01f) // 1%的概率改变颜色
        {
            sf::Color color(
                static_cast<sf::Uint8>(rnd() * 255),
                static_cast<sf::Uint8>(rnd() * 255),
                static_cast<sf::Uint8>(rnd() * 255),
                static_cast<sf::Uint8>(100 + rnd() * 155)
            );
            shape->setFillColor(color);
        }
    }
}

void Shapes::render(sf::RenderWindow &window)
{
    // 绘制所有形状到窗口
    for (auto shape : items_)
    {
        window.draw(*shape);
    }
}
