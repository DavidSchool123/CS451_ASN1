// @Author: David Ogunbanjo
// @Author: Denis Moroz

#include <iostream>
using namespace std;

class CircularQueue{
    private:
        int First; //position of the first item in the queue
        int Last; //position of the last item in the queue

        int MaxCapacity; //maximum capacity of the queue
        double* Items; //the actual items stored in the queue

    public:
        // implement the constructor
        CircularQueue(int N){
            MaxCapacity = N;
            Items = new double[MaxCapacity];
            First = 0;
            Last = 0;
        }

        // delete the dynamically allocated memory
        ~CircularQueue(){
            delete[] Items;
        }

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
