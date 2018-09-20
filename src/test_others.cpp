#include "test_others.h"
#include <string.h>
#include <math.h>
#define INT_MAX 99999
using namespace std;
int map[][5] = {                     //定义有向图
    {0, 10, INT_MAX, INT_MAX, 5},
    {INT_MAX, 0, 1, INT_MAX, 2},
    {INT_MAX, INT_MAX, 0, 4, INT_MAX},
    {7, INT_MAX, 6, 0, INT_MAX},
    {INT_MAX, 3, 9, 2, 0}
};
void Dijkstra(
              const int numOfVertex,    /*节点数目*/
              const int startVertex,    /*源节点*/
              int (map)[][5],          /*有向图邻接矩阵*/
              int *distance,            /*各个节点到达源节点的距离*/
              int *prevVertex           /*各个节点的前一个节点*/
              )
{
    vector<bool> isInS;                 //是否已经在S集合中
    isInS.reserve(0);
    isInS.assign(numOfVertex, false);   //初始化，所有的节点都不在S集合中
    /*初始化distance和prevVertex数组*/
    for(int i =0; i < numOfVertex; ++i)
    {
        distance[ i ] = map[ startVertex ][ i ];
        if(map[ startVertex ][ i ] < INT_MAX)
            prevVertex[ i ] = startVertex;
        else
            prevVertex[ i ] = -1;       //表示还不知道前一个节点是什么
    }
    prevVertex[ startVertex ] = -1;
    /*开始使用贪心思想循环处理不在S集合中的每一个节点*/
    isInS[startVertex] = true;          //开始节点放入S集合中
    int u = startVertex;
    for (int i = 1; i < numOfVertex; i ++)      //这里循环从1开始是因为开始节点已经存放在S中了，还有numOfVertex-1个节点要处理
    {
        
        /*选择distance最小的一个节点*/
        int nextVertex = u;
        int tempDistance = INT_MAX;
        for(int j = 0; j < numOfVertex; ++j)
        {
            if((isInS[j] == false) && (distance[j] < tempDistance))//寻找不在S集合中的distance最小的节点
            {
                nextVertex = j;
                tempDistance = distance[j];
            }
        }
        isInS[nextVertex] = true;//放入S集合中
        u = nextVertex;//下一次寻找的开始节点
        /*更新distance*/
        for (int j =0; j < numOfVertex; j ++)
        {
            if (isInS[j] == false && map[u][j] < INT_MAX)
            {
                int temp = distance[ u ] + map[ u ][ j ];
                if (temp < distance[ j ])
                {
                    distance[ j ] = temp;
                    prevVertex[ j ] = u;
                }
            }
        }
    }   
}
void Test_others::Test_others_dijkstra(){
	int distance[5];
    int preVertex[5];
    for (int i =0 ; i < 5; ++i ){
        Dijkstra(5, i, map, distance, preVertex);
        for(int j =0; j < 5; ++j)
        {
            int index = j;
            stack<int > trace;
            while (preVertex[index] != -1) {
                trace.push(preVertex[index]);
                index = preVertex[index];
            } 
            cout << "路径：";
            while (!trace.empty()) {
                cout<<trace.top()<<" -- ";
                trace.pop();
            }
            cout <<j;
            cout <<" 距离是："<<distance[j]<<endl;
        }
    }
}
/*
 * slab的使用
 */
typedef class data{
	public:
		int i;
		char data[16];
}data;
void Test_others::Test_others_slab(){
	cout << "Test_others_slab"<<endl;
	gm_slab<data> slab;
	data *d = slab.alloc();
	d->i = 1;
	strcpy(d->data,"hello world");
	cout << "(d->i):" << d->i << " (d->data):" << d->data << endl; 
	slab.free(d);
	cout << "(d->i):" << d->i << " (d->data):" << d->data << endl;
	return;
}
/*
 * 继承的使用
 * C++的子类与孙子类都实现了虚函数时，孙子类的实现会覆盖掉子类的实现。
 * 继承的最主要的应用就是把不同的类放到一个数组中，然后遍历调用同名函数。
 */
void Test_others::Test_others_inherit(){
	cout << "Test_others_inherit"<<endl;
	string name = "C";
	Child child(name);
	name = "GC";
	GrandChild gchild(name);
	vector<Parent*> mlist;
	mlist.push_back(dynamic_cast<Parent*>(&child));
	mlist.push_back(dynamic_cast<Parent*>(&gchild));
	for(int i = 0; i < mlist.size();++i){
		mlist[i]->printName();
	}
	return;
}
/*
 * 结合着类的特性和类中一般成员函数，我们可以这样理解：类具有封装和信息隐藏的特性。只有类的成员函数才能访问类的私有
 * 成员，程序中的其他函数是无法访问私有成员的。非成员函数可以访问类中的公有成员，但是如果将数据成员都定义为公有的，
 * 这又破坏了隐藏的特性。另外，应该 看到在某些情况下，特别是在对某些成员函数多次调用时，由于参数传递，类型检查和安
 * 全性检查等都需要时间开销，而影响程序的运行效率。
 * 为了解决上述问题，提出一种使用友元的方案。友元是一种定义在类外部的普通函数，但它需要在类体内进行说明，
 * 为了与该类的成员函数加以区别，在说明时前面加以关键字friend。友元不是成员函数，但是它可以访问类中的私有成员。友元
 * 的 作用在于提高程序的运行效率，但是，它破坏了类的封装性和隐藏性，使得非成员函数可以访问类的私有成员。
 * 友元函数的特点是能够访问类中的私有成员的非成员函数。友元函数从语法上看，它与普通函数一样，即在定义上和调用上与普通函数一样.
*/
double Distance(Point &a, Point &b){
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx*dx+dy*dy);
}
void Point::Getxy(){
	cout << "(" << x << "," << y << ")" << endl;
}
/*
 * 友元的使用
 */
void Test_others::Test_others_firends(){
	cout << "Test_others_firends"<<endl;
	Point p1(3.0,4.0), p2(6.0,8.0);
	p1.Getxy();
	p2.Getxy();
	double d = Distance(p1,p2);
	cout << "Distance is " << d << endl;
	You you;
	d = you.Multi(p1);
	cout << "Math.Multi is " << d << endl;
	return;
}