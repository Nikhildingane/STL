#ifndef STLdll_H
#define STLdll_H

#include <iostream>
using namespace std;

namespace DS
{
    // Generic structure for node used for Singly linear ,Singly Circular , Stack,Queue

    template<class T>
    struct Singly_Node
    {
        T Data;
        struct Singly_Node *Next;
    };

    //creating user defined data type

    typedef int BOOL;
    #define TRUE 1
    #define FALSE 0


//////////////////////////////////////////   Start of singly linear linked list    //////////////////////////////////////////////

    //class declaration of class for singly linear linked list

    template<class T>
    class Singly_LinkedList
    {
        private:
            struct Singly_Node<T>* Head;
        public:
            Singly_LinkedList();                    //Constructor
            ~Singly_LinkedList();                   //Destructor
            BOOL InsertFirst(T);                    //function to insert node at first position in linked list
            BOOL InsertLast(T);                     //function to insert node at last position in linked list
            BOOL InsertAtPosition(T,int);           //function to insert node at given position in linked list
            BOOL DeleteFirst();                     //function to delete node at first position in linked list
            BOOL DeleteLast();                      //function to delete node at last position in linked list
            BOOL DeleteAtPosition(int);             //function to delete node at given position in linked list
            void Display();                         //function to display all nodes from linked list
            int Count();                            //return count of nodes from linked list
    };

    template<class T>
    Singly_LinkedList<T>::Singly_LinkedList()
    {
        Head=NULL;
    }


    template<class T>
    Singly_LinkedList<T>::~Singly_LinkedList()
    {
        struct Singly_Node<T>* temp=Head;
        struct Singly_Node<T>* temp2=NULL;
        if(Head!=NULL)
        {
            while(temp->Next->Next!=NULL)
            {
                temp2=temp;
                temp=temp->Next;
                delete temp2;
            }
        }
    }

    template<class T>
    BOOL Singly_LinkedList<T>::InsertFirst(T iNo)
    {
        struct Singly_Node<T>* newn= new struct Singly_Node<T>;

        if(newn==NULL)
        {
            return FALSE;
        }
        newn->Data=iNo;
        newn->Next=NULL;

        if(Head==NULL)
        {
            Head=newn;
        }
        else
        {
            newn->Next=Head;
            Head=newn;
        }
        return TRUE;
    }

    template<class T>
    BOOL Singly_LinkedList<T>::InsertLast(T iNo)
    {
        struct Singly_Node<T>* newn=new struct Singly_Node<T>;

        if(newn==NULL)
        {
            return FALSE;
        }

        newn->Data=iNo;
        newn->Next=NULL;

        if(Head==NULL)
        {
            Head=newn;
        }
        else
        {
            struct Singly_Node<T>* temp=Head;
            while(temp->Next!=NULL)
            {
                temp=temp->Next;
            }
            temp->Next=newn;
        }
        return TRUE;
    }

    template<class T>
    BOOL Singly_LinkedList<T>::InsertAtPosition(T iNo,int iPose)
    {
        if((Head==NULL)||(iPose>(Count()+1))||(iPose<1))
        {
            return FALSE;
        }
        if(iPose==1)
        {
            return (InsertFirst(iNo));
        }
        else if(iPose==(Count()+1))
        {
            return (InsertLast(iNo));
        }
        else
        {
            struct Singly_Node<T>* temp=Head;
            struct Singly_Node<T>* newn=new struct Singly_Node<T>;

            newn->Data=iNo;
            newn->Next=NULL;

            int iCnt=0;
            for(iCnt=1;iCnt<iPose-1;iCnt++)
            {
                temp=temp->Next;
            }
            newn->Next=temp->Next;
            temp->Next=newn;
        }
        return TRUE;
    }


    template<class T>
    BOOL Singly_LinkedList<T>::DeleteFirst()
    {
        if(Head==NULL)
        {
            return FALSE;
        }
        if(Head->Next==NULL)
        {
            delete Head;
            Head=NULL;
        }
        else
        {
            struct Singly_Node<T>* temp=Head;
            Head=temp->Next;
            delete temp;
        }
        return TRUE;
    }

