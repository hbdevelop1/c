#include <QCoreApplication>

#include <iostream>          // std::cout
#include <initializer_list>  // std::initializer_list

void ff()
{
    int t;
    t=6;
}

int main1 ()
{
  std::initializer_list<int> mylist;
  mylist = { 10, 20, 30 };
  ff();
  std::cout << "mylist contains:";
  for (int x: mylist) std::cout << ' ' << x;
  std::cout << '\n';
  return 0;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    main1();

    return a.exec();
}

