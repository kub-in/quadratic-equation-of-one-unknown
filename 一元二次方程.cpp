#pragma GCC optimize(3) 
#include<iostream>
#include<stdio.h>
#include<windows.h>
#include"function.h"
#define ll long long
using namespace function;
using namespace std;
long double a,b,c;
bool end_yn()
{
	char c;
	cin>>c;
	if(c=='q')re 1;
	re 0;
}
main()
{
	a=b=c=0; 
	cin>>a>>b>>c;//输入三个系数以求解
	if(a==0)
	{
		puts("不为一元二次方程");
		system("pause");
		re 0;
	}//是否为1元2次 
	while((ll)a!=a||(ll)b!=b||c!=(ll)c)
	{
		a*=10;
		b*=10;
		c*=10;
	}//转化为整数 
	ll d=(b*b-4*a*c);
	if(d<0)
	{
		puts("无解");system("pause"); 
		re 0;
	}//判别式
	printf("x1=");
	if(d==0)
	{
		printf("x2=");
		ll fz=-b,fm=2*a,yf;
		if(fm<0)
		{
			fm=-fm;
			fz=b;
		}
		bool fh=0;
		if(fz<0)fz=-fz,fh=1;
		if(fh)putchar('-');
	 	yf=gcd(fz,fm);
		fz/=yf,fm/=yf;
		cout<<fz;
		if(fm!=1)cout<<'/'<<fm;
		putchar('\n');
		system("pause");
		re 0;
	}//delta=0，两个相同解 
	ll dr=1;
	while(d>=4&&d%4==0)
	{
		dr*=2;
		d/=4;
	}
	for(ll t=3;t*t<=d;t+=2)
	{
		while(d>=t*t&&d%(t*t)==0)
		{
			d/=(t*t);
			dr*=t;
		}
	}
	if(d==1)
	{
		ll fz1=-b-dr,fz2=-b+dr,fm=2*a,s1,s2;
		if(a<0)
		{
		 	fz1=-fz1,fm=-fm,fz2=-fz2;
		}
		bool fh1=0,fh2=0;
		if(fz1<0)
		{
			fh1=1;
			fz1=-fz1;
		}
		if(fz2<0)
		{
			fh2=1;
			fz2=-fz2;
		}
		s1=gcd(fz1,fm);
		s2=gcd(fz2,fm);
		fz1/=s1;
		fz2/=s2;
		if(fh1)putchar('-');
		cout<<fz1;
		if(fm/s1!=1)
		{
	 		cout<<'/'<<fm/s1;
	    }
	    cout<<endl<<"x2=";
	    if(fh2)putchar('-');
	    cout<<fz2;
	    if(fm/s2!=1)
	    {
	    	cout<<'/'<<fm/s2;
		}
		putchar('\n');
		system("pause"); 
		re 0;
	}//delta=1,根无无理数部分 
	ll fm=2*a,fzr=-b;
	if(fm<0)
	{
		fm=-fm;
		fzr=-fzr;
	}
	bool fh=0;
	if(fzr<0)
	{
		fzr=-fzr;
		fh=1;
	}
	ll s=gcd(fzr,gcd(dr,fm));
	fzr/=s;
	dr/=s;
	fm/=s;
	if(fh)fzr=-fzr;
	if(fm==1)
	{
		if(fzr!=0)cout<<fzr<<'+';
		if(dr!=1)cout<<dr;
		cout<<'('<<d<<"^0.5)"<<endl<<"x2=";
		if(fzr!=0)cout<<fzr;
		cout<<'-';
		if(dr!=1)cout<<dr;
		cout<<'('<<d<<"^0.5)";
	}
	else
	{
		putchar('(');
		if(fzr!=0)cout<<fzr<<'+';
		if(dr!=1)cout<<dr;
		cout<<'('<<d<<"^0.5))"<<'/'<<fm<<endl<<"x2=(";
		if(fzr!=0)cout<<fzr;
		cout<<'-';
		if(dr!=1)cout<<dr;
		cout<<'('<<d<<"^0.5))"<<'/'<<fm;
	}//处理其余情况 
	putchar('\n');
	system("pause");
	re 0;
}
