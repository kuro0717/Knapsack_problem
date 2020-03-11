//ナップサック問題　深さ探索（全探索）
#include <stdio.h>

//const int MAX_N = 25;
//int w[MAX_N], v[MAX_N];

int n = 5;     //商品数
int W = 50;     //ナップサック容量
int w[]={10,20,30,45,4};//商品容量一覧
int v[]={60,100,120,210,10};//商品価値一覧

int max(int i,int j){
    return (i>j)?i:j;
}

int rec(int i, int j){
    int ret;
    if(i==n){ //残りの商品がない場合：価値を0を返す
        ret = 0;
    }else if(j < w[i]){//商品iが残り容量よりも大きい場合、商品iは加えず、次以降の商品を調べる
        ret = rec(i+1, j);
    }else{//商品iが入れれる場合、入れる場合と入れない場合をそれぞれ調べる
        ret = max(
            rec(i+1,j), 
            rec(i+1, j-w[i]) + v[i]
        );
    }
    return ret;
}

int main (void){
    printf("%d\n",rec(0,W));
    return 0;
}