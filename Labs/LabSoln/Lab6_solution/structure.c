#include<stdio.h>

struct employee
{
    char name[1000];
    int salary;
};

void printMaximum(struct employee *p, int n)
{
  int min = p->salary;
  char *name = (p->name);
  int i;
  for( i =1; i<n; i++)
  {
    if (min < (p+i)->salary)
    {
      min = (p+i)->salary;
      name = (p+i)->name;
    }
  }
  printf("%s", name);
}

int main()
{
    struct employee e[1000];
    int n;

    scanf("%d", &n);
    for (int i =0 ; i< n; i++)
    {
      scanf("%s", e[i].name);
      scanf("%d",&e[i].salary);
    }

    printMaximum(e,n) ;
    return 0;
}