    template<class T>
    BOOL Singly_LinkedList<T>::DeleteLast()
    {
        if(Head==NULL)
        {
            return FALSE;
        }
        else if(Head->Next==NULL)
        {
            delete Head;
            Head=NULL;
        }
        else
        {
            struct Singly_Node<T>* temp=Head;
            while(temp->Next->Next!=NULL)
            {
                temp=temp->Next;
            }
            delete temp->Next;
            temp->Next=NULL;
        }
        return TRUE;
    }

    template<class T>
    BOOL Singly_LinkedList<T>::DeleteAtPosition(int iPose)
    {
        if((Head==NULL)||(iPose<1)||(iPose>Count()))
        {
            return FALSE;
        }
        if(iPose==1)
        {
            return (DeleteFirst());
        }
        else if(iPose==Count())
        {
            return (DeleteLast());
        }
        else
        {
            struct Singly_Node<T>* temp=Head;

            for(int i=1;i<iPose-1;i++)
            {
                temp=temp->Next;
            }
            struct Singly_Node<T>* temp2=temp->Next;
            temp->Next=temp->Next->Next;//temp->Next=temp2->Next;
            delete temp2;
        }
        return TRUE;
    }

    template<class T>
    void Singly_LinkedList<T>::Display()
    {
        struct Singly_Node<T>* temp=Head;
        while(temp!=NULL)
        {
            cout<<temp->Data<<"  ->  ";
            temp=temp->Next;
        }
        cout<<"NULL"<<endl;
    }

    template<class T>
    int Singly_LinkedList<T>::Count()
    {
        struct Singly_Node<T>* temp=Head;
        int iCnt=0;
        while(temp!=NULL)
        {
            iCnt++;
            temp=temp->Next;
        }
        return iCnt;
    }

/////////////////////////////////////////   End of Singly Linear Linked List    //////////////////////////////////////////////


//////////////////////////////////////////   Start of singly circular linked list    //////////////////////////////////////////////
    template<class T>
    class SinglyCircularLL
    {
        private:
            struct Singly_Node<T> *Head;
            struct Singly_Node<T> *Tail;
        public:
            SinglyCircularLL();                             //Constructor
            ~SinglyCircularLL();                            //Destructor
            void InsertFirst(T);                            //function to insert node at first position in linked list
            void InsertLast(T);                             //function to insert node at last position in linked list
            void InsertAtPosition(T,int);                   //function to insert node at given position in linked list
            void DeleteFirst();                             //function to delete node at first position in linked list
            void DeleteLast();                              //function to delete node at last position in linked list
            void DeleteAtPosition(int);                     //function to delete node at given position in linked list
            void Display();                                 //function to display all nodes from linked list
            int Count();                                    //return count of nodes from linked list
    };

    template<class T>
    SinglyCircularLL<T>::SinglyCircularLL()
    {
        Head=NULL;
        Tail=NULL;
    }

    template<class T>
    SinglyCircularLL<T>::~SinglyCircularLL()
    {
        struct Singly_Node<T> *temp=Head;
        do
        {
            temp=Head;
            Head=Head->Next;
            delete temp;
        }while(Head!=Tail->Next);
    }

    template<class T>
    void SinglyCircularLL<T>::InsertFirst(T data)
    {
        struct Singly_Node<T> *newn=new struct Singly_Node<T>;

        newn->Data=data;
        newn->Next=NULL;

        if(Head==NULL)
        {
            Head=newn;
            Tail=newn;
        }
        else
        {
            newn->Next=Head;
            Head=newn;
        }
        Tail->Next=Head;
    }

