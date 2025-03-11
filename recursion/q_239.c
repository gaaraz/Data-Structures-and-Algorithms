#include <stdio.h>
#include <math.h>
#define S(x) ((x) * (x))

void f(long long n, long long s, long long* px, long long* py){
	if(n == 1){
		if(s == 1){
			*px = 0, *py = 0;
		}else if(s == 2){
			*px = 1, *py = 0;
		}else if(s == 3){
			*px = 1, *py = 1;
		}else{
			*px = 0, *py = 1;
		}
		return;
	}
	long long L = pow(2, n-1);
	long long block = L * L;
	long long xx,yy;
	if(s <= block){
		// 1号区域
		f(n-1, s, &xx, &yy);
		*px = yy, *py = xx;
	}else if(s <= 2*block){
		// 2号区域
		f(n-1, s-block, &xx, &yy);
		*px = xx+L, *py = yy;
	}else if(s <= 3*block){
		// 3号区域
		f(n-1, s-2*block, &xx, &yy);
        *px = xx+L, *py = yy+L;
	}else{
		// 4号区域
		f(n-1, s-3*block, &xx, &yy);
		*px = L-yy-1, *py = 2*L-xx-1;
	}
	return;
}

int main(){
	long long t,n,s,d;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld%lld%lld", &n, &s, &d);
		long long sx,sy,dx,dy;
		f(n, s, &sx, &sy);
		f(n, d, &dx, &dy);
		printf("%.0lf\n", 10 * sqrt(S(sx-dx) + S(sy-dy)));
	}
}
