// @Author: David Ogunbanjo
// @Author: Denis

#include <iostream>
using namespace std;


class CircularQueue{
    private:
        int First;
        int Last;

        int MaxCapacity;
        double* Items;

    public:
        CircularQueue(int N){
            

        }
        ~CircularQueue();

        void enqueue(double newitem);
        double dequeue();
        bool isEmpty();
        bool isFull();
        int size();

};


int main(){
    cout << "Hello" << endl;
    return 0;
}