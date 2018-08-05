#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include <csignal>
#include <windows.h>
#include <thread>
#define random(x)(rand()%x)
#define PI 3.1415926
using namespace std;


string  Get_Current_Date();
void singleHandle(int signum);
class Line{
    public:
        void setLength(double len);
        double getLength();
        Line();
    
    private:
        double length;
};

Line::Line(){
    cout << "Object Line is being created" << endl;
}

void Line::setLength(double len){
    length = len;
}
double Line::getLength(){
    return length;
}




class Shape
{
protected:
  int width, height;

public:
    Shape(int a = 0,int b = 0){
        width = a;
        height = b;
    }
    virtual int area() = 0;
    ~Shape();
};

Shape::~Shape()
{
}

class MyRectangle:public Shape
{
    public:
    MyRectangle(int a = 0,int b=0):Shape(a,b){}
    int area(){
        float area = width * height ;
        cout << "Rectangle Class Area:" << area << endl;
        return area;
    }
};

class Triangle:public Shape{
    public:
    Triangle(int a = 0,int b =0):Shape(a,b){ }
    int area(){
        float area = width * height / 2;
        cout << "Triangle Class Area:" << area << endl;
        return area;
    }
};


template <typename T>
inline T const& Max(T const& a,T const& b){
    return a < b ? b : a;
}


template <class T>

class Stack
{
private:
  vector<T> elems;

public:
  void push(T const&);
  T pop() const;
  T top() const;
  void ListElement() const;
  bool empty() const{
      return elems.empty();
  }
};

template <class T>
void Stack<T>::push (T const& elem){
    elems.push_back(elem);
}
template <class T>
T Stack<T>::pop() const{
    if(elems.empty()){
        throw out_of_range("Stack<>:top():empty stack");
    }
    return elems.back();
}
template <class T>
T Stack<T>::top() const{
    if(elems.empty()){
        throw out_of_range("Stack<>:top():empty stack");
    }
    return elems.at(0);
}
template <class T>
void Stack<T>::ListElement() const{
    int i;
    for (i = 0; i < elems.capacity();i++){
        cout << "element: " << elems.at(i) << endl;
    }
}

int main()
{

    char str[50];
    strcpy(str,"this is the string.h library function");
    puts(str);
    memset(str + 37, '$', 7);
    puts(str);

    std::cout << "Hello, Universe! I'm running on Cloud Studio!\n";
    printf("hello world\n");

    cout << "type: \t\t" << "************size**************"<< endl;  
    cout << "bool: \t\t" << "occupy bit" <<sizeof(bool);
    cout << "\t Max value:" << (numeric_limits<bool>::max)(); 
    cout << "\t Min value:" << (numeric_limits<bool>::min)() <<endl;
    cout << "char: \t\t" << "occupy bit:" << sizeof(char);  
    cout << "\tMax value:" << (numeric_limits<char>::max)();  
    cout << "\t\tMin valu:" << (numeric_limits<char>::min)() << endl;  
    cout << "signed char:\t" << "occupy bit:" << sizeof(signed char);  
    cout << "\tMax value:" << (numeric_limits<signed char>::max)();  
    cout << "\t\tMin value:" << (numeric_limits<signed char>::min)() << endl; 


    int i,j;
    // 设置种子
    srand((unsigned)time(NULL));
    //void srand(unsigned seed);
    //它需要提供一个种子，这个种子会对应一个随机数，如果使用相同的种子后面的rand()函数会出现一样的随机数。如： srand(1); 直接使用 1 来初始化种子。
    //不过为了防止随机数每次重复，常常使用系统时间来初始化，即使用 time 函数来获得系统时间，它的返回值为从 00:00:00 GMT, January 1, 1970 到现在所持续的秒数，
    //然后将 time_t 型数据转化为(unsigned)型再传给 srand 函数，即： srand((unsigned) time(&t)); 还有一个经常用法，不需要定义time_t型t变量,
    //即： srand((unsigned) time(NULL)); 直接传入一个空指针，因为你的程序中往往并不需要经过参数获得的t数据
     /* 生成 10 个随机数 */
     printf("In 100 random num \n");
     for(i=0;i<30;i++){
         //j=rand();
         //cout <<"随机数： " << j % 100 << endl;
         cout <<"Random Num:" << random(100) << endl;
     }


    time_t now = time(0);
    char *dt = ctime(&now);
    cout << "Local Date And Time: " << dt << endl;
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "UTC Date And Time: " << dt << endl;
    tm *ltm = localtime(&now);
     // 输出 tm 结构的各个组成部分
    cout << "Year: "<< 1900 + ltm->tm_year << endl;
    cout << "Month: "<< 1 + ltm->tm_mon<< endl;
    cout << "Day: "<<  ltm->tm_mday << endl;
    cout << "Time: "<< ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;

    cout << Get_Current_Date().c_str() <<endl;

    
    Line line;
    line.setLength(6.0);
    cout << "Length of line :" << line.getLength() <<endl;

    Shape *shape;
    MyRectangle rect(10, 10);
    Triangle tria(10, 5);
    shape = &rect;
    shape->area();
    shape = &tria;
    shape->area();

    double *pvalue = NULL;// 初始化为 null 的指针
    pvalue = new double;// 为变量请求内存
    *pvalue = 291114.12;// 在分配的地址存储值
    cout << "Value of pvalue : " << *pvalue << endl;
    delete pvalue;

    i = 22, j = 20;
    cout << "Max(i,l):" << Max(i, j) << endl;

    double f1 = 5.5, f2 = 6.8;
    cout << "Max(f1,f2):" << Max(f1, f2) << endl;

    string s1 = "Hello", s2 = "Hellp";
    cout << "Max(s1,s2):" << Max(s1, s2) << endl;



    
    try
    {
        Stack<int> intStack;
        Stack<string> stringStack;
        intStack.push(7);
        intStack.push(22);
        cout << "intstack top" << intStack.top() << endl;
        stringStack.push("stringStack push a something");
        stringStack.push("stringStack push another something");
        cout << "string stack top" << stringStack.top() << endl;
        intStack.pop();
        stringStack.pop();
        intStack.ListElement();
        stringStack.ListElement();
    }
    catch(const std::exception& e)
    {
        cerr << "exception" << e.what() << endl;
    }
    cout << "The value of pi is :" << PI << endl;

    signal(SIGINT, singleHandle);
    i = 0;
    // while(++i){
    //     cout << "Going to sleep...." << endl;
    //     if(i == 10){
    //         raise(SIGINT);
    //     }
    //     Sleep(100);
    // }
    

    getchar();

    

    return 0;
}

string  Get_Current_Date()
{
    time_t nowtime;  
    nowtime = time(NULL); //获取日历时间   
    char tmp[64];   
    strftime(tmp,sizeof(tmp),"%Y-%m-%d",localtime(&nowtime));   
    return tmp;
}


void singleHandle(int signum){
    cout << "Interrupt single (" << signum << ") received. \n";
    
    // 清理并关闭
    // 终止程序

    exit(signum);
}


//就这样吧