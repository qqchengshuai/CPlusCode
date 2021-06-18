// testGit.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
class Item_base {
public:
    Item_base(const string& book = "",double sales_price = 0):isbn(book),price(sales_price)
    {}
    string book() const
    {
        return isbn;
    }
    virtual double net_price(int n) const
    {
        cout << "Item_base,n:" << n << endl;
        return n * price;
    }

    virtual ~Item_base()
    {
    }
private:
    string isbn;
protected:
    double price;
};

class Bulk_item :public Item_base{
public:
    double net_price(int n)const
    {
        cout << "bulk_item,n:"<<n << endl;
        cout <<"book:"<< book() << endl;
        return n * price;
    }
private:
    int nMin_qty;
    double discount;
};

class C_item :public Bulk_item {
public:
    double net_price(int n)const
    {
        cout << "C_item,n:" << n << endl;
        cout << "book:" << book() << endl;
        //net_price(2);
        return n * price;
    }
};

int main()
{
    Item_base base("a",100);

    //cout << base.net_price(1) << endl;

    Bulk_item bulk;

    //Item_base& t = bulk;
    //t.net_price(1);
    //Item_base* p = new Bulk_item();
    //p->net_price(1);
    //cout << sizeof(string) << endl;
    //cout << sizeof(Item_base) << endl;
    //cout << sizeof(Bulk_item) << endl;

    C_item citem;
    Item_base& t = citem;
    t.Item_base::net_price(1);
    //t.Bulk_item::net_price(3);
    t.net_price(2);

    //std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
