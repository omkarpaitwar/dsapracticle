#include
&lt;iostream&gt;

using namespace std;
int main() {
int n, i, j, k, row, col, mincost=0, min;
char op;
cout&lt;&lt;&quot;Enter no. of Cities: &quot;;
cin&gt;&gt;n;
int cost[n][n];
int visit[n];
for(i=0; i&lt;n; i++)
visit[i] = 0;
for(i=0; i&lt;n; i++)
for(int j=0; j&lt;n; j++)
cost[i][j] = -1;

for(i=0; i&lt;n; i++)
{
for(j=i+1; j&lt;n; j++)
{
cout&lt;&lt;&quot;Do you want a Connection between city &quot;&lt;&lt;i+1&lt;&lt;&quot; and

city &quot;&lt;&lt;j+1&lt;&lt;&quot;: &quot;;

//use &#39;i&#39; &amp; &#39;j&#39; if your vertices start from 0
cin&gt;&gt;op;
if(op==&#39;y&#39; || op==&#39;Y&#39;)
{
cout&lt;&lt;&quot;Enter weight: &quot;;
cin&gt;&gt;cost[i][j];
cost[j][i] = cost[i][j];
}
}
}
visit[0] = 1;
for(k=0; k&lt;n-1; k++)
{
min = 999;
for(i=0; i&lt;n; i++)
{
for(j=0; j&lt;n; j++)
{
if(visit[i] == 1 &amp;&amp; visit[j] == 0)
{
if(cost[i][j] != -1 &amp;&amp; min&gt;cost[i][j])

{
min = cost[i][j];
row = i;
col = j;
}
}
}
}
mincost += min;
visit[col] = 1;
cost[row][col] = cost[col][row] = -1;
cout&lt;&lt;row+1&lt;&lt;&quot;-&gt;&quot;&lt;&lt;col+1&lt;&lt;endl;
//use &#39;row&#39; &amp; &#39;col&#39; if your vertices start from 0
}
cout&lt;&lt;&quot;\nMin. Cost: &quot;&lt;&lt;mincost;
return 0;
}
