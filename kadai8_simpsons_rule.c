#include<stdio.h>
#include<math.h>

double f (double x) {
    return 1/x;   //f(x)定義
}

/*----------シンプソン法----------*/
double simpsons_rule (double a, double b, int n) {  //区間[a,b]をn分割
//-----定義-----//
    double answer;
    double DELTAx;
    int i;
    double value = 0;
    DELTAx = (b - a) / (2 * n); //範囲をn等分

//-----計算-----//
    for (i =0; i <= 2*n; i++) {
        if (i ==0 || i == 2*n) {        //最初と最後
            value += f(a + i*DELTAx);
        }
        else if (i % 2 == 1) {      //奇数
            value += 4 * f(a + i*DELTAx);
        }
        else value += 2 * f(a + i*DELTAx);  //偶数
    }

//-----リターン-----//
    answer = value * DELTAx/3;
    return answer;
}

//-----出力-----//
int main () {
    printf("解は x = %f です。", simpsons_rule(1, 2, 10));
}