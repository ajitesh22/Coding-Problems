int recur(int n ,int idx , int lastDigit){

    if(idx==n)
        return 1;
    int cnt = 0 ;
    for(int i = lastDigit + 1 ; i <=9 ; i++){
        if(idx==0 && i==0)
            continue;
        cnt += recur(n , idx+1 , i);
    }
    return cnt;
}

int solve(int n) {
    return recur(n , 0 , -1);
    
}
