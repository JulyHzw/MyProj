#include <QCoreApplication>
#include <iostream>
using namespace std;
#include <QLibrary>
#include <QDebug>
typedef int (*pAdd)(int a, int b);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QLibrary mydll("E:/1.study/11.QTtest/build-MyProjDll-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/debug/MyProjDll.dll");
    mydll.load();	// 加载库
    if(mydll.isLoaded())
    {

        pAdd add=(pAdd)mydll.resolve("add");
        if(add)
        {

            int ret=add(9,4); //在 这里调用DLL里的函数
            QString str;
            str=QString::number(ret);
            //            QMessageBox::information(NULL,"111",
            //                                     str);
            qDebug()<<str<< endl ;
        }
        mydll.unload();
    }
    return a.exec();
}
