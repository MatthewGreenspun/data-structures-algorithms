#ifndef DC_H
#define DC_H
 
class DC {
private:
    int* ids;
    int size;
    int* treeSizes;
 
public:
    DC(int points);
 
    bool connected(int p1, int p2);
    
    void connect(int p1, int p2);

    void betterConnect(int p1, int p2);

    int findRoot(int p);

    void printGraph();
};

#endif