    template<class T>
    void SinglyCircularLL<T>::InsertLast(T data)
    {
        struct Singly_Node<T> *temp=Head;
        struct Singly_Node<T> *newn=new struct Singly_Node<T>;

        newn->Data=data;
        newn->Next=NULL;

        if(Head==NULL)
        {
            Head=newn;
            Tail=newn;
        }
        else
        {
            do
            {
                temp=temp->Next;
            }
            while(temp->Next!=Tail->Next);

            temp->Next=newn;
            Tail=newn;
        }
        Tail->Next=Head;
    }

    template<class T>
    void SinglyCircularLL<T>::InsertAtPosition(T data,int pos)
    {
        if((Head==NULL)||(pos<1)||(pos>Count()+1))
        {
            return;
        }
        if(pos==1)
        {
            InsertFirst(data);
        }
        else if(pos==Count()+1)
        {
            InsertLast(data);
        }
        else
        {
            struct Singly_Node<T> *temp=Head;
            struct Singly_Node<T> *newn=new struct Singly_Node<T>;

            newn->Data=data;
            newn->Next=NULL;

            for(int i=1;i<pos-1;i++)
            {
                temp=temp->Next;
            }

            newn->Next=temp->Next;
            temp->Next=newn;
        }

    }

    template<class T>
    void SinglyCircularLL<T>::DeleteFirst()
    {
        if(Head==NULL)
        {
            return;
        }
        else if(Head==Tail)
        {
            delete Head;
            Head=NULL;
            Tail=NULL;
        }
        else
        {
            cout<<"else";
            struct Singly_Node<T> *temp=Head;
            Head=Head->Next;
            delete temp;
            Tail->Next=Head;
        }
    }

    template<class T>
    void SinglyCircularLL<T>::DeleteLast()
    {
        if(Head==NULL)
        {
            return;
        }
        else if(Head==Tail)
        {
            delete Head;
            Head=NULL;
            Tail=NULL;
        }
        else
        {
            struct Singly_Node<T> *temp=Head;

            while(temp->Next->Next!=Tail->Next)
            {
                temp=temp->Next;
            }
            delete Tail;
            Tail=temp;
            Tail->Next=Head;
        }
    }

    template<class T>
    void SinglyCircularLL<T>::DeleteAtPosition(int pos)
    {
        if((Head==NULL)||(pos<1)||(pos>Count()))
        {

            return;
        }
        if(pos==1)
        {

            DeleteFirst();
        }
        else if(pos==Count())
        {

            DeleteLast();
        }
        else
        {

            struct Singly_Node<T> *temp=Head;
            for(int i=1;i<pos-1;i++)
            {
                temp=temp->Next;
            }

            struct Singly_Node<T> *temp2=temp->Next;
            temp->Next=temp->Next->Next;
            delete temp2;
        }
    }

    template<class T>
    void SinglyCircularLL<T>::Display()
    {
        struct Singly_Node<T> *temp=Head;
        cout<<endl;
        do
        {
            cout<<temp->Data<<"  ->  ";
            temp=temp->Next;
        }while(temp!=Tail->Next);

        cout<<endl;
    }

    template<class T>
    int SinglyCircularLL<T>::Count()
    {
        struct Singly_Node<T> *temp=Head;
        int iCnt=0;
        if(Head==NULL)
        {
            return iCnt;
        }
        do
        {
            iCnt++;
            temp=temp->Next;
        }while(temp!=Tail->Next);
        return iCnt;
    }
//////////////////////////////////////////   End of singly circular linked list    //////////////////////////////////////////////


 //////////////////////////////////////////   Start of Doubly Linear linked list    //////////////////////////////////////////////

 // structure for node used in Doubly Linear Linked List and Doubly Circular Linked List

    template<class T>
    struct Doubly_Node
    {
        T Data;
        struct Doubly_Node<T> *Next;
        struct Doubly_Node<T> *Prev;
    };

