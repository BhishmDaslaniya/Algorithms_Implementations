#include<bits/stdc++.h>

clock_t s;
clock_t e;

void StartTimer()
{
    s = clock();
}

void StopTimer()
{
    e = clock();
}

double CalTimeDiff(){
    return (difftime(e, s) / (double)CLOCKS_PER_SEC);
}