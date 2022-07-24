ll dis[MAX_N][MAX_N];
void init(){
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)dis[i][i]=0;
}
void add_edge(int a,int b,int c){// node : node : dis
    dis[a][b]=min(dis[a][b],c);
    dis[b][a]=dis[a][b];
}
void Floyd_Warshell(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(i==k)continue;
            for(int j=i+1;j<=n;j++){
                if(j==k)continue;
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                    dis[j][i]=dis[i][j];
                }
            }
        }
    }
}