    template<class T>
    class DoublyLinearLL
    {
        private:
            struct Doubly_Node<T> *Head;
        public:
            DoublyLinearLL();                           //Constructor
            ~DoublyLinearLL();                          //Destructor
            void InsertFirst(T);                        //function to insert node at first position in linked list
            void InsertLast(T);                         //function to insert node at last position in linked list
            void InsertAtPosition(T,int);               //function to insert node at given position in linked list
            void DeleteFirst();                         //function to delete node at first position in linked list
            void DeleteLast();                          //function to delete node at last position in linked list
            void DeleteAtPosition(int);                 //function to delete node at given position in linked list
            void Display();                             //function to display all nodes from linked list
            void DisplayRev();                          //function to display all nodes from linked list in reverse order
            int Count();                                //return count of nodes from linked list
    };
    template<class T>
    DoublyLinearLL<T>::DoublyLinearLL()
    {
        Head=NULL;
    }

    template<class T>
    DoublyLinearLL<T>::~DoublyLinearLL()
    {
        struct Doubly_Node<T>* temp=Head;
        struct Doubly_Node<T>* temp2=NULL;
        if(Head!=NULL)
        {
            while(temp->Next->Next!=NULL)
            {
                temp2=temp;
                temp=temp->Next;
                delete temp2;
            }
        }
    }

    template<class T>
    void DoublyLinearLL<T>::InsertFirst(T iNo)
    {
        struct Doubly_Node<T>* newn= new struct Doubly_Node<T>;

        if(newn==NULL)
        {
            return ;
        }
        newn->Data=iNo;
        newn->Next=NULL;
        newn->Prev=NULL;

        if(Head==NULL)
        {
            Head=newn;
        }
        else
        {
            newn->Next=Head;
            Head->Prev=newn;
            Head=newn;
        }
    }

    template<class T>
    void DoublyLinearLL<T>::InsertLast(T iNo)
    {
        struct Doubly_Node<T>* newn=new struct Doubly_Node<T>;

        if(newn==NULL)
        {
            return ;
        }

        newn->Data=iNo;
        newn->Next=NULL;
        newn->Prev=NULL;

        if(Head==NULL)
        {
            Head=newn;
        }
        else
        {
            struct Doubly_Node<T>* temp=Head;
            while(temp->Next!=NULL)
            {
                temp=temp->Next;
            }
            temp->Next=newn;
            newn->Prev=temp;
        }
    }

    template<class T>
    void DoublyLinearLL<T>::InsertAtPosition(T iNo,int iPose)
    {
        if((Head==NULL)||(iPose>(Count()+1))||(iPose<1))
        {
            return ;
        }
        if(iPose==1)
        {
            return (InsertFirst(iNo));
        }
        else if(iPose==(Count()+1))
        {
            return (InsertLast(iNo));
        }
        else
        {
            struct Doubly_Node<T>* temp=Head;
            struct Doubly_Node<T>* newn=new struct Doubly_Node<T>;

            newn->Data=iNo;
            newn->Next=NULL;
            newn->Prev=NULL;

            int iCnt=0;
            for(iCnt=1;iCnt<iPose-1;iCnt++)
            {
                temp=temp->Next;
            }
            newn->Next=temp->Next;
            newn->Prev=temp;
            newn->Next->Prev=newn;
            temp->Next=newn;
        }
    }


    template<class T>
    void DoublyLinearLL<T>::DeleteFirst()
    {
        if(Head==NULL)
        {
            return ;
        }
        if(Head->Next==NULL)
        {
            delete Head;
            Head=NULL;
        }
        else
        {
            struct Doubly_Node<T>* temp=Head;
            Head=temp->Next;
            Head->Prev=NULL;
            delete temp;
        }
    }

    template<class T>
    void DoublyLinearLL<T>::DeleteLast()
    {
        if(Head==NULL)
        {
            return ;
        }
        else if(Head->Next==NULL)
        {
            delete Head;
            Head=NULL;
        }
        else
        {
            struct Doubly_Node<T>* temp=Head;
            while(temp->Next->Next!=NULL)
            {
                temp=temp->Next;
            }
            delete temp->Next;
            temp->Next=NULL;
        }
        return ;
    }

