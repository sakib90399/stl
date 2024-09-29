#include <iostream>
#include <stdexcept>
using namespace std;

class Resource {
public:
    Resource() {
        throw runtime_error("Resource allocation failed");
    }
};

int main() {
    try {
        Resource res;
    } catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    return 0;
}
