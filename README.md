# LearnCPP

The following is knowledge of C++ interview or exam.

**static**  
修饰普通变量，修改变量的存储区域和生命周期，使变量存储在静态区，在main函数运行前就分配了空间。  
如果有初始值就用初始值初始化它，如果没有初始值系统用默认值初始化它。  
修饰普通函数，表明函数的作用范围，仅在定义该函数的文件内才能使用。在多人开发项目时，为了防止与他人命令函数重名，可以将函数定位为static。  
修饰成员变量，修饰成员变量使所有的对象只保存一个该变量，而且不需要生成对象就可以访问该成员。  
修饰成员函数，修饰成员函数使得不需要生成对象就可以访问该函数，但是在static函数内不能访问非静态成员。  


&nbsp;  
**const**  
const int a=10;修饰*变量*，变量不可被改变 和int const a=10;是等价的  

const int* a = & [1];修饰*指针*  
如果const位于星号的左侧，则修饰指针指向的变量为常量。  
如果const位于星号的右侧，const就是修饰指针本身，即指针本身是常量。  

int const &a=x;const int &a=x;修饰*引用*，等价，a不能更新。

修饰成员函数，则该成员函数内不能修改成员变量。  

&nbsp;  

**inline**  
内联的目的是减少函数调用的开销。  
任何在类内部定义的函数自动地为内联函数  

    Class MyClass  
    {  
    public:  
    inline int GetState();  
    private:  
    int m_iState;  
    }  
    int inline MyClass::GetState()  
    {  
    return m_iState;  
    }  

内联函数的声明要和类在同一个文件里  
只要声明为内联，编译器就不把它编译成一次函数调用，而只是类似于把函数的代码拷贝到被调用的地方，原来的访问权限等问题丝毫不受影响。  
适用于简单的没有循环或递归的函数体，假如函数较大，那么花费在函数体内的时间相对于进出函数的时间的比例就会较大，所以收获会较小。  

&nbsp;  
**虚函数可以是内联函数吗**  
虚函数可以是内联函数，内联是可以修饰虚函数的，但是当虚函数表现多态性的时候不能内联。
内联是在编译器建议编译器内联，而虚函数的多态性在运行期，编译器无法知道运行期调用哪个代码，因此虚函数表现为多态性时（运行期）不可以内联。  
inline virtual 唯一可以内联的时候是：编译器知道所调用的对象是哪个类，这只有在编译器具有实际对象而不是对象的指针或引用时才会发生。

&nbsp;

**char\* && string**  
char* 获取长度strlen(a)，strlen()返回遇到第一个"\0"空字符前的长度  
获取字符串string实际长度的时候，使用a.size()和a.length()均可；

&nbsp;

**sizeof**  
sizeof 对数组，得到整个数组元素个数。  
sizeof 对指针，得到指针本身所占空间大小。

    char* a=" hello\0ls";
    cout<<sizeof(a)<<"   "<<strlen(a)<<endl;
    string b="hell\0";
    cout<<sizeof(b)<<"    "<<b.length()<<"   "<<b.size()<<"   "<<strlen(b.c_str())<<endl;
    string c="he\0ll\0";
    cout<<sizeof(c)<<"    "<<c.length()<<"   "<<c.size()<<"   "<<strlen(c.c_str())<<endl;

    //8   5
    //32  4  4  4
    //32  2  2  2


&nbsp;
**extern "C"**  
extern "C" 的作用是让C++编译器将extern "C"声明的代码当作C语言代码处理，可以避免C++因符号修饰导致代码不能和C语言库中的符号进行链接的问题。
&nbsp;
**struct && class**  
（1）  

    struct Student { 
        int age; 
    };
    void f( Student me );

（2）

    typedef struct Student { 
        int age; 
    } S;

    void Student() {}           // 正确，定义后 "Student" 只代表此函数

    //void S() {}               // 错误，符号 "S" 已经被定义为一个 "struct Student" 的别名

    int main() {
        Student(); 
        struct Student me;      // 或者 "S me";
        return 0;
    }


*struct和class的区别*  
默认继承权限。如果不明确指定，来自class的继承按照private继承处理，来自struct的继承按照public继承处理；  
成员的默认访问权限。class的成员默认是private权限，struct默认是public权限。  
“class”还可用于定义模板参数，但关键字“struct”不用于定义模板参数

&nbsp;
**explicit**  
构造函数前面加该关键字则该构造函数需要显示调用


&nbsp;
**拷贝构造函数**


&nbsp;
**函数重载**  
C++允许在同一范围中声明几个功能类似的同名函数，但是这些同名函数的形式参数（指参数的个数、类型或者顺序）必须不同，也就是说用同一个运算符完成不同的运算功能。这就是重载函数。重载函数常用来实现功能类似而所处理的数据类型不同的问题。**但是重载函数的返回值类型必须相同**。
&nbsp;
**List**  
创建

    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x): val(x), next(NULL){}
    };

    ListNode* node=new ListNode(0);
    ListNode* head=node;
    ListNode* n=new ListNode;
    n->val=x;
    node->next=n;
    node=node->next;
    ...

插入元素x


    ListNode* node=new ListNode(x);
    node->next=l1->next;
    l1->next=node;

生成：l1->node->l2  
&nbsp;

**C++面向对象的特点**  
*封装*  
把客观事物封装成抽象的类，并且类可以把自己的数据和方法只让可信的类或者对象操作，对不可信的进行信息隐藏。

*继承*  
它可以使用现有类的所有功能，并在无需重新编写原来的类的情况下对这些功能进行扩展。
实现继承、接口继承和可视继承。

*多态*  
覆盖：是指子类重新定义父类的虚函数的做法。  
重载：是指允许存在多个同名函数，而这些函数的参数表不同（或许参数个数不同，或许参数类型不同，或许两者都不同）。

重载是静态的，真正和多态相关的是“覆盖”。当子类重新定义了父类的虚函数后，父类指针根据赋给它的不同的子类指针，动态的调用属于子类的该函数，这样的函数调用在编译期间是无法确定的（调用的子类的虚函数的地址无法给出）。因此，这样的函数地址是在运行期绑定的（晚绑定）。结论就是：重载只是一种语言特性，与多态无关，与面向对象也无关。
&nbsp;

**继承**  
公有：  
基类中私有成员在派生类中是不可见的，对对象不可见   
基类的保护成员在派生类中为保护成员，对对象不可见  
基类的公有成员在派生类中为公有成员，对对象可见  

私有：  
基类中私有成员在派生类中是不可见的，对对象不可见  
基类的保护成员在派生类中为私有成员，对对象不可见  
基类的公共成员在派生类中为私有成员，对对象不可见  

保护：  
基类中私有成员在派生类中是不可见的，对对象不可见  
基类的保护成员在派生类中为保护成员，对对象不可见  
基类的公共成员在派生类中为保护成员，对对象不可见  
&nbsp;

**C++内存分配方式**

