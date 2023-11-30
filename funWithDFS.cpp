#include "funWithDFS.h"


//=============================================================================
// Exercise 2.1: Nodes at distance k
//=============================================================================
// Subexercise 2.1.1: Nodes at distance k (DFS)
//=============================================================================
// TODO
void nodesAtDistanceDFSVisit(const Graph<Person> *g, Vertex<Person> *v, int k, vector<Person> &res);

vector<Person> FunWithDFS::nodesAtDistanceDFS(const Graph<Person> *g, const Person &source, int k) {
    vector<Person> res;
    auto vset = g->getVertexSet();
    for (auto i : vset) {
        i->setVisited(false);
    }
    auto src = g->findVertex(source);
    if (src == NULL) {
        return res;
    }
    nodesAtDistanceDFSVisit(g,src,k,res);
    return res;
}

// TODO
void nodesAtDistanceDFSVisit(const Graph<Person> *g, Vertex<Person> *v, int k, vector<Person> &res) {
    v->setVisited(true);
    if (k == 0) {
        res.push_back(v->getInfo());
    }
    for (auto i : v->getAdj()) {
        auto j = i.getDest();
        if (!j->isVisited()) {
            nodesAtDistanceDFSVisit(g, j, k - 1, res);
        }
    }
}


//=============================================================================
// Exercise 2.3: Directed Acyclic Graph
//=============================================================================
// TODO
bool dfsIsDAG(Vertex<int> *v);
bool FunWithDFS::isDAG(Graph<int> g) {
    return false;
}

// TODO
bool dfsIsDAG(Vertex<int> *v) {
    return false;
}
