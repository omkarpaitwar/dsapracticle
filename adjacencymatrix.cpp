#include&lt;iostream&gt;
#include&lt;stdlib.h&gt;
using namespace std;
int cost[10][10],i,j,k,n,qu[10],front,rear,v,visit[10],visited[10];
intstk[10],top,visit1[10],visited1[10];
main()
{
int m;
cout&lt;&lt;&quot;enterno of vertices&quot;;
cin&gt;&gt; n;
cout&lt;&lt;&quot;enter no of edges&quot;;
cin&gt;&gt; m;
cout&lt;&lt;&quot;\nEDGES \n&quot;;
for(k=1;k&lt;=m;k++)
{
cin&gt;&gt;i&gt;&gt;j;
cost[i][j]=1;
cost[j][i]=1;
}

//display function
cout&lt;&lt;&quot;The adjacency matrix of the graph is:&quot;&lt;&lt;endl;
for(i=0;i&lt;n;i++)
{
for(j=0;j&lt;n;j++)
{
cout&lt;&lt;&quot; &quot;&lt;&lt;cost[i][j];
}
cout&lt;&lt;endl;
}
cout&lt;&lt;&quot;Enter initial vertex&quot;;
cin&gt;&gt;v;
cout&lt;&lt;&quot;The BFS of the Graph is\n&quot;;
cout&lt;&lt; v;
visited[v]=1;
k=1;
while(k&lt;n)
{
for(j=1;j&lt;=n;j++)
if(cost[v][j]!=0 &amp;&amp; visited[j]!=1 &amp;&amp; visit[j]!=1)
{

visit[j]=1;
qu[rear++]=j;
}
v=qu[front++];
cout&lt;&lt;v &lt;&lt; &quot; &quot;;
k++;
visit[v]=0; visited[v]=1;
}
cout&lt;&lt;&quot;Enter initial vertex&quot;;
cin&gt;&gt;v;
cout&lt;&lt;&quot;The DFS of the Graph is\n&quot;;
cout&lt;&lt; v;
visited[v]=1;
k=1;
while(k&lt;n)
{
for(j=n;j&gt;=1;j--)
if(cost[v][j]!=0 &amp;&amp; visited1[j]!=1 &amp;&amp; visit1[j]!=1)
{
visit1[j]=1;
stk[top]=j;

top++;
}
v=stk[--top];
cout&lt;&lt;v &lt;&lt; &quot; &quot;;
k++;
visit1[v]=0; visited1[v]=1;
}
}
(Adjecency List)
#include&lt;iostream&gt;
using namespace std;
#define MAX 10
#define TRUE 1
#define FALSE 0
// declaring an adjacency list for storing the graph
classlgra
{
private:
struct node1
{
int vertex;

struct node1 *next;
};
node1 *head[MAX];
int visited[MAX];
public:
//static intnodecount;
lgra();
void create();
voiddfs(int);
};
//constructor
lgra::lgra()
{
int v1;
for(v1=0;v1&lt;MAX;v1++)
visited[v1]=FALSE;
for(v1=0;v1&lt;MAX;v1++)
head[v1]=NULL;
}
voidlgra::create()
{

int v1,v2;
charans;
node1 *N,*first;
cout&lt;&lt;&quot;Enter the vertices no. beginning with 0&quot;;
do
{
cout&lt;&lt;&quot;\nEnter the Edge of a graph\n&quot;;
cin&gt;&gt;v1&gt;&gt;v2;
if(v1&gt;=MAX || v2&gt;=MAX)
cout&lt;&lt;&quot;Invalid Vertex Value\n&quot;;
else
{
//creating link from v1 to v2
N = new node1;
if (N==NULL)
cout&lt;&lt;&quot;Insufficient Memory\n&quot;;
N-&gt;vertex=v2;
N-&gt;next=NULL;
first=head[v1];
if (first==NULL)
head[v1]=N;

else
{ while(first-&gt;next!=NULL)
first=first-&gt;next;
first-&gt;next=N;
}
//creating link from v2 to v1
N=new node1;
if (N==NULL)
cout&lt;&lt;&quot;Insufficient Memory\n&quot;;
N-&gt;vertex=v1;
N-&gt;next=NULL;
first=head[v2];
if (first==NULL)
head[v2]=N;
else
{
while(first-&gt;next!=NULL)
first=first-&gt;next;
first-&gt;next=N;
}
}

cout&lt;&lt;&quot;\n Want to add more edges?(y/n)&quot;;
cin&gt;&gt;ans;
}while(ans==&#39;y&#39;);
}
//dfs function
voidlgra::dfs(int v1)
{
node1 *first;
cout&lt;&lt;endl&lt;&lt;v1;
visited[v1]=TRUE;
first=head[v1];
while(first!=NULL)
if (visited[first-&gt;vertex]==FALSE)
dfs(first-&gt;vertex);
else
first=first-&gt;next;
}
int main()
{
int v1;
lgra g;

g.create();
cout&lt;&lt;endl&lt;&lt;&quot;Enter the vertex from where you want to traverse:&quot;;
cin&gt;&gt;v1;
if(v1&gt;=MAX)
cout&lt;&lt;&quot;Invalid Vertex\n&quot;;
else
{
cout&lt;&lt;&quot;The Dfs of the graph:&quot;;
g.dfs(v1);
}
}
