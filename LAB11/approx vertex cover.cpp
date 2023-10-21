#include <iostream>
#include <vector>

class VCP {
private:
    int V;
    
public:
    VCP(int v) {
        V = v;
    }
    
    void printVertexCover(std::vector<std::vector<int>> &g) {
        std::vector<bool> visited(V, false);
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                for (int j = 0; j < V; j++) {
                    if (g[i][j] == 1 && !visited[j]) {
                        visited[i] = true;
                        visited[j] = true;
                        break;
                    }
                }
            }
        }
        
        std::cout << std::endl;
        
        for (int j = 0; j < V; j++) {
            if (visited[j]) {
                std::cout << j << " ";
            }
        }
        
        std::cout << std::endl;
    }
};

int main() {
    VCP g(4);
    
    std::vector<std::vector<int>> graph = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };
    
    std::cout << std::endl;
    g.printVertexCover(graph);
    std::cout << std::endl;
    
    return 0;
}
