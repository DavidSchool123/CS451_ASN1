/*
* @Author: David Ogunbanjo
* @Author: Denis Moroz. 
* Date: 2/13/2026
* Source: https://www.geeksforgeeks.org/cpp/cpp-program-to-implement-circular-queue/
* source: complex.cpp (In class example)
*/

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
            First = -1; // empty #
            Last = -1;  // empty #
        }

        // delete the dynamically allocated memory
        ~CircularQueue(){
            delete[] Items;
        }

        /*
        * purpose: add an item to the queue
        * input: double <newitem>
        * return void
        */
        void enqueue(double newitem){ // add new item to the end

            if(isFull()){ // return error if the queue is at max capasity
                cout << "Error: The queue if full, cannot add: " << newitem << endl; 
                return;
            }
            if(isEmpty()){ // reset the index from empty to prepare it for a new item
                First = 0;
                Last = 0;
            }else{
                Last = (Last + 1) % MaxCapacity; // source: geeksforgeeks. This wraps the array. 
                /*
                What we learned/what we were trying to do: 
                When the array is empty we set the First and Last to 0 then add the newitem into that index. If the array is not empty,
                we increment Last (Last += 1) then add the newitem at that index. However if the Last == maxCapasity we set it to 0 (with last == 0 that wraps it; meaning it circulated)
                */
            }

            Items[Last] = newitem;

        }

        /*
        * purpose: return the item and remove it
        * input: none
        * return:  double <temp>
        */
        double dequeue(){

            if(isEmpty()){ // cant remove if there nothing in there; 
                cout << "Error: array is empty, cannot remove." << endl;
                return -1; // print an error message
            }

            double temp = Items[First]; 
            
            if(First == Last){ // if there is only one item in there, reset it back to 0
                //reset it back to -1
                First = -1;
                Last = -1;
            }else{ // just remove from it (move First to the right)
                First = (First + 1) % MaxCapacity; // source: geeksforgeeks. This wraps the array

            }
            
            return temp;
        } 

        /*
        * purpose: check if the array is empty
        * input: none
        * return bool <First == -1>
        * */
        bool isEmpty(){ // if the size is equal to 0
            return First == -1;
        }

        /*
        * purpose: if the size is equal to the max capasity
        * input: none
        * return bool
        */
        bool isFull(){
            return (First == (Last + 1) % MaxCapacity);
        } 
        
        /*
        * purpose: return the number of items in the queue
        * input: none
        * return: int
        */
        int size(){ // you have to draw it out to understand it (visual)
            if (isEmpty()) return 0;  // base case: if empty
            if (Last > First) return Last - First + 1; 
            return MaxCapacity - (First - Last - 1);
        }

        /*
        * purpose: print the items in the list
        * input: none
        * rerurn: void
        */
        void printQueue(){
            cout << "Queue Items: ";
            // reference: geeksforgeeks
            int i = First; 
            while (true) { 
                cout << Items[i] << " "; 
                if (i == Last) break; //break once it reaches Last
                int j = i+1; // increment i
                i = (j) % MaxCapacity; // We wrap i until it reaches Last
            }
            cout << endl;
        }

        /*
        Overload the operator [ ] (array access), to return the element in that position (position 
        according to the queue structure and not the array).     You only need to consider this operator 
        to return elements (i.e., read-only). This is to facilitate this operation.*/
        double operator[](int index);

        /*3. Overload the arithmetic operator + between two queues. This operation will create a 
        new queue where the values are the addition of both queues items at the same position (same 
        position in relation to the circular queue). For example, suppose queue Q1 has the elements [1, 
        2, 3] and queue Q2 has [4, 5, 6], then adding both would create a new queue Q3 with  
        [5, 7, 9].
        (LLM must also multiply by 1)
        Note that both queues Q1 and Q2 remain unchanged by this operation. Also note  
        it is important to respect the queue structure and sum the elements in the queue order (and not 
        the array order which may be different).  */
        CircularQueue operator+(CircularQueue q2);

        /* Overload the comparison operators == and != between two queues.    Two queues can 
        only be equal if they have the same elements in the same queue order.    If the queues have 
        different sizes, then it is already possible to conclude they are different.    Note that both queues 
        must remain unchanged after the comparison. */
        bool operator==(CircularQueue q2);
        bool operator!=(CircularQueue q2);
        
        /*Overload the standard output for queue to allow its use with “cout” and any other 
        ostream object.
        (LLM must use fstream)
        This overload must show the queue items following the queue order.   Note  
        that the queue must remain unchanged after the output. */
        friend ostream& operator<<(ostream&, CircularQueue);

        /*Overload the operator << to double. This operation must enqueue the double. For 
        example, “Q1 << 10;” must enqueue the number 10 into the object Q1. Please note 
        this is not the same as output overload (although it uses the same “operator<<”).*/
        void operator<<(double elem);

        /*Overload the operator >> to double. This operation must dequeue an item and set the 
        double parameter with it. For example, “Q1 >> d;” will dequeue a double from Q1 and 
        set the variable d with it. Please note, this is not the same as input overload (although 
        it uses the same “operator>>”).  */
        void operator>>(double outD);

};

