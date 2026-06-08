double fatorial(int n) {
    if(n <= 1) return 1;
    return n * fatorial(n-1);
}

double potencia(int x,int n){
    if(n == 0) return 1;
    return x* potencia(x, n-1);
}

double exp_natural(int x, int n){
    if(n == 0) return 1;
    return exp_natural(x,n-1) + (potencia(x,n) / fatorial(n));
}