    template<class T>
    void DoublyLinearLL<T>::DeleteAtPosition(int iPose)
    {
        if((Head==NULL)||(iPose<1)||(iPose>Count()))
        {
            return ;
        }
        if(iPose==1)
        {
            return (DeleteFirst());
        }
        else if(iPose==Count())
        {
            return (DeleteLast());
        }
        else
        {
            struct Doubly_Node<T>* temp=Head;

            for(int i=1;i<iPose-1;i++)
            {
                temp=temp->Next;
            }
            struct Doubly_Node<T>* temp2=temp->Next;
            temp->Next=temp->Next->Next;
            temp->Next->Prev=temp;
            delete temp2;
        }
        return ;
    }

    template<class T>
    void DoublyLinearLL<T>::Display()
    {
        struct Doubly_Node<T>* temp=Head;
        while(temp!=NULL)
        {
            cout<<temp->Data<<"  ->  ";
            temp=temp->Next;
        }
        cout<<"NULL"<<endl;
    }

    template<class T>
    int DoublyLinearLL<T>::Count()
    {
        struct Doubly_Node<T>* temp=Head;
        int iCnt=0;
        while(temp!=NULL)
        {
            iCnt++;
            temp=temp->Next;
        }
        return iCnt;
    }

    template<class T>
    void DoublyLinearLL<T>::DisplayRev()
    {
        struct Doubly_Node<T> *temp=Head;
        cout<<endl;
        while(temp->Next!=NULL)
        {
            temp=temp->Next;
        }
        while(temp!=NULL)
        {
            cout<<temp->Data<<"  ->  ";
            temp=temp->Prev;
        }

        cout<<"NULL"<<endl;
    }
//////////////////////////////////////////   End of Doubly Linear linked list    //////////////////////////////////////////////


//////////////////////////////////////////   Start of Doubly Circular linked list    //////////////////////////////////////////////
    template<class T>
    class DoublyCircularLL
    {
        private:
            struct Doubly_Node<T> *Head;
            struct Doubly_Node<T> *Tail;
        public:
            DoublyCircularLL();                                 //Constructor
            ~DoublyCircularLL();                                //Destructor
            void InsertFirst(T);                                //function to insert node at first position in linked list
            void InsertLast(T);                                 //function to insert node at last position in linked list
            void InsertAtPosition(T,int);                       //function to insert node at given position in linked list
            void DeleteFirst();                                 //function to delete node at first position in linked list
            void DeleteLast();                                  //function to delete node at last position in linked list
            void DeleteAtPosition(int);                         //function to delete node at given position in linked list
            void Display();                                     //function to display all nodes from linked list
            void DisplayRev();                                  //function to display all nodes from linked list in reverse order
            int Count();                                        //return count of nodes from linked list
    };

    template<class T>
    DoublyCircularLL<T>::DoublyCircularLL()
    {
        Head=NULL;
        Tail=NULL;
    }

    template<class T>
    DoublyCircularLL<T>::~DoublyCircularLL()
    {
        struct Doubly_Node<T> *temp=Head;
        do
        {
            temp=Head;
            Head=Head->Next;
            delete temp;
        }
        while(Head!=Tail->Next);
    }

    template<class T>
    void DoublyCircularLL<T>::InsertFirst(T data)
    {
        struct Doubly_Node<T> *newn=new struct Doubly_Node<T>;

        newn->Data=data;
        newn->Next=NULL;
        newn->Prev=NULL;

        if(Head==NULL)
        {
            Head=newn;
            Tail=newn;
        }
        else
        {
            newn->Next=Head;
            Head->Prev=newn;
            Head=newn;
        }

        Head->Prev=Tail;
        Tail->Next=Head;
    }

    template<class T>
    void DoublyCircularLL<T>::InsertLast(T data)
    {
        struct Doubly_Node<T> *newn=new struct Doubly_Node<T>;

        newn->Data=data;
        newn->Next=NULL;
        newn->Prev=NULL;

        if(Head==NULL)
        {
            Head=newn;
            Tail=newn;
        }
        else
        {
            newn->Prev=Tail;
            Tail->Next=newn;
            Tail=newn;
        }

        Head->Prev=Tail;
        Tail->Next=Head;
    }

