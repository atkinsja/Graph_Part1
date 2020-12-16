/**************************************************************************************************
*
*   File name :			graph.h
*
*	Programmer:  		Jeremy Atkins
*
*   Header file for the Graph class, implemented in graph.t
*
*   Date Written:		in the past
*
*   Date Last Revised:	3/14/2019
*
*	Class Name:		Graph
*
*	Structs:
*		edgeRep				a struct holding a vertex name and an edge weight
*		vertex				a struct holding a name, if the vertex has been visited,
*							a minimum distance, a previous vertex, and a listof edgeReps
*
*	Private data members:
*		bool populated		determines whether a graph has data in it or not
*		
*	Protected data members:
*		vector<V> G			a vector of vertex structs, used to hold all of the vertices of the graph
*
*	Private member function:
*		DFUtility			utility function for the recursion in the depth first traversal
*		
*	Public member functions:
*		Graph				constructor for a Graph object
*		~Graph				destructor for a Graph object
*		isVertex			tests whether a vertex is in the graph
*		isUniEdge			tests whether a directed edge connects two vertices
*		isBiDirEdge			tests whether an undirected edge connects two vertices
*		AddVertex			adds a vertex to the graph
*		DeleteVertex		removes a vertex from the graph
*		AddUniEdge			adds a directed edge between two vertices
*		DeleteUniEdge		removes a directed edge from between two vertices
*		AddBiDirEdge		adds an undirected edge between two vertices
*		DeleteBiDirEdge		removes an undirected edge between two vertices
*		SimplyPrintGraph	prints the graph without a specific traversal
*		ShortestDistance	finds the shortest distance between two vertices as well
*							as the path between them (uses Dijkstra's algorithm)
*		GetGraph			reads a graph in from a formatted file
*		BFTraversal			breadth first traversal of the graph
*		DFTraversal			depth first traversal of the graph
*		
*
****************************************************************************************************/

#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <list>
#include <queue>
#include <stack>




template <class V, class W> // V is the vertex class; W is edge weight class
struct edgeRep
{
	V name;               // Vertex name
	W weight;             // Edge weight
};

template <class V, class W>
struct vertex           // Array cell structure for graph 
{
	typedef edgeRep<V, W> edge;
	V name;               // Vertex name
	int visited;          // Used during traversal, Breadth-First or Depth-First
	std::list<edge> edgelist; 	// Pointer to edge list
	double minDist;
	V prev;
};

template <class V, class W>
class Graph
{
protected:
	std::vector<V> G; // Main graph array for adjacency list representation
	
						 //  protected member functions

public:
	Graph();   // Constructor
			   // . . . other constructors
	~Graph();  // Destructor
			   //Predicates:
	int isVertex(V &v);  // Tests whether v is a vertex in the graph
	int isUniEdge(V &v1, V &v2); // Tests whether edge <v1,v2> in graph
	int isBiDirEdge(V &v1, V &v2);// Tests whether edge (v1,v2) in graph
								  // The following functions return -1 for failure, non-neg for success
	
	int AddVertex(V &v);

	// Adds vertex with name v to the graph, if v is not already in 
	// graph, and returns the index where the vertex is stored.
	int DeleteVertex(V &v);
	// Deletes vertex with name v from the graph, if v is in the graph.
	// If there are any edges incident on the vertex, these edges
	// are deleted also.
	int AddUniEdge(V &v1, V &v2, W &wt);
	// Adds the directed edge <v1,v2,wt> to the graph; adds the vertices
	// to the graph if the vertices are not already part of the graph    
	int DeleteUniEdge(V &v1, V &v2);
	// Deletes the directed edge <v1,v2> (any weight) from the graph, if 
	// it is in the graph. The vertices are not deleted from the graph,
	// only the edge.
	int AddBiDirEdge(V &v1, V &v2, W &wt);
	// Adds the bi-directional edge (v1,v2,wt) to the graph; adds the
	// vertices to the graph if the vertices are not already part of 
	// the graph
	int DeleteBiDirEdge(V &v1, V &v2);
	// Deletes the bi-directional edge (v1,v2) (any weight) from the 
	// graph, if it is in the graph. The vertices are not deleted from 
	// the graph, only the edge.
	void SimplePrintGraph();
	// Prints the list of vertices in the graph, and for each vertex,
	// prints the list of edges in proper parenthesized notation, namely
	// (v1,v2,wt) or <v1,v2,wt>.  NOTE: This is not a traversal.
	double ShortestDistance(V &v1, V &v2);
	//returns the shortest distance from vertex 1 to vertex 2
	// use Dijkstra
	void GetGraph();
	// Retrieves a graph from a special file and sets up the adjacency
	// list for the graph.  I am supplying 1 such files.The program
	// will be able to read any graph that is in the same format:
	// graph node followed by any adjacent nodes with followed by distance/wieigh 
	// to the node.The adjacency entry is terminated by #
	void BFTraversal(V &v);
	// Performs Breadth First Traversal with trace information printed 
	void DFTraversal(V &v);
	//Performs a recursive Depth First Traversal of the graph starting at 
	//specified vertex(parameter); prints trace information.
private:
	void DFUtility(V &v);
	bool populated;
};
#include "graph.t"
#endif // !GRAPH_H

