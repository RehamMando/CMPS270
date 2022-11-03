#include <iostream>
#include <map>
#include <vector>
using std::vector;
using std::cout; using std::endl;
using namespace std;

class Graph {
    protected:
    map <int, vector <int> > outgoing;

    public:
        Graph(const vector <int >& startPoints, const vector <int >& endPoints);
       int numOutgoing(const int nodeID) const;
       const vector <int >& adjacent(const int nodeID) const;
       vector <int>& hasCycle(const int nodeID);
       vector <int>& hasCycle(const int nodeID, int var, int numberOfOcurrences);
       int numberOfOcurrences = 0;
};


// Specification:
// Graph::Graph(const vector <int> &startPoints, const vector <int> &endPoints)
// requires: 2 vectors of positive integers {including 0}
// effects: add to the outgoing map all the outgoing nodes in the end vector from each node in the start vector.
// this is done by adding an outgoing node in the end vector i to the one in start at i.


// Test Cases:
// A)input valid vectors
//        vector<int> start = { 0,0,1,0,3 };
//        vector<int> end =   { 1,2,2,1,0 };
//        Graph graph = Graph(start, end);
//              expected output: vaild {add to the outgoing map}
// B)input invaled type vectors
//        vector<char> start = { '0','0','1','0','3' };
//        vector<char> end =   { '1','2','2','1','0' };
//        Graph graph = Graph(start, end);
//              expected output: invaild {does not compile}
// C)input 2 vectors having same node IDs
//        vector<int> start = { 0,0,1,0,3 };
//        vector<int> end =   { 0,0,1,0,3 };
//        Graph graph = Graph(start, end);
//              expected output: vaild {add to the outgoing map}
// D)2 empty vectors
//        vector<int> start = {};
//        vector<int> end = {};
//        Graph graph = Graph(start, end);
//              expected output: vaild {do not add anything}
// D)Non equally size vectors
//        1)end less than start
//              vector<int> start = { 0,0,1,0,3 };
//              vector<int> end =   { 1,2,2,1};
//              Graph graph = Graph(start, end);
//                     expected output: throw invalid_argument(" start and end vectors should have equal size. Retry.");
//        2)start less than end
//              vector<int> start = { 0,0,1,0 };
//              vector<int> end =   { 1,2,2,1,0 };
//              Graph graph = Graph(start, end);
//                     expected output: throw invalid_argument(" start and end vectors should have equal size. Retry.");
// E) repeat 2 values in start and end such that:
//              vector<int> start = { 0,1,1,0,3 };//1
//              vector<int> end =   { 1,2,2,1,0 };//2 repeated
//              Graph graph = Graph(start, end);
//                     expected output: valid {add to the outgoing map}

Graph::Graph(const vector <int>& startPoints, const vector <int>& endPoints) {
    if (startPoints.size() != endPoints.size()) {
        throw invalid_argument(" start and end vectors should have equal size. Retry.");
    }
    for (unsigned i = 0; i < startPoints.size(); i++) {
        int start = startPoints[i], end = endPoints[i];
        outgoing[start].push_back(end);
    }
}
// Specification:
// int Graph::numOutgoing(const int nodeID) const
// requires: an int nodeID
// effects: returns the number(positive int) of outgoing edges from nodeID

// Test Cases:
// vector<int> start = { 0,0,1,0,3 };
// vector<int> end = { 1,2,2,1,0 };
// Graph graph = Graph(start, end);
// int a =graph.numOutgoing(2);
// A)input valid node IDs
//        int a =graph.numOutgoing(0);
//        expected output: vaild {add to the outgoing map}

// B)input non existing node IDs
//    int a =graph.numOutgoing(5);
//    expected output: invaild {error message}
// C)input invaled type node ID
//        int a =graph.numOutgoing('5');
//        expected output: invaild {compilation error}

int Graph::numOutgoing(const int nodeID) const {
    return adjacent(nodeID).size();
}

