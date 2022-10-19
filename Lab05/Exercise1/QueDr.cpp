// Test driver
#include <iostream>
#include <fstream>

#include "QueType.h"

using namespace std;

int Length(QueType<ItemType> queue);
bool Identical(QueType<ItemType> queue1, QueType<ItemType> queue2);
void ReplaceItem(QueType<ItemType>& queue, ItemType oldItem, ItemType newItem);


int main()
{

  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  string inFileName;     // input file external name
  string outFileName;    // output file external name
  string outputLabel;     
  string command;        // operation to be executed
  
  ItemType item, oldItem, newItem;
  QueType<ItemType> queue(7);
  QueType<ItemType> *temp;
  int numCommands, size, len;


  // Prompt for file names, read file names, and prepare files
  /*
  * �Է����� : QueType.in
  * ������� : QueType.out
  * command
  *   1. Enqueue
  *   2. Dequeue
  *   3. IsEmpty
  *   4. IsFull
  *   5. Length
  *   6. Identical(Idexntical + size +  length + items[])
  *     ex) Idential 5 3 A R L
  *   7. Replace(Replace + oldItem + newItem)
  *     ex) Replace 3 5
  *   8. Quit
  */
  cout << "Enter name of input command file; press return." << endl;
  cin  >> inFileName;
  inFile.open(inFileName.c_str());

  cout << "Enter name of output file; press return." << endl;
  cin  >> outFileName;
  outFile.open(outFileName.c_str());

  cout << "Enter name of test run; press return." << endl;
  cin  >> outputLabel;
  outFile << outputLabel << endl;

  inFile >> command;


  numCommands = 0;
  while (command != "Quit")
  { 
    try 
    {
        if (command == "Enqueue")
        {
            inFile >> item;
            queue.Enqueue(item);
            outFile << item << " is enqueued." << endl;
        }
        else if (command == "Dequeue")
        {
            queue.Dequeue(item);
            outFile << item << " is dequeued. " << endl;
        }
        else if (command == "IsEmpty")
            if (queue.IsEmpty())
                outFile << "Queue is empty." << endl;
            else
                outFile << "Queue is not empty." << endl;

        else if (command == "IsFull")
            if (queue.IsFull())
                outFile << "Queue is full." << endl;
            else outFile << "Queue is not full." << endl;

        else if (command == "Length")
        {
            //����Լ�
            outFile << "Length is " << queue.Length() << "." << endl;

            //Ŭ���̾�Ʈ �Լ�
            //outFile << "Length is " << Length(queue) << "." << endl;
        }

        else if (command == "Identical")
        {
            inFile >> size >> len;
            if (size < len)
                continue;
            temp = new QueType<ItemType>(size);
            
            while (len) {
                inFile >> item;
                temp->Enqueue(item);
                len--;
            }
            
            //����Լ�
            outFile << "Identical is " << queue.Identical(*temp) << "." << endl;

            //Ŭ���̾�Ʈ �Լ�
            //outFile << "Identical is " << Identical(queue, *temp) << "." << endl;
            delete temp;
        }

        else if (command == "Replace")
        {
            inFile >> oldItem >> newItem;

            //����Լ�
            queue.ReplaceItem(oldItem, newItem);
            
            //Ŭ���̾�Ʈ �Լ�
            //ReplaceItem(queue, oldItem, newItem);

            outFile << "Queue replaced from " << oldItem << " to " << newItem << endl;
        }
    }
    catch (FullQueue)
    {
      outFile << "FullQueue exception thrown." << endl;
    }
    
    catch (EmptyQueue)
    {
      outFile << "EmtpyQueue exception thrown." << endl;
    }    
    numCommands++;
    cout <<  " Command number " << numCommands << " completed." 
         << endl;
    inFile >> command;
 
  };
 
  cout << "Testing completed."  << endl;
  inFile.close();
  outFile.close();
  return 0;
}

int Length(QueType<ItemType> queue) {
    //return queue.Length();

    ItemType item;
    int length = 0;
    while (!queue.IsEmpty()) {
        queue.Dequeue(item);
        length++;
    }
    return length;
}

bool Identical(QueType<ItemType> queue1, QueType<ItemType> queue2) {
    ItemType temp1, temp2;
    if (queue1.Length() != queue2.Length() || queue1.Size() != queue2.Size())
        return false;
    while (!queue1.IsEmpty()) {
        queue1.Dequeue(temp1);
        queue2.Dequeue(temp2);
        if (temp1 != temp2)
            return false;
    }
    return true;
}

void ReplaceItem(QueType<ItemType>& queue, ItemType oldItem, ItemType newItem) {
    ItemType item;
    int length = queue.Length();
    while (length) {
        queue.Dequeue(item);
        if (item == oldItem)
            item = newItem;
        queue.Enqueue(item);
        length--;
    }
}
