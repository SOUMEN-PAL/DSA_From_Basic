  for(int i = 0 ; i<V ; i++){
        if(visited[i] == false){
            DFS(adj , visited , ap , discovery , parent , low , i , 0 , V);
        }
    }