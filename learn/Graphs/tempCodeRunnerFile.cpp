    int v = 6;
    vector<int> adj[v];
    addEdge(adj , 0 , 1);
    addEdge(adj , 1 , 2);
    addEdge(adj , 1 , 3);
    addEdge(adj , 3 , 4);
    addEdge(adj , 4 , 5);
    addEdge(adj , 5 , 1);

    cout << "Adjacency List Array Representation of Graph" << endl;
    printList(adj , v);

    cout<<endl;