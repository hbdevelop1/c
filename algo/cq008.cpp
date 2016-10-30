#include <iostream>
#include <memory>
using namespace std;

enum class Result
{
	Result_doesnotexist,
	Result_valuefound,
	Result_cornerfound,
};
/*
struct matrix
{
	int M,N;
	void *e;
	
	struct submatrix
	{
		int x1;
		int y1;
		int x2;
		int y2;
		submatrix(int m, int n):x1(0), y1(0), x2(n-1), y2(m-1)
		{
			
		}
	} sm;
	
	matrix(int m, int n, int (*arr)[4] ):sm(m, n), M(m), N(n), e(arr)
	{
		
	}
	bool find();
};
*/
//params: 
//	the matrix in its entirety
//	the coordinates of the submatrix search is going to happen in.
//		the x1,y1 the coordinates in the matrix. these are the top-left corner of the submatrix
//		the x2,y2 the coordinates in the matrix. these are the bottom-right corner of the submatrix
Result find(void *mv, int M, int &x1, int &y1, int &x2, int &y2, int n, int &x1_last, int &y1_last)
{
	int (*m)[M-1] = static_cast<int (*)[M-1]>(mv);
	
	if(x1>x2 || y1>y2)
	{
		return Result::Result_doesnotexist;
	}
		
		
	//get mid indices;
	int midx=(x1+x2)/2;
	int midy=(y1+y2)/2;
	
	if(n==m[midx][midy])
	{
		return Result::Result_valuefound;
	}
	else if(n<m[midx][midy])
	{
		x2=midx-1;
		y2=midy-1;
		return find(m,M,x1,y1,x2,y2,n,x1_last, y1_last);
	}
	else//if(n>m[midx][midy])
	{
		if(x1==x2 && y1==y2)
		{
			return Result::Result_cornerfound;
		}
		x1_last=midx;
		y1_last=midy;
		
		x1=midx+1;
		y1=midy+1;
		return find(m,M,x1,y1,x2,y2,n,x1_last, y1_last);
	}
	//compare with n;
}

enum class Result2_info
{
	doesnotexist,
	valuefound,
	corner,
};

struct Result2
{
	int x;
	int y;
	Result2_info info;
};


Result2 find2(void *mv, int M, int &x1, int &y1, int &x2, int &y2, int n, int &x1_last, int &y1_last)
{
	int (*m)[M-1] = static_cast<int (*)[M-1]>(mv);
	Result2 r;
	
	if(x1>x2 || y1>y2)
	{
		if(x2<0 || y2<0)
			r.info=Result2_info::doesnotexist;
		else
		{
			r.info=Result2_info::corner;
			r.x=x2;
			r.y=y2;
		}
		return r;
	}
		
		
	//get mid indices;
	int midx=(x1+x2)/2;
	int midy=(y1+y2)/2;
	
	if(n==m[midx][midy])
	{
		r.info=Result2_info::valuefound;
		r.x=midx;
		r.y=midy;
	
		return r;
	}
	else if(n<m[midx][midy])
	{
		x2=midx-1;
		y2=midy-1;
		return find2(m,M,x1,y1,x2,y2,n,x1_last, y1_last);
	}
	else//if(n>m[midx][midy])
	{
		x1=midx+1;
		y1=midy+1;
		return find2(m,M,x1,y1,x2,y2,n,x1_last, y1_last);
	}
	//compare with n;
}
/*
input
100	-> corner
7
*/

int main(int argv, char *arc[])
{
	int M=4;
	int a=1;
	int k=2;
	int g=3;
	int n=7;
	
	if(argv==66)//set n
	{
		
		int i=1;
		M=atoi(arc[i++]); 
		a=atoi(arc[i++]); 
		k=atoi(arc[i++]); 
		g=atoi(arc[i++]); 
	}
	else if(argv==2)
	{
		n=atoi(arc[1]);
	}
	/*
	int sizeofmem=sizeof(int)*M*N;
//	sizeofmem+=sizeof(int*)*N;
	unique_ptr<char[]> up_mi(new char[sizeofmem]);
	char rr[100];
	char *p=new (rr) char[4];
	char (*m)[4]=(char (*)[4])new (up_mi.get()) char[9];
	char (*t)[M]=(char (*)[M])(up_mi.get());
*/
	unique_ptr<int[]> up_m(new int[M*M]);
	int (*m)[M-1]=(int (*)[M-1])up_m.get();

	//matrix mtx(M, N, (int (*)[M])up_m.get() );
#if 1	
	for(int i=0;i<M;++i)
	{
		for(int j=0;j<M;++j)
		{
			if(i==0 && j==0)
				m[i][j]=a;
			else if(j==0)
				m[i][j]=m[i-1][j]+k;
			else
				m[i][j]=m[i][j-1]+g;
		}
	}
	
	
	/*
	int m[4][4]=
	{
		{1,2,8,9},
		{2,4,9, 12},
		{4,7,10,13},
		{6,8,1,15},
	}	;
	 */

	for(int i=0;i<M;++i)
	{
		for(int j=0;j<M;++j)
		{
			printf("%2d ",m[i][j]);
		}
		printf("\n");
	}	
 
	int x1=0, y1=0;
	int x2=M-1, y2=M-1;
	int x1_last=-1,y1_last=-1;
	/*
	Result result = find(m, M,x1,y1,x2,y2, n,x1_last,y1_last);
	printf("%d found: %d (%d,%d) (%d,%d) (%d,%d)\n",
		n,result!=Result_doesnotexist,x1,y1,x2,y2,x1_last,y1_last);
*/
	Result2 result2 = find2(m, M,x1,y1,x2,y2, n,x1_last,y1_last);
	switch(result2.info)
	{
		default:
			printf("erroooooooor");
		break;
		case Result2_info::doesnotexist:
			printf("%d !found\n",
				n);
		break;
		case Result2_info::valuefound:
			printf("%d found at (%d,%d)\n",
				n,result2.x,result2.y);
		break;
		case Result2_info::corner:
			printf("%d !found but corner is (%d,%d)\n",
				n,result2.x,result2.y);
		break;
	}

#endif
	
	return 0;
}
//0611217177
//0666299455
//0662053084