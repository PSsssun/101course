#include <print>
#include <cstddef>

struct Vector {

// 私有变量 m_data 和 m_size 用户不应该直接对其进行操作
private:
    int *m_data;
    size_t m_size;

// 公有函数 setSize、data 和 size 用于对私有变量进行操作
// 私有变量的状态由公有函数进行控制，从而保证了私有变量的状态是合法的
// 在函数内可能短暂非法，但是函数结束后，私有变量的状态必须是合法的，自洽的
public:
    Vector() : m_data(new int[4]), m_size(4) {}

    void setSize(size_t newSize) {
        m_size = newSize;
        delete[] m_data;
        m_data = new int[newSize];
    }

    int *data() const {
        return m_data;
    }
    // 用户不应该直接对 m_size 进行操作，因此不提供修改 m_size 的函数
    // 返回值是一个右值
    // 无法赋值 
    size_t size() const { 
        return m_size; 
    }
};

int main() {
    Vector v;
    v.setSize(14);
    v.setSize(11);
    return 0;
}
