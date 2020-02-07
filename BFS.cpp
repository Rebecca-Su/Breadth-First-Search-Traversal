//In this code, the purpose is to determine the minimum amount of edge between node 1 and node n in an undirected graph.
//Breadth first search traversal was used to solve the problem.
//All inputs are assumed to follow the correct input format.

#include <iostream>
#include <list>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::queue;

int main();
// in_list: array of lists to be modified
// in_node1: first node of the edge relation
// in_node2: second node of the edge relation
void addEdge(list<int> in_list[], int in_node1, int in_node2);
//n_nodes: number of nodes
//in_list: array of lists for determining the level of the nodes
int detLevel(int n_nodes, list<int> in_list[]);

int main() {
    int num_test, num_nodes, num_edges, node_1, node_2;
    
    //first input will be the number of test cases
    cin >> num_test;
    
    while(!cin.eof())
    {
        //input determing the total number of nodes in the graph and
        //the amount of edge relations that will be inputted
        cin >> num_nodes >> num_edges;
        
        //creating an array of int list for graph representation
        list<int> a_node_list[num_nodes];
        
        //set edge relations in A
        //n_Edges is also the amount of lines determining edge relations, thus it is the limit for the loop
        for(int i = 0; i < num_edges; i++)
        {
            //assumes the input will always have two values per line
            cin >> node_1 >> node_2;
            addEdge(a_node_list, node_1, node_2);
        }
        
        cout << detLevel(num_nodes, a_node_list) << endl;
    }
    return 0;
}

void addEdge(list<int> in_list[], int in_node1, int in_node2)
{
    in_list[in_node1 - 1].push_front(in_node2);
    in_list[in_node2 - 1].push_front(in_node1);
}

//determines the levels of each node and returns the level of the nth node
//the level is the same as the least number of edges between 1 and nth node
int detLevel(int n_nodes, list<int> in_list[])
{
    int a_level[n_nodes] = {0};
    //boolean list for recording if a node has been visited
    bool a_visited[n_nodes] = {false};
    
    //queue is used because it follows the first-in-first-out structure
    queue<int> q;
    
    //node 1 will always be the source node. Also ensures the queue is not empty for the while loop
    //can be modified to use any node as source node, but is not necessary in the current implementation
    q.push(1);
    
    a_visited[0] = true;
    
    while(!q.empty())
    {
        //gets and removes the front of the queue
        int p = q.front();
        q.pop();
        
        for(int i : in_list[p - 1])
        {
            //condition for processing only the unvisited nodes to prevent looping
            if(a_visited[i - 1] != true)
            {
                //pushes all unvisited neighbouring nodes of the front node into the queue
                q.push(i);
                a_visited[i - 1] = true;
                
                //the level of the neighbouring nodes will be one more than the front node
                a_level[i - 1] = a_level[p - 1] + 1;
            }
        }
    }
    
    //return the level of the nth node
    //can be modified to return the level of any node, but not necessary for this implementation.
    return a_level[n_nodes - 1];
}
