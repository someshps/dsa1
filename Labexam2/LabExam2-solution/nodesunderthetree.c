#include<stdio.h>

int inorder(int node, int Left[], int Right[], int Ans[])
{
  if (Left[node] == 0 && Right[node] == 0)
  {
    Ans[node] = 1;
    return 1;
  }
  else
  {
    int leftans = 0;
    int rightans = 0;
    if(Left[node] != 0)
      leftans = inorder(Left[node], Left, Right, Ans);
    if(Right[node] != 0)
      rightans = inorder(Right[node], Left, Right, Ans);
    Ans[node] = leftans + rightans + 1;
    return Ans[node];

  }
}

int main()
{
  int n,i;
  int Left[10000],Right[10000], Ans[10000];


  scanf("%d", &n);

  for( i=1; i<n+1; i++)
  {
    scanf("%d %d", &Left[i], &Right[i]);
  }

  inorder(1, Left, Right, Ans);

  for (i=1; i<n; i++)
    printf("%d ", Ans[i]);
  printf("%d", Ans[n]);

  return 0;
}
