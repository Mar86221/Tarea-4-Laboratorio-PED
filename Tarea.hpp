//Luis Mario Valencia #00086221
#include <iostream>
#include <string>
using namespace std;


struct BaseDatos
{
    int ID;
    string usuario;
    string perfil;
};

BaseDatos solicitarData(void) //Rellenar datos
{
    BaseDatos B;
    cout<<"ID: ";
    cin>>B.ID; cin.ignore();
    cout<<"Usuario: ";
    cin>>B.usuario; cin.ignore();
    cout<<"Perfil (administrador, cliente, o trabajador): ";
    cin>>B.perfil; cin.ignore();
    return B;
}

void mostrarData(BaseDatos B) //Mostrar los datos
{
    //Se hizo dos formas para mostrar los datos
    //porque no se como mostrarlo de forma "amigable"
    cout<<"#"<<B.ID;
    cout<<" -Usuario: "<<B.usuario;
    cout<<" -Perfil: "<<B.perfil<<endl;
    /*cout<<"#"<<B.ID;
    cout<<" "<<B.usuario;
    cout<<" "<<B.perfil<<endl;*/
}

typedef BaseDatos t;
const t noValido = {0,"",""}; 

struct nodo
{
    t dato;
    nodo *sig;
    nodo *ant;
};

//Templates usados para ahorrar tiempo
typedef bool b; //b=bool
typedef void v; //v=void
typedef nodo N; //N=nodo

class ListDob   
{
private:
    N *pInicio;
public:
    ListDob ();
    ~ListDob();
    v insertFront(t); //insInicio
    v insertBack(t);  //insFinal
    v tranversalForwardDirection(v); //Mostrar de forma directa
    v tranversalReverseDirection(v); //Mostrar de forma inversa
    v deleteItem(t); //Borrar nodo
    b empty(v); //Sirve para saber si esta vacio
    b searchItem(t); //Busca un nodo en especifico
    v insertAfter(t dato, t datoRef); //Inserta un nodo luego de una referencia
};

ListDob ::ListDob ()
{
    pInicio=NULL;
}

ListDob ::~ListDob()
{
    N *p;
    while(pInicio)
    {
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

v ListDob::insertFront(t dato)
{
    N *nuevo;
    nuevo = new N;
    nuevo->dato = dato;
    nuevo->sig = pInicio;
    if (pInicio)
        pInicio->ant = nuevo;
    pInicio = nuevo;
}

v ListDob::insertBack(t dato)
{
    N *nuevo, *saltarin;

    nuevo = new N;
    nuevo->dato=dato;

    if (!pInicio)
    {
        pInicio = nuevo;
        pInicio->sig = pInicio->ant = NULL;
    }else{
        saltarin = pInicio;
        while (saltarin->sig)
        {
            saltarin=saltarin->sig;
        }
        saltarin->sig = nuevo;
        nuevo->ant = saltarin;
        nuevo->sig = NULL;
    }
}

v ListDob::tranversalForwardDirection(v)
{
    N *saltarin;

    cout<<endl;
    saltarin=pInicio;
    while (saltarin)
    {
        mostrarData(saltarin->dato);
        saltarin=saltarin->sig;
    }
    
}

v ListDob::tranversalReverseDirection(v)
{
    N *p, *q;
    cout<<endl;
    p=pInicio;
    q=NULL;
    while(p)
    {
        q = p;
        p=p->sig;
    }
    while(q)
    {
        mostrarData(q->dato);
        q=q->ant;
    }
    
}

v ListDob::deleteItem(t datoB)
{ 
    if(!pInicio){
        cout<<"\n"<< "No hay perfiles " << endl;
    }
    else{ 
        nodo *saltarin = pInicio;
        while(saltarin && (saltarin->dato).usuario.compare(datoB.usuario)!=0) 
            saltarin = saltarin->sig; 
        if(!saltarin) 
            cout<<"\n"<< "No esta el perfil " << endl;
        else{ 
              
            if(!saltarin->ant && saltarin->sig){ 
                pInicio = pInicio->sig;
                pInicio->ant = NULL;
                delete saltarin;
            }
            else
            {
                if(saltarin->ant && !saltarin->sig){
                    saltarin->ant->sig = NULL;
                    delete saltarin;
                }
                else
                {
                    if(saltarin->ant && saltarin->sig){
                        saltarin->ant->sig = saltarin->sig;
                        saltarin->sig->ant = saltarin->ant;
                        delete saltarin;
                    }
                    else{
                        pInicio = NULL;
                        delete saltarin;
                    }
                }
            }
            cout<<"\n"<<"Perfil eliminado exitosamente "<<endl;
        }
    }
      
}

b ListDob::empty(v)
{
    return pInicio==NULL;
}

b ListDob::searchItem(t datoB){
    if(!pInicio){ 
        cout << "Actualmente no hay perfiles." << endl;
        return false;
    }
    else{ 
        nodo *saltarin = pInicio;
        while(saltarin && (saltarin->dato).usuario.compare(datoB.usuario)!=0) 
            saltarin = saltarin->sig; 
        if(!saltarin) 
            return false;
        else
            return true;
    }
}

v ListDob::insertAfter(t dato, t datoRef){
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->dato = dato;

    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio->ant = NULL;
    }
    else{
        nodo *saltarin;
        saltarin = pInicio;
        while(saltarin->sig != NULL && (saltarin->dato).usuario.compare(datoRef.usuario) != 0){
            saltarin = saltarin->sig;
        }
        nuevo->sig = saltarin->sig;
        nuevo->ant = saltarin;
        if(saltarin->sig != NULL)
            saltarin->sig->ant = nuevo;
        saltarin->sig = nuevo;

    }
}