    template<class T>
    void DoublyCircularLL<T>::InsertAtPosition(T data,int pos)
    {
        if((Head==NULL)||(pos<1)||(pos>Count()+1))
        {
            return;
        }
        if(pos==1)
        {
            InsertFirst(data);
        }
        else if(pos==Count()+1)
        {
            InsertLast(data);
        }
        else
        {
            struct Doubly_Node<T> *temp=Head;
            struct Doubly_Node<T> *newn=new struct Doubly_Node<T>;

            newn->Data=data;
            newn->Next=NULL;
            newn->Prev=NULL;

            for(int i=1;i<pos-1;i++)
            {
                temp=temp->Next;
            }

            newn->Next=temp->Next;
            newn->Next->Prev=newn;
            temp->Next=newn;
            newn->Prev=temp;
        }
    }

    template<class T>
    void DoublyCircularLL<T>::DeleteFirst()
    {
        if(Head==NULL)
        {
            return;
        }
        if(Head==Tail)
        {
            delete Head;
            Head=NULL;
            Tail=NULL;
        }
        else
        {
            Head=Head->Next;
            Head->Prev=Tail;
            delete Tail->Next;
            Tail->Next=Head;
        }
    }

    template<class T>
    void DoublyCircularLL<T>::DeleteLast()
    {
        if(Head==NULL)
        {
            return;
        }
        if(Head==Tail)
        {
            delete Head;
            Head=NULL;
            Tail=NULL;
        }
        else
        {
            Tail=Tail->Prev;
            Tail->Next=Head;
            delete Head->Prev;
            Head->Prev=Tail;
        }
    }

    template<class T>
    void DoublyCircularLL<T>::DeleteAtPosition(int pos)
    {
        if((Head==NULL)||(pos<1)||(pos>Count()))
        {
            return;
        }
        if(pos==1)
        {
            DeleteFirst();
        }
        else if(pos==Count())
        {
            DeleteLast();
        }
        else
        {
            struct Doubly_Node<T> *temp=Head;
            for(int i=1;i<pos-1;i++)
            {
                temp=temp->Next;
            }
            temp->Next=temp->Next->Next;
            delete temp->Next->Prev;
            temp->Next->Prev=temp;
        }
    }

    template<class T>
    void DoublyCircularLL<T>::Display()
    {
        struct Doubly_Node<T> *temp=Head;
        cout<<endl;
        if(Head!=NULL)
        {
            do
            {
                cout<<temp->Data<<"  ->  ";
                temp=temp->Next;
            }
            while(temp!=Tail->Next);
            cout<<endl;
        }
    }

    template<class T>
    void DoublyCircularLL<T>::DisplayRev()
    {
        struct Doubly_Node<T> *temp=Head;
        cout<<endl;
        if(Head!=NULL)
        {
            do
            {
                temp=temp->Next;
            }
            while(temp->Next!=Tail->Next);
            do
            {
                cout<<temp->Data<<"  ->  ";
                temp=temp->Prev;
            }while(temp!=Head->Prev);
            cout<<endl;
        }
    }

    template<class T>
    int DoublyCircularLL<T>::Count()
    {
        struct Doubly_Node<T> *temp=Head;
        int iCnt=0;
        if(Head!=NULL)
        {
            do
            {
                iCnt++;
                temp=temp->Next;
            }
            while(temp!=Tail->Next);
        }
        return iCnt;
    }
//////////////////////////////////////////   End of Doubly Circular linked list    //////////////////////////////////////////////


/////////////////////////////////////////////   Start of Dynamic Stack     ///////////////////////////////////////////////////////


    template<class T>
    class Stack
    {
        private:
            struct Singly_Node<T> *Head;
        public:
            Stack();                            //Constructor
            ~Stack();                           //Destructor
            void Push(T);                       //Push the elements in the stack
            T Pop();                            //Pop the element from the stack and return its value
            void Display();                     //Display all elements from stack
            int Count();                        //return count of elements of stack
    };

