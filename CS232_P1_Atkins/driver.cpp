/**************************************************************************************************
*
*   File name :			driver.cpp
*
*	Programmer:  		Jeremy Atkins
*
*   Driver file initializing a Maze object and setting up a menu allowing the user to manipulate
*	the graph by adding and removing vertices and edges, as well as printing the graph either
*	simply, breadth first, or depth first. Also includes the ability to find the shortest
*	path between two nodes using Dijkstra's algorithm
*   Date Written:		in the past
*
*   Date Last Revised:	3/14/2019
****************************************************************************************************/
#include <iostream>
#include <string>
#include "graph.h"

using namespace std;
int main()
{
	int choice;			//menu option
	double distance;	//shortest path

	//main graph
	Graph<vertex<string, int>, edgeRep<string, int>> graph;

	//vertices and the edge passed to the graph by the user
	vertex<string, int> firstVertex;
	vertex<string, int> secondVertex;
	edgeRep<string, int> edge;
	
	//start do-while
	do
	{
		//menu options
		cout << "Graph Options." << endl;
		cout << "1. Read a graph from a file." << endl;
		cout << "2. Test if a vertex is in the graph." << endl;
		cout << "3. Test if a unidirectional edge exists between two vertices." << endl;
		cout << "4. Test if a bidirectional edge exists between two vertices." << endl;
		cout << "5. Add a vertex." << endl;
		cout << "6. Add a unidirectional edge." << endl;
		cout << "7. Add a bidirectional edge." << endl;
		cout << "8. Delete a vertex." << endl;
		cout << "9. Delete a unidirectional edge." << endl;
		cout << "10. Delete a bidirectional edge." << endl;
		cout << "11. Print the graph." << endl;
		cout << "12. Print the breadth first traversal of the graph." << endl;
		cout << "13. Print the depth first traversal of the graph." << endl;
		cout << "14. Find the shortest path between two vertices." << endl;
		cout << "15. Exit." << endl;
		cout << "Enter the number of the option to select: ";
		cin >> choice;


		while (cin.fail() || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Incorrect input.\nPlease enter an valid option number: " << endl;

			cin >> choice;
		}

		//begin main menu switch
		switch (choice)
		{
		//get a graph from a file
		case 1:
			graph.GetGraph();
			cout << "\n\n" << endl;
			break;

		//test if a vertex is in the graph
		case 2:
			cout << "Enter the name of the vertex to test (-1 to cancel): ";
			cin >> firstVertex.name;
			if (firstVertex.name == "-1")
			{
				cout << "\n\n" << endl;
				break;
			}
			if (graph.isVertex(firstVertex) != -1)
				cout << firstVertex.name << " is in the graph.\n\n" << endl;
			else
				cout << firstVertex.name << " is not in the graph.\n\n" << endl;
			break;

		//test if a unidirectional edge is in the graph
		case 3:
			cout << "Enter the names of the two vertices to determine if a unidirectional edge exists between them. (-1 to cancel):" << endl;
			cout << "Vertex 1: ";
			cin >> firstVertex.name;
			if (firstVertex.name == "-1")
			{
				cout << "\n\n" << endl;
				break;
			}
			if (graph.isVertex(firstVertex) == -1)
			{
				cout << firstVertex.name << " is not in the graph.\n\n" << endl;
				break;
			}
			cout << "Vertex 2: ";
			cin >> secondVertex.name;
			if (secondVertex.name == "-1")
			{
				cout << "\n\n" << endl;
				break;
			}
			if (graph.isVertex(secondVertex) == -1)
			{
				cout << secondVertex.name << " is not in the graph.\n\n" << endl;
				break;
			}
		
			if (graph.isUniEdge(firstVertex, secondVertex) == 1)
				cout << "\n\nA unidirectional edge exists between " << firstVertex.name << " and " << secondVertex.name << endl;
			
			cout << "\n\n" << endl;
			break;


		//test if a bidirectional edge is in the graph
		case 4:
			cout << "Enter the names of the two vertices to determine if a bidirectional exists between them. (-1 to cancel):" << endl;
			cout << "Vertex 1: ";
			cin >> firstVertex.name;
			if (firstVertex.name == "-1")
			{
				cout << "\n\n" << endl;
				break;
			}
			if (graph.isVertex(firstVertex) == -1)
			{
				cout << firstVertex.name << " is not in the graph.\n\n" << endl;
				break;
			}
			cout << "Vertex 2: ";
			cin >> secondVertex.name;
			if (secondVertex.name == "-1")
			{
				cout << "\n\n" << endl;
				break;
			}
			if (graph.isVertex(secondVertex) == -1)
			{
				cout << secondVertex.name << " is not in the graph.\n\n" << endl;
				break;
			}

			if (graph.isBiDirEdge(firstVertex, secondVertex) == 1)
				cout << "\n\nA bidirectional edge exists between " << firstVertex.name << " and " << secondVertex.name << endl;
			
			cout << "\n\n" << endl;
			break;


		//add a vertex to the graph
		case 5:
			cout << "Enter the name of the vertex to add (-1 to cancel): ";
			cin >> firstVertex.name;
			if (firstVertex.name == "-1")
			{
				cout << "\n\n" << endl;
				break;
			}
			if(graph.AddVertex(firstVertex)==0)
				cout << firstVertex.name << " added to the graph." << endl;
			cout << "\n\n" << endl;
			break;

		//add a unidirectional edge to the graph
		case 6:
			cout << "Enter the names of the two vertices to add a unidirectional edge between. (-1 to cancel)" << endl;
			cout << "Starting vertex: ";
			cin >> firstVertex.name;
			if (firstVertex.name == "-1")
			{
				cout << "\n\n" << endl;
				break;
			}
			
			cout << "Ending vertex: ";
			cin >> secondVertex.name;
			if (secondVertex.name == "-1")
			{
				cout << "\n\n" << endl;
				break;
			}
			cout << "Enter the distance between the two vertices: ";
			edge.name = firstVertex.name;
			cin >> edge.weight;
			if(graph.AddUniEdge(firstVertex, secondVertex, edge)==1)
				cout << "\n\nUnidirectional edge added between " << firstVertex.name << " and " << secondVertex.name << endl;
			cout << "\n\n" << endl;
			break;

		//add a bidirectional edge to the graph
		case 7:
			cout << "Enter the names of the two vertices to add a bidirectional edge between. (-1 to cancel):" << endl;
			cout << "Vertex 1: ";
			cin >> firstVertex.name;
			if (firstVertex.name == "-1")
			{
				cout << "\n\n" << endl;
				break;
			}
			
			cout << "Vertex 2: ";
			cin >> secondVertex.name;
			if (secondVertex.name == "-1")
			{
				cout << "\n\n" << endl;
				break;
			}
			cout << "Enter the distance between the two vertices: ";
			edge.name = firstVertex.name;

			cin >> edge.weight;
			graph.AddBiDirEdge(firstVertex, secondVertex, edge);
			cout << "\n\nBidirectional edge added between " << firstVertex.name << " and " << secondVertex.name << endl;
			cout << "\n\n" << endl;
			break;

		//delete a vertex from the graph
		case 8:
			cout << "Enter the name of the vertex to delete (-1 to cancel): ";
			cin >> firstVertex.name;
			if (firstVertex.name == "-1")
			{
				cout << "\n\n" << endl;
				break;
			}
			if (graph.isVertex(firstVertex) == -1)
			{
				cout << firstVertex.name << " is not in the graph.\n\n" << endl;
				break;
			}
			if (graph.DeleteVertex(firstVertex) == 0)
				cout << "\n\n" << firstVertex.name << " deleted." << endl;
			cout << "\n\n" << endl;
			break;

		//delete a unidirectional edge from the graph
		case 9:
			cout << "Enter the names of the two vertices to delete a unidirectional edge between. (-1 to cancel):" << endl;
			cout << "Vertex 1: ";
			cin >> firstVertex.name;
			if (firstVertex.name == "-1")
			{
				cout << "\n\n" << endl;
				break;
			}
			if (graph.isVertex(firstVertex) == -1)
			{
				cout << firstVertex.name << " is not in the graph.\n\n" << endl;
				break;
			}
			cout << "Vertex 2: ";
			cin >> secondVertex.name;
			if (secondVertex.name == "-1")
			{
				cout << "\n\n" << endl;
				break;
			}
			if (graph.isVertex(secondVertex) == -1)
			{
				cout << secondVertex.name << " is not in the graph.\n\n" << endl;
				break;
			}
			if(graph.DeleteUniEdge(firstVertex, secondVertex)==1)
				cout << "\n\nEdge deleted between " << firstVertex.name << " and " << secondVertex.name << endl;
			break;

		//delete a bidirectional edge from the graph
		case 10:
			cout << "Enter the names of the two vertices to delete a bidirectional edge between. (-1 to cancel):" << endl;
			cout << "Vertex 1: ";
			cin >> firstVertex.name;
			if (firstVertex.name == "-1")
			{
				cout << "\n\n" << endl;
				break;
			}
			if (graph.isVertex(firstVertex) == -1)
			{
				cout << firstVertex.name << " is not in the graph.\n\n" << endl;
				break;
			}
			cout << "Vertex 2: ";
			cin >> secondVertex.name;
			if (secondVertex.name == "-1")
			{
				cout << "\n\n" << endl;
				break;
			}
			if (graph.isVertex(secondVertex) == -1)
			{
				cout << secondVertex.name << " is not in the graph.\n\n" << endl;
				break;
			}
			if (graph.DeleteBiDirEdge(firstVertex, secondVertex) == 1)
				cout << "\n\nEdge deleted between " << firstVertex.name << " and " << secondVertex.name << endl;
			cout << "\n\n" << endl;
			break;

		//print the graph
		case 11:
			graph.SimplePrintGraph();
			cout << "\n\n" << endl;
			break;

		//breadth first traversal
		case 12:
			cout << "Breadth first traversal:" << endl;
			cout << "Enter the name of the vertex to start at (-1 to cancel): ";
			cin >> firstVertex.name;
			if (firstVertex.name == "-1")
			{
				cout << "\n\n" << endl;
				break;
			}
			if (graph.isVertex(firstVertex) == -1)
			{
				cout << firstVertex.name << " is not in the graph.\n\n" << endl;
				break;
			}
			cout << "\n\nThe Breadth First Traversal of the graph is: " << endl;
			graph.BFTraversal(firstVertex);
			cout << "\n\n" << endl;
			break;

		//depth first traversal
		case 13:
			cout << "Depth first traversal:" << endl;
			cout << "Enter the name of the vertex to start at (-1 to cancel): ";
			cin >> firstVertex.name;
			if (firstVertex.name == "-1")
			{
				cout << "\n\n" << endl;
				break;
			}
			if (graph.isVertex(firstVertex) == -1)
			{
				cout << firstVertex.name << " is not in the graph.\n\n" << endl;
				break;
			}
			cout << "\n\nThe Depth First Traveral of the graph is: " << endl;
			graph.DFTraversal(firstVertex);
			cout << "\n\n" << endl;
			break;

		//shortest path
		case 14:
			cout << "Enter the names of the two vertices to find the shortest path between them. (-1 to cancel)";
			cout << "\nVertex 1: ";
			cin >> firstVertex.name;
			if (firstVertex.name == "-1")
			{
				cout << "\n\n" << endl;
				break;
			}
			if (graph.isVertex(firstVertex) == -1)
			{
				cout << firstVertex.name << " is not in the graph.\n\n" << endl;
				break;
			}
			
			cout << "Vertex 2: ";
			cin >> secondVertex.name;
			if (graph.isVertex(secondVertex) == -1)
			{
				cout << secondVertex.name << " is not in the graph.\n\n" << endl;
				break;
			}
			distance = graph.ShortestDistance(firstVertex, secondVertex);
			if (distance != -1)
				cout << "\n\nThe shortest distance between " << firstVertex.name << " and " << secondVertex.name << " is " << distance << "\n\n" << endl;
			else
				cout << "\n\nThe shortest distance between " << firstVertex.name << " and " << secondVertex.name << " is nonexistant.\n\n" << endl;
			break;

		//exit
		case 15:
			cout << "Exitting." << endl;
			return 0;
			break;

		//default
		default:
			cout << "\n\nPlease enter a valid option number: " << endl;
			break;

		}
	} while (choice != 15);		//end do-while
	
	return 0;
}