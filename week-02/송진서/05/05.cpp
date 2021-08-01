#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    if(n%2==0){ //짝수
      answer=pow(2, n/2)+pow(2, n/2-1)-1;
    } 
    else{
      answer=pow(2, n/2)+pow(2, n/2-1)+2;
    }
    return answer%1000000007;
}