#include "node.h"
#include "util.h"
#include "api.h"
#include <iostream>
#include <array>

void rwa2::Node::print_m_walls() {
    for (int i = 0; i < 4; i++) {
        std::cerr << "printing m_walls of current node: " << m_walls[i] << std::endl;
    }
}

void rwa2::Node::set_wall(int direction, bool is_wall) {
    if (direction >= 0 && direction < 4) { // Bảo vệ truy cập mảng
        m_walls.at(direction) = is_wall;
    }
}

bool rwa2::Node::is_wall(int direction) const {
    if (direction >= 0 && direction < 4) { // Bảo vệ truy cập mảng
        return m_walls.at(direction);
    }
    return false; // Trả về false nếu direction không hợp lệ
}

int rwa2::Node::compute_number_of_walls() const {
    int weight_n = is_wall(direction::NORTH) ? 1 : 0;
    int weight_e = is_wall(direction::EAST) ? 1 : 0;
    int weight_s = is_wall(direction::SOUTH) ? 1 : 0;
    int weight_w = is_wall(direction::WEST) ? 1 : 0;

    return weight_n + weight_e + weight_s + weight_w;
}
