#include <conio.h>
#include <iostream>
using namespace std;
typedef int Info;

struct element                    
{
    int x;                           
    element* Next;                 
};

class List                         
{
    element* Head;                    
public:
    List() { Head = NULL; }            
    ~List();                        
    void Add(int x);                   
    void Show();                       
};

List::~List()                      
{
    while (Head != NULL)           
    {
        element* temp = Head->Next; 
        delete Head;               
        Head = temp;            
    }
}

void List::Add(int x)               
{
    element* temp = new element;      
    temp->x = x;                       
    temp->Next = Head;                
    Head = temp;                        
}

void List::Show()                   
{
    element* temp = Head;                

    while (temp != NULL)               
    {
        cout << temp->x << " ";           
        temp = temp->Next;             
    }
}
struct Elem
{
    Elem* V1,
        * V2,
        * link;
    int info;
};
int Include (Elem *L, Info V1, Info V2)
{
    while (L != NULL)
{
    if (L->info == V1)
    {
        Elem* tmp = new Elem; // 1
        tmp->info = V2; // 2
        tmp->link = L->link; // 3
        L->link = tmp; // 4
        L = L->link;
    }
    L = L->link;
}
}

int main()
{
    int N;                      
    int x;                      
    List lst;                     

    cout << "N = ";
    cin >> N; 
    Elem* top = NULL;
    // створення стеку
    for (int i = 1; i <= 10; i++)
    Elem* L = NULL;
    Info V1 = 1;
    Info V2 = 2;

    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << ". x = ";
        cin >> x;            
        lst.Add(x);           
    }
    while (L != NULL)
    {
        if (L->info == V1)
        {
            Include(L, V1, V2);
            L = L->link;
        }
        L = L->link;
    }

    lst.Show(); 				
    cin.ignore().get();			
    return 0;
}