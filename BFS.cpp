#include <iostream>
#include <list>
#include <queue>
 
using namespace std;
 
int main();
void createGraph(list<int> A[], int n_Nodes, int n_Edges);
int detLevel(int n_Nodes, list<int> A[], bool v[]);
 
int main() {
    int num_Test, num_Nodes, num_Edges;
    
    cin >> num_Test;
    
    while(!cin.eof())
    {
        cin >> num_Nodes >> num_Edges;
        
        list<int> A[num_Nodes];
        bool visited[num_Nodes] = {false};
        
        createGraph(A, num_Nodes, num_Edges);
        cout << detLevel(num_Nodes, A, visited) << endl;
    }
    return 0;
}
 
void createGraph(list<int> A[], int n_Nodes, int n_Edges)
{
    int node_1, node_2;
    
    for(int i = 0; i < n_Edges; i++)
    {
        cin >> node_1 >> node_2;
        A[node_1 - 1].push_front(node_2);
        A[node_2 - 1].push_front(node_1);
    }
}
 
int detLevel(int n_Nodes, list<int> A[], bool v[])
{
    
    int level[n_Nodes] = {0};
    queue<int> q;
    q.push(1);
    v[0] = true;
    
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        
        for(int i : A[p - 1])
        {
            if(v[i - 1] != true)
            {
                q.push(i);
                v[i - 1] = true;
                level[i - 1] = level[p - 1] + 1;
            }
        }
    }
    return level[n_Nodes - 1];
}
Language: C++