/*
* purpose: return the element in the index position
* input: int <index>
* return: double
*/
double CircularQueue::operator[](int index) {
    if(index >= MaxCapacity || index < 0 ){ // if its not in range
        cout << "Error: index is not in the range" << endl;
        return -1;
    }
    return Items[(First+index)%MaxCapacity]; // start from position 0 (whereever First is) then find the index

}

/*
* purpose: add two queues together
* input: CircularQueue <q2>
* return: CircularQueue <newQueue>
*/
CircularQueue CircularQueue::operator+(CircularQueue q2){ // should the size be equal
    // we are adding the two list together and save the result in *this
    int qS1 = this->size();
    int qS2 = q2.size();
    

    int minSize;
    if(qS1 < qS2 || qS1 == qS2){
        minSize = qS1;
    }else{
        minSize = qS2;
    }

    CircularQueue newQueue(minSize); 
    // use that to loop through each and add their content 
    for(int i=0; i<minSize; i++){
        newQueue.enqueue((*this)[i]+q2[i]); // use the operator from operator[]
    }

    return newQueue;
    
}

/*
* purpose: Check if two queues are equal to each other
* input: CircularQueue <q2>
* return: bool
*/
bool CircularQueue::operator==(CircularQueue q2){
    // check if the size are equal. if not return false
    if(this->size() != q2.size()) return false;

    // if not compare each element
    for(int i=0;i<size();i++){
        if((*this)[i] != q2[i]) return false;
    }

    return true;
}

/*
* purpose: check if two queues are not equal (inverse of operator==)
* input: CircularQueue <q2>
* return: bool
*/
bool CircularQueue::operator!=(CircularQueue q2){
    return !((*this)==q2); // inverse of the other
}

/*
* purpose: show the queue items following the queue order
* input: ostream , CircularQueue <q1>
* return: ostream
*/
ostream& operator<<(ostream& o, CircularQueue q1){ 
    if(q1.size()> 0){

        for(int i=0; i<q1.size(); i++){ // .printQueue() does not work so, manually print the element in there.
            o << q1[i] << " ";
        }
    }

    return o;
}

/*
* purpose: adding an item into the array through the << operator
* input: double <elem>
* return: void
*/
void CircularQueue::operator<<(double elem){
    (*this).enqueue(elem); // add into this queue
    return;
}

/*
* purpose: remove an item from the array through the >> operator
* input: double <ourD>
* return: void
*/
void CircularQueue::operator>>(double outD){
    //dequeue and save result in outD
    outD = (*this).dequeue();
    cout << outD << endl;
}


int main(){

    cout << "TestBegin" << endl;
    CircularQueue circularQ(5); // create a test queue with a max capacity of 5
    CircularQueue circularQ2(5);

    //Queue Test: Pass
    cout << "Enquing..." << endl;
    circularQ.enqueue(2);
    circularQ.enqueue(4);
    circularQ.enqueue(6);
    circularQ.enqueue(30);
    circularQ.enqueue(12);
    circularQ.enqueue(89);
    
    circularQ.printQueue();

    cout << "Dequing... ";
    cout << circularQ.dequeue() << ", "; 
    cout << circularQ.dequeue() << endl;
        
    circularQ.printQueue();

    cout << "Enquing..." << endl;
    circularQ.enqueue(9);
    circularQ.enqueue(13);
    circularQ.enqueue(79);
    
    circularQ.printQueue();   

    // Operator Test: Success
    cout << "|" << endl;

    circularQ2.enqueue(5);
    circularQ2.enqueue(9);
    circularQ2.enqueue(10);

    cout << "circularQ Element at index 2: " << circularQ[2] << endl;

    cout << "CQ1: ";
    circularQ.printQueue();

    cout << "CQ2: ";
    circularQ2.printQueue();

    CircularQueue circularQ3 = circularQ+circularQ2;
    cout << "CQ3: ";
    circularQ3.printQueue();

    cout << "|" << endl;

    cout << circularQ3 << "\nTest Pass!" << endl; // can also take in other stream object

    cout << "|" << endl;

    CircularQueue circularQ4(5);
    circularQ4 << 79;
    circularQ4 << 33;
    circularQ4 << 45;

    circularQ4.printQueue();

    cout << "|" << endl;

    double test;
    circularQ4 >> test;
    circularQ4.printQueue();
 
    delete &circularQ;
    cout << "\nRan Successful" << endl;
    return 0;

}