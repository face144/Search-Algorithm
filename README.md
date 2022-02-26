# Intro
 This repo is a search algorithm that represents an artifical intelligence. It creates a node grid and searches through it's connections until it reaches the desired node.
 The nodes and their connections are given through a text file.
 
 <br>
 
# How to use the search algorithms
 Start by creating a project in your text editor/IDE and adding the files from this repo to your project.
 
 You must have a text file with the total nodes and their connections to other nodes (see "text.txt" for example).
 
 To use the search algorithms you must create an instance of the "Search" class. The Search class has the following members:
  - void BreathFirstSearch (int startNodeID);
  - void DepthFirstSearch (int startNodeID);
  
 Important: A node's ID is the number you used to reference it in the .txt file containing the node's connections.
 
 <br>
 
# Important notes
 This repo is still a Work-In-Progress, feel free to contribute to this.
 As of right now there are only breath-first-search and depth-first-search algorithms.
 
 <br>
 
# Documentation (for developers)
 General information: <br></br>
  The outter layer object (Search) recieves an input file with information about the node grid and it's connections. The input file has a specific syntax, you must write the total nodes and every connection in a node, the syntax is as follow:
   - "t 20" (If there are 20 nodes in total, should only be written once);
   - "c 1 2 3" (If node number 1 is connected to node number 2 and going through that connection has a cost of 3).
  Be aware that you must write every connection and the total nodes in separate lines.
 
  <br></br>
  
 Connection: <br></br>
  A connection is a struct containing information about the connected node and the cost of going through that node.
   
  Members: <br>
   
   - int cost. Cost of the connection;
   - Node* connectedNode. Pointer to the connected node.
  
  <br></br>
  <br></br>
  
 Node: <br></br>
  A node is an object that contains information about their connections and it's own ID. The ID of a node is used (in most cases) to reference a node.
  
  Members: <br>
  
   - AddConnection (Node* node, int cost = 1). It takes the end node of a connection and it's cost to add it to the object's connection list.
   - GetConnections(). Returns a vector of a node's connection list.
   - GetID(). Returns the node's ID.

<br></br>
<br></br>

 Grid: <br></br>
  A grid is an object containing a set of nodes. It represents the total space where the search will happen.

Members: <br>

   - GetLowestCostConnection (int currentNodeID). It takes the node you are currently in and searches through the connection list to find the node that has the lowest connection cost.

<br></br>
<br></br>

Search: <br></br>
  A Search is an object that would represent the AI searching through the nodes. It currently contains only one type of search (Depth-First Search) and it expands the lowest cost nodes first.

 Members: <br>
 
  - (Constructor) Search(string filename). It initializes the nodes and grid through the text file.
  - BreathFirstSearch (int startNodeID);
  - DepthFirstSearch (int startNodeID).
