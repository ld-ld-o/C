#include <stdio.h>
#include <string.h>

int recursion(const char *s, int l, int r, int *m){
    *m+=1;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1, m);
}

int isPalindrome(const char *s, int *m){
    return recursion(s, 0, strlen(s)-1, m);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i<n; i++){
        int m = 0;
        char s[1001];
        scanf("%s",s);
        int isp =isPalindrome(s,&m);
        printf("%d %d\n",isp,m);
    }
    return 0;
    
}