    template<class T>
    Stack<T>::Stack()
    {
        Head=NULL;
    }

    template<class T>
    Stack<T>::~Stack()
    {
        struct Singly_Node<T> *temp=Head;
        while(Head!=NULL)
        {
            temp=Head;
            Head=Head->Next;
            delete temp;
        }
    }

    template<class T>
    void Stack<T>::Push(T data)
    {
        struct Singly_Node<T> *newn=new struct Singly_Node<T>;

        newn->Data=data;
        newn->Next=NULL;

        if(Head==NULL)
        {
            Head=newn;
        }
        else
        {
            newn->Next=Head;
            Head=newn;
        }
    }

    template<class T>
    T Stack<T>::Pop()
    {
        if(Head==NULL)
        {
            cout<<"\nStack is empty\n";
            return (T)-1;
        }
        else
        {
            struct Singly_Node<T> *temp=Head;
            T iRet=Head->Data;
            Head=Head->Next;
            delete temp;
            return iRet;
        }
    }

    template<class T>
    void Stack<T>::Display()
    {
        struct Singly_Node<T> *temp=Head;
        cout<<endl;
        while(temp!=NULL)
        {
            cout<<temp->Data<<"\t";
            temp=temp->Next;
        }
    }

    template<class T>
    int Stack<T>::Count()
    {
        struct Singly_Node<T> *temp=Head;
        int iCnt=0;
        while(temp!=NULL)
        {
            iCnt++;
            temp=temp->Next;
        }
        return iCnt;
    }

/////////////////////////////////////////////   End of Dynamic Stack     ///////////////////////////////////////////////////////


/////////////////////////////////////////////   Start of Dynamic Queue     ///////////////////////////////////////////////////////

    template<class T>
    class Queue
    {
        private:
            struct Singly_Node<T> *Head;
            struct Singly_Node<T> *Tail;
        public:
            Queue();                           //Constructor
            ~Queue();                          //Destructor
            void Enqueue(T);                   //Enqueue the element in the queue
            T Dequeue();                       //Dequeue the element from the queue and return its value
            void Display();                    //Display all elements from queue
            int Count();                       //return count of elements of queue
    };

    template<class T>
    Queue<T>::Queue()
    {
        Head=NULL;
        Tail=NULL;
    }

    template<class T>
    Queue<T>::~Queue()
    {
        struct Singly_Node<T> *temp=Head;
        while(Head!=NULL)
        {
            temp=Head;
            Head=Head->Next;
            delete temp;
        }
    }

    template<class T>
    void Queue<T>::Enqueue(T data)
    {
        struct Singly_Node<T> *newn=new struct Singly_Node<T>;

        newn->Data=data;
        newn->Next=NULL;

        if(Head==NULL)
        {
            Head=newn;
            Tail=newn;
        }
        else
        {
            Tail->Next=newn;
            Tail=newn;
        }
    }

    template<class T>
    T Queue<T>::Dequeue()
    {

        if(Head==NULL)
        {
            return (T)-1;
        }
        else
        {
        T Ret=Head->Data;
        struct Singly_Node<T> *temp=Head;
        Head=Head->Next;
        delete temp;
        return Ret;
        }
    }

    template<class T>
    void Queue<T>::Display()
    {
        struct Singly_Node<T> *temp=Head;
        cout<<endl;
        while(temp!=NULL)
        {
            cout<<temp->Data<<"\t";
            temp=temp->Next;
        }
    }

    template<class T>
    int Queue<T>::Count()
    {
        struct Singly_Node<T> *temp=Head;
        int iCnt=0;
        while(temp!=NULL)
        {
            iCnt++;
            temp=temp->Next;
        }
        return iCnt;
    }
/////////////////////////////////////////////   End of Dynamic Queue     ///////////////////////////////////////////////////////


/////////////////////////////////////////////   Start of Binary Search Tree     ///////////////////////////////////////////////////////
    template<class T>
    struct Tree_Node
    {
        T Data;
        struct Tree_Node *RChild;
        struct Tree_Node *LChild;
    };


