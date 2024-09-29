#include <iostream>
#include <memory>
using namespace std;

class Resource {
public:
    Resource() {
        cout << "Resource acquired" << endl;
    }
    ~Resource() {
        cout << "Resource destroyed" << endl;
    }
};

int main() {
    {
        unique_ptr<Resource> res1 = make_unique<Resource>();
    } 

    {
        shared_ptr<Resource> res2 = make_shared<Resource>();
        {
            shared_ptr<Resource> res3 = res2;
            cout << "Shared pointers count: " << res2.use_count() << endl; 
        }
        cout << "Shared pointers count: " << res2.use_count() << endl; 
    } 
    return 0;
}
