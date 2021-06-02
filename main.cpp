#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <windows.h>

using namespace std;

COORD coord={0,0};

    void gotoxy(int x, int y )
    {
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

int main()
{

    int op = 0;
    while( true )
    {
        system("CLS");
        cout<<"\n\n\t\t\t\t\t 같같같같같같같같같같같같같같같같같같같�";
        cout<<"\n\n\t\t\t\t\t Select the option you want to know!";
        cout<<"\n\n\t\t\t\t\t 같같같같같같같같같같같같같같같같같같같� \n\n\n";
        cout<<"\t\t 1) D E T E R M I N A N T   O F   A   M A T R I x \n\n";
        cout<<"\t\t 2) I N V E R S   O F   A   M A T R I X \n\n";
        cout<<"\t\t 3) E X I T \n\n";
        cout<<"\t\t\t\t\t Choose an option: " << endl;
        cin>> op;

        if( op == 1 )
        {
            system("CLS");
                int b,c,e,l,m,z ;
                float a[100][100];
                float det;
                cout<<"\t\t\t******* ******* ******* ******* *******\n";
                cout<<"\t\t\t Enter the order of the matrix: " << endl;
                cout<<"\t\t\t******* ******* ******* ******* *******\n";
                cin >> z;
                m = z - 1;
                // Let's introduce the matrix by keyboard

                cout << "\n\t\tEnter the elements " << endl;
                for(b = 1; b <= z; b++)
                {
                    for(c = 1; c <= z; c++)
                        {
                            cin >> a[b][c];
                        }
                }

                //Calculation of the determinant

                det = a[1][1];
                for(e = 1; e <= m; e++)
                {
                    l = e + 1;
                    for(b = l; b <= z; b++)
                    {
                        for(c = l; c <= z; c++)
                        a[b][c] = ( a[e][e]*a[b][c]-a[e][c]*a[b][e] )/a[e][e];
                    }
                det = det * a[e+1][e+1];
                }

                cout << endl;
                cout<<"\t\t\t******* ******* ******* ******* *******\n";
                cout << "\n\t\t The determinant is: " << det << endl;
                system("PAUSE");
        }

         else if ( op == 2 )
         {
             system("CLS");
                short int k,i,j, n;
                cout<<"\t\t\t******* ******* ******* ******* *******\n";
                cout<<"\t\t\t Indicate the size of the matrix: \n";
                cout<<"\t\t\t******* ******* ******* ******* *******\n";
                cin>>n;
                cout<<endl;
                cout<<endl;
                cout<<endl;

                float B[n][n], I[n][n], aux, pivote;
                for( i = 0; i < n; i++ )
                {
                    for( j = 0; j < n; j++ )
                    {
                        gotoxy(j*5, i+3);
                        cin>>B[i][j];
                        I[i][j] = 0;
                        if( i == j )
                            I[i][j] = 1;
                    }
                }

                //Reduction by Rennglons
                for( i = 0; i < n; i++ )
                {
                    pivote = B[i][i];

                    // convert the pivot to 1 and apply it to the rows
                    for( k = 0; k < n; k++ )
                    {
                        B[i][k] = B[i][k]/pivote;
                        I[i][k] = I[i][k]/pivote;
                    }

                    for( j = 0; j < n; j++ )
                    {
                        if( i != j )
                        {
                            aux = B[j][i];
                            for( k = 0; k < n; k++ )
                            {
                                B[j][k] = B[j][k]-aux*B[i][k];
                                I[j][k] = I[j][k]-aux*I[i][k];
                            }
                        }
                    }
                }

               for( i = 0; i < n; i++ )
               {
                   for( j = 0; j < n; j++ )
                   {
                       //We printed the identity matrix
                       gotoxy(25+j*5, i+10);
                       cout<<"|"<<B[i][j]<<"|";
                       cout<<endl;
                       //We printed the inverse
                       gotoxy(50+j*10, i+10);
                       cout<<"|"<<I[i][j]<<"|";
                       cout<<"\n";
                   }
               }
                system("PAUSE");
         }

         else{
             system("CLS");
             cout<<"\n\n\n";
            cout<< R"(         _          __________                              _,
     _.-(_)._     ."          ".      .--""--.          _.-{__}-._
   .'________'.   | .--------. |    .'        '.      .:-'`____`'-:.
  [____________] /` |________| `\  /   .'``'.   \    /_.-"`_  _`"-._\
  /  / .\/. \  \|  / / .\/. \ \  ||  .'/.\/.\'.  |  /`   / .\/. \   `\
  |  \__/\__/  |\_/  \__/\__/  \_/|  : |_/\_| ;  |  |    \__/\__/    |
  \            /  \            /   \ '.\    /.' / .-\                /-.
  /'._  --  _.'\  /'._  --  _.'\   /'. `'--'` .'\/   '._-.__--__.-_.'   \
 /_   `""""`   _\/_   `""""`   _\ /_  `-./\.-'  _\'.    `""""""""`    .'`\
(__/    '|    \ _)_|           |_)_/            \__)|        '       |   |
  |_____'|_____|   \__________/   |              |;`_________'________`;-'
   '----------'    '----------'   '--------------'`--------------------`
    M A R L O N       J . P .        R O R R O            J . C .)";

            cout<<"\n\n\t\t\t A G R A D E C I D O \n\n";
            break;
         }
    }
    return 0;
}
