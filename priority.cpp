#include&lt;iostream&gt;
#include&lt;string&gt;
#define N 20
#define SERIOUS 10
#define NONSERIOUS 5
#define CHECKUP 1
using namespace std;
string Q[N];
int Pr[N];
int r = -1,f = -1;
void enqueue(string data,int p)//Enqueue function to insert data and
its priority in queue
{
int i;
if((f==0)&amp;&amp;(r==N-1)) //Check if Queue is full
cout&lt;&lt;&quot;Queue is full&quot;;
else {
if(f==-1) { //if Queue is empty
f = r = 0;
Q[r] = data;
Pr[r] = p;
}
else if(r == N-1) { //if there there is some elemets in

Queue

for(i=f;i&lt;=r;i++) {

Q[i-f] = Q[i];
Pr[i-f] = Pr[i];
r = r-f;
f = 0;
for(i = r;i&gt;f;i--) {

if(p&gt;Pr[i]) {
Q[i+1] = Q[i];
Pr[i+1] = Pr[i];
}
else break;
Q[i+1] = data;
Pr[i+1] = p;
r++;
}
}
}
else {
for(i = r;i&gt;=f;i--) {
if(p&gt;Pr[i]) {
Q[i+1] = Q[i];
Pr[i+1] = Pr[i];
}

else break;
}
Q[i+1] = data;
Pr[i+1] = p;
r++;
}
}
}
void print() { //print the data of Queue
int i;
for(i=f;i&lt;=r;i++) {
cout &lt;&lt; &quot;Patient&#39;s Name - &quot;&lt;&lt;Q[i];
switch(Pr[i]) {
case 1:
cout &lt;&lt; &quot; Priority - &#39;Checkup&#39; &quot; &lt;&lt; endl;
break;
case 5:
cout &lt;&lt; &quot; Priority - &#39;Non-serious&#39; &quot; &lt;&lt; endl;
break;
case 10:
cout &lt;&lt; &quot; Priority - &#39;Serious&#39; &quot; &lt;&lt; endl;
break;
default:
cout &lt;&lt; &quot;Priority not found&quot; &lt;&lt; endl;

}
}
}
void dequeue() { //remove the data from front
if(f == -1) {
cout&lt;&lt;&quot;Queue is Empty&quot;;
}
else {
cout&lt;&lt;&quot;deleted Element =&quot;&lt;&lt;Q[f]&lt;&lt;endl;
cout&lt;&lt;&quot;Its Priority = &quot;&lt;&lt;Pr[f]&lt;&lt;endl;
if(f==r) f = r = -1;
else f++;
}
}
int main() {
string data;
int opt,n,i,p;
cout&lt;&lt;&quot;Enter Your Choice:-&quot;&lt;&lt;endl;
do {
cout &lt;&lt; &quot;1 for Insert the Data in Queue&quot; &lt;&lt; endl &lt;&lt; &quot;2 for show
the Data in Queue &quot; &lt;&lt; endl &lt;&lt; &quot;3 for Delete the data from the Queue&quot;

&lt;&lt; endl &lt;&lt; &quot;0 for Exit&quot;&lt;&lt; endl;
cin &gt;&gt; opt;
switch(opt) {
case 1:

cout &lt;&lt; &quot;Enter the number of patinent&quot; &lt;&lt; endl;
cin &gt;&gt; n;
i = 0;
while(i &lt; n) {
cout &lt;&lt; &quot;Enter your name of the patient :

&quot;;

cin &gt;&gt; data;
ifnotdoagain:
cout &lt;&lt; &quot;Enter your Prioritys (0:

serious, 1: non-serious, 2: genral checkup) : &quot;;
cin &gt;&gt; p;
switch(p) {
case 0:
enqueue(data,SERIOUS);
break;
case 1:
enqueue(data,NONSERIOUS);
break;
case 2:
enqueue(data,CHECKUP);
break;
default:
goto ifnotdoagain;

}
i++;
}
break;
case 2:
print();
break;
case 3:
dequeue();
break;
case 0:
cout &lt;&lt; &quot;Bye Bye !&quot; &lt;&lt; endl;
break;
default:
cout&lt;&lt;&quot;Incorrect Choice&quot;&lt;&lt;endl;
}
}while(opt!=0);
return 0;
}
