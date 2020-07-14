template <class A>
A MaxPtr (A *ptr, int a)
{
 if (a==1) return *ptr;
 return *ptr > (a = MaxPtr (ptr+1, a-1)) ? *ptr : a;
}
