#include <thread>

class KTest
{
public:
    KTest() {}
    ~KTest()
    {
    }
    //KTest(const KTest&) = delete;
    //KTest& operator=(KTest const&) = delete;
};

int main()
{
    KTest t;
    KTest t2 = t;
    printf("Hello world\r\n");
    return 0;
}