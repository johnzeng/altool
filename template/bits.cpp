int count_bit(int x)
{
    int count = 0;
    while(x)
    {
        count++;
        x &= (x -1);
    }
    return count;
}

