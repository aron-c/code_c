#include <iostream>
using namespace std;
//组装电脑案例

class CPU
{
public:
    virtual void calculator() = 0;
};

class GPU
{
public:
    virtual void display() = 0;
};

class MEM
{
public:
    virtual void storage() = 0;
};

class Computer
{

private:
    CPU *m_cpu;
    GPU *m_gpu;
    MEM *m_mem;

public:
    Computer(CPU *cpu, GPU *gpu, MEM *mem)
    {
        m_cpu = cpu;
        m_gpu = gpu;
        m_mem = mem;
    }

    ~Computer()
    {
        if (m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu == NULL; /* code */
        }

        if (m_gpu != NULL)
        {
            delete m_gpu;
            m_gpu == NULL; /* code */
        }

        if (m_mem != NULL)
        {
            delete m_mem;
            m_mem == NULL; /* code */
        }
    }
    void work()
    {
        m_cpu->calculator();
        m_gpu->display();
        m_mem->storage();
    }
};

class IntelCpu : public CPU
{
public:
    virtual void calculator()
    {
        std::cout << "intel的cpu在计算" << '\n';
    }
};

class IntelGpu : public GPU
{
public:
    virtual void display()
    {
        std::cout << "intel的Gpu在计算" << '\n';
    }
};

class IntelMem : public MEM
{
public:
    virtual void storage()
    {
        std::cout << "intel的内存在计算" << '\n';
    }
};

class AMDCpu : public CPU
{
public:
    virtual void calculator()
    {
        std::cout << "AMD的cpu在计算" << '\n';
    }
};
class AMDGpu : public GPU
{
public:
    virtual void display()
    {
        std::cout << "AMD的Gpu在计算" << '\n';
    }
};
class AMDMem : public MEM
{
public:
    virtual void storage()
    {
        std::cout << "AMD的内存在计算" << '\n';
    }
};

void test01()
{
    CPU *CPU = new IntelCpu;
    GPU *GPU = new IntelGpu;
    MEM *MEM = new IntelMem;

    Computer *Computer1 = new Computer(CPU, GPU, MEM);
    Computer1->work();
    delete Computer1;

    cout << "-------------------------" << endl;
    CPU = new AMDCpu;
    GPU = new AMDGpu;
    MEM = new AMDMem;
    Computer *Computer2 = new Computer(CPU, GPU, MEM);
    Computer2->work();
    delete Computer2;

    cout << "-------------------------" << endl;
    Computer *Computer3 = new Computer(new IntelCpu, new AMDGpu, new IntelMem);
    Computer3->work();
    delete Computer3;
}

int main()
{
    cout << "hello world!" << endl;
    test01();
    return 0;
}
