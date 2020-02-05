#include <stdio.h>
#include <algorithm>

using namespace std;
int l_x[3], l_y[3], r_x[3], r_y[3];

int getRemainArea(int idx){
    int area = (r_x[idx] - l_x[idx]) * (r_y[idx] - l_y[idx]);
    if(r_x[idx] <= l_x[2]) return area;
    if(l_x[idx] >= r_x[2]) return area;
    if(r_y[idx] <= l_y[2]) return area;
    if(l_y[idx] >= r_y[2]) return area;

    int nl_x =  max(l_x[idx], l_x[2]);
    int nl_y =  max(l_y[idx], l_y[2]);
    int nr_x =  min(r_x[idx], r_x[2]);
    int nr_y =  min(r_y[idx], r_y[2]);
    return area - (nr_x - nl_x) * (nr_y - nl_y);
}

int main(){
    for(int i = 0; i < 3; i++)
        scanf("%d %d %d %d", &l_x[i], &l_y[i], &r_x[i], &r_y[i]);
    printf("%d", getRemainArea(0) + getRemainArea(1));
    return 0;
}