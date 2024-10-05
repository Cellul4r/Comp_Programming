int n=1e4,m=1;extern"C"{int printf(const char*format,...);}
int main(){
    if(m<1e3){
        printf("%d x %d = %d\n",n,m++,n*m);
        main();
    }else{
        printf("%d x %d = %d",n,m,n*m);
    }
}