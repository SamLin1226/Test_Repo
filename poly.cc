#include <iostream>

using namespace std;

template<typename T>
struct Node{
    T coeff;
    int deg;

    Node<T> *fptr = nullptr;
    Node<T> *bptr = nullptr;

    Node(T c = 0, int d = 0) : coeff(c), deg(d){}
};

template<typename T>
Node<T>* makenode(T c, int d) {return new Node<T>(c,d);}


template<typename T>
class Polynomial{
private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
public:
    Polynomial(){
        Node<T> *ptr = makenode(0,0);
        head = ptr;
        tail = ptr;
    }

    add_term(T c, int d){
        Node<T> *thisNode;
        Node<T> *newNode;
        thisNode = head;
        while(1){
            if(d < thisNode->deg){
                newNode = makenode(c,d);
                thisNode->fptr->bptr = newNode;
                newNode->fptr = thisNode->fptr;
                newNode->bptr = thisNode;
                thisNode->fptr = newNode;
                if(newNode->fptr == nullptr){
                    head = newNode;
                }
                break;
            }
            else if(d == thisNode->deg){
                thisNode->coeff += c;
                if(thisNode->coeff == 0){
                    del_deg(d);
                }
                break;
            }
            else{
                if(thisNode->bptr == nullptr){
                    newNode = makenode(c,d);
                    newNode->fptr = thisNode;
                    newNode->bptr = thisNode->bptr;
                    thisNode->bptr = newNode;
                    tail = newNode;
                    break;
                }
                thisNode = thisNode->bptr;
            }
        }
    }

    void del_deg(int d){
        Node<T> *thisNode;
        thisNode = head;
        while(thisNode != nullptr){
            if(thisNode->deg == d){
                if(thisNode->bptr == nullptr && thisNode->fptr == nullptr){
                    thisNode->coeff = 0;
                    thisNode->deg = 0;
                    break;
                }
                else if(thisNode->fptr == nullptr){
                    thisNode->bptr->fptr = nullptr;
                    head = thisNode->bptr;
                }
                else if(thisNode->bptr == nullptr){
                    thisNode->fptr->bptr = nullptr;
                    tail = thisNode->fptr;
                }
                else{
                    thisNode->fptr->bptr = thisNode->bptr;
                    thisNode->bptr->fptr = thisNode->fptr;
                }
                delete thisNode;
                break;
            }

            thisNode = thisNode->bptr;
        }
    }

    friend ostream& operator<<(ostream& out, const Polynomial<T> &poly){
    Node<T> *thisPtr;
    thisPtr = poly.head;
    while(thisPtr != nullptr){
        if(thisPtr->deg == 0 ){
            out << thisPtr->coeff ;
            thisPtr = thisPtr->bptr;
            continue;
        }
        if(thisPtr->coeff < 0){
            if(thisPtr->deg > 1){
                out << " - " << abs(thisPtr->coeff) ;
                out << " X^"<< thisPtr->deg ;
            }
            else{
                out << " - X" ;
            }
        }
        else{
            if(thisPtr->deg > 1){
                out << " + " << thisPtr->coeff ;
                out << " X^"<< thisPtr->deg ;
            }
            else{
                out << " +  X" ;
            }
        }
        thisPtr = thisPtr->bptr;
    }
    return out;
}
};

int main (){
    Polynomial<int> foo;

    foo.add_term(3,2); foo.add_term(-1,1);
    foo.add_term(9,0); foo.add_term(5,6);
    foo.add_term(-2,0);
    cout << "foo = " << foo << endl ;
    foo.add_term(1,1) ;
    cout << "foo = " << foo << endl ;
    
    foo.del_deg(6) ; foo.del_deg(2) ;
    foo.del_deg(3) ; 
    foo.del_deg(0) ;
    cout << "foo = " << foo << endl ;

    foo.add_term(1,1) ;
    cout << "foo = " << foo << endl ;

    return 1;
}