#include <iostream>
#include <string>
using namespace std;

class Building
{

    friend void goodGay(Building &building);
    friend class GoodGay;

private:
    string m_bedRoom; /* data */
public:
    Building(/* args */);
    string m_sittingRoom;
    ~Building();
};

Building::Building(/* args */)
{
    m_sittingRoom = "客厅";
    m_bedRoom = "卧室";
}

Building::~Building()
{
}

class GoodGay
{
private:
    /* data */
public:
    GoodGay(/* args */);
    void visit();
    Building *building;
    ~GoodGay();
};

GoodGay::GoodGay(/* args */)
{
    building = new Building;
}

GoodGay::~GoodGay()
{
}
void GoodGay::visit()
{
    cout << "新朋友正在访问：" << building->m_sittingRoom << endl;
    cout << "新朋友正在访问：" << building->m_bedRoom << endl;
}
void goodGay(Building &building)
{
    cout << "朋友正在访问：" << building.m_sittingRoom << endl;
    cout << "朋友正在访问：" << building.m_bedRoom << endl;
}

void test01()
{
    Building b;
    goodGay(b);
}
void test02()
{
    GoodGay g;
    g.visit();
}
int main()
{
    cout << "hello world!" << endl;
    test01();
    test02();
    return 0;
}
