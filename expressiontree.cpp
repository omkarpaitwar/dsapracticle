#include &lt;iostream&gt;
#include &lt;cstring&gt; // Use &lt;cstring&gt; instead of
&lt;string.h&gt;
using namespace std;

struct node {
char data;
node *left, *right;
};

class tree {
char prefix[20];

public:
node *top;
tree() { top = nullptr; }

void expression(char[]);
void preorder(node *);
void inorder(node *);
void non_rec_postorder(node *);
void del(node *&amp;);
};

// Stack implementation for expression tree
class stack1 {
node *data[30];
int top;

public:
stack1() { top = -1; }

bool empty() { return (top == -1); }

void push(node *p) { data[++top] = p; }

node *pop() { return (empty() ? nullptr :
data[top--]); }
};

// Function to construct expression tree from
prefix expression
void tree::expression(char prefix[]) {
stack1 s;
node *t1, *t2;
int len = strlen(prefix);

for (int i = len - 1; i &gt;= 0; i--) {

top = new node;
top-&gt;left = nullptr;
top-&gt;right = nullptr;
top-&gt;data = prefix[i];

if (isalpha(prefix[i])) { // If operand, push
into stack
s.push(top);
} else if (prefix[i] == &#39;+&#39; || prefix[i] == &#39;*&#39; ||
prefix[i] == &#39;-&#39; || prefix[i] == &#39;/&#39;) { // If operator
t1 = s.pop();
t2 = s.pop();
top-&gt;left = t1;
top-&gt;right = t2;
s.push(top);
}

}
top = s.pop(); // Final root node
}

// Preorder Traversal
void tree::preorder(node *root) {
if (root) {
cout &lt;&lt; root-&gt;data &lt;&lt; &quot; &quot;;
preorder(root-&gt;left);
preorder(root-&gt;right);
}
}

// Inorder Traversal
void tree::inorder(node *root) {

if (root) {
inorder(root-&gt;left);
cout &lt;&lt; root-&gt;data &lt;&lt; &quot; &quot;;
inorder(root-&gt;right);
}
}

// Non-recursive postorder traversal
void tree::non_rec_postorder(node *top) {
if (!top) return;

stack1 s1, s2;
node *T = top;
cout &lt;&lt; &quot;\nPostorder Traversal: &quot;;

s1.push(T);
while (!s1.empty()) {
T = s1.pop();
s2.push(T);
if (T-&gt;left) s1.push(T-&gt;left);
if (T-&gt;right) s1.push(T-&gt;right);
}

while (!s2.empty()) {
top = s2.pop();
cout &lt;&lt; top-&gt;data &lt;&lt; &quot; &quot;;
}
cout &lt;&lt; endl;
}

// Function to delete the tree
void tree::del(node *&amp;node) {
if (!node) return;

del(node-&gt;left);
del(node-&gt;right);

cout &lt;&lt; &quot;Deleting node: &quot; &lt;&lt; node-&gt;data &lt;&lt;
endl;
delete node;
node = nullptr;
}

int main() {
tree t;
int choice;

char expr[20];

do {
cout &lt;&lt; &quot;\nMenu:&quot;;
cout &lt;&lt; &quot;\n1. Enter Prefix Expression&quot;;
cout &lt;&lt; &quot;\n2. Construct Expression Tree&quot;;
cout &lt;&lt; &quot;\n3. Display Tree (Preorder &amp;
Inorder)&quot;;
cout &lt;&lt; &quot;\n4. Postorder Traversal&quot;;
cout &lt;&lt; &quot;\n5. Delete Tree&quot;;
cout &lt;&lt; &quot;\n6. Exit&quot;;
cout &lt;&lt; &quot;\nEnter your choice: &quot;;
cin &gt;&gt; choice;

switch (choice) {
case 1:

cout &lt;&lt; &quot;Enter prefix Expression: &quot;;
cin &gt;&gt; expr;
break;
case 2:
t.expression(expr);
cout &lt;&lt; &quot;Expression tree constructed
successfully!&quot; &lt;&lt; endl;
break;
case 3:
if (t.top) {
cout &lt;&lt; &quot;\nPreorder traversal: &quot;;
t.preorder(t.top);
cout &lt;&lt; &quot;\nInorder traversal: &quot;;
t.inorder(t.top);
cout &lt;&lt; endl;
} else {

cout &lt;&lt; &quot;Tree does not exist!&quot; &lt;&lt;
endl;
}
break;
case 4:
t.non_rec_postorder(t.top);
break;
case 5:
t.del(t.top);
if (!t.top)
cout &lt;&lt; &quot;Tree deleted
successfully!&quot; &lt;&lt; endl;
break;
case 6:
cout &lt;&lt; &quot;Exiting...&quot; &lt;&lt; endl;
break;

default:
cout &lt;&lt; &quot;Invalid choice! Please try
again.&quot; &lt;&lt; endl;
}
} while (choice != 6);

return 0;
}
