#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_set>

struct KIntPoint3D
{
public:
    KIntPoint3D( int x_ = 0, int y_ = 0, int z_ = 0 )
    {
        x = x_;
        y = y_;
        z = z_;
    }

    bool operator==( const KIntPoint3D& rhs ) const
    {
        return x == rhs.x && y == rhs.y && z == rhs.z;
    }

    int x;
    int y;
    int z;
};

struct AStarNode;
typedef std::shared_ptr<AStarNode>  AStarNodePtr;
struct AStarNode
{
    AStarNodePtr        parent;     // parent node (zero pointer represents starting node)
    
    KIntPoint3D         location;   // location of node (some location representation)
    float               cost;       // cost to get to this node
    float               heuristic;  // heuristic cost to get to goal node
    float               total;      // total cost (cost + heuristic estimate)
    bool                isOpen;     // on Open list
    bool                isClosed;   // on Closed list
    
    // must have default constructor for A* internal structure
    AStarNode( int x = 0, int y = 0, int z = 0)
    {
        location = KIntPoint3D( x, y, z );
        parent    = NULL;
        cost      = 0.0f;
        heuristic = 0.0f;
        total     = 0.0f;
        isOpen    = false;
        isClosed  = false;
    }

    bool operator==( const AStarNode& rhs_ ) const
    {
        return location == rhs_.location;
    }

    void Print()
    {
        printf(" location = (%i, %i, %i)\n", location.x, location.y, location.z );
        printf(" cost = %g\n", cost );
        printf(" heuristic = %g\n", heuristic );
        printf(" total = %g\n", total);
        printf(" open=%d, closed=%d\n", isOpen, isClosed );
    }//Print()

    void PrintLocation()
    {
        printf("(%i, %i, %i)", location.x, location.y, location.z );
    }//Print()
};

class AStarNodeHash
{
public:
    size_t operator()( const AStarNodePtr node ) const
    {
        size_t h1 = std::hash<int>()( node->location.x );
        size_t h2 = std::hash<int>()( node->location.y );
        size_t h3 = std::hash<int>()( node->location.z );
        return h1 ^ ( h2 << 8 ) ^ ( h3 << 16 );
    }
};//class AStarNodeHash

struct AStarNodeEqualTo
{
    bool operator()(const AStarNodePtr& _Left, const AStarNodePtr& _Right) const
    {
        return (*_Left == *_Right);
    }
};

void main() {
    std::unordered_set<AStarNodePtr, AStarNodeHash, AStarNodeEqualTo> uset;
    AStarNodePtr   node;
    node.reset( new AStarNode( 1, 0, 0 ) );
    uset.insert( node );
    node.reset( new AStarNode( 3, 0, 0 ) );
    uset.insert( node );
    node.reset( new AStarNode( 5, 0, 0 ) );
    uset.insert( node );

    AStarNodePtr   node2;
    node2.reset( new AStarNode( 3, 0, 0 ) );
    auto sitor = uset.find( node2 );
    if (sitor != uset.end())
    {
        (*sitor)->Print();
    }//if
}
