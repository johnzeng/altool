// input a,b,c, return in x1,x2, and ret value is the solution number
int solve_function(long double a, long double b, long double c, long double &x1, long double &x2)
{
    int ret = 0;
    long double d = b*b - 4*a*c;
    if(d < 0) ret = 0;
    else if(d == 0)
    {
        ret = 1;
        x1 = x2 = (-b/(2.0*a));
    }
    else
    {
        ret = 2;
        long double e = sqrt(d);
        x1 = (-b + e) / (a * 2.0) ; 
        x2 = (-b - e) / (a * 2.0) ; 
    }
    return ret;
}

