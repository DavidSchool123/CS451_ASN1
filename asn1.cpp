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

        void enqueue(double newitem); // add new item to the end
        double dequeue(); // return the item and remove it 
        bool isEmpty(); // if the size is equal to 0
        bool isFull(); // if the size is equal to the maz capasity
        int size(); // return the number of items in the queue

};


int main(){
    cout << "Begin" << endl;
    CircularQueue *circularQ = new CircularQueue(5); // create a test queue with a max capacity of 5


    delete circularQ;
    cout << "Ran Successful" << endl;
    return 0;

}
