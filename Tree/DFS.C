#include <stdio.h>
#define MAXSIZE 100
typedef char VertexType;
typedef int EdgeType;

typedef struct {
    VertexType vertex[MAXSIZE];
    EdgeType arc[MAXSIZE][MAXSIZE];
    int vertex_num;
    int edge_num;
} Mat_Grph;
int visited[MAXSIZE];
void createGraph(Mat_Grph *G) {
    G->vertex_num = 8;
    G->edge_num = 12;
    G->vertex[0] = 'A';
    G->vertex[1] = 'B';
    G->vertex[2] = 'C';
    G->vertex[3] = 'D';
    G->vertex[4] = 'E';
    G->vertex[5] = 'F';
    G->vertex[6] = 'G';
    G->vertex[7] = 'H';
    for(int i = 0; i < G->vertex_num; i++){
        for(int j = 0; j < G->vertex_num; j++){
            G->arc[i][j] = 0;
        }
    }
    //A-B A-C A-D
    G->arc[0][1] = 1;
    G->arc[0][2] = 1;
    G->arc[0][3] = 1;
    //B-E B-F
    G->arc[1][4] = 1;
    G->arc[1][5] = 1;
    //C-D C-F C-G
    G->arc[2][3] = 1;
    G->arc[2][5] = 1;
    G->arc[2][6] = 1;
    //D-H
    G->arc[3][7] = 1;
    //E-F
    G->arc[4][5] = 1;
    //F-G
    G->arc[5][6] = 1;
    //G-H
    G->arc[6][7] = 1;
    for (int i = 0; i < G->vertex_num; i++) {
        for (int j = 0; j < G->vertex_num; j++) {
            G->arc[j][i] = G->arc[i][j];
        }
    }
}
void dfs(Mat_Grph G, int i) {
    visited[i] = 1;
    printf("%c ", G.vertex[i]);
    for (int j = 0; j < G.vertex_num; j++) {
        if (G.arc[i][j] == 1 && visited[j] != 1) {
            dfs(G,j);
        }
    }
}
int main() {
    Mat_Grph G;
    createGraph(&G);
    dfs(G,0);
    return 0;
}