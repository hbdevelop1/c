
template<class T1, class T2>
class Radio
{
public:
    T1 a;
    T2 b;
};

template<class T1, class T2, class T3, class T4>
class RadioManager<>
{
public:
    Radio<T1,T2> a;
    Radio<T3,T4> b;
};

int main()
{
    RadioManager<int, short, char, float> rm;
    Radio<short, char> a;
    Radio<int, float> b;

}
