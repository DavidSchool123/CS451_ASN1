// @Author: David Ogunbanjo
// @Author: Denis Moroz.  

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
            First = -1;
            Last = -1;
        }

        // delete the dynamically allocated memory
        ~CircularQueue(){
            delete[] Items;
        }

        void enqueue(double newitem){ // add new item to the end
            if(isFull()){
                cout << "Error: The queue if full, cannot add: " << newitem << endl;
                return;
            }
            if(isEmpty()){
                First = 0;
                Last = 0;
            }else{

                Last = (Last + 1) % MaxCapacity; // source: geeksforgeeks. This wraps the array
            }

            Items[Last] = newitem;

        }

        // return the item and remove it 
        double dequeue(){

            if(isEmpty()){ // cant remove if there nothing in there
                cout << "Error: array is empty, cannot remove." << endl;
                return -1;
            }

            double temp = Items[First]; 
            First = (First + 1) % MaxCapacity; // source: geeksforgeeks. This wraps the array

            return temp;
        } 

        bool isEmpty(){ // if the size is equal to 0
            return First == -1;
        }

        // if the size is equal to the maz capasity
        bool isFull(){
            return (First == (Last + 1) % MaxCapacity);
        } 
        
        // return the number of items in the queue
        int size(){
            if (isEmpty()) return 0; 
            if (Last >= First) return Last - First + 1; 
            return MaxCapacity - (First - Last - 1);
        }

        // print the items in the list
        void printQueue(){
            cout << "\n";
            for(int i=First;i<Last; i++){
                cout << Items[i] << " ";
            }
            cout << "\n";
            cout << First << " and " << Last << endl;
            

        }

};


int main(){
    cout << "Begin" << endl;
    CircularQueue *circularQ = new CircularQueue(5); // create a test queue with a max capacity of 5
    
    circularQ->enqueue(2);
    circularQ->enqueue(4);
    circularQ->enqueue(6);
    circularQ->enqueue(30);
    circularQ->enqueue(12);
    //circularQ->enqueue(89);
    /*
    circularQ->printQueue();`

    circularQ->dequeue();
    circularQ->dequeue();
    
    circularQ->printQueue();

    circularQ->enqueue(9);
    circularQ->enqueue(13);
    circularQ->enqueue(79);
    */
    circularQ->printQueue();

    delete circularQ;
    cout << "\nRan Successful" << endl;
    return 0;

}
