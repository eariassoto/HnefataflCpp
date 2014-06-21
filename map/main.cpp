#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
    char * path;
    cout << "Bienvenido, escriba el nombre del archivo: ";
    cin >> path;
    ofstream myFile (path, ios::out | ios::binary);
    bool b = true;
	int num;
	cin.exceptions(istream::failbit | istream::badbit);
    while(b)
    {
        cout << "escriba el numero a escribir: (-1 para salir) ";
         try
        {
            cin >> num;
			if(num == -1){
				b = false;
				myFile.close();
			}
			else{
				myFile.write ((char*)&num, sizeof(num));
				cout << "escribi: " << num << endl;
			}
        }
        catch(istream::failure e)
        {
            cout << "Error, no escribistes una entrada valida.";
			std::cin.clear();
			std::cin.ignore(1);

        }
		
    }
}
