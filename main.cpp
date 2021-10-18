//Luis Mario Valencia #00086221
#include "Tarea.hpp"

int menu()
{
    int opcion; //Menu de seleccion
    cout << endl;
    cout << "1) Agregar al inicio. " << endl;
    cout << "2) Agregar al final. " << endl;
    cout << "3) Mostrar datos de inicio a fin. " << endl;
    cout << "4) Mostrar datos de fin a inicio. " << endl;
    cout << "5) Eliminar un perfil. " << endl;
    cout << "6) Buscar perfil. " << endl;
    cout << "7) Agregar perfil despues de una referencia. " << endl;
    cout << "8) Salir. " << endl;
    cout << "Opcion ";
    cin >> opcion;
    cin.ignore();
    return opcion;
}

int main(int argc, char const *argv[])
{
    cout << "\n"
         << "Bienvenido al menu para ingresar informacion sobre un administrador, cliente, o trabajador " << endl;
    //BasDatos porque como guarda informacion de un usuario 
    //se le puso asi
    ListDob BasDatos;

    bool continuar = true;
    BaseDatos B;
    BaseDatos pref;
    do
    {
        switch (menu())
        {
        case 1: //Al inicio
            cout<< "Digite el perfil: " <<endl;
            B = solicitarData();
            BasDatos.insertFront(B);
            cout<<"\n"<<"Perfil almacenado exitosamente! "<<endl;
            break;
        case 2: //Al final
            cout<<"Digite el perfil: "<<endl;
            B = solicitarData();
            BasDatos.insertBack(B);
            cout<<"\n"<<"Perfil almacenado exitosamente! "<<endl;
            break;
        case 3: //Mostrando de forma directa
            if (BasDatos.empty())
            {
                cout<<"\n"<<"No hay ningun dato aun "<<endl;
            }
            else
            {
                BasDatos.tranversalForwardDirection();
            }
            break;
        case 4: //Mostrando de forma inversa
            if(BasDatos.empty())
            {
                cout<<"\n"<<"No hay ningun dato aun "<<endl;
            }
            else
            {
                BasDatos.tranversalReverseDirection();
            }
            break;
        case 5: //Borrar nodo
            B = solicitarData();
            if (BasDatos.empty())
            {
                cout<<"\n"<<"No hay perfiles aun "<<endl;
            }
            else
            {
                BasDatos.deleteItem(B);
            }
            break;
        case 6: //Buscar nodo
            if (BasDatos.empty())
            {
                cout<<"\n"<<"No hay perfiles para buscar"<<endl;
            }
            else
            {
                B = solicitarData();
                cout<<"\n"<<"El perfil "<<(BasDatos.searchItem(B)?"SI!":"NO!");
                cout<<" existe."<<endl;
            }
            break;
        case 7: //Insertar nodo despues de una referencia
            cout<<"<Perfil a insertar>"<<endl;
            B = solicitarData();
            cout<<"<Perfil de referencia>"<<endl;
            pref = solicitarData();
            BasDatos.insertAfter(B, pref);
            cout<<"\n"<<"Perfil almacenado exitosamente!"<<endl;
            break;
        case 8: //Salir
            continuar = false;
            break;
        default: //Opcion no valida
            cout<<"\n"<<"La opcion no es valida, favor intente denuevo."<<endl;
            break;
        }
    } while(continuar);

    return 0;
}
