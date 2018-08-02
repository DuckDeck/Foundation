#include <iostream>
#define random(x)(rand()%x)
using namespace std;
string  Get_Current_Date();
int main()
{
    std::cout << "Hello, Universe! I'm running on Cloud Studio!\n";
    printf("hello world\n");

    cout << "type: \t\t" << "************size**************"<< endl;  
    cout << "bool: \t\t" << "所占字节数" <<sizeof(bool);
    cout << "\t最大值：" << (numeric_limits<bool>::max)(); 
    cout << "\t最小值：" << (numeric_limits<bool>::min)() <<endl;
    cout << "char: \t\t" << "所占字节数：" << sizeof(char);  
    cout << "\t最大值：" << (numeric_limits<char>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<char>::min)() << endl;  
    cout << "signed char: \t" << "所占字节数：" << sizeof(signed char);  
    cout << "\t最大值：" << (numeric_limits<signed char>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<signed char>::min)() << endl; 


    int i,j;
    // 设置种子
    srand((unsigned)time(NULL));
    //void srand(unsigned seed);
    //它需要提供一个种子，这个种子会对应一个随机数，如果使用相同的种子后面的rand()函数会出现一样的随机数。如： srand(1); 直接使用 1 来初始化种子。
    //不过为了防止随机数每次重复，常常使用系统时间来初始化，即使用 time 函数来获得系统时间，它的返回值为从 00:00:00 GMT, January 1, 1970 到现在所持续的秒数，
    //然后将 time_t 型数据转化为(unsigned)型再传给 srand 函数，即： srand((unsigned) time(&t)); 还有一个经常用法，不需要定义time_t型t变量,
    //即： srand((unsigned) time(NULL)); 直接传入一个空指针，因为你的程序中往往并不需要经过参数获得的t数据
     /* 生成 10 个随机数 */
     printf("100以内的随机数\n");
     for(i=0;i<30;i++){
         //j=rand();
         //cout <<"随机数： " << j % 100 << endl;
         cout <<"随机数： " << random(100) << endl;
     }


    time_t now = time(0);
    char *dt = ctime(&now);
    cout << "本地日期和时间: " << dt << endl;
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "UTC 日期和时间: " << dt << endl;
    tm *ltm = localtime(&now);
     // 输出 tm 结构的各个组成部分
    cout << "年: "<< 1900 + ltm->tm_year << endl;
    cout << "月: "<< 1 + ltm->tm_mon<< endl;
    cout << "日: "<<  ltm->tm_mday << endl;
    cout << "时间: "<< ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;

    cout << Get_Current_Date().c_str() <<endl;
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