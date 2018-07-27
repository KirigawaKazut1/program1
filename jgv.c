#include <stdio.h>
#define SIZE 30
char s[SIZE];
int top=-1;
push(char elem)
{
    s[++top]=elem;
}

char pop()
{
    return(s[top--]);
}

int pr(char elem)
{
    switch(elem)
    {
    case '#': return 0;
    case '(': return 1;
    case '+':
    case '-': return 2;
    case '*':
    case '/': return 3;
    }
}

void main()
{
    char infx[30],pofx[30],ch,elem;
    int i=0,k=0,g=0;
    loop:
    printf("Enter the number of expresions\n");
    scanf("%d",&g);

    if((g>=1)&&(g<=100))
    {

    for(i=0;i<g;i++)
    {

    printf("\n\nRead the Infix Expression ? \n");
    scanf("%s",infx);
    push('#');
    while( (ch=infx[i++]) != '\0')
    {
    if( ch == '(') push(ch);
    else
    if(isalnum(ch)) pofx[k++]=ch;
      else
    if( ch == ')')
    {
        while( s[top] != '(')
      pofx[k++]=pop();
        elem=pop();
    }
    else
    {
        while( pr(s[top]) >= pr(ch) )
      pofx[k++]=pop();
        push(ch);
    }
    }
    while( s[top] != '#')
    pofx[k++]=pop();
    pofx[k]='\0';
    printf("\n\nGiven Infix Expn: %s  Postfix Expn: %s\n",infx,pofx);
    //getch();
    }
    }
    else
    {
        printf("Enter valid number betn 1-100\n");
        goto loop;
    }

}