    template<class T>
    class BinarySerachTree
    {
        private:
            struct Tree_Node<T> *Root;
        public:
            BinarySerachTree();
            void Insert(T);                                             // Constructor
            void DisplayInOrder(struct Tree_Node<T> *);                 // Display nodes in order
            void DisplayPreOrder(struct Tree_Node<T> *);                // Display nodes pre order
            void DisplayPostOrder(struct Tree_Node<T> *);               // Display nodes post order
            int Count(struct Tree_Node<T> *);                           // return the count of elements from the given list
            bool Search(T);                                             // search weather given element is present in tree or not
    };

    template<class T>
    BinarySerachTree<T>::BinarySerachTree()
    {
        Root=NULL;
    }

    template<class T>
    void BinarySerachTree<T>::Insert(T data)
    {
        struct Tree_Node<T> *newn=NULL;
        newn=new struct Tree_Node<T>;

        newn->Data=data;
        newn->RChild=NULL;
        newn->LChild=NULL;

        if(Root==NULL)
        {
            Root=newn;
        }
        else
        {
            struct Tree_Node<T> *temp=Root;
            while(1)
            {
                if(data>temp->Data)
                {
                    if(temp->RChild==NULL)
                    {
                        temp->RChild=newn;
                        break;
                    }
                    temp=temp->RChild;
                }
                else if(data<temp->Data)
                {
                    if(temp->LChild==NULL)
                    {
                        temp->LChild=newn;
                        break;
                    }
                    temp=temp->LChild;
                }
                else
                {
                    delete newn;
                    cout<<"Invalid entry";
                    break;
                }
            }
        }
    }

    template<class T>
    void BinarySerachTree<T>::DisplayInOrder(struct Tree_Node<T> *first)
    {
        static bool flag=true;
        if(flag==true)
        {
            first=Root;
            flag=false;
        }
        if(first!=NULL)
        {
            DisplayInOrder(first->LChild);
            cout<<first->Data<<"\t";
            DisplayInOrder(first->RChild);
        }
    }

    template<class T>
    void BinarySerachTree<T>::DisplayPreOrder(struct Tree_Node<T> *first)
    {
        static bool flag=true;
        if(flag==true)
        {
            first=Root;
            flag=false;
        }
        if(first!=NULL)
        {
            cout<<first->Data<<"\t";
            DisplayPreOrder(first->LChild);
            DisplayPreOrder(first->RChild);
        }
    }

    template<class T>
    void BinarySerachTree<T>::DisplayPostOrder(struct Tree_Node<T> *first)
    {
        static bool flag=true;
        if(flag==true)
        {
            first=Root;
            flag=false;
        }
        if(first!=NULL)
        {
            DisplayPostOrder(first->LChild);
            DisplayPostOrder(first->RChild);
            cout<<first->Data<<"\t";
        }
    }

    template<class T>
    int BinarySerachTree<T>::Count(struct Tree_Node<T> *first)
    {
        static bool flag=true;
        static int iCnt=0;
        if(flag==true)
        {
            first=Root;
            flag=false;
        }
        if(first!=NULL)
        {
            iCnt++;
            Count(first->LChild);
            Count(first->RChild);
        }
        return iCnt;
    }

    template<class T>
    bool BinarySerachTree<T>::Search(T data)
    {
        struct Tree_Node<T> *temp=Root;
        while(temp!=NULL)
        {
            if(data>temp->Data)
            {
                temp=temp->RChild;
            }
            else if(data<temp->Data)
            {
                temp=temp->LChild;
            }
            else if(data==temp->Data)
            {
                break;
            }
        }
        if(temp==NULL)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
/////////////////////////////////////////////   End of Binary Search Tree     ///////////////////////////////////////////////////////
}

#endif // STLdll_H