// Specification:
// const vector <int > &Graph::adjacent(const int nodeID) const
// requires:an int nodeID
// effects:Returns a reference to the list of nodes to which nodeID has outgoing edges

// Test Cases:
// vector<int> start = { 0,0,1,0,3 };
// vector<int> end = { 1,2,2,1,0 };
// Graph graph = Graph(start, end);
// vector<int> adjacentNodes =graph.adjacent(0);
// A)Input valid node IDs
//        vector<int> adjacentNodes =graph.adjacent(0);
//        expected output: valid. returns the vector of outgoing edges of that node ID
// B)input non existing node IDs
//        vector<int> adjacentNodes =graph.adjacent(6);
//        expected output: invalid. error message

// C)input invaled type node ID
//        int a =graph.numOutgoing('5');
//        vector<int> adjacentNodes =graph.adjacent('6');
//        expected output: invalid. compilation error

    const vector <int >& Graph::adjacent(const int nodeID) const {
        map <int, vector <int > >::const_iterator i = outgoing.find(nodeID);
        if (i == outgoing.end()) {
            throw invalid_argument("Invalid node ID");
        }
        return i->second;
    }


// Specification:
// vector <int>& Graph::hasCycle(const int nodeID)
// requires:an int nodeID
// effects: executes hasCycle(nodeID, nodeID)
// Test Cases:
// dependent on the next function

vector <int>& Graph::hasCycle(const int nodeID) {
       return hasCycle(nodeID, nodeID, 1);
}

// Specification:
// vector <int>& Graph::hasCycle(const int nodeID, int variable,int numberOfOcurrences )
// requires:three int nodeID, variable, and positive int numberOfOcurrences
// effects:checks if a cycle exists along the input node path and return the cycle if it does

// Test Cases:
// vector<int> cycles =graph.hasCycle(0);
// 1) nodeId and variable are the same with number of occurences 1
//        expected output: the intended implementaion, returns a vector of the cycle of nodeId
// 2)non existing nodeId or/ and variable
//        expected output: invalid, error message
// 3)non equal nodeID and variable
//        expected output: dependent of the adjacent and if their is a cycle or not
// everyother varaition is dependent of the initial implementation of the graph and nodes

    vector <int>& Graph::hasCycle(const int nodeID, int variable, int numberOfOcurrences) {
        //first check if the targeted node had no edges, if so return empty array
        if (numOutgoing(variable) == 0) {
            vector <int> CycleOfNodesList = {};
            return CycleOfNodesList;
        }

        else {
            int currtentNode = nodeID;
            //int isInitialNode = variable;
            while (variable != nodeID || numberOfOcurrences == 1) { //while we did not find a loop and we are not still in the first node
                vector <int> CycleOfNodesList;
                vector <int> currentAdjacentList = adjacent(variable);
                int i = 0;
                auto j = currentAdjacentList.cbegin();
                while (j != currentAdjacentList.cend()) {  //loop around all the paths
                    while (numOutgoing(*j) != 0) {
                        hasCycle(nodeID, *j, numberOfOcurrences);
                    }
                    if (i != 0) { 
                        CycleOfNodesList.erase(j - 1); 
                    }//if their is no loop in the previous path, delete the node
                    CycleOfNodesList.push_back(*j);//add the adjacent node j to the list of the cycle of nodes
                    if (*j == nodeID)
                        break;
                    else{
                        hasCycle(nodeID, *j, numberOfOcurrences);
                    }
                    i++;
                    numberOfOcurrences == 2;
                    ++j;
                }
                // while i has more outgoing nodes loop around them searching for the initial node
            return CycleOfNodesList;//retrun the list
            }
        }
    }

int main() {
       vector<int> start = { 0,0,1,0,3 };
       vector<int> end = { 1,2,2,1,0 };
       Graph graph = Graph(start, end);
       int a = graph.numOutgoing(2);
       vector<int> adjacentNodes = graph.adjacent(0);
       vector<int> cycles = graph.hasCycle(0);
       cout << "numOutGoing " << a << endl;


}
