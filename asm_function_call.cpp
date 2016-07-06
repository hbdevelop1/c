
void print(int *p)
{
}

int add(int a, int b)
{
    a+=2;
    b+=3;
    return a+b; 
}

int main()
{
    int a=10;
    int b=11;
    int c =     add(a+1, b-3);
    
    print(&c);
    
    return 0;
}
