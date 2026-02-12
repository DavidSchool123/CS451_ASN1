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

        void enqueue(double newitem){ // add new item to the end
            if(isFull()){
                cout << "Error: The queue if full" << endl;
                return;
            }
            
            Items[Last] = newitem;
            Last += 1;       

        }
        double dequeue(); // return the item and remove it 
        bool isEmpty(); // if the size is equal to 0

        // if the size is equal to the maz capasity
        bool isFull(){
            return false;
        } 
        
        // return the number of items in the queue
        int size(){
            return Last; // this is a test will remove soon
        } 

        // print the items in the list
        void printQueue(){
            for(int i=0;i<size(); i++){
                cout << Items[i] << " ";
            }
        }

};


int main(){
    cout << "Begin" << endl;
    CircularQueue *circularQ = new CircularQueue(5); // create a test queue with a max capacity of 5
    circularQ->enqueue(2);
    circularQ->enqueue(4);
    circularQ->enqueue(6);

    circularQ->printQueue();

    delete circularQ;
    cout << "Ran Successful" << endl;
    return 0;

}
