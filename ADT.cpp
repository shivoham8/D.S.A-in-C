#include <iostream>

using namespace std;

class myArray
{
    int total_size;
    int used_size;
    int *ptr;

public:
    myArray(int tsize, int usize)
    {
        total_size = tsize;
        used_size = usize;
        ptr = new int[tsize];
    }

    void setval()
    {
        for (int i = 0; i < used_size; i++)
        {
            cout << "Enter the value of " << i + 1 << " element " << endl;
            cin >> ptr[i];
        }
    }

    void show()
    {
        for (int i = 0; i < used_size; i++)
        {
            cout << "The value of " << i + 1 << " element is " << ptr[i] << endl;
        }
    }
};

int main()
{
    myArray marks(10, 2);
    marks.setval();
    marks.show();

    return 0;
}